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
 
// $Id: NibblesFrame.h,v 1.5 2005/08/27 14:41:32 technoplaza Exp $

#ifndef _NIBBLESFRAME_HH_
#define _NIBBLESFRAME_HH_

namespace nibbles {
    class NibblesPanel;
    
    class NibblesFrame : public wxFrame {
        DECLARE_CLASS(NibblesFrame)
        DECLARE_EVENT_TABLE()
        
    private:
        NibblesPanel *panel;
    
        /**
         * Creates the menu bar for this NibblesFrame.
         */
        void createMenuBar();
        
        /**
         * Called when the window is being closed.
         *
         * @param event The triggering wxCloseEvent.
         */
        void onWindowClose(wxCloseEvent &event);
        
        /**
         * Called when new game from the file menu is selected.
         *
         * @param event The triggering wxCommandEvent (unused).
         */
        void onFileNewGame(wxCommandEvent &event);
    
        /**
         * Called when exit from the file menu is selected.
         *
         * @param event The triggering wxCommandEvent (unused).
         */
        void onFileExit(wxCommandEvent &event);
        
        /**
         * Called when about from the help menu is selected.
         *
         * @param event The triggering wxCommandEvent (unused).
         */
        void onHelpAbout(wxCommandEvent &event);
        
    public:
        /**
         * Creates a new NibblesFrame.
         */
        NibblesFrame();
    };
    
    inline void NibblesFrame::onFileExit(wxCommandEvent &) { Close(); }
}

#endif

