#include <iostream>

int  sum_progress(int q, int b_0, int n) {
    int sum = b_0;
    for (int i = 1; i < n; i++) {
        b_0 = b_0 * q;
        sum += b_0;
    }
    return sum;
}

int main()
{
    setlocale(LC_ALL, "");
    int n;
    int q;
    int b_0;
    std::cout << "Введите q: ";
    std::cin >> q;
    std::cout << "Введите b0: ";
    std::cin >> b_0;
    std::cout << "Введите n: ";
    std::cin >> n;

    std::cout << sum_progress(q, b_0, n);
}

