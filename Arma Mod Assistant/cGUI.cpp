///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.1-0-g8feb16b3)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "cGUI.h"

///////////////////////////////////////////////////////////////////////////

cMainFrame::cMainFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	m_mgr.SetManagedWindow(this);
	m_mgr.SetFlags(wxAUI_MGR_DEFAULT);

	m_menuBar = new wxMenuBar( 0 );
	m_file = new wxMenu();
	m_New = new wxMenu();
	wxMenuItem* m_NewItem = new wxMenuItem( m_file, wxID_ANY, wxT("New"), wxEmptyString, wxITEM_NORMAL, m_New );
	wxMenuItem* m_Mod;
	m_Mod = new wxMenuItem( m_New, id_newModMenu, wxString( wxT("Mod") ) , wxEmptyString, wxITEM_NORMAL );
	m_New->Append( m_Mod );

	wxMenuItem* m_Submod;
	m_Submod = new wxMenuItem( m_New, wxID_ANY, wxString( wxT("Submod") ) , wxEmptyString, wxITEM_NORMAL );
	m_New->Append( m_Submod );

	wxMenuItem* m_Category;
	m_Category = new wxMenuItem( m_New, wxID_ANY, wxString( wxT("Category") ) , wxEmptyString, wxITEM_NORMAL );
	m_New->Append( m_Category );

	m_newFile = new wxMenu();
	wxMenuItem* m_newFileItem = new wxMenuItem( m_New, wxID_ANY, wxT("File"), wxEmptyString, wxITEM_NORMAL, m_newFile );
	wxMenuItem* m_sqf;
	m_sqf = new wxMenuItem( m_newFile, sqfMenuItem, wxString( wxT("Script (sqf)") ) , wxEmptyString, wxITEM_NORMAL );
	m_newFile->Append( m_sqf );

	wxMenuItem* m_header;
	m_header = new wxMenuItem( m_newFile, hppMenuItem, wxString( wxT("Header (hpp)") ) , wxEmptyString, wxITEM_NORMAL );
	m_newFile->Append( m_header );

	wxMenuItem* m_cfg;
	m_cfg = new wxMenuItem( m_newFile, cfgMenuItem, wxString( wxT("Model.cfg") ) , wxEmptyString, wxITEM_NORMAL );
	m_newFile->Append( m_cfg );

	m_New->Append( m_newFileItem );

	m_file->Append( m_NewItem );

	wxMenuItem* m_open;
	m_open = new wxMenuItem( m_file, wxID_ANY, wxString( wxT("Open") ) , wxEmptyString, wxITEM_NORMAL );
	m_file->Append( m_open );

	wxMenuItem* m_options;
	m_options = new wxMenuItem( m_file, wxID_ANY, wxString( wxT("Options") ) , wxEmptyString, wxITEM_NORMAL );
	m_file->Append( m_options );

	m_file->AppendSeparator();

	wxMenuItem* m_exit;
	m_exit = new wxMenuItem( m_file, wxID_ANY, wxString( wxT("Exit") ) , wxEmptyString, wxITEM_NORMAL );
	m_file->Append( m_exit );

	m_menuBar->Append( m_file, wxT("File") );

	this->SetMenuBar( m_menuBar );

	m_folderView = new wxTreeCtrl( this, wxID_ANY, wxDefaultPosition, wxSize( 150,-1 ), wxTR_DEFAULT_STYLE );
	m_folderView->SetMinSize( wxSize( 100,-1 ) );

	m_mgr.AddPane( m_folderView, wxAuiPaneInfo() .Left() .CaptionVisible( false ).CloseButton( false ).PaneBorder( false ).Movable( false ).Dock().Resizable().FloatingSize( wxDefaultSize ).BottomDockable( false ).TopDockable( false ).LeftDockable( false ).RightDockable( false ).Floatable( false ) );

	m_editBook = new wxNotebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	m_mgr.AddPane( m_editBook, wxAuiPaneInfo() .Center() .CloseButton( false ).Dock().Resizable().FloatingSize( wxDefaultSize ).BottomDockable( false ).TopDockable( false ).LeftDockable( false ).RightDockable( false ).Floatable( false ).CentrePane() );

	SetMenuBar(m_menuBar);

	m_mgr.Update();
	this->Centre( wxBOTH );

	// Connect Events
	m_New->Bind(wxEVT_MENU, &cMainFrame::newMod, this, m_Mod->GetId());
	m_New->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( cMainFrame::newSubmod ), this, m_Submod->GetId());
	m_New->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( cMainFrame::newCategory ), this, m_Category->GetId());
	m_newFile->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( cMainFrame::newFile ), this, m_sqf->GetId());
	m_newFile->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( cMainFrame::newFile ), this, m_header->GetId());
	m_newFile->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( cMainFrame::newFile ), this, m_cfg->GetId());
	m_file->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( cMainFrame::openProject ), this, m_open->GetId());
	m_file->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( cMainFrame::openOptions ), this, m_options->GetId());
	m_file->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( cMainFrame::Close ), this, m_exit->GetId());
}

