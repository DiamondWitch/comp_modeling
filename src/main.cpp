#include <chrono>
#include <thread>
#include <SFML/Graphics.hpp>
#include <istream>
#include "../headers/Engine.h"
#include <random>
#include "../headers/Molecul.h"
#include "../headers/Moleculs.h"
#include <math.h>


using namespace std;
using namespace sf;

ostream& operator<<(ostream& os, const vector<Molecul>& mols) {
    for(const auto& item: mols) {
        os << "x = " << item.get_x() << " y = " << item.get_y() << endl;
    }
    return os;
}

int main()
{
    // возьмем молекулы водорода
    int N = 100;          // количество молекул
    double D = 2.182700518 * pow(10, -18);          // энергия связи 2.182700518 * pow(10, -18)
    double a = 	0.7416 * pow(10, -10);              // длина связи
    default_random_engine gen; //генератор случайных чисел
    uniform_real_distribution<double> dist(0.0,90.0);
    vector<Molecul> position_current;
    double m = 2 * pow(10,-3);              // масса молекулы водорода
    for(int i = 0; i < N; i++) {
        double x = dist(gen);
        double y = dist(gen);
        Molecul m_i(m, x, y);
        position_current.push_back(m_i);
    }
    uniform_real_distribution<double> dist2(0.0,0.1);
    vector<Molecul> position_old;
    for(int i = 0; i < N; i++) {
        double x = dist2(gen);
        double y = dist2(gen);
        Molecul m_i(m, position_current[i].get_x() + x, position_current[i].get_y() + y);
        position_old.push_back(m_i);
    }


    int iterations = 100;                   // количество итераций цикла для поиска новых координат молекул
    Moleculs therm_system(N, D, a, position_current, position_old);
    cout << therm_system.get_position_current();
    cout << "-------------------" << endl;
    cout << therm_system.get_position_old();
    cout << "-------------------" << endl;

    RenderWindow window;
    window.create(VideoMode(100U, 100U), "Movement of gas molecules");

    int num_iter = 0;
    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        auto new_positions = therm_system.Position();
        window.clear();
        for (int k = 0; k < N; k++)
        {
            Vector2f coordinates;
            CircleShape circle(1);
            circle.setFillColor(Color::Green);
            circle.setRadius(1);
            coordinates.x = float(new_positions[k].get_x());
            coordinates.y = float(new_positions[k].get_y());
            cout << num_iter << " coordinates " << coordinates.x << " " << coordinates.y << endl;
            circle.setPosition(coordinates.x, coordinates.y);
            window.draw(circle);
        }
        window.display();
//        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        cout << "num iter " << num_iter << endl;
        cout << therm_system.get_position_current();
        num_iter += 1;
    }


     //проверка
     //Закон сохранения энергии
    cout << "-------------------" << endl;
    vector<double> speed2;
    speed2.push_back(abs(position_current[0].get_x()  - position_old[0].get_x()));
    speed2.push_back(abs(position_current[0].get_y()  - position_old[0].get_y()));

    for (int i = 0; i < speed2.size(); ++i) {
        cout << speed2[i] << endl;
    }



//    for (int i = 1; i < N; ++i) {
//        Molecul v1 = position_current[i] - position_old[i];                         // скорость молекул
//        double speed1 = sqrt(pow(v1.get_x(), 2) + pow(v1.get_y(), 2));
//        Moleculs therm_system(N, D, a, position_current, position_old);
//        Molecul v2 = position_current[i] - position_old[i];                         // скорость молекул
//        double speed2 = sqrt(pow(v2.get_x(), 2) + pow(v2.get_y(), 2));
//        if (speed1 == speed2) {
//            cout << "True" << endl;
//        } else (cout << "False" << endl);
//
//    }


    // Распределение по скоростям Максвелл
    return 0;
}