#include <fcntl.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

void add_list(char *);

int main() {
  char string[] = "hello";
  add_list(string);
}

void add_list(char *item) {
  struct linked_list {
    char data[30];
    struct linked_list *next_ptr;
  };
  struct linked_list *first_ptr = NULL;
  struct linked_list *new_item_ptr;
  new_item_ptr = malloc(sizeof(struct linked_list));
  strcpy((*new_item_ptr).data, item);
  first_ptr = new_item_ptr;
}