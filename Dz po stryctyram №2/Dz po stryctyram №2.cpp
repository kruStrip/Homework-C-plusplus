#include <iostream>
#include <cmath>

struct Vector {
    double x;
    double y;
};

void inputVec(Vector& v) {
    std::cout << "Введите координаты точки (x, y): ";
    std::cin >> v.x >> v.y;
}

struct Rectangle {
    Vector p1; // левая нижняя
    Vector p2; // правая верхняя

    void input() {
        std::cout << "Введите координаты левой нижней точки прямоугольника:\n";
        inputVec(p1);
        std::cout << "Введите координаты правой верхней точки прямоугольника:\n";
        inputVec(p2);
    }

    bool check() {
        return p1.x < p2.x&& p1.y < p2.y;
    }

    double area() {
        if (!check()) return 0;
        return (p2.x - p1.x) * (p2.y - p1.y);
    }

    double perim() {
        if (!check()) return 0;
        return 2 * ((p2.x - p1.x) + (p2.y - p1.y));
    }
};


struct Square : public Rectangle {
    void input() {
        std::cout << "Введите координаты левой нижней точки квадрата:\n";
        inputVec(p1);
        std::cout << "Введите длину стороны квадрата: ";
        double side;
        std::cin >> side;
        p2 = { p1.x + side, p1.y + side };
    }

    bool check() {
        return Rectangle::check() && (p2.x - p1.x) == (p2.y - p1.y);
    }
};


struct Triangle {
    Vector p1, p2, p3;

    void input() {
        std::cout << "Введите координаты 1-ой точки треугольника:\n";
        inputVec(p1);
        std::cout << "Введите координаты 2-ой точки треугольника:\n";
        inputVec(p2);
        std::cout << "Введите координаты 3-ей точки треугольника:\n";
        inputVec(p3);
    }

    bool check() {

        double area = 0.5 * std::abs(
            p1.x * (p2.y - p3.y) +
            p2.x * (p3.y - p1.y) +
            p3.x * (p1.y - p2.y)
        );
        return area > 0;
    }

    double area() {
        if (!check()) return 0;
        return 0.5 * std::abs(
            p1.x * (p2.y - p3.y) +
            p2.x * (p3.y - p1.y) +
            p3.x * (p1.y - p2.y)
        );
    }

    double perim() {
        if (!check()) return 0;
        double a = std::hypot(p2.x - p1.x, p2.y - p1.y);
        double b = std::hypot(p3.x - p2.x, p3.y - p2.y);
        double c = std::hypot(p1.x - p3.x, p1.y - p3.y);
        return a + b + c;
    }
};


struct Circle {
    Vector center;
    double radius;

    void input() {
        std::cout << "Введите координаты центра круга:\n";
        inputVec(center);
        std::cout << "Введите радиус круга: ";
        std::cin >> radius;
    }

    bool check() {
        return radius > 0;
    }

    double area() {
        if (!check()) return 0;
        return 3.14 * radius * radius;
    }

    double perim() {
        if (!check()) return 0;
        return 2 * 3.14 * radius;
    }
};


int main() {
    setlocale(0, "");

    Rectangle rect;
    rect.input();
    std::cout << "Площадь прямоугольника: " << rect.area() << "\n";
    std::cout << "Периметр прямоугольника: " << rect.perim() << "\n";

    Square sq;
    sq.input();
    std::cout << "Площадь квадрата: " << sq.area() << "\n";
    std::cout << "Периметр квадрата: " << sq.perim() << "\n";

    Triangle tri;
    tri.input();
    std::cout << "Площаль треугольника: " << tri.area() << "\n";
    std::cout << "Периметр треугольника: " << tri.perim() << "\n";

    Circle circ;
    circ.input();
    std::cout << "Площадь круга: " << circ.area() << "\n";
    std::cout << "Периметр круга: " << circ.perim() << "\n";

    return 0;
}

