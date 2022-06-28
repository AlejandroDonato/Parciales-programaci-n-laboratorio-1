#include "parser.h"

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#define DATOS_BINARIO 0
#define DATOS_TEXTO 1

/////////////////SALON//////////////////

/// @brief carga salones en la linkedlist desde un archivo de texto .csv
/// @param path nombre del archivo
/// @param pListSalones linkedlist
/// @return retorna 1 si salio bien y -1 para error
int controller_loadSalonFromText(char* path , LinkedList* pListSalones);

/// @brief carga salones en la linkedlist desde un archivo binario .bin
/// @param path nombre del archivo
/// @param pListSalones linkedlist
/// @return retorna 1 si salio bien y -1 para error
int controller_loadSalonFromBinary(char* path , LinkedList* pListSalones);

/// @brief carga un salones nuevo en la linkedlist pidiendo datos al usuario
/// @param pListSalones linkedlist
/// @return retorna 1 si salio bien y -1 -2 -3 para errores
int controller_addSalon(LinkedList* pListSalones);

/// @brief elimina un salon y todos sus arcades
/// @param pListSalones linkedlist
/// @param pListArcade linkedlist
/// @return retorna 1 si salio bien y -1 para error
int controller_removeSalon(LinkedList* pListSalones, LinkedList* pListArcade);

/// @brief cuenta la cantidad de salones en la linkeslist
/// @param pListSalones linkedlist
/// @return retorna la cantidad contada si salio bien y -1 para error
int controller_countSalones(LinkedList* pListSalones);

/// @brief lista todos los datos de los salones en la linkedlist
/// @param pListSalones linkedlist
/// @return retorna la cantidad listada si salio bien y -1 para error
int controller_ListSalones(LinkedList* pListSalones);

/// @brief guarda los datos de los salon en la linkedlist en un archivo de binario .bin
/// @param path nombre del archivo
/// @param pArrayListSalon linkedlist
/// @return retorna 1 si salio bien, 0 si la linkedlist esta vacia y -1 para error
int controller_saveSalonAsBinary(char* path , LinkedList* pArrayListSalon);

/// @brief guarda los datos de los salon en la linkedlist en un archivo de texto .csv
/// @param path nombre del archivo
/// @param pArrayListSalon linkedlist
/// @return retorna 1 si salio bien, 0 si la linkedlist esta vacia y -1 para error
int controller_saveSalonAsText(char* path,LinkedList* pArrayListSalon);

/////////////////ARCADE/////////////////

/// @brief carga arcades en la linkedlist desde un archivo de texto .csv
/// @param path nombre del archivo
/// @param pListArcades linkedlist
/// @return retorna 1 si salio bien y -1 para error
int controller_loadArcadeFromText(char* path , LinkedList* pListArcades);

/// @brief carga arcades en la linkedlist desde un archivo binario .bin
/// @param path nombre del archivo
/// @param pListArcades linkedlist
/// @return retorna 1 si salio bien y -1 para error
int controller_loadArcadeFromBinary(char* path , LinkedList* pListArcades);

/// @brief carga un arcade nuevo en la linkedlist pidiendo datos al usuario
/// @param pListArcades linkedlist
/// @param pListSalones linkedlist
/// @param pListGames linkedlist
/// @return retorna 1 si salio bien y -1 -2 -3 para errores
int controller_addArcade(LinkedList* pListArcades,LinkedList* pListSalones,LinkedList* pListGames);

/// @brief cuenta la cantidad de arcades en la linkeslist
/// @param pListArcades linkedlist
/// @return  retorna la cantidad contada si salio bien y -1 para error
int controller_countArcades(LinkedList* pListArcades);

/// @brief lista todos los datos de los arcades en la linkedlist
/// @param pListArcades linkedlist
/// @param pListSalones linkedlist
/// @param pListGames linkedlist
/// @return retorna la cantidad listada si salio bien y -1 para error
int controller_ListArcades(LinkedList* pListArcades,LinkedList* pListSalones,LinkedList* pListGames);

