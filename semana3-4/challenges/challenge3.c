/********************************************************************************************
autor: jorge Sierra
materia; Sistemas Operativos
fecha: 18/07/2024
tema: apuntadores c
 ********************************************************************************************/

#include <stdlib.h>
#include <stdio.h>

int main(){
  
  int *ptr,i,n1,n2;
  printf("Enter size: ");
  scanf("%d", &n1);
  ptr=(int*)malloc(n1*sizeof(int));
  printf("Addresses of previusly allocated memory");
  for(i=0; i< n2; i++){
    printf("\n\np 0 %p\n", ptr+i);
  }
  printf("\n Enter the new size: ");
  scanf("%d",&n2);
  ptr = realloc(ptr, n2*sizeof(int));
  printf("Addresses of newly allocated memory: ");
  for(i=0; i< n2; i++)
    printf("\n\np 0 %p\n", ptr+i);
  free(ptr);
  
  
}
