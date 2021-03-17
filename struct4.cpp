#include <iostream>
#include <cmath>
using namespace std;

struct Vector {
    double x, y;

    double abs() {
        return sqrt(x*x + y*y);
    }

    Vector();
    Vector(double x, double y);
    Vector operator-();
    Vector operator-(Vector a);
};
Vector operator+(Vector x, Vector y);
Vector::Vector() {
    x = 0;
    y = 0;
}

Vector::Vector(double x, double y) {
    (*this).x = x;
    this->y = y;
}
Vector Vector::operator-() {
    return Vector(-x, -y);
}

Vector Vector::operator-(Vector a) {
    return (*this) + -a;
}
Vector operator+(Vector x, Vector y) {
    Vector c;
    c.x = x.x + y.x;
    c.y = x.y + y.y;
    return c;
}

ostream& operator<<(ostream& out, Vector v) {
    out << '(' << v.x << "; " << v.y << ')'; 
    return out;
}

int main() {
    Vector p(5, 7), q(0, 5);
    p = p + q;

    cout << p << ' ' << p.abs() << '\n';
}