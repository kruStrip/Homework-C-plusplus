#include <iostream>
#include <cmath>

double raschet(double num, double k) {
    double x = num / k;
    for (int i = 0;i < 100;i++) {
        x = 0.5 * (x + num / pow(x, k-1));
    }
    return x;
}

int main()
{
    setlocale(0, "");
    double num;
    int k;
    std::cout << "Введите число: ";
    std::cin >> num;
    std::cout << "Введите степень: ";
    std::cin >> k;
    if (k < 2) {
        std::cout << "Основание должно быть >=2";
    }
    std::cout << "Квадратный корень, числа " << num <<" и степени "<< k << " равен " << raschet(num, k);
}
