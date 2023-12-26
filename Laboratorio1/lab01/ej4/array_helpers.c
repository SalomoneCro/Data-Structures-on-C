/* First, the standard lib includes, alphabetically ordered */
#include <assert.h>
#include "array_helpers.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

unsigned int array_from_file(int array[], unsigned int max_size, const char *filepath) {
    // open the file
    FILE *f;
    f = fopen(filepath, "r");
    // get its size
    unsigned int length;
    fscanf(f, "%u", &length);

    // cut the length if the files is longer than the max size
    if(max_size < length){
        length = max_size;
    }

    // Read and append the elements
    for(unsigned int i=0;i<length;i++){
        fscanf(f, "%d", &array[i]);
    }
    fclose(f);
    return length;

}

void array_dump(int a[], unsigned int length) {
    printf("[");
    for(unsigned int i=0; i<length; i++){
    if(i != length-1 ){
        printf(" %d,", a[i]);
    }
    else {
        printf(" %d", a[i]);
    }
  }
  printf("]\n");
}

bool array_is_sorted(int a[], unsigned int length){
  bool is_ord;
  is_ord = true;
  for(unsigned int i=1; i<length; i++){
    if(a[i] < a[i-1]){
        is_ord = false;
        break;
    }
  }
  return is_ord;
}