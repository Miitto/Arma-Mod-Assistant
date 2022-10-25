#include "cApp.h"

IMPLEMENT_APP(cApp);


cApp::cApp()
{

}

cApp::~cApp()
{

}

bool cApp::OnInit()
{
	if (!wxApp::OnInit())
		return false;


	m_mainFrame = new cMainFrame(nullptr, wxID_ANY, "Miitto - Arma Mod Assistant");
    m_mainFrame->SetIcon(wxICON(AAppIcon));
    if (!silent_mode) m_mainFrame->Show();
    cGuiControl::setMainFrame(m_mainFrame);

    if (!openFile.empty()) cFileManager::openConfig(openFile);

	return true;
}

int cApp::OnExit()
{
    cSettings* settings = cSettings::getSettings();
    delete settings;
	return 0;
}

int cApp::OnRun()
{
    int exitcode = wxApp::OnRun();
    //wxTheClipboard->Flush();
    if (exitcode != 0)
        return exitcode;
    return 0;
}

void cApp::OnInitCmdLine(wxCmdLineParser& parser)
{
    parser.SetDesc(g_cmdLineDesc);
    // must refuse '/' as parameter starter or cannot use "/path" style paths
    parser.SetSwitchChars(wxT("-"));
}

bool cApp::OnCmdLineParsed(wxCmdLineParser& parser)
{
    silent_mode = parser.Found(wxT("s"));
    if (silent_mode) wxMessageBox("Silent Mode", "Info");

    // to get at your unnamed parameters use
    wxArrayString files;
    wxString path;
    for (int i = 0; i < parser.GetParamCount(); i++)
    {
        wxString param = parser.GetParam(i);
        files.Add(param);
        if (param.starts_with("/") || param.starts_with("\\") || (param.c_str()[1]) == ':') {
            openFile = param;
        }
    }

    // and other command line parameters

    // then do what you need with them.
    if (files.empty()) return true;

    return true;
}