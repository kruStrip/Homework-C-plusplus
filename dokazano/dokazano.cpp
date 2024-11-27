#include <iostream>

double sum_progress(double q, double b_0, int n) {
    double sum = b_0;
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
    double q;
    double b_0;
    std::cout << "Введите q: ";
    std::cin >> q;
    std::cout << "Введите b0: ";
    std::cin >> b_0;
    std::cout << "Введите n: ";
    std::cin >> n;

    std::cout << sum_progress(q, b_0, n);
}