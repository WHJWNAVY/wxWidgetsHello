/*
 * wxNibbles
 * Copyright (C) 2005 CODEpendent
 * http://code.technoplaza.net/wxNibbles/
 *
 * This file is part of wxNibbles.
 *
 * wxNibbles is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * wxNibbles is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with wxNibbles; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */
 
// $Id: NibblesApp.cc,v 1.7 2005/08/27 15:29:10 technoplaza Exp $

#ifdef HAVE_CONFIG_H
    #include <config.h>
#endif

#include <cstdlib>
#include <ctime>

#include <wx/wxprec.h>

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include "AppConstants.hh"
#include "NibblesApp.hh"
#include "ui/UIConstants.hh"
#include "ui/NibblesFrame.hh"

using namespace nibbles;

wxString *nibbles::APP_NAME;
wxString *nibbles::APP_VERSION;
wxString *nibbles::APP_COPYRIGHT;
wxString *nibbles::APP_URL;

NibblesApp::NibblesApp() {
    // setup the application strings
    APP_NAME = new wxString(wxT("wxNibbles"));
    APP_VERSION = new wxString(wxT(PACKAGE_VERSION));
    APP_COPYRIGHT = new wxString(wxT("Copyright (C) 2005 CODEpendent"));
    APP_URL = new wxString(wxT("http://code.technoplaza.net/wxNibbles/"));
}

NibblesApp::~NibblesApp() {
    // delete the application strings
    delete APP_NAME;
    delete APP_VERSION;
    delete APP_COPYRIGHT;
    delete APP_URL;
}

bool NibblesApp::OnInit() {
    // seed the random number generator
    srand(time(NULL));
    
    // create the main application frame
    NibblesFrame *frame = new NibblesFrame;
    frame->SetClientSize(PANEL_WIDTH, PANEL_HEIGHT);
    frame->Centre();
    frame->Show();
    
    // make it our top window
    SetTopWindow(frame);
    
    return true;
}

IMPLEMENT_CLASS(NibblesApp, wxApp)
IMPLEMENT_APP(NibblesApp)

