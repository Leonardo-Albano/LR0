#include <stdio.h>
#include <stdlib.h>
#include "lr0.h"

const char *sequenceMatrix[9][7] = {
//    (      )       x       +       $       s       l
    {"s3",  "-",     "s2",   "-",     "-",     "g4",    "-"     }, // 0
    {"r2",  "r2",   "r2",   "r2",   "r2",   "r2",    "r2"   }, // 1
    {"s3",  "-",     "s2",   "-",     "-",     "g7",    "g5"   }, // 2
    {"-",    "-",     "-",     "-",     "acc",  "-",      "-"     }, // 3
    {"-",    "s6",   "-",     "s8",   "-",     "-",      "-"     }, // 4
    {"r1",  "r1",   "r1",   "r1",   "r1",   "r1",    "r1"   }, // 5
    {"r3",  "r3",   "r3",   "r3",   "r3",   "r3",    "r3"   }, // 6
    {"s3",  "-",     "s2",   "-",     "-",     "g9",    "-"     }, // 7
    {"r4",  "r4",   "r4",   "r4",   "r4",   "r4",    "r4"   }  // 8
};

void iterate(char* input) {
    int state = 1; // Mudar a lógica dos estados, pois na lista inicia do 1, e no programa inicia do 0
    for (int i = 0; input[i] != '\0'; i++) { 
        int j;

        switch (input[i])
        {
            case '(':
                j = 0;

                // if(state != 3 && 
                //     state != 4){

                //     // printf("%c\n", sequenceMatrix[state][j][0]);
                //     if(sequenceMatrix[state][j][0] == 's'){
                //         shift(input[i], sequenceMatrix[state][j][1], &state);
                //     }
                // }
                // else{
                //     printf("nao atende.");
                // };
                
                break;
            case ')':
                j = 1;

                // if(state != 0 && 
                //     state != 2 && 
                //     state != 3){
                //     printf("%s\n", sequenceMatrix[state][j]);
                // }
                // else{
                //     printf("nao atende.");
                // };
                break;
            case 'x':
                j = 2;

                // if(state != 3 && 
                //     state != 4){
                //     printf("%s\n", sequenceMatrix[state][j]);
                // }
                // else{
                //     printf("nao atende.");
                // };

                break;
            case '+':
                j = 3;
                // if(state != 0  && 
                //     state != 2 &&
                //     state != 3 &&
                //     state != 7){
                //     printf("%s\n", sequenceMatrix[state][j]);
                // }
                // else{
                //     printf("nao atende.");
                // };

                break;
            case '$':
                j = 4;

                // if(state != 0  && 
                //     state != 2 &&
                //     state != 4 &&
                //     state != 7){
                //     printf("%s\n", sequenceMatrix[state][j]);
                // }
                // else{
                //     printf("nao atende.");
                // };

                break;
            case 's':
                j = 5;

                // if(state != 3 && 
                //     state != 4){
                //     printf("%s\n", sequenceMatrix[state][j]);
                // }
                // else{
                //     printf("nao atende.");
                // };

                break;
            case 'l':
                j = 6;

                // if(state != 0  && 
                //     state != 3 &&
                //     state != 4 &&
                //     state != 7){
                //     printf("%s\n", sequenceMatrix[state][j]);
                // }
                // else{
                //     printf("nao atende.");
                // };

                break;
               
        }
        
        if(sequenceMatrix[state][j][0] == 's'){
            shift(input[i], sequenceMatrix[state][j][1], &state, j);
        }
    }
}

void shift(char input, char toState, int* actualState, int symbol){

    printf("%s", sequenceMatrix[symbol][atoi(&toState)]);
    if(sequenceMatrix[symbol][atoi(&toState)] != "-"){
        printf("\nta podendo\n");
    }else
    {
        printf("\nnao ta podendo\n");
    }
    
}