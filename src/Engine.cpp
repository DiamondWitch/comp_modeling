//
// Created by Анна on 24.05.2022.
//

#include "Engine.h"

const sf::Time Engine::TimePerFrame = seconds(1.f/60.f);

Engine::Engine() {
    resolution = Vector2f(100, 100);
    window.create(VideoMode(resolution.x, resolution.y), "Movement of gas molecules ", Style::Default);
    window.setFramerateLimit(FPS);

}


// This is the initial Circle created at the start of each level
//void Engine::newCircle() {
//    circle.clear();
//    circle.emplace_back(Vector2f(100,100));
//    circle.emplace_back(Vector2f(80,100));
//    circle.emplace_back(Vector2f(60,100));
//}

//void Engine::addCircleSection() {
//    // Just add the section at the same position as the last section of the Circle, it will follow normally
//    Vector2f newSectionPosition = circle[circle.size() - 1].getPosition();
//    circle.emplace_back(newSectionPosition);
//}


void Engine::run() {
    // Main loop - Runs until the window is closed
    while (window.isOpen()) {
        input();
        draw();

    }
}

