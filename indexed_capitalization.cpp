//Given a stringand an array of integers representing indices, capitalize all letters at the given indices.
//
//For example :
//
//capitalize("abcdef", [1, 2, 5]) = "aBCdeF"
//capitalize("abcdef", [1, 2, 5, 100]) = "aBCdeF".There is no index 100.
//The input will be a lowercase string with no spaces and an array of digits.
#include <string>
#include <vector>

std::string capitalize(std::string s, std::vector<int> idxs)
{
    for (auto n : idxs)
    {
        if ((n >= 0) && (n < s.size()))
        {
            s[n]=toupper(s[n]);
        }
    }
    return s;
}