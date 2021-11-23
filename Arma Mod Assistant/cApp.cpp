/*
https://stackoverflow.com/questions/70028491/wxwidgets-wx-form-builder-inheritance-class-events
*/

#include "cApp.h"

wxIMPLEMENT_APP(cApp);


cApp::cApp()
{

}

cApp::~cApp()
{

}

bool cApp::OnInit()
{
	m_mainFrame = new cMainFrame(nullptr, wxID_ANY, "Miitto - Arma Mod Assistant");
	m_mainFrame->Show();

	return true;
}