#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>

/**
 * Structure representing a node in a singly linked list.
 */
struct Node {
    int data;
    struct Node* next;
};

/* --- Function Prototypes --- */

// Utility functions
struct Node* create(int data);
int count(struct Node *head);
void print_data(struct Node *head);

// Insertion functions
void append(struct Node **head, int data);
void prepend(struct Node **head, int data);
void add_at_pos(struct Node *head, int data, int pos);

// Deletion functions
void delete_first(struct Node **head);
void delete_end(struct Node **head);
void delete_at_pos(struct Node **head, int pos);
void delete_whole_list(struct Node **head);

// Transformation functions
void reverse(struct Node **head);

#endif /* LIST_H */