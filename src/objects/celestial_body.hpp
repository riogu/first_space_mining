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
    Vector2 currentVelocity;
    Vector2 position;
    Color color;
    void awake();

    void update_velocity(float frametime, std::vector<std::shared_ptr<CelestialBody>> &allBodies);
    void update_position(float frametime);
    void draw();
};
#endif
