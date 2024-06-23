#include <stdio.h>
#include "replacer.h"

int main() {
    char* input = getInput();

    printf("Sequencia: ");
    for (int i = 0; input[i] != '\0'; i++)
    {
        printf("%c", input[i]);
    }
    
    return 0;
}