#include <iostream>
#include <string>
#include <ctype.h>

void warmup(char c, int i)
{
    int i1 = (int)c;
    i1 += i;

    if (std::isupper(c) != 0)
    {
        if (i1 > 90)
        {
            i1 -= 26;
            std::cout << (char)i1;
        }
    }

    if (i1 > 122)
    {
        i1 -= 26;
        std::cout << (char)i1;
    }
    else
    {
        std::cout << (char)i1;
    }
}

void caesar(std::string s, int step)
{
    for (char c : s)
    {
        if (std::isalpha(c) != 0)
        {
            warmup(c, step);
        }
        else
        {
            std::cout << c;
        }
    }
    std::cout << std::endl;
}

int main()
{
    caesar("a", 1); 
    caesar("abcz", 1); 
    caesar("irk", 13); 
    caesar("fusion", 6); 
    caesar("dailyprogrammer", 6);
    caesar("jgorevxumxgsskx", 20); 
    caesar("Daily Programmer!", 6); 
}
