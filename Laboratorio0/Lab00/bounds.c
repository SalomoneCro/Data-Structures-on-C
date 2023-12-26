#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define ARRAY_SIZE 4

struct bound_data {
    bool is_upperbound;
    bool is_lowerbound;
    bool exists;
    unsigned int where;
};

struct bound_data check_bound(int value, int arr[], unsigned int length) {
    struct bound_data res;
    unsigned int i;
    int count1, count2;
    count1 = 0;
    count2 = 0;

    //Inicializo esta variable con este valor para ahorrarme ifs y acortar el codigo
    res.exists = false;

    for(i=0; i<length; i++){

        if (arr[i] <= value){
            count1 += 1;
        }

        if (arr[i] >= value){
            count2 += 1;
        } 
        
        if (arr[i] == value){
            res.exists = true;
            res.where = i;
        }
    }   

    if (count1 == 4){
        res.is_upperbound = true; 
    }else{
        res.is_upperbound = false;
    }
    if (count2 == 4){
        res.is_lowerbound = true;  
    }else{
        res.is_lowerbound = false;
    }

    return res;
}

int main(void) {
    int a[ARRAY_SIZE] = {0, -1, 9, 4};
    int value=9;
    int i;
    printf("Ingrese los cuatro elementos de la lista separados por un espacio: ");
    for(i=0; i<ARRAY_SIZE; i++){
        scanf("%i", &a[i]);
    }
    printf("Ingrese un valor: ");
    scanf("%i", &value);

    struct bound_data result = check_bound(value, a, ARRAY_SIZE);

    //max
    if(result.is_upperbound == 1 && result.exists == 1){
        printf("El valor que ingresó el usuario es un maximo, el cual esta en la posicion %d\n", result.where);
    }else if(result.is_lowerbound == 1 && result.exists == 1){
        printf("El valor que ingresó el usuario es un minimo, el cual esta en la posicion %d\n", result.where);
    }else if(result.is_upperbound == 1 && result.exists == 0){
        printf("El valor que ingresó el usuario es una cota superior\n");
    }else if(result.is_lowerbound == 1 && result.exists == 0){
        printf("El valor que ingresó el usuario es una cota inferior\n");
    }
    return EXIT_SUCCESS;
}