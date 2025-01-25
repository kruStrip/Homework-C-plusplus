#include <iostream>
#include <string>
#include <list>

std::string operator/(const std::string& left, const std::string& right) {

    if (left.back() == '/' && right.front() == '/')
        return left + right.substr(1);
    else if (left.back() != '/' && right.front() != '/')
        return left + '/' + right;
    else
        return left + right;
}

void print_list(const std::list<double>& lst) {
    std::cout << "[";
    for (auto it = lst.begin(); it != lst.end(); ++it) {
        std::cout << *it;
        if (std::next(it) != lst.end()) {
            std::cout << ", ";
        }
    }
    std::cout << "]\n";
}

struct Fraction {
    int numerator;
    int denominator;

    Fraction(int num, int denom) {
        if (denominator == 0) {
            std::cout<<("Знаменатель не может быть равен нулю");
        }
        else {
            numerator = num;
            denominator = denom;
        }
    }

    operator double() {
        return static_cast<double>(numerator) / denominator;
    }
};

long double operator"" _oz(long double ounces) {
    return ounces * 28.41;
}

int main() {
    setlocale(0, "");
    std::string path1 = "C:";
    std::string path2 = "Users";
    std::string path3 = "Descktop";

    std::string fullPath = path1 / path2 / path3;
    std::cout << "Путь: " << fullPath << std::endl;

    std::list<double> nums = { 1.0, 3.5, -2.2, 4.0 };
    print_list(nums);

    Fraction fraction(3, 4);
    double result = fraction;
    std::cout << "Перевод в double: " << result << std::endl;

    long double ml = 3.5_oz;
    std::cout << "3.5 унции в мл: " << ml <<std::endl;
}
