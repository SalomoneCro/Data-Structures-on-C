#include <stdlib.h>
#include <assert.h>
#include "stack.h"

struct _s_stack
{
    int elem;
    struct _s_stack * next;
};

stack stack_empty(){
    return NULL;
}

stack stack_push(stack s, stack_elem e){
    stack p = malloc(sizeof(struct _s_stack));
    p -> next = s;
    p -> elem = e;
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
    unsigned int count = 0u;
    
    for(stack p = s; p != NULL; p = p -> next){
        count += 1;
    }

    return count;
}

stack_elem stack_top(stack s){
    assert(!stack_is_empty(s));
    return (s -> elem);
}

bool stack_is_empty(stack s){
    return (s == NULL);
}

stack_elem *stack_to_array(stack s){
    unsigned int length = stack_size(s);
    stack_elem * arr = malloc(length * sizeof(struct _s_stack));
    stack p = s;

    for(unsigned int i = 0u; i < length; i++){
        arr[length - 1 - i] = p -> elem;
        p = p -> next;
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





