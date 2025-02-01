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
#endif
