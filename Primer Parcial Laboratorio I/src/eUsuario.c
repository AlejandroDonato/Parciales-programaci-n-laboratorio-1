#include "eUsuario.h"

static int U_GenerarId(void);
static int U_GenerarId(void){
	static int contadorP = 1000;
	return contadorP++;
}

int U_Ingresar(eUsuarios usuarios[],int cantidadUsuarios,int *idUsuario,int reintentos){
	int rtn=-1;
	char auxNombre[MAX_CHARS];
	char auxPass[MAX_CHARS];
	int intentos;
	int i;

	if(usuarios != NULL && cantidadUsuarios > 0){
		intentos=0;
		do{
			if(GetArrayCharsAndIntWithRetrys("nombre de usuario:",3,"Error,",auxNombre,MAX_CHARS)==1){
				if(GetArrayCharsAndIntWithRetrys("Contraseña:",3,"Error,",auxPass,MAX_CHARS)==1){
					for (i = 0; i < cantidadUsuarios; ++i) {
						if( strcmp(usuarios[i].nombre,auxNombre)==0 &&
							strcmp(usuarios[i].password,auxPass)==0 &&
							strlen(auxNombre)>0&& strlen(auxPass)>0 &&
							usuarios[i].isEmpty == OCUPADO){
								*idUsuario = usuarios[i].idUsuario;
								rtn=1;
								break;
						}
					}
					if(rtn!=1){
						puts("Nonbre o contraceña incorrecta");
						intentos++;
					}
				}
			}
			if(rtn == 1){
				break;
			}
		}while(reintentos!=intentos);
	}
	return rtn;
}

