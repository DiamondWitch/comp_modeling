#include <SFML/Graphics.hpp>
#include <istream>
#include "Engine.h"
#include <random>
#include "Molecul.h"
#include "Moleculs.h"


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
    double D = 2.182700518 * pow(10, -18);          // энергия связи  2.182700518 * pow(10, -18)
    double a = 	0.7416 * pow(10, -10);              // длина связи
    default_random_engine gen; //генератор случайных чисел
    uniform_real_distribution<double> dist(0.0,10.0);
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

    Engine engine;
//    engine.run();

    for (int j = 0; j < iterations; ++j) {
        therm_system.Position();

        Vector2f coordinates;
        CircleShape circle(1);
        circle.setFillColor(Color::Green);
        //        circle.setRadius(1);
        coordinates.x = float(position_current[j].get_x());
        coordinates.y = float(position_current[j].get_y());
        circle.setPosition(coordinates.x,coordinates.y);
        engine.window.clear();
        engine.window.draw(circle);
        engine.window.display();
    }
    cout << therm_system.get_position_current();


    return 0;
}