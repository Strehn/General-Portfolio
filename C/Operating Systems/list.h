/*Decalring all the structs*/
typedef struct Node node;

struct Node {
    char *item
    node *next;
};

typedef struct List list;

typedef struct List {
    node *head;
};

/*Allocate space for new list*/
list* create_list();

/*Allocate space and set head to NULL*/
int add_to_list(list* ll, char *item);

/* Removes the head from list*/
char* remove_from_list(list* ll);

/*Prints every string in ll*/
void print_list(list *ll);

/*Flush list*/
void flush_list(list *ll);

/*Deallocate memory*/
void free_list(list *ll);
