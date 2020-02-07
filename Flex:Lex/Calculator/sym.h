#ifndef SYMTBL_H
#define SYMTBL_H


struct sym {
  char * name;
  double value;
  struct sym* next;
} *head;

extern struct sym *head;

void sym_constants( );  
struct sym * sym_lookup(char * s, double x);


#endif /* SYMTBL_H */
