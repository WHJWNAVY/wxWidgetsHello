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
 
// $Id: NibblesFrame.cc,v 1.8 2005/08/27 14:41:32 technoplaza Exp $

#ifdef HAVE_CONFIG_H
    #include <config.h>
#endif

#include <wx/wxprec.h>

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include "AppConstants.h"
#include "Game.h"
#include "UIConstants.h"
#include "NibblesFrame.h"
#include "NibblesPanel.h"

using namespace nibbles;

BEGIN_EVENT_TABLE(NibblesFrame, wxFrame)
    EVT_CLOSE(NibblesFrame::onWindowClose)

    EVT_MENU(IDM_FILE_NEWGAME, NibblesFrame::onFileNewGame)
    EVT_MENU(wxID_EXIT, NibblesFrame::onFileExit)
    EVT_MENU(wxID_ABOUT, NibblesFrame::onHelpAbout)
END_EVENT_TABLE()

NibblesFrame::NibblesFrame() {
    wxString title = *APP_NAME + wxT(' ') + *APP_VERSION;
    
    // create the frame
    Create(NULL, ID_FRAME, title, wxDefaultPosition,
           wxDefaultSize, wxCAPTION | wxSYSTEM_MENU | 
           wxMINIMIZE_BOX | wxCLOSE_BOX);
           
    // create the menu bar
    createMenuBar();
    
    // create the NibblesPanel
    panel = new NibblesPanel(this);
}

void NibblesFrame::createMenuBar() {
    // create the menu bar
    wxMenuBar *mb = new wxMenuBar;
    
    // create the file menu
    wxMenu *fileMenu = new wxMenu;
    fileMenu->Append(IDM_FILE_NEWGAME, wxT("&New Game\tCtrl-N"));
    
    #ifndef __WXOSX__
        fileMenu->AppendSeparator();
    #endif
    
    fileMenu->Append(wxID_EXIT, wxT("E&xit"));
    
    // append the file menu to the menu bar
    mb->Append(fileMenu, wxT("&File"));
    
    // create the help menu
    wxMenu *helpMenu = new wxMenu;
    helpMenu->Append(wxID_ABOUT, wxT("About"));
    
    // append the help menu to the menu bar
    mb->Append(helpMenu, wxT("&Help"));
    
    // set the frame's menu bar
    SetMenuBar(mb);
}

void NibblesFrame::onWindowClose(wxCloseEvent &event) {
    // can we ignore this Close event?
    if (event.CanVeto()) {
        // if so, ask the user if he really wants to quit
        if (panel->getGame().isPlaying()) {
            int result = wxMessageBox(wxT("Really Exit wxNibbles?"),
                                      wxT("Warning: Game in Progess"),
                                      wxYES_NO | wxICON_QUESTION);
            
            // if not, don't close
            if (result == wxNO) {
                return;
            }
        }
    }
    
    // Destroy this window
    Destroy();
}

void NibblesFrame::onFileNewGame(wxCommandEvent &) {\
    // confirm ending the current game before starting a new one
    if (panel->getGame().isPlaying()) {
        int result = wxMessageBox(wxT("Quit current game?"), 
                                  wxT("Warning: Game in Progress"), 
                                  wxYES_NO | wxICON_QUESTION);
        
        if (result == wxNO) {
            return;
        }
    }
    
    panel->newGame();
}

void NibblesFrame::onHelpAbout(wxCommandEvent &) {
    // display standard 'about' box
    wxString message = GetTitle() + wxT('\n') + *APP_COPYRIGHT;
    wxString title = wxT("About ") + GetTitle();
    
    wxMessageBox(message, title, wxOK | wxICON_INFORMATION);
}

IMPLEMENT_CLASS(NibblesFrame, wxFrame)

