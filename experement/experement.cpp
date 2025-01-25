#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <unordered_set>
#include <ctime>

void vector() {
    std::vector<int> vec(100000);
    for (int i = 0; i < 100000; ++i) {
        vec[i] = i;
    }

    clock_t start = clock();
    for (int i = 0; i < 10000; ++i) {
        int value = vec[50000];
    }
    clock_t end = clock();
    double time = static_cast<double>(end - start) / CLOCKS_PER_SEC;
    std::cout << "Время нахождения элемента: " << time << " сек\n";
}

void list() {
    std::list<int> lst;
    for (int i = 0; i < 100000; ++i) {
        lst.push_back(i);
    }

    clock_t start = clock();
    for (int i = 0; i < 10000; ++i) {
        auto it = std::next(lst.begin(), 50000); 
        int value = *it;
    }
    clock_t end = clock();
    double time = static_cast<double>(end - start) / CLOCKS_PER_SEC;
    std::cout << "Время нахождения элемента: " << time << " сек\n";
}

void set() {
    std::set<int> s;
    for (int i = 0; i < 100000; ++i) {
        s.insert(i);
    }

    clock_t start = clock();
    for (int i = 0; i < 10000; ++i) {
        auto it = s.find(50000); 
        int value = *it;
    }
    clock_t end = clock();
    double time = static_cast<double>(end - start) / CLOCKS_PER_SEC;
    std::cout << "Время нахождения элемента: " << time << " сек\n";
}

void unorderedSet() {
    std::unordered_set<int> us;
    for (int i = 0; i < 100000; ++i) {
        us.insert(i);
    }

    clock_t start = clock();
    for (int i = 0; i < 10000; ++i) {
        auto it = us.find(50000);
        int value = *it;
    }
    clock_t end = clock();
    double time = static_cast<double>(end - start) / CLOCKS_PER_SEC;
    std::cout << "Время нахождения элемента: " << time << " сек\n";
}

int main() {
    setlocale(0, "");
    vector();
    list();
    set();
    unorderedSet();
}
