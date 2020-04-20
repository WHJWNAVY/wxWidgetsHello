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
 
// $Id: NibblesPanel.hh,v 1.11 2005/08/27 15:29:10 technoplaza Exp $

#ifndef _NIBBLESPANEL_HH_
#define _NIBBLESPANEL_HH_

#include <wx/panel.h>

#include "engine/Game.hh"
#include "ui/UIConstants.hh"

namespace nibbles {
    class NibblesPanel : public wxPanel {
        DECLARE_CLASS(NibblesPanel)
        DECLARE_EVENT_TABLE()
        
    private:
        Game game;
        
        /**
         * Draws the level.
         *
         * @param dc The device context to draw with.
         */
        void drawLevel(wxDC &dc);
        
        /**
         * Draws the snake.
         *
         * @param dc The device context to draw with.
         */
        void drawSnake(wxDC &dc);
        
        /**
         * Draws the apple.
         *
         * @param dc The device context to draw with.
         */
        void drawApple(wxDC &dc);
    
        /**
         * Called to paint this NibblesPanel.
         *
         * @param event The triggering wxPaintEvent (unused).
         */
        void onPaint(wxPaintEvent &event);
        
        /**
         * Called to erase the background.
         *
         * @param event The triggering wxEraseEvent (unused).
         */
        void onEraseBackground(wxEraseEvent &event);
        
        /**
         * Called when a key is pressed.
         *
         * @param event The triggering wxKeyEvent.
         */
        void onKeyDown(wxKeyEvent &event);
        
    public:
        /**
         * Creates a new NibblesPanel.
         */
        NibblesPanel(wxWindow *parent);
        
        /**
         * Gets the Game used by this NibblesPanel.
         *
         * @return The Game.
         */
        const Game &getGame() const;
        
        /**
         * Called to start a new game.
         */
        void newGame();
    };
    
    inline void NibblesPanel::onEraseBackground(wxEraseEvent &) {}
    inline const Game &NibblesPanel::getGame() const { return game; }
}

#endif

