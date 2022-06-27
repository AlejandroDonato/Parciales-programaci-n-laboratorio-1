#ifndef SALON_H_
#define SALON_H_

#include "EntradaYSalida.h"
#include "LinkedList.h"
//tipos de salon:
#define SHOPING 1
#define LOCAL 2

typedef struct{
	int id;
	char nombre[MAX_CHARS];
	char direccion[MAX_CHARS];
	int tipo;
}Salon;

/// @brief genera un salon nuevo sin nada cargado
/// @return retorna el puntero al salon
Salon* Salon_new();

/// @brief genera un salon nuevo con sus parametros cargados
/// @param codigoStr
/// @param stadoStr
/// @return rtorna el puntero al salon nuevo
Salon* Salon_newParametros(char* nombre,char* direccion, int tipo);

/// @brief genera un salon nuevo con sus parametros cargados desde texto
/// @param nombre
/// @param direccion
/// @param tipo
/// @param id
/// @return rtorna el puntero al salon nuevo
Salon* Salon_newParametrosTxt(char* nombre, char* direccion,char* tipo,char* id);

/// @brief carga el id del salon desde un char*
/// @param this salon
/// @param id
/// @return retorna el id del salon o -1 para error
int Salon_setIdTxt(Salon* this,char* id);

/// @brief obtiene el id de salon en char*
/// @param this salon
/// @param id
/// @return retorna el id del salon o -1 para error
int Salon_getIdTxt(Salon* this,char* id);

/// @brief carga el id del salon
/// @param this salon
/// @param id
/// @return retorna el id del salon o -1 para error
int Salon_setId(Salon* this,int id);

/// @brief obtiene el id de salon
/// @param this salon
/// @param id
/// @return retorna el id del salon o -1 para error
int Salon_getId(Salon* this,int* id);

/// @brief carga el nombre del salon
/// @param this salon
/// @param nombre
/// @return retorna 1 si salio bien o -1 para error
int Salon_setNombre(Salon* this,char* nombre);

/// @brief obtiene el nombre de salon
/// @param this salon
/// @param nombre
/// @return retorna 1 si salio bien o -1 para error
int Salon_getNombre(Salon* this,char* nombre);

/// @brief carga la direccion del salon
/// @param this salon
/// @param direccion
/// @return retorna el 1 si salio bien o -1 para error
int Salon_setDireccion(Salon* this,char* direccion);

/// @brief obtiene la direccion del salon
/// @param this salon
/// @param direccion
/// @return retorna el 1 si salio bien o -1 para error
int Salon_getDireccion(Salon* this,char* direccion);

/// @brief carga el tipo del salon desde un char*
/// @param this salon
/// @param tipo
/// @return retorna el 1 si salio bien o -1 para error
int Salon_setTipoTxt(Salon* this,char* tipo);

/// @brief obtiene el tipo de salon en char*
/// @param this salon
/// @param tipo
/// @return retorna el 1 si salio bien o -1 para error
int Salon_getTipoTxt(Salon* this,char* tipo);

/// @brief carga el tipo del salon
/// @param this salon
/// @param tipo
/// @return retorna el 1 si salio bien o -1 para error
int Salon_setTipo(Salon* this,int tipo);

/// @brief obtiene el tipo de salon
/// @param this salon
/// @param tipo
/// @return retorna el 1 si salio bien o -1 para error
int Salon_getTipo(Salon* this,int* tipo);

/// @brief muestra un salon
/// @param salon
void Salon_showSalon(Salon* this);

/// @brief ultimo id de la lista
/// @return ultimo id
int Salon_lastId(LinkedList* listaSalones);

/// @brief genera un ide para el salon desde un archivo
/// @return retorna el id generado
int Salon_GenerarId(void);

/// @brief busca un salon por su id
/// @param this linkedlist
/// @param id
/// @return retorna el puntero al salon o -1 para error
Salon* Salon_findSalonById(LinkedList* this, int id);

/// @brief busca el id maximo de los salones
/// @param this linkedlist
/// @return retorna el id maximo
int Salon_findMaxId(LinkedList* this);

/// @brief busca el id minimo de los salones
/// @param this linkedlist
/// @return retorna el id minimo
int Salon_findMinId(LinkedList* this);

/// @brief valida un salon
/// @param this sañon
/// @return retorna el 1 si salio bien o -1 para error
int Salon_isValid(Salon* this);


#endif /* SALON_H_ */
