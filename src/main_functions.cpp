#include "raylib.h"
// earth mass = 5.972 × 10^24 kg
// grav constant = 6.6743 × 10^-11 m3 kg-1 s-2
Vector2 Vector2ScaleDivision(Vector2 v, float scale) {
    Vector2 result = {v.x / scale, v.y / scale};
    return result;
}
