/********************************************************************************************
autor: jorge Sierra
materia; Sistemas Operativos
fecha: 18/07/2024
tema: apuntadores c
 ********************************************************************************************/
#include <stdio.h>
#include <stdio.h>

#define size 10

int main(int argc, char *argv[]){
  int *vectorPunteros[3]; //vector de punteros int
  int p=40, q=80, r=120;
  
  vectorPunteros[0] = &p;
  vectorPunteros[1] = &q;
  vectorPunteros[2] = &r;
  
  printf("\nForma de acceso al vector de punteros: \n");
  for(int i=0; i<3; i++){
    printf("Para la direccion %p \t el valor = %d\n", vectorPunteros[i], *vectorPunteros[i]);
  }
  
  return 0;
}
