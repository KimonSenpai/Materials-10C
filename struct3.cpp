#include <iostream>
#include <cmath>
using std::ostream;
struct Vector {
    double x, y;
    Vector() {
        x = 0;
        y = 0;
    }

    Vector(double x, double y) {
        this->x = x;
        this->y = y;
    }

    double abs() {
        return std::sqrt(x*x + y*y);
    }
};

Vector operator+(Vector a, Vector b) {
    Vector c;
    c.x = a.x + b.x;
    c.y = a.y + b.y;
    return c;
}

ostream& operator<<(ostream& out, Vector v) {
    out << '(' << v.x << "; " << v.y << ')';
    return out;
}

int main() {
    Vector p(3, 5), q(5, 7);
    p = p + q;
    std::cout << p << ' ' << p.abs() << '\n';
}