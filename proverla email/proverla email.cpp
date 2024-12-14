#include <iostream>
#include <string>

bool check(std::string email) {
    int c_sobak = 0;
    int c_tochka = 0;
    for (int i = 0; i <= email.size(); i++) {
        if (email[i] == '@') {
            c_sobak += 1;
        }
        else if ((email[i] == '.') && (c_sobak > 0)) {
            c_tochka += 1;
        }
    }
    if ((c_sobak == 1) && (c_tochka == 1)) {
        return true;
    }
    else {
        return false;
    }
}

int main()
{
    setlocale(0, "");
    std::string email;
    std::cout << "Введите email: ";
    std::cin >> email;
    if (check(email)) {
        std::cout << "Верный email!";
    }
    else {
        std::cout << "Неверный email!";
    }
}

