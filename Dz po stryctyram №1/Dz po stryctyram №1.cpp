#include <iostream>
#include <vector>
#include <cmath>

void equal(std::vector<int> points1, std::vector<int> points2) {
    if ((points1[0] == points2[0]) && (points1[1] == points2[1])) {
        std::cout<<"Две точки, являются одинаковыми.";
    }
    else {
        std::cout << "Две точки, не являются одинаковыми.";
    }
}

void distance(std::vector<int> points1, std::vector<int> points2) {
    int xs = points2[0] - points1[0];
    xs = pow(xs, 2);
    int ys = points2[1] - points1[1];
    ys = pow(ys, 2);
    int dist = xs + ys;
    dist = sqrt(dist);

    std::cout << "Расстояние между двумя точками: ", dist;
}



int main()
{
    setlocale(0, "");
    std::vector<int> points1 = {};
    std::vector<int> points2 = {};

    std::cout << "Введите координаты 1-й точки(x, y): ";
    std::cin >> points1[0], points1[1];


    std::cout << "Введите координаты 2-й точки(x,y): ";
    std::cin >> points2[0], points2[1];

    equal(points1, points2);

}
