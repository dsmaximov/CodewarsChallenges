//In this Kata, you will be given a string that may have mixed uppercaseand lowercase lettersand your task is to convert that string to either lowercase only or uppercase only based on :
//
//make as few changes as possible.
//if the string contains equal number of uppercaseand lowercase letters, convert the string to lowercase.
//For example :
//
//solve("coDe") = "code".Lowercase characters > uppercase.Change only the "D" to lowercase.
//solve("CODe") = "CODE".Uppercase characters > lowecase.Change only the "e" to uppercase.
//solve("coDE") = "code".Upper == lowercase.Change all to lowercase.

#include <string>

std::string fix_string_case(const std::string& str) {
    std::string out_str;
    uint32_t lo = 0;
    uint32_t up = 0;
    for (char n : str)
    {
        if (isupper(n))
            up++;
        else
            lo++;
    }
    if (up > lo)
        for (char n : str)
            out_str.push_back(toupper(n));
    else
        for (char n : str)
            out_str.push_back(tolower(n));
    return out_str;
}