/// @brief permite al usuario modificar siertos campos de la estructura de un arcade seleccionado por id
/// @param pListArcades linkedlist
/// @param pListSalones linkedlist
/// @param pListGames linkedlist
/// @return retorna 1 si salio bien y -1 para error
int controller_editArcade(LinkedList* pListArcades,LinkedList* pListSalones,LinkedList* pListGames);

/// @brief elimina un arcade de la linkedlist seleccionado por su id
/// @param pListArcade linkedlist
/// @param pListSalones linkedlist
/// @param pListGames linkedlist
/// @return retorna 1 si salio bien y -1 para error
int controller_removeArcade(LinkedList* pListArcade,LinkedList* pListSalones,LinkedList* pListGames);

/// @brief elimina un arcade de la linkedlist mediante el id del salon
/// @param pListArcade linkedlist
/// @param idSalon linkedlist
/// @return retorna 1 si salio bien y -1 para error
int controller_removeArcadeByIdSalon(LinkedList* pListArcade,int idSalon);

/// @brief guarda los datos de los arcades en la linkedlist en un archivo de binario .bin
/// @param path nombre del archivo
/// @param pArrayListArcade linkedlist
/// @return  retorna 1 si salio bien, 0 si la linkedlist esta vacia y -1 para error
int controller_saveArcadeAsBinary(char* path , LinkedList* pArrayListArcade);

/// @brief guarda los datos de los arcades en la linkedlist en un archivo de texto .csv
/// @param path nombre del archivo
/// @param pArrayListArcade linkedlist
/// @return retorna 1 si salio bien, 0 si la linkedlist esta vacia y -1 para error
int controller_saveArcadeAsText(char* path,LinkedList* pArrayListArcade);

/////////////////JUEGO//////////////////

/// @brief carga juegos en la linkedlist desde un archivo de texto .csv
/// @param path nombre del archivo
/// @param pListGames linkedlist
/// @return retorna 1 si salio bien y -1 para error
int controller_loadGameFromText(char* path , LinkedList* pListGames);

/// @brief carga juegos en la linkedlist desde un archivo binario .bin
/// @param path nombre del archivo
/// @param pListGames linkedlist
/// @return retorna 1 si salio bien y -1 para error
int controller_loadGameFromBinary(char* path , LinkedList* pListGames);

/// @brief carga un juego nuevo en la linkedlist pidiendo datos al usuario
/// @param pListGames linkedlist
/// @return retorna 1 si salio bien y -1 -2 -3 para errores
int controller_addGame(LinkedList* pListGames);

/// @brief cuenta la cantidad de juegos en la linkeslist
/// @param pListGames linkedlist
/// @return retorna la cantidad contada si salio bien y -1 para error
int controller_countGames(LinkedList* pListGames);

/// @brief lista todos los datos de los juegos en la linkedlist
/// @param pListGames linkedlist
/// @return retorna la cantidad listada si salio bien y -1 para error
int controller_ListGames(LinkedList* pListGames);

/// @brief guarda los datos de los juegos en la linkedlist en un archivo de binario .bin
/// @param path nombre del archivo
/// @param pArrayListGame linkedlist
/// @return retorna 1 si salio bien, 0 si la linkedlist esta vacia y -1 para error
int controller_saveGameAsBinary(char* path , LinkedList* pArrayListGame);

/// @brief guarda los datos de los juegos en la linkedlist en un archivo de texto .csv
/// @param path nombre del archivo
/// @param pArrayListGame linkedlist
/// @return retorna 1 si salio bien, 0 si la linkedlist esta vacia y -1 para error
int controller_saveGameAsText(char* path,LinkedList* pArrayListGame);

/////////////////INFORMES/////////////////

