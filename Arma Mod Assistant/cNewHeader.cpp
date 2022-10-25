#include "cGUI.h"
#include "cFileManager.h"
#include <wx/generic/textdlgg.h>

void cNewHeaderDialog::createFile(wxCommandEvent& event)
{

	wxString name = m_fileNameEdit->GetValue();
	wxString category = m_catLB->GetStringSelection();
	wxString submod = m_submodLB->GetStringSelection();
	if (!submod.IsEmpty()) submod = submod.Append("\\");
	if (!name.IsEmpty() && !(name.Contains('\\') || name.Contains('/'))) {
		BaseOptions settings = cSettings::getBaseSettings();
		if (!cFileManager::fileExists(settings.path + submod + "functions\\" + category + "\\" + name + ".hpp")) {
			std::ofstream headerFile(std::string(settings.path + submod + "functions\\" + category + "\\" + name + ".hpp"));
			headerFile << "// File Created by Miitto's Arma Mod Assistant" << std::endl;
			headerFile << "#include \"..\\script_component.hpp\"" << std::endl;
			headerFile.close();
		}
		cGuiControl::fillFolderTree();
		Close(true);
	}
	else {
		wxMessageBox(wxT("Name cannot be empty, or contain invalid file name characters, eg. \"\\\" or \"/\""), wxT("Invalid Name"));
	}
	event.Skip();
}

void cNewHeaderDialog::createCategory(wxCommandEvent& event)
{
	BaseOptions settings = cSettings::getBaseSettings();
	wxString submod = m_submodLB->GetStringSelection();
	if (submod.IsEmpty() && settings.type == "complex") {
		wxMessageBox("Please Selected a Submod First", "Invalid Submod");
		return;
	}
	else submod.Append("\\");
	wxTextEntryDialog categoryDialog(NULL, "Enter name for the new Category", "Category Name", "", wxOK | wxCANCEL);
	if (categoryDialog.ShowModal() == wxID_OK) {
		if (categoryDialog.GetValue().Contains("\\") || categoryDialog.GetValue().Contains("/")) {
			wxMessageBox("Submod Cannot Contain Invalid Character such as \"\\\" or \"/\"", "Name Error");
			return;
		}
		std::filesystem::create_directories(std::string(settings.path + submod + "functions\\" + categoryDialog.GetValue()));
		cFileManager::createCfgFunctions(settings.path.ToStdString(), submod.RemoveLast().ToStdString()); // Recreate CfgFunctions with new Category
		cGuiControl::fillFolderTree();
		std::vector<wxString> categoryList;
		cFileManager::scanFolders(settings.path + submod + "functions", categoryList);
		m_catLB->Clear();
		for (std::vector<wxString>::iterator iter = categoryList.begin(); iter != categoryList.end(); ++iter) {
			m_catLB->AppendString(*iter);
		}
	}
	event.Skip();
}

void cNewHeaderDialog::newSubmod(wxCommandEvent& event) {
	wxTextEntryDialog submodDialog(NULL, "Enter name for the new Submod", "Submod Name", "", wxOK | wxCANCEL);
	if (submodDialog.ShowModal() == wxID_OK) {
		if (submodDialog.GetValue().Contains("\\") || submodDialog.GetValue().Contains("/")) {
			wxMessageBox("Submod Cannot Contain Invalid Character such as \"\\\" or \"/\"", "Name Error");
			return;
		}
		BaseOptions settings = cSettings::getBaseSettings();
		cFileManager::createSubmod(submodDialog.GetValue().ToStdString());
		std::vector<wxString> submodList;
		cFileManager::scanFolders(settings.path, submodList);
		m_submodLB->Clear();
		for (std::vector<wxString>::iterator iter = submodList.begin(); iter != submodList.end(); ++iter) {
			m_submodLB->AppendString(*iter);
		}
	}
	event.Skip();
}

void cNewHeaderDialog::initDialog(wxInitDialogEvent& event) {
	BaseOptions settings = cSettings::getBaseSettings();

	if (settings.type == "simple") {
		m_submodLB->Enable(false);
		m_newSubmod->Enable(false);
		std::vector<wxString> catList;
		cFileManager::scanFolders(wxString(settings.path + "/functions"), catList);
		m_catLB->Clear();
		for (std::vector<wxString>::iterator iter = catList.begin(); iter != catList.end(); ++iter) {
			m_catLB->AppendString(*iter);
		}
	}
	else {
		std::vector<wxString> submodList;
		cFileManager::scanFolders(settings.path, submodList);
		m_submodLB->Clear();
		for (std::vector<wxString>::iterator iter = submodList.begin(); iter != submodList.end(); ++iter) {
			m_submodLB->AppendString(*iter);
		}
	}
}

void cNewHeaderDialog::submodSelected(wxCommandEvent& event) {
	BaseOptions settings = cSettings::getBaseSettings();
	if (settings.type == "simple") {
		event.Skip();
		return;
	}
	wxString submod = m_submodLB->GetStringSelection();
	m_catLB->Clear();

	std::vector<wxString> catList;
	cFileManager::scanFolders(wxString(settings.path + "\\" + submod + "/functions"), catList);
	for (std::vector<wxString>::iterator iter = catList.begin(); iter != catList.end(); ++iter) {
		m_catLB->AppendString(*iter);
	}
	event.Skip();
}