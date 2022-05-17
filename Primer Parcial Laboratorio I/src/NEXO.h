#ifndef NEXO_H_
#define NEXO_H_

#include "eProducto.h"
#include "eTracking.h"
#include "eUsuario.h"

//tamaño de los textos
#define MAX_CHAR 51
//estado de isEmpty:
#define LIBRE 0
#define OCUPADO 1
#define BAJA 2
//estado de isEmpty:
#define LIBRE 0
#define EN_VIAJE 1
#define ENTREGADO 2
#define CANCELADO 3
#define ALL 411 // opcion para mostrar todas >0
#define FINALIZADAS 23 // etregadi y cancelado

/// @brief da de baja un usuario, sus productos y cancela envios en proseso
/// @param usuarios - estructura usuarios
/// @param cantUsuarios - cantidad de usuarios que posee la estructura
/// @param productos - estructura productos
/// @param cantProductos - cantidad de productos que posee la estructura
/// @param trackings - estructura de Tracking
/// @param cantTrackings - cantidad de Tracking maxima
/// @return retorna 1 si es correcto o -1 para error
int N_BajaDeUnUsuarioCompleta(eUsuarios usuarios[],int cantUsuarios,eProductos productos[],int cantProductos,eTracking trackings[],int cantTrackings);

/// @brief muestra los trackings en un determinado estado
/// @param tracking - estructura de Tracking
/// @param cantidad - cantidad de Tracking maxima
/// @param estado - estado en que se quieran ver lostrackings
/// @param productos - estructura productos
/// @param cantProductos - cantidad de productos que posee la estructura
/// @return retorna la cantidad contada de trackins en el estado o -1 para errado
int N_MostrarTrackings(eTracking tracking[],int cantidadTracking,int estado,eProductos productos[],int cantProductos);

/// @brief muestra el tracking en una posicion especifica
/// @param tracking - estructura de Tracking
/// @param pocicion - posicion para mostrar ek tracking
/// @param productos - estructura productos
/// @param cantProductos - cantidad de productos que posee la estructura
void N_MostrarTracking(eTracking tracking[],int pocicion,eProductos productos[],int cantProductos);

/// @brief íde los datos para generar una compra
/// @param usuarios - estructura usuarios
/// @param cantUsuarios - cantidad de usuarios que posee la estructura
/// @param productos - estructura productos
/// @param cantProductos - cantidad de productos que posee la estructura
/// @param tracking - estructura de Tracking
/// @param cantTrackings - cantidad de Tracking maxima
/// @param idComprador - id del comprador del producto
/// @return retorna 1 si salio bien y -1/-2/-3/-4/-5/-6/-7 para distintos errores
int N_AltaTracking(eUsuarios usuarios[],int cantUsuarios,eProductos productos[],int cantProductos,eTracking tracking[],int cantTrackings,int idComprador);

/// @brief muestra el estado de las compras de un usuario y da la opcion de cancelar una en curso
/// @param tracking - estructura de Tracking
/// @param cantidadTracking - cantidad de Tracking maxima
/// @param estado - estado de las compras a mostrar
/// @param productos - estructura productos
/// @param cantProductos - cantidad de productos que posee la estructura
/// @param idUsuario - id del usuario comprador / logueado
/// @return retorna 1 si esta bien 0 si el usuario no tiene ocmpras o -1 para error
int N_EstadoDeCompras(eTracking tracking[],int cantidadTracking,int estado,eProductos productos[],int cantProductos, int idUsuario);

/// @brief cancela un tracking con estaod en vieaje
/// @param tracking - estructura de Tracking
/// @param cantidadTracking - cantidad de Tracking maxima
/// @param productos - estructura productos
/// @param cantProductos - cantidad de productos que posee la estructura
/// @param idUsuario - id del usuario que se mostraran las compras que se pueden cancelar
/// @return retorna 1 si salio bien, 0 si el usuario no tiene compras y -1 para error
int N_BajaDeUnTracking(eTracking tracking[],int cantidadTracking,eProductos productos[],int cantProductos, int idUsuario);

/// @brief menu que permite mostrar las ventas finalizadas y los productos a la venta del usuario
/// @param tracking - estructura de Tracking
/// @param cantidadTracking - cantidad de Tracking maxima
/// @param productos - estructura productos
/// @param cantProductos - cantidad de productos que posee la estructura
/// @param idUsuario - id del usuario logueado
/// @return retorna 1 si es correcto o -1 para error
int N_EstadoDeVentas(eTracking tracking[],int cantidadTracking,eProductos productos[],int cantProductos, int idUsuario);

/// @brief da de alta un usuario y sus productos dados de baja
/// @param usuarios - estructura usuarios
/// @param cantUsuarios - cantidad de usuarios que posee la estructura
/// @param productos - estructura productos
/// @param cantProductos - cantidad de productos que posee la estructura
/// @return retorna 1 si es correcto o -1 para error
int N_AltaDeUnUsuarioDadoDeBaja(eUsuarios usuarios[],int cantUsuarios,eProductos productos[],int cantProductos);

#endif /* NEXO_H_ */
