#include "cGui.h"
#include "cFileManager.h"
#include <wx/generic/textdlgg.h>

void cMainFrame::newMod( wxCommandEvent& event )
{
	cNewModDialog* newModDialog = new cNewModDialog(this);
	newModDialog->Show(true);
	event.Skip();
}

void cMainFrame::newSubmod( wxCommandEvent& event )
{
	wxTextEntryDialog submodDialog(NULL, "Enter name for the new Submod", "Submod Name", "", wxOK | wxCANCEL);
	if (submodDialog.ShowModal() == wxID_OK) {
		if (submodDialog.GetValue().IsEmpty() || submodDialog.GetValue().Contains("\\") || submodDialog.GetValue().Contains("/")) {
			wxMessageBox("Submod Cannot Contain Invalid Character such as \"\\\" or \"/\"", "Name Error");
		}
		cFileManager::createSubmod(submodDialog.GetValue().ToStdString());
		cGuiControl::fillFolderTree();
	}
	event.Skip();
}

void cMainFrame::newCategory( wxCommandEvent& event )
{
	cNewCategoryDialog* newCategoryDialog = new cNewCategoryDialog(this);
	newCategoryDialog->Show(true);
	event.Skip();
}

void cMainFrame::newSqfFile( wxCommandEvent& event )
{
	cNewScriptFileDialog* newScriptFileDialog = new cNewScriptFileDialog(this);
	newScriptFileDialog->Show(true);
	event.Skip();
}

void cMainFrame::newHeaderFile(wxCommandEvent& event)
{
	cNewHeaderDialog* newHeaderDialog = new cNewHeaderDialog(this);
	newHeaderDialog->Show(true);
	event.Skip();
}

void cMainFrame::newCfgFile(wxCommandEvent& event)
{

}

void cMainFrame::openProject( wxCommandEvent& event )
{
	WCHAR* path = nullptr;
	if (SUCCEEDED(cFileManager::projectFileOpen(path))) {
		cFileManager::openConfig(path);
	}
	event.Skip();
}

void cMainFrame::openFolder(wxCommandEvent& event)
{
	WCHAR* path;
	if (SUCCEEDED(cFileManager::basicFolderOpen(path))) {
		cFileManager::openProjectFolder(path);
	}
	event.Skip();
}

void cMainFrame::saveProject(wxCommandEvent& event)
{

}

void cMainFrame::saveProjectAs(wxCommandEvent& event)
{

}

void cMainFrame::openOptions( wxCommandEvent& event )
{

}

void cMainFrame::CloseWindow( wxCommandEvent& event )
{
	Destroy();
	event.Skip();
}
