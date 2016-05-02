#ifndef LIST_C
#define LIST_C

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* TYPE DEFINITIONS */
typedef int element;

typedef struct list_element {
    element value;
    struct list_element *next;
} item;

typedef item *list;

/* USEFUL FUNCTIONS */
bool isLess(element e1, element e2);
bool isEqual(element e1, element e2);
element copy(element e);
element getElement(void);
void printElement(element e);

/* PRIMITIVES */
list emptyList();
bool empty(list l);
element head(list l);
list tail(list l);
list cons(element e, list l);

/* OTHERS */
void showList(list l);
bool member(element e, list l);
int length(list l);
list append(list l1, list l2);
list delete(element e, list l);
list del_it(element e, list l);

#endif /* LIST_C */
