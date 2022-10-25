#pragma once
#include <Windows.h>
#include <shobjidl.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <wx/string.h>
#include "cSettings.h"
#include "CDialogEventHandler.h"
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <stdio.h>

#include <wx/log.h> 

class cFileManager
{
public:
	cFileManager();
	~cFileManager();

	// Project File
	static bool readConfig(std::string configPath, std::string& prefix, std::string& name, std::string& author, std::string& addons, std::string& path, std::string& type);
	static bool readConfig(wxString configPath, wxString& prefix, wxString& name, wxString& author, wxString& addons, wxString& path, wxString& type);
	static bool createConfig(std::string path, std::string prefix, std::string name, std::string author, std::string addons, std::string type);
	static bool createConfig(wxString path, wxString prefix, wxString name, wxString author, wxString addons, wxString type);
	static bool openConfig(std::string path);
	static bool openConfig(PWSTR path);
	static bool saveConfig();
	static bool saveConfig(std::string path);
	static bool saveConfig(PWSTR path);

	static bool openProjectFolder(std::string path);
	static bool openProjectFolder(PWSTR path);

	static bool createSubmod(std::string name);

	static bool createConfigCpp(std::string path = "", std::string name = "");
	static bool createCfgFunctions(std::string path = "", std::string name = "");

	static bool fileExists(wxString path);

	// Scan Project Folders
	static unsigned int scanFolders(wxString path, std::vector<wxString>& foundFolders);
	static unsigned int scanFiles(wxString path, std::vector<wxString>& foundFiles, wxString parent = "");


	// File Manager Dialog
	static HRESULT basicFileOpen(WCHAR*& path);
	static HRESULT projectFileOpen(WCHAR*& path);
	static HRESULT basicFolderOpen(WCHAR*& path);
};

