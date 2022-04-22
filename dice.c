#include <pic14/pic12f675.h>

typedef unsigned int word;
word __at 0x2007 __CONFIG =(_MCLRE_OFF & _WDT_OFF & _INTRC_OSC_NOCLKOUT);//desactivar WDT y MCLRE

 
void delay (unsigned inttiempo);
 
void main(void)
{
	ANSEL = 0; //Necesario al utilizar un PIN como entrada.
    TRISIO = 0b00100000; //Poner todos los pines como salidas y el segundo PIN (GP5) como entrada (fuente)
	GPIO = 0x00; //Poner pines en bajo
 
    unsigned int tiempo = 100; //for delay

	// Random number:
	// un contador por escenario (1 LED, 2 LED...)
	int contador0 = 0;
	int contador1 = 0;
	int contador2 = 0;
	int contador3 = 0;
	int contador4 = 0;
	int contador5 = 0;
 
    //Loop forever
    while ( 1 )
    {
		// Se configuran los parametros los contadores
		contador0 = contador0;	
		contador1 = contador1 + 1;	
		contador2 = contador2 + 2;
		contador3 = contador3 + 3;
		contador4 = contador4 + 4;	
		contador5 = contador5 + 5;

		if (GP5==0) // Para cuando se activa el boton
		{	
			// Manejo del número aleatorio:
			// se vuelven a modificar para crear nuevos números
				contador0 = contador0 + 6;
				contador1 = contador1 + 5;	
				contador2 = contador2 + 4;
				contador3 = contador3 + 3;
				contador4 = contador4 + 2;	
				contador5 = contador5 + 1;

			// Lógica para encender LEDs de acuerdo al valor de los contadores.
			// Si el contador es mayor a todos los demas se enciende el respectivo LED

			if (contador0>contador1 & contador0>contador2 & contador0>contador3 & contador0>contador4 & contador0>contador5 ) // se enciende 1 LED
			{
				GP2 = ~GP2;	//cambio de estado
				contador0 = 0; // reset del contador

			}

			if (contador1>contador0 & contador1>contador2 & contador1>contador3 & contador1>contador4 & contador1>contador5) // se encienden 2 LEDs
			{
			
				GP1 = ~GP1;
				delay(tiempo);
				contador1 = 0;
			}

			if (contador2>contador1 & contador2>contador0 & contador2>contador3 & contador2>contador4 & contador2>contador5) // se encienden 3 LEDs						
			{

				GP2 = ~GP2;
				GP1 = ~GP1;
				delay(tiempo);
				contador2 = 0;
			}

			if (contador3>contador1 & contador3>contador2 & contador3>contador0 & contador3>contador4 & contador3>contador5) // se encienden 4 LEDs
			{

				GP1 = ~GP1;
				GP0 = ~GP0;
				delay(tiempo);
				contador3 = 0;
			}

			if (contador4>contador1 & contador4>contador2 & contador4>contador3 & contador4>contador0 & contador4>contador5) // se encienden 5 LEDs
			{

				GP2 = ~GP2;
				GP1 = ~GP1;
				GP0 = ~GP0;
				delay(tiempo);
				contador4 = 0;	
			}

			if (contador5>contador1 & contador5>contador2 & contador5>contador3 & contador5>contador4 & contador5>contador0) //se encienden 6 LEDs
			{

				
				GP2 = ~GP2;
				GP1 = ~GP1;
				GP0 = ~GP0;
				GP4 = ~GP4;
				delay(tiempo);
				contador5 = 0;
				
			}
		}
	}
 
}

void delay(unsigned int tiempo)
{
	unsigned int i;
	unsigned int j;

	for(i=0;i<tiempo;i++)
	  for(j=0;j<1275;j++);
}
