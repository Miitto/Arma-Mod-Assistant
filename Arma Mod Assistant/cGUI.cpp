///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.1-0-g8feb16b3)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "cGUI.h"

///////////////////////////////////////////////////////////////////////////

BEGIN_EVENT_TABLE( cMainFrame, wxFrame )
	EVT_MENU( m_newModId, cMainFrame::_wxFB_newMod )
	EVT_MENU( m_newSubModId, cMainFrame::_wxFB_newSubmod )
	EVT_MENU( m_newCategoryId, cMainFrame::_wxFB_newCategory )
	EVT_MENU( m_sqfId, cMainFrame::_wxFB_newSqfFile )
	EVT_MENU( m_headerId, cMainFrame::_wxFB_newHeaderFile )
	EVT_MENU( m_cfgId, cMainFrame::_wxFB_newCfgFile )
	EVT_MENU( m_openId, cMainFrame::_wxFB_openProject )
	EVT_MENU( m_openFolderId, cMainFrame::_wxFB_openFolder )
	EVT_MENU( m_saveId, cMainFrame::_wxFB_saveProject )
	EVT_MENU( m_saveAsId, cMainFrame::_wxFB_saveProjectAs )
	EVT_MENU( m_optionsId, cMainFrame::_wxFB_openOptions )
	EVT_MENU( m_exitId, cMainFrame::_wxFB_CloseWindow )
	EVT_TREE_ITEM_ACTIVATED( wxID_ANY, cMainFrame::_wxFB_onFileOpened )
	EVT_TREE_SEL_CHANGED( wxID_ANY, cMainFrame::_wxFB_onFileClicked )
	EVT_AUINOTEBOOK_PAGE_CLOSE( m_editBookId, cMainFrame::_wxFB_onPageClose )
END_EVENT_TABLE()

