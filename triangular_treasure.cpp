/*Triangular numbers are so called because of the equilateral triangular shape that they occupy when laid out as dots. i.e.

1st (1)   2nd (3)    3rd (6)
*          **        ***
           *         **
                     *

You need to return the nth triangular number. You should return 0 for out of range values:
*/

int triangular(int n) {
	int x = 0;
	if (n < 1)
	{
		return 0;
	}
	else
	{
		for (int i = 1; i <= n; i++)
		{
			x += i;
		}
		return x;
	}
}