#include "EntradaYSalida.h"
#include "LinkedList.h"

#ifndef ARCADE_H_
#define ARCADE_H_

#define ID_LEN 10

#define MONO 1
#define ESTEREO 2

typedef struct{
	int id;
	char nacionalidad[MAX_CHARS];
	int tipoSonido;
	int cantJugadores;
	int cantFichas;
	int idJuego;
	int idSalon;
}Arcade;

/// @brief genera un espacio en memoria para un arcade
/// @return devuelve el puntero a ese espacio
Arcade* Arcade_new();

/// @brief carga los datos de un nuevo arcade desde texto y devuelde la estructura cargada
/// @param idStr
/// @param nacionalidadStr
/// @param tipoSonidoStr
/// @param cantJugadoresStr
/// @param cantFichasStr
/// @param idSalonStr
/// @param idJuegoStr
/// @return devuelde la estructura cargada
Arcade* Arcade_newParametrosTxt(char* idStr,char* nacionalidadStr,char* tipoSonidoStr,char* cantJugadoresStr,char* cantFichasStr,char* idJuegoStr,char* idSalonStr);

/// @brief carga los datos de un nuevo arcade y devuelde la estructura cargada
/// @param nacionalidad
/// @param tipoSonido
/// @param cantJugadores
/// @param cantFichas
/// @param idSalon
/// @param idJuego
/// @return devuelde la estructura cargada
Arcade* Arcade_newParametros(char* nacionalidad,int tipoSonido,int cantJugadores,int cantFichas,int idJuego,int idSalon);

/// @brief carga el id de un arcade pasado como texto a int
/// @param this arcade al cual cargar el dato
/// @param id pasado como texto
/// @return rertorna 1 si salio bien y -1 para error
int Arcade_setIdTxt(Arcade* this,char* id);

/// @brief obtiene el id de un arcade como int y lo devuelve como char
/// @param this arcade del cual sacar lo pedido
/// @param id pasado como texto
/// @return rertorna 1 si salio bien y -1 para error
int Arcade_getIdTxt(Arcade* this,char* id);

/// @brief carga el id en un arcade
/// @param this arcade al cual cargar el dato
/// @param id
/// @return rertorna 1 si salio bien y -1 para error
int Arcade_setId(Arcade* this,int id);

/// @brief obtiene el id de un arcade
/// @param this arcade del cual sacar lo pedido
/// @param id
/// @return rertorna 1 si salio bien y -1 para error
int Arcade_getId(Arcade* this,int* id);

/// @brief carga la nacionalidad de un arcade
/// @param this arcade al cual cargar el dato
/// @param id
/// @return rertorna 1 si salio bien y -1 para error
int Arcade_setNacionalidad(Arcade* this,char* nacionalidad);

/// @brief obtiene la nacionalidad de un arcade
/// @param this arcade del cual sacar lo pedido
/// @param id
/// @return rertorna 1 si salio bien y -1 para error
int Arcade_getNacionalidad(Arcade* this,char* nacionalidad);

/// @brief carga el tipo de sonido de un arcade pasado como texto a int
/// @param this arcade al cual cargar el dato
/// @param id pasado como texto
/// @return rertorna 1 si salio bien y -1 para error
int Arcade_setTipoSonidoTxt(Arcade* this,char* tipoSonido);

/// @brief obtiene el tipo de sonido de un arcade como int y lo devuelve como char*
/// @param this arcade del cual sacar lo pedido
/// @param id pasado como texto
/// @return rertorna 1 si salio bien y -1 para error
int Arcade_getTipoSonidoTxt(Arcade* this,char* tipoSonido);

/// @brief carga el tipo de sonido en un arcade
/// @param this arcade al cual cargar el dato
/// @param id
/// @return rertorna 1 si salio bien y -1 para error
int Arcade_setTipoSonido(Arcade* this,int tipoSonido);

/// @brief obtiene el tipo de sonido de un arcade
/// @param this arcade del cual sacar lo pedido
/// @param id
/// @return rertorna 1 si salio bien y -1 para error
int Arcade_getTipoSonido(Arcade* this,int* tipoSonido);

/// @brief carga la cantidad de jugadores de un arcade pasado como texto a int
/// @param this arcade al cual cargar el dato
/// @param id pasado como texto
/// @return rertorna 1 si salio bien y -1 para error
int Arcade_setCantJugadoresTxt(Arcade* this,char* cantJugadores);

/// @brief obtiene la cantidad de juegadores de un arcade como int y la devuelve como char*
/// @param this arcade del cual sacar lo pedido
/// @param id pasado como texto
/// @return rertorna 1 si salio bien y -1 para error
int Arcade_getCantJugadoresTxt(Arcade* this,char* cantJugadores);

/// @brief carga la cantidad de jugadores en un arcade
/// @param this arcade al cual cargar el dato
/// @param id
/// @return rertorna 1 si salio bien y -1 para error
int Arcade_setCantJugadores(Arcade* this,int cantJugadores);

/// @brief obtiene la cantidad de jugadores de un arcade
/// @param this arcade del cual sacar lo pedido
/// @param id
/// @return rertorna 1 si salio bien y -1 para error
int Arcade_getCantJugadores(Arcade* this,int* cantJugadores);

