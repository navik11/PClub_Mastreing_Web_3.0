#include <iostream>
#include <cmath>
using namespace std;

class Car {
    string make;
    string model;
    int year;
    int speed;
    int x;
    int y;
    int z;

    public:
    Car(string name, string model, int year, int speed, int x, int y, int z) {
        this->make = name;
        this->model = model;
        this->year = year;
        this->speed = speed;
        this->x = x;
        this->y = y;
        this->z = z;
    }

    // increases the speed by x;
    void accelerate(int x) {
        speed += x;
    }

    // decreases the speed by x
    void brake(int x) {
        if (speed > x) {
            speed -= x;
        } else {
            speed = 0;
        }
    }

    // updates the position in 3D
    void move() {
        y += speed;
        x += speed;
        z += speed;
    }

    // detects whether the cars have collided or not
    bool detect_collision(Car car2) {
        return (car2.x == x && car2.y == y && car2.z == z);
    }

    // returns the time taken to collide
    double time_to_collision(Car car2) {
        int xdis = car2.x - x;
        int ydis = car2.y - y;
        int zdis = car2.z - z;
        double speed_diff = speed - car2.speed;
        return (sqrt(xdis * xdis + ydis * ydis + zdis * zdis)) / abs(speed_diff);
    }
};

int main() {
    Car car1 = Car("BMW", "M4", 2016, 20, 0, 0, 0);
    Car car2 = Car("Mercedes", "Benz", 2017, 15, 0, 0, 0);

    cout << car1.detect_collision(car2) <<endl;
    car1.move();
    cout << car1.detect_collision(car2) <<endl;
    cout << car1.time_to_collision(car2) <<endl;

    return 0;
}
