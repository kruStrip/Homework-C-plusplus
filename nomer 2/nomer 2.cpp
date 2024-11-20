#include <iostream>
#include <cmath>

int main()
{
    setlocale(LC_ALL, "");
    double h;
    double r;
    const double p = 3.141592;
    std::cout << "Введите высоту: ";
    std::cin >> h;
    std::cout << "Введите радиус: ";
    std::cin >> r;
    double v = p*pow(r,2)*h;
    double s = 2 * p * pow(r, 2) + 2 * p * r * h;
    std::cout << "Объем кружки: " << v<<std::endl;
    std::cout << "Площадь поверхности: " << s;
}

