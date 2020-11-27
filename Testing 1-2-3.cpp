//Your team is writing a fancy new text editorand you've been tasked with implementing the line numbering.
//
//Write a function which takes a list of strings and returns each line prepended by the correct number.
//
//The numbering starts at 1. The format is n : string.Notice the colon and space in between.
//
//Examples :
//
//	number(List<string>()) // => List<string>()
//	number(List<string>{"a", "b", "c"}) // => ["1: a", "2: b", "3: c"]

#include <string>
#include <vector>

std::vector<std::string> number(const std::vector<std::string>& lines)
{
    std::vector <std::string> out_vec;
    int line_counter = 1;
    for (auto n : lines)
    {
        std::string current_line = std::to_string(line_counter) + ": " + n;
        out_vec.push_back(current_line);
        line_counter++;
    }
    return out_vec;
}