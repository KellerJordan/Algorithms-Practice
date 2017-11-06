#include <stdio.h>
#include <string.h>

int hashArr[11];

int hash(int k, int i) {
    return (k % 11 + i * (1 + k % 10)) % 11;
}

void insert(int k) {
    char result[] = k + ": ";
    int i = 0; int p = 0;
    do {
        p = hash(k, i);
        strcat(result, p + ", ");
        i++;
    } while (hashArr[p] != 0);
    hashArr[p] = k;

    printf(result);
}

int main() {
    insert(34);
    insert(25);
    insert(79);
    insert(56);
    insert(6);
}