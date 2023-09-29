#include "rpncalc.h"

#define MAXIMUM_LENGTH 255

void CalculateInputRPN() {
    char str[MAXIMUM_LENGTH];
    printf("Input calculation:\n");
    fgets(str, MAXIMUM_LENGTH, stdin);
    double result = CalculateRPN(str);
    printf("Result: %.10f\n", result);
}

double CalculateRPN(char* str) {
    size_t len = strlen(str);
    double data[len];
    ArrayStackDouble stackOriginal = InitializeArrayStackDouble(data, len);
    ArrayStackDouble* stack = &stackOriginal;
    for (size_t i = 0; i < len - 1; i++) {
        Token token = CharToToken(str[i]);
        switch (token) {
            case Zero: PushDouble(0, stack); break;
            case One: PushDouble(1, stack); break;
            case Two: PushDouble(2, stack); break;
            case Three: PushDouble(3, stack); break;
            case Four: PushDouble(4, stack); break;
            case Five: PushDouble(5, stack); break;
            case Six: PushDouble(6, stack); break;
            case Seven: PushDouble(7, stack); break;
            case Eight: PushDouble(8, stack); break;
            case Nine: PushDouble(9, stack); break;
            case Plus: ProcessRPNStack(stack, Add); break;
            case Minus: ProcessRPNStack(stack, Subtract); break;
            case Asterisk: ProcessRPNStack(stack, Multiply); break;
            case Slash: ProcessRPNStack(stack, Divide); break;
            case Cross: ProcessRPNStack(stack, Multiply); break;
            case Unknown: fprintf(stderr, "Unknown input %c, skipping character\n", str[i]); break;
            default: fprintf(stderr, "CharToToken returned unrecognised token\n"); 
        }
    }
    if (stack->Count > 1) {
        fprintf(stderr, "Insufficient operations to match inputs, performing addition on the remaining numbers...\n");
        while (stack->Count > 1) {
            ProcessRPNStack(stack, Add);
        }
    }
    if (stack->Count == 0) {
        fprintf(stderr, "Nothing was inputted, defaulting to 0\n");
        return 0;
    }
    return TopDouble(stack);
}

void ProcessRPNStack(ArrayStackDouble* stack, Operation operation) {
    if (stack->Count < 2) {
        fprintf(stderr, "Too few arguments, skipping operation...\n");
        return;
    }

    double second = PopDouble(stack);
    double first = PopDouble(stack);

    switch (operation) {
        case Add: {
            PushDouble(first + second, stack);
            break;
        }
        case Subtract: {
            PushDouble(first - second, stack);
            break;
        }
        case Multiply: {
            PushDouble(first * second, stack);
            break;
        }
        case Divide: {
            PushDouble(first / second, stack);
            break;
        }
        default: {
            fprintf(stderr, "Unrecognised operation, doing nothing...\n");
            break;
        }
    }
}

Token CharToToken(char input) {
    switch (input) {
        case '0': return Zero;
        case '1': return One;
        case '2': return Two;
        case '3': return Three;
        case '4': return Four;
        case '5': return Five;
        case '6': return Six;
        case '7': return Seven;
        case '8': return Eight;
        case '9': return Nine;
        case '+': return Plus;
        case '-': return Minus;
        case '*': return Asterisk;
        case '/': return Slash;
        case 'x': return Cross;
        default: return Unknown;
    }
}