int U_HarcodearUsuarios(eUsuarios usuarios[],int cantidad){
	int rtn =-1;
	char nombre[10][MAX_CHARS]={"asd","Usuario2","Usuario3","Usuario4","Usuario5","Usuario6","Usuario7","Usuario8","Usuario9","Usuario10"};
	char direccion[10][MAX_CHARS]={"calle111","calle222","calle333","calle444","calle555","calle666","calle777","calle888","calle999","calle000"};
	char password[11]={"asd123"};
	char correo[MAX_CHARS]={"email@algo.com"};
	int i;
	int j = 0;

	if(usuarios != NULL && cantidad > 0){
		for (i = 0; i < cantidad; i++){
			if(usuarios[i].isEmpty == 0){
				usuarios[i].idUsuario = U_GenerarId();
				strcpy(usuarios[i].nombre,nombre[j]);
				strcpy(usuarios[i].direccion,direccion[j]);
				strcpy(usuarios[i].password,password);
				strcpy(usuarios[i].correo,correo);
				usuarios[i].codigoPostal = rand()%9999;
				usuarios[i].tipo =  USUARIO;
				usuarios[i].isEmpty = OCUPADO;
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

int U_InicializarUsuarios(eUsuarios usuarios[],int cantidad,int estado){
	int rtn =-1;
	if(usuarios != NULL && cantidad > 0){
		for (int i = 0; i < cantidad; i++){
			usuarios[i].isEmpty = estado;
		}
		rtn = 1;
	}
	return rtn;
}

int U_MostrarUsuarios(eUsuarios usuarios[],int cantidad,int estado){
	int contador = -1;
	int flagContador =-1;
	if(usuarios != NULL && cantidad>0){
		contador = 0;
		printf( "\n"
				"+------+---------------------+---------------------+--------------+\n"
				"|  Id  | Usuario             | Correo              | Estado       |\n"
				"+------+---------------------+---------------------+--------------+\n");
		for(int i = 0;i<cantidad;i++){
			if(estado == 411 && usuarios[i].isEmpty> 0 && usuarios[i].tipo == USUARIO){
				U_MostrarUsuario(usuarios,i);
				contador++;
				flagContador =1;
			}
			if( usuarios[i].isEmpty == estado && usuarios[i].tipo == USUARIO){
				U_MostrarUsuario(usuarios,i);
				contador++;
				flagContador =1;
			}
		}
		if(flagContador == -1){
			printf( "+-----------------------------------------------------------------+\n"
					"|  No hay usuarios para mostrar                                   |\n"
					"+-----------------------------------------------------------------+\n"
					"No hay usuarios para mostrar\n");
		}
	}
	return contador;
}

void U_MostrarUsuario(eUsuarios usuarios[],int posicion){

	char auxEstado[MAX_CHARS];

	switch (usuarios[posicion].isEmpty){
	case 1:
		strcpy(auxEstado,"ALTA");
		break;
	case 2:
		strcpy(auxEstado,"BAJA");
		break;
	}
	printf( "|%-6d| %-20s| %-20s| %-13s|\n"
			"+------+---------------------+---------------------+--------------+\n",
			usuarios[posicion].idUsuario,
			usuarios[posicion].nombre,
			usuarios[posicion].correo,
			auxEstado);
}

int U_BuscarEspacioParaUsuarioNuevo(eUsuarios usuarios[],int cantidad){
	int rtn;
	int flag = 0;
	if(usuarios != NULL && cantidad>0){
		for(int i = 0;i<cantidad;i++){
			if( usuarios[i].isEmpty == LIBRE){
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

int U_SeleccionarUsuarios(eUsuarios usuarios[],int cantidad,short int tipo){
	int rtn=-3;
	int opcion;
	int auxId;
	if(usuarios != NULL && cantidad > 0){
		if(getIntInRange("Ingrese una opcion:\n\t1 - Usuario nuevo \n\t2 - Usuario existente\n\t3 - Usuario dado de baja",3,1,3,"Opcion invalida",&opcion) ==1){
			switch (opcion) {
				case 1:
					auxId=U_AltaUsuario(usuarios,cantidad,tipo);
					if(auxId>-1){
						rtn=auxId;
					}
					break;
				case 2:

					if(U_GetIdUsuarioFromList(usuarios,cantidad,&auxId,OCUPADO)==1){

						rtn=auxId;
					}
					break;
				case 3:
					auxId=U_AltaUsuarioExistente(usuarios,cantidad);
					if(auxId>-1){
						rtn=auxId;
					}
					break;
			}
		}
		else{rtn=-2;
		}
	}
return rtn;
}

int U_OpcionAltaUsuarios(eUsuarios usuarios[],int cantidad,short int tipo){
	int rtn=-1;
	int opcion;
	if(usuarios != NULL && cantidad > 0){
		if(getIntInRange("Ingrese una opcion:\n\t1 - Usuario nuevo \n\t2 - Usuario dado de baja",3,1,2,"Opcion invalida",&opcion) ==1){
			switch (opcion) {
				case 1:
					if(U_AltaUsuario(usuarios,cantidad,tipo)>-1){
						rtn=1;
					}
					break;
				case 2:
					if(U_AltaUsuarioExistente(usuarios,cantidad)>-1){
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

int U_AltaUsuario(eUsuarios usuarios[],int cantidad,short int tipo){
	int rtn;
	int usuarioLibre;

	int auxId;
	char auxNombre[MAX_CHARS];
	char auxCorreo[MAX_CORREO];
	char auxDireccion[MAX_CHARS];
	int  auxCodigoPostal;
	char auxPassword[MAX_PASSWORD];

	if(usuarios != NULL && cantidad > 0){
		usuarioLibre = U_BuscarEspacioParaUsuarioNuevo(usuarios,cantidad);
		if(usuarioLibre != -1){
			if(U_NombreDeUsuario(usuarios,cantidad,auxNombre) == 1){//NOMBRE
				if(GetEmail(3,auxCorreo,MAX_CORREO) == 1){//CORREO
					if(GetArrayCharsAndIntWithRetrys("Ingrese direccion:",3,"Direccion incorrecta",auxDireccion,MAX_CHARS) == 1){//DIRECCION
						if(getIntInRange("Ingrese codigo postal:", 3, 1, 9999,"Codigo postal incorrecto", &auxCodigoPostal) == 1){//CODIGOPOSTAL
							if(GetPassword(3,4,10,auxPassword) == 1){//CONTRASEÑA
								auxId = U_GenerarId();
								if(U_AddUsuario(usuarios,usuarioLibre,auxId,auxNombre,auxCorreo,auxDireccion,auxCodigoPostal,auxPassword,tipo)==1){
									usuarios[usuarioLibre].isEmpty = OCUPADO;
									rtn =auxId;
								}
								else{rtn =-8;//error en la carga de la funcion addUsuario
								}
							}
							else{rtn =-7;//error en la carga de la contraceña
							}
						}
						else{rtn =-6;//error en la carga del codigo postal
						}
					}
					else{rtn =-5;//error en la carga de la direccion
					}
				}
				else{rtn =-4;//error en la cargar del E-mail del Usuario
				}
			}
			else{rtn =-3;//error en la carga del nombre del Usuario
			}
		}
		else{rtn =-2;//error al buscar espacio libre
		}
	}
	else{rtn =-1;//error estructura o cantidad nula
	}
return rtn;
}

int U_AddUsuario(eUsuarios usuarios[], int posicion, int id, char nombre[],char correo[],char direccion[],int codigoPostal,char password[],short int tipo){
	int rtn;
	if(usuarios != NULL && posicion > -1 && id >= 0 && nombre != NULL && correo != NULL && direccion != NULL && codigoPostal >= 0 && password != NULL){
		usuarios[posicion].idUsuario = id;
		strcpy(usuarios[posicion].nombre,nombre);
		strcpy(usuarios[posicion].direccion,direccion);
		strcpy(usuarios[posicion].password,password);
		strcpy(usuarios[posicion].correo,correo);
		usuarios[posicion].codigoPostal = codigoPostal;
		usuarios[posicion].tipo = tipo;
		rtn = 1;
	}
	else{rtn = -1;
	}
return rtn;
}

int U_NombreDeUsuario(eUsuarios usuarios[],int cantidad,char nombre[]){
	int rtn=-1;
	int flagNombre;
	char auxNombre[MAX_CHARS];
	int i;
	int contador=0;
	if(usuarios !=NULL && cantidad>0 && nombre!=NULL){
		do{
			flagNombre=1;
			if(GetArrayCharsAndIntWithRetrys("Ingrese Nombre del usuario:",3,"Nombre incorrecto",auxNombre,MAX_CHARS) == 1){
				for(i = 0; i < cantidad; ++i) {
					if(strcmp(usuarios[i].nombre,auxNombre)==0){
						flagNombre=-1;
						puts("Nombre no disponible");
						contador++;
						break;
					}
				}
				if(flagNombre==1){
					rtn =1;
					strncpy(nombre,auxNombre,MAX_CHARS);
				}
				if(contador==3 && flagNombre ==-1){
					flagNombre=1;
				}
			}
		}while(flagNombre!=1);
	}
	return rtn;
}

int U_AltaUsuarioExistente(eUsuarios usuarios[],int cantidad){
	int rtn;
	int posicion;
	int auxId;
	int maxId;

	if(usuarios != NULL && cantidad > 0){
		U_MostrarUsuarios(usuarios,cantidad,BAJA);
		maxId = U_BuscarIdMayor(usuarios,cantidad,BAJA);
		if(getIntInRange("Ingrese una id:",3,0,maxId,"Id invalida,",&auxId)==1){
			posicion = U_FindUsuarioById(usuarios,cantidad,auxId);
			printf( "Usuario a dar de alta:\n"
					"+------+---------------------+---------------------+--------------+\n"
					"|  Id  | Usuario             | Correo              | Estado       |\n"
					"+------+---------------------+---------------------+--------------+\n");
			U_MostrarUsuario(usuarios,posicion);
			puts(" ");
			if(PedirVerificacion("Desea dar de alta este usuario?","Opcion invalida")==1){
				usuarios[posicion].isEmpty = OCUPADO;
				rtn =usuarios[posicion].idUsuario;
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

int U_FindUsuarioById(eUsuarios usuarios[], int cantidad,int idUsuario){
	int rtn = -1;
	for(int i = 0;i < cantidad; i++){
		if(usuarios[i].idUsuario == idUsuario){
			rtn = i;
			break;
		}
	}
	return rtn;
}

int U_BajaDeUnUsuario(eUsuarios usuarios[], int cantidad,int *idUsuario){
	int rtn =-1;
	if(usuarios != NULL && cantidad > 0){
		int auxId;
		int maxId;
		int posicion;

		maxId = U_BuscarIdMayor(usuarios,cantidad,OCUPADO);
		U_MostrarUsuarios(usuarios,cantidad,OCUPADO);

		if(getIntInRange("Ingrese una id:",3,0,maxId,"Id invalida,",&auxId)==1){

			posicion = U_FindUsuarioById(usuarios,cantidad,auxId);
			printf(	"Usuario seleccionado para eliminar:\n"
					"+------+---------------------+---------------------+--------------+\n"
					"|  Id  | Usuario             | Correo              | Estado       |\n"
					"+------+---------------------+---------------------+--------------+\n");
			U_MostrarUsuario(usuarios,posicion);
			puts(" ");
			if(PedirVerificacion("Desea dar de baja este Usuario?","Opcion invalida")==1){
				usuarios[posicion].isEmpty=BAJA;
				*idUsuario = auxId;
				rtn =1;
			}
			else{
				rtn =0;
			}
		}
	}
	return rtn;
}

int U_ContarUsuarios(eUsuarios usuarios[],int cantidad, int estado){
	int contador = -1;

	if(usuarios != NULL && cantidad >0){
		contador = 0;
		for(int i = 0;i<cantidad;i++){
			if(estado == 411 && usuarios[i].isEmpty> 0 && usuarios[i].tipo == USUARIO){
				contador++;
			}
			if( usuarios[i].isEmpty == estado && usuarios[i].tipo == USUARIO){
				contador++;
			}
		}
	}
	return contador;
}

int U_BuscarIdMayor(eUsuarios usuarios[],int cantidad, int estado){
	int auxMaxId =-1;
	if(usuarios != NULL && cantidad >0){
		auxMaxId =0;
		for(int i = 0;i<cantidad;i++){
			if(estado == 411 && usuarios[i].idUsuario>auxMaxId){
				auxMaxId = usuarios[i].idUsuario;
			}
			if( usuarios[i].isEmpty == estado && usuarios[i].idUsuario>auxMaxId ){
				auxMaxId = usuarios[i].idUsuario;
			}
		}
	}
	return auxMaxId;
}

int U_GetIdUsuarioFromList(eUsuarios usuarios[],int cantidad,int *idUsuario, int estado){
	int rtn=-1;
	int auxIdUsuarioMayor;
	int auxIdUsuario;
	int flagId = -1;
	int contador =0;
	int i;

	if(usuarios != NULL && cantidad >0){
		U_MostrarUsuarios(usuarios,cantidad,estado);
		auxIdUsuarioMayor = U_BuscarIdMayor(usuarios,cantidad,estado);
		do{
			if(getIntInRange("Ingrese Id del Usuario:",3,0,auxIdUsuarioMayor,"Opcion invalida,",&auxIdUsuario) == 1 ){
				for (i = 0; i < cantidad; ++i) {
					if(usuarios[i].idUsuario == auxIdUsuario){
						*idUsuario = auxIdUsuario;
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

int U_ADMIN(eUsuarios usuarios[],int cantidad){
	int rtn =-1;
	char nombre[MAX_CHARS]={"Kitsune"};
	char direccion[MAX_CHARS]={"Falsa 123"};
	char password[11]={"asd123"};
	char correo[MAX_CHARS]={"email@algo.com"};
	int libre;

	if(usuarios != NULL && cantidad > 0){
		libre = U_BuscarEspacioParaUsuarioNuevo(usuarios,cantidad);
		usuarios[libre].idUsuario = U_GenerarId();
		strcpy(usuarios[libre].nombre,nombre);
		strcpy(usuarios[libre].direccion,direccion);
		strcpy(usuarios[libre].password,password);
		strcpy(usuarios[libre].correo,correo);
		usuarios[libre].codigoPostal = rand()%9999;
		usuarios[libre].tipo = ADMIN;
		usuarios[libre].isEmpty = 1;
		rtn = 1;
	}
	return rtn;
}
