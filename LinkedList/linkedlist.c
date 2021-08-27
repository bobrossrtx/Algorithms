#include <stdio.h>
#include <stdlib.h>

// A doubly linked list node with data and next and prev pointers
typedef struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
} node_t;

// A LinkedList struct with head and tail pointers
struct LinkedList
{
  struct Node *head;
  struct Node *tail;
};

// A function to create a new node with given data
node_t *add_node(int data)
{
  node_t *new_node = (node_t *)malloc(sizeof(node_t));
  new_node->data = data;
  new_node->next = NULL;
  new_node->prev = NULL;

  return new_node;
}

// A function to remove a node from list
void remove_node(node_t *node)
{
  node->prev->next = node->next;
  node->next->prev = node->prev;
  free(node);
}

// A function that prints the linked list
void print_list(struct LinkedList *list)
{
  node_t *temp = list->head;
  while (temp != NULL)
  {
    printf("%#x <- (%#x) %d -> %#x\n", temp->prev, &temp->data, temp->data, temp->next);
    temp = temp->next;
  }
}

int main(int argc, char **argv)
{
  // Initialize a new linked list
  struct LinkedList list;
  list.head = NULL;
  list.tail = NULL;
  int i;
  
  for (i = 0; i < 10; i++)
  {
    // Create a new node with data as i
    node_t *new_node = add_node(i);

    // If the list is empty, set the head to new_node
    if (list.head == NULL)
    {
      list.head = new_node;
      list.tail = new_node;
    }
    // Else set the next pointer of last node to new_node
    else
    {
      list.tail->next = new_node;
      new_node->prev = list.tail;
      list.tail = new_node;
    }
  }

  // Print the list
  print_list(&list);

  // Remove the node with data as 5
  node_t *node = list.head;
  while (node != NULL)
  {
    if (node->data == 5)
    {
      remove_node(node);
      break;
    }
    node = node->next;
  }
  
  // Print the list
  printf("\n");
  print_list(&list);

  return 0;
}