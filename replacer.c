#include <stdio.h>
#include <stdlib.h>
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
    scanf("%s", input);

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
        int typeOfChar = isAcceptedSymbol(input[i]);
        printf("%d", typeOfChar);
        switch (typeOfChar)
        {
        case 1:
            if (isCharSequence){
                output[outputIndex] = 'x';
                outputIndex++;
                isCharSequence = 0;

                printf("%c", output[outputIndex]);
                // break;
            }

            output[outputIndex] = input[i];
            outputIndex++;

            printf("%c", output[outputIndex]);
            break;
        case 2:
            qttOfChar++;
            break;
        }
    }
    output[outputIndex] = '\0';

}