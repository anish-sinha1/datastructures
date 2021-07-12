#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

struct Node *head;

void append(int);
void print();

int main() {
  head = NULL;

  int n, i, x;
  printf("Enter the amount of numbers: ");
  scanf("%d ", &n);
  for (i = 0; i < n; i++) {
    printf("\nEnter a number: ");
    scanf("%d", &x);
    append(x);
    print();
  }
}

void append(int x) {
  struct Node *temp = (struct Node *)(malloc(sizeof(struct Node)));
  temp->data = x;
  temp->next = head;
  head = temp;
}

void print() {
  struct Node *temp = head;
  while (temp != NULL) {
    printf("%d", temp->data);
    temp = temp->next;
  }
}