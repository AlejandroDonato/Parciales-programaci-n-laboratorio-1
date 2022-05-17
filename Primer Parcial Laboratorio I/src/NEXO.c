#include "NEXO.h"

int N_BajaDeUnUsuarioCompleta(eUsuarios usuarios[],int cantUsuarios,eProductos productos[],int cantProductos,eTracking tracking[],int cantTrackings){
	int rtn =-1;
	int idUsuario;
	if(usuarios != NULL && cantUsuarios > 0 && productos != NULL && cantProductos > 0 && tracking != NULL && cantTrackings > 0){
		if(U_BajaDeUnUsuario(usuarios,cantUsuarios,&idUsuario)==1){
			if(P_BajaDeProductosDelUsuario(productos,cantProductos,idUsuario)==1){
				if(T_BajaDeTrackingDelUsuario(tracking,cantTrackings,idUsuario)==1){
					rtn=1;
				}
			}
		}
	}
	return rtn;
}

int N_MostrarTrackings(eTracking tracking[],int cantidadTracking,int estado,eProductos productos[],int cantProductos){
	int contador = -1;
	int flagContador =-1;
	if(tracking != NULL && cantidadTracking>0){
		contador = 0;
		printf( "+------+---------------------+-----------+---------------------+-----------+----------------------------+\n"
				"|  Id  | Nombre de producto  | Cantidad  | Precio              | Estado    | Fecha de entrega           |\n"
				"+------+---------------------+-----------+---------------------+-----------+----------------------------+\n");
		for(int i = 0;i<cantidadTracking;i++){
			if(estado == 411 && tracking[i].isEmpty> 0){
				N_MostrarTracking(tracking,i,productos,cantProductos);
				contador++;
				flagContador =1;

			}
			if( tracking[i].isEmpty == estado){
				N_MostrarTracking(tracking,i,productos,cantProductos);
				contador++;
				flagContador =1;
			}
		}
		if(flagContador == -1){
			printf( "+-------------------------------------------------------------------------------------------------------+\n"
					"| No hay tracking para mostrar                                                                          |\n"
					"+-------------------------------------------------------------------------------------------------------+\n\n\n");
		}
	}
	return contador;
}

int N_MostrarTrackingsComprador(eTracking tracking[],int cantidadTracking,int estado,eProductos productos[],int cantProductos, int idUsuario){
	int contador = -1;
	int flagContador =-1;
	if(tracking != NULL && cantidadTracking>0){
		contador = 0;
		if(T_VerificarTreckingUsuario(tracking,cantidadTracking,idUsuario)>0){
			printf( "+------+---------------------+-----------+---------------------+-----------+----------------------------+\n"
					"|  Id  | Nombre de producto  | Cantidad  | Precio              | Estado    | Fecha de entrega           |\n"
					"+------+---------------------+-----------+---------------------+-----------+----------------------------+\n");
			for(int i = 0;i<cantidadTracking;i++){
				if( tracking[i].idUsuarioComprador == idUsuario){
					if(estado == 411 && tracking[i].isEmpty> 0){
						N_MostrarTracking(tracking,i,productos,cantProductos);
						contador++;
						flagContador =1;
					}
					if(estado == 23 && tracking[i].isEmpty> 1){
						N_MostrarTracking(tracking,i,productos,cantProductos);
						contador++;
						flagContador =1;
					}
					if( tracking[i].isEmpty == estado){
					N_MostrarTracking(tracking,i,productos,cantProductos);
					contador++;
					flagContador =1;
					}
				}
			}
		}
		if(flagContador == -1){
			printf( "+-------------------------------------------------------------------------------------------------------+\n"
					"| No hay tracking para mostrar                                                                          |\n"
					"+-------------------------------------------------------------------------------------------------------+\n\n\n");
		}
	}
	return contador;
}

int N_MostrarTrackingsVendedor(eTracking tracking[],int cantidadTracking,int estado,eProductos productos[],int cantProductos, int idUsuario){
	int contador = -1;
	int flagContador =-1;
	if(tracking != NULL && cantidadTracking>0){
		contador = 0;
		printf( "+------+---------------------+-----------+---------------------+-----------+----------------------------+\n"
				"|  Id  | Nombre de producto  | Cantidad  | Precio              | Estado    | Fecha de entrega           |\n"
				"+------+---------------------+-----------+---------------------+-----------+----------------------------+\n");
		for(int i = 0;i<cantidadTracking;i++){
			if( tracking[i].idUsuarioVendedor == idUsuario){
				if(estado == 411 && tracking[i].isEmpty> 0){
				N_MostrarTracking(tracking,i,productos,cantProductos);
				contador++;
				flagContador =1;
				}
				if(estado == 23 && tracking[i].isEmpty> 1){
					N_MostrarTracking(tracking,i,productos,cantProductos);
					contador++;
					flagContador =1;
				}
				if( tracking[i].isEmpty == estado){
				N_MostrarTracking(tracking,i,productos,cantProductos);
				contador++;
				flagContador =1;
				}
			}
		}
		if(flagContador == -1){
			printf( "+-------------------------------------------------------------------------------------------------------+\n"
					"| No hay tracking para mostrar                                                                          |\n"
					"+-------------------------------------------------------------------------------------------------------+\n\n\n");
		}
	}
	return contador;
}


