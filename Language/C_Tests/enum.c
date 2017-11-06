#include <stdio.h>
#include <string.h>

typedef enum {
    first,
    second,
    third
} Outcome;
// just defines first, second, third to be unique ints (actually are 0, 1, 2)

int main()
{
    Outcome outcome = first; // defines outcome to be the int represented by first

    printf("%d\n", sizeof(outcome));
    printf("%d, %d, %d\n", outcome == first, outcome == second, outcome == third);

    return 0;
}
