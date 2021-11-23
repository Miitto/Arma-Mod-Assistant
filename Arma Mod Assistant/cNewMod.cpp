#include "cNewMod.h"
#include "cCommon.h"
#include "cSettings.h"
#include <wx/msgdlg.h>


cNewMod::cNewMod( wxWindow* parent )
:
cNewModDialog( parent )
{

}

void cNewMod::Close( wxCommandEvent& event )
{
// TODO: Implement Close
}

void cNewMod::createMod( wxCommandEvent& event )
{
	cCommon cCommon;
	cSettings cSettings;
	wxFileName modPath = m_pathPicker->GetDirName();
	cSettings.SetWorkingDir(modPath.GetPath());
	std::string modPathStr = std::string(modPath.GetPath().mb_str());
	std::string modName = std::string(m_nameTxtCtrl->GetValue().mb_str());
	std::string modPrefix = std::string(m_prefixTxtCtrl->GetValue().mb_str());
	std::string author = std::string(m_AuthorTxtCtrl->GetValue().mb_str());
	std::string reqMods = std::string(m_addonsTxtCtrl->GetValue().mb_str());

	std::string modPathArma = modPathStr;
	modPathArma.erase(0, 2);

	std::ofstream config(modPathStr + "/config.cpp");
	config << "class CfgPatches" << std::endl << "{" << std::endl << "	class " + modPrefix + "_" + modName + "" << std::endl << "	{" << std::endl << "	name=\"" + modPrefix + " " + modName + "\";" << std::endl << "	units[] = {};" << std::endl << "	weapons[] = {};" << std::endl << "	requiredVersion = 0.1;" << std::endl << "	requiredAddons[] = {" + reqMods + "};" << std::endl << "	author=\"" + author + "\";" << std::endl << "	};" << std::endl << "};" << std::endl << "" << std::endl << "#include \"" + modPathArma + "\\CfgFunctions.hpp\"";
	config.close();
	std::ofstream functions(modPathStr + "/CfgFunctions.hpp");
	functions << "class CfgFunctions" << std::endl << "{" << std::endl << "	class " + modPrefix + "" << std::endl << "	{" << std::endl << "		tag=\"" + modPrefix + "\";" << std::endl << "	};" << std::endl << "};";
	functions.close();
	struct stat info;
	if ((cCommon.dirExists(&(modPathStr + "/functions")[0]) > 0) && (_mkdir(&(modPathStr + "/functions")[0]) != 0))
	{
		wxMessageBox(wxT("Error Creating Functions Folder"), wxT("Functions Error"));
	}
	if ((cCommon.dirExists(&(modPathStr + "/source")[0]) > 0) && (_mkdir(&(modPathStr + "/source")[0]) != 0))
	{
		wxMessageBox(wxT("Error Creating Source Folder"), wxT("Source Error"));
	}
	else {
		std::ofstream projectFile(modPathStr + "/source/" + modPrefix + "_" + modName + ".ama");
		projectFile << L"Arma Mod Assistant" << std::endl << modPathStr << std::endl << modPrefix << std::endl << modName;
		projectFile.close();
	}

	wxWindow::Close();
	event.Skip();
}