void N_MostrarTracking(eTracking tracking[],int pocicion,eProductos productos[],int cantProductos){
	char auxEstado[MAX_CHAR];
	char fechaEntrega[MAX_CHAR];
	char nombre[MAX_CHAR];
	int cantidad;
	float precioTotal;
	float precio;

	strcpy(fechaEntrega,ctime(&tracking[pocicion].horaLlegada));
	strcpy(nombre,productos[P_FindProductoById(productos,cantProductos,tracking[pocicion].idProducto)].nombreProducto);
	cantidad = tracking[pocicion].cantidad;
	precio = productos[P_FindProductoById(productos,cantProductos,tracking[pocicion].idProducto)].precio;
	precioTotal = precio * cantidad;

	if(fechaEntrega[strnlen(fechaEntrega,sizeof(fechaEntrega))-1] == '\n'){
		fechaEntrega[strnlen(fechaEntrega,sizeof(fechaEntrega))-1] = '\0';
	}

	if(tracking[pocicion].isEmpty==EN_VIAJE){
		if(difftime(tracking[pocicion].horaLlegada,T_TiempoActual())<=0){
				tracking[pocicion].isEmpty=ENTREGADO;
		}
	}
	switch (tracking[pocicion].isEmpty){
	case 1:
		strcpy(auxEstado,"En viaje");
		break;
	case 2:
		strcpy(auxEstado,"Entregado");
		break;
	case 3:
		strcpy(auxEstado,"Cancelado");
		break;
	}
	printf( "| %-5d| %-20s| %-10d| $%-19.2f| %-10s| %-27s|\n"
			"+------+---------------------+-----------+---------------------+-----------+----------------------------+\n",
			tracking[pocicion].idTracking,nombre,cantidad,precioTotal,auxEstado,fechaEntrega);
}

int N_AltaTracking(eUsuarios usuarios[],int cantUsuarios,eProductos productos[],int cantProductos,
				   eTracking tracking[],int cantTrackings,int idComprador){
	int rtn;
	int trackingLibre;
	int auxMaxCantidad;

	int auxIdTracking;
	int auxIdProducto;
	int auxIdUsuarioVendedor;
	int auxCantidad;
	int auxDistanciaKM;
	long int auxHoraLlegada;

	if(productos != NULL && cantProductos > 0 && tracking != NULL && cantTrackings > 0 && usuarios != NULL && cantUsuarios > 0){
		trackingLibre = T_BuscarEspacioParaTrackingNuevo(tracking,cantTrackings);
		if(trackingLibre != -1){
			if(P_GetIdProductoFromList(productos,cantProductos,&auxIdProducto,OCUPADO,idComprador) == 1){
				auxMaxCantidad = productos[P_FindProductoById(productos,cantProductos,auxIdProducto)].stock;
				if(getIntInRange("Ingrese cantidad que desa comprar:",3,1,auxMaxCantidad,"cantidad invalida,",&auxCantidad) == 1){
					if(T_CalcularDistanciaEnKM(usuarios[U_FindUsuarioById(usuarios,cantUsuarios,idComprador)].codigoPostal,&auxDistanciaKM) == 1){
						if(PedirVerificacion("Desea realizar esta compra?","Opcion invalida")==1){
						auxIdUsuarioVendedor = productos[P_FindProductoById(productos,cantProductos,auxIdProducto)].idUsuario;
						auxHoraLlegada = T_AgregarTiempo(auxDistanciaKM);
						auxIdTracking = T_GenerarIdTracking();
							if(T_AddTracking(tracking,trackingLibre,auxIdTracking,auxIdProducto,idComprador,
								auxIdUsuarioVendedor,auxCantidad,auxDistanciaKM,auxHoraLlegada)==1){
								tracking[trackingLibre].isEmpty = OCUPADO;
								productos[P_FindProductoById(productos,cantProductos,auxIdProducto)].stock-=auxCantidad;
								rtn =1;
							}
							else{rtn =-7;//error en la funcion addTracking
							}
						}
						else{rtn =-6;//error o cancelacion de la validacion
						}
					}
					else{rtn =-5;//error en la funcion calcular distancia
					}
				}
				else{rtn =-4;//error en la carga de la cantidad a comprar
				}
			}
			else{rtn =-3;//error en la P_GetIdProductoFromList
			}
		}
		else{rtn =-2;//error al buscar espacio libre
		}
	}
	else{rtn =-1;//error estructura o cantidad nula
	}
return rtn;
}