cMainFrame::cMainFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetForegroundColour( wxColour( 75, 75, 75 ) );
	this->SetBackgroundColour( wxColour( 75, 75, 75 ) );
	m_mgr.SetManagedWindow(this);
	m_mgr.SetFlags(wxAUI_MGR_DEFAULT);

	m_menuBar = new wxMenuBar( 0 );
	m_menuBar->SetForegroundColour( wxColour( 75, 75, 75 ) );
	m_menuBar->SetBackgroundColour( wxColour( 75, 75, 75 ) );

	m_file = new wxMenu();
	m_New = new wxMenu();
	wxMenuItem* m_NewItem = new wxMenuItem( m_file, wxID_ANY, wxT("New"), wxEmptyString, wxITEM_NORMAL, m_New );
	wxMenuItem* m_Mod;
	m_Mod = new wxMenuItem( m_New, m_newModId, wxString( wxT("Mod") ) , wxEmptyString, wxITEM_NORMAL );
	m_New->Append( m_Mod );

	wxMenuItem* m_Submod;
	m_Submod = new wxMenuItem( m_New, m_newSubModId, wxString( wxT("Submod") ) , wxEmptyString, wxITEM_NORMAL );
	m_New->Append( m_Submod );

	wxMenuItem* m_Category;
	m_Category = new wxMenuItem( m_New, m_newCategoryId, wxString( wxT("Category") ) , wxEmptyString, wxITEM_NORMAL );
	m_New->Append( m_Category );

	m_newFile = new wxMenu();
	wxMenuItem* m_newFileItem = new wxMenuItem( m_New, wxID_ANY, wxT("File"), wxEmptyString, wxITEM_NORMAL, m_newFile );
	wxMenuItem* m_sqf;
	m_sqf = new wxMenuItem( m_newFile, m_sqfId, wxString( wxT("Script (sqf)") ) , wxEmptyString, wxITEM_NORMAL );
	m_newFile->Append( m_sqf );

	wxMenuItem* m_header;
	m_header = new wxMenuItem( m_newFile, m_headerId, wxString( wxT("Header (hpp)") ) , wxEmptyString, wxITEM_NORMAL );
	m_newFile->Append( m_header );

	wxMenuItem* m_cfg;
	m_cfg = new wxMenuItem( m_newFile, m_cfgId, wxString( wxT("Model.cfg") ) , wxEmptyString, wxITEM_NORMAL );
	m_newFile->Append( m_cfg );

	m_New->Append( m_newFileItem );

	m_file->Append( m_NewItem );

	wxMenuItem* m_open;
	m_open = new wxMenuItem( m_file, m_openId, wxString( wxT("Open") ) , wxEmptyString, wxITEM_NORMAL );
	m_file->Append( m_open );

	wxMenuItem* m_openFolder;
	m_openFolder = new wxMenuItem( m_file, m_openFolderId, wxString( wxT("Open Folder") ) , wxEmptyString, wxITEM_NORMAL );
	m_file->Append( m_openFolder );

	wxMenuItem* m_save;
	m_save = new wxMenuItem( m_file, m_saveId, wxString( wxT("Save") ) , wxEmptyString, wxITEM_NORMAL );
	m_file->Append( m_save );

	wxMenuItem* m_saveAs;
	m_saveAs = new wxMenuItem( m_file, m_saveAsId, wxString( wxT("Save As") ) , wxEmptyString, wxITEM_NORMAL );
	m_file->Append( m_saveAs );

	m_file->AppendSeparator();

	wxMenuItem* m_options;
	m_options = new wxMenuItem( m_file, m_optionsId, wxString( wxT("Options") ) , wxEmptyString, wxITEM_NORMAL );
	m_file->Append( m_options );

	m_file->AppendSeparator();

	wxMenuItem* m_exit;
	m_exit = new wxMenuItem( m_file, m_exitId, wxString( wxT("Exit") ) , wxEmptyString, wxITEM_NORMAL );
	m_file->Append( m_exit );

	m_menuBar->Append( m_file, wxT("File") );

	this->SetMenuBar( m_menuBar );

	m_folderView = new wxTreeCtrl( this, wxID_ANY, wxDefaultPosition, wxSize( 200,-1 ), wxTR_DEFAULT_STYLE );
	m_folderView->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOWTEXT ) );
	m_folderView->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOW ) );
	m_folderView->SetMinSize( wxSize( 100,-1 ) );

	m_mgr.AddPane( m_folderView, wxAuiPaneInfo() .Left() .CaptionVisible( false ).CloseButton( false ).PaneBorder( false ).Movable( false ).Dock().Resizable().FloatingSize( wxDefaultSize ).BottomDockable( false ).TopDockable( false ).LeftDockable( false ).RightDockable( false ).Floatable( false ) );

	m_editBook = new wxAuiNotebook( this, m_editBookId, wxDefaultPosition, wxDefaultSize, wxAUI_NB_DEFAULT_STYLE );
	m_mgr.AddPane( m_editBook, wxAuiPaneInfo() .Center() .CloseButton( false ).Dock().Resizable().FloatingSize( wxDefaultSize ).BottomDockable( false ).TopDockable( false ).LeftDockable( false ).RightDockable( false ).Floatable( false ).CentrePane() );



	m_mgr.Update();
	this->Centre( wxBOTH );
}

cMainFrame::~cMainFrame()
{
	m_mgr.UnInit();

}

BEGIN_EVENT_TABLE( cNewCategoryDialog, wxDialog )
	EVT_INIT_DIALOG( cNewCategoryDialog::_wxFB_initDialog )
	EVT_TEXT_ENTER( wxID_ANY, cNewCategoryDialog::_wxFB_onNameEnter )
	EVT_BUTTON( m_createId, cNewCategoryDialog::_wxFB_createCategory )
END_EVENT_TABLE()

