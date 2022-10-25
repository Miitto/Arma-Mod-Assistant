#pragma once

#include <wx/stdpaths.h>
#include <wx/config.h>
#include <wx/confbase.h>
#include <wx/fileconf.h>
#include <wx/string.h>
#include "cGuiControl.h"

#include <iostream>
#include <fstream>

#include <filesystem>

struct BaseOptions {
	BaseOptions() {};
	~BaseOptions() {};
	wxString prefix = "";
	wxString name = "";
	wxString author = "";
	wxString addons = "[]";
	wxString path = "";
	wxString type = "";
};

class cSettings
{
private:
	static wxString currentConfigFile;
	static cSettings* mainSettings;
	static BaseOptions* settings;
	std::vector<std::pair<std::string, std::string>> defines;


public:
	cSettings(std::string path, std::string prefix = "", std::string name = "", std::string author = "", std::string addons = "[]", std::string modPath = "", std::string type = "");
	cSettings(std::wstring path, std::wstring prefix = L"", std::wstring name = L"", std::wstring author = L"", std::wstring addons = L"[]", std::wstring modPath = L"", std::wstring type = L"");
	~cSettings();
	static cSettings* getSettings();
	static BaseOptions getBaseSettings() {
		return *settings;
	}
	static BaseOptions setBaseOptions(wxString prefix, wxString name, wxString author, wxString addons, wxString path, wxString type) {
		settings->prefix = prefix;
		settings->name = name;
		settings->author = author;
		settings->addons = addons;
		settings->path = path;
		settings->type = type;
		return *settings;
	}

	static bool setConfigFile(wxString path);
	static bool setConfigFile(std::string path);
	static bool setConfigFile(const char* path);
	static wxString getConfigFile();
};
