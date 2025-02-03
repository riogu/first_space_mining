#ifndef MAIN_FUNCTIONS_HPP
#define MAIN_FUNCTIONS_HPP

#include "objects/n_body_simulation.hpp"
#include <memory>

void update_screen(const std::unique_ptr<NBodySimulation> &simulation);
Vector2 Vector2ScaleDivision(Vector2 v, float scale);
#endif
