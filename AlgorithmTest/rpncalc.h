#ifndef _RPNCALC_H_
#define _RPNCALC_H_

#include "arraystack.h"
#include <string.h>

typedef enum {
    Zero,
    One,
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Plus,
    Minus,
    Asterisk,
    Slash,
    Cross,
    Unknown,
} Token;

typedef enum {
    Add,
    Subtract,
    Multiply,
    Divide,
} Operation;

void CalculateInputRPN();
double CalculateRPN(char* str);
void ProcessRPNStack(ArrayStackDouble* stack, Operation operation);
Token CharToToken(char input);

#endif