cNewCategoryDialog::cNewCategoryDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( -1,150 ), wxDefaultSize );

	wxFlexGridSizer* mainSizer;
	mainSizer = new wxFlexGridSizer( 0, 3, 0, 0 );
	mainSizer->SetFlexibleDirection( wxBOTH );
	mainSizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );


	mainSizer->Add( 0, 15, 1, wxEXPAND, 5 );


	mainSizer->Add( 0, 0, 1, wxEXPAND, 5 );


	mainSizer->Add( 0, 0, 1, wxEXPAND, 5 );

	m_nameTxt = new wxStaticText( this, wxID_ANY, wxT("Name:"), wxDefaultPosition, wxSize( 50,25 ), 0 );
	m_nameTxt->Wrap( -1 );
	mainSizer->Add( m_nameTxt, 0, wxALL, 5 );

	m_nameTxtCtrl = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 250,25 ), wxTE_PROCESS_ENTER );
	mainSizer->Add( m_nameTxtCtrl, 0, wxALL, 5 );


	mainSizer->Add( 0, 0, 1, wxEXPAND, 5 );

	m_submodTxt = new wxStaticText( this, wxID_ANY, wxT("Submod:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_submodTxt->Wrap( -1 );
	mainSizer->Add( m_submodTxt, 0, wxALL, 5 );

	m_submodLB = new wxListBox( this, wxID_ANY, wxDefaultPosition, wxSize( 250,175 ), 0, NULL, 0 );
	mainSizer->Add( m_submodLB, 0, wxALL, 5 );

	wxFlexGridSizer* newSubmodSizer;
	newSubmodSizer = new wxFlexGridSizer( 0, 1, 0, 0 );
	newSubmodSizer->SetFlexibleDirection( wxBOTH );
	newSubmodSizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );


	newSubmodSizer->Add( 0, 145, 1, wxEXPAND, 5 );

	m_newSubmod = new wxButton( this, m_newSubmodId, wxT("+"), wxDefaultPosition, wxSize( 30,30 ), 0 );
	newSubmodSizer->Add( m_newSubmod, 0, wxALL, 5 );


	mainSizer->Add( newSubmodSizer, 1, wxEXPAND, 5 );


	mainSizer->Add( 0, 0, 1, wxEXPAND, 5 );

	m_create = new wxButton( this, m_createId, wxT("Create"), wxDefaultPosition, wxSize( 250,50 ), 0 );
	mainSizer->Add( m_create, 0, wxALL, 5 );


	this->SetSizer( mainSizer );
	this->Layout();

	this->Centre( wxBOTH );
}

cNewCategoryDialog::~cNewCategoryDialog()
{
}

BEGIN_EVENT_TABLE( cNewScriptFileDialog, wxDialog )
	EVT_INIT_DIALOG( cNewScriptFileDialog::_wxFB_initDialog )
	EVT_LISTBOX( m_submodLBId, cNewScriptFileDialog::_wxFB_submodSelected )
	EVT_BUTTON( m_newSubmodId, cNewScriptFileDialog::_wxFB_newSubmod )
	EVT_BUTTON( m_createCategoryId, cNewScriptFileDialog::_wxFB_createCategory )
	EVT_BUTTON( m_createFileId, cNewScriptFileDialog::_wxFB_createFile )
END_EVENT_TABLE()

