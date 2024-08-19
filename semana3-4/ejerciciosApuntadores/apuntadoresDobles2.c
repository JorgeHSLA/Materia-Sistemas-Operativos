/********************************************************************************************
autor: jorge Sierra
materia; Sistemas Operativos
fecha: 8/08/2024
tema: doble apuntadores
 ********************************************************************************************/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main(){
  int *vP1 = calloc(4*sizeof(int));
  int *vP2 = calloc(sizeof(int[4]));
  int *vP3 = calloc(4*sizeof *varptr3);
  
  if(vP2){
    
    for(int i =0 ;i<4; i++){
      printf("varptr1[%d]\t == %d\n",i, vP2[i]);
    }
    free(vP1);
    free(vP2);
    free(vP3);
  
    return 0;
  }
