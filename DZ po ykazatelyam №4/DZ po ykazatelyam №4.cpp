#include <iostream>
#include <vector>


int* filter(int arr[], int n, bool(*func)(int, int), int&size) {
    size = 0;
    for (int i = 0; i < 4; i++) {
        if (func(arr[i], n)) {
            size++;
        }
    }
    int* nums = new int[size];
    int ind = 0;
    for (int i = 0; i < 4; i++) {
        if (func(arr[i], n)) {
            nums[ind++] = arr[i];
        }
    }
    return nums;
}

bool not_equal(int a, int b) {
    if (a != b) {
        return true;
    }
    else {
        return false;
    }
}

bool greater(int a, int b) {
    if (a >= b) {
        return true;
    }
    else {
        return false;
    }
}
bool divides(int a, int b) {
    if (a % b == 0) {
        return true;
    }
    else {
        return false;
    }
}

int main()
{
    setlocale(0, "");
    int arr[4] = {};
    for (int i = 0; i < 4; i++) {
        std::cout << "Введите число: ";
        std::cin >> arr[i];
    }
    int size = 0;

    std::cout << "\n";
    // массив без чисел 5
    int* arr2 = filter(arr, 5, not_equal, size);
    std::cout << "Массив без чисел 5: \n";
    for (int i = 0; i < size; i++) {
        std::cout << arr2[i] << " ";
    }
    delete[] arr2;
    std::cout << "\n";

    // массив из положительных чисел
    int* arr3 = filter(arr, 0, greater, size);
    std::cout << "Массив из положительных чисел: \n";
    for (int i = 0; i < size; i++) {
        std::cout << arr3[i] << " ";
    }
    delete[] arr3;
    std::cout << "\n";

    // массив из четных чисел
    std::cout << "Массив из четных чисел: \n";
    int* arr4 = filter(arr, 2, divides, size);
    for (int i = 0; i < size; i++) {
        std::cout << arr4[i] << " ";
    }
    delete[] arr4;
}
