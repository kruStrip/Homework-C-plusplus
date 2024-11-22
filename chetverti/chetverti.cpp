#include <iostream>

int main()
{
    setlocale(LC_ALL, "");
    int x;
    int y;
    std::cout << "Введите x: ";
    std::cin >> x;
    std::cout << "Введите y: ";
    std::cin >> y;
    if (x > 0) {
        if (y > 0) {
            std::cout << "Первая четверть";
        }
        else if (y < 0) {
            std::cout << "Четвертая четверть";
        }
        else {
            std::cout << "Первая и четвертая четверть";
        }
    }
    else if (x < 0){
        if (y > 0) {
            std::cout << "Вторая четверть";
        }
        else if (y < 0) {
            std::cout << "Третья четверть";
        }
        else {
            std::cout << "Вторая и третья четверть";
        }
    }
    else {
        if (y > 0) {
            std::cout << "Первая и вторая четверть";
        }
        else if (y < 0) {
            std::cout << "Третья и четвертая четверть";
        }
    }
}
