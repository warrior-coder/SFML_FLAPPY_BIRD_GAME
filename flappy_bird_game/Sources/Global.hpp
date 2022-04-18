#pragma once


// bird properties
constexpr float FLAP_SPEED = -4.0f;
constexpr float GRAVITY = 0.25f;
constexpr float BIRD_SPEED = 1.0f;
constexpr int BIRD_SIZE = 16;
constexpr int BIRD_START_X = 37;

// font
constexpr int FONT_CHARACTERS_COUNT = 96;

// pipe
constexpr int PIPE_INDENT = 32;					// minimum indent from the ground and from the top to the gap
constexpr int PIPE_WIDTH = 32;
constexpr int GAP_HEIGHT = 64;					// distance between top and bottom pipes
constexpr int GENERATOR_TIMER_DURATION = 128;	// we will generate new pipes after this number of frames

// ground
constexpr int GROUND_Y = 288;

// screen
constexpr int SCREEN_HEIGHT = 320;
constexpr int SCREEN_WIDTH = 180;
constexpr float SCREEN_RESIZE = 3.0f;

// frame duration
constexpr long long MILLISECONDS_FRAME_DURATION(17);