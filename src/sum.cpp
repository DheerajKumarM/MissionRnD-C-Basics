/*
OVERVIEW: Write a function which takes two numbers as input and returns sum of two numbers.
		E.g.: sum(2, 3) returns 5.

INPUTS: Two numbers a, b;

OUTPUT: sum of the numbers a, b.

ERROR CASES:

NOTES:
*/

int sum(int a, int b)
{
	int carry;
	while (b != 0)
	{
		carry = a&b;
		a = a^b;
		b = carry << 1;
	}
	return a;
}