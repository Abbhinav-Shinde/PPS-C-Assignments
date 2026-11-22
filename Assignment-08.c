#include <stdio.h>

int main()
{
    int n, i, nearestSensor = 0;
    float distance[100], threshold, minDistance;
    float *ptr;

    ptr = distance;

    printf("Enter number of robot sensors: ");
    scanf("%d", &n);

    if(n <= 0 || n > 100)
    {
        printf("Invalid number of sensors!\n");
        return 0;
    }

    for(i = 0; i < n; i++)
    {
        printf("Enter distance reading of Sensor %d: ", i + 1);
        scanf("%f", ptr + i);
    }

    printf("Enter safety threshold: ");
    scanf("%f", &threshold);

    minDistance = *ptr;

    for(i = 1; i < n; i++)
    {
        if(*(ptr + i) < minDistance)
        {
            minDistance = *(ptr + i);
            nearestSensor = i;
        }
    }

    printf("\n===== ROBOT SENSOR REPORT =====\n");

    for(i = 0; i < n; i++)
    {
        printf("Sensor %d: %.2f cm\n", i + 1, *(ptr + i));
    }

    printf("\nNearest Object Distance: %.2f cm\n", minDistance);
    printf("Nearest Object Detected by Sensor: %d\n",
           nearestSensor + 1);

    if(minDistance < threshold)
    {
        printf("WARNING! Object is too close.\n");
    }
    else
    {
        printf("Object is at a safe distance.\n");
    }

    return 0;
}