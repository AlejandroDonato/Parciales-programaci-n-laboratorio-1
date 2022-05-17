#include "eProducto.h"

static int P_GenerarId(void);
static int P_GenerarId(void){
	static int contadorV = 100;
	return contadorV++;
}

int P_HarcodearProductos(eProductos productos[],int cantidad){
	int rtn =-1;
	int j = 0;
	char nombre[10][MAX_CHAR]={"Producto01","Producto02","Producto03","Producto04","Producto05","Producto06","Producto07","Producto08","Producto09","Producto10"};
	if(productos != NULL && cantidad > 0){

		for (int i = 0; i < cantidad; i++){
			if(productos[i].isEmpty == 0){
				productos[i].isEmpty = 1;
				strcpy(productos[i].nombreProducto,nombre[j]);
				productos[i].precio=rand()%10000;
				productos[i].stock=rand()%100+10;
				productos[i].categoria=rand()%10;
				productos[i].idProducto = P_GenerarId();
				productos[i].idUsuario =rand()%10+100;
				j++;
			}
			if(j == 10){
				break;
			}
		}
		rtn = 1;
	}
	return rtn;
}

int P_InicializarProductos(eProductos productos[],int cantidad,int estado){
	int rtn =-1;
	if(productos != NULL && cantidad > 0){
	for (int i = 0; i < cantidad; i++){
		productos[i].isEmpty = estado;
	}
	rtn = 1;
	}
	return rtn;
}

int P_MostrarProductos(eProductos productos[],int cantidad, int estado){
	int contador = -1;
	int flagContador =-1;
	if(productos != NULL && cantidad>0){
		contador = 0;
		printf( "+------+---------------------+---------------------+---------------------+-----------+\n"
				"|  Id  | Nombre de Producto  | Categoria           | Precio              | Stock     |\n"
				"+------+---------------------+---------------------+---------------------+-----------+\n");
		for(int i = 0;i<cantidad;i++){
			if(estado == 411 && productos[i].isEmpty> 0){
				P_MostrarProducto(productos,i);
				contador++;
				flagContador =1;
			}
			if( productos[i].isEmpty == estado && productos[i].stock > 0){
				P_MostrarProducto(productos,i);
				contador++;
				flagContador =1;
			}
		}
		if(flagContador == -1){
			printf( "+------------------------------------------------------------------------------------+\n"
					"|  No hay productos para mostrar                                                     |\n"
					"+------------------------------------------------------------------------------------+\n\n\n");
		}
	}
	return contador;
}

int P_MostrarProductosVendedor(eProductos productos[],int cantidad,int estado,int idUsuario){
	int contador = -1;
	int flagContador =-1;
	if(productos != NULL && cantidad>0){
		contador = 0;
		printf( "+------+---------------------+---------------------+---------------------+-----------+\n"
				"|  Id  | Nombre de Producto  | Categoria           | Precio              | Stock     |\n"
				"+------+---------------------+---------------------+---------------------+-----------+\n");
		for(int i = 0;i<cantidad;i++){
			if(estado == 411 && productos[i].isEmpty> 0 && productos[i].idUsuario == idUsuario){
				P_MostrarProducto(productos,i);
				contador++;
				flagContador =1;
			}
			if( productos[i].isEmpty == estado && productos[i].idUsuario == idUsuario && productos[i].stock > 0){
				P_MostrarProducto(productos,i);
				contador++;
				flagContador =1;
			}
		}
		if(flagContador == -1){
			printf( "+------------------------------------------------------------------------------------+\n"
					"|  No hay productos para mostrar                                                     |\n"
					"+------------------------------------------------------------------------------------+\n\n\n");
		}
	}
	return contador;
}

