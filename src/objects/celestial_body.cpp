

#include "raylib.h"
#include "raymath.h"

#include "../constants.hpp"
#include "celestial_body.hpp"
#include <algorithm>
#include <cmath>

Vector2 Vector2MoveAway(Vector2 v, Vector2 target, float maxDistance) {
    Vector2 result = {0};

    float dx = target.x - v.x;
    float dy = target.y - v.y;
    float value = (dx * dx) + (dy * dy);

    if ((value == 0) || ((maxDistance >= 0) && (value <= maxDistance * maxDistance)))
        return target;

    float dist = sqrtf(value);

    result.x = v.x - dx / dist * maxDistance;
    result.y = v.y - dy / dist * maxDistance;

    return result;
}
void CelestialBody::awake() { velocity = initialVelocity; }

void CelestialBody::draw() { DrawCircleV(position, radius, color); }

void CelestialBody::update_velocity(float frametime,
                                    std::vector<std::shared_ptr<CelestialBody>> &allBodies) {
    for (auto &other_body : allBodies) {
        if (this == other_body.get()) {
            continue;
        }

        Vector2 force_direction = Vector2Normalize(other_body->position - position);
        // F = (G x m1 x m2) / r²; F = m x a
        // rewritten as:
        //       a = (G x m2) / r²
        float sqr_distance = Vector2DistanceSqr(other_body->position, position);
        // NOTE: removed GRAV_CONSTANT because values were too small
        Vector2 acceleration =
            force_direction * GRAVITATIONAL_CONSTANT * other_body->mass / sqr_distance;
        // multiplied by direction to turn magnitude into vectorial change
        velocity += acceleration * frametime * SCALING_FACTOR;

        // ---------------------------------------------------------------------------
        // detect collisions between the bodies
        // NOTE: should probably make this more realistic in the future
        float radius_sum = radius + other_body->radius;

        if (sqr_distance < radius_sum * radius_sum) {
            Vector2 move;
            if (other_body->mass > mass) {
                move = Vector2MoveAway(this->position, other_body->position, 2.5);
            } else {
                move = Vector2MoveAway(other_body->position, this->position, 2.5);
            }
            position = move;
        }
        // ---------------------------------------------------------------------------

        // detect_collision(other_body);
    }
}

void CelestialBody::update_position(float frametime) { position += velocity * frametime; }
void CelestialBody::detect_collisions(std::vector<std::shared_ptr<CelestialBody>> &allBodies) {

    for (auto &other_body : allBodies) {
        if (this == other_body.get()) {
            // TraceLog(LOG_DEBUG, TextFormat("this is me"));
            continue;
        }
        detect_collision(other_body);
    }
}
void CelestialBody::detect_collision(std::shared_ptr<CelestialBody> &other_body) {

    float sqr_distance = Vector2DistanceSqr(other_body->position, position);

    if (sqr_distance < radius + other_body->radius) {
    }
}
