#include "list.h"

struct s_node_t{
    list_elem elem;
    struct s_node_t *next;
};

list empty(){
    return NULL;
}

list addl(list l, list_elem e){
    list q = malloc(sizeof(struct s_node_t));
    q -> elem = e;
    q -> next = l;
    return q; 
}

list addr(list l, list_elem e){
    list p = malloc(sizeof(struct s_node_t));
    p -> elem = e;
    p -> next = NULL;

    if(l != NULL) {
        list q;
        q = l;
        while(q -> next != NULL) {
        q = q -> next;
        }
        q -> next = p;
    } else {
        l = p;
    }

    return l;
}

bool is_empty(list l){
    return l == NULL;
}

list_elem list_index(list l, unsigned int i){
    assert(i < length(l));

    list q;
    q = l;
    unsigned int k = 0;

    while(k < i){
        q = q -> next;
        k = k + 1;
    }

    return q -> elem;
}


void _exhaust_into(list l, list target) {
    list p = l;
    while(p!=NULL) {
        addr(target, p -> elem);
    }
}

list copy(list l){
    list lc = empty();
    _exhaust_into(l, lc);
    return lc;
}


list concat(list l1, list l2){
    list res = empty();
    _exhaust_into(l1, res);
    _exhaust_into(l2, res);
    return res;
}


list tail(list l) {
    assert(!is_empty(l));
    return l -> next;
}

list_elem head(list l) {
    assert(!is_empty(l));
    return l -> elem;
}

unsigned int length(list l) {
    unsigned int res = 0;
    list p = l;
    while(p != NULL) {
        p = p -> next;
        res = res + 1;
    }
    return res;
}

list drop(list l, unsigned int n) {
    assert(n <= length(l));
    while(n > 0) {
        l = l->next;
        n = n - 1;
    }

    return l;
}

list list_destroy(list l) {
    if(l != NULL) {
        list a, b;
        a = l;
        b = a->next;
        while(a != NULL) {
        free(a);
        a = b;
        if(a != NULL) {
            b = a -> next;
        }
        }
        l = a;
    }
    return l;
}