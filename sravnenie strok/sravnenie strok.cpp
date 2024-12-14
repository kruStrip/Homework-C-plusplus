#include <iostream>
#include <string>

bool check(std::string str1, std::string str2) {

    if (str1.size() != str2.size()) {
        return false;
    }

    for (int i = 0; i < str1.size(); i++) {
        if (str1[i] != str2[i]) {
            return false;
        }
    }
}

int main()
{
    setlocale(0, "");
    std::string str1;
    std::string str2;
    std::cout << "Введите превое слово: ";
    std::cin >> str1;
    std::cout << "Введите второе слово: ";
    std::cin >> str2;

    if (check(str1, str2)) {
        std::cout << "Строки совпадают!";
    }
    else {
        std::cout << "Строки не совпадают!";
    }
}