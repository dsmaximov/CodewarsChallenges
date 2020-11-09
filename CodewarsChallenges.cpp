#include <iostream>
#include <vector>
#include <array>


int cockroach_speed(float FloatSpeed);
size_t over_the_road(size_t address, size_t street);
int days(int date, int month, int year);
std::vector<int> solve(std::vector<std::string> arr);
int SAP(std::vector<std::vector<int>> v);
int triangular(int n);
std::array<int, 10> paint_letterboxes(int start, int end);
std::vector<int> digits(int n);


int main()
{
	for (auto i : digits(123))
	{
		std::cout << i;
	}
}

