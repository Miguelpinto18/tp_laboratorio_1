#include <stdio.h>
#include <stdlib.h>
#include "String.h"
#include "LinkedList.h"
#include "Passenger.h"
#include "Parser.h"
#include "menu.h"
#include "input.h"
#include "Controller.h"
#include "UTN.h"


/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(LinkedList* pArrayListPassenger, int* flagCargados)
{
	int retorno=-1;
	char path[100];
	FILE* pArchivo;
	if(*flagCargados ==0)
	{
		PedirString("Ingrese el Path del archivo a cargar: ", path);
		pArchivo=fopen(path,"r");

		if(pArchivo != NULL)
		{
			if(pArrayListPassenger != NULL)
			{
				retorno=parser_PassengerFromText(pArchivo, pArrayListPassenger);
				*flagCargados=1;
			}
			if(retorno>0)
			{
				printf("%d pasajeros no pudieron ser cargados correctamente.\n", retorno);
			}
			else
			{
				printf("Pasajeros cargados correctamente.\n");
			}
		}
		else
		{
			printf("Error al intentar abrir el archivo %s.\n",path);
		}

	}
	else
	{
		printf("Los datos del archivo ya fueron cargados. No puede volver a cargarlos.\n");
	}
	fclose(pArchivo);

    return retorno;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(LinkedList* pArrayListPassenger, int* flagCargados)
{
	int retorno=-1;
	char path[100];
	FILE* pArchivo;
	if(*flagCargados ==0)
	{
		PedirString("Ingrese el Path del archivo a cargar: ", path);
		pArchivo=fopen(path,"rb");

		if(pArchivo != NULL)
		{
			if(pArrayListPassenger != NULL)
			{
				retorno=parser_PassengerFromBinary(pArchivo, pArrayListPassenger);
				*flagCargados=1;
			}
			if(retorno>0)
			{
				printf("%d pasajeros no pudieron ser cargados correctamente.\n", retorno);
			}
			else
			{
				printf("Pasajeros cargados correctamente.\n");
			}
		}
		else
		{
			printf("Error al intentar abrir el archivo %s.\n",path);
		}

	}
	else
	{
		printf("Los datos del archivo ya fueron cargados. No puede volver a cargarlos.\n");
	}
	fclose(pArchivo);

	return retorno;

}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger)
{
	int retorno=-1;
	int id;//int id
	char nombre[50];
	char apellido[50];
	float precio;//float precio;
	char codigoVuelo[10];
	char tipoPasajero[20];
	char statusFlight[20];
	Passenger* pNewPassenger;
	if(pArrayListPassenger != NULL)
	{

	id=CreateNewId("ultimoId.txt");
	PedirStringSinDigitos("Ingrese el nombre del pasajero/a: ", nombre);
	PedirStringSinDigitos("Ingrese el apellido del pasajero/a: ", apellido);
	precio=PedirFlotantePositivoValidandoCaracteres("Ingrese el precio del pasaje: ");
	PedirString("Ingrese el codigo del vuelo: ", codigoVuelo);
	strupr(codigoVuelo);
	MostrarTypePassenger();
	PedirTypePassenger(tipoPasajero);
	MostrarStatusFlight();
	PedirStatusFlight(statusFlight);

	pNewPassenger=Passenger_newParametros(id, nombre, apellido, precio, codigoVuelo, tipoPasajero, statusFlight);
	if(pNewPassenger!=NULL)
	{
		printf("\n El isEmpty del id %d es %d", id, (pNewPassenger->isEmpty));

		ll_add(pArrayListPassenger, pNewPassenger);
		retorno=0;
	}
	}

	//primero passenger_newParametros (lo creo en heap)
	//despues ll_ad lo agrego a la lista
    return retorno;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger)
{
	int chequeo;
	int tam;
	int opcion;
	int i;
	int id;

	if(pArrayListPassenger!=NULL)
	{
		Passenger* pPasajeroModificar=Passenger_new();
		tam=ll_len(pArrayListPassenger);
		do
		{
			UTN_getValidacionMaximoMinimo(&id,"\nIngrese el ID del pasajero que desea modificar: ","ERROR, numero de ID invalido\n"
				"ingrese el ID del pasajero que desea modificar: ",0,tam);
			for(i=0;i<tam;i++)
			{
				pPasajeroModificar=ll_get(pArrayListPassenger,0);
				if(pPasajeroModificar->id==id)
				{
					break;
				}
			}

			if(pPasajeroModificar->isEmpty!=1)
			{
				printf("\nEl pasajero con ID %d se ah eliminado anteriormente\n",id);
			}
		}while(pPasajeroModificar->isEmpty!=1);
		mostrarPasajero(pPasajeroModificar);
//-------------------------------------------MENU DE MODIFICACIONES--------------------------------------------------------------------------------------------------------------------------------
		do{
			UTN_getValidacionMaximoMinimo(&opcion,"\nIngrese un numero \n"
							" 1. para modificar el nombre\n"
							" 2. para modificar el apelllido\n"
							" 3. para modificar el precio\n"
							" 4. para modificar el Codigo de Vuelo \n"
							" 5. para modificar el Tipo de pasajero\n"
							" 6. para modificar el Estado de vuelo\n"
							" 7. salir\n", "\nERROR, Reingrese un numero valido(1-7)\n"
											" 1. para modificar el nombre\n"
											" 2. para modificar el apelllido\n"
											" 3. para modificar el precio\n"
											" 4. para modificar el Codigo de Vuelo \n"
											" 5. para modificar el Tipo de pasajero\n"
											" 6. para modificar el Estado de vuelo\n"
											" 7. salir", 1, 7);
			 switch(opcion)
		      {
				case 1:
					chequeo=modificarNombre(pPasajeroModificar);
					if(chequeo==0)
					{
						printf("\nNo se pudo modificar el nombre\n");
					}
				break;

				case 2:
					chequeo=modificarApellido(pPasajeroModificar);
					if(chequeo==0)
					{
						printf("\nNo se pudo modificar el apellido\n");
					}
				break;

				case 3:
				   chequeo=modificarPrecio(pPasajeroModificar);
				   if(chequeo==0)
				   {
					   printf("\nNo se pudo modificar el precio\n");
				   }
				break;
				case 4:
					chequeo=modificarCodigoVuelo(pPasajeroModificar);
					if(chequeo==0)
				   {
					   printf("\nNo se pudo modificar el codigo de vuelo\n");
				   }
				break;

				case 5:
					chequeo=modificarTipoPasajero(pPasajeroModificar);
					if(chequeo==0)
				    {
					    printf("\nNo se pudo modificar el tipo de pasajero\n");
				    }
				break;

				case 6:
					chequeo=modificarestadoVuelo(pPasajeroModificar);
					if(chequeo==0)
					{
						printf("\nNo se pudo modificar el estado de vuelo\n");
				    }
				break;
		      }

		    }while(opcion != 7);
	}

	return 1;
}

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
	int devuelve;
	int chequeo;
	int tam;
	int i;
	int id;
	devuelve=0;

	if(pArrayListPassenger!=NULL)
	{
		Passenger* pPasajeroModificar=Passenger_new();
		devuelve=1;
		tam=ll_len(pArrayListPassenger);
		do
		{
			UTN_getValidacionMaximoMinimo(&id,"\nIngrese el ID del pasajero que desea eliminar: ","ERROR, numero de ID invalido\n"
				"ingrese el ID del pasajero que desea eliminar: ",0,tam);
			for(i=0;i<tam;i++)
			{
				pPasajeroModificar=ll_get(pArrayListPassenger,i);
				printf("\n El isEmpty del id %d es %d", id, (pPasajeroModificar->isEmpty));
				if(pPasajeroModificar->id==id)
				{
					printf("\n%d", pPasajeroModificar->id);
					break;
				}
			}
			if(pPasajeroModificar->isEmpty!=0)
			{
				printf("\nEl pasajero con ID %d ya habia sido eliminado\n",id);
			}
		}while(pPasajeroModificar->isEmpty!=0);
		chequeo=Passenger_delete(pPasajeroModificar);
		if(chequeo==0)
		{
			printf("\nNo se pudo eliminar el pasajero\n");
		}
		else
		{
			printf("El pasajero se pudo eliminar con exito\n");
		}
		ll_remove(pArrayListPassenger, id);
	}
    return devuelve;
}



