#include <string>
#include <vector>

/**
 * Please use the following type aliases in the solution:
 */
using uint = unsigned int;
using Pos = std::pair<int, int>;
using Board = std::vector<std::string>;
using Result = std::pair<Pos, std::size_t>;


Result exit_from_maze(const Board& model) {
	int max_x = model[0].size();
	int max_y = model.size();
	size_t distance = 0;
	Pos current_pos(0, 0);
	Pos speed(0, 0); // first: -1 down, +1 up; second: -1 left, +1 right

	//find start position
	for (int j = 0; j < max_x; j++)
	{
		if (model[0][j] == '*') // top row entry
		{
			current_pos = { 0, j };
			speed = { -1, 0 };
			break;
		}
	}
	for (int j = 0; j < max_x; j++)
	{
		if (model[max_y-1][j] == '*') // bottom row entry
		{
			current_pos = { max_y - 1, j };
			speed = { 1, 0 };
			break;
		}
	}
	for (int i = 0; i < max_y; i++)
	{
		if (model[i][0] == '*') // left column entry
		{
			current_pos = { i, 0 };
			speed = { 0, 1 };
			break;
		}
	}
	for (int i = 0; i < max_y; i++)
	{
		if (model[i][max_x - 1] == '*') // right column entry
		{
			current_pos = { i,max_x - 1 };
			speed = { 0, -1 };
			break;
		}
	}
	//move beam
	if ((current_pos.first+current_pos.second > 0)&&(max_x > 0)&&(max_y>0))
	{
		while (!(model[current_pos.first][current_pos.second] == '#'))
		{
			current_pos.first = current_pos.first + speed.first;
			current_pos.second = current_pos.second + speed.second;
			distance++;
			if (model[current_pos.first][current_pos.second] == '\\')
			{
				std::swap(speed.first, speed.second);
			}
			if (model[current_pos.first][current_pos.second] == '/')
			{
				speed.first = speed.first * (-1);
				speed.second = speed.second * (-1);
				std::swap(speed.first, speed.second);
			}
		}
		distance--;
		std::swap(current_pos.first, current_pos.second);
	}

		return { current_pos, distance };
}

