#include <stdlib.h>
#include <stdio.h>

void absolute(int x, int *y) {
    if(x >= 0){
        *y = x;
    }else{
        *y = -x;
    }
}

int main(void) {
    int a=0, res=0;  // No modificar esta declaración
    a = -10;
    absolute(a, &res);
    printf("%i\n", res);
    return EXIT_SUCCESS;
}

// El parametro int *y es de tipo in
// Los parametros de C pueden ser de tipo in/out, in y out