int P_MostrarProductosComprador(eProductos productos[],int cantidad,int estado,int idUsuario){
	int contador = -1;
	int flagContador =-1;
	if(productos != NULL && cantidad>0){
		contador = 0;
		printf( "+------+---------------------+---------------------+---------------------+-----------+\n"
				"|  Id  | Nombre de Producto  | Categoria           | Precio              | Stock     |\n"
				"+------+---------------------+---------------------+---------------------+-----------+\n");
		for(int i = 0;i<cantidad;i++){
			if(estado == 411 && productos[i].isEmpty> 0 && productos[i].idUsuario == idUsuario){
				P_MostrarProducto(productos,i);
				contador++;
				flagContador =1;
			}
			if( productos[i].isEmpty == estado && productos[i].idUsuario != idUsuario && productos[i].stock > 0){
				P_MostrarProducto(productos,i);
				contador++;
				flagContador =1;
			}
		}
		if(flagContador == -1){
			printf( "+------------------------------------------------------------------------------------+\n"
					"|  No hay productos para mostrar                                                     |\n"
					"+------------------------------------------------------------------------------------+\n\n\n");
		}
	}
	return contador;
}

void P_MostrarProducto(eProductos productos[],int posicion){

	char auxCategoriaProducto[MAX_CHAR];

	switch (productos[posicion].categoria){
	case 1:
		strcpy(auxCategoriaProducto,"Construcción");
		break;
	case 2:
		strcpy(auxCategoriaProducto,"Deportes");
		break;
	case 3:
		strcpy(auxCategoriaProducto,"Electrodomesticos");
		break;
	case 4:
		strcpy(auxCategoriaProducto,"Herramientas");
		break;
	case 5:
		strcpy(auxCategoriaProducto,"Hogar y Muebles");
		break;
	case 6:
		strcpy(auxCategoriaProducto,"Juegos y Juguetes");
		break;
	case 7:
		strcpy(auxCategoriaProducto,"Moda");
		break;
	case 8:
		strcpy(auxCategoriaProducto,"Supermercado");
		break;
	case 9:
		strcpy(auxCategoriaProducto,"Tecnologia");
		break;
	case 0:
		strcpy(auxCategoriaProducto,"Belleza");
		break;
	}
	printf( "| %-5d| %-20s| %-20s| $%-19.2f| %-10d|\n"
			"+------+---------------------+---------------------+---------------------+-----------+\n",
			productos[posicion].idProducto,
			productos[posicion].nombreProducto,
			auxCategoriaProducto,
			productos[posicion].precio,
			productos[posicion].stock);

}

int P_BuscarEspacioParaProductoNuevo(eProductos productos[],int cantidad){
	int rtn;
	int flag = 0;
	if(productos != NULL && cantidad>0){
		for(int i = 0;i<cantidad;i++){
			if( productos[i].isEmpty == LIBRE){
				rtn = i;
				flag = 1;
				break;
			}
		}
		if(flag == 0){rtn = 0;//sin espacio en la lista
		}
	}
	else{rtn=-1;//array nulo
	}
return rtn;
}

int P_OpcionAltaProductos(eProductos productos[],int cantidad,int idUsuario){
	int rtn=-1;
	int opcion;
	if(productos != NULL && cantidad > 0){
		if(getIntInRange("Ingrese una opcion:\n\t1 - Producto nuevo \n\t2 - Producto existente",3,1,2,"Opcion invalida",&opcion) ==1){
			switch (opcion) {
				case 1:
					if(P_AltaProducto(productos,cantidad,idUsuario)==1){
						rtn=1;
					}
					break;
				case 2:
					if(P_AltaProductoExistente(productos,cantidad)==1){
						rtn=1;
					}
					break;
			}
		}
		else{rtn=-2;
		}
	}
return rtn;
}

