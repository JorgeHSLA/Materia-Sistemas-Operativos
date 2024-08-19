/********************************************************************************************
autor: jorge Sierra
materia; Sistemas Operativos
fecha: 8/08/2024
tema: doble apuntadores
 ********************************************************************************************/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

main(){
  int var=480;
  int *varptr = 5;
  int **doubleptr =&varptr;
  printf("valor de la variable \t  %d", var);
  printf("valor del puntero %d", *varptr);
  printf("valor del puntero  dobe \t  %d", **doubleptr);
  
  printf("direccion de variable \t %p", &var );
  printf("direccion de puntero \t %p", varptr );
  
}
