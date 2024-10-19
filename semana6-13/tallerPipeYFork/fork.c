 /********************************************************************************************
autor: jorge Sierra
materia; Sistemas Operativos
fecha: 3/10/2024
tema: el fork(), saber como funciona los fork
 ********************************************************************************************/
    
    
  #include <stdio.h>
  #include <stdlib.h>
  #include <unistd.h>
  #include <sys/types.h>
  
 
 void creacion_fork(int linea){
     pid_t proceso; 
     proceso = fork();
     if(proceso<0){ // si es negativo hay un error
         printf("Error creación proceso\n");
         exit(1);
     }else if (proceso==0)  // si es 0 significa quue el proceso es un hijo
         printf("%d: Proceso =HIJO=: %d\n",linea, getpid());
     else // este else simboliza cuando proceso es positivo, si es positivo significa que es uno, uno representa que es un padre
         printf("%d: Proceso =PADRE= %d\n",linea, getpid());
 }
 
 int main(int argc, char *argv[]){
     int p = (int) atoi(argv[1]);
     for(int i=0; i<p; i++)
         creacion_fork(i);
 

   
     printf("\n---\n\n");
     return 0;
 }
