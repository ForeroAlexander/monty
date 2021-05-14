#define GLOBALS
#include "monty.h"

/**
 * 
 * 
 * 
 */
char **get_div_line(char *line)
{
    char **divide;
    int i = 0;

    divide = malloc(1024 * sizeof(char *));
    divide[i] = strtok(line, " \n\t");
    if (divide[i] == NULL)
    {
        free(divide);
        return (NULL);
    }
    while (divide[i])
    {
    i++;
    divide[i = strtok(NULL, " \n\t");   
    }
    divide[i + 1] = NULL;
    return (divide);
}