/// @brief carga la cantidad de fichas de un arcade pasado como texto a int
/// @param this arcade al cual cargar el dato
/// @param id pasado como texto
/// @return rertorna 1 si salio bien y -1 para error
int Arcade_setCantFichasTxt(Arcade* this,char* cantFichas);

/// @brief obtiene la cantidad de fichas de un arcade como int y lo devuelve como char
/// @param this arcade del cual sacar lo pedido
/// @param id pasado como texto
/// @return rertorna 1 si salio bien y -1 para error
int Arcade_getCantFichasTxt(Arcade* this,char* cantFichas);

/// @brief carga la cantidad de ficahas en un arcade
/// @param this arcade al cual cargar el dato
/// @param id
/// @return rertorna 1 si salio bien y -1 para error
int Arcade_setCantFichas(Arcade* this,int cantFichas);

/// @brief obtiene la cantidad de fichas de un arcade
/// @param this arcade del cual sacar lo pedido
/// @param id
/// @return rertorna 1 si salio bien y -1 para error
int Arcade_getCantFichas(Arcade* this,int* cantFichas);

/// @brief carga el id del salon de un arcade pasado como texto a int
/// @param this arcade al cual cargar el dato
/// @param id pasado como texto
/// @return rertorna 1 si salio bien y -1 para error
int Arcade_setIdSalonTxt(Arcade* this,char* idSalon);

/// @brief obtiene el id del salon de un arcade como int y lo devuelve como char
/// @param this arcade del cual sacar lo pedido
/// @param id pasado como texto
/// @return rertorna 1 si salio bien y -1 para error
int Arcade_getIdSalonTxt(Arcade* this,char* idSalon);

/// @brief carga el id del salon en un arcade
/// @param this arcade al cual cargar el dato
/// @param id
/// @return rertorna 1 si salio bien y -1 para error
int Arcade_setIdSalon(Arcade* this,int idSalon);

/// @brief obtiene el id del salon de un arcade
/// @param this arcade del cual sacar lo pedido
/// @param id
/// @return rertorna 1 si salio bien y -1 para error
int Arcade_getIdSalon(Arcade* this,int* idSalon);

/// @brief carga el id del juego de un arcade pasado como texto a int
/// @param this arcade al cual cargar el dato
/// @param id pasado como texto
/// @return rertorna 1 si salio bien y -1 para error
int Arcade_setIdJuegoTxt(Arcade* this,char* idJuego);

/// @brief obtiene el id del juego de un arcade como int y lo devuelve como char
/// @param this arcade del cual sacar lo pedido
/// @param id pasado como texto
/// @return rertorna 1 si salio bien y -1 para error
int Arcade_getIdJuegoTxt(Arcade* this,char* idJuego);

/// @brief carga el id del juego en un arcade
/// @param this arcade al cual cargar el dato
/// @param id
/// @return rertorna 1 si salio bien y -1 para error
int Arcade_setIdJuego(Arcade* this,int idJuego);

/// @brief obtiene el id del juego de un arcade
/// @param this arcade del cual sacar lo pedido
/// @param id
/// @return rertorna 1 si salio bien y -1 para error
int Arcade_getIdJuego(Arcade* this,int* idJuego);

/// @brief muestra un arcade especificado sumado al nombre del juego y de salon
/// @param arcade
/// @param nombreJuego
/// @param nombreSalon
void Arcade_showArcade(Arcade* arcade,char* nombreJuego,char* nombreSalon);

/// @brief busca un arcade en la linkedlist por su id
/// @param this linkedlist
/// @param id del arcade a buscar
/// @return el puntero al arcade buscado
Arcade* Arcade_findArcadeById(LinkedList* this,int id);

/// @brief busca en el archivo .cvs el id mayor guardado
/// @param path archivo .cvs
/// @return rertorna 1 si salio bien y -1 para error
int Arcade_lastId(LinkedList* listaArcades);

/// @brief genera un id nuevo a apartir del ultimo registrado
/// @return retorna un id nuevo
int Arcade_GenerarId(void);

/// @brief busca el ultimo id
/// @return retorna el valor del ultimo id
int Arcade_GetLastId(void);

/// @brief busca el id maximo en la linkedlist
/// @param this linkedlist
/// @return retorna el id maximo
int Arcade_findMaxId(LinkedList* this);

/// @brief verifica que el arcade tenga todos los campos correctos
/// @param this arcade a analizar
/// @return rertorna 1 si es un pásajero valido y -1 para error
int Arcade_isValid(Arcade* this);

/// @brief remplaza un arcade con otro
/// @param this arcade 1 a rempalazar
/// @param this2 arcade 2 remplazante
/// @return rertorna 1 si salio bien y -1 para error
int Arcade_remplazar(Arcade* this, Arcade* this2);

/// @brief criterio de ordenamiento por id
/// @param this1 arcade 1 a comparar
/// @param this2 arcade 2 a comparar
/// @return retorna 1 si es mayo o -1 si es menor y 0 si son iguales
int Arcade_sortById( void* this1, void* this2);

#endif /* ARCADE_H_ */
