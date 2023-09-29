#ifndef _BRACKETCHECKER_H_
#define _BRACKETCHECKER_H_

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "arraystack.h"

typedef enum {
    Regular,
    Square,
    Curly,
    RegularClosing,
    SquareClosing,
    CurlyClosing,
    None,
} Bracket;

typedef struct {
    char opening;
    char closing;
} BracketPair;

void BracketCheckUserInput();
void BracketCheck(char* str);
Bracket ConvertToBracket(char input);

#endif
