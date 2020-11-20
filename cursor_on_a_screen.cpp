/*My TV remote control has arrow buttons and an OK button.

I can use these to move a "cursor" on a logical screen keyboard to type "words"...

The screen "keyboard" layout looks like this

a	b	c	d	e	1	2	3
f	g	h	i	j	4	5	6
k	l	m	n	o	7	8	9
p	q	r	s	t	.	@	0
u	v	w	x	y	z	_	/
Kata task
How many button presses on my remote are required to type a given word?

Notes
The cursor always starts on the letter a (top left)
Remember to also press OK to "accept" each character.
Take a direct route from one character to the next
The cursor does not wrap (e.g. you cannot leave one edge and reappear on the opposite edge)
A "word" (for the purpose of this Kata) is any sequence of characters available on my virtual "keyboard"
*/
#include <array>
#include <string>

unsigned int tv_remote(const std::string& word)
{
	int next_i = 0;
	int next_j = 0;
	int current_i = 0;
	int current_j = 0;
	int movement = 0;
	const char keyboard[5][8] = {
	{'a',	'b',	'c',	'd',	'e',	'1',	'2',	'3' },
	{'f',	'g',	'h',	'i',	'j',	'4',	'5',	'6' },
	{'k',	'l',	'm',	'n',	'o',	'7',	'8',	'9' },
	{'p',	'q',	'r',	's',	't',	'.',	'@',	'0' },
	{'u',	'v',	'w',	'x',	'y',	'z',	'_',	'/' }
	};

	for (const char& letter : word)
	{
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (letter == keyboard[i][j])
				{
					next_i = i;
					next_j = j;
				}
			}
		}

		movement += abs(next_i - current_i) + abs(next_j - current_j) + 1;
		current_i += next_i - current_i;
		current_j += next_j - current_j;
	}
	return movement;
}