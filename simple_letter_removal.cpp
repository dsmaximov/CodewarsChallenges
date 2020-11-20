//-first remove all letter 'a', followed by letter 'b', then 'c', etc...
//- remove the leftmost character first.
//For example :
//solve('abracadabra', 1) = 'bracadabra' # remove the leftmost 'a'.
//solve('abracadabra', 2) = 'brcadabra'  # remove 2 'a' from the left.
//solve('abracadabra', 6) = 'rcdbr'      # remove 5 'a', remove 1 'b'
//solve('abracadabra', 8) = 'rdr'
//solve('abracadabra', 50) = ''

#include<string>

std::string simple_letter_removal(const std::string& s, unsigned k)
{
	std::string outString = s;
	for (char i = 'a'; i <= 'z'; i++)
	{
		for (auto it = outString.begin(); it != outString.end();)
		{
			if (*it == i)
			{
				if (k > 0)
				{
					it = outString.erase(it);
					k--;
				}
				else break;
			}
			else
				it++;
		}
	}
	return outString;
}