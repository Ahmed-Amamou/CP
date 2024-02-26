#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_COMMAND_LENGTH 100000000000000000000
#define MAX_FILE_NAME_LENGTH 100000000000000000000

typedef struct
{
    char name[MAX_FILE_NAME_LENGTH];
    int status;
} File;

int main()
{
    int n;
    scanf("%d", &n);
    File files[n];
    int fileCount = 0;
    int somme = 0;
    for (int i = 0; i < n; i++)
    {
        char command[MAX_COMMAND_LENGTH];
        scanf(" %[^\n]", command);
        if (strncmp(command, "touch", 5) == 0)
        {
            char *file = command + 6;
            int found = 0;
            for (int j = 0; j < fileCount; j++)
            {
                if (strcmp(files[j].name, file) == 0)
                {
                    found = 1;
                    if (files[j].status == 0)
                    {
                        somme++;
                        files[j].status = 1;
                    }
                    break;
                }
            }
            if (!found)
            {
                somme++;
                strcpy(files[fileCount].name, file);
                files[fileCount].status = 1;
                fileCount++;
            }
        }
        else if (strncmp(command, "rm", 2) == 0)
        {
            char *file = command + 3;
            for (int j = 0; j < fileCount; j++)
            {
                if (strcmp(files[j].name, file) == 0 && files[j].status == 1)
                {
                    somme--;
                    files[j].status = 0;
                    break;
                }
            }
        }
        else
        {
            printf("%d\n", somme);
        }
    }
    return 0;
}