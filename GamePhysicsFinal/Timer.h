#pragma once
#include <SDL.h>
class Timer
{
public:
	Timer();

	void start();
	void stop();
	void pause();
	void unpause();

	Uint32 getTicks();

	bool isStarted() { return mStarted; };
	bool isPaused() { return mPaused; };

private:
	Uint32 mStartTicks;
	Uint32 mPausedTicks;

	bool mPaused;
	bool mStarted;
};

