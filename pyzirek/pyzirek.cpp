#include <iostream>

void sortirovka(int nums[], char znak, int size) {
    int ord;
    if (znak == '>') {
        while (size != 0) {
            for (int i = 0; i < 11; i++) {
                if (nums[i] < nums[i + 1]) {
                    ord = nums[i];
                    nums[i] = nums[i + 1];
                    nums[i + 1] = ord;
                }
            }
            size--;
        }
    }
    else if (znak == '<') {
        while (size != 0) {
            for (int i = 0; i < 11; i++) {
                if (nums[i] > nums[i + 1]) {
                    ord = nums[i];
                    nums[i] = nums[i + 1];
                    nums[i + 1] = ord;
                }
            }
            size--;
        }
    }
    else {
        std::cout << "Нужно ввести: < или >";
        return;
    }
    for (int i = 0; i < 12; i++) {
        std::cout << nums[i] << " ";
    }
}

int main()
{
    setlocale(LC_ALL, "");
    int nums[12] = { 1, -1, 5, 2, 4, 2, 1, 3, 2, 7, -6, 9 };
    int size = 12;
    char znak;

    std::cout << "Массив: ";
    for (int i = 0; i < 12;i++) {
        std::cout << nums[i] << " ";
    }
    std::cout << "\nКак выполняется сортировка? От меньшего к большему (знак меньше <), или по убыванию, то есть от большего к меньшему (знак больше >): ";
    std::cin >> znak;
    sortirovka(nums, znak, size);
}

