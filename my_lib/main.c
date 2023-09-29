#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

int my_atoi(char digit) {
    return digit - '0';
}

double my_pow(double x, int y) {
    double val = x;
    for (int i = 1; i < y; i++) {
        x *= val;
    }
    return x;
}

double my_strtod(const char* str, const char** end) {
    double dbl = 0;
    bool before_point = true;
    int after_point_count = 0;
    int count = 0;

    for (; !isdigit(str[count]); count++);
    
    for (; ; count++) {
        if (isdigit(str[count])) {
            if (before_point) {
                dbl *= 10;
                dbl += my_atoi(str[count]);
            }
            if (!before_point) {
                after_point_count++;
                dbl += my_atoi(str[count]) / my_pow(10, after_point_count);
            }
            *end = str + count + 1;
        }
        if (str[count] == '.') {
            before_point = false;
            continue;
        }
        if (!isdigit(str[count])) {
            break;
        }
    }
    return dbl;
}

int main(void) {
    const char* end;
    double dbl = my_strtod("hello, 210000.020020014., mylove", &end);
    printf("%.10f\n", dbl);
    printf("%s\n", end);
}
