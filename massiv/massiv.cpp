#include <iostream>

double res_avg(int nums[]) {
    double avg = 0;
    for (int i = 0; i < 12; i++) {
        avg += nums[i];
    }
    avg /= 12;
    return avg;
}
double sredn(int nums[]) {
    double max = nums[1];
    double min = nums[1];
    for (int i = 0; i < 12; i++) {
        if (nums[i] > max) {
            max = nums[i];
        }
        else if (nums[i] < min) {
            min = nums[i];
        }
    }
    return (max + min) / 2;
}

void median(int nums[], int size) {
    int ord;
    int count = 12;
    while (count != 0) {
        for (int i = 0; i < 11; i++) {
            if (nums[i] > nums[i+1]) {
                ord = nums[i];
                nums[i] = nums[i + 1];
                nums[i + 1] = ord;
            }
        }
        count--;
    }
    if (size % 2 == 0) {
        int m1 = nums[size / 2 - 1];
        int m2 = nums[size / 2];
        std::cout << "Медиана: " << m1 << " и " << m2 << "\n";
    }
    else {
        int med = nums[size / 2];
        std::cout << "Медиана: " << med << "\n";
    }

    std::cout << "Левая часть: ";
    for (int i = 0; i < ((size / 2)-1); i++) {
        std::cout << nums[i] << " ";
    }

    std::cout << "\nПравая часть: ";
    for (int i = ((size / 2)+1); i < size; i++) {
        std::cout << nums[i] << " ";
    }
    std::cout << "\n";
}


int moda(int nums[]) {
    int count[12] = {};
    int modniy = 0;
    for (int i = 0; i < 12; i++) {
        for (int g = 0; g < 12; g++) {
            if (nums[i] == nums[g]) {
                count[i] +=1;
            }
        }
    }
    for (int i = 0; i < 12; i++) {
        if (count[i] > modniy) {
            modniy = nums[i];
        }
    }
    return modniy;
}

int main()
{
    setlocale(LC_ALL, "");
    int nums[12] = { 1, -1, 5, 2, 4, 2, 1, 3, 2, 7, -6, 9 };
    int size = 12;

    std::cout << "Среднее арифметическое: " << res_avg(nums) << "\n";
    std::cout << "Среднее: " << sredn(nums) << "\n";
    median(nums, size);
    std::cout << "Мода: " << moda(nums) << "\n";
}

