#include <stdio.h>
#include "lr0.h"

const char *array[9][7] = {
//    (      )       x       +       $       s       l
    {"s3",  "",     "s2",   "",     "",     "g4",    ""     }, // 1
    {"r2",  "r2",   "r2",   "r2",   "r2",   "r2",    "r2"   }, // 2
    {"s3",  "",     "s2",   "",     "",     "g7",    "g5"   }, // 3
    {"",    "",     "",     "",     "acc",  "",      ""     }, // 4
    {"",    "s6",   "",     "s8",   "",     "",      ""     }, // 5
    {"r1",  "r1",   "r1",   "r1",   "r1",   "r1",    "r1"   }, // 6
    {"r3",  "r3",   "r3",   "r3",   "r3",   "r3",    "r3"   }, // 7
    {"s3",  "",     "s2",   "",     "",     "g9",    ""     }, // 8
    {"r4",  "r4",   "r4",   "r4",   "r4",   "r4",    "r4"   } // 9
};

void iterate(char* input) {
    int state = 1;
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
            
            default:
                break;
        }
        printf("%d-%d\n", state, j);
    }
}
