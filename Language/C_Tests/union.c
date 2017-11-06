#include <stdio.h>
#include <string.h>

typedef union Values {
    int i;
    char str[20];
} Value;
// struct but only the most recently set value is actually set
// is as large as largest field

int main()
{
    Value val;

    strcpy(val.str, "C Programming");
    val.i = 24323;

    printf("%d\n", sizeof(val));
    printf("%p, %p, %p\n", &val, &(val.i), &(val.str));
    printf("%d, %s\n", val.i, val.str);

    return 0;
}