cMainFrame::~cMainFrame()
{
	// Disconnect Events

	m_mgr.UnInit();

}

cNewScriptFileDialog::cNewScriptFileDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	m_mgr.SetManagedWindow(this);
	m_mgr.SetFlags(wxAUI_MGR_DEFAULT);

	m_NameTxt = new wxStaticText( this, wxID_ANY, wxT("Name"), wxPoint( 10,25 ), wxSize( 75,27 ), wxALIGN_CENTER_HORIZONTAL|wxST_NO_AUTORESIZE );
	m_NameTxt->Wrap( -1 );
	m_NameTxt->SetFont( wxFont( 18, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Arial") ) );

	m_mgr.AddPane( m_NameTxt, wxAuiPaneInfo() .Left() .CaptionVisible( false ).CloseButton( false ).PaneBorder( false ).Movable( false ).Dock().Fixed().BottomDockable( false ).TopDockable( false ).LeftDockable( false ).RightDockable( false ).Floatable( false ).Position( 25 ) );

	m_NameInfo = new wxStaticText( this, wxID_ANY, wxT("No fn_ prefix or .sqf suffix required (eg. \"hello\" will be created as fn_hello.sqf)"), wxDefaultPosition, wxSize( -1,30 ), 0 );
	m_NameInfo->Wrap( 1 );
	m_mgr.AddPane( m_NameInfo, wxAuiPaneInfo() .Left() .CaptionVisible( false ).CloseButton( false ).PaneBorder( false ).Movable( false ).Dock().Fixed().BottomDockable( false ).TopDockable( false ).LeftDockable( false ).RightDockable( false ).Floatable( false ).Row( 2 ).Position( 25 ) );

	m_CategoryTxt = new wxStaticText( this, wxID_ANY, wxT("Category"), wxPoint( 10,25 ), wxSize( 75,22 ), wxALIGN_CENTER_HORIZONTAL|wxST_NO_AUTORESIZE );
	m_CategoryTxt->Wrap( -1 );
	m_CategoryTxt->SetFont( wxFont( 12, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Arial") ) );

	m_mgr.AddPane( m_CategoryTxt, wxAuiPaneInfo() .Left() .CaptionVisible( false ).CloseButton( false ).PaneBorder( false ).Movable( false ).Dock().Fixed().BottomDockable( false ).TopDockable( false ).LeftDockable( false ).RightDockable( false ).Floatable( false ).Position( 75 ) );

	m_nameTxtCtrl = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxPoint( 10,25 ), wxSize( 300,30 ), 0 );
	m_mgr.AddPane( m_nameTxtCtrl, wxAuiPaneInfo() .Left() .CaptionVisible( false ).CloseButton( false ).PaneBorder( false ).Movable( false ).Dock().Fixed().BottomDockable( false ).TopDockable( false ).LeftDockable( false ).RightDockable( false ).Floatable( false ).Row( 1 ).Position( 25 ) );

	m_categoryLB = new wxListBox( this, wxID_ANY, wxDefaultPosition, wxSize( -1,300 ), 0, NULL, 0 );
	m_mgr.AddPane( m_categoryLB, wxAuiPaneInfo() .Left() .CaptionVisible( false ).CloseButton( false ).Movable( false ).Dock().Fixed().BottomDockable( false ).TopDockable( false ).LeftDockable( false ).RightDockable( false ).Floatable( false ).Row( 1 ).Position( 75 ) );

	m_cancel = new wxButton( this, wxID_ANY, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_mgr.AddPane( m_cancel, wxAuiPaneInfo() .Bottom() .CaptionVisible( false ).CloseButton( false ).PaneBorder( false ).Movable( false ).Dock().Fixed().BottomDockable( false ).TopDockable( false ).LeftDockable( false ).RightDockable( false ).Floatable( false ) );

	m_create = new wxButton( this, wxID_ANY, wxT("Create"), wxPoint( -1,-1 ), wxSize( 150,50 ), 0 );
	m_mgr.AddPane( m_create, wxAuiPaneInfo() .Left() .CaptionVisible( false ).CloseButton( false ).PaneBorder( false ).Movable( false ).Dock().Fixed().DockFixed( true ).BottomDockable( false ).TopDockable( false ).LeftDockable( false ).RightDockable( false ).Floatable( false ).Row( 1 ).Position( 300 ).Layer( 0 ) );

	wxString m_initTypeChoices[] = { wxT("Normal"), wxT("Post Init"), wxT("Pre Init") };
	int m_initTypeNChoices = sizeof( m_initTypeChoices ) / sizeof( wxString );
	m_initType = new wxRadioBox( this, wxID_ANY, wxT("Init Type"), wxDefaultPosition, wxDefaultSize, m_initTypeNChoices, m_initTypeChoices, 1, wxRA_SPECIFY_COLS );
	m_initType->SetSelection( 0 );
	m_mgr.AddPane( m_initType, wxAuiPaneInfo() .Left() .CaptionVisible( false ).CloseButton( false ).PaneBorder( false ).Movable( false ).Dock().Fixed().BottomDockable( false ).TopDockable( false ).LeftDockable( false ).RightDockable( false ).Floatable( false ).Row( 2 ).Position( 200 ) );


	m_mgr.Update();
	this->Centre( wxBOTH );

	// Connect Events
	m_cancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cNewScriptFileDialog::Close ), NULL, this );
	m_create->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cNewScriptFileDialog::createSQF ), NULL, this );
}