int P_AltaProducto(eProductos productos[],int cantidad,int idUsuario){
	int rtn;
	int productoLibre;
	int auxId;
	char auxNombre[MAX_CHAR];
	float auxPrecio;
	int auxCategoria;
	int auxStock;

	if(productos != NULL && cantidad > 0){
		productoLibre = P_BuscarEspacioParaProductoNuevo(productos,cantidad);
		if(productoLibre != -1){
			if(GetArrayCharsWithRetrys("Ingrese Nombre del producto:",3,"Nombre invalido,",auxNombre,MAX_CHAR) == 1){
				if(getFloatInRange("Ingrese precio del producto:",3,0,100000000, "Valor invalido,",&auxPrecio) == 1){
					printf( "\n"
							"<<->>+<><><><><><><><><><><><>+<<->>\n"
							"<>-<>| 1er EXAMEN  LAB I - 1H |<>-<>\n"
							"<<->>+<><><><><><><><><><><><>+<<->>\n"
							"<>                                <>\n"
							"<<->>+------------------------+<<->>\n"
							"<>-<>|       CATEGORIAS       |<>-<>\n"
							"<<->>+------------------------+<<->>\n"
							"<>                                <>\n"
							"<>    (0) - Belleza               <>\n"
							"<>    (1) - Construcción          <>\n"
							"<>    (2) - Electrodomesticos     <>\n"
							"<>    (3) - Deportes              <>\n"
							"<>    (4) - Herramientas          <>\n"
							"<>    (5) - Hogar y Muebles       <>\n"
							"<>    (6) - Juegos y Juguetes     <>\n"
							"<>    (7) - Moda                  <>\n"
							"<>    (8) - Supermercado          <>\n"
							"<>    (9) - Tecnologia            <>\n"
							"<>                                <>\n"
							"<<->>+<><><><><><><><><><><><>+<<->>\n\n");
					if(getIntInRange("Ingrese categoria:",3,0,9,"Opcion invalida,",&auxCategoria) == 1){
						if(getIntInRange("ingrese stock:",3,1,100000,"cantidad invalida,",&auxStock) == 1){
						auxId = P_GenerarId();//
							if(P_AddProducto(productos,productoLibre,auxId,auxNombre,auxPrecio,auxCategoria,auxStock,idUsuario)==1){
								productos[productoLibre].isEmpty = OCUPADO;//
								rtn =1;
							}
							else{rtn =-7;//error en la funcion addProducto
							}
						}
						else{rtn =-6;//error en la carga del stock del Producto
						}
					}
					else{rtn =-5;//error al cargar de la categoria del Producto
					}
				}
				else{rtn =-4;//error en la carga del precio del Producto
				}
			}
			else{rtn =-3;//error en la carga del nombre del Producto
			}
		}
		else{rtn =-2;//error al buscar espacio libre
		}
	}
	else{rtn =-1;//error estructura o cantidad nula
	}
return rtn;
}

int P_AddProducto(eProductos productos[], int posicion, int id, char nombre[],float precio,short int categoria, int stock,int idUsuario){
	int rtn;
	if(productos != NULL && posicion > -1){
		productos[posicion].idProducto = id;
		productos[posicion].idUsuario = idUsuario;
		strcpy(productos[posicion].nombreProducto,nombre);
		productos[posicion].precio = precio;
		productos[posicion].categoria = categoria;
		productos[posicion].stock = stock;
		rtn = 1;
	}
	else{rtn = -1;
	}
return rtn;
}

int P_AltaProductoExistente(eProductos productos[],int cantidad){
	int rtn;
	int posicion;
	int auxId;
	int maxId;

	if(productos != NULL && cantidad > 0){
		P_MostrarProductos(productos,cantidad,BAJA);
		maxId = P_BuscarIdMayor(productos,cantidad,BAJA);
		if(getIntInRange("Ingrese una id:",3,0,maxId,"Id invalida,",&auxId)==1){
			posicion = P_FindProductoById(productos,cantidad,auxId);
			puts("Producto a dar de alta:\n"
				 "+------+---------------------+---------------------+-----------+-----------+\n"
				 "|  Id  | Nombre de Producto  | Categoria           | Precio    | Stock     |\n"
				 "+------+---------------------+---------------------+-----------+-----------+\n");
			P_MostrarProducto(productos,posicion);
			puts(" ");
			if(PedirVerificacion("Desea dar de alta este producto?","Opcion invalida")==1){
				productos[posicion].isEmpty = OCUPADO;
				rtn =1;
			}
			else{rtn =-3;//error en la verificacion o canccelacion de accion
			}
		}
		else{rtn =-2;//error en la funcion getIntInRange
		}
	}
	else{rtn =-1;//error en los datos receividos
	}
	return rtn;
}

