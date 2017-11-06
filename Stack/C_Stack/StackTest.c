//-----------------------------------------------------------------------------
// StackTest.c
// A test client for Stack ADT
//-----------------------------------------------------------------------------

#include<stdio.h>
#include"Stack.h"

int main(int argc, char* argv[]){
   int i;
   Stack A = newStack();
   Stack B = newStack();

   for(i=1; i<=10; i++){
      push(A, i);
      push(B, 11-i);
   }
   printStack(A);
   printStack(B);
   printf("\n");

   for(i=1; i<=6; i++){
      push(A, getTop(B));
      pop(B);
   }
   printStack(A);
   printStack(B);
   printf("\n");

   printf("%s\n", equals(A,B)?"true":"false");
   printf("%s\n", equals(A,A)?"true":"false");

   freeStack(&A);
   freeStack(&B);

   return(0);
}
