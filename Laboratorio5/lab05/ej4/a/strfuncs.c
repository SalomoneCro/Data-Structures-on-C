#include "strfuncs.h"

size_t string_length(const char *str){

    size_t i = 0;
    while(str[i] != '\0'){
        i++;
    }
    return i;
}

char *string_filter(const char *str, char c){

    size_t bad_length = string_length(str);
    size_t cont = 0;
    char * new_str = malloc((bad_length + 1) * sizeof(char));

    for(size_t i = 0; i < bad_length; i++){

        if(str[i] != c){
            new_str[cont] = str[i];
            cont++;
        }
    }

    new_str = realloc(new_str, cont * sizeof(char));

    return new_str;
}


