#include <iostream>

struct String {
    char* str;
    size_t size;

    String(const char* inp) {
        size = 0;
        while (inp[size] != '\0') {
            ++size;
        }
        str = new char[size + 1];
        for (size_t i = 0; i < size; ++i) {
            str[i] = inp[i];
        }
        str[size] = '\0';
    }

    ~String() {
        delete[] str;
        str = nullptr;
    }

    void append(const char* inp) {
        size_t newSize = 0;
        while (inp[newSize] != '\0') {
            ++newSize;
        }

        char* newData = new char[size + newSize + 1];
        for (size_t i = 0; i < size; ++i) {
            newData[i] = str[i];
        }
        for (size_t i = 0; i < newSize; ++i) {
            newData[size + i] = inp[i];
        }
        newData[size + newSize] = '\0';

        delete[] str;
        str = newData;
        size += newSize;
    }

    void prepend(const char* inp) {
        size_t newSize = 0;
        while (inp[newSize] != '\0') {
            ++newSize;
        }

        char* newData = new char[size + newSize + 1];
        for (size_t i = 0; i < newSize; ++i) {
            newData[i] = inp[i];
        }
        for (size_t i = 0; i < size; ++i) {
            newData[newSize + i] = str[i];
        }
        newData[size + newSize] = '\0';

        delete[] str;
        str = newData;
        size += newSize;
    }

    char at(size_t ind) {
        if (ind >= size) {
            std::cout<<"Ошибка";
            return 0;
        }
        return str[ind];
    }

    String substring(size_t start, size_t len) {
        if (start >= size || start + len > size) {
            std::cout << "Ошибка";
            return 0;
        }
        char* subStr = new char[len + 1];
        for (size_t i = 0; i < len; ++i) {
            subStr[i] = str[start + i];
        }
        subStr[len] = '\0';
        return String(subStr);
    }

    int first(char ch) {
        for (size_t i = 0; i < size; ++i) {
            if (str[i] == ch) {
                return i;
            }
        }
        return -1;
    }

    int last(char ch) {
        for (int i = size - 1; i >= 0; --i) {
            if (str[i] == ch) {
                return i;
            }
        }
        return -1;
    }

    void split(char delim) const {
        std::cout << "Разделённые строки:\n";
        size_t start = 0;
        for (size_t i = 0; i <= size; ++i) {
            if (str[i] == delim || str[i] == '\0') {
                for (size_t j = start; j < i; ++j) {
                    std::cout << str[j];
                }
                std::cout << '\n';
                start = i + 1;
            }
        }
    }

    void replace(const char* oldStr, const char* newStr) {
        size_t oldLen = 0;
        while (oldStr[oldLen] != '\0') {
            ++oldLen;
        }

        size_t newLen = 0;
        while (newStr[newLen] != '\0') {
            ++newLen;
        }

        for (size_t i = 0; i <= size - oldLen; ++i) {
            bool flag = true;
            for (size_t j = 0; j < oldLen; ++j) {
                if (str[i + j] != oldStr[j]) {
                    flag = false;
                    break;
                }
            }

            if (flag) {
                char* newStr = new char[size - oldLen + newLen + 1];
                for (size_t k = 0; k < i; ++k) {
                    newStr[k] = str[k];
                }
                for (size_t k = 0; k < newLen; ++k) {
                    newStr[i + k] = newStr[k];
                }
                for (size_t k = i + oldLen; k < size; ++k) {
                    newStr[k - oldLen + newLen] = str[k];
                }
                newStr[size - oldLen + newLen] = '\0';

                delete[] str;
                str = newStr;
                size = size - oldLen + newLen;
                i += newLen - 1;
            }
        }
    }
};

int main() {
    setlocale(0, "");
    String a("Hello");
    std::cout << "Строка: " << a.str << "\n";

    a.append(" World!");
    std::cout << "После append: " << a.str << "\n";

    a.prepend("meow ");
    std::cout << "После prepend: " << a.str << "\n";

    std::cout << "Символ на позиции 2: " << a.at(2) << "\n";

    String sub = a.substring(4, 5);
    std::cout << "Подстрока: " << sub.str << "\n";

    std::cout << "Первое вхождение 'l': " << a.first('l') << "\n";
    std::cout << "Последнее вхождение 'l': " << a.last('l') << "\n";

    std::cout << "Split по пробелу\n";
    a.split(' ');

    a.replace("World", "meow");
    std::cout << "После replace: " << a.str << "\n";
}


