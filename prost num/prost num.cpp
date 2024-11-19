#include <iostream>
#include <vector>

std::vector<int> prost(std :: vector<int> nums, int p) {
    int h = p;
        for (int g = 0; g < nums.size(); g++) {
            if ((nums[g]>p)&&(nums[g] % p == 0)) {
                nums[g] = 0;
            }
        }
        for (int g = 0; g < nums.size(); g++) {
            if (nums[g] > p) {
                p = nums[g];
                break;
            }
        }
        if (h == p) {
            return nums;
        }
        else {
            return prost(nums, p);
        }
 }

bool answ(std::vector<int> nums, int a) {
    for (int i = 0; i < nums.size();i++) {
        if (nums[i] == a) {
            return true;
        }
    }
    return false;
}

int main()
{
    setlocale(LC_ALL, "");
    const int N = 50;
    int a;
    int p = 2;
    std::vector<int> nums = {};
    for (int i = 0; i < N-2; i++) {
        nums[i] = i+2;
    }
    std::cout << "Введите число: ";
    std::cin >> a;
    std::vector<int> res = prost(nums, p);
    std::cout << answ(res, a);
}

