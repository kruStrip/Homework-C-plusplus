#include <iostream>

void sochet(int k, int n) {
    int res = 1;
    for (int i = 1; i <= k; i++) {
        res = res * (n - k + i) / i;
    }
    std::cout << "Кол-во сочетаний: "<< res;
}

int main()
{
    setlocale(LC_ALL, "");
    int k;
    int n;
    std::cout << "Введите k: ";
    std::cin >> k;
    std::cout << "Введите n: ";
    std::cin >> n;
    sochet(k, n);
}
