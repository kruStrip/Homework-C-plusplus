#include <iostream>
#include <string>

char* left(char str[], int n) {
    char* s = new char[n+1];
    for (int i = 0; i < n; i++) {
        s[i] = str[i];
    }
    s[n] = '\0';
    return s;
}

char* right(char str[], int n) {
    char* s = new char[n + 1];
    int len = strlen(str);
    for (int i = 0; i < n; i++) {
        s[i] = str[len-n+i];
    }
    s[n] = '\0';
    return s;
}

int main()
{
    setlocale(0, "");
    char str[] = "nitroglycerin";

    char* str2 = left(str, 5);
    std::cout << "Первые 5 символов: \n";
    std::cout << str2 << std::endl;
    delete[] str2;

    char* str3 = right(str, 8);
    std::cout << "Последние 8 символов: \n";
    std::cout << str3;
    delete[] str3;
}
