#include <stdlib.h>
#include <stdio.h>

void absolute(int x, int y) {
    if(x >= 0){
        y = x;
    }else{
        y = -x;
    }
}

int main(void) {
    int a=0, res=0;
    a = -10;
    absolute(a, res);
    printf("%i\n", res);
    return EXIT_SUCCESS;
}

/* Lo mostrado en pantalla no coincide con el programa en el lenguaje teorico, en el programa del
   teorico practico se obtiene el valor absoluto y en este programa se obtiene el valor 0 */

