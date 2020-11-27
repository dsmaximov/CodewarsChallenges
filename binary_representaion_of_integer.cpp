//Write a function that returns a vector(list in Python) with each element representing one bit of a 32bit unsigned / signed integer in such a way that if printed it would appear as the binary representation of the integer(Least Significant Bit on the right).
//
//e.g. 1 = 00000000000000000000000000000001
//
//Assign either a 1 or a 0 to the vector element depending on whether the bit at the corresponding position is a 1 or 0.
//
//For example :

#include <vector>
using namespace std;

vector<int> showBits(int n) {
	vector<int> out_vector;
	for (int i = 31; i >=0; i--)
	{
		if (n & (1 << i)) out_vector.push_back(1);
		else out_vector.push_back(0);
	}
	return out_vector;
}