int P_ModificarProducto(eProductos productos[], int cantidad){
	int rtn;

	if(productos != NULL && cantidad > 0){
		int auxId;
		int auxIdUsuario;
		char auxNombre[MAX_CHAR];
		float auxPrecio;
		int auxCategoria;
		int auxStock;

		int finalizar;
		int opcion;
		int maxId;
		int posicion;

		maxId = P_BuscarIdMayor(productos,cantidad,OCUPADO);
		P_MostrarProductos(productos,cantidad,OCUPADO);


		if(getIntInRange("Ingrese una id:",3,0,maxId,"Id invalida,",&auxId)==1){
			posicion = P_FindProductoById(productos,cantidad,auxId);
			puts("Producto a Modificar:\n"
				 "+------+---------------------+---------------------+-----------+-----------+\n"
				 "|  Id  | Nombre de Producto  | Categoria           | Precio    | Stock     |\n"
				 "+------+---------------------+---------------------+-----------+-----------+\n");
			P_MostrarProducto(productos,posicion);
			puts(" ");
			strcpy(auxNombre,productos[posicion].nombreProducto);
			auxPrecio = productos[posicion].precio;
			auxCategoria = productos[posicion].categoria;
			auxStock = productos[posicion].stock;
			auxIdUsuario = productos[posicion].idUsuario;
			do{
				printf(	"\n"
						"<<->>+<><><><><><><><><><><><>+<<->>\n"
						"<>-<>| 1er EXAMEN  LAB I - 1H |<>-<>\n"
						"<<->>+<><><><><><><><><><><><>+<<->>\n"
						"<>                                <>\n"
						"<<->>+------------------------+<<->>\n"
						"<>-<>|       MODIFICAR        |<>-<>\n"
						"<<->>+------------------------+<<->>\n"
						"<>                                <>\n"
						"<>    (1) - Modificar Nombre      <>\n"
						"<>    (2) - Modificar Categoria   <>\n"
						"<>    (3) - Modificar Precio      <>\n"
						"<>    (4) - Modificar Stock       <>\n"
						"<>                                <>\n"
						"<>    (0) - Guardar/Salir         <>\n"
						"<>                                <>\n"
						"<<->>+<><><><><><><><><><><><>+<<->>\n\n");
				if(getIntInRange("ingrese una opcion:",3,0,4,"Opcion invalida",&opcion) !=1){
					puts("-----| Error |-----");
					finalizar =1;
				}
				switch(opcion){
				case 1://Modificar Nombre
					puts(   "\n"
							"<<->>+------------------------+<<->>\n"
							"<>-<>|    MODIFICAR NOMBRE    |<>-<>\n"
							"<<->>+------------------------+<<->>\n");
					if(GetArrayCharsWithRetrys("Ingrese Nombre:",3,"Nombre invalido,",auxNombre,MAX_CHAR) != 1){
						puts("Error al Modificar nombre de la Producto");
					}
					break;
				case 2://Modificar categoria
					printf( "\n"
							"<<->>+------------------------+<<->>\n"
							"<>-<>|  MODIFICAR CATEGORIA   |<>-<>\n"
							"<<->>+------------------------+<<->>\n"
							"<>                                <>\n"
							"<>    (0) - Belleza               <>\n"
							"<>    (1) - Construcción          <>\n"
							"<>    (2) - Electrodomesticos     <>\n"
							"<>    (3) - Deportes              <>\n"
							"<>    (4) - Herramientas          <>\n"
							"<>    (5) - Hogar y Muebles       <>\n"
							"<>    (6) - Juegos y Juguetes     <>\n"
							"<>    (7) - Moda                  <>\n"
							"<>    (8) - Supermercado          <>\n"
							"<>    (9) - Tecnologia            <>\n"
							"<>                                <>\n"
							"<<->>+------------------------+<<->>\n\n");
					if(getIntInRange("Ingrese categoria:",3,0,9,"Opcion invalida,",&auxCategoria) != 1){
						puts("Error al Modificar la direccion de la Producto");
					}
					break;
				case 3://Modificar precio
					puts(   "\n"
							"<<->>+------------------------+<<->>\n"
							"<>-<>|    MODIFICAR PRECIO    |<>-<>\n"
							"<<->>+------------------------+<<->>\n");
					if(getFloatInRange("Ingrese nuevo precio:",3,0,100000000, "Valor invalido,",&auxPrecio) != 1){
						puts("Error al Modificar el precio de la Producto");
					}
					break;
				case 4://Modificar tipo
					puts(   "\n"
							"<<->>+------------------------+<<->>\n"
							"<>-<>|    MODIFICAR STOCK     |<>-<>\n"
							"<<->>+------------------------+<<->>\n");
					if(getIntInRange("Ingrese nuevo stock",3,1,2,"Opcion invalida,",&auxStock) != 1){
						puts("Error al Modificar stock del Producto");
					}
					break;
				case 5://Modificar Precio
					puts(   "\n"
							"<<->>+------------------------+<<->>\n"
							"<>-<>|     GUARDAR/SALIR      |<>-<>\n"
							"<<->>+------------------------+<<->>\n");
					if(PedirVerificacion("Desea guardar los cambios?","Opcion invalida")==1){
						P_AddProducto(productos,posicion,auxId,auxNombre,auxPrecio,auxCategoria,auxStock,auxIdUsuario);
						puts("<<<<<| Guardardado exitoso |>>>>>");
					}
					finalizar =1;
					rtn = 1;
					puts("<<<<<| Saliendo de modificar |>>>>>");
					break;
				}
			}while(finalizar!=1);
		}
		else{rtn=-2;//id ingresado incorrecto
		}
	}
	else{rtn=-1;//datos nulos o cantidad 0
	}
	return rtn;
}

