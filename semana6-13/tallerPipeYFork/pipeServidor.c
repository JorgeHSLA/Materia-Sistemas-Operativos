 /********************************************************************************************
autor: jorge Sierra
materia; Sistemas Operativos
fecha: 3/10/2024
tema: FIFO, servidor como el que escucha los mensajes y solo lee de la tuberia
 ********************************************************************************************/
    

 #include <stdio.h>
 #include <sys/stat.h>
 #include <unistd.h>
 #include <sys/types.h>
 #include <string.h> 
 #include <fcntl.h>
 #define FIFO_FILE "MYFIFO"

int main() {
     int fd;
     char readbuf[80];
     char end[10];
     int to_end;
     int read_bytes;
    
     // crea la tuberia
     mknod(FIFO_FILE, S_IFIFO|0640, 0);
     strcpy(end, "end");
 
     while(1) {
        fd = open(FIFO_FILE, O_RDONLY); // abre la tuberia solo para lectura
        read_bytes = read(fd, readbuf, sizeof(readbuf)); // lee la tuberia
        readbuf[read_bytes] = '\0'; //agrega el \0 para crear el string
        printf("Received string: \"%s\" and length is %d\n", readbuf, (int)strlen    (readbuf));
        to_end = strcmp(readbuf, end);
        if (to_end == 0) { // si readbuf es igual a end se terminara y se cerrara la tuebria
           close(fd);
           break;
        }
     }
}
