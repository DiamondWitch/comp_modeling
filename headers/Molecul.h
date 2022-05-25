//
// Created by Анна on 24.05.2022.
//

#ifndef UNTITLED2_MOLECUL_H
#define UNTITLED2_MOLECUL_H

#include <cmath>


class Molecul {
private:
    double m, x, y;
public:
    Molecul() {

    }
    Molecul(double m_, double x_, double y_): m(m_), x(x_), y(y_) {

    }
    Molecul(const Molecul& m1) {
        m = m1.m;
        x = m1.x;
        y = m1.y;
    }
    friend Molecul operator+(Molecul m1, const Molecul& m2) {
        m1 = Molecul(m1.m, m1.x + m2.x, m1.y + m2.y);
        return  m1;
    }
    friend Molecul operator-(Molecul m1, const Molecul& m2) {
        m1 = Molecul(m1.m, m1.x - m2.x, m1.y - m2.y);
        return  m1;
    }
    friend Molecul operator*(Molecul m1, const double s) {
        m1 = Molecul(m1.m, m1.x * s, m1.y *s);
        return m1;
    }
    friend Molecul operator*(double s, const Molecul& m1) {
        return m1 * s;
    }
    friend Molecul operator+=(Molecul& m1, const Molecul& m2) {
        m1 = m1 + m2;
        return m1;
    }
    double abs() const {
        double r = 0;
        r = sqrt(pow(x,2) + pow(y,2));
        return r;
    }
    double get_m() const {
        return m;
    }
    double get_x() const {
        return x;
    }
    double get_y() const {
        return y;
    }
};


#endif //UNTITLED2_MOLECUL_H
