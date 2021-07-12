#include <stdio.h>
#include <stdlib.h>

struct Node *getNewNode(int);
void push(int x);
void pop(void);
void print(void);

struct Node {
  int data;
  struct Node *link;
} * top;

int main() {
  top = NULL;
  push(1);
  push(2);
  push(3);
  push(4);
  push(5);
  pop();
  print();
}

void push(int x) {
  struct Node *newNode = getNewNode(x);
  top = newNode;
}

struct Node *getNewNode(int x) {
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = x;
  newNode->link = top;
  return newNode;
}

void pop(void) {
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

void print(void){
    struct Node* temp = top;
    while(temp!= NULL){
        printf("%d ", temp->data);
        temp = temp->link;
    }
}