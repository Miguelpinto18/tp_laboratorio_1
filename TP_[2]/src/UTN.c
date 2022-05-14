/*
 * UTN.c
 *
 *  Created on: 13 may. 2022
 *      Author: Miguel Pinto
 */

#include <stdio.h>
#include <stdlib.h>

int menu(void)
{
	int opcion;

	printf("\n Ingrese un numero: \n"
					" 1. ALTAS\n"
					" 2. MODIFICAR\n"
					" 3. BAJA\n"
					" 4. INFORMAR\n"
					" 5. CARGA FORZADA DE DATOS\n"
					" 6. SALIR ");
	scanf("%d", &opcion);

	while(opcion > 6 || opcion < 1)
	{
		printf("Error, vuelva a ingresar un numero valido del 1 al 6");
		scanf("%d", &opcion);
	}

	return opcion;
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "UTN.h"

int UTN_getValidacionMaximoMinimo(int* resultado, char* mensaje,char* mensajeError, int minimo, int maximo)
{
	char array[100];
	int devuelve;

	printf(mensaje);
	fflush(stdin);
	gets(array);

	devuelve=chearLetraint(array,100);

	while(devuelve!=0)
	{
		printf(mensajeError);
		fflush(stdin);
		gets(array);
		devuelve=chearLetraint(array,100);
	}

	*resultado=atoi(array);

	while(*resultado<minimo || *resultado>maximo)
	{
		printf(mensajeError);
		fflush(stdin);
		gets(array);
		devuelve=chearLetraint(array,100);
		while(devuelve!=0)
		{
			printf(mensajeError);
			fflush(stdin);
			gets(array);
			devuelve=chearLetraint(array,100);
		}
		*resultado=atoi(array);
	}
	return 0;
}

int UTN_getValidacionMayorInt(int* resultado, char* mensaje,char* mensajeError, int numero)
{
	char array[100];
	int devuelve;

	printf(mensaje);
	fflush(stdin);
	gets(array);

	devuelve=chearLetraint(array,100);

	while(devuelve!=0)
	{
		printf(mensajeError);
		fflush(stdin);
		gets(array);
		devuelve=chearLetraint(array,100);
	}

	*resultado=atoi(array);

	while(*resultado<numero)
	{
		printf(mensajeError);
		fflush(stdin);
		gets(array);
		devuelve=chearLetraint(array,100);
		while(devuelve!=0)
		{
			printf(mensajeError);
			fflush(stdin);
			gets(array);
			devuelve=chearLetraint(array,100);
		}
		*resultado=atoi(array);
	}
	return 0;
}

int UTN_getValidacionMayorfloat(float* resultado, char* mensaje,char* mensajeError, int numero)
{
	char array[100];
	int devuelve;

	printf(mensaje);
	fflush(stdin);
	gets(array);

	devuelve=chearLetraint(array,100);

	while(devuelve!=0)
	{
		printf(mensajeError);
		fflush(stdin);
		gets(array);
		devuelve=chearLetraint(array,100);
	}

	*resultado=atof(array);

	while(*resultado<numero)
	{
		printf(mensajeError);
		fflush(stdin);
		gets(array);
		devuelve=chearLetraint(array,100);
		while(devuelve!=0)
		{
			printf(mensajeError);
			fflush(stdin);
			gets(array);
			devuelve=chearLetraint(array,100);
		}
		*resultado=atof(array);
	}
	return 0;
}

int UTN_GetValor(char array[], int tam, char* mensaje, char* mensajeError, int conNumero)
{
	int i;
	int devuelve;
	int comprobacion;
	devuelve=-1;
	if(array!=NULL)
	{
		devuelve=0;

		printf(mensaje);
		fflush(stdin);
		gets(array);

		while(strlen(array)>tam)
		{
			printf(mensajeError);
			gets(array);
			fflush(stdin);

		}
		if(conNumero==0)
		{
			do
			{
				for(i=0;i<tam;i++)
				{
					comprobacion= isdigit(array[i]);
					if (comprobacion !=0)
					{
						printf(mensajeError);
						gets(array);
						fflush(stdin);
						break;
					}
				}
			}while(comprobacion!=0);
		}
	}
	return devuelve;
}

int chearLetraint(char* array, int tam)
{
	int resultado;
	int i;

	resultado=-1;
	if(array!=NULL)
	{
		for(i=0;array[i]!='\0';i++)
		{
			resultado=isalpha(array[i]);
			if(resultado!=0)
			{
				break;
			}
		}
	}
	return resultado;
}
