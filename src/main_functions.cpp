#include "constants.hpp"
#include "main_functions.hpp"
#include "objects/celestial_body.hpp"
#include "objects/n_body_simulation.hpp"
#include "raylib.h"
#include <memory>
// earth mass = 5.972 × 10^24 kg
// grav constant = 6.6743 × 10^-11 m3 kg-1 s-2
std::unique_ptr<NBodySimulation>
first_simulation_test(std::vector<std::shared_ptr<CelestialBody>> &allBodies) {
    // NOTE: not using all bodies atm
    // using y = 140 creates an orbit
    std::shared_ptr body_smol = std::make_shared<CelestialBody>(
        24, 60000, (Vector2){0, 140}, (Vector2){screenWidth / 4.0f, screenHeight / 2.0f}, BLUE);
    std::shared_ptr body_beeg =
        std::make_shared<CelestialBody>(100, 8000000, (Vector2){0, 10}, screenCenter, RED);
    std::vector<std::shared_ptr<CelestialBody>> new_vec;
    // new_vec.reserve(2);
    new_vec.push_back(body_smol);
    new_vec.push_back(body_beeg);
    std::unique_ptr<NBodySimulation> first_sim = std::make_unique<NBodySimulation>(new_vec);
    return first_sim;
}

std::unique_ptr<NBodySimulation>
orbiting_simulation(std::vector<std::shared_ptr<CelestialBody>> &allBodies) {
    // NOTE: not using all bodies atm
    std::shared_ptr body_smol = std::make_shared<CelestialBody>(
        15, 60000, (Vector2){0, 140}, (Vector2){screenWidth / 4.0f, screenHeight / 2.0f}, BLUE);
    std::shared_ptr body_beeg =
        std::make_shared<CelestialBody>(100, 9000000, (Vector2){0, 0}, screenCenter, RED);
    std::vector<std::shared_ptr<CelestialBody>> new_vec;
    // new_vec.reserve(2);
    new_vec.push_back(body_smol);
    new_vec.push_back(body_beeg);
    std::unique_ptr<NBodySimulation> first_sim = std::make_unique<NBodySimulation>(new_vec);
    return first_sim;
}
