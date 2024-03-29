#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"
#include "fixstring.h"


static unsigned int partition(fixstring a[], unsigned int izq, unsigned int der) {
    unsigned int i, j, ppiv;
    ppiv = izq;
    i = izq + 1;
    j = der;

    while(i <= j){
        if(goes_before(a[i], a[ppiv])){
            i += 1;
        }else if(goes_before(a[ppiv], a[j])){
            j -= 1;
        }else{
            swap(a,i,j);
        }
    }
    swap(a,ppiv,j);
    ppiv = j;
    return ppiv;
}

static void quick_sort_rec(fixstring a[], unsigned int izq, unsigned int der) {
    unsigned int ppiv = partition(a, izq, der);
    if(der > izq){
        if(ppiv > izq){
            quick_sort_rec(a, izq, ppiv-1);
        }
        if(ppiv < der){
            quick_sort_rec(a, ppiv+1, der);
        }
    }
}

void quick_sort(fixstring a[], unsigned int length) {
    quick_sort_rec(a, 0, (length == 0) ? 0 : length - 1);
}


