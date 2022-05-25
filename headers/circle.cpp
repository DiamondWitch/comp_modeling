//
// Created by Анна on 25.05.2022.
//

#include "circle.h"


CircleSection::CircleSection(Vector2f startPosition) {
    CircleShape circle(2);
    section.setFillColor(Color::Green);
    circle.setRadius(1);
    section.setPosition(startPosition);

}

Vector2f CircleSection::getPosition() {
    return position;
}

void CircleSection::setPosition(Vector2f newPosition) {
    position = newPosition;
}

RectangleShape CircleSection::getShape() {
    return section;
}

void CircleSection::update() {
    section.setPosition(position);
}