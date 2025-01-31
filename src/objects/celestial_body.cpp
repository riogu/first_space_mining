

#include "raylib.h"
#include "raymath.h"

#include "../constants.hpp"
#include "celestial_body.hpp"

void CelestialBody::awake() { currentVelocity = initialVelocity; }

void CelestialBody::draw() { DrawCircleV(position, radius, color); }

void CelestialBody::update_velocity(float frametime,
                                    std::vector<std::shared_ptr<CelestialBody>> &allBodies) {
    for (auto &other_body : allBodies) {
        if (other_body.get() != this) {
            Vector2 force_direction = Vector2Normalize(other_body->position - position);
            // F = (G x m1 x m2) / r²; F = m x a
            // rewritten as:
            //       a = (G x m2) / r²
            float sqr_distance = Vector2DistanceSqr(other_body->position, position);
            Vector2 acceleration =
                force_direction * GRAVITATIONAL_CONSTANT * other_body->mass / sqr_distance;
            // multiplied by direction to turn magnitude into vectorial change
            currentVelocity += acceleration * frametime;
        }
    }
}

void CelestialBody::update_position(float frametime) { position += currentVelocity * frametime; }
