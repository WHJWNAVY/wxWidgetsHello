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
 
// $Id: Snake.cc,v 1.10 2005/08/27 15:29:10 technoplaza Exp $

#ifdef HAVE_CONFIG_H
    #include <config.h>
#endif

#include "Snake.h"
#include "UIConstants.h"

using namespace nibbles;

void Snake::addSegment(int count) {
    // get the last part of the Snake
    wxPoint &segment = segments[segments.size() - 1];
    
    // clone it
    for (int i = 0; i < count; i++) {
        segments.push_back(segment);
    }
}

void Snake::reincarnate() {
    // The Snake is alive and headed north
    direction = NORTH;
    alive = true;
    
    // center the Snake vertically in the middle of the screen
    wxPoint point((PANEL_WIDTH / 2) - BLOCK_SIZE, 
                  (PANEL_HEIGHT / 2) - (2 * BLOCK_SIZE));
                  
    segments.clear();
    
    for (int i = 0; i < 4; i++) {
        segments.push_back(point);
        point.y += BLOCK_SIZE;
    }
}

void Snake::move() {
    // move the body towards the head
    for (unsigned int i = segments.size() - 1; i >= 1; --i) {
        segments[i].x = segments[i - 1].x;
        segments[i].y = segments[i - 1].y;
    }
    
    // move the head in the current direction
    if (direction == NORTH) {
        segments[0].y -= BLOCK_SIZE;
    } else if (direction == EAST) {
        segments[0].x += BLOCK_SIZE;
    } else if (direction == SOUTH) {
        segments[0].y += BLOCK_SIZE;
    } else {
        segments[0].x -= BLOCK_SIZE;
    }
}

