#include "n_body_simulation.hpp"
#include "constants.hpp"
#include "raylib.h"
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
        body->detect_screen_collision();
        body->detect_collisions(bodies, frametime);
    }
    for (auto &body : bodies) {
        body->update_position(frametime);
    }
}

void NBodySimulation::draw_bodies() {
    for (const auto &body : bodies) {
        body->draw();
    }
}

std::unique_ptr<NBodySimulation>
first_simulation_test(std::vector<std::shared_ptr<CelestialBody>> &allBodies) {
    // NOTE: not using all bodies atm
    // using y = 140 creates an orbit
    std::shared_ptr body_smol = std::make_shared<CelestialBody>(
        24, 600000, (Vector2){1000, 140}, (Vector2){screenWidth / 4.0f, screenHeight / 2.0f}, BLUE);
    std::shared_ptr body_beeg =
        std::make_shared<CelestialBody>(100, 8000000, (Vector2){-150, 10}, screenCenter, RED);
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
std::unique_ptr<NBodySimulation>
three_body_simulation(std::vector<std::shared_ptr<CelestialBody>> &allBodies) {
    std::shared_ptr body_smol = std::make_shared<CelestialBody>(
        24, 60000, (Vector2){1000, 140}, (Vector2){screenWidth / 4.0f, screenHeight / 2.0f}, BLUE);
    std::shared_ptr body_mid = std::make_shared<CelestialBody>(
        50, 6000000, (Vector2){1000, 140},
        (Vector2){3.0f * screenWidth / 4.0f, screenHeight / 2.0f}, GREEN);
    std::shared_ptr body_beeg =
        std::make_shared<CelestialBody>(100, 89000000, (Vector2){-150, 10}, screenCenter, RED);
    std::vector<std::shared_ptr<CelestialBody>> new_vec;
    // new_vec.reserve(3);
    new_vec.push_back(body_smol);
    new_vec.push_back(body_mid);
    new_vec.push_back(body_beeg);
    std::unique_ptr<NBodySimulation> first_sim = std::make_unique<NBodySimulation>(new_vec);
    return first_sim;
}
std::unique_ptr<NBodySimulation>
four_body_simulation(std::vector<std::shared_ptr<CelestialBody>> &allBodies) {
    std::shared_ptr body_smoller = std::make_shared<CelestialBody>(
        10, 6000, (Vector2){0, 140}, (Vector2){screenWidth / 2.0f, 3.0f * screenHeight / 4.0f},
        ORANGE);
    std::shared_ptr body_smol = std::make_shared<CelestialBody>(
        24, 60000, (Vector2){0, 140}, (Vector2){screenWidth / 4.0f, screenHeight / 2.0f}, BLUE);
    std::shared_ptr body_mid = std::make_shared<CelestialBody>(
        50, 6000000, (Vector2){100, 140}, (Vector2){3.0f * screenWidth / 4.0f, screenHeight / 2.0f},
        GREEN);
    std::shared_ptr body_beeg =
        std::make_shared<CelestialBody>(100, 89000000, (Vector2){0, 0}, screenCenter, RED);
    std::vector<std::shared_ptr<CelestialBody>> new_vec;
    // new_vec.reserve(3);
    new_vec.push_back(body_smoller);
    new_vec.push_back(body_smol);
    new_vec.push_back(body_mid);
    new_vec.push_back(body_beeg);
    std::unique_ptr<NBodySimulation> first_sim = std::make_unique<NBodySimulation>(new_vec);
    return first_sim;
}
