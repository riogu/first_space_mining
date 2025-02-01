#ifndef N_BODY_SIMULATION_HPP
#define N_BODY_SIMULATION_HPP
#include "celestial_body.hpp"
#include <memory>

class NBodySimulation {

    // trying to find ways to structure this project so it wont implode once it has lots of stuff
  public:
    std::vector<std::shared_ptr<CelestialBody>> bodies;
    bool awoken = false;
    NBodySimulation(std::vector<std::shared_ptr<CelestialBody>> bodies) : bodies(bodies) {}

    void update(float frametime);
    void awake();
};
std::unique_ptr<NBodySimulation>
first_simulation_test(std::vector<std::shared_ptr<CelestialBody>> &allBodies);
std::unique_ptr<NBodySimulation>
orbiting_simulation(std::vector<std::shared_ptr<CelestialBody>> &allBodies);
Vector2 Vector2ScaleDivision(Vector2 v, float scale);
std::unique_ptr<NBodySimulation>
three_body_simulation(std::vector<std::shared_ptr<CelestialBody>> &allBodies);
std::unique_ptr<NBodySimulation>
four_body_simulation(std::vector<std::shared_ptr<CelestialBody>> &allBodies);
#endif
