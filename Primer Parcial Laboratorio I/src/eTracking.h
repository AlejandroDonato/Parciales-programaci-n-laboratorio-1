#ifndef ETRACKING_H_
#define ETRACKING_H_

#include "EntradaYSalida.h"
#include <time.h>

//cantidad de trackings
#define MAX_TRACKING  300
//tamaño de los textos
#define MAX_CHAR 51
//estado de isEmpty:
#define LIBRE 0
#define EN_VIAJE 1
#define ENTREGADO 2
#define CANCELADO 3
#define ALL 411 // opcion para mostrar todas

#define TIEMPO_X_KM 2

typedef struct{
	int idTracking;			//idTracking
	int idProducto;			//idProducto
	int idUsuarioComprador;	//idUsuarioComprador
	int idUsuarioVendedor;	//idUsuarioVendedor
	short int isEmpty;		//libre,alta,baja
	int cantidad;			//cantridad a comprar
	int distanciaKM;		//distancia para entrga del producto(calculado segun codigo postal)
	long int horaLlegada;	//caclculo de 20seg cada 10km de distancia
}eTracking;


int T_GenerarIdTracking(void);

/// @brief harcodea los datos para 10 trackings
/// @param tracking - estructura de Tracking
/// @param cantidad - cantidad de Tracking maxima
/// @return retorna 1 si es correcto o -1 para error
int T_HarcodearTrackings(eTracking tracking[],int cantidad);

/// @brief inicializa la estructura de eTracking
/// @param tracking - estructura de Tracking
/// @param cantidad - cantidad de Tracking maxima
/// @param estado - estado en que se quiere inicializar (0 LIBRE / 1 OCUPADO / 2 BAJA)
/// @return retorna 1 si es correcto o -1 para error
int T_InicializarTracking(eTracking tracking[],int cantidad, int estado);

/// @brief Busca Espacio Para Pasa jero Nuevo
/// @param tracking - estructura de Tracking
/// @param cantidad - cantidad de Tracking maxima
/// @return retorna la ubicacion encontrada libre o -1 para error
int T_BuscarEspacioParaTrackingNuevo(eTracking tracking[],int cantidad);

/// @brief Carga los datos de un tracking en una posicion determinada
/// @param tracking - estructura de Tracking
/// @param posicion - posicion en la estructura
/// @param idTracking - id del tracking
/// @param idProducto - id del producto comprado
/// @param idUsuarioComprador - id del usuario comprador
/// @param idUsuarioVendedor - id del usuario vendedor
/// @param cantidad - cantidad comprada del producto
/// @param distanciKM - distancia para la entrega
/// @param horaLlegada - hora de llegada
/// @return retorna 1 si es correcto o -1 para error
int T_AddTracking(eTracking tracking[], int posicion, int idTracking,int idProducto,int idUsuarioComprador,int idUsuarioVendedor,int cantidad,int distanciKM,long int horaLlegada);

/// @brief calcula la distancia por medio del codigo postal
/// @param codigoPostal
/// @param distancia - valor que calcula y retorna por puntero
/// @return retorna 1 si es correcto o -1 para error
int T_CalcularDistanciaEnKM(int codigoPostal,int *distancia);

/// @brief busca la posicion de un pasajero mediante su id
/// @param tracking - estructura de Tracking
/// @param len - cantidad de Tracking maxima
/// @param id - id del pasajero que buscamos
/// @return retorna el indice del pasajero buscado o -1 si no encontro nada/error
int T_FindTrackingById(eTracking tracking[], int cantidad,int id);

/// @brief cuenta la cantidad de Tracking segun el estado que se desee
/// @param tracking - estructura de Tracking
/// @param cantidad - cantidad de Tracking maxima
/// @param estado - estado en que se quiere inicializar (0 LIBRE / 1 OCUPADO / 2 BAJA /411 ocupados y baja)
/// @return retorna la cantidad de Tracking contados o -1 para error
int T_ContarTracking(eTracking tracking[],int cantidad, int estado);

/// @brief busca el id mayor en la estructura
/// @param tracking - estructura de Tracking
/// @param cantidad - cantidad de Tracking maxima
/// @param estado - estado en que se quiere buscar (0 LIBRE / 1 OCUPADO / 2 BAJA / 411 ocupado y baja)
/// @return retorna el id mayor encontrado o -1 para error
int T_BuscarIdMayor(eTracking tracking[],int cantidad, int estado);

/// @brief da de baja todos los trackings del usuario determinado por id
/// @param tracking - estructura de Tracking
/// @param cantidad - cantidad de Tracking maxima
/// @param idUsuario - usuario des que se dan de baja los trackings
/// @return retorna 1 si es correcto o -1 para error
int T_BajaDeTrackingDelUsuario(eTracking tracking[], int cantidad,int idUsuario);

/// @brief informa el tiempo en el momento
/// @return retotna el tiempo
long int T_TiempoActual(void);

/// @brief incrementa el tiempo segun la distancia dada y tiempo x distancia
/// @param distancia
/// @return retorna el tiempo final de la entrega
long int T_AgregarTiempo(int distancia);

/// @brief cuenta las compras de determinado usuario
/// @param tracking - estructura de Tracking
/// @param cantidad - cantidad de Tracking maxima
/// @param idUsuario - id del usuario determinado
/// @return retorna la cantidad contada o -1 para error
int T_VerificarTreckingUsuario(eTracking tracking[],int cantidad, int idUsuario);

/// @brief cuenta las ventas de determinado usuario
/// @param tracking - estructura de Tracking
/// @param cantidad - cantidad de Tracking maxima
/// @param idUsuario - id del usuario determinado
/// @return retorna la cantidad contada o -1 para error
int T_VerificarVentasUsuario(eTracking tracking[],int cantidad, int idUsuario);

#endif /* ETRACKING_H_ */
