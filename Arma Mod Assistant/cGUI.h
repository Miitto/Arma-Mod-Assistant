///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.1-0-g8feb16b3)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/menu.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/treectrl.h>
#include <wx/aui/auibook.h>
#include <wx/frame.h>
#include <wx/aui/aui.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/listbox.h>
#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/dialog.h>
#include <wx/radiobox.h>
#include <wx/filepicker.h>

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Class cMainFrame
///////////////////////////////////////////////////////////////////////////////
class cMainFrame : public wxFrame
{
	DECLARE_EVENT_TABLE()
	private:

		// Private event handlers
		void _wxFB_newMod( wxCommandEvent& event ){ newMod( event ); }
		void _wxFB_newSubmod( wxCommandEvent& event ){ newSubmod( event ); }
		void _wxFB_newCategory( wxCommandEvent& event ){ newCategory( event ); }
		void _wxFB_newSqfFile( wxCommandEvent& event ){ newSqfFile( event ); }
		void _wxFB_newHeaderFile( wxCommandEvent& event ){ newHeaderFile( event ); }
		void _wxFB_newCfgFile( wxCommandEvent& event ){ newCfgFile( event ); }
		void _wxFB_openProject( wxCommandEvent& event ){ openProject( event ); }
		void _wxFB_openFolder( wxCommandEvent& event ){ openFolder( event ); }
		void _wxFB_saveProject( wxCommandEvent& event ){ saveProject( event ); }
		void _wxFB_saveProjectAs( wxCommandEvent& event ){ saveProjectAs( event ); }
		void _wxFB_openOptions( wxCommandEvent& event ){ openOptions( event ); }
		void _wxFB_CloseWindow( wxCommandEvent& event ){ CloseWindow( event ); }
		void _wxFB_onFileOpened( wxTreeEvent& event ){ onFileOpened( event ); }
		void _wxFB_onFileClicked( wxTreeEvent& event ){ onFileClicked( event ); }
		void _wxFB_onPageClose( wxAuiNotebookEvent& event ){ onPageClose( event ); }


	protected:
		enum
		{
			id_mainFrame = 1000,
			m_newModId,
			m_newSubModId,
			m_newCategoryId,
			m_sqfId,
			m_headerId,
			m_cfgId,
			m_openId,
			m_openFolderId,
			m_saveId,
			m_saveAsId,
			m_optionsId,
			m_exitId,
			m_editBookId
		};

		wxMenu* m_file;
		wxMenu* m_newFile;

		// Virtual event handlers, override them in your derived class
		void newMod( wxCommandEvent& event );
		void newSubmod( wxCommandEvent& event );
		void newCategory( wxCommandEvent& event );
		void newSqfFile( wxCommandEvent& event );
		void newHeaderFile( wxCommandEvent& event );
		void newCfgFile( wxCommandEvent& event );
		void openProject( wxCommandEvent& event );
		void openFolder( wxCommandEvent& event );
		void saveProject( wxCommandEvent& event );
		void saveProjectAs( wxCommandEvent& event );
		void openOptions( wxCommandEvent& event );
		void CloseWindow( wxCommandEvent& event );
		void onFileOpened( wxTreeEvent& event );
		void onFileClicked( wxTreeEvent& event );
		void onPageClose( wxAuiNotebookEvent& event );


	public:
		wxMenuBar* m_menuBar;
		wxMenu* m_New;
		wxTreeCtrl* m_folderView;
		wxAuiNotebook* m_editBook;

		cMainFrame( wxWindow* parent, wxWindowID id = id_mainFrame, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 1920,1080 ), long style = wxDEFAULT_FRAME_STYLE );
		wxAuiManager m_mgr;

		~cMainFrame();

};

///////////////////////////////////////////////////////////////////////////////
/// Class cNewCategoryDialog
///////////////////////////////////////////////////////////////////////////////
class cNewCategoryDialog : public wxDialog
{
	DECLARE_EVENT_TABLE()
	private:

		// Private event handlers
		void _wxFB_initDialog( wxInitDialogEvent& event ){ initDialog( event ); }
		void _wxFB_onNameEnter( wxCommandEvent& event ){ onNameEnter( event ); }
		void _wxFB_createCategory( wxCommandEvent& event ){ createCategory( event ); }


	protected:
		enum
		{
			m_newSubmodId = 1000,
			m_createId
		};

		wxStaticText* m_nameTxt;
		wxTextCtrl* m_nameTxtCtrl;
		wxStaticText* m_submodTxt;
		wxListBox* m_submodLB;
		wxButton* m_newSubmod;
		wxButton* m_create;

		// Virtual event handlers, override them in your derived class
		void initDialog( wxInitDialogEvent& event );
		void onNameEnter( wxCommandEvent& event );
		void createCategory( wxCommandEvent& event );


	public:

		cNewCategoryDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("New Category"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 374,330 ), long style = wxDEFAULT_DIALOG_STYLE );

		~cNewCategoryDialog();

};

///////////////////////////////////////////////////////////////////////////////
/// Class cNewScriptFileDialog
///////////////////////////////////////////////////////////////////////////////
class cNewScriptFileDialog : public wxDialog
{
	DECLARE_EVENT_TABLE()
	private:

		// Private event handlers
		void _wxFB_initDialog( wxInitDialogEvent& event ){ initDialog( event ); }
		void _wxFB_submodSelected( wxCommandEvent& event ){ submodSelected( event ); }
		void _wxFB_newSubmod( wxCommandEvent& event ){ newSubmod( event ); }
		void _wxFB_createCategory( wxCommandEvent& event ){ createCategory( event ); }
		void _wxFB_createFile( wxCommandEvent& event ){ createFile( event ); }


