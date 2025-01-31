#ifndef MAIN_FUNCTIONS_HPP
#define MAIN_FUNCTIONS_HPP

#include "raylib.h"
#include "constants.hpp"
#include <memory>

#include "objects/celestial_body.hpp"

void update_screen(std::vector<std::shared_ptr<CelestialBody>> &allBodies);
#endif
