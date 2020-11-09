/*
Given a long number, return all the possible sum of two digits of it.

For example, 12345: all possible sum of two digits from that number are:

[ 1 + 2, 1 + 3, 1 + 4, 1 + 5, 2 + 3, 2 + 4, 2 + 5, 3 + 4, 3 + 5, 4 + 5 ]
*/
#include<vector>
#include<string>

std::vector<int> digits(int n) {
	std::string inputStr = std::to_string(n);
	std::vector<int> outputVec;
	for (auto itFirst = inputStr.begin(); itFirst < inputStr.end(); itFirst++)
	{
		for (auto itSecond = itFirst+1; itSecond < inputStr.end(); itSecond++)
		{
			outputVec.push_back((*itFirst-'0') + (*itSecond-'0'));
		}
	}
	return outputVec;
}