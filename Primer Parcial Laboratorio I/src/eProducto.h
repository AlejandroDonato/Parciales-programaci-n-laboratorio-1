#ifndef EPRODUCTO_H_
#define EPRODUCTO_H_

#include "EntradaYSalida.h"

//camtidad de productos
#define MAX_PRODUCTOS 200
//tamaño de los textos
#define MAX_CHAR 51
//estado de isEmpty:
#define LIBRE 0
#define OCUPADO 1
#define BAJA 2
#define ALL 411 // opcion para mostrar todas

typedef struct{
	int idProducto;			//idProducto
	int idUsuario;			//idUsuario Vendedor
	short int isEmpty;		//libre,alta,baja
	char nombreProducto[50];//nombre
	float precio;			//precio
	short int categoria;	//moda,construccion,tecnologia,etc
	int stock;				//cantidad a la venta
}eProductos;

/// @brief harcodea la lista de productos
/// @param Producto - estructura productos
/// @param cantidadproductos - cantidad de productos que posee la estructura
/// @return rotorna 1 si salio bien y -1 para error
int P_HarcodearProductos(eProductos productos[],int cantidad);

/// @brief inicializa los productos en el estado deceado (isEmpty)
/// @param Producto - estructura productos
/// @param cantidadproductos - cantidad de productos que posee la estructura
/// @param estado - estado para inicilaizar los productos (0 libre/1 ocupado/2 baja)
/// @return rotorna 1 si salio bien y -1 para error
int P_InicializarProductos(eProductos productos[],int cantidad,int estado);

/// @brief muestra la lista de productos de un estado determinado
/// @param productos - estructura productos
/// @param cantidad - cantidad de productos que posee la estructura
/// @param estado - estado para mostrar los productos (0 libre/1 ocupado/2 baja)
/// @return rotorna la cantidad de productos mostrados si salio bien y -1 para error
int P_MostrarProductos(eProductos productos[],int cantidad,int estado);

/// @brief muestra la lista de productos de un comprador
/// @param productos - estructura productos
/// @param cantidad - cantidad de productos que posee la estructura
/// @param estado - estado para mostrar los productos
/// @param idUsuario - id del usuario que queremos mostrar sus productos
/// @return rotorna la cantidad de productos mostrados si salio bien y -1 para error
int P_MostrarProductosComprador(eProductos productos[],int cantidad,int estado,int idUsuario);

/// @brief muestra la lista de productos de un vendedor
/// @param productos - estructura productos
/// @param cantidad - cantidad de productos que posee la estructura
/// @param estado - estado para mostrar los productos
/// @param idUsuario - id del usuario que queremos mostrar sus productos
/// @return rotorna la cantidad de productos mostrados si salio bien y -1 para error
int P_MostrarProductosVendedor(eProductos productos[],int cantidad,int estado,int idUsuario);

/// @brief muestra un Producto determinado
/// @param Producto - estructura productos
/// @param pocicion - pucicion del Producto que se quiere mostrar
void P_MostrarProducto(eProductos productos[],int pocicion);

/// @brief nusca un espacio libre para cargar un Producto
/// @param productos - estructura productos
/// @param cantidad - cantidad de productos que posee la estructura
/// @return rotorna la pocicion vacia / 0  si no encuentra espacio  -1 y -2 para errores
int P_BuscarEspacioParaProductoNuevo(eProductos productos[],int cantidad);

/// @brief da opcion de dar de alta un producto nuevo o uno dado de baja
/// @param productos - estructura productos
/// @param cantidad - cantidad de productos que posee la estructura
/// @param idUsuario
/// @return rotorna 1 si salio bien y -1 /-2 para errores
int P_OpcionAltaProductos(eProductos productos[],int cantidad,int idUsuario);

/// @brief pide los datos y da de alta un Producto
/// @param productos - estructura productos
/// @param cantidad - cantidad de productos que posee la estructura
/// @param idUsuario - id del usuario que da de alta el producto
/// @return rotorna 1 si salio bien y -1 /-2 /-3 /-4 /-5 para errores
int P_AltaProducto(eProductos productos[],int cantidad,int idUsuario);

/// @brief carga los datos de un Producto en un espacio determinado
/// @param productos - estructura productos
/// @param pocicion - pocicion en la que se desea cargar los datos del Producto
/// @param id - id del Producto a cargar
/// @param nombre - nombre de Producto a cargar
/// @param precio - estado del Producto a cargar
/// @param categoria - categoria a la que pertenece el producto
/// @param stock - cantidad del producto a vender
/// @param udUsuario - id del usuario de carga el producto
/// @return rotorna 1 si salio bien y -1 para error
int P_AddProducto(eProductos productos[], int pocicion, int id, char nombre[],float precio,short int categoria, int stock,int idUsuario);

