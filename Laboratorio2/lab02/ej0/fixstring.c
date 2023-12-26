#include <stdbool.h>
#include <assert.h>

#include "fixstring.h"

unsigned int fstring_length(fixstring s) {
    unsigned int len = 0;

    while(s[len] != '\0'){
        len += 1;
    }

    return len;
}

bool fstring_eq(fixstring s1, fixstring s2) {
    unsigned int len1, len2;
    unsigned int i = 0;

    len1 = fstring_length(s1);
    len2 = fstring_length(s2);
    
    bool sorted = (len1 == len2);

    while(sorted && i < len1){
        sorted = (s1[i] == s2[i]);
        i += 1;
    }
    
    return sorted;
}

bool fstring_less_eq(fixstring s1, fixstring s2){
    bool less_or_equal = true;
    unsigned int i = 0;

    while(s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0'){
        i += 1;
    }
    
    if(s1[i] > s2[i] && s1[i] != '\0' && s2[i] != '\0'){
        less_or_equal = false;
    }else if(s2[i] == '\0'){
        less_or_equal = false;
    }

    return less_or_equal;
}

