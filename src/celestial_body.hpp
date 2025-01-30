

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


    void awake();

    void update_velocity(float frametime, std::vector<std::unique_ptr<CelestialBody>> &allBodies);
    void update_position(float frametime);
    void draw();
};
