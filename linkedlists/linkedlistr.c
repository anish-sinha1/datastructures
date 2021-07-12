#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *link;
} * head;

struct Node *getNewNode(int);
void append(int);
void delete (int);
void reverse(struct Node *);
void insert(int, int);
void print(void);

int main() {
  head = NULL;
  append(1);
  append(2);
  append(3);
  insert(5, 1);
  reverse(head);
  print();
}

struct Node *getNewNode(int x) {
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = x;
  newNode->link = NULL;
  return newNode;
}

void append(int x) {
  struct Node *newNode = getNewNode(x);
  struct Node *iterator = head;
  if (head == NULL) {
    head = newNode;
    return;
  }
  while (iterator->link != NULL) {
    iterator = iterator->link;
  }
  iterator->link = newNode;
}

void print(void) {
  struct Node *iterator = head;
  while (iterator != NULL) {
    printf("%d ", iterator->data);
    iterator = iterator->link;
  }
}

void insert(int x, int pos) {
  struct Node *newNode = getNewNode(x);
  struct Node *iterator = head;
  if (head == NULL) {
    head = newNode;
    return;
  }
  for (int i = 0; i < pos - 2; i++) {
    iterator = iterator->link;
  }
  struct Node *temp = iterator->link->link;
  newNode->link = iterator->link;
  iterator->link = newNode;
}

void reverse(struct Node *p) {
  if (p->link == NULL) {
    head = p;
    return;
  }
  reverse(p->link);
  struct Node *q = p->link;
  q->link = p;
  p->link = NULL;
}