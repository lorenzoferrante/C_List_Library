#include "list.h"

int main(int argc, char **argv) {
    list l1 = emptyList(), l2 = emptyList();
    int e;
    
    do {
        printf("Introdurre il valore:\t");
        e = getElement();
        if (e != 0)
            l1 = cons(e, l1);
    } while(e != 0);
    
    showList(l1);
    l1 = delete(2, l1);
    showList(l1);
    
    return 0;
}