/// @brief da de alta un producto que estaba dado de baja
/// @param productos - estructura productos
/// @param cantidad - cantidad de productos que posee la estructura
/// @return rotorna 1 si salio bien y -1 /-2 /-3 para errores
int P_AltaProductoExistente(eProductos productos[],int cantidad);

/// @brief muestra la lista y pide seleccionar un id para modificar un Producto
/// @param productos - estructura productos en dererminada pocicion
/// @param cantidad - cantidad de productos que posee la estructura
/// @return rotorna 1 si salio bien y -1/-2 para errores
int P_ModificarProducto(eProductos productos[], int cantidad);

/// @brief busca la pocicion de un Producto mediante su id
/// @param productos - estructura productos
/// @param cantidad - cantidad de productos que posee la estructura
/// @param idProducto - id del Producto a buscar pocicion
/// @return rotorna el id si salio bien y -1 para error
int P_FindProductoById(eProductos productos[], int cantidad,int idProducto);

/// @brief muestra la lista de productos y pide un id para dar de baja
/// @param productos - estructura productos
/// @param cantidad - cantidad de productos que posee la estructura
/// @return rotorna 1 si salio bien, 0 si se cacelo la baja y -1 para error
int P_BajaDeUnProducto(eProductos productos[], int cantidad);

/// @brief cuenta la cantidad de productos en un determinado estado
/// @param productos - estructura productos
/// @param cantidad - cantidad de productos que posee la estructura
/// @param estado - estado para mostrar los productos (0 libre/1 ocupado/2 baja/411 todos)
/// @return rotorna la cantidad de contada si salio bien y -1 para error
int P_ContarProductos(eProductos productos[],int cantidad, int estado);

/// @brief busca el id mayor de un determinado estado de productos
/// @param productos - estructura productos
/// @param cantidad - cantidad de productos que posee la estructura
/// @param estado - estado para buscar id de los productos mayores (0 libre/1 ocupado/2 baja/411 todos)
/// @return rotorna eñ id mayor si salio bien y -1 para errores
int P_BuscarIdMayor(eProductos productos[],int cantidad, int estado);

/// @brief muestra la lista de productos y pide seleccionar un id
/// @param productos - estructura productos
/// @param cantidad - cantidad de productos que posee la estructura
/// @param idProducto - puntero donde devuelve el id seleccionado
/// @return rotorna 1 si salio bien y -1 para errores
int P_GetIdProductoFromList(eProductos productos[],int cantidad,int *idProducto,int estado,int idUsuario);

/// @brief da de baja un producto de un usuario determinado por id
/// @param productos - estructura productos
/// @param cantidad - cantidad de productos que posee la estructura
/// @param idUsuario - id del usuario del que se va a dar de baja un producto
/// @return rotorna 1 si salio bien y -1 para errores
int P_BajaDeProductosDelUsuario(eProductos productos[], int cantidad,int idUsuario);

/// @brief da de alta un producto de un usuario determinado por id
/// @param productos - estructura productos
/// @param cantidad - cantidad de productos que posee la estructura
/// @param idUsuario - id del usuario del que se va a dar de alta un producto dado de baja
/// @return rotorna 1 si salio bien y -1 para errores
int P_AltaDeProductosDelUsuario(eProductos productos[], int cantidad,int idUsuario);

/// @brief recorre la lista de productos y cuenta cuanto producto este dado de alta y con stock
/// @param productos - estructura productos
/// @param cantidad - cantidad de productos que posee la estructura
/// @return rotorna la cantidad de procutos contado si salio bien y -1 para errores
int P_VerificarProductosYStock(eProductos productos[],int cantidad);

/// @brief recorre la lista de productos y cuanta cuantos productos no son del usuario determinado por el id
/// @param productos - estructura productos
/// @param cantidad - cantidad de productos que posee la estructura
/// @param idUsuario - id del usuario del que se van a descartar procuctos
/// @return retotna la cantidad de productos contados
int P_VerificarProductosDeOtros(eProductos productos[],int cantidad,int idUsuario);

/// @brief ordena los productos por categoria y nombre
/// @param productos - estructura productos
/// @param cantidad - cantidad de productos que posee la estructura
/// @param orden 1 descendente 2 ascendente
/// @return rotorna 1 si salio bien y -1 para errores
int T_SortProductos(eProductos producto[],int cantidad, int orden);

#endif /* EPRODUCTO_H_ */
