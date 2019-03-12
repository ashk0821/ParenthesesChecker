#define STACK_SIZE 100
#include <stdio.h>

char stack[STACK_SIZE];
int sp=0;


/*
 * Pushes character c onto the stack.
 * Returns 0 if successful.
 * Returns -1 if an error occurs.  (Stack full).
 */
int push (char c)
{
  if (sp < 100) {
    stack[sp] = c;
    sp = sp+1;
    return 0;
  }
  return -1;
}

/*
 * Pops next character off the stack.
 * Returns the char if successful.
 * Returns -1 if an error occurs.  (Stack empty).
 */
int pop ()
{
  if (sp > 0){
    sp=sp-1;
    return stack[sp];
  }
  return -1;
}

/*
 * Returns the current size of the stack.
 */
int stackSize()
{
  return sp;
}

/*
\ * Tests if the stack is correctly implemented
 */
int main (){
  int check = 0;
  char temp;
  int pairing;
  int error_check;
  char mychar = getchar();
  int ln = 1;
  int character = 0;

  while ((mychar != EOF) && (check != -1)) {
    character++;
    if (mychar == 10){
      ln++;
      character = 0;
    }

    if (mychar == '{' || mychar == '(' || mychar == '[') {
      error_check = push(mychar);

      if(error_check == -1){
        printf("Error: Stack Full!");
        check = -1;
      }

    }

    if (check!= -1 && ((mychar == '}') || (mychar == ')') || (mychar == ']'))){

      temp = pop();

      if (temp == -1){
        printf("Error! Line %d, Char %d: found %c. No matching character.", ln, character, mychar);
        check =-1;
      }
      if (check != -1)

        if (((mychar == '}') && (temp != '{')) || ((mychar == ']') && (temp != '[')) || (mychar == ')') &&
        (temp != '(')){
          if (temp == '[')
            pairing = ']';

          else if (temp == '(')
            pairing = ')';

          else if (temp == '{')
            pairing = '}';

          printf ("Line %d, Char %d: found %c, expected %c", ln, character, mychar, pairing);
          check = -1;
        }
    }
    mychar = getchar();
  }

  if ((stackSize() != 0) && (check == 0)){
    temp = pop();

    if (temp == '[')
      pairing = ']';

    if (temp == '(')
      pairing = ')';

    printf("Error! Expecting %c, found end of input.", pairing);
    check = -1;
  }

  if (check == 0) {
    printf("Well formatted input.");
  }
}
