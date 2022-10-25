#include "cGUI.h"
#include "cFileManager.h"

void cNewCategoryDialog::createCategory( wxCommandEvent& event )
{
	wxString name = m_nameTxtCtrl->GetValue();
	wxString submod = m_submodLB->GetStringSelection();
	if (!submod.IsEmpty()) submod = submod.Append("\\");
	if (!name.IsEmpty() && !(name.Contains('\\') || name.Contains('/'))) {
		BaseOptions settings = cSettings::getBaseSettings();
		std::filesystem::create_directories(std::string(settings.path + submod + "functions\\" + name));
		cFileManager::createCfgFunctions(settings.path.ToStdString(), submod.RemoveLast().ToStdString()); // Recreate CfgFunctions with new Category
		std::ofstream defineFile(std::string(settings.path + "\\functions\\" + name + "\\script_component.hpp"));
		defineFile << "// File Created by Miitto's Arma Mod Assistant" << std::endl;
		defineFile << "#include \"..\\script_component.hpp\"" << std::endl;
		cGuiControl::fillFolderTree();
		Close(true);
	}
	else {
		wxMessageBox(wxT("Name cannot be empty, or contain invalid file name characters, eg. \"\\\" or \"/\""), wxT("Invalid Name"));
	}
	event.Skip();
}

void cNewCategoryDialog::initDialog(wxInitDialogEvent &event) {
	BaseOptions settings = cSettings::getBaseSettings();
	if (settings.type == "simple") {
		m_submodLB->Enable(false);
		m_newSubmod->Enable(false);
	}
	else {
		std::vector<wxString> submodList;
		cFileManager::scanFolders(settings.path, submodList);
		for (std::vector<wxString>::iterator iter = submodList.begin(); iter != submodList.end(); ++iter) {
			m_submodLB->AppendString(*iter);
		}
		if (!submodList.empty()) m_submodLB->SetSelection(0);
	}
	event.Skip();
}

void cNewCategoryDialog::onNameEnter(wxCommandEvent& event) {
	createCategory(event);
}
