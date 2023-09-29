// #include "bracketchecker.h"

// char brackets[None] = {
//     [Regular] = '(',
//     [Square] = '[',
//     [Curly] = '{',
//     [RegularClosing] = ')',
//     [SquareClosing] = ']',
//     [CurlyClosing] = '}',
// }

// void BracketCheck(char* str) {
//     size_t len = strlen(str);
//     size_t data[len];
//     ArrayStack stackValue = InitializeArrayStack(data, len);
//     ArrayStack* stack = &stackValue;

//     for (size_t i = 0; i < len; i++) {
//         Bracket bracket = ConvertToBracket(str[i]);
//         switch (bracket) {
//             case Regular: Push(brackets[Regular], stack); break;
//             case Square: Push(brackets[Square], stack); break;
//             case Curly: Push(brackets[Curly], stack); break;
//             case RegularClosing: {
//                 if (Top(stack) == brackets[Regular]) {
//                     Pop(stack);
//                 } else if (Top(stack))
//             }
//         }
//     }
// }

// Bracket ConvertToBracket(char input) {
//     switch (input) {
//         case '(': return Regular; break;
//         case '[': return Square; break;
//         case '{': return Curly; break;
//         case ')': return RegularClosing; break;
//         case ']': return SquareClosing; break;
//         case '}': return CurlyClosing; break;
//         default: return None; 
//     }
// }

