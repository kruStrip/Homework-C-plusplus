#include <iostream>

double integralchik(int a, int b,  double h) {
    double x;
    double integral = 0;
    double f1;
    double f2;
    for (int i = a; i <= b; i++) {
        x = -0.5 + i * h;
        f1 = -0.5 * x * x + 6 * x - 10;
        x = x + h;
        f2 = -0.5 * x * x + 6 * x - 10;
        integral += (f2 + f1) / 2;
    }
    integral *= h;
    return integral;
}

int main()
{
    setlocale(LC_ALL, "");
    double h;
    std::cout << "Введите h: ";
    std::cin >> h;
    int a = 2;
    int b = 10;
    double res = integralchik(a, b, h);
    std::cout << "Интеграл на промежутке [2;10] равен: " << res;
}
