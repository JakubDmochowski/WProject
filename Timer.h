#pragma once

#include <SDL.h>

class Timer
{
    private:
        //The clock time when the timer started
        unsigned int mStartTicks;

        //The ticks stored when the timer was paused
        unsigned int mPausedTicks;

        //The timer status
        bool mPaused;
        bool mStarted;

    public:
        //Initializes variables
        Timer();

        //The various clock actions
        void start();
        void stop();
        void pause();
        void unpause();

        //Gets the timer's time
        unsigned int getTime() const;

        //Checks the status of the timer
        bool isStarted() const;
        bool isPaused() const;

};
