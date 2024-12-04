#include <iostream>
#include <cmath>

double log_r(double x) {
    double e = (x - 1) / (x + 1);
    double l = 0;
    int stepen;
    for (int n = 0; n <= 50; n++) {
        stepen = 2 * n + 1;
        l += pow(e, stepen) / stepen;
    }
    return l * 2;
}

int main()
{
    setlocale(LC_ALL, "");
    double nums[] = { 2, 5, 10, 2.718281828 };
    double res;
    double calc;

    double error;
    for (int i = 0; i < 4; i++) {
        res = log_r(nums[i]);
        calc = log(nums[i]);
        error = calc - res;
        std::cout << "Логарифм от " << nums[i] << " полученный по формуле равен: " << res << "\n";
        std::cout << "Логарифм от " << nums[i] << " полученный по калькулятору: " << calc << "\n";
        std::cout << "Погрешность: " << error << "\n\n";
    }
}