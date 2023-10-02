#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <limits.h>
#include <string.h>
#include <time.h>

struct timespec timespec_diff(struct timespec two, struct timespec one) {
    time_t secDiff = two.tv_sec - one.tv_sec;
    long nsecDiff = two.tv_nsec - one.tv_nsec;
    if (nsecDiff < 0) {
        secDiff -= 1;
        nsecDiff += 1E9;
    }
    struct timespec diff = {
        .tv_sec = secDiff,
        .tv_nsec = nsecDiff,
    };
    return diff;
}

// int main() {
//     // printf("signed %lu\n", sizeof(signed));
//     // printf("signed long %lu\n", sizeof(signed long));
//     // printf("signed long long %lu\n", sizeof(signed long long));
//     // printf("int %lu\n", sizeof(int));
//     // printf("size_t %lu\n", sizeof(size_t));
//     // printf("unsigned %lu\n", sizeof(unsigned));
//     // printf("double %lu\n", sizeof(double));
//     // printf("float %lu\n", sizeof(float));
//     // printf("long double %lu\n", sizeof(long double));
//     // printf("%d\n", INT_MAX);
//     // printf("%u\n", SIZE_MAX);
//     // printf("%u\n", -1U);

//     char str[] = { 'H', 'e', 'l', 'l', 'o', '\0' };
//     char str2[] = { 'H', 'e', 'l', 'l', 'o', '\0' };
//     if (strcmp(str, str2)) {
//         printf("true\n");
//     }

//     struct timespec time1 = {
//         .tv_sec = 50,
//         .tv_nsec = 1000,
//     };

//     struct timespec time2 = {
//         .tv_sec = 55,
//         .tv_nsec = 500,
//     };

//     struct timespec diff = timespec_diff(time2, time1);

//     printf("%ld\n", diff.tv_sec);
//     printf("%ld\n", diff.tv_nsec);
// }

void delay(double secs) {
    double const magic = 4E8 ; // works just on my machine
    unsigned long long const nano = secs * magic ;
    for ( unsigned long volatile count = 0;
        count < nano ;
        ++ count ) {
            /* nothing here */
        }
}

int main(int argc, char * argv[argc+1]) {
    fputs("waiting 10 seconds for you to stop me", stdout);
    if (argc < 3) fflush(stdout);
    for (unsigned i = 0; i < 10; ++ i) {
        fputc ( '.', stdout);
        if ( argc < 2) fflush(stdout);
        delay (1.0) ;
    }
    fputs ("\n", stdout);
    fputs ("You did ignore me, so bye bye\n" , stdout);
}
