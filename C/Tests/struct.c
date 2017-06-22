#include <stdio.h>
#include <string.h>

typedef struct {
    int pages;
    char title[50];
} Book;
// has size = sum of all fields

int main()
{
    Book book;

    book.pages = 25556;
    strcpy(book.title, "C Programming");

    printf("%d\n", sizeof(book));
    printf("%p, %p, %p\n", &book, &(book.pages), &(book.title));
    printf("%d, %s\n", book.pages, book.title);

    return 0;
}
