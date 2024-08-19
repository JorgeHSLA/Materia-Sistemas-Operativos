/********************************************************************************************
autor: jorge Sierra
materia; Sistemas Operativos
fecha: 18/07/2024
tema: integracion con el lenguaje de c
 ********************************************************************************************/
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]){
  int x;
  int suma = 0;
  do{
    scanf("%d", &x);
    suma += x;
  } while(x!=0);
  printf("La suma es: %d \n", suma);
  return 0;

}