int P_FindProductoById(eProductos productos[], int cantidad,int idProducto){
int rtn = -1;
for(int i = 0;i < cantidad; i++){
	if(productos[i].idProducto == idProducto){
		rtn = i;
		break;
	}
}
return rtn;
}

int P_BajaDeUnProducto(eProductos productos[], int cantidad){
	int rtn =-1;
	if(productos != NULL && cantidad > 0){
		int auxId;
		int maxId;
		int posicion;
		maxId = P_BuscarIdMayor(productos,cantidad,OCUPADO);
		P_MostrarProductos(productos,cantidad,OCUPADO);
		if(getIntInRange("Ingrese una id:",3,0,maxId,"Id invalida,",&auxId)==1){
			posicion = P_FindProductoById(productos,cantidad,auxId);
			printf( "Producto seleccionada para eliminar:\n"
					"+------+---------------------+---------------------+---------------------+-----------+\n"
					"|  Id  | Nombre de Producto  | Categoria           | Precio              | Stock     |\n"
					"+------+---------------------+---------------------+---------------------+-----------+\n");
			P_MostrarProducto(productos,posicion);
			puts(" ");
			if(PedirVerificacion("Desea dar de baja este Producto?","Opcion invalida")==1){
				productos[posicion].isEmpty=BAJA;
				rtn =1;
			}
			else{
				rtn =0;
			}
		}
	}
	return rtn;
}

int P_ContarProductos(eProductos productos[],int cantidad, int estado){
	int contador = -1;

	if(productos != NULL && cantidad >0){
		contador = 0;
		for(int i = 0;i<cantidad;i++){
			if(estado == 411 && productos[i].isEmpty> 0){
				contador++;
			}
			if( productos[i].isEmpty == estado){
				contador++;
			}
		}
	}
	return contador;
}

int P_BuscarIdMayor(eProductos productos[],int cantidad, int estado){
	int auxMaxId =-1;
	if(productos != NULL && cantidad >0){
		auxMaxId =0;
		for(int i = 0;i<cantidad;i++){
			if(estado == 411 && productos[i].idProducto>auxMaxId){
				auxMaxId = productos[i].idProducto;
			}
			if( productos[i].isEmpty == estado && productos[i].idProducto>auxMaxId ){
				auxMaxId = productos[i].idProducto;
			}
		}
	}
	return auxMaxId;
}

