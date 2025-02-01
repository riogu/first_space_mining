#ifndef MAIN_FUNCTIONS_HPP
#define MAIN_FUNCTIONS_HPP

#include "constants.hpp"
#include "raylib.h"
#include <memory>

#include "objects/celestial_body.hpp"
#include "objects/n_body_simulation.hpp"

void update_screen(const std::unique_ptr<NBodySimulation> &simulation);
std::unique_ptr<NBodySimulation>
first_simulation_test(std::vector<std::shared_ptr<CelestialBody>> &allBodies);
std::unique_ptr<NBodySimulation>
orbiting_simulation(std::vector<std::shared_ptr<CelestialBody>> &allBodies);
Vector2 Vector2ScaleDivision(Vector2 v, float scale);
std::unique_ptr<NBodySimulation>
three_body_simulation(std::vector<std::shared_ptr<CelestialBody>> &allBodies);
#endif
