/*******************************************************************
 *
 ** This program uses a stack to reverse a linked list of characters
 *
 * ****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node { // Define the node of the linked list.
  char data;  // Each data part of the node is a character
  struct Node
      *link; // Define the second part of each node as a link to the next node
} * top;     // Define top as a global variable (this could be improved in a
             // production application to be more encapsulated)

struct Node *getNewNode(int); // Define functions
void push(int);
void print(void);
void pop(void);
void reverse(char *);
struct Node *getNewNode(int);

int main() {
  top = NULL;      // Sets top equal to NULL
  char array[100]; // Character array of max length 100. This could be replaced
                   // with a #define
  char *array_ptr =
      array; // creates a pointer to the first element of the character array
  printf("Enter your name: ");
  fgets(array, sizeof(array), stdin); // stores everything in stdin in the array
  reverse(array_ptr);                 // reverses the array
}

struct Node *getNewNode(int x) { // function for creating a new node
  struct Node *newNode = (struct Node *)malloc(
      sizeof(struct Node)); // first, we allocate space in the memory for it
  newNode->data =
      x; // set its data field to whatever is passed into the function
  newNode->link = top; // set its link to point to top.
  return newNode;      // return the newly created node
}

void push(int x) {
  struct Node *newNode = getNewNode(x); // creates a new node
  top = newNode; // sets top equal to the new node. Now, our new node is the
                 // first element in the stack
}

void pop() {          // function to pop elements from the stack
  struct Node *temp;  // creates an iterator variable
  if (temp == NULL) { // if it's null, there's nothing to pop, so return.
    printf("Stack is empty!");
    return;
  }
  temp = top;      // set the temporary node equal to the top
  top = top->link; // top is now what top used to point to
  free(temp);      // deallocate memory for the temporary variable
  temp = NULL; // set the unused pointer to NULL so we can use the memory it was
               // occupying
}

void print(void) {         // function to print each element in the list/stack
  struct Node *temp = top; // create an iterator variable
  while (temp != NULL) {   // iterate over the list
    printf("%c", temp->data); // print every character one by one
    temp = temp->link;        // go to the next character
  }
}

void reverse(char *array) { // function to reverse the list
  for (int i = 0; i < strlen(array);
       i++) { // until iterator variable i is equal to the length of the
              // character array
    push(array[i]); // push every element of the array into it
  }
  print(); // print the array
}