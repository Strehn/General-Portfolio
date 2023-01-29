int main(int argc, char *argv[]){
    // Variable Declaration
    int addSuccess;

    // ----- TEST create list
    // null starting list
    printf("Testing create list. \n");
    list *null_ll = create_list(); // null list for testing
    list *ll = create_list(); // linked list
    
    // not null starting list
    char *teststring = "teststring";
    node *item; // node list
    item->item = teststring;
    item->next = NULL;
    ll->head = item;
    list *ll = create_list(); // linked list
    free_list(ll);
    
    // ----- TEST add to list
    printf("Testing add to list. \n");
    // null starting list
    addSuccess = add_to_list(ll, item);
    if(addSuccess = 1){
        printf("Unable to add to list. \n");
    }
    // not null starting list
    addSuccess = add_to_list(ll, item);
    if(addSuccess = 1){
        printf("Unable to add to list. \n");
    }
    addSuccess = add_to_list(ll, item);
    if(addSuccess = 1){
        printf("Unable to add to list. \n");
    }

    // ----- TEST flush list
    printf("Testing flush list. \n");
    // null starting list
    flush_list(null_ll);
    // not null starting list
    flush_list(ll);
        // see if we can then readd items to list
    addSuccess = add_to_list(ll, item);
    if(addSuccess = 1){
        printf("Unable to add to list. \n");
    }
    addSuccess = add_to_list(ll, item);
    if(addSuccess = 1){
        printf("Unable to add to list. \n");
    }
    addSuccess = add_to_list(ll, item);
    if(addSuccess = 1){
        printf("Unable to add to list. \n");
    }
    addSuccess = add_to_list(ll, item);
    if(addSuccess = 1){
        printf("Unable to add to list. \n");
    }
    addSuccess = add_to_list(ll, item);
    if(addSuccess = 1){
        printf("Unable to add to list. \n");
    }

    // ----- TEST remove from list
    printf("Testing remove from list. \n");
    // null starting list
    testString = remove_from_list(null_ll);
    // not null starting list
    testString = remove_from_list(ll);
    if(testString != "teststring")
    {
        printf("recieved incorrect value from function: remove from list. \n");
    }
    testString = remove_from_list(ll);
    if(testString != "teststring")
    {
        printf("recieved incorrect value from function: remove from list. \n");
    }

    // ----- TEST print list
    printf("Testing print list. \n");
    // null list
    print_list(null_ll);
    // not null list
    print_list(ll);

    // ----- TEST free list
    printf("Testing free list. \n");
    // null list
    free_list(null_ll);
    // not null list
    free_list(ll);
    
    // ----- re-TEST create list after freeing
    printf("re-Testing create list after freeing lists. \n");
    list *null_ll = create_list(); // null list for testing
    list *ll = create_list(); // linked list
    
    // ----- re-TEST add to list after freeing
    printf("re-Testing add to list after freeing lists. \n");
    // null starting list
    addSuccess = add_to_list(ll, item);
    if(addSuccess = 1){
        printf("Unable to add to list. \n");
    }
    // not null starting list
    addSuccess = add_to_list(ll, item);
    if(addSuccess = 1){
        printf("Unable to add to list. \n");
    }
    addSuccess = add_to_list(ll, item);
    if(addSuccess = 1){
        printf("Unable to add to list. \n");
    }

    // end of tests
    free_list(null_ll);
    free_list(ll);
    
}