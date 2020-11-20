/*
Given an array of integers, find the minimum number of elements to remove from the array so that the square root of the largest integer in the array is less or equal to the smallest number
in the same array.
x = smallest integer in the array
y = largest integer in the array
Find the minimum number of elements to remove so, √y ≤ x.
*/
#include <vector>
#include <algorithm>
#include <math.h>

int minRemove(std::vector<int> arr)
{
	int outputInt = 0;
	std::sort(arr.begin(), arr.end());
	arr.erase(unique(arr.begin(), arr.end()), arr.end());
	for (auto it = arr.rbegin(); it != arr.rend(); it++)
	{
		double a = sqrt(*it);
		double b = *arr.begin();
		if (a > b)
		{
			outputInt++;
		}
	}
	return outputInt;
}