/// @brief despliega el menu con las opciones para los informes
/// @param listaArcades linkedlist
/// @param listaSalones linkedlist
/// @param listaJuegos linkedlist
void controler_MenuInformes(LinkedList* listaArcades,LinkedList* listaSalones,LinkedList* listaJuegos);

/// @brief Lista Salones Con Mas De Cuatro Arcades
/// @param listaArcades linkedlist
/// @param listaSalones linkedlist
/// @return retorna 1 si salio bien, 0 si no listo nada y -1 para error
int controller_ListarSalonesConMasDeCuatroArcades(LinkedList* listaArcades,LinkedList* listaSalones);

/// @brief Lista Arcades Para Mas De Dos Jugadores
/// @param listaSalones linkedlist
/// @param listaArcades linkedlist
/// @param listaJuegos linkedlist
/// @return retorna 1 si salio bien, 0 si no listo nada y -1 para error
int controller_ListarArcadesParaMasDeDosJugadores(LinkedList* listaSalones,LinkedList* listaArcades,LinkedList* listaJuegos);

/// @brief Lista Un Salon De terminado
/// @param listaSalones linkedlist
/// @return retorna 1 si salio bien y -1 para error
int controller_ListarUnSalonDeterminado(LinkedList* listaSalones);

/// @brief Lista Salones Completos
/// @param listaArcades linkedlist
/// @param listaSalones linkedlist
/// @param listaJuegos linkedlist
/// @return retorna 1 si salio bien, 0 si no listo nada y -1 para error
int controller_ListarSalonesCompletos(LinkedList* listaArcades,LinkedList* listaSalones,LinkedList* listaJuegos);

/// @brief Lista Arcades De Un Salon Determinado
/// @param listaSalones linkedlist
/// @param listaArcades linkedlist
/// @param listaJuegos linkedlist
/// @return retorna 1 si salio bien, 0 si no listo nada y -1 para error
int controller_ListarArcadesDeUnSalonDeterminado(LinkedList* listaSalones,LinkedList* listaArcades,LinkedList* listaJuegos);

/// @brief Listar Salon Con Mas Arcades
/// @param listaSalones linkedlist
/// @param listaArcades linkedlist
/// @param listaJuegos linkedlist
/// @return retorna 1 si salio bien, 0 si no listo nada y -1 para error
int controller_ListarSalonConMasArcades(LinkedList* listaSalones,LinkedList* listaArcades,LinkedList* listaJuegos);

/// @brief Arcades sonido Mono con juego tipo Plataforma, ordenado Por Nombre
/// @param listaArcades linkedlist
/// @param listaJuegos linkedlist
/// @return retorna 1 si salio bien, 0 si no listo nada y -1 para error
int controller_ArcadesMonoPlataformaPorNombre(LinkedList* listaArcades,LinkedList* listaJuegos);

////////CARGA DE DATOS///////////////////

/// @brief carga De Datos Inicial
/// @param tipoDeCarga 0 para archivo binario .bin y 1 para archivo de texto .csv
/// @param listaSalones linkedlist
/// @param listaArcades linkedlist
/// @param listaJuegos linkedlist
void controller_cargaDeDatosInicial(int tipoDeCarga,LinkedList* listaSalones,LinkedList* listaArcades,LinkedList* listaJuegos);

////////MARCOS PARA LOS MENSAJES///////////////////

/// @brief pone un mensaje centrado dentro de un marco cabecera
/// @param mensaje dentro del marco
void controller_MensajeCabecera(char mensaje[]);

/// @brief pone un mensaje centrado dentro de un marco de operacion exitosa
/// @param mensaje dentro del marco
void controller_MensajeExitoso(char mensaje[]);

/// @brief pone un mensaje centrado dentro de un marco de error
/// @param mensaje dentro del marco
void controller_MensajeError(char mensaje[]);

int controler_FiltrarPorSalon(LinkedList* listaSalones);

int controler_FiltrarPorGeneroDeJuego(LinkedList* listaJuegos);

#endif