cNewScriptFileDialog::cNewScriptFileDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxFlexGridSizer* dialogFlexSizer;
	dialogFlexSizer = new wxFlexGridSizer( 0, 3, 0, 0 );
	dialogFlexSizer->SetFlexibleDirection( wxBOTH );
	dialogFlexSizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );


	dialogFlexSizer->Add( 0, 15, 1, wxEXPAND, 5 );


	dialogFlexSizer->Add( 0, 0, 1, wxEXPAND, 5 );


	dialogFlexSizer->Add( 0, 0, 1, wxEXPAND, 5 );

	m_FileNameTxt = new wxStaticText( this, wxID_ANY, wxT("File Name:"), wxPoint( -1,-1 ), wxSize( 75,25 ), 0 );
	m_FileNameTxt->Wrap( -1 );
	dialogFlexSizer->Add( m_FileNameTxt, 0, wxALL, 5 );

	m_fileNameEdit = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 250,25 ), 0 );
	dialogFlexSizer->Add( m_fileNameEdit, 0, wxALL, 5 );

	m_sqfNotice = new wxStaticText( this, wxID_ANY, wxT(".sqf"), wxDefaultPosition, wxDefaultSize, 0 );
	m_sqfNotice->Wrap( -1 );
	dialogFlexSizer->Add( m_sqfNotice, 0, wxALL, 5 );

	m_submodTxt = new wxStaticText( this, wxID_ANY, wxT("Submod:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_submodTxt->Wrap( -1 );
	dialogFlexSizer->Add( m_submodTxt, 0, wxALL, 5 );

	m_submodLB = new wxListBox( this, m_submodLBId, wxDefaultPosition, wxSize( 250,175 ), 0, NULL, 0 );
	dialogFlexSizer->Add( m_submodLB, 0, wxALL, 5 );

	wxFlexGridSizer* rightFbSizer;
	rightFbSizer = new wxFlexGridSizer( 0, 1, 0, 0 );
	rightFbSizer->SetFlexibleDirection( wxBOTH );
	rightFbSizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	wxString m_initTypeRadioChoices[] = { wxT("None"), wxT("Pre Init"), wxT("Post Init") };
	int m_initTypeRadioNChoices = sizeof( m_initTypeRadioChoices ) / sizeof( wxString );
	m_initTypeRadio = new wxRadioBox( this, m_initTypeRadioId, wxT("InitType"), wxDefaultPosition, wxSize( 100,100 ), m_initTypeRadioNChoices, m_initTypeRadioChoices, 1, wxRA_SPECIFY_COLS );
	m_initTypeRadio->SetSelection( 0 );
	rightFbSizer->Add( m_initTypeRadio, 0, wxALL, 5 );


	rightFbSizer->Add( 0, 35, 1, wxEXPAND, 5 );

	m_newSubmod = new wxButton( this, m_newSubmodId, wxT("+"), wxDefaultPosition, wxSize( 30,30 ), 0 );
	rightFbSizer->Add( m_newSubmod, 0, wxALL, 5 );


	dialogFlexSizer->Add( rightFbSizer, 1, wxEXPAND, 5 );

	m_catTxt = new wxStaticText( this, wxID_ANY, wxT("Category: "), wxDefaultPosition, wxDefaultSize, 0 );
	m_catTxt->Wrap( -1 );
	dialogFlexSizer->Add( m_catTxt, 0, wxALL, 5 );

	m_catLB = new wxListBox( this, m_categoryLBId, wxDefaultPosition, wxSize( 250,175 ), 0, NULL, 0 );
	dialogFlexSizer->Add( m_catLB, 0, wxALL, 5 );

	wxFlexGridSizer* m_newCatSizer;
	m_newCatSizer = new wxFlexGridSizer( 0, 1, 0, 0 );
	m_newCatSizer->SetFlexibleDirection( wxBOTH );
	m_newCatSizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );


	m_newCatSizer->Add( 0, 145, 1, wxEXPAND, 5 );

	m_newCategory = new wxButton( this, m_createCategoryId, wxT("+"), wxDefaultPosition, wxSize( 30,30 ), 0 );
	m_newCatSizer->Add( m_newCategory, 0, wxALL, 5 );


	dialogFlexSizer->Add( m_newCatSizer, 1, wxEXPAND, 5 );


	dialogFlexSizer->Add( 0, 0, 1, wxEXPAND, 5 );

	m_createFile = new wxButton( this, m_createFileId, wxT("Create"), wxDefaultPosition, wxSize( 250,50 ), 0 );
	dialogFlexSizer->Add( m_createFile, 0, wxALL, 5 );


	this->SetSizer( dialogFlexSizer );
	this->Layout();

	this->Centre( wxBOTH );
}

cNewScriptFileDialog::~cNewScriptFileDialog()
{
}

BEGIN_EVENT_TABLE( cNewHeaderDialog, wxDialog )
	EVT_INIT_DIALOG( cNewHeaderDialog::_wxFB_initDialog )
	EVT_LISTBOX( m_submodLBId, cNewHeaderDialog::_wxFB_submodSelected )
	EVT_BUTTON( m_newSubmodId, cNewHeaderDialog::_wxFB_newSubmod )
	EVT_BUTTON( m_createCategoryId, cNewHeaderDialog::_wxFB_createCategory )
	EVT_BUTTON( m_createFileId, cNewHeaderDialog::_wxFB_createFile )
END_EVENT_TABLE()

