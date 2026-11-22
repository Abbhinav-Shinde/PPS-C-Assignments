#include <stdio.h>
#include <time.h>

// Function to check leap year
int isLeapYear(int year)
{
    return (year % 400 == 0) ||
           (year % 4 == 0 && year % 100 != 0);
}

// Function to print a single month
void printMonth(int month, int year, int startDay, int days)
{
    char *months[] = {
        "January", "February", "March", "April",
        "May", "June", "July", "August",
        "September", "October", "November", "December"
    };

    printf("\n\n       %s %d\n", months[month - 1], year);
    printf(" Sun Mon Tue Wed Thu Fri Sat\n");

    // Print leading spaces
    for(int i = 0; i < startDay; i++)
    {
        printf("    ");
    }

    // Print dates
    for(int date = 1; date <= days; date++)
    {
        printf("%4d", date);

        if((startDay + date) % 7 == 0)
        {
            printf("\n");
        }
    }

    if((startDay + days) % 7 != 0)
    {
        printf("\n");
    }
}

int main()
{
    int year, startDay;

    int daysInMonth[] = {
        31, 28, 31, 30, 31, 30,
        31, 31, 30, 31, 30, 31
    };

    printf("Enter the year: ");
    scanf("%d", &year);

    if(year < 1900 || year > 9999)
    {
        printf("Please enter a year between 1900 and 9999.\n");
        return 0;
    }

    // Update February for leap year
    if(isLeapYear(year))
    {
        daysInMonth[1] = 29;
    }

    // Find the first day of the year
    struct tm t = {0};

    t.tm_year = year - 1900;
    t.tm_mon = 0;
    t.tm_mday = 1;
    t.tm_hour = 12;
    t.tm_isdst = -1;

    if(mktime(&t) == (time_t)-1)
    {
        printf("Unable to calculate calendar.\n");
        return 1;
    }

    startDay = t.tm_wday;

    // Print all 12 months
    for(int month = 1; month <= 12; month++)
    {
        printMonth(month, year, startDay, daysInMonth[month - 1]);

        // Calculate starting day of next month
        startDay = (startDay + daysInMonth[month - 1]) % 7;
    }

    return 0;
}