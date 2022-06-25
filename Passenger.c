/*
 * Passenger.c
 *
 *  Created on: 19 may. 2022
 *      Author: Maru
 */
/*${COMMAND} ${FLAGS} ${OUTPUT_FLAG} ${OUTPUT_PREFIX}${OUTPUT} ${INPUTS}${workspace_loc:/${ProjName}}/LinkedList.a*/
#include "Passenger.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "input.h"
#include "UTN.h"

//CONSTRUCTORES - DESTRUCTOR
Passenger* Passenger_new()
{
	Passenger* pNewPassenger = NULL;
	pNewPassenger = (Passenger*) malloc(sizeof(Passenger));

	return pNewPassenger;
}
Passenger* Passenger_newParametros(int id,char* nombre, char* apellido, float precio, char* codigoVuelo, char* tipoPasajero, char* statusFlight)
{
	Passenger* pNewPassenger=Passenger_new();
	if(pNewPassenger !=NULL)
	{
		if(Passenger_setId(pNewPassenger, id)||
		Passenger_setNombre(pNewPassenger, nombre) ||
		Passenger_setApellido(pNewPassenger, apellido) ||
		Passenger_setPrecio(pNewPassenger, precio) ||
		Passenger_setCodigoVuelo(pNewPassenger, codigoVuelo) ||
		Passenger_setTipoPasajero(pNewPassenger, tipoPasajero) ||
		Passenger_setStatusFlight(pNewPassenger, statusFlight) ==-1)
		{
			Passenger_delete(pNewPassenger);
		}
	}

	return pNewPassenger;
}

int Passenger_delete(Passenger* this )
{
	int devuelve=0;
	if(this!=NULL)
	{
		devuelve=1;
		this->isEmpty=1;

		printf("\nEl pasajero:\n\nID:%d \nNombre:%s \nApellido:%s \nPrecio:%f \nCodigo de Vuelo:%s \nTipo de pasajero:%s \nEstado de vuelo:%s\n\nHa sido eliminado",
				this->id,this->nombre,this->apellido,this->precio,this->codigoVuelo,this->tipoPasajero,this->statusFlight);
	}
	return devuelve;
}

// GETTERS - SETTERS
int Passenger_setId(Passenger* this,int id)
{
	int retorno=-1;
	if(this != NULL && id>0)
	{
		retorno=0;
		this->id=id;
	}
	return retorno;
}
int Passenger_getId(Passenger* this,int* id)
{
	int retorno=-1;
	if(this != NULL && id != NULL)
	{
		retorno=0;
		*id=this->id;
	}
	return retorno;
}
int Passenger_setNombre(Passenger* this,char* nombre)
{
	int retorno=-1;
	if(this != NULL && nombre != NULL)
	{
		retorno=0;
		strcpy(this->nombre,nombre);
	}
	return retorno;
}
int Passenger_getNombre(Passenger* this,char* nombre)
{
	int retorno=-1;
	if(this != NULL && nombre != NULL)
	{
		retorno=0;
		strcpy(nombre,this->nombre);
	}
	return retorno;
}

int Passenger_setApellido(Passenger* this,char* apellido)
{
	int retorno=-1;
	if(this != NULL && apellido != NULL)
	{
		retorno=0;
		strcpy(this->apellido,apellido);
	}
	return retorno;
}
int Passenger_getApellido(Passenger* this,char* apellido)
{
	int retorno=-1;
	if(this != NULL && apellido != NULL)
	{
		retorno=0;
		strcpy(apellido,this->apellido);
	}
	return retorno;
}

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int retorno=-1;
	if(this != NULL && codigoVuelo != NULL)
	{
		retorno=0;
		strcpy(this->codigoVuelo,codigoVuelo);
	}
	return retorno;
}
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int retorno=-1;
	if(this != NULL && codigoVuelo != NULL)
	{
		retorno=0;
		strcpy(codigoVuelo,this->codigoVuelo);
	}
	return retorno;
}

int Passenger_setTipoPasajero(Passenger* this,char* tipoPasajero)
{
	int retorno=-1;
	if(this != NULL && tipoPasajero != NULL)
	{
		retorno=0;
		strcpy(this->tipoPasajero,tipoPasajero);
	}
	return retorno;
}
int Passenger_getTipoPasajero(Passenger* this,char* tipoPasajero)
{
	int retorno=-1;
	if(this != NULL && tipoPasajero != NULL)
	{
		retorno=0;
		strcpy(tipoPasajero,this->tipoPasajero);
	}
	return retorno;
}
int Passenger_setPrecio(Passenger* this,float precio)
{
	int retorno=-1;
	if( this != NULL && precio>0)
	{
		retorno=0;
		this->precio=precio;
	}
	return retorno;
}
int Passenger_getPrecio(Passenger* this,float* precio)
{
	int retorno=-1;
	if( this != NULL && precio>0)
	{
		retorno=0;
		*precio=this->precio;
	}
	return retorno;
}

