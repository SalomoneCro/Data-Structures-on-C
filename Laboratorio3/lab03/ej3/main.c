#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

#define MAX_SIZE 1000

static void dump(char a[], unsigned int length) {
    printf("\"");
    for (unsigned int j=0u; j < length; j++) {
        printf("%c", a[j]);
    }
    printf("\"");
    printf("\n\n");
}

unsigned int data_from_file(const char *path, unsigned int indexes[],  char letters[], unsigned int max_size){
    FILE *f;
    f = fopen(path, "r"); 

    unsigned int length = 0u;

    while(length < MAX_SIZE && !feof(f)){
        int res = fscanf(f,"%u -> *%c* \n", &indexes[length], &letters[length]); // el /n (o espacio) al final de lo que escanea es muy importante
        if(res < 2){
            printf("Error de lectura (linea %d)", length);
            exit(EXIT_FAILURE);
        }
        length += 1;
    }
    fclose(f);

    return length;                  
}
// Entender que devolvia fscanf!!!!!!!!!!!!!! controlar que fscanf siemore lea dos elementos
char *parse_filepath(int argc, char *argv[]) {
    /* Parse the filepath given by command line argument. */
    char *result = NULL;
    // Program takes exactly two arguments
    // (the program's name itself and the input-filepath)
    bool valid_args_count = (argc == 2);

    if (!valid_args_count) {
        exit(EXIT_FAILURE);
    }

    result = argv[1];

    return result;
}

void sorter(unsigned int length, unsigned int indexes[], char letters[], char sorted[]){
    for(unsigned int i = 0u; i < length; i = i + 1){
        assert(indexes[i] < MAX_SIZE);
        sorted[indexes[i]] = letters[i];
    }
}

int main(int argc, char *argv[]) {
    unsigned int indexes[MAX_SIZE];
    char letters[MAX_SIZE];
    char sorted[MAX_SIZE];
    char *file;
    unsigned int length=0; 

    file = parse_filepath(argc, argv);
    length = data_from_file(file, indexes, letters, MAX_SIZE);
    sorter(length, indexes, letters, sorted);
    dump(sorted, length);

    return EXIT_SUCCESS;
}

