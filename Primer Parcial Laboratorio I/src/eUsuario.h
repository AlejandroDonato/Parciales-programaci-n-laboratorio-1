#ifndef EUSUARIO_H_
#define EUSUARIO_H_

#include "EntradaYSalida.h"
//cantidad de usuarios
#define MAX_USUARIOS  100
//tamaño de los textos
#define MAX_CHARS 50
#define MAX_CORREO 25
#define MAX_PASSWORD 10
//estado de isEmpty:
#define LIBRE 0
#define OCUPADO 1
#define BAJA 2
#define ALL 411 // ocupado y baja
//usuarios
#define ADMIN 666
#define USUARIO 1

typedef struct{
	int idUsuario;				//idUsuario
	short int isEmpty;			//libre,alta,baja
	short int tipo;				// admin / uduario
	char nombre[MAX_CHARS];		//nick para mostrar
	char correo[MAX_CORREO];	//E-mail validado
	char password[MAX_PASSWORD];//minimo 4 | alfanumerico sin signo
	char direccion[MAX_CHARS];	//domicilio
	int codigoPostal;			//codigo postal
}eUsuarios;

/// @brief pide y compara usuario y contraceña con la lista de usuarios validando
/// @param usuarios - estructura usuarios
/// @param cantidadUsuarios - cantidad de usuarios que posee la estructura
/// @param idUsuario - puntero que devuelve el id del usuario ingresado
/// @param reintentos - cantidad de reintentos
/// @return rotorna 1 si salio bien y -1 para error
int U_Ingresar(eUsuarios usuarios[],int cantidadUsuarios,int *idUsuario,int reintentos);

/// @brief harcodea la lista de usuarios
/// @param Usuario - estructura usuarios
/// @param cantidadusuarios - cantidad de usuarios que posee la estructura
/// @return rotorna 1 si salio bien y -1 para error
int U_HarcodearUsuarios(eUsuarios usuarios[],int cantidad);

/// @brief inicializa los usuarios en el estado deceado (isEmpty)
/// @param Usuario - estructura usuarios
/// @param cantidadusuarios - cantidad de usuarios que posee la estructura
/// @param estado - estado para inicilaizar los usuarios (0 libre/1 ocupado/2 baja)
/// @return rotorna 1 si salio bien y -1 para error
int U_InicializarUsuarios(eUsuarios usuarios[],int cantidad,int estado);

/// @brief muestra la lista de usuarios de un estado determinado
/// @param usuarios - estructura usuarios
/// @param cantidad - cantidad de usuarios que posee la estructura
/// @param estado- estado para mostrar los usuarios (0 libre/1 ocupado/2 baja)
/// @return rotorna la cantidad de usuarios mostrados si salio bien y -1 para error
int U_MostrarUsuarios(eUsuarios usuarios[],int cantidad, int estado);

/// @brief muestra un Usuario determinado
/// @param Usuario - estructura usuarios
/// @param posicion - pucicion del Usuario que se quiere mostrar
void U_MostrarUsuario(eUsuarios usuarios[],int posicion);

/// @brief nusca un espacio libre para cargar un Usuario
/// @param usuarios - estructura usuarios
/// @param cantidad - cantidad de usuarios que posee la estructura
/// @return rotorna la posicion vacia / 0  si no encuentra espacio  -1 y -2 para errores
int U_BuscarEspacioParaUsuarioNuevo(eUsuarios usuarios[],int cantidad);

/// @brief da a elegir entre da de alta un usuario nuevo o uno existente dado de baja
/// @param usuarios - estructura usuarios
/// @param cantidad - cantidad de usuarios que posee la estructura
/// @param tipo - tipo de usuario
/// @return rotorna 1 si salio bien y -1 y -2 para error
int U_OpcionAltaUsuarios(eUsuarios usuarios[],int cantidad,short int tipo);

/// @brief pide los datos y da de alta un Usuario
/// @param usuarios - estructura usuarios
/// @param cantidad - cantidad de usuarios que posee la estructura
/// @param tipo - tipo de usuario
/// @return rotorna 1 si salio bien y -1 /-2 /-3 /-4 /-5 /-6 /-7 /-8 para errores
int U_AltaUsuario(eUsuarios usuarios[],int cantidad,short int tipo);

