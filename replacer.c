#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "replacer.h"

const char acceptedSymbols[NUM_SYMBOLS] = {'+', '(', ')'};

int isAcceptedSymbol(char c) {
    for (int i = 0; i < NUM_SYMBOLS; i++) {
        if (c == acceptedSymbols[i]) {
            return 1;
        }
    }

    if (c >= 'a' && c <= 'z')
        return 2;
    else if (c == ' ')
        return 3;
    
    printf("\nCRITICAL ERROR: %c isn't on alphabet.", c);
    exit(0);
}

char* getInput() {
    char input[NUM_INPUT_SIZE];

    printf("Enter the sequence: ");
    if (fgets(input, NUM_INPUT_SIZE, stdin) == NULL) {
        printf("Error reading input.\n");
        exit(1);
    }

    // Remove the newline character if present
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }
    len -= 2;

    return replaceToGrammar(input, len);
}

char* replaceToGrammar(char* input, int len){

    char* output = (char*)malloc((NUM_INPUT_SIZE + 1) * sizeof(char));
    if (output == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    int isCharSequence = 0;
    int outputIndex = 0;
    for(int i = 0; input[i] != '\0'; i++){

        switch (isAcceptedSymbol(input[i]))
        {
        case 1:
            if (isCharSequence){
                output[outputIndex++] = 'x';
                isCharSequence = 0;
            }

            output[outputIndex++] = input[i];
            break;
        case 2:
            isCharSequence = 1;

            if (i == len)
            {
                output[outputIndex++] = 'x';
            }
            
            break;
        case 3:
            if (isCharSequence){
                output[outputIndex++] = 'x';
                isCharSequence = 0;
            }
            break;
        }

    }
    output[outputIndex] = '\0';

    return output;
}