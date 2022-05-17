/*
 ============================================================================
 Name        : Primer.c
 Author      : Donato Alejandro Damian
  ============================================================================
 */

#include "NEXO.h"

int main(void) {
	setbuf(stdout,NULL);

int salir;
int opcion;
int subOpcion;
int idUsuarioIngresado;
int menu=0;

eUsuarios usuarios[MAX_USUARIOS];
eProductos productos[MAX_PRODUCTOS];
eTracking tracking[MAX_TRACKING];

U_InicializarUsuarios(usuarios,MAX_USUARIOS,LIBRE);
P_InicializarProductos(productos,MAX_PRODUCTOS,LIBRE);
T_InicializarTracking(tracking,MAX_TRACKING,LIBRE);

U_ADMIN(usuarios,MAX_USUARIOS);



do{
	switch(menu){
	case 0://menu principal
		printf(	"\n"
				"<<->>+<><><><><><><><><><><><>+<<->>\n"
				"<>-<>| 1er EXAMEN  LAB I - 1H |<>-<>\n"
				"<<->>+<><><><><><><><><><><><>+<<->>\n"
				"<>                                <>\n"
				"<<->>+------------------------+<<->>\n"
				"<>-<>|      MENU INICIAL      |<>-<>\n"
				"<<->>+------------------------+<<->>\n"
				"<>                                <>\n"
				"<>   (1) - INGRESAR               <>\n"
				"<>   (2) - REGISTRARSE            <>\n"
				"<>                                <>\n"
				"<>   (0) - SALIR                  <>\n"
				"<>                                <>\n"
				"<<->>+<><><><><><><><><><><><>+<<->>\n\n");
		if(getIntInRange("     Ingrese una opcion:",3,0,3,"Opcion invalida",&opcion) !=1){
			puts("<<->>-------<| ERROR |>-------<<->>");
			salir =1;
		}
		switch(opcion){
		case 1://Ingresar
			puts("<<->>+------------------------+<<->>\n"
				 "<>-<>|        INGRESAR        |<>-<>\n"
				 "<<->>+------------------------+<<->>\n");
			if(U_Ingresar(usuarios,MAX_USUARIOS,&idUsuarioIngresado,3)==1){
				puts("<<<<<| Usuario y contraseña correctos |>>>>>\n");
				menu=1;
			}
			else{puts("-----| ERROR DE INGRESO |-----\n");
			}
			break;
		case 2://Registrarse
			puts("<<->>+------------------------+<<->>\n"
				 "<>-<>|       REGISTRARSE      |<>-<>\n"
				 "<<->>+------------------------+<<->>\n");
			if(U_AltaUsuario(usuarios,MAX_USUARIOS,USUARIO)>=0){
				puts("<<<<<|   Registro  exitoso   |>>>>>\n");
			}
			else{puts("<<->>-------<| ERROR |>-------<<->>");
			}
			break;
		case 3://harcodear
			puts("<<->>+------------------------+<<->>\n"
				 "<>-<>|        HARCODEO        |<>-<>\n"
				 "<<->>+------------------------+<<->>\n");
			U_HarcodearUsuarios(usuarios,MAX_USUARIOS);
			P_HarcodearProductos(productos,MAX_PRODUCTOS);
			T_HarcodearTrackings(tracking,MAX_TRACKING);
			break;
		case 0://salir
			puts("<<->>+------------------------+<<->>\n"
				 "<>-<>|    FIN DEL PROGRAMA    |<>-<>\n"
				 "<<->>+------------------------+<<->>\n");
			salir =1;
			break;
		}
		break;
	case 1://menu usuario
		switch(usuarios[U_FindUsuarioById(usuarios,MAX_USUARIOS,idUsuarioIngresado)].tipo){
		case USUARIO:
			printf(	"\n"
					"<<->>+<><><><><><><><><><><><>+<<->>\n"
					"<>-<>| 1er EXAMEN  LAB I - 1H |<>-<>\n"
					"<<->>+<><><><><><><><><><><><>+<<->>\n"
					"<>                                <>\n"
					"<<->>+------------------------+<<->>\n"
					"<>-<>|     %-19s|<>-<>\n"
					"<<->>+------------------------+<<->>\n"
					"<>                                <>\n"
					"<>   (1) - COMPRAR                <>\n"
					"<>   (2) - VENDER                 <>\n"
					"<>   (3) - ESTADO DE COMPRAS      <>\n"
					"<>   (4) - ESTADO DE VENTAS       <>\n"
					"<>                                <>\n"
					"<>   (0) - SALIR                  <>\n"
					"<>                                <>\n"
					"<<->>+<><><><><><><><><><><><>+<<->>\n\n"
					,usuarios[U_FindUsuarioById(usuarios,MAX_USUARIOS,idUsuarioIngresado)].nombre);
			if(getIntInRange("     Ingrese una opcion:",3,0,4,"Opcion invalida",&subOpcion) !=1){
				puts("<<->>-------<| ERROR |>-------<<->>");
				menu=0;
				idUsuarioIngresado=-1;
			}
			switch(subOpcion){
			case 1://COMPRAR
				if(P_VerificarProductosDeOtros(productos,MAX_PRODUCTOS,idUsuarioIngresado)>0){
					puts("<<->>+------------------------+<<->>\n"
						 "<>-<>|        COMPRAR         |<>-<>\n"
						 "<<->>+------------------------+<<->>\n");
					if(N_AltaTracking(usuarios,MAX_USUARIOS, productos,MAX_PRODUCTOS,tracking,MAX_TRACKING,idUsuarioIngresado)==1){
						puts("<<<<<|     Compra exitosa     |>>>>>\n");
					}
				}
				else{puts("<<>>| Sin Productos para comprar |<<>>");
				}
				break;
			case 2:// VENDER
				puts("<<->>+------------------------+<<->>\n"
					 "<>-<>|        VENDER          |<>-<>\n"
					 "<<->>+------------------------+<<->>\n");
				if(P_AltaProducto(productos,MAX_PRODUCTOS,idUsuarioIngresado)>=0){
					puts("<<<<<|     Carga  exitosa     |>>>>>\n");
				}
				break;
			case 3://ESTADO DE COMPRAS
				if(T_VerificarTreckingUsuario(tracking,MAX_TRACKING,idUsuarioIngresado)>0){
					puts("<<->>+------------------------+<<->>\n"
			  			 "<>-<>|    ESTADO DE COMPRAS   |<>-<>\n"
						 "<<->>+------------------------+<<->>\n");
					N_EstadoDeCompras(tracking,MAX_TRACKING,ALL,productos,MAX_PRODUCTOS,idUsuarioIngresado);
				}
				else{puts("<<>>| Sin productos comprados |<<>>");
				}
				break;
			case 4://ESTADO DE VENTAS
				if(T_VerificarVentasUsuario(tracking,MAX_TRACKING,idUsuarioIngresado)>0){
					N_EstadoDeVentas(tracking,MAX_TRACKING,productos,MAX_PRODUCTOS,idUsuarioIngresado);
				}
				else{puts("<<>>| Sin productos vendidos |<<>>");
				}
				break;
			case 0://DESCONECTANDOCE
				puts("<<->>+------------------------+<<->>\n"
					 "<>-<>|    DESCONECTANDOCE     |<>-<>\n"
					 "<<->>+------------------------+<<->>\n");
				menu=0;
				idUsuarioIngresado=-1;
				subOpcion=-1;
				break;
			}
			break;
		case ADMIN:
			printf(	"\n"
					"<<->>+<><><><><><><><><><><><>+<<->>\n"
					"<>-<>| 1er EXAMEN  LAB I - 1H |<>-<>\n"
					"<<->>+<><><><><><><><><><><><>+<<->>\n"
					"<>                                <>\n"
					"<<->>+------------------------+<<->>\n"
					"<>-<>|          ADMIN         |<>-<>\n"
					"<<->>+------------------------+<<->>\n"
					"<>                                <>\n"
					"<>   (1) - LISTAR ESTADO USUARIOS <>\n"
					"<>   (2) - LISTAR PRODUCTOS       <>\n"
					"<>   (3) - BAJA DE UN PRODUCTO    <>\n"
					"<>   (4) - BAJA DE UN USUARIO     <>\n"
					"<>   (5) - VER TRACKING GLOBAL    <>\n"
					"<>                                <>\n"
					"<>   (0) - SALIR                  <>\n"
					"<>                                <>\n"
					"<<->>+<><><><><><><><><><><><>+<<->>\n\n");
			if(getIntInRange("     Ingrese una opcion:",3,0,6,"Opcion invalida",&subOpcion) !=1){
				puts("<<->>-------<| ERROR |>-------<<->>");
				menu=0;
				idUsuarioIngresado=-1;
			}
			switch(subOpcion){
			case 1://LISTAR ESTADO USUARIOS
				if(U_ContarUsuarios(usuarios,MAX_USUARIOS,ALL)>0){
				puts("<<->>+------------------------+<<->>\n"
					 "<>-<>| LISTAR ESTADO USUARIOS |<>-<>\n"
					 "<<->>+------------------------+<<->>\n\n");
				U_MostrarUsuarios(usuarios,MAX_USUARIOS,ALL);
				}
				else{puts("<<>>| Sin usuarios registrados |<<>>");
				}
				break;
			case 2://LISTAR PRODUCTOS
				if(P_ContarProductos(productos,MAX_PRODUCTOS,OCUPADO)>0){
				puts("<<->>+------------------------+<<->>\n"
					 "<>-<>|    LISTAR PRODUCTOS    |<>-<>\n"
					 "<<->>+------------------------+<<->>\n");
				 	T_SortProductos(productos,MAX_PRODUCTOS,2);
					P_MostrarProductos(productos,MAX_PRODUCTOS,OCUPADO);
				}
				else{puts("<<>>| Sin productos registrados |<<>>");
				}
				break;
			case 3://BAJA DE UN PRODUCTO
				if(P_ContarProductos(productos,MAX_PRODUCTOS,OCUPADO)>0){
				puts("<<->>+------------------------+<<->>\n"
					 "<>-<>|   BAJA DE UN PRODUCTO  |<>-<>\n"
					 "<<->>+------------------------+<<->>\n");
					P_BajaDeUnProducto(productos,MAX_PRODUCTOS);
				}
				else{puts("<<>>| Sin productos registrados |<<>>");
				}
				break;
			case 4://BAJA DE UN USUARIO
				if(U_ContarUsuarios(usuarios,MAX_USUARIOS,OCUPADO)>0){
				puts("<<->>+------------------------+<<->>\n"
					 "<>-<>|   BAJA DE UN USUARIO   |<>-<>\n"
					 "<<->>+------------------------+<<->>\n");
					if(N_BajaDeUnUsuarioCompleta(usuarios,MAX_USUARIOS,productos,MAX_PRODUCTOS,tracking,MAX_TRACKING)==1){
						puts("<<<<<|      Baja exitosa      |>>>>>\n");
					}
					else{puts("<<->>--<| Baja no realizada |>--<<->>");
					}
				}
				else{puts("<<>>| Sin usuarios para baja |<<>>");
				}
				break;
			case 5://VER TRACKING GLOBAL
				if(T_ContarTracking(tracking,MAX_TRACKING,ALL)>0){
				puts("<<->>+------------------------+<<->>\n"
					 "<>-<>|   VER TRACKING GLOBAL  |<>-<>\n"
					 "<<->>+------------------------+<<->>\n");
					N_MostrarTrackings(tracking,MAX_TRACKING,ALL,productos,MAX_PRODUCTOS);
				}
				else{puts("<<->>--<| Sin trackings cargados |>--<<->>");
				}
				break;
			case 6://CANCELAR BAJA
				if(U_ContarUsuarios(usuarios,MAX_USUARIOS,BAJA)>0){
					puts("<<->>+------------------------+<<->>\n"
						 "<>-<>|     CANCELAR BAJA      |<>-<>\n"
						 "<<->>+------------------------+<<->>\n");
					if(N_AltaDeUnUsuarioDadoDeBaja(usuarios,MAX_USUARIOS,productos,MAX_PRODUCTOS)==1){
						puts("<<<<<|      Alta exitosa      |>>>>>\n");
					}
					else{puts("<<->>--<| Alta no realizada |>--<<->>");
					}
				}
				else{puts("<<->>--<| Sin usuarios dados de baja |>--<<->>");
				}
				break;
			case 0://DESCONECTANDOCE
				puts("<<->>+------------------------+<<->>\n"
					 "<>-<>|    DESCONECTANDOCE     |<>-<>\n"
					 "<<->>+------------------------+<<->>\n");
				menu=0;
				idUsuarioIngresado=-1;
				subOpcion=-1;
				break;
			}
			break;
		}
		break;
	}
}while(salir!=1);
	return EXIT_SUCCESS;
}
