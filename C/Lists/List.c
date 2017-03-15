// Linked List with cursor

#include <stdio.h>
#include <stdlib.h>
#include "List.h"

// structs --------------------------------------------------------------------

typedef struct NodeObj {
    int data;
    struct NodeObj* next;
    struct NodeObj* prev;
} NodeObj;

typedef NodeObj* Node;

typedef struct ListObj {
    Node front, back, cursor;
    int length, index;
} ListObj;


// Constructors-Destructors ---------------------------------------------------

Node newNode(int node_data) {
    Node N = malloc(sizeof(NodeObj));
    N->data = node_data;
    N->next = N->prev = NULL;
    return N;
}

void freeNode(Node* pN) {
    if (pN!=NULL && *pN!=NULL) {
        free(*pN);
        *pN = NULL;
    }
}

List newList(void) {
    List L;
    L = malloc(sizeof(ListObj));
    L->front = L->back = L->cursor = NULL;
    L->length = 0;
    return L;
}

void freeList(List* pL) {
    if (pL != NULL && *pL != NULL) {
        while ((*pL)->length > 0) deleteFront(*pL);
        free(*pL);
        *pL = NULL;
    }
}


// Access functions -----------------------------------------------------------

int length(List L) {
    if (L == NULL) {
        printf("List Error: calling length() on NULL List reference\n");
        exit(1);
    }
    return L->length;
}

int index(List L) {
    if (L == NULL) {
        printf("List Error: calling index() on NULL List reference\n");
        exit(1);
    }
    if (L->cursor == NULL) L->index = -1;
    return L->index;
}

int front(List L) {
    if (L == NULL) {
        printf("List Error: calling front() on NULL List reference\n");
        exit(1);
    }
    if (L->length == 0) {
        printf("List Error: calling front() on an empty List\n");
        exit(1);
    }
    return L->front->data;
}

int back(List L) {
    if (L == NULL) {
        printf("List Error: calling back() on NULL List reference\n");
        exit(1);
    }
    if (L->length == 0) {
        printf("List Error: calling back() on an empty List\n");
        exit(1);
    }
    return L->back->data;
}

int get(List L) {
    if (L == NULL) {
        printf("List Error: calling get() on NULL List reference\n");
        exit(1);
    }
    if (L->cursor == NULL) {
        printf("List Error: calling get() on a List with no cursor\n");
        exit(1);
    }
    return L->cursor->data;
}

int equals(List A, List B) {
    Node N = A->front;
    Node M = B->front;
    while (N != NULL && M != NULL && N->data == M->data) {
        N = N->next;
        M = M->next;
    }
    return N == NULL && M == NULL;
}


// Manipulation procedures ----------------------------------------------------

void clear(List L) {
    if (L == NULL) {
        printf("List Error: calling clear() on NULL List reference\n");
        exit(1);
    }
    while (L->length > 0)
        deleteFront(L);
}

void moveFront(List L) {
    if (L == NULL) {
        printf("List Error: calling moveFront() on NULL List reference\n");
        exit(1);
    }
    L->cursor = L->front;
    L->index = 0;
}

void moveBack(List L) {
    if (L == NULL) {
        printf("List Error: calling moveBack() on NULL List reference\n");
        exit(1);
    }
    L->cursor = L->back;
    L->index = L->length - 1;
}

void movePrev(List L) {
    if (L == NULL) {
        printf("List Error: calling movePrev() on NULL List reference\n");
        exit(1);
    }
    if (L->cursor != NULL)
        L->cursor = L->cursor->prev;
    L->index--;
}

void moveNext(List L) {
    if(L == NULL) {
        printf("List Error: calling moveNext() on NULL List reference\n");
        exit(1);
    }
    if (L->cursor != NULL)
        L->cursor = L->cursor->next;
    L->index++;
}

void prepend(List L, int data) {
    if(L == NULL) {
        printf("List Error: calling prepend() on NULL List reference\n");
        exit(1);
    }
    Node N = newNode(data);
    if (L->length == 0)
        L->back = N;
    else {
        L->front->prev = N;
        N->next = L->front;
    }
    L->front = N;
    L->length++;
}

void append(List L, int data) {
    if (L == NULL) {
        printf("List Error: calling append() on NULL List reference\n");
        exit(1);
    }
    Node N = newNode(data);
    if (L->length == 0)
        L->front = N;
    else {
        L->back->next = N;
        N->prev = L->back;
    }
    L->back = N;
    L->length++;
}

void insertBefore(List L, int data) {
    if (L == NULL) {
        printf("List Error: calling insertBefore() on NULL List reference\n");
        exit(1);
    }
    if (L->cursor == NULL) {
        printf("List Error: calling insertBefore() on a List with no cursor\n");
        exit(1);
    }
    Node N = newNode(data);
    if (L->cursor == L->front)
        L->front = N;
    else {
        Node H = L->cursor->prev;
        N->prev = H;
        H->next = N;
    }
    N->next = L->cursor;
    L->cursor->prev = N;
    L->length++;
}

void insertAfter(List L, int data) {
    if (L == NULL) {
        printf("List Error: calling insertAfter() on NULL List reference\n");
        exit(1);
    }
    if (L->cursor == NULL) {
        printf("List Error: calling insertAfter() on a List with no cursor\n");
        exit(1);
    }
    Node N = newNode(data);
    if (L->cursor == L->back)
        L->back = N;
    else {
        Node H = L->cursor->next;
        N->next = H;
        H->prev = N;
    }
    N->prev = L->cursor;
    L->cursor->next = N;
    L->length++;
}

void deleteFront(List L) {
    if (L == NULL) {
        printf("List Error: calling deleteFront() on NULL List reference\n");
        exit(1);
    }
    if (L->length == 0) {
        printf("List Error: calling deleteFront() on empty List\n");
        exit(1);
    }
    Node N = L->front->next;
    freeNode(&(L->front));
    L->front = N;
    if(N != NULL) N->prev = NULL;
    L->length--;
}

void deleteBack(List L) {
    if (L == NULL) {
        printf("List Error: calling deleteBack() on NULL List reference\n");
        exit(1);
    }
    if (L->length == 0) {
        printf("List Error: calling deleteBack() on empty List\n");
        exit(1);
    }
    Node N = L->back->prev;
    freeNode(&(L->back));
    L->back = N;
    if (N != NULL) N->next = NULL;
    L->length--;
}

void delete(List L) {
    if (L == NULL) {
        printf("List Error: calling delete() on NULL List reference\n");
        exit(1);
    }
    if (L->cursor == NULL) {
        printf("List Error: calling delete() on a List with no cursor\n");
        exit(1);
    }
    Node M = L->cursor->next;
    Node J = L->cursor->prev;
    freeNode(&(L->cursor));
    if (M != NULL) M->prev = J;
    if (J != NULL) J->next = M;
    L->length--;
}


// Other operations -----------------------------------------------------------

void printList(FILE* out, List L) {
    if (L == NULL) {
        printf("List Error: calling printList() on NULL List reference\n");
        exit(1);
    }
    if (L->front != NULL) {
        for (Node N = L->front; N->next != NULL; N = N->next)
        fprintf(out, "%d ", N->data);
        fprintf(out, "%d", back(L));
    }
    fprintf(out, "\n");
}

List copyList(List L) {
    List K = newList();
    for (Node N = L->front; N != NULL; N = N->next)
        append(K, N->data);
    return K;
}

List concatList(List A, List B) {
    List C = newList();
    for (moveFront(A); index(A) != -1; moveNext(A)) append(C, get(A));
    for (moveFront(B); index(B) != -1; moveNext(B)) append(C, get(B));
    return C;
}