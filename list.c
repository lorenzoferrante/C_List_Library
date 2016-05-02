#include "list.h"

/* DEFINING FUNCTIONS */
bool isLess(element e1, element e2) {
    return (e1 < e2);
}

bool isEqual(element e1, element e2) {
    return (e1 == e2);
}

element copy(element e) {
    element e_copy;
    e_copy = e;
    
    return e_copy;
}

element getElement() {
    element new_e;
    scanf("%d", &new_e);
    
    return new_e;
}

void printElement(element e) {
    printf("%d", e);
}

/* DEFINING PRIMITIVES */
list emptyList() {
    return NULL;
}

bool empty(list l) {
    return (l == NULL);
}

element head(list l) {
    if (empty(l)) abort();
    else return l->value;
}

list tail(list l) {
    if(empty(l)) abort();
    else return l->next;
}

list cons(element e, list l) {
    list t;
    t = (list) malloc(sizeof(item));
    t->value = copy(e);
    t->next = l;
    
    return t;
}

/* OTHERS */
void showList(list l) {
    printf("[");
    while (!empty(l)) {
        printElement(l->value);
        l = tail(l);
        if (!empty(l)) printf(", ");
    }
    printf("]\n");
}

bool member(element e, list l) {
    if (empty(l)) abort();
    else {
        while (!empty(l)) {
            if (l->value != e) 
                l = tail(l);
            else return true;        
        }
        return false;
    }
}

int length(list l) {
    int n = 0;
    
    if (empty(l)) return 0;
    else {
        while (!empty(l)) {
            n++;
            l = tail(l);
        }
        return n;
    }
}

list append(list l1, list l2) {
    if (empty(l1)) return l2;
    else {       
        return cons(head(l1), append(tail(l1), l2));
    }
}

list delete(element e, list l) {
    if (empty(l)) return emptyList();
    else {
        if(isEqual(e, head(l))) return tail(l);
        else return cons(head(l), delete(e, tail(l)));
    }
}
