/*Develop a Program in C for the following:
a) Declare a calendar as an array of 7 elements (A dynamically Created array) to represent 7 days of a
week. Each Element of the array is a structure having three fields. The first field is the name of the
Day (A dynamically allocated String), The second field is the date of the Day (A integer), the third field
is the description of the activity for a particular day (A dynamically allocated String).
b) Write functions create(), read() and display(); to create the calendar, to read the data from the
keyboard and to print weeks activity details report on screen.*/

#include<stdio.h>
#include<stdlib.h>

typedef struct
{
  char *dayname;
  int date;
  char *activity;
}week;

void create(week *day)
{
  day->dayName=(char *)malloc(sizeof(char) * 20);
  day->activity=(char *)malloc(sizeof(char) *100);

  printf("Enter the day:");
  scanf("%s",day->dayname);

  printf("Enter the date:");
  scanf("%d",&day->date);

  printf("Enter the activity:");
  scanf("%[^\n]s",day->activity);
}

void read(week *calendar,int size)
{
  int i;
  for(i=0;i<size;i++)
  {
    printf("enter details for day %d:\n"i+1);
    create(&calendar[i]);
  }
}

void display(display(week *calendar, int size)
{
  int i;
  printf("\nWeek's Activity Details:\n");
  printf("--------------------------------------------------\n");
  printf("Dayno\t\tDayname\t\tDate\t\tActivity\n");
  printf("--------------------------------------------------\n");
  for (i = 0; i < size; i++)
  {
    printf("%d\t\t", i + 1);
    printf("| %s |\t\t", calendar[i].dayName);
    printf("| %d |\t\t", calendar[i].date);
    printf("| %s |\t\t", calendar[i].activity);
    printf("\n");
  }
}


int main() {
  int size;
  week *calendar;  
  printf("Enter the number of days in the week: ");
  scanf("%d", &size);
  calendar = (week *)malloc(sizeof(week) * size);
  if (calendar == NULL) 
  {
    printf("Memory allocation failed. Exiting program.\n");
    return 1;
  }
  read(calendar, size);
  display(calendar, size);
  free(calendar);
  return 0;
}

