//
// Created by Анна on 24.05.2022.
//

#ifndef UNTITLED2_MOLECULS_H
#define UNTITLED2_MOLECULS_H

#include <iostream>
#include <vector>
#include <cmath>
#include "Molecul.h"

using namespace std;

class Moleculs {
private:
    int N;               // количество молекул
    double D;           // энергия связи
    double a;           // длина связи
    vector<Molecul> position_current;           // положение частиц в момент времени t
    vector<Molecul> position_old;          // положение молекул в момент времени (t - delta_t)
public:
    Moleculs() {

    }
    Moleculs(int N_, double D_, double a_,
             vector<Molecul> position_current_, vector<Molecul> position_old_): N(N_), D(D_), a(a_),
                                                                                position_current(position_current_), position_old(position_old_)  {
    }

    vector<Molecul> Potentials() {               // считает потенциалы Леннарда-Джонсона
        vector<Molecul> potentials;
        for (int i = 0; i < position_current.size(); ++i) {
            Molecul m1 = position_current[i];
            Molecul x;
            for (int j = 0; j < position_current.size(); ++j) {
                Molecul m2 = position_current[j];
                double r = (m1 - m2).abs();
                if(r == 0) { continue; }
                x =+ (1/r) * (12 * D / a) * (pow((a/r), 13) - (pow((a/r), 7)) / m1.get_m()) * (m1 - m2);
            }
            potentials.push_back(x);
//            cout << "i = " << i << " " << x.get_x() << " " << x.get_y() << endl;
        }
        return potentials;
    }
    auto Position() {      // вычисляет новое положение молекул в момент времени (t + delta_t) по схеме Верле, будем считать delta_t = 1
        auto potentials = Potentials();

        for (int i = 0; i < position_current.size(); ++i) {
            Molecul m_curr = position_current[i];
            Molecul m_old = position_old[i];
            Molecul m_new = m_curr * 2 - m_old + potentials[i];
            position_old[i] = position_current[i];
            position_current[i] = m_new;

            if (position_current[i].get_x() >= 100.0) {
                position_current[i] = Molecul(position_current[i].get_m(), 100.0 - position_current[i].get_x(), position_current[i].get_y());
                position_old[i] = Molecul(position_current[i].get_m(), 100.0 - position_old[i].get_x(),
                                          position_old[i].get_y());
            }
            if (position_current[i].get_y() >= 100.0) {
                position_current[i] = Molecul(position_current[i].get_m(), position_current[i].get_x(), 100.0 - position_current[i].get_y());
                position_old[i] = Molecul(position_current[i].get_m(), position_old[i].get_x(),
                                          100.0 - position_old[i].get_y());
            }


            if (position_current[i].get_x() <= 0.0) {
                position_current[i] = Molecul(position_current[i].get_m(), 100.0 + position_current[i].get_x(), position_current[i].get_y());
                position_old[i] = Molecul(position_current[i].get_m(), 100.0 + position_old[i].get_x(),
                                          position_old[i].get_y());
            }
            if (position_current[i].get_y() <= 0.0) {
                position_current[i] = Molecul(position_current[i].get_m(), position_current[i].get_x(), 100.0 + position_current[i].get_y());
                position_old[i] = Molecul(position_current[i].get_m(), position_old[i].get_x(),
                                          100.0 + position_old[i].get_y());
            }
        }
        return position_current;
    }
    vector<Molecul> get_position_current() const {
        return position_current;
    }
    vector<Molecul> get_position_old() const {
        return position_old;
    }
};


#endif //UNTITLED2_MOLECULS_H
