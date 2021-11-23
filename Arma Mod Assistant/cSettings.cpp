#include "cSettings.h"

cSettings::cSettings()
{
	GetWorkingDir(&workingDir);
	 
}

cSettings::~cSettings()
{
	delete configINI;
}

void cSettings::GetWorkingDir(wxString *path)
{
	wxFileName f(wxStandardPaths::Get().GetExecutablePath());
	wxString appPath(f.GetPath() + _T("\\config.ini"));
	configINI->SetPath(appPath);

	configINI->SetPath("/settings");
	*path = configINI->Read("WorkingDir", "P:/");
}

void cSettings::SetWorkingDir(wxString path)
{
	wxFileName f(wxStandardPaths::Get().GetExecutablePath());
	wxString appPath(f.GetPath() + _T("\\config.ini"));
	configINI->SetPath(appPath);

	configINI->SetPath("/settings");
	configINI->Write("WorkingDir", path);
}