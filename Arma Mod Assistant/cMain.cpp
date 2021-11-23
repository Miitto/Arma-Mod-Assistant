#include "cMain.h"
#include <wx/msgdlg.h>

cMain::cMain( wxWindow* parent )
:
cMainFrame( parent )
{

}

void cMain::newMod( wxCommandEvent& event )
{
	wxMessageBox(wxT("CALLED"));
	cNewModDialog* m_newModDialog = new cNewModDialog(nullptr);
	m_newModDialog->Show();
	event.Skip();
}

void cMain::newSubmod( wxCommandEvent& event )
{
// TODO: Implement newSubmod
}

void cMain::newCategory( wxCommandEvent& event )
{
// TODO: Implement newCategory
}

void cMain::newFile( wxCommandEvent& event )
{
// TODO: Implement newFile
}

void cMain::openProject( wxCommandEvent& event )
{
// TODO: Implement openProject
}

void cMain::openOptions( wxCommandEvent& event )
{
// TODO: Implement openOptions
}

void cMain::Close( wxCommandEvent& event )
{
// TODO: Implement Close
}
