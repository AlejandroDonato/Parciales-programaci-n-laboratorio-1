#ifndef ENTRADAYSALIDA_H_
#define ENTRADAYSALIDA_H_
#include "Matematica.h"
#include "validacion.h"



/// @brief Pide un numero entero al usuario dentro de un rango y verifica que sea correcto, con x reintentos
/// @param mensaje - mensaje para el usuario solicitandole el numero
/// @param reintentos - cantidad de reintentos
/// @param minimo - valor minimo del rango
/// @param maximo - valor maximo del rango
/// @param mensajeError - mensaje de error
/// @param pNumeroIngresado - retorno por puntero del numero ingresado
/// @return retorna -1 para error y 1 si fue correcto
int getIntInRange(char mensaje[],int reintentos, int minimo, int maximo, char mensajeError[], int *pNumeroIngresado);

/// @brief Pide un numero flotante al usuario dentro de un rango y verifica que sea correcto, con x reintentos
/// @param mensaje - mensaje para el usuario solicitandole el numero
/// @param reintentos - cantidad de reintentos
/// @param minimo - valor minimo del rango
/// @param maximo - valor maximo del rango
/// @param mensajeError - mensaje de error
/// @param pNumeroIngresado - puntero donde devuelve el numero pedido si es correcto
/// @return retorna -1 para error y 1 si fue correcto
int getFloatInRange(char mensaje[],int reintentos, float minimo, float maximo, char mensajeError[], float *pNumeroIngresado);

/// @brief Pide una letra al usuario dentro de un rango y verifica que sea correcto, con x reintentos
/// @param mensaje - mensaje para el usuario solicitandole una letra
/// @param mensajeError - mensaje de error
/// @param minimo - valor minimo del rango
/// @param maximo - valor maximo del rango
/// @param reintentos - cantidad de reintentos
/// @param pLetra - puntero donde devuelve la letra pedida si es correcta
/// @return retorna -1 para error y 1 si fue correcto
int getCharInRange(char mensaje[],char mensajeError[],char minimo,char maximo,int reintentos,char *pLetra);

/// @brief Pide una array de letras al usuario y verifica que sea correcto, con x reintentos
/// @param mensaje - mensaje para el usuario solicitandole un array de letras
/// @param reintentos - cantidad de reintentos
/// @param mensajeError - mensaje de error
/// @param pLetrasIngresadas - puntero donde devuelve el array de letras pedida si es correcta
/// @param longitud - tamaño del array
/// @return retorna -1 para error y 1 si fue correcto
int GetArrayCharsWithRetrys(char mensaje[],int reintentos, char mensajeError[],char *pLetrasIngresadas,int longitud);

/// @brief Pide una array de letras y/o numeros al usuario y verifica que sea correcto, con x reintentos
/// @param mensaje - mensaje para el usuario solicitandole un array de letras y/o numeros
/// @param reintentos - cantidad de reintentos
/// @param mensajeError - mensaje de error
/// @param pLetrasIngresadas - puntero donde devuelve el array de letras y/o numeros pedida si es correcta
/// @param longitud - tamaño del array
/// @return retorna -1 para error y 1 si fue correcto
int GetArrayCharsAndIntWithRetrys(char mensaje[],int reintentos, char mensajeError[],char *pLetrasIngresadas,int longitud);

/// @brief pide un numero flotante y valida
/// @param pNumeroTomado  - puntero donde devuelve lo ingresado
/// @return retorna -1 para error y 1 si fue correcto
int GetFloat(float *pNumeroTomado);

/// @brief pide un numero entero y valida
/// @param pNumeroTomado  - puntero donde devuelve lo ingresado
/// @return retorna -1 para error y 1 si fue correcto
int GetInt(int *pNumeroTomado);

int GetLongInt(long int *pNumeroTomado);

/// @brief pide un string y valida
/// @param pLetrasTomadas - puntero donde devuelve lo ingresado
/// @param longitud - tamño del puntero string
/// @return retorna -1 para error y 1 si fue correcto
int GetArrayChars(char *pLetrasTomadas,int longitud);

/// @brief pide un array
/// @param cadena - array donde devuelve lo pedido
/// @param longitud - tamño del array
/// @return retorna -1 para error y 1 si fue correcto
int MyGets(char cadena[], int longitud);

/// @brief piede in string de letras y nuemeros y valida
/// @param pLetrasTomadas - puntero donde devuelve lo ingresado
/// @param longitud - tamño del array
/// @return retorna -1 para error y 1 si fue correcto
int GetArrayCharsAndInt(char *pLetrasTomadas,int longitud);

/// @brief pide una verificacion al usuario por S/N
/// @param mensaje - mensaje de lo que se desea verificar, sin S/N
/// @param mensajeError - mensaje de error
/// @return retorna -1 para error y 1 si fue correcto
int PedirVerificacion(char mensaje[],char mensajeError[]);

int GetCuitWithRetrys(char mensaje[],int reintentos, char mensajeError[],char *pCuitIngresado,int longitud);

int GetArrayInt(char *pLetrasTomadas,int longitud);

int GetPassword(int reintentos,int minimo,int maximo,char *pEmailIngresadas);

int GetEmail(int reintentos,char *pEmailIngresado,int longitud);

#endif /* ENTRADAYSALIDA_H_ */