cNewHeaderDialog::cNewHeaderDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxFlexGridSizer* dialogFlexSizer;
	dialogFlexSizer = new wxFlexGridSizer( 0, 3, 0, 0 );
	dialogFlexSizer->SetFlexibleDirection( wxBOTH );
	dialogFlexSizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );


	dialogFlexSizer->Add( 0, 15, 1, wxEXPAND, 5 );


	dialogFlexSizer->Add( 0, 0, 1, wxEXPAND, 5 );


	dialogFlexSizer->Add( 0, 0, 1, wxEXPAND, 5 );

	m_FileNameTxt = new wxStaticText( this, wxID_ANY, wxT("File Name:"), wxPoint( -1,-1 ), wxSize( 60,25 ), 0 );
	m_FileNameTxt->Wrap( -1 );
	dialogFlexSizer->Add( m_FileNameTxt, 0, wxALL, 5 );

	m_fileNameEdit = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 250,25 ), 0 );
	dialogFlexSizer->Add( m_fileNameEdit, 0, wxALL, 5 );

	m_sqfNotice = new wxStaticText( this, wxID_ANY, wxT(".hpp"), wxDefaultPosition, wxDefaultSize, 0 );
	m_sqfNotice->Wrap( -1 );
	dialogFlexSizer->Add( m_sqfNotice, 0, wxALL, 5 );

	m_submodTxt = new wxStaticText( this, wxID_ANY, wxT("Submod:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_submodTxt->Wrap( -1 );
	dialogFlexSizer->Add( m_submodTxt, 0, wxALL, 5 );

	m_submodLB = new wxListBox( this, m_submodLBId, wxDefaultPosition, wxSize( 250,175 ), 0, NULL, 0 );
	dialogFlexSizer->Add( m_submodLB, 0, wxALL, 5 );

	wxFlexGridSizer* rightFbSizer;
	rightFbSizer = new wxFlexGridSizer( 0, 1, 0, 0 );
	rightFbSizer->SetFlexibleDirection( wxBOTH );
	rightFbSizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );


	rightFbSizer->Add( 0, 145, 1, wxEXPAND, 5 );

	m_newSubmod = new wxButton( this, m_newSubmodId, wxT("+"), wxDefaultPosition, wxSize( 30,30 ), 0 );
	rightFbSizer->Add( m_newSubmod, 0, wxALL, 5 );


	dialogFlexSizer->Add( rightFbSizer, 1, wxEXPAND, 5 );

	m_catTxt = new wxStaticText( this, wxID_ANY, wxT("Category: "), wxDefaultPosition, wxDefaultSize, 0 );
	m_catTxt->Wrap( -1 );
	dialogFlexSizer->Add( m_catTxt, 0, wxALL, 5 );

	m_catLB = new wxListBox( this, m_categoryLBId, wxDefaultPosition, wxSize( 250,175 ), 0, NULL, 0 );
	dialogFlexSizer->Add( m_catLB, 0, wxALL, 5 );

	wxFlexGridSizer* m_newCatSizer;
	m_newCatSizer = new wxFlexGridSizer( 0, 1, 0, 0 );
	m_newCatSizer->SetFlexibleDirection( wxBOTH );
	m_newCatSizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );


	m_newCatSizer->Add( 0, 145, 1, wxEXPAND, 5 );

	m_newCategory = new wxButton( this, m_createCategoryId, wxT("+"), wxDefaultPosition, wxSize( 30,30 ), 0 );
	m_newCatSizer->Add( m_newCategory, 0, wxALL, 5 );


	dialogFlexSizer->Add( m_newCatSizer, 1, wxEXPAND, 5 );


	dialogFlexSizer->Add( 0, 0, 1, wxEXPAND, 5 );

	m_createFile = new wxButton( this, m_createFileId, wxT("Create"), wxDefaultPosition, wxSize( 250,50 ), 0 );
	dialogFlexSizer->Add( m_createFile, 0, wxALL, 5 );


	this->SetSizer( dialogFlexSizer );
	this->Layout();

	this->Centre( wxBOTH );
}

cNewHeaderDialog::~cNewHeaderDialog()
{
}

BEGIN_EVENT_TABLE( cNewModDialog, wxDialog )
	EVT_BUTTON( m_cancelId, cNewModDialog::_wxFB_CloseDialog )
	EVT_BUTTON( m_createModId, cNewModDialog::_wxFB_createMod )
END_EVENT_TABLE()

