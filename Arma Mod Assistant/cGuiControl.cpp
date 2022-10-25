#include "cGuiControl.h"


cMainFrame* cGuiControl::mainFrame = NULL;
std::map<wxString, wxTreeItemId> cGuiControl::fileMap;
wxImageList cGuiControl::iconList(16,16,true);
std::list<wxString> openTabs;

void cGuiControl::generateIconList()
{
	iconList.Add(wxICON(AAppIcon));
	iconList.Add(wxICON(UNKNOWN_ICO));
	iconList.Add(wxICON(FOLDER_ICO));
	iconList.Add(wxICON(PROJFILE_ICO));
	iconList.Add(wxICON(CPP_ICO));
	iconList.Add(wxICON(HPP_ICO));
	iconList.Add(wxICON(SQF_ICO));
	iconList.Add(wxICON(CFG_ICO));
	iconList.Add(wxICON(PAA_ICO));
	iconList.Add(wxICON(P3D_ICO));
	iconList.Add(wxICON(PNG_ICO));

	mainFrame->m_folderView->SetImageList(&iconList);
}

int cGuiControl::getFileIco(wxString file)
{
	if (file.EndsWith(".a3p")) return ICO_A3P;
	if (file.EndsWith(".cpp")) return ICO_CPP;
	if (file.EndsWith(".hpp")) return ICO_HPP;
	if (file.EndsWith(".sqf")) return ICO_SQF;
	if (file.EndsWith(".cfg")) return ICO_CFG;
	if (file.EndsWith(".paa")) return ICO_PAA;
	if (file.EndsWith(".p3d")) return ICO_P3D;
	if (file.EndsWith(".png")) return ICO_PNG;
	return ICO_UNKNOWN;
}

cGuiControl::~cGuiControl()
{
	delete mainFrame;
}

void cGuiControl::setMainFrame(cMainFrame* passedFrame)
{
	if (passedFrame != nullptr) {
		mainFrame = passedFrame;
		generateIconList();
	}
}

void cGuiControl::setUpGui() {
	BaseOptions bSettings = cSettings::getBaseSettings();

	if (bSettings.type == "simple") {
		wxMenuItem* submod = mainFrame->m_New->FindItemByPosition(1);
		submod->Enable(false);
	}
}

bool cGuiControl::fillFolderTree()
{
	std::vector<wxString> fileList;
	BaseOptions settings = cSettings::getBaseSettings();
	if (!mainFrame->m_folderView->GetRootItem().IsOk())
	{
		mainFrame->m_folderView->AddRoot(settings.name, ICO_AMA, -1, new folderTreeData(true, settings.path));
	}
	else {
		mainFrame->m_folderView->DeleteAllItems();
		mainFrame->m_folderView->AddRoot(settings.name, ICO_AMA, -1, new folderTreeData(true, settings.path));
	}
	if (cFileManager::scanFiles(settings.path, fileList) > 0) {
		for (std::vector<wxString>::iterator iter = fileList.begin(); iter < fileList.end(); ++iter) {
			// Do Root Directory Stuff
			if (!iter->Contains(wxT("/")) && !iter->Contains(wxT("\\"))) {
				if (iter->starts_with("%%dir%%")) {
					// do dir things
					iter->Replace("%%dir%%", "", false);
					wxTreeItemId itemId = mainFrame->m_folderView->AppendItem(mainFrame->m_folderView->GetRootItem(), *iter, ICO_FOLDER);
					mainFrame->m_folderView->SetItemData(itemId, new folderTreeData(true, settings.path + *iter));
					fileMap[*iter] = itemId;
				}
				else {
					// do file things
					wxTreeItemId itemId = mainFrame->m_folderView->AppendItem(mainFrame->m_folderView->GetRootItem(), *iter, getFileIco(*iter));
					mainFrame->m_folderView->SetItemData(itemId, new folderTreeData(false, settings.path + *iter));
					fileMap[*iter] = itemId;
				}
			}
			// Do Subdirectory Stuff
			else {
				if (iter->starts_with("%%dir%%")) {
					// Is a Folder
					iter->Replace("%%dir%%", "", false);
					wxString parent(iter->BeforeLast('\\'));
					if (fileMap[parent]) {
						wxTreeItemId itemId = mainFrame->m_folderView->AppendItem(fileMap[parent], iter->AfterLast('\\'), ICO_FOLDER);
						mainFrame->m_folderView->SetItemData(itemId, new folderTreeData(true, settings.path + *iter));
						fileMap[*iter] = itemId;
					}
				}
				else {
					// Is a File
					wxString parent(iter->BeforeLast('\\'));
					if (fileMap[parent]) {
						wxTreeItemId itemId = mainFrame->m_folderView->AppendItem(fileMap[parent], iter->AfterLast('\\'), getFileIco(*iter));
						mainFrame->m_folderView->SetItemData(itemId, new folderTreeData(false, settings.path + *iter));
						fileMap[*iter] = itemId;
					}
				}
			}
		}
		mainFrame->m_folderView->ExpandAll();
		return true;
	}
	return false;
}