cNewScriptFileDialog::~cNewScriptFileDialog()
{
	// Disconnect Events
	m_cancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cNewScriptFileDialog::Close ), NULL, this );
	m_create->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cNewScriptFileDialog::createSQF ), NULL, this );

	m_mgr.UnInit();

}

cNewCategoryDialog::cNewCategoryDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	m_mgr.SetManagedWindow(this);
	m_mgr.SetFlags(wxAUI_MGR_DEFAULT);

	m_NameTxt = new wxStaticText( this, wxID_ANY, wxT("Name"), wxPoint( 10,25 ), wxSize( 75,27 ), wxALIGN_CENTER_HORIZONTAL|wxST_NO_AUTORESIZE );
	m_NameTxt->Wrap( -1 );
	m_NameTxt->SetFont( wxFont( 18, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Arial") ) );

	m_mgr.AddPane( m_NameTxt, wxAuiPaneInfo() .Left() .CaptionVisible( false ).CloseButton( false ).PaneBorder( false ).Movable( false ).Dock().Fixed().BottomDockable( false ).TopDockable( false ).LeftDockable( false ).RightDockable( false ).Floatable( false ).Position( 25 ) );

	m_nameTxtCtrl = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxPoint( 10,25 ), wxSize( 300,30 ), 0 );
	m_mgr.AddPane( m_nameTxtCtrl, wxAuiPaneInfo() .Left() .CaptionVisible( false ).CloseButton( false ).PaneBorder( false ).Movable( false ).Dock().Fixed().BottomDockable( false ).TopDockable( false ).LeftDockable( false ).RightDockable( false ).Floatable( false ).Row( 1 ).Position( 25 ) );

	m_cancel = new wxButton( this, wxID_ANY, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_mgr.AddPane( m_cancel, wxAuiPaneInfo() .Bottom() .CaptionVisible( false ).CloseButton( false ).PaneBorder( false ).Movable( false ).Dock().Fixed().BottomDockable( false ).TopDockable( false ).LeftDockable( false ).RightDockable( false ).Floatable( false ) );

	m_create = new wxButton( this, wxID_ANY, wxT("Create"), wxPoint( -1,-1 ), wxSize( 150,75 ), 0 );
	m_create->SetMinSize( wxSize( -1,50 ) );
	m_create->SetMaxSize( wxSize( -1,50 ) );

	m_mgr.AddPane( m_create, wxAuiPaneInfo() .Left() .CaptionVisible( false ).CloseButton( false ).PaneBorder( false ).Movable( false ).Dock().Fixed().DockFixed( true ).BottomDockable( false ).TopDockable( false ).LeftDockable( false ).RightDockable( false ).Floatable( false ).Row( 1 ).Position( 50 ).BestSize( wxSize( -1,50 ) ).MinSize( wxSize( -1,50 ) ).MaxSize( wxSize( -1,50 ) ).Layer( 0 ) );


	m_mgr.Update();
	this->Centre( wxBOTH );

	// Connect Events
	m_cancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cNewCategoryDialog::Close ), NULL, this );
	m_create->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cNewCategoryDialog::createCategory ), NULL, this );
}

