#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lr0.h"

#define STACK_SIZE 100

typedef struct
{
    char lhs;   // Lado esquerdo da produção
    int rhsLen; // Comprimento do lado direito da produção
} ProductionRule;

ProductionRule rules[] = {
    {'S', 3}, // S → (E)
    {'S', 1}, // S → x
    {'E', 1}, // E → S
    {'E', 3}  // E → E+S
};

const char *sequenceMatrix[9][7] = {
    //    (      )       x       +       $       s       l
    {"s2", "-", "s1", "-", "-", "g3", "-"},     // 0
    {"r2", "r2", "r2", "r2", "r2", "r2", "r2"}, // 1
    {"s2", "-", "s1", "-", "-", "g6", "g4"},    // 2
    {"-", "-", "-", "-", "acc", "-", "-"},      // 3
    {"-", "s5", "-", "s7", "-", "-", "-"},      // 4
    {"r1", "r1", "r1", "r1", "r1", "r1", "r1"}, // 5
    {"r3", "r3", "r3", "r3", "r3", "r3", "r3"}, // 6
    {"s2", "-", "s1", "-", "-", "g8", "-"},     // 7
    {"r4", "r4", "r4", "r4", "r4", "r4", "r4"}  // 8
};

void shift(char input, char toState, int *stateStack, int *top);
void reduce(int ruleIndex, int *stateStack, int *top);

void iterate(char *input)
{
    int stateStack[STACK_SIZE];
    int top = 0;
    stateStack[top] = 0;

    int i = 0;
    while (1)
    {
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
        default:
            printf("Invalid character encountered: %c\n", input[i]);
            return;
        }
        const char *action = sequenceMatrix[stateStack[top]][j];
        printf("%c\n", action[0]);
        if (action[0] == 's')
        {
            shift(input[i], action[1], stateStack, &top);
            i++;
        }
        else if (action[0] == 'r')
        {
            reduce(atoi(&action[1]) - 1, stateStack, &top);
        }
        else if (action[0] == 'a')
        {
            printf("Accepted\n");
            return;
        }
        else
        {
            printf("Error: Invalid action for state %d and input '%c'\n", stateStack[top], input[i]);
            return;
        }
    }
}

void shift(char input, char toState, int *stateStack, int *top)
{
    int newState = toState - '0'; // Corrigir a conversão de caractere para inteiro
    stateStack[++(*top)] = newState;
    printf("Shifted to state %d on input '%c'\n", newState, input);
}

void reduce(int ruleIndex, int *stateStack, int *top)
{
    ProductionRule rule = rules[ruleIndex];
    *top -= rule.rhsLen;
    int currentState = stateStack[*top];
    // Push the left-hand side of the production
    stateStack[++(*top)] = currentState;
    printf("Reduced using rule %d: %c → ...\n", ruleIndex + 1, rule.lhs);

    // Determine the new state after reduction
    int lhsIndex;
    switch (rule.lhs)
    {
    case 'S':
        lhsIndex = 5;
        break;
    case 'E':
        lhsIndex = 6;
        break;
    default:
        printf("Error: Invalid LHS in rule %d\n", ruleIndex + 1);
        return;
    }

    const char *gotoAction = sequenceMatrix[stateStack[*top]][lhsIndex];
    if (gotoAction[0] == 'g')
    {
        stateStack[*top] = atoi(&gotoAction[1]);
        printf("Goto state %d\n", stateStack[*top]);
    }
    else
    {
        printf("Error: Invalid goto action for state %d and LHS '%c'\n", stateStack[*top], rule.lhs);
    }
}
