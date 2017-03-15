//-----------------------------------------------------------------------------
// Stack.h
// Header file for Stack ADT
//-----------------------------------------------------------------------------

#ifndef _STACK_H_INCLUDE_
#define _STACK_H_INCLUDE_


// Exported Type --------------------------------------------------------------
typedef struct StackObj* Stack;


// Constructors-Destructors ---------------------------------------------------

// newStack()
// Returns reference to new empty Stack object.
Stack newStack(void);

// freeStack()
// Frees all heap memory associated with Stack *pS, and sets *pS to NULL.
void freeStack(Stack* pS);


// Access functions -----------------------------------------------------------

// getTop()
// Returns the value at the top of S.
// Pre: !isEmpty(S)
int getTop(Stack S);

// getHeight()
// Returns the height of S
int getHeight(Stack S);

// isEmpty()
// Returns true (1) if S is empty, otherwise returns false (0).
int isEmpty(Stack S);


// Manipulation procedures ----------------------------------------------------

// push()
// Places new data element on top of S
// Post: !isEmpty(S)
void push(Stack S, int data);

// pop()
// Deletes element on top of S
// Pre: !isEmpty(S)
void pop(Stack S);


// Other Functions ------------------------------------------------------------

// printStack()
// Prints data elements in S on a single line to stdout.
void printStack(Stack S);

// equals()
// returns true (1) if Stack A is identical to Stack B, false (0) otherwise.
int equals(Stack A, Stack B);

#endif
