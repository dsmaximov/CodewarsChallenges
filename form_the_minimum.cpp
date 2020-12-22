//Task
//Given a list of digits, return the smallest number that could be formed from these digits, using the digits only once(ignore duplicates).

#include <vector>

unsigned long long minValue(std::vector <int> values)
{
    unsigned long long out_value = 0;
    bool map[10] = {false};
    int product = 1;
    for (int n : values)
    {
        map[n] = true;
    }
    for (int i = 9; i >= 0; i--)
    {
        if (map[i])
        {
            out_value += i * product;
            product *= 10;
        }
    }
    return out_value;
}