#include <stdio.h>

static char daytab[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int day)
{
	int i = 0;
	int leap = 0;
	
	if (year < 1)
		return -1;
	
	leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
	if (month < 1 || month > 12)
		return -1;
	if (day < 1 || day > daytab[leap][month])
		return -1;
	for (i = 1; i < month; i++)
		day += daytab[leap][i];
	
	return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday)
{
	int i = 0;
	int leap = 0;
	
	if (year < 1)
	{
		*pmonth = -1;
		*pday = -1;
		return ;
	}
	
	leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
	for (i = 1; yearday > daytab[leap][i]; i++)
		yearday -= daytab[leap][i];
	if (i > 12 && yearday > daytab[leap][12])
	{
		*pmonth = -1;
		*pday = -1;
	}
	else
	{
		*pmonth = i;
		*pday = yearday;
	}
}

int main()
{
	int inYear = 0;
	int inMonth = 0;
	int inDay = 0;
	int outMonth = 0;
	int outDay = 0;
	int date = 0;
	
	scanf("%d-%d-%d", &inYear, &inMonth, &inDay);
	
	date = day_of_year(inYear, inMonth, inDay);
	printf("%d\n", date);
	
	month_day(inYear, date, &outMonth, &outDay);
	if (inMonth == outMonth || inDay == outDay)
		printf("succeed\n");
	else
		printf("fail\n");
	
	return 0;
}
