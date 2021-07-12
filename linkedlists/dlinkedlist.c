#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *prev;
  struct node *next;
} * head;

struct Node *getNewNode(int);

void insertAtHead(int);

int main() { insertAtHead(1); }

void insertAtHead(int x) {
  struct Node *newNode = getNewNode(x);
  if (head == NULL) {
    head = newNode;
    return;
  }
  head->prev = newNode;
  newNode->next = head;
  head = newNode;
}

struct Node *getNewNode(int x) {
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = x;
  newNode->prev = NULL;
  newNode->next = NULL;
  return newNode;
}