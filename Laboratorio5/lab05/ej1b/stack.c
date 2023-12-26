#include <stdlib.h>
#include <assert.h>
#include "stack.h"

struct _s_stack
{
    int elem;
    struct _s_stack * next;
    unsigned int size;
};

stack stack_empty(){
    return NULL;
}

stack stack_push(stack s, stack_elem e){
    stack p = malloc(sizeof(struct _s_stack));
    p -> next = s;
    p -> elem = e;
    p -> size = s==NULL ? 1 : s -> size + 1;
    return p;
}

stack stack_pop(stack s){
    assert(!stack_is_empty(s));
    stack p = s;
    s = s -> next;
    free(p);
    return s;
}

unsigned int stack_size(stack s){
    return s == NULL ? 0 : s -> size;
}

stack_elem stack_top(stack s){
    assert(!stack_is_empty(s));
    return (s -> elem);
}

bool stack_is_empty(stack s){
    return (s == NULL);
}

stack_elem *stack_to_array(stack s){
     int length = stack_size(s);
    stack_elem * arr = malloc(length * sizeof(struct _s_stack));

    for(int i = length - 1; i >= 0 ; --i){
        arr[i] = s -> elem;
        s = s -> next;
    }

    return arr;
}

stack stack_destroy(stack s){
    stack p;
    while(s!=NULL) {
        p = s;
        s = s -> next;
        free(p);
    }
    return s; 
}