cNewCategoryDialog::~cNewCategoryDialog()
{
	// Disconnect Events
	m_cancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cNewCategoryDialog::Close ), NULL, this );
	m_create->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cNewCategoryDialog::createCategory ), NULL, this );

	m_mgr.UnInit();

}

cNewHeaderDialog::cNewHeaderDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	m_mgr.SetManagedWindow(this);
	m_mgr.SetFlags(wxAUI_MGR_DEFAULT);

	m_NameTxt = new wxStaticText( this, wxID_ANY, wxT("Name"), wxPoint( 10,25 ), wxSize( 75,27 ), wxALIGN_CENTER_HORIZONTAL|wxST_NO_AUTORESIZE );
	m_NameTxt->Wrap( -1 );
	m_NameTxt->SetFont( wxFont( 18, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Arial") ) );

	m_mgr.AddPane( m_NameTxt, wxAuiPaneInfo() .Left() .CaptionVisible( false ).CloseButton( false ).PaneBorder( false ).Movable( false ).Dock().Fixed().BottomDockable( false ).TopDockable( false ).LeftDockable( false ).RightDockable( false ).Floatable( false ).Position( 25 ) );

	m_nameTxtCtrl = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxPoint( 10,25 ), wxSize( 300,30 ), 0 );
	m_mgr.AddPane( m_nameTxtCtrl, wxAuiPaneInfo() .Left() .CaptionVisible( false ).CloseButton( false ).PaneBorder( false ).Movable( false ).Dock().Fixed().BottomDockable( false ).TopDockable( false ).LeftDockable( false ).RightDockable( false ).Floatable( false ).Row( 1 ).Position( 25 ) );

	m_cancel = new wxButton( this, wxID_ANY, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_mgr.AddPane( m_cancel, wxAuiPaneInfo() .Bottom() .CaptionVisible( false ).CloseButton( false ).PaneBorder( false ).Movable( false ).Dock().Fixed().BottomDockable( false ).TopDockable( false ).LeftDockable( false ).RightDockable( false ).Floatable( false ) );

	m_create = new wxButton( this, wxID_ANY, wxT("Create"), wxPoint( -1,-1 ), wxSize( 150,75 ), 0 );
	m_create->SetMinSize( wxSize( -1,50 ) );
	m_create->SetMaxSize( wxSize( -1,50 ) );

	m_mgr.AddPane( m_create, wxAuiPaneInfo() .Left() .CaptionVisible( false ).CloseButton( false ).PaneBorder( false ).Movable( false ).Dock().Fixed().DockFixed( true ).BottomDockable( false ).TopDockable( false ).LeftDockable( false ).RightDockable( false ).Floatable( false ).Row( 1 ).Position( 50 ).BestSize( wxSize( -1,50 ) ).MinSize( wxSize( -1,50 ) ).MaxSize( wxSize( -1,50 ) ).Layer( 0 ) );


	m_mgr.Update();
	this->Centre( wxBOTH );

	// Connect Events
	m_cancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cNewHeaderDialog::Close ), NULL, this );
	m_create->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cNewHeaderDialog::createHeader ), NULL, this );
}

