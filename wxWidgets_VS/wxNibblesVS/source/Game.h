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
 
// $Id: Game.h,v 1.9 2005/08/27 15:29:10 technoplaza Exp $

#ifndef _GAME_HH_
#define _GAME_HH_

#include <cstddef>

#include "EngineConstants.h"
#include "Level.h"

namespace nibbles {
    class Snake;
    class Timer;
    class NibblesPanel;
    
    class Game {
    private:
        wxPoint apple;
        Snake *snake;
        Level level;
        Timer *timer;
        NibblesPanel &panel;
        enum Difficulty difficulty;
        bool playing, paused;
        
        /// The number of starting lives for each difficulty setting
        static const int LIVES[];
        
        /// The speed for each difficulty level (lower = faster)
        static const int SPEEDS[];
        
        /**
         * Checks if a point is occupied, either by the snake or a wall.
         *
         * @param point The wxPoint to check.
         * @param checkHead If the Snake's head should be checked.
         *
         * @return true if the point is occupied; false otherwise.
         */
        bool isOccupied(const wxPoint &point, bool checkHead = false) const;
        
        /**
         * Moves the apple to a random position on the screen.
         */
        void moveApple();
        
    public:
        /**
         * Creates a new Game.
         *
         * @param panel The NibblesPanel displaying this Game.
         */
        Game(NibblesPanel &panel);
        
        /**
         * Destructs this Game.
         */
        ~Game();
        
        /**
         * Gets the apple position.
         *
         * @return The apple position.
         */
        const wxPoint &getApple() const;
        
        /**
         * Gets this Game's Snake.
         *
         * @return The Snake.
         */
        const Snake &getSnake() const;
        
        /**
         * Returns the Level used by this Game.
         *
         * @return The Level.
         */
        const Level &getLevel() const;
        
        /**
         * Gets the difficulty setting for this Game.
         *
         * @return The difficulty setting.
         */
        enum Difficulty getDifficulty() const;
        
        /**
         * Queries if this Game is being played.
         *
         * @return true if this Game is being played; false otherwise.
         */
        bool isPlaying() const;
        
        /**
         * Starts this Game.
         *
         * @param difficulty The difficulty setting.
         */
        void start(enum Difficulty difficulty);
        
        /**
         * Restarts the current level.
         */
        void restart();
        
        /**
         * Ends the current Game.
         */
        void end();
        
        /**
         * Change the direction the Snake is moving.
         *
         * @param direction The new direction.
         */
        void changeDirection(enum Direction direction);
        
        /**
         * Checks whether this Game is paused or not.
         *
         * @return true if paused; false otherwise.
         */
        bool isPaused() const;
        
        /**
         * Toggles whether the Game is paused or not.
         */
        void togglePause();
        
        /**
         * Called when the timer goes off.
         */
        void tick();
    };
    
    inline const wxPoint &Game::getApple() const { return apple; }
    inline const Snake &Game::getSnake() const { return *snake; }
    inline const Level &Game::getLevel() const { return level; }
    inline enum Difficulty Game::getDifficulty() const { return difficulty; }
    inline bool Game::isPlaying() const { return playing; }
    inline bool Game::isPaused() const { return paused; }
}

#endif

