#include "celestial_body.hpp"
#include "../constants.hpp"
#include "main_functions.hpp"
#include "raylib.h"
#include "raymath.h"
#include <cerrno>
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
    }
}

void CelestialBody::update_position(float frametime) { position += velocity * frametime; }

void CelestialBody::detect_collisions(std::vector<std::shared_ptr<CelestialBody>> &allBodies,
                                      float frametime) {

    for (auto &other_body : allBodies) {
        if (this == other_body.get()) {
            continue;
        }
        detect_collision(other_body, frametime);
    }
}

void CelestialBody::detect_screen_collision() {
    float damping = 0.5;
    if (position.x + radius > screenWidth) {
        velocity.x = -velocity.x * damping;
        position.x = screenWidth - radius;
    } else if (position.x - radius < 0) {
        velocity.x = -velocity.x * damping;
        position.x = radius;
    } else if (position.y + radius > screenHeight) {
        velocity.y = -velocity.y * damping;
        position.y = screenHeight - radius;
    } else if (position.y - radius < 0) {
        velocity.y = -velocity.y * damping;
        position.y = radius;
    }
}

// naive collision detection because i cant be bothered with fancy methods
// for this project, its more focused on the gravity side of the simulation anyways
// TODO:
// option: use axis theorem so we can have squares and polygons
// bonus option: quadtrees
// optimization solution: use a grid structure to minize collision checks

void CelestialBody::detect_collision(std::shared_ptr<CelestialBody> &other_body, float frametime) {
    // read this to understand how this function works
    // https://dipamsen.github.io/notebook/collisions.pdf
    float distance = Vector2Distance(other_body->position, position);
    float radius_sum = radius + other_body->radius;

    if (distance < radius_sum) {
        solve_collision(other_body, frametime);
    }
}

void CelestialBody::solve_collision(std::shared_ptr<CelestialBody> &other_body, float frametime) {
    // find new velocity vectors
    float distance = Vector2Distance(other_body->position, position);

    float mass_sum = mass + other_body->mass;

    Vector2 velocity_dif = other_body->velocity - velocity;
    Vector2 impact = other_body->position - position;

    float relative_change_dot = Vector2DotProduct(velocity_dif, impact);

    Vector2 unit_vector_n = Vector2ScaleDivision(impact, distance * distance * mass_sum);

    // final velocity
    velocity += Vector2Scale(unit_vector_n, 2 * other_body->mass * relative_change_dot);

    // other body
    other_body->velocity -= Vector2Scale(unit_vector_n, 2 * mass * relative_change_dot);

    // ############################################################################
    // solve overlapping

    float radius_sum = radius + other_body->radius;
    float overlap = distance - radius_sum;
    // divide the overlap by 2 so each particle
    // gets pushed the same amount in opposite directions
    overlap /= 2.0f;
    float correction = 0.5f; // NOTE: this value is here to stabilize the simulation

    // points towards the other body
    Vector2 push = Vector2Normalize(impact);
    push += Vector2AddValue(push, overlap + correction);
    other_body->position += push;
    position -= push;
    // ############################################################################
}
