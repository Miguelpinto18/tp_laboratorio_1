
/*
 * calculos.h
 *
 *  Created on: 15 abr. 2022
 *      Author: Miguel Pinto
 */

#ifndef CALCULOS_H_
#define CALCULOS_H_

/// @brief
///
/// @pre
/// @post
/// @param mensaje
/// @return
int opcionMenu(void);

/// @brief
///
/// @pre
/// @post
/// @param precioAerolineas
/// @return
float descuentoAerolineas(float precioAerolineas);

/// @brief
///
/// @pre
/// @post
/// @param precioLatam
/// @return
float descuentoLatam(float precioLatam);

/// @brief
///
/// @pre
/// @post
/// @param precioAerolineas
/// @return
float interes(float precioAerolineas);

/// @brief
///
/// @pre
/// @post
/// @param precioAerolineas
/// @return
float bitcoin(float precioAerolineas);

/// @brief
///
/// @pre
/// @post
/// @param precioAerolineas
/// @param kilometros
/// @return
float precioxKilometrosUno(float precioAerolineas, float kilometros);

/// @brief
///
/// @pre
/// @post
/// @param precioLatam
/// @param kilometros
/// @return
float precioxKilometrosDos(float precioLatam, float kilometros);

/// @brief
///
/// @pre
/// @post
/// @param precioAerolineas
/// @param precioLatam
/// @return
float diferenciaPrecioIngresado(float precioAerolineas, float precioLatam);

/// @brief
///
/// @pre
/// @post
void cargaForzada(void);


#endif /* CALCULOS_H_ */
