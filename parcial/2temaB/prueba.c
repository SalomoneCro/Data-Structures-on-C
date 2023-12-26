#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "prueba.h"

struct s_pstack {
    unsigned int size;
    struct s_node * first;
};

struct s_node {
    pstack_elem elem;
    priority_t priority;
    struct s_node * next;
};

static struct s_node * create_node(pstack_elem e, priority_t priority) {
    struct s_node *new_node = NULL;
    new_node = malloc(sizeof(struct s_node));
    assert(new_node!=NULL);
    new_node -> elem = e;
    new_node -> priority = priority;
    new_node -> next = NULL;
    return new_node;
}

static struct s_node * destroy_node(struct s_node *node) {
    assert(node != NULL);
    free(node);
    node = NULL;
    assert(node == NULL);
    return node;
}


static bool invrep(pstack s) {
    unsigned int actual_size = 0;
    // For starters, the stack value shouldn't be null;
    bool valid = (s != NULL);

    struct s_node *curr = s->first;
    while(valid && curr != NULL) {
      // Keep track of size
      ++actual_size;
      // Check order's validity
      valid = curr->next == NULL || curr->priority >= curr->next->priority;
      curr = curr->next;
    }

    return valid && s->size == actual_size;
}

pstack pstack_empty(void) {
    pstack s = malloc(sizeof(struct s_pstack));
    s -> first = NULL;
    s -> size = 0;
    return s;
}

pstack pstack_push(pstack s, pstack_elem e, priority_t priority) {
    assert(invrep(s));
    // New node to add
    struct s_node *new_node = create_node(e, priority);
    // Node to the left
    struct s_node *left;
    // Node to the right
    struct s_node *right;
    left = NULL;
    right = s->first;

    while(right != NULL && new_node->priority < right->priority) {
      left = right;
      right = right->next;
    }

    if(left == NULL) { // No nodes to the left
      // Add at the beginning
      new_node->next = right;
      s->first = new_node;
    } else {
      // Add in between
      left->next = new_node;
      new_node->next = right;
    }
    ++s->size;

    assert(invrep(s));
    return s;
}

bool pstack_is_empty(pstack s) {
    return s -> size == 0;
}

pstack_elem pstack_top(pstack s) {
    assert(invrep(s));
    assert(!pstack_is_empty(s));
    return s -> first -> elem;
}

priority_t pstack_top_priority(pstack s) {
    assert(invrep(s));
    assert(!pstack_is_empty(s));
    return  s -> first -> priority;
}

unsigned int pstack_size(pstack s) {
    assert(invrep(s));
    return s -> size;
}

pstack pstack_pop(pstack s) {
    struct s_node *aux = s -> first;
    s -> first = s -> first -> next;
    destroy_node(aux);
    --s->size;
    assert(invrep(s));
    return s;
}

pstack pstack_destroy(pstack s) {
    assert(invrep(s));
    struct s_node *killme;
    while(s -> first != NULL){
        killme = s -> first;
        s -> first = s -> first -> next;
        killme = destroy_node(killme);
    }
    free(s);
    s = NULL;
    assert(s == NULL);
    return s;
}
