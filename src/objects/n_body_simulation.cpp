#include "n_body_simulation.hpp"

void NBodySimulation::awake() {
    for (auto &body : bodies) {
        body->awake();
    }
    awoken = true;
}
void NBodySimulation::update(float frametime) {
    if (!awoken)
        return;
    for (auto &body : bodies) {
        body->update_velocity(frametime, bodies);
    }
    for (auto &body : bodies) {
        body->update_position(frametime);
        body->detect_screen_collision(frametime);
    }
    // for (auto &body : bodies) {
    //     body->detect_collisions(bodies);
    // }
}