int P_GetIdProductoFromList(eProductos productos[],int cantidad,int *idProducto,int estado,int idUsuario){
	int rtn=-1;
	int auxIdProductoMayor;
	int auxIdProducto;
	int flagId = -1;
	int contador =0;
	int i;

	if(productos != NULL && cantidad >0){
		P_MostrarProductosComprador(productos, cantidad, estado, idUsuario);
		auxIdProductoMayor = P_BuscarIdMayor(productos,cantidad,estado);
		do{
			if(getIntInRange("Ingrese Id del Producto:",3,0,auxIdProductoMayor,"Opcion invalida,",&auxIdProducto) == 1 ){
				for (i = 0; i < cantidad; ++i) {
					if(productos[i].idProducto == auxIdProducto){
						*idProducto = auxIdProducto;
						flagId =1;
						rtn = 1;
						break;
					}
				}
				if(flagId !=1){
					puts("-----| ERROR |-----");
					contador++;
				}
				if(contador == 3){
					flagId =1;
				}
			}
		}while(flagId !=1);
	}
	return rtn;
}

int P_BajaDeProductosDelUsuario(eProductos productos[], int cantidad,int idUsuario){
	int rtn=-1;
	int i;
	if(productos != NULL && cantidad > 0){
		for(i = 0; i < cantidad; i++){
			if(productos[i].idUsuario==idUsuario){
			productos[i].isEmpty=BAJA;
			}
		}
		rtn=1;
	}
	return rtn;
}

int P_AltaDeProductosDelUsuario(eProductos productos[], int cantidad,int idUsuario){
	int rtn=-1;
	int i;
	if(productos != NULL && cantidad > 0){
		for(i = 0; i < cantidad; i++){
			if(productos[i].idUsuario==idUsuario){
			productos[i].isEmpty=OCUPADO;
			}
		}
		rtn=1;
	}
	return rtn;
}

int P_VerificarProductosYStock(eProductos productos[],int cantidad){
	int contador = -1;

	if(productos != NULL && cantidad >0){
		contador = 0;
		for(int i = 0;i<cantidad;i++){
			if( productos[i].isEmpty == OCUPADO && productos[i].stock>0 ){
				contador++;
			}
		}
	}
	return contador;
}

int P_VerificarProductosDeOtros(eProductos productos[],int cantidad,int idUsuario){
	int contador = -1;

	if(productos != NULL && cantidad >0){
		contador = 0;
		for(int i = 0;i<cantidad;i++){
			if( productos[i].isEmpty == OCUPADO && productos[i].stock>0 && productos[i].idUsuario != idUsuario){
				contador++;
			}
		}
	}
	return contador;
}

int T_SortProductos(eProductos producto[],int cantidad, int orden){
	int rtn = -1;
	eProductos auxProducto;
	int flagSwap;
	int limite;
	int i;

	if(producto != NULL && cantidad >= 0 && orden > 0){
		limite = cantidad-1;
		do{
			flagSwap=0;
			for (i = 0; i < limite; i++){
				if(orden == 1){
					if(producto[i].categoria < producto[i+1].categoria){
						flagSwap=1;
						auxProducto = producto[i];
						producto[i] =	producto[i+1];
						producto[i+1] = auxProducto;
					}
					if(producto[i].categoria == producto[i+1].categoria){
						flagSwap=1;
						if(strcmp(producto[i].nombreProducto , producto[i+1].nombreProducto)<0){
						auxProducto = producto[i];
						producto[i] =	producto[i+1];
						producto[i+1] = auxProducto;
						}
					}
				}
				if(orden == 2){
					if(producto[i].categoria > producto[i+1].categoria){
						flagSwap=1;
						auxProducto = producto[i];
						producto[i] =	producto[i+1];
						producto[i+1] = auxProducto;
					}
					if(producto[i].categoria == producto[i+1].categoria){
						flagSwap=1;
						if(strcmp(producto[i].nombreProducto , producto[i+1].nombreProducto)>0){
							auxProducto = producto[i];
							producto[i] =	producto[i+1];
							producto[i+1] = auxProducto;
						}
					}
				}
			}
			limite--;
		}while(flagSwap);
		rtn = 1;
	}
return rtn;
}

