/*Name: Anuj Rajendra Mane
Project Name: Restraurant Billing System
Div: c
Roll No: 66_FY_CSE*/
#include <stdio.h>

int FirstDayOfYear(int year)
{
  int day = (year * 365 + ((year - 1) / 4) - ((year - 1) / 100) + ((year - 1) / 400)) % 7;
  // To print a first day of year
  return day;
  //year=2004
  //((731460+500-20+5)%7)
  //(731945%7)
}

int main()
{
  char name[200], *months[100] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
  int i, j, k, weekday = 0, year, totaldays[100] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  printf("\t\t\t\t\t\t\tWELCOME TO calender.com\n");
  printf("Enter your name:\n");
  // gets(name);
  scanf("%s", name);

  printf("\nHello! %s enter any year:\n", name);
  scanf("%d", &year);
  printf("\n~~~~~~~~~~~ Welcome to %d year ~~~~~~~~~~~ \n", year);
  // if a leap year

  if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
  {
    totaldays[1] = 29;
  }

  // FirstDayOfYear function call
  weekday = FirstDayOfYear(year);

  for (i = 0; i < 12; i++)
  {
    printf("\n=====================%s=====================", months[i]);
    printf("\n    Sun   Mon   Tue   Wed   Thu   Fri   Sat\n");

    for (j = 1; j <= weekday; j++)//(j=1; j<=4; j++)
    {
      printf("      ");
    }

    for (k = 1; k <= totaldays[i]; k++)//(K=1; K<=31; K++)
    {
      printf("%6d", k);
      weekday++;
      if (weekday > 6)
      {
        printf("\n");
        weekday = 0;
      }
    }
  }
  return 0;
}