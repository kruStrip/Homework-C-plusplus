#include <iostream>

int main()
{
    setlocale(LC_ALL, "");
    int num;
    std::cout << "Введите число: ";
    std::cin >> num;
    if (num >= 0 && num < 10) {
        std::cout << num;
    }
    else {
        switch (num) {
        case 10:
            std::cout << "A";
            break;
        case 11:
            std::cout << "B";
            break;
        case 12:
            std::cout << "C";
            break;
        case 13:
            std::cout << "D";
            break;
        case 14:
            std::cout << "E";
            break;
        case 15:
            std::cout << "F";
            break;
        default:
            std::cout << num;
        }
    }
}