int Passenger_setStatusFlight(Passenger* this,char* statusFlight)
{
	int retorno=-1;
	if(this != NULL && statusFlight != NULL)
	{
		retorno=0;
		strcpy(this->statusFlight,statusFlight);
	}

	return retorno;
}
int Passenger_getStatusFlight(Passenger* this,char* statusFlight)
{
	int retorno=-1;
	if(this != NULL && statusFlight != NULL)
	{
		retorno=0;
		strcpy(statusFlight,this->statusFlight);
	}

	return retorno;
}

int getLastId(char* path, int* id)
{
	int retorno=-1;
	FILE* pArchivoId =fopen(path,"r");
	if(path != NULL && id != NULL && pArchivoId != NULL)
	{
		fscanf(pArchivoId,"%d",id);
		retorno=0;
	}
	return retorno;
}
//LISTAR
int Passenger_printOne(Passenger* this)
{
	int retorno=-1;
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	char codigoVuelo[10];
	char tipoPasajero[20];
	char statusFlight[20];
	if(this != NULL)
	{
		if(!Passenger_getId(this, &id) &&
		!Passenger_getNombre(this, nombre) &&
		!Passenger_getApellido(this, apellido) &&
		!Passenger_getPrecio(this, &precio) &&
		!Passenger_getCodigoVuelo(this, codigoVuelo) &&
		!Passenger_getTipoPasajero(this, tipoPasajero) &&
		!Passenger_getStatusFlight(this, statusFlight))
		{
			printf("%04d    %-20s %-20s %10.2f           %-10s        %-20s %-20s\n", id, nombre, apellido, precio, codigoVuelo, tipoPasajero, statusFlight);
		}
		retorno=0;

	}
	return retorno;
}

//TYPE PASSENGER
void MostrarTypePassenger(void)
{
	printf("Codigo:\tDescripcion:\n");
	printf("1      \tFirstClass\n"
			"2      \tExecutiveClass\n"
			"3      \tEconomyClass\n");
}
int PedirTypePassenger(char* typePassenger)
{
	int retorno=-1;
	int opcion;
	if(typePassenger != NULL)
	{
		opcion=PedirOpcionValidandoCaracteres("Ingrese el Codigo del tipo de pasajero: ", 1, 3, "Error, en número. ");
		switch(opcion)
		{
		case 1:
			strcpy(typePassenger,"FirstClass");
		break;
		case 2:
			strcpy(typePassenger,"ExecutiveClass");
		break;
		case 3:
			strcpy(typePassenger,"EconomyClass");
		break;
		}
	}
	return retorno;
}

//STATUS FLIGHT
void MostrarStatusFlight(void)
{
	printf("CODIGO:\tDESCRIPCION:\n");
	printf("1       Aterrizado\n"
			"2      \tDemorado\n"
			"3      \tEn Horario\n"
			"4      \tEn Vuelo\n");
}
/*	{1, "Aterrizado"},
		{2, "Demorado"},
		{3, "En Horario"},
		{4, "En Vuelo"}*/
int PedirStatusFlight(char* statusFlight)
{
	int retorno=-1;
	int opcion;
	if(statusFlight != NULL)
	{
		opcion=PedirOpcionValidandoCaracteres("Ingrese el Codigo del estado de vuelo: ", 1, 4, "Error, en número. ");
		switch(opcion)
		{
		case 1:
			strcpy(statusFlight,"Aterrizado");
		break;
		case 2:
			strcpy(statusFlight,"Demorado");
		break;
		case 3:
			strcpy(statusFlight,"En Horario");
		break;
		case 4:
			strcpy(statusFlight,"En Vuelo");
		break;
		}
	}
	return retorno;
}

