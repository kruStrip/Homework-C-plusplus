#include <iostream>

double raschet(double num) {
    double x = num / 2;
    for (int i = 0;i < 100;i++) {
        x = 0.5 * (x + num / x);
    }
    return x;
}

int main()
{
    setlocale(0, "");
    double num;
    std::cout << "Введите число: ";
    std::cin >> num;
    std::cout << "Квадратный корень, числа " << num << " равен " << raschet(num);
}