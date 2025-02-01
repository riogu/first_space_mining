#ifndef MAIN_FUNCTIONS_HPP
#define MAIN_FUNCTIONS_HPP

#include "constants.hpp"
#include "raylib.h"
#include <memory>

#include "objects/celestial_body.hpp"
#include "objects/n_body_simulation.hpp"

void update_screen(const std::unique_ptr<NBodySimulation> &simulation);
#endif
