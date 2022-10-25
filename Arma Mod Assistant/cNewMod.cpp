#include "cGUI.h"
#include "cCommon.h"
#include "cFileManager.h"
#include <filesystem>
#include <iostream>
#include <fstream>

void cNewModDialog::CloseDialog( wxCommandEvent& event )
{
	Close(true);
	event.Skip();
}

void cNewModDialog::createMod( wxCommandEvent& event )
{
	wxString prefix = m_prefixTxtCtrl->GetValue();
	wxString name = m_nameTxtCtrl->GetValue();
	wxString author = m_AuthorTxtCtrl->GetValue();
	wxString path = m_pathPicker->GetTextCtrlValue();
	wxString addons = m_addonsTxtCtrl->GetValue();
	
	int selection = m_modTypeRadio->GetSelection();
	wxString type;

	if (selection == 0) type = "simple"; else type = "complex";

	addons.Prepend("{");
	addons.append("}");

	cFileManager::createConfig(path, prefix, name, author, addons, type);
	Close(true);
}
