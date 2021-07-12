#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *link;
} * head;

void append(int);
void print(void);
void delete (int);
void reverse(void);

int main(int argc, char *argv[]) {
  head = NULL;
  append(1);
  append(2);
  append(3);
  append(4);
  append(5);
  delete (2);
  reverse();
  print();
}

void append(int data) {
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  struct Node *temp = head;
  newNode->data = data;
  newNode->link = NULL;
  if (temp == NULL) {
    head = newNode;
    return;
  }
  while (temp->link != NULL) {
    temp = temp->link;
  }
  temp->link = newNode;
}

void print(void) {
  struct Node *temp = head;
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->link;
  }
}

void delete (int pos) {
  struct Node *temp1 = head;
  for (int i = 0; i < pos - 2; i++) {
    temp1 = temp1->link;
  }
  struct Node *temp2 = temp1->link;
  temp1->link = temp2->link;
  free(temp1);
  temp1 = NULL;
}

void reverse(void) {
  struct Node *current, *prev, *next;
  current = head;
  prev = NULL;
  while (current != NULL) {
    next = current->link;
    current->link = prev;
    prev = current;
    current = next;
  }
  head = prev;
}
