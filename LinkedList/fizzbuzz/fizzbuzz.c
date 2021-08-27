#include <stdio.h>
#include <stdlib.h>

// A struct that represents a node in a linked list.
struct Node
{
  int data;
  struct Node* next;
};

// A struct that represents a linked list.
struct LinkedList
{
  struct Node* head;
  struct Node* tail;
};

// Fizzbuzz function that takes a linked list as an argument.
void fizzbuzz(struct LinkedList* list)
{
  // Iterate through the linked list.
  struct Node* current = list->head;
  while (current != NULL)
  {
    // If the current node's data is divisible by 3, print "Fizz".
    if (current->data % 3 == 0)
      printf("Fizz%5s|%#4d -> %#x\n", "", current->data, current->next);

    // If the current node's data is divisible by 5, print "Buzz".
    if (current->data % 5 == 0)
      printf("Buzz%5s|%#4d -> %#x\n", "", current->data, current->next);
    
    // If the current node's data is divisible by 3 and 5, print "FizzBuzz".
    if (current->data % 3 == 0 && current->data % 5 == 0)
      printf("FizzBuzz%1s|%#4d -> %#x\n", "", current->data, current->next);
    
    // If the current node's data is not divisible by 3 or 5, print the current node's data
    if (current->data % 3 != 0 && current->data % 5 != 0)
      printf("Null%5s|%#4d -> %#x\n", "", current->data, current->next);

    // Move to the next node.
    current = current->next;
  }
}

int main(int argc, char **argv)
{
  // Create a linked list.
  struct LinkedList list;
  list.head = NULL;
  list.tail = NULL;

  // Add nodes to the linked list.
  int i;
  for (i = 1; i <= 100; i++)
  {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = i;
    node->next = NULL;

    if (list.head == NULL)
      list.head = node;
    else
      list.tail->next = node;
    
    list.tail = node;
  }

  // Print the linked list.
  fizzbuzz(&list);

  // Free the linked list.
  struct Node* current = list.head;
  while (current != NULL)
  {
    struct Node* temp = current;
    current = current->next;
    free(temp);
  }

  return 0;
}