int P_ReponerStockProducto(eProductos productos[], int cantidad,int idUsuario){
	int rtn;

	if(productos != NULL && cantidad > 0){
		int auxId;
		int auxStock;
		int maxId;
		int posicion;

		maxId = P_BuscarIdMayor(productos,cantidad,OCUPADO);
		P_MostrarProductosVendedor(productos,cantidad,OCUPADO,idUsuario);


		if(getIntInRange("Ingrese una id:",3,0,maxId,"Id invalida,",&auxId)==1){
			posicion = P_FindProductoById(productos,cantidad,auxId);
			printf( "Producto a recargar Stock:\n"
					"+------+---------------------+---------------------+---------------------+-----------+\n"
					"|  Id  | Nombre de Producto  | Categoria           | Precio              | Stock     |\n"
					"+------+---------------------+---------------------+---------------------+-----------+\n");
			P_MostrarProducto(productos,posicion);
			puts(" ");
			if(getIntInRange("Ingrese stock a agregar",3,1,1000,"cantidad invalida,",&auxStock)== 1){
				if(PedirVerificacion("Desea agregar el stock?","Opcion invalida")==1){
					productos[posicion].stock+=auxStock;
					rtn = 1;
				}
				else{rtn=-4;//error en verificacion o cancelacion
				}
			}
			else{rtn=-3;//error en cargar id
			}
		}
		else{rtn=-2;//error en pedir id
		}
	}
	else{rtn=-1;//datos nulos
	}
	return rtn;
}

int P_FiltrarPorNombreDeProducto(eProductos producto[],int cantidad,int estado){
	int rtn =-1;
	char auxNombre[MAX_CHAR];
	if(producto != NULL && cantidad >= 0){
		if(GetArrayCharsAndIntWithRetrys("Ingrese nombre del producto a buscar:",3,"Nombre incorrecto",auxNombre,MAX_CHAR) == 1){
			if(T_SortProductosPorStock(producto,cantidad)==1){
				if(P_MostrarProductosPorNombre(producto,cantidad,estado,auxNombre)>0){
					rtn=1;
				}
			}
		}
	}
	return rtn;
}

int T_SortProductosPorStock(eProductos producto[],int cantidad){
	int rtn = -1;
	eProductos auxProducto;
	int flagSwap;
	int limite;
	int i;

	if(producto != NULL && cantidad >= 0){
		limite = cantidad-1;
		do{
			flagSwap=0;
			for (i = 0; i < limite; i++){
				if(producto[i].isEmpty!=LIBRE){
					if(strcmp(producto[i].nombreProducto , producto[i+1].nombreProducto)<0){
						flagSwap=1;
						auxProducto = producto[i];
						producto[i] =	producto[i+1];
						producto[i+1] = auxProducto;
					}
					if(strcmp(producto[i].nombreProducto , producto[i+1].nombreProducto) == 0){
						flagSwap=1;
						if(producto[i].stock < producto[i+1].stock){
						auxProducto = producto[i];
						producto[i] =	producto[i+1];
						producto[i+1] = auxProducto;
						}
					}
				}
			}
			limite--;
		}while(flagSwap);
		rtn = 1;
	}
return rtn;
}

int P_MostrarProductosPorNombre(eProductos productos[],int cantidad, int estado, char nombre[]){
	int contador = -1;
	int flagContador =-1;
	if(productos != NULL && cantidad>0){
		contador = 0;
		printf( "+------+---------------------+---------------------+---------------------+-----------+\n"
				"|  Id  | Nombre de Producto  | Categoria           | Precio              | Stock     |\n"
				"+------+---------------------+---------------------+---------------------+-----------+\n");
		for(int i = 0;i<cantidad;i++){
			if(estado == 411 && productos[i].isEmpty> 0){
				if(strcmp(productos[i].nombreProducto,nombre)==0){
					P_MostrarProducto(productos,i);
					contador++;
					flagContador =1;
				}
			}
			if( productos[i].isEmpty == estado && productos[i].stock > 0){
				if(strcmp(productos[i].nombreProducto,nombre)==0){
					P_MostrarProducto(productos,i);
					contador++;
					flagContador =1;
				}
			}
		}
		if(flagContador == -1){
			printf( "+------------------------------------------------------------------------------------+\n"
					"|  No hay productos para mostrar                                                     |\n"
					"+------------------------------------------------------------------------------------+\n\n\n");
		}
	}
	return contador;
}
