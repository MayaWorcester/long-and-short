#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main (int argc, char *argv[])
{
    // Prints an error statement if there are less than 4 arguments.
    if (argc < 4)
    {
        printf("ERROR: 3 file names must be provided.\n");
        exit(1);
    }

    FILE *in = fopen(argv[1], "r");
    // Prints an error statement if the source file cannot be opened.
    if (!in)
    {
        printf("ERROR: Cannot open source file for reading.\n");
        exit(1);
    }

    FILE *shortDest = fopen(argv[2], "w");
    // Prints an error statement if the short destination file cannot be opened.
    if (!shortDest)
    {
        printf("ERROR: Cannot open short dest file for writing.\n");
        exit(1);
    }

    FILE *longDest = fopen(argv[3], "w");
    // Prints an error statement if the long destination file cannot be opened.
    if (!longDest)
    {
        printf("ERROR: Cannot open long dest file for writing\n");
        exit(1);
    }

    char line[100];
    int longCount = 0;
    int shortCount = 0;
    // Loops through the source file until its end is reached
    while(fgets(line, 100, in) != NULL)
    {
        int length = 0;
        // Obtains the length of one line
        for (int i = 0; line[i] != '\0'; i++)
        {
            length++;
        }

        // If the length < 20 characters, convert the line to uppercase and write to the short destination file
        if (length < 20)
        {
            for (int j = 0; line[j] != '\0'; j++)
            {
                line[j] = toupper(line[j]);
            }
            fprintf(shortDest, "%s", line);
            shortCount++;
        }
        // Otherwise convert the line to lowercase and write to the long destination file
        else
        {
            for (int k = 0; line[k] != '\0'; k++)
            {
                line[k] = tolower(line[k]);
            }
            fprintf(longDest, "%s", line);
            longCount++;
        }
    }
    // Prints how many lines were written to each file
    printf("%d lines written to %s\n", shortCount, argv[2]);
    printf("%d lines written to %s\n", longCount, argv[3]);

    fclose(in);
    fclose(shortDest);
    fclose(longDest);
}