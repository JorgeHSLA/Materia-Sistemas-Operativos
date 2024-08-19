/********************************************************************************************
autor: jorge Sierra
materia; Sistemas Operativos
fecha: 18/07/2024
tema: apuntadores c
 ********************************************************************************************/
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char *function(char*p);

int main(){
  char *a = NULL;
  char *b = NULL;
  a= function("Hi is fun to learn");
  b= function("Systems engineer");

}

char *function(char *p){
  char q[strlen(p)+1];
  strcpy(q,p);
  printf("From q: the stringis %sin", q);
  char * i = q;
  return i;
}
