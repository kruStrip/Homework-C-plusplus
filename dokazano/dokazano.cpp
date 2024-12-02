#include <iostream>

void sum_progress(double q, double b_0) {
    double sum = b_0;
    double check = b_0 / (1 - q);
    for (int i = 1; i < 150; i++) {
        b_0 = b_0 * q;
        sum += b_0;
    }
    if (sum <= check) {
        std::cout << "Сумма г.прогресси при n = 150, равна " << sum << " и стремится к " << check << " /чтд";
  }
    else {
        std::cout << "Теорема лжива";
    }
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
    sum_progress(q, b_0);
}