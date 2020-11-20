#include<vector>

long long queue(const std::vector<int>& queuers, int pos) {
	std::vector<int> currQue = queuers;
	long long outTime = 0;
	int currPos = pos;
	int temp = 0;
	int start_pos = 0;
	int end_pos = size(queuers) - 1;

	while (end_pos >= start_pos)
	{
		outTime++;
		currQue[start_pos]--;
		if (currQue[start_pos] == 0)
		{
			if (currPos == start_pos) return outTime;
			else
			{
				start_pos++;
			}
		}
		temp = currQue[start_pos];
		for (int i = start_pos; i < end_pos; i++)
		{
			currQue[i] = currQue[i + 1];
		}
		currQue[end_pos] = temp;
		if (currPos == start_pos) currPos = end_pos;
		else currPos--;
	}
	return 0;
}
