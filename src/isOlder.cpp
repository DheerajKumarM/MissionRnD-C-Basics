/*
OVERVIEW: 	Given date of births of two persons as inputs, return 1 if person one is elder,
2 if person two is elder, 0 if both are of same age.
Example: isOlder("24-07-2000", "25-07-2000") should return 1 as person one
is elder than person two.

INPUTS: 	DOBs of two persons as parameters in the format "DD-MM-YYYY".

OUTPUT: 	1 if person one is elder, 2 if person two is elder, 0 if both are of same age.

ERROR CASES: Return -1 if any DOB is invalid.

NOTES: 		Don't use any built-in C functions for comparisions. You are free to write any helper functions.
*/
int power(int num1, int num2)
{
	int i,temp=1;
	for (i = 0; i < num2; i++)
		temp *= num1;
	return temp;
}
int datecalc(char s[], int i, int j)
{
	int k = 0, z;
	int sum = 0;
	for (k = i, z = 0; k<j; z++, k++)
	{
		sum += (s[k] - '0')*(power(10, j - i - z - 1));
	}
	return sum;
}
int isOlder(char *dob1, char *dob2) 
{
	int month1,month2, day1,day2, flag1 = 0,flag2=0, i, year1,year2;
	int daysinnonleap[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int daysinleap[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (dob1[2] == '-'&&dob1[5] == '-'&&dob2[2] == '-'&&dob2[5] == '-')
	{
		year1 = datecalc(dob1, 6, 10);
		year2 = datecalc(dob2, 6, 10);
		if (year1 % 4 == 0)
		{
			month1 = datecalc(dob1, 3, 5);
			day1 = datecalc(dob1, 0, 2);
			if (month1 <= 12)
			{
				i = month1;
				if (day1 <= daysinleap[i - 1])
				{
					flag1 = 1;
				}
				else
					flag1 = 0;
			}
			else
				flag1 = 0;
		}
		else
		{
			month1 = datecalc(dob1, 3, 5);
			day1 = datecalc(dob1, 0, 2);
			if (month1 < 13)
			{
				i = month1;
				if (day1 <= daysinnonleap[i - 1])
				{
					flag1 = 1;
				}
				else
					flag1 = 0;
			}
			else
				flag1 = 0;
		}
		if (flag1 == 1)
		{
			if (year2 % 4 == 0)
			{
				month2 = datecalc(dob2, 3, 5);
				day2 = datecalc(dob2, 0, 2);
				if (month2 <= 12)
				{
					i = month2;
					if (day2 <= daysinleap[i - 1])
					{
						flag2 = 1;
					}
					else
						flag2 = 0;
				}
				else
					flag2 = 0;
			}
			else
			{
				month2 = datecalc(dob2, 3, 5);
				day2 = datecalc(dob2, 0, 2);
				if (month2 < 13)
				{
					i = month2;
					if (day2 <= daysinnonleap[i - 1])
					{
						flag2 = 1;
					}
					else
						flag2 = 0;
				}
				else
					flag2 = 0;
			}
		}
		if (flag1 == 1 && flag2 == 1)
		{
			if (year1 < year2)
				return 1;
			else if (year2 < year1)
				return 2;
			else
			{
				if (month1 < month2)
					return 1;
				else if (month2 < month1)
					return 2;
				else
				{
					if (day1 < day2)
						return 1;
					else if (day2 < day1)
						return 2;
					else
						return 0;
				}
			}
		}
	}
	return -1;
}
