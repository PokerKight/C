#include <stdio.h>

static char daytab[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int day)
{
	int leap = 0;
	char *p = NULL;
	
	if (year < 1)
		return -1;
	
	leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
	if (month < 1 || month > 12)
		return -1;
	if (day < 1 || day > *(*(daytab + leap) + month))
		return -1;
	p = daytab[leap];
	while (--month)
		day += *++p;
	
	return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday)
{
	int leap = 0;
	char *p = NULL;
	
	if (year < 1)
	{
		*pmonth = -1;
		*pday = -1;
		return ;
	}
	
	leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
	p = daytab[leap];
	while (yearday > *++p && p - daytab[leap] < 12)
		yearday -= *p;
	if (yearday > *(*(daytab + leap)+12))
	{
		*pmonth = -1;
		*pday = -1;
	}
	else
	{
		*pmonth = p - *(daytab + leap);
		*pday = yearday;
	}
}

int main()
{
	int inYear = 0;
	int inDate = 0;
	int outMonth = 0;
	int outDay = 0;
	int outDate = 0;
	
	scanf("%d %d", &inYear, &inDate);
	
	month_day(inYear, inDate, &outMonth, &outDay);
	printf("%04d-%02d-%02d\n", inYear, outMonth, outDay);
	
	outDate = day_of_year(inYear, outMonth, outDay);
	if (inDate == outDate)
		printf("succeed\n");
	else
		printf("fail\n");
	
	return 0;
}
