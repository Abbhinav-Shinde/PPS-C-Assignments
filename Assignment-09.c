#include <stdio.h>
#include <string.h>

struct Robot
{
    int robotID;
    float jointAngle;
    float motorTemperature;
    float torque;
    char operationalStatus[20];
};

int main()
{
    struct Robot r;
    FILE *fp;
    int n, i;
    float temperatureLimit, torqueLimit;

    printf("Enter number of robotic arms: ");
    scanf("%d", &n);

    if(n <= 0)
    {
        printf("Invalid number of robotic arms!\n");
        return 0;
    }

    printf("Enter maximum temperature limit: ");
    scanf("%f", &temperatureLimit);

    printf("Enter maximum torque limit: ");
    scanf("%f", &torqueLimit);

    fp = fopen("robot_records.txt", "w");

    if(fp == NULL)
    {
        printf("Unable to open file!\n");
        return 1;
    }

    for(i = 0; i < n; i++)
    {
        printf("\nEnter details of Robot %d\n", i + 1);

        printf("Enter Robot ID: ");
        scanf("%d", &r.robotID);

        printf("Enter Joint Angle: ");
        scanf("%f", &r.jointAngle);

        printf("Enter Motor Temperature: ");
        scanf("%f", &r.motorTemperature);

        printf("Enter Torque Value: ");
        scanf("%f", &r.torque);

        printf("Enter Operational Status (Normal/Abnormal): ");
        scanf("%19s", r.operationalStatus);

        fprintf(fp, "%d %.2f %.2f %.2f %s\n",
                r.robotID,
                r.jointAngle,
                r.motorTemperature,
                r.torque,
                r.operationalStatus);
    }

    fclose(fp);

    fp = fopen("robot_records.txt", "r");

    if(fp == NULL)
    {
        printf("Unable to read file!\n");
        return 1;
    }

    printf("\n===== ROBOT HISTORICAL RECORDS =====\n");

    while(fscanf(fp, "%d %f %f %f %19s",
                 &r.robotID,
                 &r.jointAngle,
                 &r.motorTemperature,
                 &r.torque,
                 r.operationalStatus) == 5)
    {
        printf("\nRobot ID: %d\n", r.robotID);
        printf("Joint Angle: %.2f\n", r.jointAngle);
        printf("Motor Temperature: %.2f\n", r.motorTemperature);
        printf("Torque: %.2f\n", r.torque);
        printf("Operational Status: %s\n", r.operationalStatus);

        if(r.motorTemperature > temperatureLimit ||
           r.torque > torqueLimit ||
           strcmp(r.operationalStatus, "Normal") != 0)
        {
            printf("WARNING: Potential Mechanical Failure!\n");

            if(r.motorTemperature > temperatureLimit)
                printf("Abnormal Motor Temperature Detected.\n");

            if(r.torque > torqueLimit)
                printf("Excessive Torque Detected.\n");

            if(strcmp(r.operationalStatus, "Normal") != 0)
                printf("Abnormal Operational Status Detected.\n");
        }
        else
        {
            printf("Status: Normal Operation.\n");
        }
    }

    fclose(fp);

    printf("\nHistorical records analyzed successfully.\n");

    return 0;
}