cNewModDialog::cNewModDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOWTEXT ) );
	this->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOW ) );
	m_mgr.SetManagedWindow(this);
	m_mgr.SetFlags(wxAUI_MGR_DEFAULT);

	m_prefixTxt = new wxStaticText( this, wxID_ANY, wxT("Prefix"), wxPoint( 10,25 ), wxSize( 75,27 ), wxALIGN_CENTER_HORIZONTAL|wxST_NO_AUTORESIZE );
	m_prefixTxt->Wrap( -1 );
	m_prefixTxt->SetFont( wxFont( 18, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Arial") ) );
	m_prefixTxt->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOWTEXT ) );
	m_prefixTxt->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOW ) );

	m_mgr.AddPane( m_prefixTxt, wxAuiPaneInfo() .Left() .CaptionVisible( false ).CloseButton( false ).PaneBorder( false ).Movable( false ).Dock().Fixed().BottomDockable( false ).TopDockable( false ).LeftDockable( false ).RightDockable( false ).Floatable( false ).Position( 25 ) );

	m_NameTxt = new wxStaticText( this, wxID_ANY, wxT("Name"), wxPoint( 10,25 ), wxSize( 75,27 ), wxALIGN_CENTER_HORIZONTAL|wxST_NO_AUTORESIZE );
	m_NameTxt->Wrap( -1 );
	m_NameTxt->SetFont( wxFont( 18, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Arial") ) );

	m_mgr.AddPane( m_NameTxt, wxAuiPaneInfo() .Left() .CaptionVisible( false ).CloseButton( false ).PaneBorder( false ).Movable( false ).Dock().Fixed().BottomDockable( false ).TopDockable( false ).LeftDockable( false ).RightDockable( false ).Floatable( false ).Position( 75 ) );

	m_Author = new wxStaticText( this, wxID_ANY, wxT("Author"), wxPoint( 10,25 ), wxSize( 75,27 ), wxALIGN_CENTER_HORIZONTAL|wxST_NO_AUTORESIZE );
	m_Author->Wrap( -1 );
	m_Author->SetFont( wxFont( 18, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Arial") ) );

	m_mgr.AddPane( m_Author, wxAuiPaneInfo() .Left() .CaptionVisible( false ).CloseButton( false ).PaneBorder( false ).Movable( false ).Dock().Fixed().BottomDockable( false ).TopDockable( false ).LeftDockable( false ).RightDockable( false ).Floatable( false ).Position( 125 ) );

	m_addonsTxt = new wxStaticText( this, wxID_ANY, wxT("Req Addons"), wxPoint( 10,25 ), wxSize( 100,60 ), wxALIGN_CENTER_HORIZONTAL|wxST_NO_AUTORESIZE );
	m_addonsTxt->Wrap( -1 );
	m_addonsTxt->SetFont( wxFont( 18, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Arial") ) );

	m_mgr.AddPane( m_addonsTxt, wxAuiPaneInfo() .Left() .CaptionVisible( false ).CloseButton( false ).PaneBorder( false ).Movable( false ).Dock().Fixed().BottomDockable( false ).TopDockable( false ).LeftDockable( false ).RightDockable( false ).Floatable( false ).Position( 175 ) );

	m_PathTxt = new wxStaticText( this, wxID_ANY, wxT("Path"), wxPoint( 10,25 ), wxSize( 75,27 ), wxALIGN_CENTER_HORIZONTAL|wxST_NO_AUTORESIZE );
	m_PathTxt->Wrap( -1 );
	m_PathTxt->SetFont( wxFont( 18, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Arial") ) );

	m_mgr.AddPane( m_PathTxt, wxAuiPaneInfo() .Left() .CaptionVisible( false ).CloseButton( false ).PaneBorder( false ).Movable( false ).Dock().Fixed().BottomDockable( false ).TopDockable( false ).LeftDockable( false ).RightDockable( false ).Floatable( false ).Position( 325 ) );

	m_prefixTxtCtrl = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxPoint( 10,25 ), wxSize( 300,30 ), 0 );
	m_mgr.AddPane( m_prefixTxtCtrl, wxAuiPaneInfo() .Left() .CaptionVisible( false ).CloseButton( false ).PaneBorder( false ).Movable( false ).Dock().Fixed().BottomDockable( false ).TopDockable( false ).LeftDockable( false ).RightDockable( false ).Floatable( false ).Row( 1 ).Position( 25 ) );

	m_nameTxtCtrl = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxPoint( 10,25 ), wxSize( 300,30 ), 0 );
	m_mgr.AddPane( m_nameTxtCtrl, wxAuiPaneInfo() .Left() .CaptionVisible( false ).CloseButton( false ).PaneBorder( false ).Movable( false ).Dock().Fixed().BottomDockable( false ).TopDockable( false ).LeftDockable( false ).RightDockable( false ).Floatable( false ).Row( 1 ).Position( 75 ) );

	m_AuthorTxtCtrl = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxPoint( 10,25 ), wxSize( 300,30 ), 0 );
	m_mgr.AddPane( m_AuthorTxtCtrl, wxAuiPaneInfo() .Left() .CaptionVisible( false ).CloseButton( false ).PaneBorder( false ).Movable( false ).Dock().Fixed().BottomDockable( false ).TopDockable( false ).LeftDockable( false ).RightDockable( false ).Floatable( false ).Row( 1 ).Position( 125 ) );

	m_addonsTxtCtrl = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxPoint( 10,25 ), wxSize( 300,60 ), 0 );
	m_addonsTxtCtrl->SetToolTip( wxT("Comma seperated mod class names in speech marks.\nE.g | \"ace_main\",\"cba_main\" | would add CBA and ACE as required") );

	m_mgr.AddPane( m_addonsTxtCtrl, wxAuiPaneInfo() .Left() .CaptionVisible( false ).CloseButton( false ).PaneBorder( false ).Movable( false ).Dock().Fixed().BottomDockable( false ).TopDockable( false ).LeftDockable( false ).RightDockable( false ).Floatable( false ).Row( 1 ).Position( 175 ) );

	m_cancel = new wxButton( this, m_cancelId, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_mgr.AddPane( m_cancel, wxAuiPaneInfo() .Bottom() .CaptionVisible( false ).CloseButton( false ).PaneBorder( false ).Movable( false ).Dock().Fixed().BottomDockable( false ).TopDockable( false ).LeftDockable( false ).RightDockable( false ).Floatable( false ) );

	m_create = new wxButton( this, m_createModId, wxT("Create"), wxPoint( -1,-1 ), wxSize( 150,50 ), 0 );
	m_mgr.AddPane( m_create, wxAuiPaneInfo() .Left() .CaptionVisible( false ).CloseButton( false ).PaneBorder( false ).Movable( false ).Dock().Fixed().DockFixed( true ).BottomDockable( false ).TopDockable( false ).LeftDockable( false ).RightDockable( false ).Floatable( false ).Row( 1 ).Position( 375 ).Layer( 0 ) );

	m_pathPicker = new wxDirPickerCtrl( this, wxID_ANY, wxEmptyString, wxT("Select a folder"), wxDefaultPosition, wxDefaultSize, wxDIRP_DEFAULT_STYLE );
	m_mgr.AddPane( m_pathPicker, wxAuiPaneInfo() .Left() .CaptionVisible( false ).Movable( false ).Dock().Fixed().BottomDockable( false ).TopDockable( false ).LeftDockable( false ).RightDockable( false ).Floatable( false ).Row( 1 ).Position( 325 ) );

	wxString m_modTypeRadioChoices[] = { wxT("Simple"), wxT("Complex (Multi)") };
	int m_modTypeRadioNChoices = sizeof( m_modTypeRadioChoices ) / sizeof( wxString );
	m_modTypeRadio = new wxRadioBox( this, modTypeRadio, wxT("Mod Type"), wxPoint( -1,100 ), wxSize( -1,-1 ), m_modTypeRadioNChoices, m_modTypeRadioChoices, 1, wxRA_SPECIFY_COLS );
	m_modTypeRadio->SetSelection( 0 );
	m_mgr.AddPane( m_modTypeRadio, wxAuiPaneInfo() .Right() .CaptionVisible( false ).CloseButton( false ).PaneBorder( false ).Movable( false ).Dock().Fixed().DockFixed( true ).BottomDockable( false ).TopDockable( false ).LeftDockable( false ).RightDockable( false ).Floatable( false ).Row( 1 ).Position( 250 ).BestSize( wxSize( 150,125 ) ) );


	m_mgr.Update();
	this->Centre( wxBOTH );
}

cNewModDialog::~cNewModDialog()
{
	m_mgr.UnInit();

}

BEGIN_EVENT_TABLE( cNewSubmodDialog, wxDialog )
	EVT_BUTTON( wxID_ANY, cNewSubmodDialog::_wxFB_CloseDialog )
	EVT_BUTTON( wxID_ANY, cNewSubmodDialog::_wxFB_createMod )
END_EVENT_TABLE()

cNewSubmodDialog::cNewSubmodDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOWTEXT ) );
	this->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOW ) );
	m_mgr.SetManagedWindow(this);
	m_mgr.SetFlags(wxAUI_MGR_DEFAULT);

	m_NameTxt = new wxStaticText( this, wxID_ANY, wxT("Name"), wxPoint( 0,0 ), wxSize( 75,27 ), wxALIGN_CENTER_HORIZONTAL|wxST_NO_AUTORESIZE );
	m_NameTxt->Wrap( -1 );
	m_NameTxt->SetFont( wxFont( 18, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Arial") ) );

	m_mgr.AddPane( m_NameTxt, wxAuiPaneInfo() .Left() .CaptionVisible( false ).CloseButton( false ).PaneBorder( false ).Movable( false ).Dock().Fixed().BottomDockable( false ).TopDockable( false ).LeftDockable( false ).RightDockable( false ).Floatable( false ).Position( 25 ) );

	m_addonsTxt = new wxStaticText( this, wxID_ANY, wxT("Req Addons"), wxPoint( 10,25 ), wxSize( 100,60 ), wxALIGN_CENTER_HORIZONTAL|wxST_NO_AUTORESIZE );
	m_addonsTxt->Wrap( -1 );
	m_addonsTxt->SetFont( wxFont( 18, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Arial") ) );

	m_mgr.AddPane( m_addonsTxt, wxAuiPaneInfo() .Left() .CaptionVisible( false ).CloseButton( false ).PaneBorder( false ).Movable( false ).Dock().Fixed().BottomDockable( false ).TopDockable( false ).LeftDockable( false ).RightDockable( false ).Floatable( false ).Position( 75 ) );

	m_nameTxtCtrl = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxPoint( 0,0 ), wxSize( 300,30 ), 0 );
	m_mgr.AddPane( m_nameTxtCtrl, wxAuiPaneInfo() .Left() .CaptionVisible( false ).CloseButton( false ).PaneBorder( false ).Movable( false ).Dock().Fixed().BottomDockable( false ).TopDockable( false ).LeftDockable( false ).RightDockable( false ).Floatable( false ).Row( 1 ).Position( 25 ) );

	m_addonsTxtCtrl = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxPoint( 10,25 ), wxSize( 300,60 ), 0 );
	m_addonsTxtCtrl->SetToolTip( wxT("Comma seperated mod class names in speech marks.\nE.g | \"ace_main\",\"cba_main\" | would add CBA and ACE as required") );

	m_mgr.AddPane( m_addonsTxtCtrl, wxAuiPaneInfo() .Left() .CaptionVisible( false ).CloseButton( false ).PaneBorder( false ).Movable( false ).Dock().Fixed().BottomDockable( false ).TopDockable( false ).LeftDockable( false ).RightDockable( false ).Floatable( false ).Row( 1 ).Position( 75 ) );

	m_cancel = new wxButton( this, wxID_ANY, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_mgr.AddPane( m_cancel, wxAuiPaneInfo() .Bottom() .CaptionVisible( false ).CloseButton( false ).PaneBorder( false ).Movable( false ).Dock().Fixed().BottomDockable( false ).TopDockable( false ).LeftDockable( false ).RightDockable( false ).Floatable( false ) );

	m_create = new wxButton( this, wxID_ANY, wxT("Create"), wxPoint( -1,-1 ), wxSize( 150,50 ), 0 );
	m_mgr.AddPane( m_create, wxAuiPaneInfo() .Left() .CaptionVisible( false ).CloseButton( false ).PaneBorder( false ).Movable( false ).Dock().Fixed().DockFixed( true ).BottomDockable( false ).TopDockable( false ).LeftDockable( false ).RightDockable( false ).Floatable( false ).Row( 1 ).Position( 150 ).Layer( 0 ) );


	m_mgr.Update();
	this->Centre( wxBOTH );
}

cNewSubmodDialog::~cNewSubmodDialog()
{
	m_mgr.UnInit();

}