//COMPARES
int Passenger_CompareById(void* p1, void* p2) //unboxing
{
	Passenger* pNewPassenger1;
	Passenger* pNewPassenger2;
	int compara=0;
	pNewPassenger1=(Passenger*)p1;
	pNewPassenger2=(Passenger*)p2;
	int id1;
	int id2;
	Passenger_getId(pNewPassenger1, &id1);
	Passenger_getId(pNewPassenger2, &id2);

	if(id1>id2)
	{
		compara= 1;
	}
	else
	{
		if(id1<id2)
		{
			compara=-1;
		}
	}

	return compara;
}
int Passenger_CompareByName(void* p1, void* p2) //unboxing
{
	Passenger* pNewPassenger1;
	Passenger* pNewPassenger2;
	char nombre1[50];
	char nombre2[50];
	pNewPassenger1=(Passenger*)p1;
	pNewPassenger2=(Passenger*)p2;
	Passenger_getNombre(pNewPassenger1, nombre1);
	Passenger_getNombre(pNewPassenger2, nombre2);

	return strcmpi(nombre1,nombre2);
}
int Passenger_CompareByLastName(void* p1, void* p2) //unboxing
{
	Passenger* pNewPassenger1;
	Passenger* pNewPassenger2;
	char apellido1[50];
	char apellido2[50];
	pNewPassenger1=(Passenger*)p1;
	pNewPassenger2=(Passenger*)p2;
	Passenger_getApellido(pNewPassenger1, apellido1);
	Passenger_getApellido(pNewPassenger2, apellido2);

	return strcmpi(apellido1,apellido2);
}

int Passenger_CompareByPrecio(void* p1, void* p2) //unboxing
{
	Passenger* pNewPassenger1;
	Passenger* pNewPassenger2;
	int compara=0;
	pNewPassenger1=(Passenger*)p1;
	pNewPassenger2=(Passenger*)p2;
	float precio1;
	float precio2;
	Passenger_getPrecio(pNewPassenger1, &precio1);
	Passenger_getPrecio(pNewPassenger2, &precio2);

	if(precio1>precio2)
	{
		compara= 1;
	}
	else
	{
		if(precio1<precio2)
		{
			compara=-1;
		}
	}

	return compara;
}
int Passenger_CompareByCodigoVuelo(void* p1, void* p2)
{
	Passenger* pNewPassenger1;
	Passenger* pNewPassenger2;
	char codigoVuelo1[50];
	char codigoVuelo2[50];
	pNewPassenger1=(Passenger*)p1;
	pNewPassenger2=(Passenger*)p2;
	Passenger_getNombre(pNewPassenger1, codigoVuelo1);
	Passenger_getNombre(pNewPassenger2, codigoVuelo2);

	return strcmpi(codigoVuelo1,codigoVuelo2);
}

int Passenger_CompareByTipoPasajero(void* p1, void* p2)
{
	Passenger* pNewPassenger1;
	Passenger* pNewPassenger2;
	char tipoPasajero1[50];
	char tipoPasajero2[50];
	pNewPassenger1=(Passenger*)p1;
	pNewPassenger2=(Passenger*)p2;
	Passenger_getTipoPasajero(pNewPassenger1, tipoPasajero1);
	Passenger_getTipoPasajero(pNewPassenger2, tipoPasajero2);

	return strcmpi(tipoPasajero1,tipoPasajero2);
}

int Passenger_CompareByStatusFlight(void* p1, void* p2)
{
	Passenger* pNewPassenger1;
	Passenger* pNewPassenger2;
	char statusFlight1[50];
	char statusFlight2[50];
	pNewPassenger1=(Passenger*)p1;
	pNewPassenger2=(Passenger*)p2;
	Passenger_getStatusFlight(pNewPassenger1, statusFlight2);
	Passenger_getStatusFlight(pNewPassenger2, statusFlight2);

	return strcmpi(statusFlight1,statusFlight2);
}

int CreateNewId(char* pathArchivoIds)
{
	int nuevaId=-1;
	FILE* pFileId = fopen(pathArchivoIds, "r");

	if(pFileId != NULL)
	{
		fscanf(pFileId, "%d", &nuevaId);
		nuevaId++;
		fclose(pFileId);

		pFileId = fopen(pathArchivoIds, "w");
		fprintf(pFileId, "%d", nuevaId);
		fclose(pFileId);
	}

	return nuevaId;
}

//---------------------funciones auxiliares------------

int mostrarPasajero(Passenger* pasajero)
{
	int devuelve;
	devuelve=0;
	if(pasajero!=NULL)
	{
		devuelve=1;
		printf("\nID:%d Nombre:%s Apellido:%s Precio:%2.f Codigo de Vuelo:%s Tipo de pasajero:%s Estado de vuelo:%s"
			,pasajero->id,pasajero->nombre,pasajero->apellido,pasajero->precio,pasajero->codigoVuelo,pasajero->tipoPasajero,pasajero->statusFlight);
	}
	return devuelve;
}


