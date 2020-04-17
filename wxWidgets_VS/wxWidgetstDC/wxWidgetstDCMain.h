///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __WX_WIDGETST_DC_MAIN_H__
#define __WX_WIDGETST_DC_MAIN_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/statbmp.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/sizer.h>
#include <wx/radiobox.h>
#include <wx/button.h>
#include <wx/statbox.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class MyFrameHello
///////////////////////////////////////////////////////////////////////////////
class MyFrameHello : public wxFrame
{
private:

protected:
    wxStaticBitmap* mBitmapMain;
    wxStaticText* mStaticTextInfo;
    wxStaticText* mStaticTextScore;
    wxRadioBox* mRadioBoxBoundary;
    wxRadioBox* mRadioBoxInvincibleMode;
    wxButton* mButtonRenew;
    wxButton* mButtonStop;
    wxButton* mButtonExit;
    wxButton* mButtonAbout;

    // Virtual event handlers, overide them in your derived class
    virtual void MyFrameHelloOnSize(wxSizeEvent& event) { event.Skip(); }


public:

    MyFrameHello(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(600, 500), long style = wxDEFAULT_FRAME_STYLE | wxTAB_TRAVERSAL);

    ~MyFrameHello();

};

#endif //__NONAME_H__
