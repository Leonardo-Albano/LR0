#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "replacer.h"

const char acceptedSymbols[NUM_SYMBOLS] = {'+', '(', ')', ' '};

int isAcceptedSymbol(char c) {
    for (int i = 0; i < NUM_SYMBOLS; i++) {
        if (c == acceptedSymbols[i]) {
            return 1;
        }
    }

    if ((c >= 'a' && c <= 'z')){
        return 2;
    }

    printf("\nCRITICAL ERROR: %c isn't on alphabet.", c);
    exit(0);
}

void getInput() {
    char input[NUM_INPUT_SIZE];

    printf("Enter the sequence: ");
    // Use fgets to read the entire line including spaces
    if (fgets(input, NUM_INPUT_SIZE, stdin) == NULL) {
        printf("Error reading input.\n");
        exit(1);
    }

    // Remove the newline character if present
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }

    char* output = (char*)malloc((NUM_INPUT_SIZE + 1) * sizeof(char));
    if (output == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    int isCharSequence = 0;
    int qttOfChar = 0;
    int outputIndex = 0;
    printf("\n");
    for(int i = 0; input[i] != '\0'; i++){

        switch (isAcceptedSymbol(input[i]))
        {
        case 1:
            if (isCharSequence){
                output[outputIndex] = 'x';
                printf("%c", output[outputIndex]);
                outputIndex++;
                isCharSequence = 0;

                // break;
            }

            output[outputIndex] = input[i];
            printf("%c", output[outputIndex]);

            outputIndex++;

            break;
        case 2:
            isCharSequence = 1;
            qttOfChar++;
            break;
        }
    }
    output[outputIndex] = '\0';

}