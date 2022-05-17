#include "eTracking.h"

static int T_GenerarId(void);
static int T_GenerarId(void){
	static int contadorP = 1000;
	return contadorP++;
}
int T_GenerarIdTracking(void){
	int rtn;
	rtn = T_GenerarId();
	return rtn;
}

int T_HarcodearTrackings(eTracking tracking[],int cantidad){
	int rtn =-1;
	if(tracking != NULL && cantidad > 0){
		int j=0;
		for (int i = 0; i < cantidad; i++){
			if(tracking[i].isEmpty == 0){
				tracking[i].isEmpty = 1;
				tracking[i].idProducto=rand()%10+100;
				tracking[i].idUsuarioComprador=rand()%10+1000;
				tracking[i].idUsuarioVendedor=rand()%10+1000;
				tracking[i].idTracking = T_GenerarId();
				tracking[i].cantidad =rand()%1000;
				tracking[i].distanciaKM =rand()%130+20;
				tracking[i].horaLlegada =T_AgregarTiempo(tracking[i].distanciaKM);
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

int T_InicializarTracking(eTracking tracking[],int cantidad,int estado){
	int rtn =-1;
	if(tracking != NULL && cantidad > 0){
	for (int i = 0; i < cantidad; i++){
		tracking[i].isEmpty = estado;
	}
	rtn = 1;
	}
	return rtn;
}

int T_BuscarEspacioParaTrackingNuevo(eTracking tracking[],int cantidad){
	int rtn;
	int flag = 0;
	if(tracking != NULL){
		if(cantidad > 0){
			for(int i = 0;i<cantidad;i++){
				if( tracking[i].isEmpty == LIBRE){
					rtn = i;
					flag = 1;
					break;
				}
			}
			if(flag == 0){rtn = -3;//sin espacio en la trackinga
			}
		}
		else{rtn =-2;//cantidad != de 0
		}
	}
	else{rtn=-1;//array nulo
	}
return rtn;
}

int T_AddTracking(eTracking tracking[],int pocicion,int idTracking,int idProducto,int idUsuarioComprador,
			 	  int idUsuarioVendedor,int cantidad,int distanciKM,long int horaLlegada){
	int rtn;
	if(tracking != NULL && pocicion > -1){
		tracking[pocicion].idTracking = idTracking;
		tracking[pocicion].idProducto = idProducto;
		tracking[pocicion].idUsuarioComprador = idUsuarioComprador;
		tracking[pocicion].idUsuarioVendedor=idUsuarioVendedor;
		tracking[pocicion].cantidad=cantidad;
		tracking[pocicion].distanciaKM=distanciKM;
		tracking[pocicion].horaLlegada=horaLlegada;
		rtn = 1;
	}
	else{rtn = -1;
	}
return rtn;
}

int T_CalcularDistanciaEnKM(int codigoPostal,int *distancia){
	int rtn=-1;
	if(codigoPostal > 0 && distancia != NULL){
		if(codigoPostal >= 1 && codigoPostal <= 1000){
			*distancia = 20;
			rtn=1;
		}
		else if(codigoPostal >= 1001 && codigoPostal <= 3000){
			*distancia = 30;
			rtn=1;
		}
		else if(codigoPostal >= 3001 && codigoPostal <= 5000){
			*distancia = 50;
			rtn=1;
		}
		else if(codigoPostal >= 5001 && codigoPostal <= 8000){
			*distancia = 80;
			rtn=1;
		}
		else if(codigoPostal >= 8001 && codigoPostal <= 9999){
			*distancia = 150;
			rtn=1;
		}
	}
	return rtn;
}

long int T_TiempoActual(){
	return time(NULL);
}

long int T_AgregarTiempo(int distancia){
	return (distancia*TIEMPO_X_KM)+T_TiempoActual();
}

int T_EstadoTracking(eTracking tracking[], int cantidad,int idTracking){
	int rtn =-1;
	if(tracking[T_FindTrackingById(tracking,cantidad,idTracking)].isEmpty==EN_VIAJE){
		if(difftime(tracking[T_FindTrackingById(tracking,cantidad,idTracking)].horaLlegada,T_TiempoActual())<=0){
			tracking[T_FindTrackingById(tracking,cantidad,idTracking)].isEmpty=ENTREGADO;
			rtn=1;
		}
	}
	return rtn;
}

int T_FindTrackingById(eTracking tracking[], int cantidad,int id){
	int rtn = -1;
	for(int i = 0;i < cantidad; i++){
		if(tracking[i].idTracking == id){
			rtn = i;
			break;
		}
	}
	return rtn;
}

int T_ContarTracking(eTracking tracking[],int cantidad, int estado){
	int contador = -1;
	if(tracking != NULL && cantidad >0){
	contador = 0;
		for(int i = 0;i<cantidad;i++){
			if(estado == 411 && tracking[i].isEmpty >0){
				contador++;
			}
			if( tracking[i].isEmpty == estado){
				contador++;
			}
		}
	}
	return contador;
}

int T_BuscarIdMayor(eTracking tracking[],int cantidad, int estado){
	int auxMaxId =-1;
	if(tracking != NULL && cantidad >0){
		auxMaxId =0;
		for(int i = 0;i<cantidad;i++){
			if(estado == 411 && tracking[i].idTracking>auxMaxId){
				auxMaxId = tracking[i].idTracking;
			}
			if( tracking[i].isEmpty == estado && tracking[i].idTracking>auxMaxId ){
				auxMaxId = tracking[i].idTracking;
			}
		}
	}
	return auxMaxId;
}

int T_BajaDeTrackingDelUsuario(eTracking tracking[],int cantidad,int idUsuario){
	int rtn=-1;
	int i;
	if(tracking != NULL && cantidad > 0){
		for(i = 0; i < cantidad; i++){
			if(tracking[i].idUsuarioComprador==idUsuario){
				tracking[i].isEmpty=CANCELADO;
			}
		}
		rtn=1;
	}
	return rtn;
}

int T_VerificarTreckingUsuario(eTracking tracking[],int cantidad, int idUsuario){
	int contador = -1;

	if(tracking != NULL && cantidad >0 && idUsuario >0){
		contador = 0;
		for(int i = 0;i<cantidad;i++){
			if( tracking[i].idUsuarioComprador == idUsuario){
				contador++;
			}
		}
	}
	return contador;
}

int T_VerificarVentasUsuario(eTracking tracking[],int cantidad, int idUsuario){
	int contador = -1;

	if(tracking != NULL && cantidad >0 && idUsuario >0){
		contador = 0;
		for(int i = 0;i<cantidad;i++){
			if( tracking[i].idUsuarioVendedor == idUsuario){
				contador++;
			}
		}
	}
	return contador;
}
