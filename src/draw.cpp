////
//// Created by Анна on 24.05.2022.
////
#include "Engine.h"


void Engine::draw() {
    window.clear(Color::Black);


    // Draw circle sections
    for (auto &s : circle) {
        window.draw(s.getShape());

    }
    window.display();

}
