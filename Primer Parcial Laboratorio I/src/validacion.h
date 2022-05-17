#ifndef VALIDACION_H_
#define VALIDACION_H_

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/// @brief Valida que un numero sea flotante
/// @param arrayPosiblesNumeros
/// @return 1 para si y -1 para no
int EsNumeroFlotante(char arrayPosiblesNumeros[]);

/// @brief Valida que un numero sea entero
/// @param arrayPosiblesNumeros
/// @return 1 para si y -1 para no
int EsNumeroEntero(char arrayPosiblesNumeros[]);

/// @brief Valida que un array sea todas letras de la a-z o A-Z
/// @param arrayPosiblesLetras
/// @return 1 para si y -1 para no
int EsChar(char arrayPosiblesLetras[]);

/// @brief Valida que un array sea todas letras de la a-z o A-Z o numero del 1-9
/// @param arrayPosiblesLetras
/// @return 1 para si y -1 para no
int EsCharAndInt(char arrayPosiblesLetras[]);

int EsAlfanumerica(char arrayPosiblesLetras[]);

int EsEmail(char arrayPosiblesLetras[]);

#endif /* VALIDACION_H_ */
