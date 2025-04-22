#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

//at first, I wanted to get each character of the string, cast it to int, put in a vector and check if vector is sorted, but in the end I decided to just use STL :) 

void in_order(std::string s)
{
    if (std::is_sorted(s.begin(), s.end()))
    {
        std::cout << s << " IN ORDER" << std::endl;
    }
    else if (std::is_sorted(s.rbegin(), s.rend()))
    {
        std::cout << s << " REVERSED ORDER" << std::endl;
    }
    else
    {
        std::cout << s << " NOT IN ORDER" << std::endl;
    }
}

int main()
{
    //tests
    std::vector<std::string> v = { "billowy", "biopsy", "chinos", "defaced", "chintz", "sponged", "bijoux", "abhors", "fiddle", "begins", "chimps", "wronged" };
    
    for (auto it : v)
    {
        in_order(it);
    }
    
    return 0;
}