/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
	int retorno=-1;
	int len, i;
	Passenger* pAux;

	if(pArrayListPassenger != NULL)
	{

		len=ll_len(pArrayListPassenger);

		printf("ID:     Nombre:              Apellido:                Precio:          Codigo de Vuelo:  Tipo de Pasajero:    Estado de vuelo:\n");//precio, codigoVuelo, tipoPasajero, statusFlight)
		for(i=0;i<len;i++)
		{
			pAux=(Passenger*)ll_get(pArrayListPassenger, i);

			if(pAux->isEmpty == 0)
			{
				Passenger_printOne(pAux);
			}



		}

		retorno=0;
	}
    return retorno;
}


/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
	int retorno=-1;
	int opcion;
	int orden;
	if(pArrayListPassenger !=NULL)
	{
		retorno=0;
		subMenuOrdenar(&opcion);
		switch(opcion)
		{
		case 1:
			orden=PedirOpcionValidandoCaracteres("Ingrese 0 para ordenar de manera Descendente\nIngrese 1 para ordenar de manera Ascendente", 0, 1, "Error. ");
			printf("Ordenando...\n");
			ll_sort(pArrayListPassenger, Passenger_CompareById, orden);
		break;
		case 2:
			orden=PedirOpcionValidandoCaracteres("Ingrese 0 para ordenar de manera Descendente\nIngrese 1 para ordenar de manera Ascendente", 0, 1, "Error. ");
			printf("Ordenando...\n");
			ll_sort(pArrayListPassenger, Passenger_CompareByName, orden);
		break;
		case 3:
			orden=PedirOpcionValidandoCaracteres("Ingrese 0 para ordenar de manera Descendente\nIngrese 1 para ordenar de manera Ascendente", 0, 1, "Error. ");
			printf("Ordenando...\n");
			ll_sort(pArrayListPassenger, Passenger_CompareByLastName, orden);
		break;
		case 4:
			orden=PedirOpcionValidandoCaracteres("Ingrese 0 para ordenar de manera Descendente\nIngrese 1 para ordenar de manera Ascendente", 0, 1, "Error. ");
			printf("Ordenando...\n");
			ll_sort(pArrayListPassenger, Passenger_CompareByPrecio, orden);
		break;
		case 5:
			orden=PedirOpcionValidandoCaracteres("Ingrese 0 para ordenar de manera Descendente\nIngrese 1 para ordenar de manera Ascendente", 0, 1, "Error. ");
			printf("Ordenando...\n");
			ll_sort(pArrayListPassenger, Passenger_CompareByCodigoVuelo, orden);
		break;
		case 6:
			orden=PedirOpcionValidandoCaracteres("Ingrese 0 para ordenar de manera Descendente\nIngrese 1 para ordenar de manera Ascendente", 0, 1, "Error. ");
			printf("Ordenando...\n");
			ll_sort(pArrayListPassenger, Passenger_CompareByTipoPasajero, orden);
		break;
		case 7:
			orden=PedirOpcionValidandoCaracteres("Ingrese 0 para ordenar de manera Descendente\nIngrese 1 para ordenar de manera Ascendente", 0, 1, "Error. ");
			printf("Ordenando...\n");
			ll_sort(pArrayListPassenger, Passenger_CompareByStatusFlight, orden);
		break;
		}

	}

    return retorno;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
	int retorno=-1;
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	char codigoVuelo[10];
	char tipoPasajero[20];
	char statusFlight[20];
	Passenger* pNewPassenger;
	int i;
	int len;
	FILE* pArchivo = fopen(path,"w");

	if(pArrayListPassenger != NULL && pArchivo != NULL)
	{
		len=ll_len(pArrayListPassenger);
		fprintf(pArchivo, "id,name,lastname,price,flycode,typePassenger,statusFlight\n");
		for(i=0; i<len; i++)
		{
			pNewPassenger= (Passenger*)ll_get(pArrayListPassenger, i);
			if(pNewPassenger->isEmpty == 0)
			{
				Passenger_getId(pNewPassenger, &id);
				Passenger_getNombre(pNewPassenger, nombre);
				Passenger_getApellido(pNewPassenger, apellido);
				Passenger_getPrecio(pNewPassenger, &precio);
				Passenger_getCodigoVuelo(pNewPassenger, codigoVuelo);
				Passenger_getTipoPasajero(pNewPassenger, tipoPasajero);
				Passenger_getStatusFlight(pNewPassenger, statusFlight);

				fprintf(pArchivo,"%d,%s,%s,%f,%s,%s,%s\n",id,nombre,apellido,precio,codigoVuelo,tipoPasajero,statusFlight);

			}

		}
		fclose(pArchivo);
		retorno=0;
	}
	return retorno;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
	int retorno=-1;
	Passenger* pNewPassenger;
	int i;
	int len;
	FILE* pArchivo = fopen(path,"wb");

	if(pArrayListPassenger != NULL && pArchivo != NULL)
	{
		len=ll_len(pArrayListPassenger);
		for(i=0; i<len; i++)
		{
			pNewPassenger= (Passenger*)ll_get(pArrayListPassenger, i);

			if(pNewPassenger->isEmpty == 0)
			{
				fwrite(pNewPassenger,sizeof(Passenger),1,pArchivo);
			}

		}
		retorno=0;
	}

    return retorno;
}

