#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node { // Define the structure for a node
  char character;
  struct Node *link;
} * top; // Initialize one called top

struct Node *getNewNode(char); // Define all functions to be used in the program
void push(char);
void pop(void);
void parse(char *);
void print(void);
void reverse(struct Node *);
bool isEmpty(void);

int main() { // main method. Get a string from stdin and parse it.
  top = NULL;
  char string[100];
  char *string_ptr = string;
  printf("Enter an expression to parse: ");
  fgets(string, sizeof(string), stdin);
  parse(string_ptr);
}

struct Node *getNewNode(char character) { // Function for creating a new node
  struct Node *newNode = (struct Node *)(malloc(sizeof(struct Node)));
  newNode->character = character;
  newNode->link = top;
  return newNode;
}

void push(char character) { // Function for pushing a new character to the top
                            // of the stack
  struct Node *newNode = getNewNode(character);
  top = newNode;
}

void pop(void) { // function for popping a node from the stack
  struct Node *temp;
  if (top == NULL) {
    printf("Stack is empty!");
    return;
  }
  temp = top;
  top = top->link;
  free(temp);
  temp = NULL;
}

void print(void) { // function for printing the whole stack. This was more for
                   // debugging than production use
  struct Node *temp = top;
  while (temp != NULL) {
    printf("%c", temp->character);
    temp = temp->link;
  }
}

void parse(char *string) { // function for parsing the string received as an
                           // argument in stdin
  int stringLength = strlen(string);
  if (string[0] == ')' || string[0] == ']' || string[0] == '}') {
    printf("ParseError: Statement begins with invalid token '%c'", string[0]);
    return;
  }
  for (int i = 0; i < stringLength; i++) {

    if (string[i] == '(' || string[i] == '[' || string[i] == '{') {
      push(string[i]);
    } else if (string[i] == ')' || string[i] == ']' || string[i] == '}') {
      if (isEmpty()) {
        printf("ParseError: Unbalanced expression");
      }
      if (string[i] == ')') {
        if (top->character == '(') {
          pop();
        }
      }
      if (string[i] == ']') {
        if (top->character == '[') {
          pop();
        }
      }
      if (string[i] == '}') {
        if (top->character == '{') {
          pop();
        }
      }
    }
  }
  if (isEmpty()) {
    printf("Expression parsed successfully.");
    return;
  }
  printf("ParseError: Invalid token in expression!");
}

void reverse(struct Node *p) { // function for reversing the stack. used only
                               // for debugging purposes
  if (p->link == NULL) {
    top = p;
    return;
  }
  reverse(p->link);
  struct Node *q = p->link;
  q->link = p;
  p->link = NULL;
}

bool isEmpty(void) { // function to check whether the stack is empty
  if (top == NULL) {
    return true;
  }
  return false;
}