#include <stdio.h>

struct Robot
{
    int robotID;
    char robotType[30];
    float payloadCapacity;
    float actualLoad;
    float operatingTime;
    float utilization;
};

int main()
{
    struct Robot r[100];
    int n, i;
    int overloaded = 0;

    printf("Enter number of robotic arms: ");
    scanf("%d", &n);

    if(n <= 0 || n > 100)
    {
        printf("Invalid number of robots!\n");
        return 0;
    }

    for(i = 0; i < n; i++)
    {
        printf("\nEnter details of Robot %d\n", i + 1);

        printf("Enter Robot ID: ");
        scanf("%d", &r[i].robotID);

        printf("Enter Robot Type: ");
        scanf("%29s", r[i].robotType);

        printf("Enter Payload Capacity: ");
        scanf("%f", &r[i].payloadCapacity);

        printf("Enter Actual Load: ");
        scanf("%f", &r[i].actualLoad);

        printf("Enter Operating Time: ");
        scanf("%f", &r[i].operatingTime);

        if(r[i].payloadCapacity <= 0 || r[i].actualLoad < 0 || r[i].operatingTime < 0)
        {
            printf("Invalid robot measurements!\n");
            return 0;
        }

        r[i].utilization =
        (r[i].actualLoad / r[i].payloadCapacity) * 100;
    }

    printf("\n===== ROBOT LOAD UTILIZATION REPORT =====\n");

    for(i = 0; i < n; i++)
    {
        printf("\nRobot ID: %d\n", r[i].robotID);
        printf("Robot Type: %s\n", r[i].robotType);
        printf("Payload Capacity: %.2f\n", r[i].payloadCapacity);
        printf("Actual Load: %.2f\n", r[i].actualLoad);
        printf("Operating Time: %.2f hours\n", r[i].operatingTime);
        printf("Load Utilization: %.2f%%\n", r[i].utilization);

        if(r[i].actualLoad > r[i].payloadCapacity)
        {
            printf("Status: OVERLOADED!\n");
            overloaded++;
        }
        else
        {
            printf("Status: Within Rated Payload\n");
        }
    }

    printf("\n===== OVERLOADED ROBOTS =====\n");

    if(overloaded == 0)
    {
        printf("No robots are operating beyond rated payload.\n");
    }
    else
    {
        for(i = 0; i < n; i++)
        {
            if(r[i].actualLoad > r[i].payloadCapacity)
            {
                printf("Robot ID %d is operating beyond rated payload.\n",
                       r[i].robotID);
            }
        }
    }

    return 0;
}