#include <iostream>
#include <vector>
#include <cmath>

void equal(std::vector<int> points1, std::vector<int> points2) {
    if ((points1[0] == points2[0]) && (points1[1] == points2[1])) {
        std::cout << "Две точки являются одинаковыми.\n";
    }
    else {
        std::cout << "Две точки не являются одинаковыми.\n";
    }
}

void distance(std::vector<int> points1, std::vector<int> points2) {
    double xs = points2[0] - points1[0];
    xs = pow(xs, 2);
    double ys = points2[1] - points1[1];
    ys = pow(ys, 2);
    double dist = sqrt(xs + ys);

    std::cout << "Расстояние между двумя точками: " << dist << std::endl;
}

void angle(std::vector<int> points1, std::vector<int> points2, std::vector<int> common) {
    double x1 = points2[0] - points1[0];
    double y1 = points2[1] - points1[1];
    double x2 = common[0] - points1[0];
    double y2 = common[1] - points1[1];

    double scal = x1 * x2 + y1 * y2;
    double dlina1 = sqrt(x1 * x1 + y1 * y1);
    double dlina2 = sqrt(x2 * x2 + y2 * y2);
    double cos = scal / (dlina1 * dlina2);

    double ygol = acos(cos) * 180 / 3.14;
    std::cout << "Угол между векторами: " << ygol << " градусов.\n";
}

void normalize(std::vector<int> point) {
    double vel = sqrt(point[0] * point[0] + point[1] * point[1]);
    std::vector<double> normal = { point[0] / vel, point[1] / vel };

    std::cout << "Нормализованный вектор: " << normal[0] << ", " << normal[1] << "\n";
}

void rotate90(std::vector<int> point, bool napr) {
    int x = point[0];
    int y = point[1];

    if (napr) {
        std::cout << "Вектор после поворота на 90 градусов по часовой стрелке: " << y << ", " << -x << "\n";
    }
    else {
        std::cout << "Вектор после поворота на 90 градусов против часовой стрелки: " << -y << ", " << x << "\n";
    }
}

void collinear(std::vector<int> points1, std::vector<int> points2, std::vector<int> common) {
    int x1 = points2[0] - points1[0];
    int y1 = points2[1] - points1[1];
    int x2 = common[0] - points1[0];
    int y2 = common[1] - points1[1];

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
    std::vector<int> points1(2);
    std::vector<int> points2(2);
    std::vector<int> common(2);

    std::cout << "Введите x 1-й точки: ";
    std::cin >> points1[0];
    std::cout << "Введите y 1-й точки: ";
    std::cin >> points1[1];

    std::cout << "Введите x 2-й точки: ";
    std::cin >> points2[0];
    std::cout << "Введите y 2-й точки: ";
    std::cin >> points2[1];

    std::cout << "Введите x общей точки: ";
    std::cin >> common[0];
    std::cout << "Введите y общей точки: ";
    std::cin >> common[1];

    std::cout << "\n";
    equal(points1, points2);
    distance(points1, points2);
    angle(points1, points2, common);
    normalize(points1);
    rotate90(points1, true);
    rotate90(points1, false);
    collinear(points1, points2, common);
}

