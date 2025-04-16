#include <iostream>
#include <climits>
#include <vector> 
#include <algorithm>

int drop_cache(int phones, int floors, std::vector<std::vector<int>>& cache)
{
    //base cases
    if (phones == 0)
    {
        return 0;
    }
    
    if (floors == 0 || floors == 1)
    {
        return floors;
    }
    
    if (phones == 1)
    {
        return floors;
    }

    //check if result already exists in "cache table", return if it does and don't calculate further
    if (cache[phones][floors] != -1)
    {
        return cache[phones][floors];
    }
  
    int min_drops = INT_MAX;    //initialize minimum number of drops to be as high as possible, so it can be updated later when comparing with breaks/survives

    //calculate for each floor
    for (int i = 1; i <= floors; i++)
    {
        int breaks = drop_cache(phones - 1, i - 1, cache);
        int survives = drop_cache(phones, floors - i, cache);

        //worst case for the current floor
        min_drops = std::min(min_drops, 1 + ((breaks > survives) ? breaks : survives));    //inline calculation of minimum number of drops by comparing them to the current drop + max of breaks/survives
    }

    //store the result and return it
    cache[phones][floors] = min_drops;
    
    return min_drops;
}

int drop(int phones, int floors)
{
    //"cache table" 
    std::vector<std::vector<int>> cache(phones + 1, std::vector<int>(floors + 1, -1));
    
    return drop_cache(phones, floors, cache);
}

int main()
{
    //tests
    std::cout << drop(1, 100) << std::endl;
    std::cout << drop(2, 100) << std::endl;
    std::cout << drop(3, 100) << std::endl;
    std::cout << drop(1, 1) << std::endl;
    std::cout << drop(2, 456) << std::endl;
    std::cout << drop(3, 456) << std::endl;
    std::cout << drop(4, 456) << std::endl;
    std::cout << drop(2, 789) << std::endl;
    std::cout << drop(3, 789) << std::endl;
    std::cout << drop(4, 789) << std::endl;

    return 0;
}
