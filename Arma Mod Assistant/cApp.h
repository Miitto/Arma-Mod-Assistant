#pragma once

#include "wx/wx.h"
#include "cGUI.h"
#include "cSettings.h"

class cApp : public wxApp
{
	
public: // Pub Func
	cApp();
	~cApp();
	virtual bool OnInit();

public: // Pub Var
	cMainFrame* m_mainFrame = nullptr;
	cSettings settings;
};

