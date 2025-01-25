#include <iostream>
#include <cmath>

struct Vector {
    double x;
    double y;
};

void equal(Vector point1, Vector point2) {
    if ((point1.x == point2.x) && (point1.y == point2.y)) {
        std::cout << "Две точки являются одинаковыми.\n";
    }
    else {
        std::cout << "Две точки не являются одинаковыми.\n";
    }
}

void distance(Vector point1, Vector point2) {
    double xs = point2.x - point1.x;
    xs = pow(xs, 2);
    double ys = point2.y - point1.y;
    ys = pow(ys, 2);
    double dist = sqrt(xs + ys);

    std::cout << "Расстояние между двумя точками: " << dist << std::endl;
}

void angle(Vector point1, Vector point2, Vector common_point) {
    double x1 = point2.x - point1.x;
    double y1 = point2.y - point1.y;
    double x2 = common_point.x - point1.x;
    double y2 = common_point.y - point1.y;

    double scal = x1 * x2 + y1 * y2;
    double dlina1 = sqrt(x1 * x1 + y1 * y1);
    double dlina2 = sqrt(x2 * x2 + y2 * y2);

    if (dlina1 == 0 || dlina2 == 0) {
        std::cout << "Длина одного из векторов равна 0\n";
        return;
    }

    double cos = scal / (dlina1 * dlina2);
    double ygol = acos(cos) * 180 / 3.14;
    std::cout << "Угол между векторами: " << ygol << " градусов.\n";
}

void normalize(Vector point) {
    double vel = sqrt(point.x * point.x + point.y * point.y);
    if (vel == 0) {
        std::cout << "Невозможно нормализовать нулевой вектор.\n";
        return;
    }

    Vector normal = { point.x / vel, point.y / vel };
    std::cout << "Нормализованный вектор: " << normal.x << ", " << normal.y << "\n";
}

void rotate90(Vector point, bool napr) {
    int x = point.x;
    int y = point.y;

    if (napr) {
        std::cout << "Вектор после поворота на 90 градусов по часовой стрелке: " << y << ", " << -x << "\n";
    }
    else {
        std::cout << "Вектор после поворота на 90 градусов против часовой стрелки: " << -y << ", " << x << "\n";
    }
}

void collinear(Vector point1, Vector point2, Vector common_point) {
    int x1 = point2.x - point1.x;
    int y1 = point2.y - point1.y;
    int x2 = common_point.x - point1.x;
    int y2 = common_point.y - point1.y;

    int check = x1 * y2 - y1 * x2;
    if (check == 0) {
        std::cout << "Точки коллинеарны.\n";
    }
    else {
        std::cout << "Точки не коллинеарны.\n";
    }
}

int main() {
    setlocale(0, "");
    Vector point1;
    Vector point2;
    Vector common_point;

    std::cout << "Введите x 1-й точки: ";
    std::cin >> point1.x;
    std::cout << "Введите y 1-й точки: ";
    std::cin >> point1.y;

    std::cout << "Введите x 2-й точки: ";
    std::cin >> point2.x;
    std::cout << "Введите y 2-й точки: ";
    std::cin >> point2.y;

    std::cout << "Введите x общей точки: ";
    std::cin >> common_point.x;
    std::cout << "Введите y общей точки: ";
    std::cin >> common_point.y;

    std::cout << "\n";
    equal(point1, point2);
    distance(point1, point2);
    angle(point1, point2, common_point);
    normalize(point1);
    rotate90(point1, true);
    rotate90(point1, false);
    collinear(point1, point2, common_point);
}


