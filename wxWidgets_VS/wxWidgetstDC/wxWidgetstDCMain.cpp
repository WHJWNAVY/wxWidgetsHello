///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "wxWidgetstDCMain.h"

#include <wx/msgdlg.h>
#include <wx/intl.h>
#include <wx/string.h>


///////////////////////////////////////////////////////////////////////////

MyFrameHello::MyFrameHello(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style) : wxFrame(parent, id, title, pos, size, style)
{
    this->SetSizeHints(wxSize(600, 500), wxSize(600, 500));

    wxBoxSizer* bSizerMain;
    bSizerMain = new wxBoxSizer(wxHORIZONTAL);

    mBitmapMain = new wxStaticBitmap(this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, 0);
    bSizerMain->Add(mBitmapMain, 6, wxALL | wxEXPAND, 5);

    wxStaticBoxSizer* sbSizerCtrlInfo;
    sbSizerCtrlInfo = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, wxT("Info")), wxVERTICAL);

    wxBoxSizer* bSizerScore;
    bSizerScore = new wxBoxSizer(wxHORIZONTAL);

    mStaticTextInfo = new wxStaticText(sbSizerCtrlInfo->GetStaticBox(), wxID_ANY, wxT("Score:"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE);
    mStaticTextInfo->Wrap(-1);
    bSizerScore->Add(mStaticTextInfo, 1, wxALIGN_CENTER | wxALL | wxEXPAND, 5);

    mStaticTextScore = new wxStaticText(sbSizerCtrlInfo->GetStaticBox(), wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE);
    mStaticTextScore->Wrap(-1);
    bSizerScore->Add(mStaticTextScore, 2, wxALIGN_CENTER | wxALL | wxEXPAND, 5);


    sbSizerCtrlInfo->Add(bSizerScore, 1, wxALIGN_CENTER | wxEXPAND, 5);

    wxString mRadioBoxBoundaryChoices[] = { wxT("Borderless"), wxT("Bounded") };
    int mRadioBoxBoundaryNChoices = sizeof(mRadioBoxBoundaryChoices) / sizeof(wxString);
    mRadioBoxBoundary = new wxRadioBox(sbSizerCtrlInfo->GetStaticBox(), wxID_ANY, wxT("Boundary"), wxDefaultPosition, wxDefaultSize, mRadioBoxBoundaryNChoices, mRadioBoxBoundaryChoices, 1, wxRA_SPECIFY_COLS);
    mRadioBoxBoundary->SetSelection(0);
    sbSizerCtrlInfo->Add(mRadioBoxBoundary, 3, wxALIGN_CENTER | wxALL | wxEXPAND, 5);

    wxString mRadioBoxInvincibleModeChoices[] = { wxT("Invincible Mode"), wxT("Normal Mode") };
    int mRadioBoxInvincibleModeNChoices = sizeof(mRadioBoxInvincibleModeChoices) / sizeof(wxString);
    mRadioBoxInvincibleMode = new wxRadioBox(sbSizerCtrlInfo->GetStaticBox(), wxID_ANY, wxT("Invincible Mode"), wxDefaultPosition, wxDefaultSize, mRadioBoxInvincibleModeNChoices, mRadioBoxInvincibleModeChoices, 1, wxRA_SPECIFY_COLS);
    mRadioBoxInvincibleMode->SetSelection(0);
    sbSizerCtrlInfo->Add(mRadioBoxInvincibleMode, 3, wxALIGN_CENTER | wxALL | wxEXPAND, 5);

    mButtonRenew = new wxButton(sbSizerCtrlInfo->GetStaticBox(), wxID_ANY, wxT("ReNew"), wxDefaultPosition, wxDefaultSize, 0);
    sbSizerCtrlInfo->Add(mButtonRenew, 1, wxALIGN_CENTER | wxALL | wxEXPAND, 5);

    mButtonStop = new wxButton(sbSizerCtrlInfo->GetStaticBox(), wxID_ANY, wxT("Stop"), wxDefaultPosition, wxDefaultSize, 0);
    sbSizerCtrlInfo->Add(mButtonStop, 1, wxALIGN_CENTER | wxALL | wxEXPAND, 5);

    mButtonExit = new wxButton(sbSizerCtrlInfo->GetStaticBox(), wxID_ANY, wxT("Exit"), wxDefaultPosition, wxDefaultSize, 0);
    sbSizerCtrlInfo->Add(mButtonExit, 1, wxALIGN_CENTER | wxALL | wxEXPAND, 5);

    mButtonAbout = new wxButton(sbSizerCtrlInfo->GetStaticBox(), wxID_ANY, wxT("About"), wxDefaultPosition, wxDefaultSize, 0);
    sbSizerCtrlInfo->Add(mButtonAbout, 1, wxALIGN_CENTER | wxALL | wxEXPAND, 5);


    bSizerMain->Add(sbSizerCtrlInfo, 1, wxEXPAND, 5);


    this->SetSizer(bSizerMain);
    this->Layout();

    this->Centre(wxBOTH);

    // Connect Events
    this->Connect(wxEVT_SIZE, wxSizeEventHandler(MyFrameHello::MyFrameHelloOnSize));
}

MyFrameHello::~MyFrameHello()
{
    // Disconnect Events
    this->Disconnect(wxEVT_SIZE, wxSizeEventHandler(MyFrameHello::MyFrameHelloOnSize));

}