/********************************************************************************************
autor: jorge Sierra
materia; Sistemas Operativos
fecha: 8/08/2024
tema: Uso de malloc en codigo de c
 ********************************************************************************************/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

main(){

  // se reserva la memoria de 4 numeros enteros de distintas maneras
  int *varptr1 = malloc(4*sizeof(int));
  int *varptr2 = malloc(sizeof(int[4]));
  int *varptr3 = malloc(4*sizeof *varptr3);
  
  if(varptr1){
    //se rellena ese espacio de 4 numeros 
    for(int i =0 ;i<4; i++){
      varptr1[i]=i*i;
    }
    // se imprimen los 4 numeros guardados 
    for(int i =0 ;i<4; i++){
      printf("varptr1[%d]\t == %d\n",i, varptr1[i]);
    }

    //se libera la memoria de los 3 apuntadores
    free(varptr1);
    free(varptr2);
    free(varptr3);
  
    return 0;
  }

  
  
}
