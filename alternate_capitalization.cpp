//Given a string, capitalize the letters that occupy even indexesand odd indexes separately, and return as shown below.Index 0 will be considered even.
//
//For example, capitalize("abcdef") = ['AbCdEf', 'aBcDeF'].See test cases for more examples.
//
//The input will be a lowercase string with no spaces.

#include <string>
#include <utility>

std::pair<std::string, std::string> capitalize(const std::string& s)
{
    std::string out1, out2;
    for (unsigned long i = 0; i < s.size(); i++)
    {
        if (i % 2)
        {
            out1.push_back(s[i]);
            out2.push_back(toupper(s[i]));
        }
        else
        {
            out2.push_back(s[i]);
            out1.push_back(toupper(s[i]));
        }
    }
    return { out1, out2 };
}