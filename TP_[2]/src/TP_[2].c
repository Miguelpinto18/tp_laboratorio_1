/*
 ============================================================================
 Name        : TP_[2].c
 Author      : Miguel Pinto - DIV D TP2
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*

 1. Enunciado
 Una aerolínea requiere un sistema para administrar los pasajeros de cada
 vuelo. Se sabe que no puede tener más de 2000 pasajeros.

 El sistema deberá tener el siguiente menú de opciones:
 1. ALTAS: Se debe permitir ingresar un pasajero calculando automáticamente el
 número de Id. El resto de los campos se le pedirá al usuario.

 2. MODIFICAR: Se ingresará el Número de Id, permitiendo modificar: o Nombre o Apellido
 o Precio o Tipo de pasajero o Código de vuelo

 3. BAJA: Se ingresará el Número de Id y se eliminará el empleado del sistema.

 4. INFORMAR:
 1. Listado de los pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero.

 2. Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio
 promedio.

 3. Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’
 1-NOTA: Se deberá realizar el menú de opciones y las validaciones a través de funciones.
 Tener en cuenta que no se podrá ingresar a los casos 2, 3 y 4; sin antes haber realizado la
 carga de algún pasajero.

 2-NOTA: Es deseable generar una segunda entidad y utilizarla en el programa.

*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayPassenger.h"
#include "UTN.h"
#define CANTIDAD 2000
#define CARGA 2



int main(void)
{
	setbuf(stdout,NULL);


	Passenger sRegistro[CANTIDAD];
	//Passenger forzado[CARGA];
	Passenger pj;
	int opcion;
	int validacion;
	/*char flyCode[10];

	int statusFlight;
	char namePassenger[51];
	char lastNamePassenger[51];
	 */

	int id;
	id=0;
	validacion=0;
	initPassengers (sRegistro, CANTIDAD);


	do
	{
		opcion = menu();

		if(cantidadPasajeros(sRegistro, CANTIDAD) > 0)
		{
			validacion++;
		}

		switch(opcion)
		{
			case 1:
				id++;
				alta(pj,id,sRegistro,CANTIDAD);
			break;

			case 2:
				if(validacion!=0)
				{
					modificacion(sRegistro,CANTIDAD);

				}
				else
				{
					printf("\nIngrese un pasajero antes\n");
				}
			break;

			case 3:
				if(validacion!=0)
				{
					baja(sRegistro,CANTIDAD);
				}
				else
				{
					printf("\nIngrese un pasajero antes\n");
				}
			break;

			case 4:
				if(validacion!=0)
				{
					informar(sRegistro,CANTIDAD);
				}
				else
				{
					printf("\nIngrese un pasajero antes\n");
				}
			break;

			case 5:
						strcpy(sRegistro[0].name, "Pepe");
						strcpy(sRegistro[0].lastName, "Barili");
						sRegistro[0].price = 15000;
						sRegistro[0].typePassenger = 2;
						strcpy(sRegistro[0].flycode, "latam");
						sRegistro[0].statusFlight = 1;
						sRegistro[0].id = 1000;
						sRegistro[0].isEmpty = 0;


						strcpy(sRegistro[1].name, "Lucas");
						strcpy(sRegistro[1].lastName, "Romero");
						sRegistro[1].price = 15000;
						sRegistro[1].typePassenger = 2;
						strcpy(sRegistro[1].flycode, "latam");
						sRegistro[1].statusFlight = 1;
						sRegistro[1].id = 1200;
						sRegistro[1].isEmpty = 0;


						strcpy(sRegistro[2].name, "Pedro");
						strcpy(sRegistro[2].lastName, "Roldan");
						sRegistro[2].price = 20000;
						sRegistro[2].typePassenger = 3;
						strcpy(sRegistro[1].flycode, "latam");
						sRegistro[2].statusFlight = 1;
						sRegistro[2].id = 1300;
						sRegistro[2].isEmpty = 0;


						strcpy(sRegistro[3].name, "Martin");
						strcpy(sRegistro[3].lastName, "Zalazar");
						sRegistro[3].price = 25000;
						sRegistro[3].typePassenger = 2;
						strcpy(sRegistro[3].flycode, "euro");
						sRegistro[3].statusFlight = 3;
						sRegistro[3].id = 1400;
						sRegistro[3].isEmpty = 0;


						strcpy(sRegistro[4].name, "Vanesa");
						strcpy(sRegistro[4].lastName, "Fernandez");
						sRegistro[4].price = 19000;
						sRegistro[4].typePassenger = 1;
						strcpy(sRegistro[4].flycode, "latam");
						sRegistro[4].statusFlight = 2;
						sRegistro[4].id = 1500;
						sRegistro[4].isEmpty = 0;
			break;

		}

	}while(opcion != 6);


	return EXIT_SUCCESS;
}




