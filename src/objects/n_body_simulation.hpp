#ifndef N_BODY_SIMULATION_HPP
#define N_BODY_SIMULATION_HPP
#include "objects/celestial_body.hpp"
#include <memory>
#include <vector>
class Simulation {

    // can i call this an interface?? lol
  public:
    bool awoken = false;
    Simulation() {}

    void update(float frametime);
    void awake();
    void draw_bodies();
};

class NBodySimulation : public Simulation {

    // NOTE: it imploded. welp
    // trying to find ways to structure this project so it wont implode once it has lots of stuff
  public:
    std::vector<std::shared_ptr<CelestialBody>> bodies;
    bool awoken = false;
    NBodySimulation(std::vector<std::shared_ptr<CelestialBody>> bodies) : bodies(bodies) {}

    void update(float frametime);
    void awake();
    void draw_bodies();
    void draw_orbits(int iterations);
};
class SimulationWithOrbits : public Simulation {
    // SimulationWithOrbits() {}

    std::vector<std::shared_ptr<BodyWithOrbit>> bodies;
};

std::unique_ptr<NBodySimulation>
first_simulation_test(std::vector<std::shared_ptr<CelestialBody>> &allBodies);
std::unique_ptr<NBodySimulation>
orbiting_simulation(std::vector<std::shared_ptr<CelestialBody>> &allBodies);
std::unique_ptr<NBodySimulation>
three_body_simulation(std::vector<std::shared_ptr<CelestialBody>> &allBodies);
std::unique_ptr<NBodySimulation>
four_body_simulation(std::vector<std::shared_ptr<CelestialBody>> &allBodies);
#endif
