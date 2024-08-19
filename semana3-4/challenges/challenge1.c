/********************************************************************************************
autor: jorge Sierra
materia; Sistemas Operativos
fecha: 18/07/2024
tema: apuntadores c
 ********************************************************************************************/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main(){
  char *p;
  char *q = NULL;
  printf("Address of p = %s\n", p);
  printf("About to copy\"Goodbye\" to q\n");
  strcpy(q, "Goodbye");
  printf("String copied\n");
  printf("%s\n",q);
         
  return 0;
}
