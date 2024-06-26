#define NUM_SYMBOLS 3
#define NUM_INPUT_SIZE 50

extern const char acceptedSymbols[NUM_SYMBOLS];

int isAcceptedSymbol(char c);
char* replaceToGrammar(char* input, int len);
char* getInput();