#pragma once

#include <wx/wxprec.h>
#include <wx/cmdline.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
#include "cGUI.h"
#include "cSettings.h"
#include "cFileManager.h"
#include "cGuiControl.h"
#include "resource.h"
#include <numeric>

class cApp : public wxApp
{
private:
	bool silent_mode;
	std::string openFile;
	
public: // Pub Func
	cApp();
	~cApp();
	virtual bool OnInit();
	virtual int OnExit();
	virtual int OnRun();
	virtual void OnInitCmdLine(wxCmdLineParser& parser);
	virtual bool OnCmdLineParsed(wxCmdLineParser& parser);

public: // Pub Var
	cMainFrame* m_mainFrame = nullptr;
	cSettings* settings;
};

static const wxCmdLineEntryDesc g_cmdLineDesc[] =
{
	 { wxCMD_LINE_PARAM, NULL, NULL, "Open File", wxCMD_LINE_VAL_STRING, wxCMD_LINE_PARAM_OPTIONAL},
	 { wxCMD_LINE_SWITCH, "h", "help", "displays help on the command line parameters",
		  wxCMD_LINE_VAL_NONE, wxCMD_LINE_OPTION_HELP },
	 { wxCMD_LINE_SWITCH, "t", "test", "test switch"},
	 { wxCMD_LINE_SWITCH, "s", "silent", "disables the GUI" },

	 { wxCMD_LINE_NONE }
};

DECLARE_APP(cApp)
