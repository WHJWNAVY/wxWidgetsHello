///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "wxFormBuilderHelloMain.h"

#include <wx/msgdlg.h>

 //(*InternalHeaders(wxLayoutFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f
};

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f)
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

///////////////////////////////////////////////////////////////////////////

MyFrameHello::MyFrameHello(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style) : wxFrame(parent, id, title, pos, size, style)
{
    this->SetSizeHints(wxDefaultSize, wxDefaultSize);

    wxGridSizer* gSizerHello;
    gSizerHello = new wxGridSizer(0, 2, 0, 0);

    m_button_hello = new wxButton(this, wxID_ANY, wxT("Hello"), wxDefaultPosition, wxDefaultSize, 0);
    gSizerHello->Add(m_button_hello, 0, wxALL, 5);

    m_textCtrlHello = new wxTextCtrl(this, wxID_ANY, wxT("Hello"), wxDefaultPosition, wxDefaultSize, 0);
    gSizerHello->Add(m_textCtrlHello, 0, wxALL, 5);

    m_staticTextHello = new wxStaticText(this, wxID_ANY, wxT("Hello"), wxDefaultPosition, wxDefaultSize, 0);
    m_staticTextHello->Wrap(-1);
    gSizerHello->Add(m_staticTextHello, 0, wxALL, 5);

    m_comboBoxHello = new wxComboBox(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0);
    m_comboBoxHello->Append(wxT("ComboHello0"));
    m_comboBoxHello->Append(wxT("ComboHello1"));
    m_comboBoxHello->Append(wxT("ComboHello2"));
    m_comboBoxHello->Append(wxT("ComboHello3"));
    gSizerHello->Add(m_comboBoxHello, 0, wxALL, 5);

    m_checkBoxHello = new wxCheckBox(this, wxID_ANY, wxT("Check Me!"), wxDefaultPosition, wxDefaultSize, 0);
    gSizerHello->Add(m_checkBoxHello, 0, wxALL, 5);

    wxString m_radioBoxHelloChoices[] = { wxT("Radio Button 0"), wxT("Radio Button 1"), wxT("Radio Button 2") };
    int m_radioBoxHelloNChoices = sizeof(m_radioBoxHelloChoices) / sizeof(wxString);
    m_radioBoxHello = new wxRadioBox(this, wxID_ANY, wxT("wxRadioBox"), wxDefaultPosition, wxDefaultSize, m_radioBoxHelloNChoices, m_radioBoxHelloChoices, 1, wxRA_SPECIFY_COLS);
    m_radioBoxHello->SetSelection(0);
    gSizerHello->Add(m_radioBoxHello, 0, wxALL, 5);


    this->SetSizer(gSizerHello);
    this->Layout();

    this->Centre(wxBOTH);

    // Connect Events
    m_button_hello->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrameHello::m_button_helloOnButtonClick), NULL, this);
    m_comboBoxHello->Connect(wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler(MyFrameHello::m_comboBoxHelloOnCombobox), NULL, this);
    m_checkBoxHello->Connect(wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler(MyFrameHello::m_checkBoxHelloOnCheckBox), NULL, this);
    m_radioBoxHello->Connect(wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler(MyFrameHello::m_radioBoxHelloOnRadioBox), NULL, this);
}

MyFrameHello::~MyFrameHello()
{
    // Disconnect Events
    m_button_hello->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrameHello::m_button_helloOnButtonClick), NULL, this);
    m_comboBoxHello->Disconnect(wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler(MyFrameHello::m_comboBoxHelloOnCombobox), NULL, this);
    m_checkBoxHello->Disconnect(wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler(MyFrameHello::m_checkBoxHelloOnCheckBox), NULL, this);
    m_radioBoxHello->Disconnect(wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler(MyFrameHello::m_radioBoxHelloOnRadioBox), NULL, this);

}

// Virtual event handlers, overide them in your derived class
void MyFrameHello::m_button_helloOnButtonClick(wxCommandEvent& event)
{

    wxString msg = wxbuildinfo(long_f);
    msg << std::to_string(event.GetId());
    wxMessageBox(msg, _("Welcome to..."));
}

void MyFrameHello::m_comboBoxHelloOnCombobox(wxCommandEvent& event)
{
    wxString msg("OnCombobox-String:");
    msg << event.GetString();
    wxMessageBox(msg, _("Combobox..."));
}

void MyFrameHello::m_checkBoxHelloOnCheckBox(wxCommandEvent& event)
{
    wxString msg("OnCheckBox-IsChecked:");
    if (event.IsChecked()) {
        msg << "True";
    }
    else
    {
        msg << "False";
    }
    wxMessageBox(msg, _("CheckBox..."));
}

void MyFrameHello::m_radioBoxHelloOnRadioBox(wxCommandEvent& event)
{
    wxString msg("OnRadioBox-Selection:");
    msg << std::to_string(event.GetSelection());
    msg << "-";
    msg << std::to_string(event.GetInt());
    wxMessageBox(msg, _("RadioBox..."));
}