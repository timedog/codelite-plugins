///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __FILE2ARRAY_BASE_DLG_H__
#define __FILE2ARRAY_BASE_DLG_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/filepicker.h>
#include <wx/textctrl.h>
#include <wx/sizer.h>
#include <wx/gauge.h>
#include <wx/statline.h>
#include <wx/button.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class File2ArrayBaseDlg
///////////////////////////////////////////////////////////////////////////////
class File2ArrayBaseDlg : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText1;
		wxFilePickerCtrl* m_filePicker2;
		wxStaticText* m_staticText_Offset;
		wxTextCtrl* m_textCtrl_Offset;
		wxStaticText* m_staticText11;
		wxStaticText* m_staticText_Size;
		wxTextCtrl* m_textCtrl_Size;
		wxStaticText* m_staticText13;
		wxGauge* m_gauge1;
		wxStaticLine* m_staticline2;
		wxButton* m_buttonOK;
		wxButton* m_buttonCancel;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnButtonOK( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		File2ArrayBaseDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("File Convert to Array"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 360,245 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~File2ArrayBaseDlg();
	
};

#endif //__FILE2ARRAY_BASE_DLG_H__