int N_EstadoDeCompras(eTracking tracking[],int cantidadTracking,int estado,eProductos productos[],int cantProductos, int idUsuario){
	int rtn =-1;
	int opcion;
	if(tracking != NULL && cantidadTracking >0 && estado >0 && productos != NULL && cantProductos > 0 && idUsuario >0){
		opcion =-1;
		do{
			if(N_MostrarTrackingsComprador(tracking,cantidadTracking,estado,productos,cantProductos,idUsuario)>0){
				rtn =1;
				printf( "\n"
						"<<->>+------------------------+<<->>\n"
						"<>-<>|    ESTADO DE COMPRA    |<>-<>\n"
						"<<->>+------------------------+<<->>\n"
						"<>                                <>\n"
						"<>    (1) - Cancelar una compra   <>\n"
						"<>    (2) - Actualizar lista      <>\n"
						"<>                                <>\n"
						"<>    (0) - Salir                 <>\n"
						"<>                                <>\n"
						"<<->>+------------------------+<<->>\n\n");
				if(getIntInRange("Ingrese una opcion:",3,0,2,"Opcion invalida,",&opcion) == 1){
					switch(opcion){
					case 1:
						N_BajaDeUnTracking(tracking,cantidadTracking,productos,cantProductos,idUsuario);
						break;
					case 2:
						puts(   "+-------------------------------------------------------------------------------------------------------+\n"
								"| Actualizar lista                                                                                      |\n"
								"+-------------------------------------------------------------------------------------------------------+\n");
						break;
					}
				}
				else{opcion=0;
				}
			}
			else{rtn=0;
			}
		}while(opcion!=0);
	}
	return rtn;
}

int N_BajaDeUnTracking(eTracking tracking[],int cantidadTracking,eProductos productos[],int cantProductos, int idUsuario){
	int rtn =-1;
	if(tracking != NULL && cantidadTracking >0 && productos != NULL && cantProductos > 0 && idUsuario >0){
		int auxId;
		int maxId;
		int pocicion;

		maxId = T_BuscarIdMayor(tracking,cantidadTracking,EN_VIAJE);
		if(N_MostrarTrackingsComprador(tracking,cantidadTracking,EN_VIAJE,productos,cantProductos,idUsuario)>0){
			if(getIntInRange("Ingrese una id:",3,0,maxId,"Id invalida,",&auxId)==1){

				pocicion = T_FindTrackingById(tracking,cantidadTracking,auxId);
				puts("Compra seleccionada para cancelar:");
				printf( "+------+---------------------+-----------+---------------------+-----------+----------------------------+\n"
						"|  Id  | Nombre de producto  | Cantidad  | Precio              | Estado    | Fecha de entrega           |\n"
						"+------+---------------------+-----------+---------------------+-----------+----------------------------+\n");
				N_MostrarTracking(tracking,pocicion,productos,cantProductos);
				puts(" ");
				if(PedirVerificacion("Desea dar de baja este Producto?","Opcion invalida")==1){
					tracking[pocicion].isEmpty=CANCELADO;
					puts("<<<<<-----| Baja exitosa |----->>>>>\n");
					rtn =1;
				}
				else{
					puts("<<<<<----| Baja Cancelada |---->>>>>\n");
					rtn =0;
				}
			}
		}
	}
	return rtn;
}

int N_EstadoDeVentas(eTracking tracking[],int cantidadTracking,eProductos productos[],int cantProductos, int idUsuario){
	int rtn =-1;
	int opcion;
	if(tracking != NULL && cantidadTracking >0 && productos != NULL && cantProductos > 0 && idUsuario >0){
		opcion =-1;
		do{
			rtn =1;
			printf( "\n"
					"<<->>+------------------------+<<->>\n"
					"<>-<>|    ESTADO DE VENTAS    |<>-<>\n"
					"<<->>+------------------------+<<->>\n"
					"<>                                <>\n"
					"<>    (1) - Ventas finalizadas    <>\n"
					"<>    (2) - Ver productos         <>\n"
					"<>                                <>\n"
					"<>    (0) - Salir                 <>\n"
					"<>                                <>\n"
					"<<->>+------------------------+<<->>\n\n");
			if(getIntInRange("Ingrese una opcion:",3,0,2,"Opcion invalida,",&opcion) == 1 && opcion >= 1){
				switch(opcion){
				case 1:
					if(T_VerificarVentasUsuario(tracking,cantidadTracking,idUsuario)>0){
					N_MostrarTrackingsVendedor(tracking,cantidadTracking,FINALIZADAS,productos,cantProductos,idUsuario);
					}
					else{puts("<<<<<------| Sin ventas |------>>>>>\n");
					}
					break;
				case 2:
					if(P_VerificarProductosYStock(productos,cantProductos)>0){
						P_MostrarProductosVendedor(productos,cantProductos,OCUPADO,idUsuario);
					}
					else{puts("<<<<<----| Sin  Productos |---->>>>>\n");
					}
					break;
				}
			}
			else{opcion=0;
			}
		}while(opcion!=0);
	}
	return rtn;
}

int N_AltaDeUnUsuarioDadoDeBaja(eUsuarios usuarios[],int cantUsuarios,eProductos productos[],int cantProductos){
	int rtn =-1;
	int idUsuario;
	if(usuarios != NULL && cantUsuarios > 0 && productos != NULL && cantProductos > 0){
		idUsuario = U_AltaUsuarioExistente(usuarios,cantUsuarios);
		if(idUsuario >0){
			if(P_AltaDeProductosDelUsuario(productos,cantProductos,idUsuario)==1){
				rtn=1;
			}
		}
	}
	return rtn;
}