cNewHeaderDialog::~cNewHeaderDialog()
{
	// Disconnect Events
	m_cancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cNewHeaderDialog::Close ), NULL, this );
	m_create->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cNewHeaderDialog::createHeader ), NULL, this );

	m_mgr.UnInit();

}

cNewModDialog::cNewModDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	m_mgr.SetManagedWindow(this);
	m_mgr.SetFlags(wxAUI_MGR_DEFAULT);

	m_prefixTxt = new wxStaticText( this, wxID_ANY, wxT("Prefix"), wxPoint( 10,25 ), wxSize( 75,27 ), wxALIGN_CENTER_HORIZONTAL|wxST_NO_AUTORESIZE );
	m_prefixTxt->Wrap( -1 );
	m_prefixTxt->SetFont( wxFont( 18, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Arial") ) );

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

	m_cancel = new wxButton( this, wxID_ANY, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_mgr.AddPane( m_cancel, wxAuiPaneInfo() .Bottom() .CaptionVisible( false ).CloseButton( false ).PaneBorder( false ).Movable( false ).Dock().Fixed().BottomDockable( false ).TopDockable( false ).LeftDockable( false ).RightDockable( false ).Floatable( false ) );

	m_create = new wxButton( this, wxID_ANY, wxT("Create"), wxPoint( -1,-1 ), wxSize( 150,50 ), 0 );
	m_mgr.AddPane( m_create, wxAuiPaneInfo() .Left() .CaptionVisible( false ).CloseButton( false ).PaneBorder( false ).Movable( false ).Dock().Fixed().DockFixed( true ).BottomDockable( false ).TopDockable( false ).LeftDockable( false ).RightDockable( false ).Floatable( false ).Row( 1 ).Position( 375 ).Layer( 0 ) );

	m_pathPicker = new wxDirPickerCtrl( this, wxID_ANY, wxEmptyString, wxT("Select a folder"), wxDefaultPosition, wxDefaultSize, wxDIRP_DEFAULT_STYLE );
	m_mgr.AddPane( m_pathPicker, wxAuiPaneInfo() .Left() .CaptionVisible( false ).Movable( false ).Dock().Fixed().BottomDockable( false ).TopDockable( false ).LeftDockable( false ).RightDockable( false ).Floatable( false ).Row( 1 ).Position( 325 ) );


	m_mgr.Update();
	this->Centre( wxBOTH );

	// Connect Events
	m_cancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cNewModDialog::Close ), NULL, this );
	m_create->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cNewModDialog::createMod ), NULL, this );
}

cNewModDialog::~cNewModDialog()
{
	// Disconnect Events
	m_cancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cNewModDialog::Close ), NULL, this );
	m_create->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cNewModDialog::createMod ), NULL, this );

	m_mgr.UnInit();

}
