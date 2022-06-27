/*
 * Operaciones.h
 *
 *  Created on: 11 abr 2022
 *      Author: kyubi
 */

#ifndef OPERACIONES_H_
#define OPERACIONES_H_
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Matematica.h"
#include "EntradaYSalida.h"

/// @brief Calcula todos las diferetes formas de pago para los vuelos
/// @param precioVuelo - precio inicial del vuelo
/// @param descuento - % de descuento a realizar (resultado del total en valor decimal // ejemplo: 10% --> 0.9)
/// @param recargo - % de recarga a realizar (resultado del total en valor decimal // ejemplo: 10% --> 1.1)
/// @param ValorOtraMoneda - valor en pesos de otro tipo de moneda (BTC,U$S,etc)
/// @param distancia - distancia que cubre el vuelo
/// @param precioConDescuento - resultado con descuento
/// @param precioConRegargo - resultado con recargo
/// @param precioEnOtraMoneda - costo en otra moneda
/// @param precioXDistancia - costo por km
/// @return
int TodosLosCalculos(float precioVuelo,float descuento,float recargo,float ValorOtraMoneda,float distancia,
	  float *precioConDescuento,float *precioConRegargo,float *precioEnOtraMoneda,float *precioXDistancia);



#endif /* OPERACIONES_H_ */
