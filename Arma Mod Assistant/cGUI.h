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
#include <wx/notebook.h>
#include <wx/frame.h>
#include <wx/aui/aui.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/listbox.h>
#include <wx/button.h>
#include <wx/radiobox.h>
#include <wx/dialog.h>
#include <wx/filepicker.h>

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Class cMainFrame
///////////////////////////////////////////////////////////////////////////////
class cMainFrame : public wxFrame
{
	private:

	protected:
		enum
		{
			id_mainFrame = 1000,
			id_newModMenu,
			sqfMenuItem,
			hppMenuItem,
			cfgMenuItem
		};

		wxMenuBar* m_menuBar;
		wxMenu* m_file;
		wxMenu* m_New;
		wxMenu* m_newFile;

		// Virtual event handlers, override them in your derived class
		virtual void newMod( wxCommandEvent& event ) { event.Skip(); }
		virtual void newSubmod( wxCommandEvent& event ) { event.Skip(); }
		virtual void newCategory( wxCommandEvent& event ) { event.Skip(); }
		virtual void newFile( wxCommandEvent& event ) { event.Skip(); }
		virtual void openProject( wxCommandEvent& event ) { event.Skip(); }
		virtual void openOptions( wxCommandEvent& event ) { event.Skip(); }
		virtual void Close( wxCommandEvent& event ) { event.Skip(); }


	public:
		wxTreeCtrl* m_folderView;
		wxNotebook* m_editBook;

		cMainFrame( wxWindow* parent, wxWindowID id = id_mainFrame, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 1920,1080 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		wxAuiManager m_mgr;

		~cMainFrame();

};

///////////////////////////////////////////////////////////////////////////////
/// Class cNewScriptFileDialog
///////////////////////////////////////////////////////////////////////////////
class cNewScriptFileDialog : public wxDialog
{
	private:

	protected:
		wxStaticText* m_NameTxt;
		wxStaticText* m_NameInfo;
		wxStaticText* m_CategoryTxt;
		wxTextCtrl* m_nameTxtCtrl;
		wxListBox* m_categoryLB;
		wxButton* m_cancel;
		wxButton* m_create;
		wxRadioBox* m_initType;

		// Virtual event handlers, override them in your derived class
		virtual void Close( wxCommandEvent& event ) { event.Skip(); }
		virtual void createSQF( wxCommandEvent& event ) { event.Skip(); }


	public:

		cNewScriptFileDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("New SQF File"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 637,499 ), long style = wxDEFAULT_DIALOG_STYLE );
		wxAuiManager m_mgr;

		~cNewScriptFileDialog();

};

///////////////////////////////////////////////////////////////////////////////
/// Class cNewCategoryDialog
///////////////////////////////////////////////////////////////////////////////
class cNewCategoryDialog : public wxDialog
{
	private:

	protected:
		wxStaticText* m_NameTxt;
		wxTextCtrl* m_nameTxtCtrl;
		wxButton* m_cancel;
		wxButton* m_create;

		// Virtual event handlers, override them in your derived class
		virtual void Close( wxCommandEvent& event ) { event.Skip(); }
		virtual void createCategory( wxCommandEvent& event ) { event.Skip(); }


	public:

		cNewCategoryDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("New Category"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 400,125 ), long style = wxDEFAULT_DIALOG_STYLE );
		wxAuiManager m_mgr;

		~cNewCategoryDialog();

};

///////////////////////////////////////////////////////////////////////////////
/// Class cNewHeaderDialog
///////////////////////////////////////////////////////////////////////////////
class cNewHeaderDialog : public wxDialog
{
	private:

	protected:
		wxStaticText* m_NameTxt;
		wxTextCtrl* m_nameTxtCtrl;
		wxButton* m_cancel;
		wxButton* m_create;

		// Virtual event handlers, override them in your derived class
		virtual void Close( wxCommandEvent& event ) { event.Skip(); }
		virtual void createHeader( wxCommandEvent& event ) { event.Skip(); }


	public:

		cNewHeaderDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("New Header"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 400,125 ), long style = wxDEFAULT_DIALOG_STYLE );
		wxAuiManager m_mgr;

		~cNewHeaderDialog();

};

///////////////////////////////////////////////////////////////////////////////
/// Class cNewModDialog
///////////////////////////////////////////////////////////////////////////////
class cNewModDialog : public wxDialog
{
	private:

	protected:
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

		// Virtual event handlers, override them in your derived class
		virtual void Close( wxCommandEvent& event ) { event.Skip(); }
		virtual void createMod( wxCommandEvent& event ) { event.Skip(); }


	public:

		cNewModDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("New Mod"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 637,499 ), long style = wxDEFAULT_DIALOG_STYLE );
		wxAuiManager m_mgr;

		~cNewModDialog();

};

