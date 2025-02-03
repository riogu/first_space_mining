#ifndef CELESTIAL_BODY_HPP
#define CELESTIAL_BODY_HPP

#include "raylib.h"
#include "raymath.h"
#include "spline.hpp"
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
    void detect_collision(std::shared_ptr<CelestialBody> &other_body, float frametime);
    void solve_collision(std::shared_ptr<CelestialBody> &other_body, float frametime);
    void detect_collisions(std::vector<std::shared_ptr<CelestialBody>> &allBodies, float frametime);
    void detect_screen_collision();
    void draw();
};

class Orbit {
  public:
    Spline spline;
    /* -> timeleap is in seconds */
    int timeleap;

    Orbit(std::shared_ptr<CelestialBody> body, int timeleap, Color color)
        : spline(color), timeleap(timeleap) {}
  // want to also build orbits from simple celestial body copies so i add 2 constructors
    Orbit(CelestialBody body, int timeleap, Color color)
        : spline(color), timeleap(timeleap) {}
    void draw();
};

class BodyWithOrbit {
    std::shared_ptr<CelestialBody> body;
    std::shared_ptr<Orbit> orbit;

    BodyWithOrbit(std::shared_ptr<CelestialBody> body, std::shared_ptr<Orbit> orbit)
        : body(body), orbit(orbit) {}
};

#endif