/// @brief carga los datos de un Usuario en un espacio determinado
/// @param usuarios - estructura usuarios
/// @param posicion - posicion en la que se desea cargar los datos del Usuario
/// @param id - id del Usuario a cargar
/// @param nombre - nombre del usuario
/// @param correo - E-mail del usuario
/// @param direccion - direccion del usuario
/// @param codigoPostal - codigo postal del usuario
/// @param password - password del usuario
/// @param tipo - tipo de usuario
/// @return rotorna 1 si salio bien y -1 para error
int U_AddUsuario(eUsuarios usuarios[], int posicion, int id, char nombre[],char correo[],char direccion[],int codigoPostal,char password[],short int tipo);

/// @brief pide nombre de usuario a cargar y valida que no este repetido y este disponible para su uso
/// @param usuarios - estructura usuarios
/// @param cantidad - cantidad de usuarios que posee la estructura
/// @param nombre - nombre que devuelve validado
/// @return rotorna 1 si salio bien y -1 para error
int U_NombreDeUsuario(eUsuarios usuarios[],int cantidad,char nombre[]);

/// @brief muestra la lista de usuarios dados de baja y pide un id de uno para darlo de alta
/// @param usuarios - estructura usuarios
/// @param cantidad - cantidad de usuarios que posee la estructura
/// @return rotorna el id del usuario dado de alta si salio bien y -1/-2/-3/ para errores
int U_AltaUsuarioExistente(eUsuarios usuarios[],int cantidad);

/// @brief busca la posicion de un Usuario mediante su id
/// @param list - estructura usuarios
/// @param len - cantidad de usuarios que posee la estructura
/// @param id - id del Usuario a buscar posicion
/// @return rotorna la posicion del id dado si salio bien y -1 para error
int U_FindUsuarioById(eUsuarios usuarios[], int cantidad,int idUsuario);

/// @brief muestra la lista de usuarios activos y pide un id de uno para darlo de baja
/// @param usuarios - estructura usuarios
/// @param cantidad - cantidad de usuarios que posee la estructura
/// @return rotorna 1 si salio bien, 0 si se cancelo la baja y -1 para error
int U_BajaDeUnUsuario(eUsuarios usuarios[],int cantidad,int *idUsuario);

/// @brief cuenta la cantidad de usuarios en un determinado estado
/// @param usuarios - estructura usuarios
/// @param cantidad - cantidad de usuarios que posee la estructura
/// @param estado - estado para mostrar los usuarios (0 libre/1 ocupado/2 baja/411 todos)
/// @return rotorna la cantidad de contada si salio bien y -1 para error
int U_ContarUsuarios(eUsuarios usuarios[],int cantidad, int estado);

/// @brief busca el id mayor de un determinado estado de usuarios
/// @param usuarios - estructura usuarios
/// @param cantidad - cantidad de usuarios que posee la estructura
/// @param estado - estado para buscar id de los usuarios mayores (0 libre/1 ocupado/2 baja/411 todos)
/// @return rotorna eñ id mayor si salio bien y -1 para errores
int U_BuscarIdMayor(eUsuarios usuarios[],int cantidad, int estado);

/// @brief muestra la lista de usuarios y pide seleccionar un id
/// @param usuarios - estructura usuarios
/// @param cantidad - cantidad de usuarios que posee la estructura
/// @param idUsuario - puntero donde devuelve el id seleccionado
/// @return rotorna 1 si salio bien y -1 para errores
int U_GetIdUsuarioFromList(eUsuarios usuarios[],int cantidad,int *idUsuario, int estado);

/// @brief da opciones entre usuario nuevo existente o dado de baja, los da de alta y devuelve su id
/// @param usuarios - estructura usuarios
/// @param cantidad - cantidad de usuarios que posee la estructura
/// @param tipo - tipo de usuario
/// @return rotorna el id del usuario dado de alta si salio bien y -1/-2/-3/ para errores
int U_SeleccionarUsuarios(eUsuarios usuarios[],int cantidad,short int tipo);

/// @brief carga los datos de un Admin
/// @param usuarios - estructura usuarios
/// @param cantidad - cantidad de usuarios que posee la estructura
/// @return rotorna 1 si salio bien y -1 para errores
int U_ADMIN(eUsuarios usuarios[],int cantidad);

#endif /* EPANTALLAS_H_ */
