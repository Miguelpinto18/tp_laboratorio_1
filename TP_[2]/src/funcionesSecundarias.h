/*
 * funcionesSecundarias.h
 *
 *  Created on: 13 may. 2022
 *      Author: Miguel Pinto
 */

#ifndef FUNCIONESSECUNDARIAS_H_
#define FUNCIONESSECUNDARIAS_H_


/***
 * @fn void convertirPalabraAMayusculas(char*, int);
 * @brief combierte un td el string a mayuscula.
 *
 * @param comprobar: array donde se encuentra el string.
 * @param tam: tamaño del array.
 */
void convertirPalabraAMayusculas(char comprobar[], int tam);

/**
 * @fn void convertirPalabraAMayusculas(char*, int);
 * @brief combierte un td el string a minuscula.
 *
 * @param comprobar: array donde se encuentra el string.
 * @param tam: tamaño del array.
 */
void convertirPalabraAMinusculas(char comprobar[], int tam);

/**
 * @fn float promedio(float, int);
 * @brief calcula el promedio, dividiendo un float sobre un int.
 *
 * @param numeroTotal: el dato tipo float.
 * @param cantidadNumero: el dato tipo int por el cual se va a divir.
 * @return devuelve el promedio.
 */
float promedio(float numeroTotal, int cantidadNumero);


#endif /* FUNCIONESSECUNDARIAS_H_ */
