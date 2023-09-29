#include <stdio.h>
#include <stdbool.h>

int main() {
    int a = 0;
    int b = 1;
    while (true) {
        int c = a + b;
        a = b;
        b = c;
        printf("%d", b);
    }
}