int modificarNombre(Passenger* pasajeroModificar)
{
	int devuelve;
	devuelve=0;

	if(pasajeroModificar!=NULL)
	{
		devuelve=1;
		UTN_GetValor(pasajeroModificar->nombre,CARACTERES,"Ingrese el nuevo nombre: ",
			"\nERROR, el nuevo nombre no puede contener numeros o excederse de los 50 caracteres\nIngrese el nuevo nombre: ",0);
		printf("\nEl nuevo nombre es: %s\n",pasajeroModificar->nombre);
	}
	return devuelve;
}

int modificarApellido(Passenger* pasajeroModificar)
{
	int devuelve;
	devuelve=0;

	if(pasajeroModificar!=NULL)
	{
		devuelve=1;
		UTN_GetValor(pasajeroModificar->apellido,CARACTERES,"Ingrese el nuevo apellido: ",
			"\nERROR, el nuevo apellido no puede contener numeros o excederse de los 50 caracteres\nIngrese el nuevo apellido: ",0);
		printf("\nEl nuevo apellido es: %s\n",pasajeroModificar->apellido);
	}
	return devuelve;
}

int modificarPrecio(Passenger* pasajeroModificar)
{
	int devuelve;
	float precio;
	devuelve=0;

	if(pasajeroModificar!=NULL)
	{
		devuelve=1;
		UTN_getValidacionMayorfloat(&precio,"Ingrese el nuevo precio del vuelo: ",
			"\nERROR, el nuevo precio del vuelo no puede contener letras o ser menor a 0\nIngrese el nuevo precio del vuelo: ",0);
		pasajeroModificar->precio=precio;
		printf("\nEl nuevo precio es: %f\n",pasajeroModificar->precio);
	}
	return devuelve;
}

int modificarCodigoVuelo(Passenger* pasajeroModificar)
{
	int devuelve;
	devuelve=0;

	if(pasajeroModificar!=NULL)
	{
		devuelve=1;
		UTN_GetValor(pasajeroModificar->codigoVuelo,7,"Ingrese el nuevo Codigo de Vuelo: ",
			"\nERROR, el nuevo Codigo de Vuelo no excederse de los 7 caracteres\nIngrese el nuevo Codigo de Vuelo: ",1);
		convertirPalabraAMayusculas(pasajeroModificar->codigoVuelo,7);
		printf("\nEl nuevo codigo de vuelo es: %s\n",pasajeroModificar->codigoVuelo);
	}
	return devuelve;
}

int modificarTipoPasajero(Passenger* pasajeroModificar)
{
	int devuelve;
	devuelve = 0;

	if(pasajeroModificar!=NULL)
	{
		devuelve=1;
		UTN_getValidacionMaximoMinimo(&(pasajeroModificar->id),"Ingrese el nuevo tipo de pasajero:(1=FirstClass 2=ExecutiveClass 3=EconomyClass): ",
			"\nERROR, Reingrese un numero valido(1-3)\nIngrese el nuevo tipo de pasajero(1=FirstClass 2=ExecutiveClass 3=EconomyClass): ", 1, 3);
		if(strcmp(pasajeroModificar->tipoPasajero, "FirstClass")==0)
		{
			printf("\nEl nuevo tipo de pasajero es: FirstClass\n");
		}
		if(strcmp(pasajeroModificar->tipoPasajero, "ExecutiveClass")==0)
		{
			printf("\nEl nuevo tipo de pasajero es: ExecutiveClass\n");
		}
		else
		{
			printf("\nEl nuevo tipo de pasajero es: EconomyClass\n");
		}

	}
	return devuelve;
}

int modificarestadoVuelo(Passenger* pasajeroModificar)
{
	int estado;
	int devuelve;
	devuelve=0;

	if(pasajeroModificar!=NULL)
	{
		devuelve=1;
		UTN_getValidacionMaximoMinimo(&estado,"Ingrese el nuevo estado de vuelo(1=Aterrizado 2=En horario 3=Demorado): ",
			"\nERROR, Reingrese solo un numero valido(1-3)\nIngrese el estado de vuelo(1=Aterrizado 2=En horario 3=Demorado): ", 1, 3);
		switch(estado)
		{
			case 1:
				strcpy(pasajeroModificar->statusFlight,"Aterrizado");
				printf("\nEl nuevo estado de vuelo es: Aterrizado\n");
			break;

			case 2:
				strcpy(pasajeroModificar->statusFlight,"En horario");
				printf("\nEl nuevo estado de vuelo es: En horario\n");
			break;

			case 3:
				strcpy(pasajeroModificar->statusFlight,"Demorado");
				printf("\nEl nuevo estado de vuelo es: Demorado\n");
			break;
		}
	}
	return devuelve;
}