	protected:
		enum
		{
			m_submodLBId = 1000,
			m_initTypeRadioId,
			m_newSubmodId,
			m_categoryLBId,
			m_createCategoryId,
			m_createFileId
		};

		wxStaticText* m_FileNameTxt;
		wxTextCtrl* m_fileNameEdit;
		wxStaticText* m_sqfNotice;
		wxStaticText* m_submodTxt;
		wxListBox* m_submodLB;
		wxRadioBox* m_initTypeRadio;
		wxButton* m_newSubmod;
		wxStaticText* m_catTxt;
		wxListBox* m_catLB;
		wxButton* m_newCategory;
		wxButton* m_createFile;

		// Virtual event handlers, override them in your derived class
		void initDialog( wxInitDialogEvent& event );
		void submodSelected( wxCommandEvent& event );
		void newSubmod( wxCommandEvent& event );
		void createCategory( wxCommandEvent& event );
		void createFile( wxCommandEvent& event );


	public:

		cNewScriptFileDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("New Script File"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 472,524 ), long style = wxDEFAULT_DIALOG_STYLE );

		~cNewScriptFileDialog();

};

///////////////////////////////////////////////////////////////////////////////
/// Class cNewHeaderDialog
///////////////////////////////////////////////////////////////////////////////
class cNewHeaderDialog : public wxDialog
{
	DECLARE_EVENT_TABLE()
	private:

		// Private event handlers
		void _wxFB_initDialog( wxInitDialogEvent& event ){ initDialog( event ); }
		void _wxFB_submodSelected( wxCommandEvent& event ){ submodSelected( event ); }
		void _wxFB_newSubmod( wxCommandEvent& event ){ newSubmod( event ); }
		void _wxFB_createCategory( wxCommandEvent& event ){ createCategory( event ); }
		void _wxFB_createFile( wxCommandEvent& event ){ createFile( event ); }


	protected:
		enum
		{
			m_submodLBId = 1000,
			m_newSubmodId,
			m_categoryLBId,
			m_createCategoryId,
			m_createFileId
		};

		wxStaticText* m_FileNameTxt;
		wxTextCtrl* m_fileNameEdit;
		wxStaticText* m_sqfNotice;
		wxStaticText* m_submodTxt;
		wxListBox* m_submodLB;
		wxButton* m_newSubmod;
		wxStaticText* m_catTxt;
		wxListBox* m_catLB;
		wxButton* m_newCategory;
		wxButton* m_createFile;

		// Virtual event handlers, override them in your derived class
		void initDialog( wxInitDialogEvent& event );
		void submodSelected( wxCommandEvent& event );
		void newSubmod( wxCommandEvent& event );
		void createCategory( wxCommandEvent& event );
		void createFile( wxCommandEvent& event );


	public:

		cNewHeaderDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("New Header File"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 385,513 ), long style = wxDEFAULT_DIALOG_STYLE );

		~cNewHeaderDialog();

};

///////////////////////////////////////////////////////////////////////////////
/// Class cNewModDialog
///////////////////////////////////////////////////////////////////////////////
class cNewModDialog : public wxDialog
{
	DECLARE_EVENT_TABLE()
	private:

		// Private event handlers
		void _wxFB_CloseDialog( wxCommandEvent& event ){ CloseDialog( event ); }
		void _wxFB_createMod( wxCommandEvent& event ){ createMod( event ); }


	protected:
		enum
		{
			m_cancelId = 1000,
			m_createModId,
			modTypeRadio
		};

		wxStaticText* m_prefixTxt;
		wxStaticText* m_NameTxt;
		wxStaticText* m_Author;
		wxStaticText* m_addonsTxt;
		wxStaticText* m_PathTxt;
		wxTextCtrl* m_prefixTxtCtrl;
		wxTextCtrl* m_nameTxtCtrl;
		wxTextCtrl* m_AuthorTxtCtrl;
		wxTextCtrl* m_addonsTxtCtrl;
		wxButton* m_cancel;
		wxButton* m_create;
		wxDirPickerCtrl* m_pathPicker;
		wxRadioBox* m_modTypeRadio;

		// Virtual event handlers, override them in your derived class
		void CloseDialog( wxCommandEvent& event );
		void createMod( wxCommandEvent& event );


	public:

		cNewModDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("New Mod"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 637,499 ), long style = wxDEFAULT_DIALOG_STYLE );
		wxAuiManager m_mgr;

		~cNewModDialog();

};

///////////////////////////////////////////////////////////////////////////////
/// Class cNewSubmodDialog
///////////////////////////////////////////////////////////////////////////////
class cNewSubmodDialog : public wxDialog
{
	DECLARE_EVENT_TABLE()
	private:

		// Private event handlers
		void _wxFB_CloseDialog( wxCommandEvent& event ){ CloseDialog( event ); }
		void _wxFB_createMod( wxCommandEvent& event ){ createMod( event ); }


	protected:
		wxStaticText* m_NameTxt;
		wxStaticText* m_addonsTxt;
		wxTextCtrl* m_nameTxtCtrl;
		wxTextCtrl* m_addonsTxtCtrl;
		wxButton* m_cancel;
		wxButton* m_create;

		// Virtual event handlers, override them in your derived class
		void CloseDialog( wxCommandEvent& event );
		void createMod( wxCommandEvent& event );


	public:

		cNewSubmodDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("New Submod"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 423,258 ), long style = wxDEFAULT_DIALOG_STYLE );
		wxAuiManager m_mgr;

		~cNewSubmodDialog();

};

