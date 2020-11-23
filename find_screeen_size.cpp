//Cheesy Cheeseman just got a new monitor!He is happy with it, but he just discovered that his old desktop wallpaper no longer fits.He wants to find a new 
//wallpaper, but does not know which size wallpaper he should be looking for, and alas, he just threw out the new monitor's box. Luckily he remembers the width
//and the aspect ratio of the monitor from when Bob Mortimer sold it to him. Can you help Cheesy out?
//
//The Challenge
//Given an integer width and a string ratio written as WIDTH : HEIGHT, output the screen dimensions as a string written as WIDTHxHEIGHT.

#include <string>
#include <stdlib.h>

std::string find_screen_height(int width, const std::string& ratio)
{
	std::string width_ratio;
	std::string height_ratio;
	bool colon_reached_flag = false;
	for (auto it = ratio.begin(); it != ratio.end(); it++)
	{
		if (!colon_reached_flag)
		{
			if (*it == ':')
				colon_reached_flag = true;
			else 
				width_ratio.push_back(*it);
		}
		else
		{
			height_ratio.push_back(*it);
		}
	}
	int height = stoi(height_ratio)*width/stoi(width_ratio);
	std::string outString = std::to_string(width) + "x" + std::to_string(height);
	return(outString);
}