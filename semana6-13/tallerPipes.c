/********************************************************************************************
autor: jorge Sierra
materia; Sistemas Operativos
fecha: 18/07/2024
tema: taller pipes, aca podemos obserbar el comportamiento de los pipes con un ejemplo en los que abren los archivos y hacen una operacion 
 ********************************************************************************************/

#include <stdio.h>        // Biblioteca para operaciones de entrada/salida 
#include <stdlib.h>       // malloc, lo saque de mis proyectos de coccalc
#include <unistd.h>       // 
#include <sys/types.h>    
#include <sys/wait.h>     

int* leer_arreglo(const char* archivo, int n) {
    FILE* file = fopen(archivo, "r");  // Abre el archivo en modo de lectura
    if (file == NULL) {                // si el archivo es nulo hay error
        perror("Error al abrir el archivo"); 
        exit(EXIT_FAILURE);            // Termina el programa si no se puede abrir el archivo
    }


    int* arreglo = (int*) malloc(n * sizeof(int)); // guarda el espacio de memoria para la cantidad de n elementos del arreglo
    if (arreglo == NULL) {             
        perror("Error al asignar memoria"); 
        fclose(file);                  
        exit(EXIT_FAILURE);           
    }


    for (int i = 0; i < n; i++) {
        if (fscanf(file, "%d", &arreglo[i]) != 1) { // lee todo el archivo y si el fscanf devuelve algo que no sea un 1 es que no pudo lee bien
            perror("Error al leer el archivo");     
                               
            fclose(file);   
            free(arreglo);  // Libera la memoria del arreglo
            exit(EXIT_FAILURE);      
        }
    }

    fclose(file);                     // Cierra el archivo
    return arreglo;                  
}


int calcular_suma(int* arreglo, int n) {
    int suma = 0;                    // Inicializa la suma en 0
    for (int i = 0; i < n; i++) {   
        suma += arreglo[i];
    }
    return suma;                     // Devuelve la suma calculada
}

int main(int argc, char* argv[]) {
    if (argc != 5) {                // Verifica que el número de argumentos pasados al programa sea correcto (4 argumentos esperados)
        fprintf(stderr, "Uso: %s N1 archivo00 N2 archivo01\n", argv[0]);  
        exit(EXIT_FAILURE);  
    }
    int N1 = atoi(argv[1]);  // Convierte el primer argumentos a int
    int N2 = atoi(argv[3]); 
                               // lee archivos
    int* arregloA = leer_arreglo(argv[2], N1);  
    int* arregloB = leer_arreglo(argv[4], N2);
     
      

    // Crea tres tuberías 
    int pipeA[2], pipeB[2], pipeC[2];
    if (pipe(pipeA) == -1 || pipe(pipeB) == -1 || pipe(pipeC) == -1) {  // -1 significa que hay error
        perror("Error al crear las tuberías"); 
        exit(EXIT_FAILURE);  
    }

    pid_t pid1, pid2, pid3; 

    pid1 = fork();  // Crea el primer proceso hijo
    
    if (pid1 == 0) { // hijo debe ser igual a 0
        close(pipeA[0]); // Cierra el lado de lectura de la tubería A (solo escribirá), si fuera escritura haria close(tubera[1])
        close(pipeB[0]);
        close(pipeB[1]);
        close(pipeC[0]);
        close(pipeC[1]);
        
        int sumaA = calcular_suma(arregloA, N1);  // Calcula la suma del primer arreglo
        if (write(pipeA[1], &sumaA, sizeof(int)) == -1) {  // Escribe la suma en la tubería A
            perror("Error al escribir en pipeA");  
            exit(EXIT_FAILURE);
        }

        free(arregloA);  
        free(arregloB);  
        exit(0);  
    }

    pid2 = fork();  // Crea el segundo proceso hijo
    
    if (pid2 == 0) {  // Código que ejecuta el segundo hijo
        close(pipeA[1]);
        close(pipeA[0]);
        close(pipeB[0]);
        close(pipeC[0]);
        close(pipeC[1]);
        
        int sumaB = calcular_suma(arregloB, N2);  // Calcula la suma del segundo arreglo
        if (write(pipeB[1], &sumaB, sizeof(int)) == -1) {  // Escribe la suma en la tubería B
            perror("Error al escribir en pipeB"); 
            exit(EXIT_FAILURE);
        }
        close(pipeB[1]);  // Cierra el lado de escritura de la tubería B

        free(arregloA);  
        free(arregloB);  
        exit(0);  
    }

    pid3 = fork();// Crea el tercer proceso hijo (el nieto)
   
    if (pid3 == 0) {  // Código que ejecuta el tercer hijo
        close(pipeA[1]);
        close(pipeB[1]);
        close(pipeC[0]);
        
        int sumaA = calcular_suma(arregloA, N1);  // Calcula la suma del primer arreglo
        int sumaB = calcular_suma(arregloB, N2);  // Calcula la suma del segundo arreglo

        int sumaTotal = sumaA + sumaB;  // Calcula la suma total
        if (write(pipeC[1], &sumaTotal, sizeof(int)) == -1) {  // Escribe la suma total en la tubería C
            perror("Error al escribir en pipeC"); 
            exit(EXIT_FAILURE);
        }

        close(pipeA[0]);  
        close(pipeB[0]);  
        close(pipeC[1]);  
        
        free(arregloA);  
        free(arregloB);  
        exit(0);  // Termina el proceso hijo exitosamente
    }

    // Código que ejecuta el proceso padre
    close(pipeA[1]);  // Cierra el lado de escritura de lastuberias
    close(pipeB[1]); 
    close(pipeC[1]);  

    int sumaA, sumaB, sumaTotal;
    if (read(pipeA[0], &sumaA, sizeof(int)) == -1) {  // Lee la suma de la tubería A
        perror("Error al leer pipeA en el padre");  
        exit(EXIT_FAILURE);
    }
    if (read(pipeB[0], &sumaB, sizeof(int)) == -1) {  // Lee la suma de la tubería B
        perror("Error al leer pipeB en el padre");  
        exit(EXIT_FAILURE);
    }
    if (read(pipeC[0], &sumaTotal, sizeof(int)) == -1) {  // Lee la suma total de la tubería C
        perror("Error al leer pipeC en el padre");  
        exit(EXIT_FAILURE);
    }

    // Mostrar los resultados
    printf("Gran HIJO:\t Suma de A: %d\n", sumaA);  // Imprime la suma del primer arreglo
    printf("SEGUNDO HIJO:\t Suma de B: %d\n", sumaB);  // Imprime la suma del segundo arreglo
    printf("Padre:\t %d\n", sumaTotal); 
    printf("Suma Total:\t %d\n", sumaTotal);  // Imprime la suma total
 

    free(arregloA);  // libera memoria de los arreglos creados
    free(arregloB);  

    return 0;  
}
