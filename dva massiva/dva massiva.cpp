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

int razni(int nums_pryam[3][6]) {
    int sum_chet = 0;
    int sum_nechet = 0;
    for (int i = 0; i < 3; i++) {
        for (int g = 0; g < 4; g++) {
            if ((i + g) % 2 == 0) {
                sum_chet += nums_pryam[i][g];
            }
            else {
                sum_chet += nums_pryam[i][g];
            }
        }
    }
    return sum_chet - sum_nechet;
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

    int nums_pryam[3][6] = { {1,2,3,4,5,6}, {5,6,7,8,9,0}, {1,2,3,4, 5,6} };
    std::cout << "\nПрямоугольный массив:\n";
    for (int i = 0; i < 3; i++) {
        for (int g = 0; g < 6; g++) {
            std::cout << nums_pryam[i][g] << " ";
        }
        std::cout << "\n";
    }

    std::cout << "\nРазница суммы элементов в четной ячейке и суммы элементов в нечетной ячейке: " << razni(nums_pryam);
}

