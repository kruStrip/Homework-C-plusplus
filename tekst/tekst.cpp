#include <iostream>

int count(const char text[]) {
    int c = 0;
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?' || text[i] == '...') {
            c++;
        }
    }
    return c;
}

int main()
{
    setlocale(LC_ALL, "");
    const char text[] = "The other three old people nodded their heads slowly up and down, "
        "and said ‘Absolutely true, Just as true as can be’. "
        "And Grandpa Joe said\n"
        "- You mean to say I’ve never told you about Mr Willy Wonka and his factory?\n"
        "- Never — answered little Charlie.\n"
        "- Good heavens above! I don’t know what’s the matter with me!";

    std::cout << "Кол-во предложений: " << count(text);
}
