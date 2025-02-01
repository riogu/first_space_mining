#ifndef CELESTIAL_BODY_HPP
#define CELESTIAL_BODY_HPP

#include "raylib.h"
#include "raymath.h"
#include <memory>
#include <vector>

class CelestialBody {

  public:
    float radius;
    float mass;
    Vector2 initialVelocity;
    Vector2 velocity;
    Vector2 position;
    Color color;

    CelestialBody(float radius, float mass, Vector2 initialVelocity, Vector2 position, Color color)
        : radius(radius), mass(mass), initialVelocity(initialVelocity), position(position),
          color(color) {}

    void awake();
    void update_velocity(float frametime, std::vector<std::shared_ptr<CelestialBody>> &allBodies);
    void update_position(float frametime);
    void detect_collision(std::shared_ptr<CelestialBody> &other_body);
    void detect_collisions(std::vector<std::shared_ptr<CelestialBody>> &allBodies);
    void detect_screen_collision(float frametime);
    void draw();
};
#endif
