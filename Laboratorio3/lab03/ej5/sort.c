/*
  @file sort.c
  @brief sort functions implementation
*/

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "helpers.h"
#include "sort.h"
#include "player.h"

bool goes_before(player_t x, player_t y){
    return (x.rank <= y.rank);
}

bool array_is_sorted(player_t atp[], unsigned int length) {
    unsigned int i = 1u;
    while (i < length && goes_before(atp[i - 1u], atp[i])) {
        i++;
    }
    return (i == length);
}

void swap(player_t a[], unsigned int j, unsigned int i){
    player_t tmp;
    tmp = a[j];
    a[j] = a[i];
    a[i] = tmp;
}

void sort(player_t a[], unsigned int length){

    for(unsigned int i = 0; i < length - 1; i++){
        int k;
        player_t mejor = a[i];
        for(unsigned int j = i; j < length; j++){
            if (goes_before(a[j + 1], mejor)){
                mejor = a[j + 1]; 
                k = j + 1;
            }
        }
        if(mejor.rank < a[i].rank){
            swap(a, i, k);
        }
    }
}

