 /********************************************************************************************
autor: jorge Sierra
materia; Sistemas Operativos
fecha: 3/10/2024
tema: FIFO, el ciente de manera unidiriccional, solo manda mensajes al servidor
 ********************************************************************************************/
    
    
  #include <stdio.h>
  #include <sys/stat.h>
  #include <unistd.h>
  #include <sys/types.h>
  #include <string.h> 
  #include <fcntl.h>
 
#define FIFO_FILE "MYFIFO"  // el nombre de la tuberia donde se van a conectar con el servidor
  int main() {
     int fd;
     int end_process;
     int stringlen;
     char readbuf[80];
     char end_str[5];
     printf("FIFO_CLIENT: Send messages, infinitely, to end enter \"end\"\n");
     fd = open(FIFO_FILE, O_CREAT|O_WRONLY); //se abre la tuberia para escribir
     strcpy(end_str, "end"); //copia un end
  
     while (1) { //ciclo infinito
        printf("Enter string: ");
        fgets(readbuf, sizeof(readbuf), stdin);
        stringlen = strlen(readbuf);
        readbuf[stringlen - 1] = '\0';
        end_process = strcmp(readbuf, end_str);
   
        //printf("end_process is %d\n", end_process);
        if (end_process != 0) {
           write(fd, readbuf, strlen(readbuf));
           printf("Sent string: \"%s\" and string length is %d\n", readbuf, (int)    strlen(readbuf));
        } else {
           write(fd, readbuf, strlen(readbuf));
           printf("Sent string: \"%s\" and string length is %d\n", readbuf, (int)    strlen(readbuf));
           close(fd);
           break;
        }
     }
     return 0;
  }
