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
 
// $Id: NibblesPanel.cc,v 1.13 2005/08/27 15:29:10 technoplaza Exp $

#ifdef HAVE_CONFIG_H
    #include <config.h>
#endif

#include <wx/wxprec.h>

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include <wx/dcbuffer.h>

#include "engine/Level.hh"
#include "engine/Snake.hh"
#include "ui/NibblesPanel.hh"

using namespace nibbles;

BEGIN_EVENT_TABLE(NibblesPanel, wxPanel)
    EVT_PAINT(NibblesPanel::onPaint)
    EVT_ERASE_BACKGROUND(NibblesPanel::onEraseBackground)
    EVT_KEY_DOWN(NibblesPanel::onKeyDown)
END_EVENT_TABLE()

NibblesPanel::NibblesPanel(wxWindow *parent) : wxPanel(parent, ID_PANEL),
                                               game(Game(*this)) {
    // enforce size constraints
    wxSize size(PANEL_WIDTH, PANEL_HEIGHT);
    
    SetMinSize(size);
    SetMaxSize(size);
}

void NibblesPanel::drawLevel(wxDC &dc) {
    const Level &level = game.getLevel();
    
    // begin drawing
    dc.BeginDrawing();
    
    // draw the walls
    dc.SetPen(*wxBLACK_PEN);
    dc.SetBrush(*wxBLACK_BRUSH);
    
    for (int y = 0; y < PANEL_HEIGHT; y += BLOCK_SIZE) {
        for (int x = 0; x < PANEL_WIDTH; x += BLOCK_SIZE) {
            if (level.isWall(wxPoint(x, y))) {
                dc.DrawRectangle(x, y, BLOCK_SIZE, BLOCK_SIZE);
            }
        }
    }
    
    // end drawing
    dc.EndDrawing();
}

void NibblesPanel::drawSnake(wxDC &dc) {
    const std::vector<wxPoint> &segments = game.getSnake().getSegments();
    
    // begin drawing
    dc.BeginDrawing();
    
    // draw the head
    dc.SetPen(*wxGREEN_PEN);
    dc.SetBrush(*wxBLUE_BRUSH);
    
    dc.DrawRectangle(segments[0].x, segments[0].y, BLOCK_SIZE, BLOCK_SIZE);
    
    // draw the body
    dc.SetPen(*wxMEDIUM_GREY_PEN);
    dc.SetBrush(*wxGREEN_BRUSH);
    
    for (unsigned int i = 1; i < segments.size(); i++) {
        dc.DrawRectangle(segments[i].x, segments[i].y, BLOCK_SIZE, BLOCK_SIZE);
    }
    
    // end drawing
    dc.EndDrawing();
}

void NibblesPanel::drawApple(wxDC &dc) {
    // begin drawing
    dc.BeginDrawing();
    
    // draw the apple
    dc.SetPen(*wxRED_PEN);
    dc.SetBrush(*wxRED_BRUSH);
    
    int radius = BLOCK_SIZE / 2;
    
    wxPoint apple = game.getApple();
    apple.x += radius;
    apple.y += radius;
    
    dc.DrawCircle(apple, radius);
    
    // end drawing
    dc.EndDrawing();
}

void NibblesPanel::onPaint(wxPaintEvent &) {
    wxBufferedPaintDC dc(this);
    
    // clear the background
    dc.SetBackground(*wxMEDIUM_GREY_BRUSH);
    dc.Clear();
    
    if (game.isPlaying()) {
        // draw the level
        drawLevel(dc);
        
        // draw the snake
        drawSnake(dc);
        
        // draw the apple
        drawApple(dc);
        
        if (!game.getSnake().isAlive() && !game.isPaused()) {
            // pause the Game
            game.togglePause();
            
            if (game.getSnake().getLives() > 0) {
                // the snake has more lives
                wxMessageBox(wxT("Your snake has died. How sad."),
                             wxT("Snake Death"), wxOK | wxICON_EXCLAMATION);
                         
                // restart the game
                game.restart();
            } else {
                // no more lives for the snake
                wxMessageBox(wxT("Your snake is out of lives."),
                             wxT("Game Over"), wxOK | wxICON_INFORMATION);
                             
                // end the Game
                game.end();
                
                // Refresh the display
                Refresh();
            }
        }
    }
}

void NibblesPanel::onKeyDown(wxKeyEvent &event) {
    switch (event.m_keyCode) {
        case WXK_PAUSE:
            // (un)pause the game
            game.togglePause();
            break;
        case WXK_UP:
            // up arrow = north
            if (game.getSnake().getDirection() != SOUTH) {
                game.changeDirection(NORTH);
            }
            
            break;
        case WXK_RIGHT:
            // right arrow = west
            if (game.getSnake().getDirection() != WEST) {
                game.changeDirection(EAST);
            }
            
            break;
        case WXK_DOWN:
            // down arrow = south
            if (game.getSnake().getDirection() != NORTH) {
                game.changeDirection(SOUTH);
            }
            
            break;
        case WXK_LEFT:
            // left arrow = west
            if (game.getSnake().getDirection() != EAST) {
                game.changeDirection(WEST);
            }
            
            break;
        default:
            // allow other handlers to process KEY_DOWN events
            event.Skip();
            break;
    }
}

void NibblesPanel::newGame() {
    // start a new game
    game.start(AVERAGE);
    
    // refresh the screen
    Refresh();
}

IMPLEMENT_CLASS(NibblesPanel, wxPanel)

