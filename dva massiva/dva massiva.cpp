#include <iostream>

int summ_glavnya(int nums[4][4]) {
    int sum = 0;
    for (int i = 0; i < 4; i++) {
        for (int g = 0; g < 4; g++) {
            if (i == g) {
                sum += nums[i][g];
            }
        }
    }
    return sum;
}

int summ_poboch(int nums[4][4]) {
    int sum = 0;
    for (int i = 3; i >= 0; i--) {
        sum += nums[i][3 - i];
    }
    return sum;
}

int main()
{
    setlocale(LC_ALL, "");
    int nums[4][4] = { {1,2,3,4}, {5,6,7,8}, {1,2,3,4}, {5,6,7,8} };
    std::cout << "Массив:\n";
    for (int i = 0; i < 4; i++) {
        for (int g = 0; g < 4; g++) {
            std::cout << nums[i][g]<< " ";
        }
        std::cout << "\n";
    }

    std::cout << "\nСумма элементов на главной диагонали: " << summ_glavnya(nums);
    std::cout << "\nСумма элементов на побочной диагонали: " << summ_poboch(nums);

}

