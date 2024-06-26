#include <stdio.h>
#include "replacer.h"
#include "lr0.h"

int main() {
    char* input = getInput();

    printf("Sequencia: ");
    for (int i = 0; input[i] != '\0'; i++)
    {
        printf("%c", input[i]);
    }
    printf("\n\n");
    
    iterate(input);
    return 0;
}