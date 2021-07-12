#include <stdio.h>
#include <stdlib.h>

void insert(int, int); // declares the functions
void print();

struct Node { // Defines the structure for a node
  int data;
  struct Node *next;
};

struct Node *head; // Instantiates the head Node.

int main() {
  head = NULL; // Head initially points to NULL
  insert(2, 1);
  insert(3, 2);
  insert(4, 1);
  insert(5, 2);
  print();
}

void insert(int data, int pos) {
  struct Node *temp1 = (struct Node *)(malloc(
      sizeof(struct Node))); // Creates a Node. malloc allocates the amount of
                             // memory needed for this node
  temp1->data = data;        // Sets the data field of this node to data.
  temp1->next = NULL;        // Sets the next field of this node to NULL
  if (pos == 1) {
    temp1->next = head; // If the insertion position equals one, set the next
                        // field of this newly created node to head.
    head = temp1;       // This node becomes the new head
    return;             // Return from the function early
  }
  struct Node *temp2 = head; // Create another temporary Node for the purposes
                             // for traversing the linked list
  for (int i = 0; i < pos - 2;
       i++) { // Iterate up to the n-2th position, because that means we will be
              // pointing at the n-1th node

    temp2 = temp2->next; // Point this temporary variable at the n-1th node.
  }
  temp1->next = temp2->next; // Set the next field of our created node to the
                             // next field of the temporary node.
  temp2->next =
      temp1; // Set the next field of the n-1th node to the nth node (temp1).
}

void print() { // Print
  struct Node *temp = head;
  while (temp != NULL) {
    printf("%d", temp->data);
    printf("\n");
    temp = temp->next;
  }
}