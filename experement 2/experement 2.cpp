#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <unordered_set>
#include <ctime>

void vector() {
    std::vector<int> vec;
    for (int i = 0; i < 100000; ++i) {
        vec.push_back(i);
    }

    clock_t start = clock();
    vec.insert(vec.begin(), -1); 
    clock_t end = clock();
    double insertTime = static_cast<double>(end - start) / CLOCKS_PER_SEC;

    start = clock();
    vec.erase(vec.begin()); 
    end = clock();
    double removeTime = static_cast<double>(end - start) / CLOCKS_PER_SEC;

    std::cout << "Время затраченное на добавление элемента в vector: " << insertTime << " сек\n";
    std::cout << "Время затраченное на удаление элемента из vector: " << removeTime << " сек\n\n";
}

void list() {
    std::list<int> lst;
    for (int i = 0; i < 100000; ++i) {
        lst.push_back(i);
    }

    clock_t start = clock();
    lst.push_front(-1); 
    clock_t end = clock();
    double insertTime = static_cast<double>(end - start) / CLOCKS_PER_SEC;

    start = clock();
    lst.pop_front(); 
    end = clock();
    double removeTime = static_cast<double>(end - start) / CLOCKS_PER_SEC;

    std::cout << "Время затраченное на добавление элемента в list: " << insertTime << " сек\n";
    std::cout << "Время затраченное на удаление элемента из list: " << removeTime << " сек\n\n";
}

void set() {
    std::set<int> s;
    for (int i = 0; i < 100000; ++i) {
        s.insert(i);
    }

    clock_t start = clock();
    s.insert(-1); 
    clock_t end = clock();
    double insertTime = static_cast<double>(end - start) / CLOCKS_PER_SEC;

    start = clock();
    s.erase(-1); 
    end = clock();
    double removeTime = static_cast<double>(end - start) / CLOCKS_PER_SEC;

    std::cout << "Время затраченное на добавление элемента в set: " << insertTime << " сек\n";
    std::cout << "Время затраченное на удаление элемента из set: " << removeTime << " сек\n\n";
}

void unorderedSet() {
    std::unordered_set<int> us;
    for (int i = 0; i < 100000; ++i) {
        us.insert(i);
    }

    clock_t start = clock();
    us.insert(-1); 
    clock_t end = clock();
    double insertTime = static_cast<double>(end - start) / CLOCKS_PER_SEC;

    start = clock();
    us.erase(-1); 
    end = clock();
    double removeTime = static_cast<double>(end - start) / CLOCKS_PER_SEC;

    std::cout << "Время затраченное на добавление элемента в unorderedSet: " << insertTime << " сек\n";
    std::cout << "Время затраченное на удаление элемента из unorderedSet: " << removeTime << " сек\n\n";
}

int main() {
    setlocale(0, "");
    vector();
    list();
    set();
    unorderedSet();
}
