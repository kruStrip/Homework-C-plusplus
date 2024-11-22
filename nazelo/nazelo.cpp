#include <iostream>

bool check(int a, int m) {
    if (a % m == 0) {
        return true;
    }
    return false;
}

int main()
{
    setlocale(LC_ALL, "");
    int a;
    int m;
    std::cout << "Введите число а: ";
    std::cin >> a;
    std::cout << "Введите число m: ";
    std::cin >> m;
    if (check(a, m)) {
        std::cout << "Делится";
    }
    else {
        std::cout << "Не делится";
    }
}
