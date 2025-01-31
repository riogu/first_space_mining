#include "celestial_body.hpp"
#include <memory>

class NBodySimulation {

    // trying to find ways to structure this project so it wont implode once it has lots of stuff
    std::vector<std::shared_ptr<CelestialBody>> bodies;

    void update(float frametime);
    void awake(float frametime);

};
