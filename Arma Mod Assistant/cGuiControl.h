#pragma once

#include <wx/msgdlg.h>
#include <map>

#include "cFileManager.h"
#include "cSettings.h"
#include "cGUI.h"
#include "resource.h"

class folderTreeData : public wxTreeItemData {
public:
	bool isFolder;
	wxString path;

	folderTreeData(bool isFolder, wxString path) : isFolder(isFolder), path(path) {}
};

class cGuiControl
{
private:

	static cMainFrame* mainFrame;
	static wxImageList iconList;
	static void generateIconList();

	

public:
	cGuiControl() {}
	~cGuiControl();

	enum fileTypes {
		ICO_AMA,
		ICO_UNKNOWN,
		ICO_FOLDER,
		ICO_A3P,
		ICO_CPP,
		ICO_HPP,
		ICO_SQF,
		ICO_CFG,
		ICO_PAA,
		ICO_P3D,
		ICO_PNG
	};

	static std::list<wxString> openTabs;
	static int getFileIco(wxString file);
	static std::map<wxString, wxTreeItemId> fileMap;
	static void setMainFrame(cMainFrame* mainFrame);
	static bool fillFolderTree();
	static void setUpGui();
};