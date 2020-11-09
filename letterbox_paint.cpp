#include <array>
#include <string>

using namespace std;

array<int, 10> paint_letterboxes(int start, int end)
{
	array <int, 10> digitArray = {0,0,0,0,0,0,0,0,0,0};
	std::string curDigit;
	for (int i = start; i <= end; i++)
	{
		curDigit = std::to_string(i);
		for (char a : curDigit)
		{
			for (int j = 48; j < 58; j++)
			{
				if (a == j) digitArray[j - 48]++;
			}
		}
	}
	return digitArray;
}