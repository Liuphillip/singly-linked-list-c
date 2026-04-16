#include "list.h"

int count(struct Node *head){
    int count = 0;
    if(head == NULL){
        printf("list is empty\n");
        return 0;
    }
    struct Node *ptr = NULL;
    ptr = head;
    while(ptr != NULL){
        count++;
        ptr = ptr->next;
    }
    return count;
}

void print_data(struct Node *head){
    if(head == NULL){
        printf("list is empty\n");
        return;
    }
    struct Node *ptr = NULL;
    ptr = head;
    while(ptr != NULL){
        printf("%d, ", ptr->data);
        ptr = ptr->next;
    }
}

void append(struct Node **head, int data){

    if(*head == NULL){
        printf("list is empty\n");
        return;
    }
    struct Node *ptr = NULL;
    struct Node *temp = NULL;

    temp = malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;

    ptr = *head;
    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    ptr->next = temp;
}

void prepend(struct Node **head, int data){
    struct Node *temp = NULL;
    temp = malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;

    temp->next = *head;
    *head = temp;
}

struct Node* create(int data){
    struct Node* temp = malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;

    return temp;
}

void add_at_pos(struct Node *head, int data, int pos){
    if (pos < 0) return;
    int count = 0;
    struct Node *ptr = NULL;
    struct Node *new = malloc(sizeof(struct Node));
    new->data = data;

    ptr = head;
    while(count != (pos-1)){
        if(ptr->next == NULL){
            printf("attempted to place %d and position %d. Invalid, not within range of list\n", data, pos);
            return;
        }
        ptr = ptr->next;
        count++;
    }
    new->next = ptr->next;
    ptr->next = new;
}

void delete_first(struct Node **head){
    if(*head == NULL){
        printf("List is empty");
        return;
    }
    else{
        struct Node * temp = *head;
        *head = (*head)->next;
        free(temp);
        temp = NULL;
    }
}

void delete_end(struct Node **head){
    

    if(*head == NULL){
        printf("list is empty\n");
        return;
    }
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    else{
        struct Node *ptr = *head;

        while(ptr->next->next != NULL){
            ptr = ptr->next;
        }
        free(ptr->next);
        ptr->next = NULL;
    }
    
    
}
void delete_at_pos(struct Node **head, int pos){
    struct Node *ptr = *head;
    if(*head == NULL){
        printf("List is empty.\n");
        return;
    }
    if (pos == 1) {
        *head = ptr->next;
        free(ptr);
        return;
    }

    for (int i = 1; ptr != NULL && i < pos - 1; i++) {
    ptr = ptr->next;
    }

    if (ptr == NULL || ptr->next == NULL) {
        printf("Position out of range.\n");
        return;
    }
    struct Node *target = ptr->next;
    ptr->next = target->next;

    free(target);
    target = NULL;

}
void delete_whole_list(struct Node **head){
    if(head == NULL){
        printf("List is already empty.\n");
        return;
    }

    struct Node *ptr = *head;
    struct Node *temp;

    while(ptr != NULL){
        temp = ptr->next;
        free(ptr);
        ptr = temp;
    }
    *head = NULL;
    
}

void reverse(struct Node **head){
    if(head == NULL){
            printf("List is already empty.\n");
            return;
    }

    struct Node * prev = NULL;
    struct Node * current = *head;
    struct Node * next_node = NULL;

    while(current != NULL){
        next_node = current->next;
        current->next = prev;
        prev = current;
        current = next_node;
    }
    *head = prev;
}