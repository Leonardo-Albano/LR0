#include <stdio.h>
#include <stdlib.h>
#include "lr0.h"

const char *sequenceMatrix[9][7] = {
//    (      )       x       +       $       s       l
    {"s2",  "-",     "s1",   "-",     "-",     "g3",    "-"     }, // 0
    {"r2",  "r2",   "r2",   "r2",   "r2",   "r2",    "r2"   }, // 1
    {"s2",  "-",     "s1",   "-",     "-",     "g6",    "g4"   }, // 2
    {"-",    "-",     "-",     "-",     "acc",  "-",      "-"     }, // 3
    {"-",    "s5",   "-",     "s7",   "-",     "-",      "-"     }, // 4
    {"r1",  "r1",   "r1",   "r1",   "r1",   "r1",    "r1"   }, // 5
    {"r3",  "r3",   "r3",   "r3",   "r3",   "r3",    "r3"   }, // 6
    {"s2",  "-",     "s1",   "-",     "-",     "g8",    "-"     }, // 7
    {"r4",  "r4",   "r4",   "r4",   "r4",   "r4",    "r4"   }  // 8
};

void iterate(char* input) {
    int state = 0; // Mudar a lógica dos estados, pois na lista inicia do 1, e no programa inicia do 0
    for (int i = 0; input[i] != '\0'; i++) { 
        int j;

        switch (input[i])
        {
            case '(':
                j = 0;
                break;
            case ')':
                j = 1;
                break;
            case 'x':
                j = 2;
                break;
            case '+':
                j = 3;
                break;
            case '$':
                j = 4;
                break;
            case 's':
                j = 5;
                break;
            case 'l':
                j = 6;
                break;
               
        }
        // printf("%c", sequenceMatrix[state][j][0]);
        if(sequenceMatrix[state][j][0] == 's'){
            // printf("ta chegando");
            shift(input[i], sequenceMatrix[state][j][1], &state, j);
        }
    }
}

void shift(char input, char toState, int* actualState, int symbol){

    printf("%d", atoi(&toState+1));
    // printf("%s\n", sequenceMatrix[symbol][atoi(&toState)]);
    // printf("%s\n", sequenceMatrix[symbol][toState]);
    if(sequenceMatrix[symbol][atoi(&toState)] != "-"){
        printf("\nta podendo\n");
    }else
    {
        printf("\nnao ta podendo\n");
    }
    
}