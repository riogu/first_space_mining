#include "n_body_simulation.hpp"

void NBodySimulation::awake(float frametime) {
    for (auto &body : bodies) {
        body->awake();
    }
}
void NBodySimulation::update(float frametime) {
    for (auto &body : bodies) {
        body->update_velocity(frametime, bodies);
    }
    for (auto &body : bodies) {
        body->update_position(frametime);
    }
}
