#include <stdio.h>

int main() 
{
    float num1, num2;
    int choice;

    printf("======BASIC CALCULATOR======\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("Enter two numbers: ");
    scanf("%f %f", &num1, &num2);

switch(choice)
{
    case 1:
    printf("Addition = %.2f\n", num1 + num2);
    break;

    case 2: 
    printf("Subtraction = %.2f\n", num1 - num2);
    break;

    case 3:
    printf("Multiplication = %.2f\n", num1 * num2);
    break;

    case 4:
    if(num2 != 0)
    {
    printf("Division = %.2f\n", num1 / num2);
    }
    else
    {
        printf("Error! Division by zero is not possible.\n");
    }
    break;    
}

    return 0;
}