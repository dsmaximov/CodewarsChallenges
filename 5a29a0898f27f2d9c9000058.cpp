/*
In this Kata, you will be given a string and your task will be to return a list of ints detailing the count of uppercase letters, lowercase, numbers and special characters, as follows.

Solve("*'&ABCDabcde12345") = [4,5,5,3].
--the order is: uppercase letters, lowercase, numbers and special characters.

*/
#include <vector>
#include <string>

bool sorterFunct(char letter, int low, int high)
{
	return (letter > low) && (letter < high);
}

std::vector<int> simple_strings(std::string s) {

	std::vector<int> outVector = { 0,0,0,0 };
	for (auto letter : s)
	{
		if (sorterFunct(letter, 64, 91)) outVector[0]++;
		else if (sorterFunct(letter, 96, 123)) outVector[1]++;
		else if (sorterFunct(letter, 47, 58)) outVector[2]++;
		else outVector[3]++;
	}
	return outVector;
}