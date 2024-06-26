#include <stdio.h>
#include <stdlib.h>
#include "replacer.h"
#include <string.h>
#include "lr0.h"

int main()
{
    char *sequence = getInput();
    printf("Sequencia: %s\n", sequence);

    // Adiciona o símbolo de fim de entrada '$'
    int len = strlen(sequence);
    char *inputWithEnd = (char *)malloc((len + 2) * sizeof(char)); // +1 for '$' and +1 for '\0'
    if (inputWithEnd == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    strcpy(inputWithEnd, sequence);
    inputWithEnd[len] = '$';
    inputWithEnd[len + 1] = '\0';

    iterate(inputWithEnd);

    free(sequence);
    free(inputWithEnd);

    return 0;
}
