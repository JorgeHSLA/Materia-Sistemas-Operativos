EL TALLER BIDIRECCIONAL SE BASA EN 2 COSAS: 

Cliente:
      Este manda un mensaje y espera un mensaje del servidor, esta conectado a la misma tubería bidireccional que le servidor
      la tuberia en cuestion se llama:  "/tmp/fifo_twoway"
      

Servidor:
      Este recibe un mensaje y con una función llamada reverse_string la voltea y este nuevo string lo devuelve por la tuberia, la tuberia se llama igual       que la del cliente. 
        
Este laboratorio sirve para mostrar practicamente como funciona las piped named,  recurso importante de los procesos
