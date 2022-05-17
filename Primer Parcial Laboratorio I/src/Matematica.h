#ifndef MATEMATICA_H_
#define MATEMATICA_H_

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/// @brief Realiza el producto, lo devuelve por parametro y retorna si salio bien
/// @param numeroUno - premer valor
/// @param numeroDos - segundo valor
/// @param resultado - resultado de la multiplicacion
/// @return - retorna 1 si se realizo correctamente y 0 para un error
int Multiplicacion(float numeroUno, float numeroDos, float *resultado);

/// @brief Calcula una divicion entre des valores nuemericos
/// @param dividendo
/// @param divisor
/// @param resultado
/// @return - retorna 1 si se realizo correctamente y 0 para un error
int Divicion(float dividendo,float divisor, float* resultado);

/// @brief realiza una suma de dos valores numericos
/// @param num1 - premer valor
/// @param num2 - segundo valor
/// @param resultado - resultado de la suma
/// @return - retorna 1 si se realizo correctamente y 0 para un error
int sumar(float num1, float num2, float* resultado);

/// @brief realiza la diferencia entre 2 calores numericos
/// @param num1 - premer valor
/// @param num2 - segundo valor
/// @param resultado - resultado de la resta
/// @return - retorna 1 si se realizo correctamente y 0 para un error
int resta(float num1, float num2, float* resultado);

/// @brief cacula una regra de tres simple
/// @param numeroA - valor inicial
/// @param numeroB - valor correspondiente al inicial
/// @param numeroC - valor secundario
/// @param resultado - valor correspondiente al secundario que queremos calcular
/// @return - retorna 1 si se realizo correctamente y 0 para un error
int ReglaDeTres(float numeroA, float numeroB, float numeroC, float* resultado);



#endif /* MATEMATICA_H_ */
