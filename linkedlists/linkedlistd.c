#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *link;
};

struct Node *head;

void append(int);
void delete (int);
void print(void);
void reverse(void);

int main() {
  head = NULL;
  append(1);
  append(2);
  append(3);
  delete (2);
  reverse();
  print();
}

void append(int data) {
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->link = NULL;
  struct Node *temp = head;
  if (temp == NULL) {

    head = newNode;
    return;
  }

  while (temp->link != NULL) {
    temp = temp->link;
  }
  temp->link = newNode;
}

void delete (int pos) {
  struct Node *temp = head;
  int i;
  for (i = 0; i < pos - 2; i++) {
    temp = temp->link;
  }
  struct Node *temp2 = temp->link;
  temp->link = temp2->link;
  free(temp);
}

void print() {

  struct Node *temp = head;
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->link;
  }
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