///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "file2array_base_dlg.h"

///////////////////////////////////////////////////////////////////////////

File2ArrayBaseDlg::File2ArrayBaseDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( -1,-1 ), wxDefaultSize );
	
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText1 = new wxStaticText( this, wxID_ANY, wxT("Input File :"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1->Wrap( -1 );
	bSizer1->Add( m_staticText1, 0, wxALL, 5 );
	
	m_filePicker2 = new wxFilePickerCtrl( this, wxID_ANY, wxEmptyString, wxT("Select a file"), wxT("*.*"), wxDefaultPosition, wxDefaultSize, wxFLP_DEFAULT_STYLE );
	m_filePicker2->SetMinSize( wxSize( 300,-1 ) );
	
	bSizer1->Add( m_filePicker2, 0, wxALL|wxEXPAND, 5 );
	
	wxFlexGridSizer* fgSizer1;
	fgSizer1 = new wxFlexGridSizer( 2, 3, 0, 0 );
	fgSizer1->SetFlexibleDirection( wxBOTH );
	fgSizer1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText_Offset = new wxStaticText( this, wxID_ANY, wxT("Offset :"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText_Offset->Wrap( -1 );
	fgSizer1->Add( m_staticText_Offset, 0, wxALL, 5 );
	
	m_textCtrl_Offset = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 190,-1 ), 0 );
	m_textCtrl_Offset->SetToolTip( wxT("The default value is 0. If the value exceeds the file size, a warning will pop up.Example 0x200.") );
	
	fgSizer1->Add( m_textCtrl_Offset, 0, wxALL, 5 );
	
	m_staticText11 = new wxStaticText( this, wxID_ANY, wxT("(bytes,hexadec.)"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText11->Wrap( -1 );
	fgSizer1->Add( m_staticText11, 0, wxALL, 5 );
	
	m_staticText_Size = new wxStaticText( this, wxID_ANY, wxT("Size :"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText_Size->Wrap( -1 );
	fgSizer1->Add( m_staticText_Size, 0, wxALL, 5 );
	
	m_textCtrl_Size = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 190,-1 ), 0 );
	m_textCtrl_Size->SetToolTip( wxT("The default value and 0 are the file size.") );
	
	fgSizer1->Add( m_textCtrl_Size, 0, wxALL, 5 );
	
	m_staticText13 = new wxStaticText( this, wxID_ANY, wxT("(bytes,decimal)"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText13->Wrap( -1 );
	fgSizer1->Add( m_staticText13, 0, wxALL, 5 );
	
	
	bSizer1->Add( fgSizer1, 0, wxEXPAND, 5 );
	
	m_gauge1 = new wxGauge( this, wxID_ANY, 100, wxDefaultPosition, wxDefaultSize, wxGA_HORIZONTAL );
	m_gauge1->SetValue( 0 ); 
	bSizer1->Add( m_gauge1, 0, wxALL|wxEXPAND, 5 );
	
	m_staticline2 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer1->Add( m_staticline2, 0, wxEXPAND | wxALL, 5 );
	
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxHORIZONTAL );
	
	m_buttonOK = new wxButton( this, wxID_OK, wxT("&OK"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( m_buttonOK, 0, wxALIGN_BOTTOM|wxALL, 5 );
	
	m_buttonCancel = new wxButton( this, wxID_CANCEL, wxT("&Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( m_buttonCancel, 0, wxALIGN_BOTTOM|wxALL, 5 );
	
	
	bSizer1->Add( bSizer2, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
	this->SetSizer( bSizer1 );
	this->Layout();
	bSizer1->Fit( this );
    
	this->Centre( wxBOTH );
	
	// Connect Events
	m_buttonOK->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( File2ArrayBaseDlg::OnButtonOK ), NULL, this );
}

File2ArrayBaseDlg::~File2ArrayBaseDlg()
{
	// Disconnect Events
	m_buttonOK->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( File2ArrayBaseDlg::OnButtonOK ), NULL, this );
	
}
