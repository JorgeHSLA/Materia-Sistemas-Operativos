/********************************************************************************************
autor: jorge Sierra
materia; Sistemas Operativos
fecha: 18/07/2024
tema: apuntadores c
 ********************************************************************************************/
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]){
  int variable=123;
  int *ptr=&variable;
  printf("Valo de variable %d \n", variable);
  printf("Direccion de memoria d la variable %p \n",&variable);
  printf("Direccion a la que apunta el punteo %p \n", (void*)ptr);
  printf("Valor de la variable %i \n ",*ptr);
  return 0;
}
