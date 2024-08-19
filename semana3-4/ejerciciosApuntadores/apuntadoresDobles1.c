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
  int *varptr1 = malloc(4*sizeof(int));
  int *varptr2 = malloc(sizeof(int[4]));
  int *varptr3 = malloc(4*sizeof *varptr3);
  
  if(varptr1){
    for(int i =0 ;i<4; i++){
      varptr1[i]=i*i;
    }
    for(int i =0 ;i<4; i++){
      printf("varptr1[%d]\t == %d\n",i, varptr1[i]);
    }
    free(varptr1);
    free(varptr2);
    free(varptr3);
  
    return 0;
  }

  
  
}
