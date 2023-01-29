
#include <stdlib.h>
#include <stdio.h>
#include "list.h"

// ----- Functions -----

/*Allocate space for new list*/
list* create_list(){
    ll = (list*)malloc(sizeof(list));
    ll->head = NULL;
}

/*Allocate space 4 item and add to list*/
int add_to_list(list* ll, char *item){
    // ----- Create the new node ----- 
    node *temp  = (node*)malloc(sizeof(node));
    temp->item = item;
    temp->next = NULL;

    // ----- Add node to list -----
    // case for empty list
    if(ll.head = NULL)
    {
        ll->head = temp;
        return 0;
    }
    else // non empty list, add to end
    {
        node *current = (node*)malloc(sizeof(node));
        current = ll->head;
        node *next = (node*)malloc(sizeof(node));
        next = current->next;
       
        while(next != NULL){// step through list to find end of ll
            current = next;
            next = current->next;
        } 

        next = temp;
        next->next = NULL;
        return 0;
    }
    return 1;
}

/* Removes the head from list*/
char* remove_from_list(list* ll){
    // ----- Remove node from list -----
    node *temp  = (node*)malloc(sizeof(node));
    temp = ll->head;
    char *item = temp->item;

    // case for empty list
    if(ll->head = NULL)
    {
        printf("Nothing in list. \n");
        return '0';
    }
    else // remove head
    {
        temp = temp->next;
        free(ll->head);
        // replace with next list item
        ll->head = temp;
        return item;
    }
}

/*Prints every string in ll*/
void print_list(list *ll){
    // step through list to print nodes data
    node *current = (node*)malloc(sizeof(node));
    current = ll->head;
    node *next = (node*)malloc(sizeof(node));
    next = current->next;

    if(current == NULL){
        printf("Empty List. \n");
    }
    else{
        printf(%s\n, current->item );
        while(next != NULL){
            current = next; 
            next = current->next;
            printf(%s\n, current->item );
        }
    }
}

/*Flush list*/
void flush_list(list *ll){
    // free all data in list 
    free_list(ll);
    // reinitialize list
    ll = create_list(ll);
}

/*Deallocate all data in list*/
void free_list(list *ll){
    // step through list to free nodes
    node *current = (node*)malloc(sizeof(node));
    current = ll->head;
    node *next = (node*)malloc(sizeof(node));
    next = current->next;
    while(next != NULL){
        current = next;
        next = next->next;
        free(current);
    }
    // free the memory for the list itself
    free(ll->head);
    free(ll);
}

