
#ifndef CONSTANTS_HPP_
#define CONSTANTS_HPP_
#include "raylib.h"
#include "raymath.h"
#include <cmath>
#include <cstdlib>
#include <math.h>
#include <vector>
// const int particle_count = 50;

const int screenWidth = 1000;
const int screenHeight = 700;
const Vector2 screenCenter = {(float)screenWidth / 2, (float)screenHeight / 2};
#define GRAVITY 9.81
#define GRAVITATIONAL_CONSTANT 0.6
#define SCALING_FACTOR 1
#define FONT_SIZE 20
const float mouse_radius = 1000;
const std::vector<Color> all_colors = {LIGHTGRAY, GRAY,   DARKGRAY, YELLOW, GOLD,  ORANGE,
                                       PINK,      RED,    MAROON,   GREEN,  LIME,  SKYBLUE,
                                       BLUE,      PURPLE, VIOLET,   BEIGE,  BROWN, DARKBROWN};
#endif
