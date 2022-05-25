//
// Created by Анна on 25.05.2022.
//

#ifndef UNTITLED2_CIRCLE_H
#define UNTITLED2_CIRCLE_H

#include <SFML/Graphics.hpp>

using namespace sf;

class CircleSection {
private:
    Vector2f position;
    RectangleShape section;
public:
    explicit CircleSection(Vector2f startPosition);

    Vector2f getPosition();
    void setPosition(Vector2f newPosition);

    RectangleShape getShape();

    void update();
};



#endif //UNTITLED2_CIRCLE_H
