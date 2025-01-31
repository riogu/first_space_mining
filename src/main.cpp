#include "constants.hpp"
#include "main_functions.hpp"
#include "objects/celestial_body.hpp"
#include "raylib.h"
#include <memory>

/*
cmake -B build -S . -DCMAKE_EXPORT_COMPILE_COMMANDS=On
cmake --build build
*/
//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void) {

    std::vector<std::shared_ptr<CelestialBody>> allBodies;

    InitWindow(screenWidth, screenHeight, "THIS... is a BUCKET.");

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        ClearBackground(BLACK);
        BeginDrawing();

        // update_screen(allBodies);

        EndDrawing();
    }

    //--------------------------------------------------------------------------------------
    CloseWindow(); // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

void update_screen(const std::vector<std::shared_ptr<CelestialBody>> &allBodies) {
    // remember to delcare stuff as const when you have no intention of changing it
    // (only accessing information)
    for (const auto &body : allBodies) {
        // body->draw();
    }
}
