#include <stdio.h>
#define MAX_SIZE 101

void push(int *, int *, int);
void print(int *, int *);
void pop(int *, int *);
int getTop(int*, int*);
int main() {
  int arr[MAX_SIZE];
  int top = -1;
  int *top_ptr = &top;
  push(arr, top_ptr, 1);
  push(arr, top_ptr, 2);
  push(arr, top_ptr, 3);
  pop(arr, top_ptr);
  print(arr, top_ptr);
  int x = getTop(arr, top_ptr);
  printf("%d", x);
}

void push(int *array, int *top_ptr, int x) {
  if (*top_ptr == MAX_SIZE + 1) {
    printf("Stack overflow!");
    return;
  }
  (*top_ptr)++;
  array[*top_ptr] = x;
}

void pop(int *array, int *top_ptr) {
  if (*top_ptr == -1) {
    printf("No element to pop!");
    return;
  }
  (*top_ptr)--;
}

void print(int *array, int *top_ptr) {
  for (int i = 0; i <= *top_ptr; i++) {
    printf("%d ", array[i]);
  }
}

int getTop(int *array, int *top_ptr) { return (array[*top_ptr]); }
