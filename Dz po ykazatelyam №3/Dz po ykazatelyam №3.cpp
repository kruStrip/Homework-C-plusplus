#include <iostream>
#include <cmath>
#include <vector>

std::vector<double> roots(double (*func)(double), double a, double b, double step) {
    std::vector<double> res = {};
    double X = a;
    double Y = func(X);

    for (double x = a + step; x <= b; x += step) {
        double y = func(x);

        if ((Y > 0 && y < 0) || (Y < 0 && y > 0)) {
            double root = (X + x) / 2.0;
            res.push_back(root);
        }

        X = x;
        Y = y;
    }

    return res;
}

double gen_func(double x) {
    return 0.2 * x * sin(x) - 1.0 / x;
}

int main() {
    setlocale(0, "");
    double a = 4, b = 13;
    double step = 0.001;

    std::vector<double> korni = roots(gen_func, a, b, step);

    std::cout << "Корни функции:" << std::endl;
    for (double root : korni) {
        std::cout << root << std::endl;
    }

    return 0;
}