//Build a simple algorithm that corrects the missing full - stops and capitalisation in the given string.
//
//For every captial letter, assume the need to place a fullstop at the end of the sentence before the current one.
//
//For every full - stops, there shall be only one whitespace to the next sentence.
//
//Each first letter of every sentance must be capitalised.
//
//Every word will be spaced but might be more than once.
//
//Trailling and leading spaces to be removed.
//
//Example:
//
//correct_it("John have   an apple The sky is blue.  they get a coin")
//= > return "John have an apple. The sky is blue. They get a coin."

#include <string>

std::string correct_it(std::string str) {
	std::string out_str;
	bool cap_flag = false;
	for (auto it = str.begin(); it != str.end(); it++)
	{
		if (*it == ' ')
		{
			if (out_str.size() == 0)
				continue;
			else if (*out_str.rbegin() == ' ')
				continue;
			else if (it == str.end() - 1)
				continue;
			else
				out_str.push_back(' ');
		}
		if (*it == '.')
		{
			if (*out_str.rbegin() == ' ')
			{
				out_str.pop_back();
			}
			out_str.push_back('.');
			cap_flag = true;
		}
		if (islower(*it))
		{
			if (cap_flag)
			{
				out_str.push_back(toupper(*it));
				cap_flag = false;
			}
			else
				out_str.push_back(*it);
		}
		if (isupper(*it))
		{
			if (cap_flag)
				out_str.push_back(*it);
			else
			{
				out_str.pop_back();
				out_str.push_back('.');
				out_str.push_back(' ');
				out_str.push_back(*it);
			}
		}
	}
	return str;
}