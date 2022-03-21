#pragma once

#include <chrono>


// bird properties
const float FLAP_SPEED = -4.0f;
const float GRAVITY = 0.25f;
const float BIRD_SPEED = 1.0f;
const int BIRD_SIZE = 16U;
const int BIRD_START_X = 37U;

// font
const int FONT_SIZE = 32U;

// pipe
const int PIPE_INDENT = 32U;				// minimum indent from the ground and from the top to the gap
const int PIPE_WIDTH = 32U;
const int GAP_HEIGHT = 64U;					// distance between top and bottom pipes
const int GENERATOR_TIMER_DURATION = 128U;	// we will generate new pipes after this number of frames

// ground
const int GROUND_Y = 288U;

// screen
const int SCREEN_HEIGHT = 320;
const int SCREEN_WIDTH = 180;
const float SCREEN_RESIZE = 3.0f;

// frame
const std::chrono::microseconds FRAME_DURATION(16667);