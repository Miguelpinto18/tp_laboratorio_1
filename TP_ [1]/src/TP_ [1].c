 /*
 ============================================================================
 Name        : TP1.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*
1. Ingresar Kilómetros: ( km=x)

2. Ingresar Precio de Vuelos: (Aerolíneas=y, Latam=z)

- Precio vuelo Aerolíneas:
- Precio vuelo Latam:

3. Calcular todos los costos:
a) Tarjeta de débito (descuento 10%)
b) Tarjeta de crédito (interés 25%)
c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)
d) Mostrar precio por km (precio unitario)
e) Mostrar diferencia de precio ingresada (Latam - Aerolíneas)
4. Informar Resultados
“Latam:

a) Precio con tarjeta de débito: r
b) Precio con tarjeta de crédito: r
c) Precio pagando con bitcoin : r
d) Precio unitario: r

Aerolíneas:

a) Precio con tarjeta de débito: r
b) Precio con tarjeta de crédito: r
c) Precio pagando con bitcoin : r
d) Precio unitario: r
La diferencia de precio es : r “

5. Carga forzada de datos

6. Salir
 */


#include <stdio.h>
#include <stdlib.h>
#include "calculos.h"


int main(void)
{
	setbuf(stdout,NULL);

	int opcion;
	float kilometros;
	float precioAerolineas;
	float precioLatam;
	float desAerolineas;
	float desLatam;
	float interesAerolineas;
	float interesLatam;
	float bitcoinAerolineas;
	float bitcoinLatam;
	float precioKilometrosAerolineas;
	float precioKilometrosLatam;
	float diferenciaPrecio;


	 do{
		 		opcion = opcionMenu();


		 		switch(opcion)
		 		{
		 			case 1:
		 				printf("\nIngrese Kilometros:");
		 				scanf("%f", &kilometros);


		 			break;

		 			case 2:
		 				printf("\n Ingrese el precio de aerolineas");
		 				scanf("%f", &precioAerolineas);

		 				printf("El precio de aerolineas es: %f \n", precioAerolineas);

		 				printf("\n Ingrese el precio de Latam");
		 				scanf("%f", &precioLatam);

		 				printf("El precio de Latam es: %f \n", precioLatam);
		 			break;

		 			case 3:
		 				desAerolineas = descuentoAerolineas(precioAerolineas);
		 				desLatam = descuentoLatam(precioLatam);

		 				interesAerolineas = interes(precioAerolineas);
		 				interesLatam = interes(precioLatam);

		 				bitcoinAerolineas = bitcoin(precioAerolineas);
		 				bitcoinLatam = bitcoin(precioLatam);

		 				precioKilometrosAerolineas = precioxKilometrosUno(precioAerolineas, kilometros);
		 				precioKilometrosLatam = precioxKilometrosDos(precioLatam, kilometros);

		 				diferenciaPrecio = diferenciaPrecioIngresado(precioAerolineas, precioLatam);

		 			break;

		 			case 4:
		 				printf("Los kilometros son: %f \n", kilometros);
		 				printf("El descuento de Aerolineas es: %f \n", desAerolineas);
		 				printf("El descuento de Latam es: %f \n", desLatam);
		 				printf("El interes de Aerolineas es: %f \n", interesAerolineas);
		 				printf("El interes de Latam es: %f \n", interesLatam);
		 				printf("El precio en Bitcoin de Aerolineas es: %f \n", bitcoinAerolineas);
		 				printf("El precio en Bitcoin de Latam es: %f \n", bitcoinLatam);
		 				printf("El precio por cada kilometros de Aerolineas es: %f \n", precioKilometrosAerolineas );
		 				printf("El precio por cada kilometros de Latam es: %f \n", precioKilometrosLatam);
		 				printf("La diferencia de precio ingresado es: %f \n",diferenciaPrecio);
		 			break;

		 			case 5:
		 				cargaForzada();
		 			break;

		 			default:
		 				break;

		 		}

	 }
	 while(opcion != 6);

	return EXIT_SUCCESS;
}
