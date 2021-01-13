#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

void showVector(std::vector<int> arr)
{
    for (auto it : arr)
    {
        std::cout << it << " ";
    }
}

bool hh(std::vector<int> arr)
{
    //remove 0s
    arr.erase(std::remove(arr.begin(), arr.end(), 0), arr.end());

    if (arr.empty())
    {
        std::cout << "true" << std::endl;
        return true;
    }
    else
    {
        //descending sort
        std::sort(arr.begin(), arr.end(), std::greater<int>());

        int n = arr.front();
        arr.erase(arr.begin());
        int arrSize = arr.size();

        //length check
        if (n > arrSize)
        {
            std::cout << "false" << std::endl;
            return false;
        }
        else
        {
            //front elimination
            for (int i = 0; i < n; i++)
            {
                arr[i]--;
            }
        }
    }

    hh(arr);
}

int main()
{
    //tests
    std::vector<std::vector<int>> sequences = { { 5, 3, 0, 2, 6, 2, 0, 7, 2, 5 },
                                                { 4, 2, 0, 1, 5, 0 },
                                                { 3, 1, 2, 3, 1, 0 },
                                                { 16, 9, 9, 15, 9, 7, 9, 11, 17, 11, 4, 9, 12, 14, 14, 12, 17, 0, 3, 16 },
                                                { 14, 10, 17, 13, 4, 8, 6, 7, 13, 13, 17, 18, 8, 17, 2, 14, 6, 4, 7, 12 },
                                                { 15, 18, 6, 13, 12, 4, 4, 14, 1, 6, 18, 2, 6, 16, 0, 9, 10, 7, 12, 3 },
                                                { 6, 0, 10, 10, 10, 5, 8, 3, 0, 14, 16, 2, 13, 1, 2, 13, 6, 15, 5, 1 },
                                                { 2, 2, 0 },
                                                { 3, 2, 1 },
                                                { 1, 1 },
                                                { 1 },
                                                {  } };

    for (auto seq : sequences)
    {
        showVector(seq);
        std::cout << " - ";
        hh(seq);
    }
}