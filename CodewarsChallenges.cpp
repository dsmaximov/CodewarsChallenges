#include <iostream>
#include <vector>

int cockroach_speed(float FloatSpeed);
size_t over_the_road(size_t address, size_t street);
int days(int date, int month, int year);
std::vector<int> solve(std::vector<std::string> arr);


int main()
{
	std::vector<int> sOutput;
	sOutput = solve({ "aBc", "abc", "aaa" });
	for (int i = 0; i < size(sOutput); i++)
	{
		std::cout << sOutput[i];
	}
}

