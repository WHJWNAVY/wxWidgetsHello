///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __WXFORMBUILDER_HELLO_MAIN_H__
#define __WXFORMBUILDER_HELLO_MAIN_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/button.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/textctrl.h>
#include <wx/stattext.h>
#include <wx/combobox.h>
#include <wx/checkbox.h>
#include <wx/radiobox.h>
#include <wx/sizer.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class MyFrameHello
///////////////////////////////////////////////////////////////////////////////
class MyFrameHello : public wxFrame
{
private:

protected:
    wxButton* m_button_hello;
    wxTextCtrl* m_textCtrlHello;
    wxStaticText* m_staticTextHello;
    wxComboBox* m_comboBoxHello;
    wxCheckBox* m_checkBoxHello;
    wxRadioBox* m_radioBoxHello;

    // Virtual event handlers, overide them in your derived class
    void m_button_helloOnButtonClick(wxCommandEvent& event);
    void m_comboBoxHelloOnCombobox(wxCommandEvent& event);
    void m_checkBoxHelloOnCheckBox(wxCommandEvent& event);
    void m_radioBoxHelloOnRadioBox(wxCommandEvent& event);

public:

    MyFrameHello(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(500, 400), long style = wxDEFAULT_FRAME_STYLE | wxTAB_TRAVERSAL);

    ~MyFrameHello();

};

#endif //__NONAME_H__
