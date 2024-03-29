#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include "abb.h"

struct _s_abb {
    abb_elem elem;
    struct _s_abb *left;
    struct _s_abb *right;
};

static bool elem_eq(abb_elem a, abb_elem b) {
    return a == b;
}

static bool elem_less(abb_elem a, abb_elem b) {
    return a < b;
}

static bool invrep(abb tree) {
    return tree == NULL ||
    //El arbol de la izquierda es valido
    ((tree->left == NULL || (tree->elem > abb_max(tree -> left) && invrep(tree->left))) && 
    //El arbol de la derecha es valido
    (tree->right == NULL || (tree->elem < abb_min(tree->right) && invrep(tree->right))));
}

abb abb_empty(void) {
    abb tree;
    tree = NULL;
    assert(invrep(tree) && abb_is_empty(tree));
    return tree;
}

//Funcion auxiliar para la funcion abb_add
abb new_leaf(abb_elem e){
    abb new_leaf = malloc(sizeof(struct _s_abb));
    new_leaf->elem = e;
    new_leaf->left = NULL;
    new_leaf->right = NULL;
    return new_leaf;
}

abb abb_add(abb tree, abb_elem e) {
    assert(invrep(tree));
    
    if(!abb_exists(tree, e)){

        if(abb_is_empty(tree)){
            tree = new_leaf(e);
        }else if(elem_less(tree->elem, e)){
            tree -> right = abb_add(tree->right, e);
        }else{
            tree -> left = abb_add(tree->left, e);
        }
    }

    assert(invrep(tree) && abb_exists(tree, e));
    return tree;
}

bool abb_is_empty(abb tree) {
    bool is_empty=false;
    assert(invrep(tree));
    is_empty = (tree == NULL);
    return is_empty;
}

bool abb_exists(abb tree, abb_elem e) {
    bool exists=false;
    assert(invrep(tree));

    if(! abb_is_empty(tree)){
        if(abb_is_empty(tree->left) && abb_is_empty(tree -> right)){
            exists = elem_eq(e, tree->elem);
        }else{
            if(elem_less(e, tree->elem)){
                exists = abb_exists(tree->left, e);
            }else if(elem_less(tree->elem, e)){
                exists = abb_exists(tree->right, e);
            }else{
                exists = elem_eq(e, tree->elem);
            }
        }
    }

    return exists;
}

unsigned int abb_length(abb tree) {
    unsigned int length = 0;
    assert(invrep(tree));
    if(! abb_is_empty(tree)){
        length += 1 + abb_length(tree->left) + abb_length(tree->right);
    }
    assert(invrep(tree) && (abb_is_empty(tree) || length > 0));
    return length;
}

abb abb_remove(abb tree, abb_elem e) {
    assert(invrep(tree));
    
    struct _s_abb **ref = NULL;// Referencia al puntero que enlaza al nodo a borrar
    struct _s_abb **substi;   // Referencia al puntero que enlaza al nodo que reemplazara al borrado
    struct _s_abb *aux;      // Variable auxiliar para las busquedas
    bool keepLooking = true;
    
    if(tree != NULL && abb_exists(tree, e)){
        aux = tree;
        /* Busco el elemento a borrar y una referencia al puntero que lo enlaza */
        while(keepLooking) {
            if(elem_less(e, aux->elem)) {
            ref = &aux->left;
            aux = aux->left; 
            }
            else if(elem_less(aux->elem, e)) {
            ref = &aux->right;
            aux = aux->right; 
            } else {
            keepLooking = false;
            }
        }
        if(ref == NULL) {
            ref = &tree;
        }

        /* Busco el minimo nodo del arbol de la derecha */
        substi = &aux->right;
        aux = aux->right;
        if(aux != NULL) {

            while(aux->left != NULL) {
            substi = &aux->left;
            aux = aux->left;
            }
            // Quitamos el reemplazo del lugar en el que esta
            *substi = aux->right;
        }

        if(aux != NULL) {
            aux->left = (*ref)->left;
            aux->right = (*ref)->right;
        } 
        else {
            /* Si el right es nulo, entonces solo tenemos que poner el 
               izquierdo en el lugar del borrado. */
            aux = (*ref)->left;
        }
        
        if(*ref != NULL) {
            free(*ref);
        }

        *ref = aux;
    }
    assert(invrep(tree) && !abb_exists(tree, e));
    return tree;
}


abb_elem abb_root(abb tree) {
    abb_elem root;
    assert(invrep(tree) && !abb_is_empty(tree));
    root = tree->elem;
    assert(abb_exists(tree, root));
    return root;
}

abb_elem abb_max(abb tree) {
    abb_elem max_e;
    assert(invrep(tree) && !abb_is_empty(tree));
   
    if(abb_is_empty(tree->right)){
        max_e = tree->elem;
    }else{
        max_e = abb_max(tree->right);
    }

    assert(invrep(tree) && abb_exists(tree, max_e));
    return max_e;
}

abb_elem abb_min(abb tree) {
    abb_elem min_e;
    assert(invrep(tree) && !abb_is_empty(tree));

    if(abb_is_empty(tree->left)){
        min_e = tree->elem;
    }else{
        min_e = abb_min(tree->left);
    }

    assert(invrep(tree) && abb_exists(tree, min_e));
    return min_e;
}

void abb_dump(abb tree) {
    assert(invrep(tree));
    if (tree != NULL) {
        abb_dump(tree->left);
        printf("%d ", tree->elem);
        abb_dump(tree->right);
    }
}

abb abb_destroy(abb tree) {
    assert(invrep(tree));

    if(tree != NULL){
        abb_destroy(tree->left);
        abb_destroy(tree->right);
        free(tree);
        tree = NULL;
    }

    assert(tree == NULL);
    return tree;
}