void cMainFrame::onFileClicked(wxTreeEvent &event) {
	wxTreeItemId itemId = m_folderView->GetSelection();
	folderTreeData* itemData = (folderTreeData* )m_folderView->GetItemData(itemId);
	for (std::list<wxString>::iterator iter = openTabs.begin(); iter != openTabs.end(); ++iter) {
		if (*iter == itemData->path) {
			for (int indx = 0; indx != m_editBook->GetPageCount(); ++indx) {
				if (m_editBook->GetPageToolTip(indx) == itemData->path) {
					m_editBook->SetSelection(indx);
					return;
				}
			}
		}
	}
	if (itemData->isFolder) return;
	if (itemData->path.ends_with(".sqf") || itemData->path.ends_with(".hpp") || itemData->path.ends_with(".cpp") || itemData->path.ends_with(".txt")) { // Text Type File selected
		wxPanel* newPage = new wxPanel(m_editBook);
		newPage->SetBackgroundColour(wxColor("white"));
		wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
		std::string fileText;
		std::ifstream scriptFile(itemData->path.ToStdString());
		std::string lineTxt;
		while (std::getline(scriptFile, lineTxt))
		{
			fileText += lineTxt + '\n';
		}
		scriptFile.close();
		wxLogDebug(wxString(fileText));
		wxTextCtrl* editBox = new wxTextCtrl(newPage, wxID_ANY, fileText, wxDefaultPosition, wxDefaultSize, wxTE_DONTWRAP | wxNO_BORDER | wxTE_MULTILINE | wxTE_READONLY);
		wxFont font = editBox->GetFont();
		font.SetPointSize(font.GetPointSize() + 2);
		editBox->SetFont(font);
		sizer->Add(editBox, 1, wxEXPAND);
		newPage->SetSizerAndFit(sizer);

		m_editBook->AddPage(newPage, itemData->path.AfterLast('\\'), true);
		m_editBook->SetPageToolTip(m_editBook->GetSelection(), itemData->path);
		wxIcon fileIco;
		/*
		if (file.EndsWith(".a3p")) return ICO_A3P;
		if (file.EndsWith(".cpp")) return ICO_CPP;
		if (file.EndsWith(".hpp")) return ICO_HPP;
		if (file.EndsWith(".sqf")) return ICO_SQF;
		if (file.EndsWith(".cfg")) return ICO_CFG;
		if (file.EndsWith(".paa")) return ICO_PAA;
		if (file.EndsWith(".p3d")) return ICO_P3D;
		if (file.EndsWith(".png")) return ICO_PNG;
		return ICO_UNKNOWN;

		iconList.Add(wxICON(AAppIcon));
		iconList.Add(wxICON(UNKNOWN_ICO));
		iconList.Add(wxICON(FOLDER_ICO));
		iconList.Add(wxICON(PROJFILE_ICO));
		iconList.Add(wxICON(CPP_ICO));
		iconList.Add(wxICON(HPP_ICO));
		iconList.Add(wxICON(SQF_ICO));
		iconList.Add(wxICON(CFG_ICO));
		iconList.Add(wxICON(PAA_ICO));
		iconList.Add(wxICON(P3D_ICO));
		iconList.Add(wxICON(PNG_ICO));
		*/
		switch (cGuiControl::getFileIco(itemData->path))
		{
		case cGuiControl::ICO_UNKNOWN:
			fileIco = wxICON(UNKNOWN_ICO);
			break;
		case cGuiControl::ICO_CPP:
			fileIco = wxICON(CPP_ICO);
			break;
		case cGuiControl::ICO_HPP:
			fileIco = wxICON(HPP_ICO);
			break;
		case cGuiControl::ICO_SQF:
			fileIco = wxICON(SQF_ICO);
			break;
		case cGuiControl::ICO_CFG:
			fileIco = wxICON(CFG_ICO);
			break;
		case cGuiControl::ICO_P3D:
			fileIco = wxICON(P3D_ICO);
			break;
		case cGuiControl::ICO_PNG:
			fileIco = wxICON(PNG_ICO);
			break;
		case cGuiControl::ICO_PAA:
			fileIco = wxICON(PAA_ICO);
			break;
		case cGuiControl::ICO_A3P:
			fileIco = wxICON(PROJFILE_ICO);
			break;
		default:
			fileIco = wxICON(FOLDER_ICO);
			break;
		}
		m_editBook->SetPageBitmap(m_editBook->GetSelection(), fileIco);
		openTabs.push_back(itemData->path);
	}
	event.Skip();
}

void cMainFrame::onFileOpened(wxTreeEvent& event) {
	wxTreeItemId itemId = m_folderView->GetSelection();
	folderTreeData* itemData = (folderTreeData*)m_folderView->GetItemData(itemId);
	wxExecute("cmd /c code \"" + itemData->path + "\"", wxEXEC_HIDE_CONSOLE);
}

void cMainFrame::onPageClose(wxAuiNotebookEvent& event) {
	int pageIndx = event.GetSelection();
	wxString path = m_editBook->GetPageToolTip(pageIndx);
	openTabs.remove(path);
}