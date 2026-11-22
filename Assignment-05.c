#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char str1[100], str2[100];
    char result[200];
    char ch, *ptr;
    int choice, i;

    do
    {
        printf("\n===== STRING OPERATIONS =====\n");
        printf("1. Find Length\n");
        printf("2. Copy String\n");
        printf("3. Concatenate Strings\n");
        printf("4. Compare Strings\n");
        printf("5. Find Character\n");
        printf("6. Find Last Character\n");
        printf("7. Find Substring\n");
        printf("8. Tokenize String\n");
        printf("9. Convert to Uppercase\n");
        printf("10. Convert to Lowercase\n");
        printf("11. Check Character Type\n");
        printf("12. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch(choice)
        {
            case 1:
                printf("Enter a string: ");
                fgets(str1, sizeof(str1), stdin);
                str1[strcspn(str1, "\n")] = '\0';

                printf("Length = %d\n", (int)strlen(str1));
                break;

            case 2:
                printf("Enter a string: ");
                fgets(str1, sizeof(str1), stdin);
                str1[strcspn(str1, "\n")] = '\0';

                strcpy(result, str1);
                printf("Copied string = %s\n", result);
                break;

            case 3:
                printf("Enter first string: ");
                fgets(str1, sizeof(str1), stdin);
                str1[strcspn(str1, "\n")] = '\0';

                printf("Enter second string: ");
                fgets(str2, sizeof(str2), stdin);
                str2[strcspn(str2, "\n")] = '\0';

                strcpy(result, str1);
                strcat(result, str2);

                printf("Concatenated string = %s\n", result);
                break;

            case 4:
                printf("Enter first string: ");
                fgets(str1, sizeof(str1), stdin);
                str1[strcspn(str1, "\n")] = '\0';

                printf("Enter second string: ");
                fgets(str2, sizeof(str2), stdin);
                str2[strcspn(str2, "\n")] = '\0';

                if(strcmp(str1, str2) == 0)
                    printf("Strings are equal.\n");
                else
                    printf("Strings are not equal.\n");
                break;

            case 5:
                printf("Enter a string: ");
                fgets(str1, sizeof(str1), stdin);
                str1[strcspn(str1, "\n")] = '\0';

                printf("Enter character to find: ");
                scanf(" %c", &ch);
                getchar();

                ptr = strchr(str1, ch);

                if(ptr != NULL)
                    printf("Character found.\n");
                else
                    printf("Character not found.\n");
                break;

            case 6:
                printf("Enter a string: ");
                fgets(str1, sizeof(str1), stdin);
                str1[strcspn(str1, "\n")] = '\0';

                printf("Enter character to find: ");
                scanf(" %c", &ch);
                getchar();

                ptr = strrchr(str1, ch);

                if(ptr != NULL)
                    printf("Last occurrence found at position %d\n",
                           (int)(ptr - str1 + 1));
                else
                    printf("Character not found.\n");
                break;

            case 7:
                printf("Enter a string: ");
                fgets(str1, sizeof(str1), stdin);
                str1[strcspn(str1, "\n")] = '\0';

                printf("Enter substring to find: ");
                fgets(str2, sizeof(str2), stdin);
                str2[strcspn(str2, "\n")] = '\0';

                ptr = strstr(str1, str2);

                if(ptr != NULL)
                    printf("Substring found.\n");
                else
                    printf("Substring not found.\n");
                break;

            case 8:
                printf("Enter a string: ");
                fgets(str1, sizeof(str1), stdin);
                str1[strcspn(str1, "\n")] = '\0';

                ptr = strtok(str1, " ");

                printf("Tokens:\n");
                while(ptr != NULL)
                {
                    printf("%s\n", ptr);
                    ptr = strtok(NULL, " ");
                }
                break;

            case 9:
                printf("Enter a string: ");
                fgets(str1, sizeof(str1), stdin);
                str1[strcspn(str1, "\n")] = '\0';

                for(i = 0; str1[i] != '\0'; i++)
                    str1[i] = toupper((unsigned char)str1[i]);

                printf("Uppercase string = %s\n", str1);
                break;

            case 10:
                printf("Enter a string: ");
                fgets(str1, sizeof(str1), stdin);
                str1[strcspn(str1, "\n")] = '\0';

                for(i = 0; str1[i] != '\0'; i++)
                    str1[i] = tolower((unsigned char)str1[i]);

                printf("Lowercase string = %s\n", str1);
                break;

            case 11:
                printf("Enter a character: ");
                scanf(" %c", &ch);
                getchar();

                if(isalpha((unsigned char)ch))
                    printf("Alphabet\n");
                else if(isdigit((unsigned char)ch))
                    printf("Digit\n");
                else if(isspace((unsigned char)ch))
                    printf("Whitespace\n");
                else
                    printf("Special character\n");
                break;

            case 12:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while(choice != 12);

    return 0;
}