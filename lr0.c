#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lr0.h"

#define STACK_SIZE 100

typedef struct
{
    char le;  // Gerador
    int ld; // Quantidade a ser reduzida 
} ProductionRule;

ProductionRule rules[] = {
    {'S', 3}, // S → (E)
    {'S', 1}, // S → x
    {'E', 1}, // E → S
    {'E', 3}  // E → E+S
};

const char *sequenceMatrix[9][7] = {
//    (     )    x     +    $    s     e
    {"s2", "-", "s1", "-", "-", "g3", "-"},     // 0
    {"r2", "r2", "r2", "r2", "r2", "r2", "r2"}, // 1
    {"s2", "-", "s1", "-", "-", "g6", "g4"},    // 2
    {"-",  "-", "-", "-", "acc", "-", "-"},      // 3
    {"-",  "s5", "-", "s7", "-", "-", "-"},      // 4
    {"r1", "r1", "r1", "r1", "r1", "r1", "r1"}, // 5
    {"r3", "r3", "r3", "r3", "r3", "r3", "r3"}, // 6
    {"s2", "-", "s1", "-", "-", "g8", "-"},     // 7
    {"r4", "r4", "r4", "r4", "r4", "r4", "r4"}  // 8
};


void iterate(char *input)
{
    int stateStack[STACK_SIZE];
    int top = 0;
    stateStack[top] = 0;

    int i = 0;
    while (1)
    {
        int inputSymbol;
        switch (input[i])
        {
        case '(':
            inputSymbol = 0;
            break;
        case ')':
            inputSymbol = 1;
            break;
        case 'x':
            inputSymbol = 2;
            break;
        case '+':
            inputSymbol = 3;
            break;
        case '$':
            inputSymbol = 4;
            break;
        default:
            printf("Encontrado caracter invalido: %c\n", input[i]);
            return;
        }
        const char *action = sequenceMatrix[stateStack[top]][inputSymbol];

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
            printf("Aceito\n");
            return;
        }
        else
        {
            printf("Erro: Ação invalida para o estado %d e para a entrada '%c'\n", stateStack[top], input[i]);
            return;
        }
    }
}
// toState = ação
void shift(char input, char toState, int *stateStack, int *top)
{
    int newState = toState - '0'; // Corrigir a conversão de caractere para inteiro
    stateStack[++(*top)] = newState;
    printf("Shifted para o estado %d com a entrada '%c'\n", newState, input);
}

void reduce(int ruleIndex, int *stateStack, int *top)
{
    ProductionRule rule = rules[ruleIndex];
    *top -= rule.ld;
    int currentState = stateStack[*top];
    stateStack[++(*top)] = currentState; // Adiciona um novo estado no topo da pilha
    printf("Reduzido pela regra %d: %c\n", ruleIndex + 1, rule.le);

    int ldIndex;
    switch (rule.le)
    {
    case 'S':
        ldIndex = 5;
        break;
    case 'E':
        ldIndex = 6;
        break;
    default:
        printf("Erro: regra inválida: %d\n", ruleIndex + 1);
        return;
    }

    const char *gotoAction = sequenceMatrix[stateStack[*top]][ldIndex];
    if (gotoAction[0] == 'g')
    {
        stateStack[*top] = atoi(&gotoAction[1]);
        printf("Go to para o estado %d\n", stateStack[*top]);
    }
    else
    {
        printf("Erro: Go to invalido para o estado %d e o lado esquerdo '%c'\n", stateStack[*top], rule.le);
    }
}
