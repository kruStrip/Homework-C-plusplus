#include <iostream>

void opredelenie(char* preob) {
    if (preob[0] == 0x00) {
        std::cout << "Порядок следования байт: big-endian";
    }
    else if (preob[1] == 0x00) {
        std::cout << "Порядок следования байт: little-endian";
    }
}

int main()
{
    setlocale(0, "");
    short int num = 0xFF00;
    char* preob = (char*)&num;
    opredelenie(preob);
}
