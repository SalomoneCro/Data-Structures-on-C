/*
flag -g  #Se agrega a las lineas de compilacion

DEPURAR PROGRAMA

gdb ./<ejecutable o .o>/grep debug

1- ejecutar el programa siempre con los mismos argumentos: gdb --args ./<nombre ejecutables> <args>
2- ejecutar en programa y decidir los argumentos dentro de gdb: gdb ./ejecutable
    y dentro del gdb al comenzar la ejecucion hacemos run <args>

EJECUTAR UN PROGRAMA DENTRO DEL GDB
run
quit

BREAKPOINTS

break <nombre funcion>
break <archivo>:<nombre funcion>
break <archivo>:<numero de linea>

info <breakpoint_number>
enable <breakpoint_number>
disable <breakpoint_number>
delete <breakpoint_number>

EJECUCION CON RUN

next <- siguiente instruccion
step <- igual que next pero permite entrar dentro de la funcion
continue <- sigue el flujo de ejecucion hasta el proximo brakpoint
finish <- ejecuta hasta finalizar la linea acatual

DONDE ESTOY

where
list <n> o - o <nombre_funcion>

ESTADOS DE VARIABLES

ptype <var>
print <format> <var or expr>

WATCHPOINTS

watch <var>


*/


// tar -czvf lab03_Salomone_Pedro.tar.gz lab03
// tar -xvf lab03_Salomone_Pedro.tar.gz

// $ gcc -Wall -Wextra -pedantic -std=c99 -c helpers.c sort.c main.c
// $ gcc -Wall -Wextra -pedantic -std=c99 helpers.o sort.o main.o -o mysort
// $ ./mysort ../input/atpplayers.in

// $ ./mysort ../input/atpplayers.in > atpplayers.out
// $ diff ../input/atpplayers.in atpplayers.out

// valgrind --leak-check=full ./dispatch_patients example.in
