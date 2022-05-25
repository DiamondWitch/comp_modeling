//
// Created by Анна on 24.05.2022.
//

#ifndef UNTITLED2_ENGINE_H
#define UNTITLED2_ENGINE_H


#include "circle.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <vector>

using namespace sf;
using namespace std;

class Engine {
private:
    // Window
//    Vector2f resolution;
//    RenderWindow window;
//    const unsigned int FPS = 60;
//    static const Time TimePerFrame;
//
//    vector<CircleSection> circle;

public:
    Vector2f resolution;
    RenderWindow window;
    const unsigned int FPS = 60;
    static const Time TimePerFrame;

    vector<CircleSection> circle;
    Engine();

    void input();

    void draw();

    void newCircle();
    void addCircleSection();

    // The main loop will be in the run function
    void run();

};


#endif //UNTITLED2_ENGINE_H
