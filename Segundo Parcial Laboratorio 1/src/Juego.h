#ifndef JUEGO_H_
#define JUEGO_H_

#include "EntradaYSalida.h"

#include "LinkedList.h"

//estado de los juegos:
#define PLATAFORMA 1
#define LABERINTO 2
#define AVENTURA 3
#define OTRO 0

typedef struct{
	int id;
	char nombre[MAX_CHARS];
	char empresa[MAX_CHARS];
	int genero;
}Game;

/// @brief genera un vielo nuevo sin nada cargado
/// @return retorna el puntero al juego
Game* Game_new();

/// @brief genera un juego nuevo con sus parametros cargados
/// @param nombre
/// @param empresa
/// @param genero
/// @return rtorna el puntero al juego nuevo
Game* Game_newParametros(char* nombre,char* empresa, int genero);

/// @brief genera un juego nuevo con sus parametros cargados pasados como texto
/// @param nombre
/// @param empresa
/// @param genero
/// @param id
/// @return rtorna el puntero al juego nuevo
Game* Game_newParametrosTxt(char* nombre, char* empresa,char* genero,char* id);

/// @brief carga el id del juego desde un char*
/// @param this juego
/// @param id
/// @return retorna el id del juego o -1 para error
int Game_setIdTxt(Game* this,char* id);

/// @brief obtiene el id de juego en char*
/// @param this juego
/// @param id
/// @return retorna el id del juego o -1 para error
int Game_getIdTxt(Game* this,char* id);

/// @brief carga el id del juego
/// @param this juego
/// @param id
/// @return retorna el id del juego o -1 para error
int Game_setId(Game* this,int id);

/// @brief obtiene el id de juego
/// @param this juego
/// @param id
/// @return retorna el id del juego o -1 para error
int Game_getId(Game* this,int* id);

/// @brief carga el nombre del juego
/// @param this juego
/// @param nombre
/// @return retorna el id del juego o -1 para error
int Game_setNombre(Game* this,char* nombre);

/// @brief obtiene el nombre de juego
/// @param this juego
/// @param nombre
/// @return retorna el id del juego o -1 para error
int Game_getNombre(Game* this,char* nombre);

/// @brief carga el nombre de la empresa creadora del juego
/// @param this juego
/// @param nombre
/// @return retorna el 1 si salio bien o -1 para error
int Game_setEmpresa(Game* this,char* empresa);

/// @brief obtiene el nombre de la empresa creadora del juego
/// @param this juego
/// @param empresa
/// @return retorna el 1 si salio bien o -1 para error
int Game_getEmpresa(Game* this,char* empresa);

/// @brief carga el genero del juego desde un char*
/// @param this juego
/// @param genero
/// @return retorna el 1 si salio bien o -1 para error
int Game_setGeneroTxt(Game* this,char* genero);

/// @brief obtiene el genero de juego en char*
/// @param this juego
/// @param idgenero retorna el 1 si salio bien o -1 para error
int Game_getGeneroTxt(Game* this,char* genero);

/// @brief carga el genero del juego
/// @param this juego
/// @param genero
/// @return retorna el 1 si salio bien o -1 para error
int Game_setGenero(Game* this,int genero);

/// @brief obtiene el genero de juego
/// @param this juego
/// @param genero
/// @return retorna el 1 si salio bien o -1 para error
int Game_getGenero(Game* this,int* genero);

/// @brief muestra un juego
/// @param juego
void Game_showGame(Game* this);

/// @brief ultimo id en la lista
/// @return ultimo id
int Game_lastId(LinkedList* listaJuegos);

/// @brief genera un ide para el juego desde un archivo
/// @return retorna el id generado
int Game_GenerarId(void);

/// @brief busca un juego por su id
/// @param this linkedlist
/// @param id
/// @return retorna el puntero al juego o -1 para error
Game* Game_findGamebyId(LinkedList* this, int id);

/// @brief busca el id maximo de los juegos
/// @param this linkedlist
/// @return retorna el id maximo
int Game_findMaxId(LinkedList* this);

/// @brief busca el id minimo de los juegos
/// @param this linkedlist
/// @return retorna el id minimo
int Game_findMinId(LinkedList* this);

/// @brief verifica si es juego paso es valido
/// @param this juego
/// @return retorna el 1 si salio bien o -1 para error
int Game_isValid(Game* this);

/// @brief funcion de ordenamiento por nombre de juego
/// @param this1 juego 1
/// @param this2 juego 2
/// @return retorna 1 si es mayor, -1 si es menor y 0 par igualdad
int Game_sortByName( void* this1, void* this2);

int Game_FilterByGeneroPlataforma( void* this);
int Game_FilterByGeneroLaberinto( void* this);
int Game_FilterByGeneroAventura( void* this);
int Game_FilterByGeneroOtro( void* this);

#endif /* JUEGO_H_ */
