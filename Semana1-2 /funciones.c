/********************************************************************************************
autor: jorge Sierra
materia; SO
fecha: 25/07/2024
tema: funciones usando .cxx .h 
 ********************************************************************************************/

#include <stdio.h>
#include <math.h>
#include <funciones.h>

void sumarEnteros(){
  float a,b;
  printf("ingrese el primer valor: ");
  scanf("%f",&a);
  printf("ingrese el segundo valor: ");
  scanf("%f",&b);
  printf("La suma de %f y %f sera %f \n", a,b,a+b);
}
void areaCircun(){
  float a,b;
  float pi= 3.14159;
  printf("ingrese el radio para area de cicunferencia: ");
  scanf("%f",&b);
  printf("La area con radio %f sera %f \n", b,b*b*pi);
}
void volumenCIrcu(){
  float a,b;
  float pi= 3.14159;
  printf("ingrese radio para volumen de circunferencia ");
  scanf("%f",&a);
  printf("el volumen con radio %f sera %f \n", a,a*a*a*(4/3)*pi);
}
void volumenCono(){
  float a,b;
  float pi= 3.14159;
  printf("ingrese radio para volumen de cono ");
  scanf("%f",&a);
  printf("ingrese altura para volumen de cono ");
  scanf("%f",&b);
  printf("el volumen con radio %f y altura %f sera %f \n", a,b,((a*a)*b)*pi/3);
}
void hipotenusa(){
  float a,b;
  printf("ingrese cateto opuesto ");
  scanf("%f",&a);
  printf("ingrese cateto adyacente ");
  scanf("%f",&b);
  float potenciaA=pow(a,2);
  float potenciaB=pow(b,2);
  printf("La hipotenusa con cateto opuesto siendo %f y el cateto adyacente  %f sera %f \n", a,b,pow(potenciaA+potenciaB, 1/2));
}
