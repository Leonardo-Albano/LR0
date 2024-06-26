#ifndef LR0_H
#define LR0_H

void iterate(char *input);
void shift(char input, char toState, int *stateStack, int *top);
void reduce(int ruleIndex, int *stateStack, int *top);

#endif /* LR0_H */
