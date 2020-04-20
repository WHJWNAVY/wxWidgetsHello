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
 
// $Id: Snake.h,v 1.7 2005/08/27 15:29:10 technoplaza Exp $

#ifndef _SNAKE_HH_
#define _SNAKE_HH_

#include <vector>

#include <wx/gdicmn.h>

#include "EngineConstants.h"

namespace nibbles {
    class Snake {
    private:
        std::vector<wxPoint> segments;
        enum Direction direction;
        unsigned int lives;
        bool alive;
        
    public:
        /**
         * Creates a new Snake.
         *
         * @param lives The number of lives this Snake has.
         */
        Snake(unsigned int lives);
        
        /**
         * Gets the segments of this Snake.
         *
         * @return The snake segment vector.
         */
        const std::vector<wxPoint> &getSegments() const;
        
        /**
         * Adds a segment to this Snake.
         *
         * @param count The number of segments to add.
         */
        void addSegment(int count = 1);
        
        /**
         * Gets the direction this Snake is moving in.
         *
         * @return The direction.
         */
        enum Direction getDirection() const;
        
        /**
         * Sets the direction this Snake is moving in.
         *
         * @param direction The new direction.
         */
        void setDirection(enum Direction direction);
        
        /**
         * Gets the number of lives this Snake has.
         *
         * @return The number of lives remaining.
         */
        unsigned int getLives() const;
        
        /**
         * Adds a life to this Snake.
         */
        void addLife();
        
        /**
         * Subtracts a life from this Snake.
         */
        void subtractLife();
        
        /**
         * Queries if this Snake is alive.
         *
         * @return true if this Snake is alive; false otherwise.
         */
        bool isAlive() const;
        
        /**
         * Sets whether this Snake is alive or not.
         *
         * @param alive true if this Snake is alive; false otherwise.
         */
        void setAlive(bool alive);
        
        /**
         * Initializes this Snake.
         */
        void reincarnate();
        
        /**
         * Moves this Snake one unit in the current direction.
         */
        void move();
    };
    
    inline Snake::Snake(unsigned int lives) : lives(lives) { reincarnate(); }
    inline const std::vector<wxPoint> &Snake::getSegments() const { return segments; }
    inline enum Direction Snake::getDirection() const { return direction; }
    inline void Snake::setDirection(enum Direction direction) { this->direction = direction; }
    inline unsigned int Snake::getLives() const { return lives; }
    inline void Snake::addLife() { ++lives; }
    inline void Snake::subtractLife() { --lives; }
    inline bool Snake::isAlive() const { return alive; }
    inline void Snake::setAlive(bool alive) { this->alive = alive; }
}

#endif

