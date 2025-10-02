#include <iostream>
using namespace std;

class Train
{
private:
    double mass;
    double velocity;
    double x;

public:
    Train(double m) : mass(m), velocity(0.0), x(0.0) {}

    void move(double dt) {
        x += velocity * dt;
    }

    void accelerate(double dp) {
        velocity = (mass * velocity + dp) / mass;
    }

    double getX() {
        return x;
    }
};
/*
int main() {
    Train t(10);
    t.accelerate(1);
    t.move(1);
    cout << "Current X: " << t.getX() << endl;
    t.move(1);
    cout << "Current X: " << t.getX() << endl;
    t.accelerate(-2);
    t.move(3);
    cout << "Current X: " << t.getX() << endl;

    return 0;
}*/
