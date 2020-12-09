//# Task:
//Complete the pattern, using the special character ■ □
//In this kata, we draw some histogram of the sound performance of upsand downs.
//# Rules :
//    parameter waves The value of sound waves, an array of number, all number in array >= 0.
//    return a string, ■ represents the sound waves, and □ represents the blank part, draw the histogram from bottom to top.
//    # Example :
//    draw([1, 2, 3, 4])
//
//    □□□■
//    □□■■
//    □■■■
//    ■■■■
//
//    draw([1, 2, 3, 3, 2, 1])
//
//    □□■■□□
//    □■■■■□
//    ■■■■■■
//
//    draw([1, 2, 3, 3, 2, 1, 1, 2, 3, 4, 5, 6, 7])
//
//    □□□□□□□□□□□□■
//    □□□□□□□□□□□■■
//    □□□□□□□□□□■■■
//    □□□□□□□□□■■■■
//    □□■■□□□□■■■■■
//    □■■■■□□■■■■■■
//    ■■■■■■■■■■■■■
//
//
//    draw([5, 3, 1, 2, 4, 6, 5, 4, 2, 3, 5, 2, 1])
//
//    □□□□□■□□□□□□□
//    ■□□□□■■□□□■□□
//    ■□□□■■■■□□■□□
//    ■■□□■■■■□■■□□
//    ■■□■■■■■■■■■□
//    ■■■■■■■■■■■■■
//
//    draw([1, 0, 1, 0, 1, 0, 1, 0])
//
//    ■□■□■□■□

#include <string>
#include <vector>
#include <algorithm>

std::string draw(std::vector<int> waves)
{
    std::string out_string;
    int max_val = *std::max_element(waves.begin(), waves.end());
    for (int i = max_val; i > 0; i--)
    {
        for (auto n : waves)
        {
            if (n >= i) 
                out_string+="■";
            else
                out_string+="□";
        }
        out_string.push_back('\n');
    }
    out_string.pop_back();
    return out_string;
}