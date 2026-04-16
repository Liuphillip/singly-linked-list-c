#include <stdio.h>
#include "list.h"

int main(){
     // Initialize the list
    struct Node *list = create(6);

    // Adding elements
    add_at_pos(list, 15, 1);
    add_at_pos(list, 15, 2);
    add_at_pos(list, 22, 3);
    
    append(&list, 3);
    append(&list, 4);

    // Initial display
    printf("Original List: ");
    print_data(list);
    printf("\nNode count: %d\n", count(list));

    // Transformation
    reverse(&list);

    // Final display
    printf("Reversed List: ");
    print_data(list);
    printf("\nNode count: %d\n", count(list));

    // Clean up memory before exiting
    delete_whole_list(&list);


    return 0;
}
