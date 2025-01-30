

#include "raylib.h"
#include "raymath.h"

#include "celestial_body.hpp"



void CelestialBody::awake() {
    currentVelocity = initialVelocity;
} 
