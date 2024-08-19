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
  int valor1,valor2,*ptrV1,*ptrV2;
  ptrV1 = &valor1;
  ptrV2 = &valor2;
  
  
  printf("\nIngrese dos valores pa sumarlos\n");
  scanf("%d %d",&valor1,&valor2);
  printf("\nla suma es = %d\n", *ptrV1+*ptrV2);
  
  
  return 0;
}
