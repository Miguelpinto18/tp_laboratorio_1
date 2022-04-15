
/*
 * calculos.c
 *
 *  Created on: 15 abr. 2022
 *      Author: Miguel Pinto
 */

#include <stdio.h>
#include <stdlib.h>


int opcionMenu(void)
{
	int opcion;
	printf("\n1.Ingresar Kilómetros:"
			"\n2.Ingresar Precio de Vuelos"
			"\n3.Calcular todos los costos"
			"\n4.Informar Resultados"
			"\n5.Carga forzada de datos"
			"\n6.Salir\n"
			"\nElija una opcion: \n");

	scanf("%d", &opcion);

	return opcion;
}

float descuentoAerolineas(float precioAerolineas)
{
	precioAerolineas = precioAerolineas - (precioAerolineas * 0.10);
	return precioAerolineas;
}

float descuentoLatam(float precioLatam)
{
	precioLatam = precioLatam - (precioLatam * 0.10);
	return precioLatam;
}

float interes(float precioAerolineas)
{
	precioAerolineas = precioAerolineas + precioAerolineas * 0.25;
	return precioAerolineas;
}

float bitcoin(float precioAerolineas)
{
	precioAerolineas = precioAerolineas / 4606954.55;
	return precioAerolineas;
}

float precioxKilometrosUno(float precioAerolineas, float kilometros)
{
	float precioUnitario;

	precioUnitario = precioAerolineas / kilometros;
	return precioUnitario;
}

float precioxKilometrosDos(float precioLatam, float kilometros)
{
	float precioUnitario;

	precioUnitario = precioLatam / kilometros;
	return precioUnitario;
}

float diferenciaPrecioIngresado(float precioAerolineas, float precioLatam)
{
	if(precioAerolineas > precioLatam)
	{
		precioAerolineas = precioAerolineas - precioLatam;
		return precioAerolineas;
	}
	else
	{
		precioLatam = precioLatam - precioAerolineas;
		return precioLatam;
	}

}

void cargaForzada(void)
{
	float kilometros;
	float precioAerolineas;
	float precioLatam;
	float descuentoAerolineas;
	float descuentoLatam;
	float interesAerolineas;
	float interesLatam;
	float bitcoinAerolineas;
	float bitcoinLatam;
	float precioKilometrosAerolineas;
	float precioKilometrosLatam;
	float diferenciaPrecio;

	kilometros = 7090;
	precioAerolineas = 162965;
	precioLatam = 159339;

	descuentoAerolineas = precioAerolineas - (precioAerolineas * 0.10);
	descuentoLatam = precioLatam - (precioLatam * 0.10);

	interesAerolineas = precioAerolineas + (precioAerolineas * 0.25);
	interesLatam = precioLatam + (precioLatam * 0.25);

	bitcoinAerolineas = precioAerolineas / 4606954.55;
	bitcoinLatam = precioLatam / 4606954.55;

	precioKilometrosAerolineas = precioAerolineas / kilometros;
	precioKilometrosLatam = precioAerolineas / kilometros;

	if(precioAerolineas > precioLatam)
		{
			 diferenciaPrecio = precioAerolineas - precioLatam;
		}
		else
		{
			diferenciaPrecio = precioLatam - precioAerolineas;
		}
	printf("Los kilometros son: %f \n", kilometros);
	printf("El descuento de Aerolineas es: %f \n", descuentoAerolineas);
	printf("El descuento de Latam es: %f \n", descuentoLatam);
	printf("El interes de Aerolineas es: %f \n", interesAerolineas);
	printf("El interes de Latam es: %f \n", interesLatam);
	printf("El precio en Bitcoin de Aerolineas es: %f \n", bitcoinAerolineas);
	printf("El precio en Bitcoin de Latam es: %f \n", bitcoinLatam);
	printf("El precio por cada kilometros de Aerolineas es: %f \n", precioKilometrosAerolineas );
	printf("El precio por cada kilometros de Latam es: %f \n", precioKilometrosLatam);
	printf("La diferencia de precio ingresado es: %f \n",diferenciaPrecio);

}
