#pragma once

#include <wx/stdpaths.h>
#include <wx/config.h>
#include <wx/confbase.h>
#include <wx/fileconf.h>

#include <iostream>
#include <fstream>

#include <filesystem>
namespace fs = std::experimental::filesystem;

class cSettings
{
private:
	wxString workingDir = "";

public:
	cSettings();
	~cSettings();

	void GetWorkingDir(wxString *path);
	void SetWorkingDir(wxString path);
	wxFileConfig* configINI = new wxFileConfig(wxEmptyString, wxEmptyString, wxPathOnly(wxStandardPaths::Get().GetExecutablePath()));
};

