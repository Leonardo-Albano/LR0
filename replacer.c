#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "replacer.h"

const char acceptedSymbols[NUM_SYMBOLS] = {'+', '(', ')'};

int isAcceptedSymbol(char c)
{
    for (int i = 0; i < NUM_SYMBOLS; i++)
    {
        if (c == acceptedSymbols[i])
        {
            return 1;
        }
    }

    if (c >= 'a' && c <= 'z')
        return 2;
    else if (c == ' ')
        return 3;

    printf("\nErro critico: %c o alfabeto é invalido.\n", c);
    exit(0);
}

char *getInput()
{
    char input[NUM_INPUT_SIZE];

    printf("Digite a sequencia: ");
    if (fgets(input, NUM_INPUT_SIZE, stdin) == NULL)
    {
        printf("Erro de leitura na entrada.\n");
        exit(1);
    }

    // Remove the newline character if present
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n')
    {
        input[len - 1] = '\0';
    }

    return replaceToGrammar(input, len);
}

char *replaceToGrammar(char *input, int len)
{
    char *output = (char *)malloc((NUM_INPUT_SIZE + 1) * sizeof(char));
    if (output == NULL)
    {
        printf("Falha para alocar memória.\n");
        exit(1);
    }

    int isCharSequence = 0;
    int outputIndex = 0;
    for (int i = 0; input[i] != '\0'; i++)
    {
        switch (isAcceptedSymbol(input[i]))
        {
        case 1:
            if (isCharSequence)
            {
                output[outputIndex++] = 'x';
                isCharSequence = 0;
            }
            output[outputIndex++] = input[i];
            break;
        case 2:
            isCharSequence = 1;
            if (i == len - 1)
            {
                output[outputIndex++] = 'x';
            }
            break;
        case 3:
            if (isCharSequence)
            {
                output[outputIndex++] = 'x';
                isCharSequence = 0;
            }
            break;
        }
    }
    if (isCharSequence)
    {
        output[outputIndex++] = 'x';
    }
    output[outputIndex] = '\0';

    return output;
}
