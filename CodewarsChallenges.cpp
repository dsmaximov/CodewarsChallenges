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
std::vector<int> simple_strings(std::string s);
std::vector<int> arrayLeaders(const std::vector<int>& numbers);
unsigned int tv_remote(const std::string& word);
int minRemove(std::vector<int> arr);
long long queue(const std::vector<int>& queuers, int pos);
std::string wordPattern(const std::string& word);
std::string simple_letter_removal(const std::string& s, unsigned k);


int main()
{
	std::cout<< simple_letter_removal("abracadabra", 8) <<"\n";
}

