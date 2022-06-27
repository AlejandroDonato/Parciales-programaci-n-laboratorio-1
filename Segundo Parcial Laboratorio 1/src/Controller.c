#include "Controller.h"

/////////////////SALON/////////////////
int controller_loadSalonFromText(char* path , LinkedList* pListSalones){
	int rtn = -1;
	FILE* pFile;
	if(pListSalones != NULL && path != NULL){
		pFile = fopen(path,"r");
		if(pFile != NULL && parser_SalonFromText(pFile ,pListSalones) == 1){
			rtn = 1;
		}
		fclose(pFile);
	}
	return rtn;
}

int controller_loadSalonFromBinary(char* path , LinkedList* pListSalones){
	int rtn = -1;
	FILE* pFile;
	if(pListSalones != NULL && path != NULL){
		pFile = fopen(path,"rb");
		if(pFile != NULL){
			parser_SalonFromBinary(pFile ,pListSalones);
			fclose(pFile);
			rtn = 1;
		}
	}
	return rtn;
}

int controller_addSalon(LinkedList* pListSalones){
	int rtn;
		char auxName[MAX_CHARS];
		char auxDireccion[MAX_CHARS];
		int auxTipo;
		Salon* auxSalon;
		if(pListSalones != NULL){
			if(GetArrayCharsWithRetrys("Ingrese Nombre del Salon:",3,"Nombre invalido,",auxName,MAX_CHARS) == 1 &&
				GetAddresWithRetrys("Ingrese Dirección:",3,"dirección invalida,",auxDireccion,MAX_CHARS) == 1 &&
				getIntInRange("Ingrese Tipo:\n\t 1- Shoping \n\t 2- local \n",3,1,2,"Opcion invalida,",&auxTipo) == 1){
				auxSalon = Salon_newParametros(auxName,auxDireccion,auxTipo);
				if(auxSalon != NULL){
					ll_add(pListSalones,auxSalon);
					rtn =1;
					printf( "+----------+------------------------------+------------------------------+------------------------------+\n"
							"| Id       | Nombre del salon             | dirección                    | Tipo de salon                |\n"
							"+----------+------------------------------+------------------------------+------------------------------+\n");
					Salon_showSalon(auxSalon);
					printf( "+----------+------------------------------+------------------------------+------------------------------+\n");
				}
				else{rtn =-3;//error al salon new parametros
				}
			}
			else{rtn =-2;//error al cargar de datos pedidos
			}
		}
		else{rtn =-1;//error NULL
		}
	return rtn;
}

int controller_removeSalon(LinkedList* pListSalones, LinkedList* pListArcade){
	int rtn = -1;
	int auxId;
	int maxIdS;
	int i;
	Salon* auxSalon;
	Arcade* auxArcade;
	if(pListSalones != NULL && pListArcade != NULL){
		controller_ListSalones(pListSalones);
		maxIdS = Salon_findMaxId(pListSalones);
		if(getIntInRange("Ingrese el Id del salon que desea eliminar",3,1,maxIdS,"Opcion invalida,",&auxId) == 1){
			auxSalon = Salon_findSalonById(pListSalones,auxId);
			if(auxSalon != NULL && PedirVerificacion("Seguro desea eliminar este salon?","Opcion invalida")==1){
				if(ll_remove(pListSalones,ll_indexOf(pListSalones,auxSalon))==0){
					for (i = 0; i < ll_len(pListArcade); ++i) {
						auxArcade = ll_get(pListArcade,i);
						if(auxArcade->idSalon == auxSalon->id){
							ll_remove(pListArcade,ll_indexOf(pListArcade,auxArcade));
							free(auxArcade);
							auxArcade = NULL;
						}
					}					//if(controller_removeArcadeByIdSalon(pListArcade,auxId)==1){
					free(auxSalon);
					auxSalon = NULL;
					rtn = 1;
				}
			}
		}
	}
	return rtn;
}

int controller_countSalones(LinkedList* pListSalones){
	int contador = -1;
	Salon* auxPassenger;
	if(pListSalones != NULL){
		contador = 0;
		for(int i = 0;i<ll_len(pListSalones);i++){
			auxPassenger = ll_get(pListSalones,i);
			if(auxPassenger != NULL){
				contador++;
			}
		}
	}
	return contador;
}

int controller_ListSalones(LinkedList* pListSalones){
	int contador = -1;
	int i;
	Salon* auxSalon;
	if(pListSalones != NULL){
		contador = 0;
		printf( "+----------+------------------------------+------------------------------+------------------------------+\n"
				"| Id       | Nombre del salon             | Dirección                    | Tipo de salon                |\n"
				"+----------+------------------------------+------------------------------+------------------------------+\n");
		for(i = 0;i<ll_len(pListSalones);i++){
			auxSalon = ll_get(pListSalones,i);
			if(auxSalon != NULL){
				Salon_showSalon(auxSalon);
				contador++;
			}
		}
		printf( "+----------+------------------------------+------------------------------+------------------------------+\n");
	}
	return contador;
}

int controller_saveSalonAsBinary(char* path , LinkedList* pArrayListSalon){
	int rtn = -1;
	FILE* file;
	Salon* auxSalon;
	int len;
	int i;
	if(path != NULL && pArrayListSalon != NULL){
		len = ll_len(pArrayListSalon);
		if(len > 0){
			file = fopen(path,"wb");
			if(file!=NULL){
				for(i=0;i<len;i++){
					auxSalon = ll_get(pArrayListSalon,i);
					if(auxSalon != NULL){
						fwrite(auxSalon,sizeof(Salon),1,file);
					}
				}
				fclose(file);
				if(i == len){
					rtn = 1;
				}
			}
		}
		else{
			rtn = 0;
		}
	}
	return rtn;
}

int controller_saveSalonAsText(char* path,LinkedList* pArrayListSalon){
	int rtn = -1;
	FILE* pfile;
	Salon* auxSalon;
	int len = -1;
	int i;
	if(path != NULL && pArrayListSalon != NULL){
		len = ll_len(pArrayListSalon);
		if(len > 0){
			pfile = fopen(path,"w");
			if(pfile!=NULL){
				for(i=0;i<len;i++){
					auxSalon=(Salon*)ll_get(pArrayListSalon,i);
					fprintf(pfile,"%d,%s,%s,%d\n",auxSalon->id,auxSalon->nombre,auxSalon->direccion,auxSalon->tipo);
				}
				fclose(pfile);
				if(i == len){
					rtn = 1;
				}
			}
		}
		else{rtn = 0;
		}
	}
	return rtn;
}

/////////////////ARCADE/////////////////

int controller_loadArcadeFromText(char* path , LinkedList* pListArcades){
	int rtn = -1;
	FILE* pFile;
	if(pListArcades != NULL && path != NULL){
		pFile = fopen(path,"r");
		if(pFile != NULL && parser_ArcadeFromText(pFile ,pListArcades) == 1){
			rtn = 1;
		}
		fclose(pFile);
	}
	return rtn;
}

int controller_loadArcadeFromBinary(char* path , LinkedList* pListArcades){
	int rtn = -1;
	FILE* pFile;
	if(pListArcades != NULL && path != NULL){
		pFile = fopen(path,"rb");
		if(pFile != NULL){
			parser_ArcadeFromBinary(pFile ,pListArcades);
			fclose(pFile);
			rtn = 1;
		}
	}
	return rtn;
}

int controller_addArcade(LinkedList* pListArcades,LinkedList* pListSalones,LinkedList* pListGames){
	int rtn;
		char auxNacionalidad[MAX_CHARS];
		int auxTipoSonido;
		int auxCantJugadores;
		int auxCantFichas;
		int auxIdJuego;
		int auxIdSalon;
		Arcade* auxArcade;
		Salon* auxSalon;
		Game* auxJuego;
		int auxMaxIdJuego;
		int auxMaxIdSalon;
		if(pListArcades != NULL && pListSalones != NULL && pListGames != NULL){
			if(GetArrayCharsWithRetrys("Ingrese nacionalidad del arcade:",3,"Nacionalidad invalido,",auxNacionalidad,MAX_CHARS) == 1 &&
				getIntInRange("Ingrese Tipo sonido:\n\t 1- mono \n\t 2- estéreo \n",3,1,2,"Opcion invalida,",&auxTipoSonido) == 1 &&
				getIntInRange("Ingrese cantidad de jugadores (1-4):",3,1,4,"Opcion invalida,",&auxCantJugadores) == 1 &&
				getIntInRange("Ingrese cantidad de fichas",3,1,1000,"Opcion invalida,",&auxCantFichas) == 1){
				controller_ListGames(pListGames);
				auxMaxIdJuego = Game_findMaxId(pListGames);
				if(getIntInRange("Ingrese id del juego que desea cargar:",3,1,auxMaxIdJuego,"Opcion invalida,",&auxIdJuego) ==1){
					controller_ListSalones(pListSalones);
					auxMaxIdSalon = Salon_findMaxId(pListSalones);
					if(getIntInRange("Ingrese id del salon donde se encontrara el arcade:",3,1,auxMaxIdSalon,"Opcion invalida,",&auxIdSalon)==1){
						auxArcade = Arcade_newParametros(auxNacionalidad,auxTipoSonido,auxCantJugadores,auxCantFichas,auxIdJuego,auxIdSalon);
							if(auxArcade != NULL){
							ll_add(pListArcades,auxArcade);
							rtn =1;
							auxSalon = Salon_findSalonById(pListSalones,auxIdSalon);
							auxJuego = Game_findGamebyId(pListGames,auxIdJuego);
							printf( "+------+---------------------+-----------+-----------+-----------+---------------------+---------------------+\n"
									"| Id   | Nacionalidad        | sonido    | jugadores | fichas    |  juego              | salon               |\n"
									"+------+---------------------+-----------+-----------+-----------+---------------------+---------------------+\n");
							Arcade_showArcade(auxArcade,auxJuego->nombre,auxSalon->nombre);
							printf( "+------+---------------------+-----------+-----------+-----------+---------------------+---------------------+\n");
						}
					}
				}
				else{rtn =-3;//error al arcade new parametros
				}
			}
			else{rtn =-2;//error al cargar de datos pedidos
			}
		}
		else{rtn =-1;//error NULL
		}
	return rtn;
}

int controller_countArcades(LinkedList* pListArcades){
	int contador = -1;
	Arcade* auxPassenger;
	if(pListArcades != NULL){
		contador = 0;
		for(int i = 0;i<ll_len(pListArcades);i++){
			auxPassenger = ll_get(pListArcades,i);
			if(auxPassenger != NULL){
				contador++;
			}
		}
	}
	return contador;
}

int controller_ListArcades(LinkedList* pListArcades,LinkedList* pListSalones,LinkedList* pListGames){
	int contador = -1;
	int i;
	Arcade* auxArcade;
	Salon* auxSalon;
	Game* auxJuego;
	if(pListArcades != NULL && pListSalones != NULL && pListGames != NULL){
		contador = 0;
		printf( "+------+---------------------+-----------+-----------+-----------+---------------------+---------------------+\n"
				"| Id   | Nacionalidad        | Sonido    | Jugadores | Fichas    |  Juego              | Salon               |\n"
				"+------+---------------------+-----------+-----------+-----------+---------------------+---------------------+\n");
		for(i = 0;i<ll_len(pListArcades);i++){
			auxArcade = ll_get(pListArcades,i);
			if(auxArcade != NULL){
				auxJuego = Game_findGamebyId(pListGames,auxArcade->idJuego);
				auxSalon = Salon_findSalonById(pListSalones,auxArcade->idSalon);
				if(auxJuego != NULL && auxSalon != NULL){
					Arcade_showArcade(auxArcade,auxJuego->nombre,auxSalon->nombre);
					contador++;
				}
			}
		}
		printf( "+------+---------------------+-----------+-----------+-----------+---------------------+---------------------+\n");
	}
	return contador;
}

int controller_editArcade(LinkedList* pListArcades,LinkedList* pListSalones,LinkedList* pListGames){
	int rtn = -1;
	int auxId;
	int maxIdS;
	int opcion;
	int finalizar;
	int auxCantJugadores;
	int auxIdJuego;
	Arcade* auxArcade;
	Arcade* buferArcade;
	if(pListArcades != NULL && pListSalones != NULL && pListGames != NULL){
		controller_ListArcades(pListArcades,pListSalones,pListGames);
		maxIdS = Arcade_GetLastId();
		if(getIntInRange("Ingrese el Id del Arcade que desea modificar",3,0,maxIdS,"Opcion invalida,",&auxId) == 1){
			auxArcade = Arcade_findArcadeById(pListArcades,auxId);
			if(auxArcade != NULL){
				buferArcade = Arcade_newParametros(auxArcade->nacionalidad,auxArcade->tipoSonido,auxArcade->cantJugadores,auxArcade->cantFichas,auxArcade->idSalon,auxArcade->idJuego);
				do{
					puts(	"++------------------------------------------------------++\n"
							"||                         MENU                         ||\n"
							"++------------------------------------------------------++\n"
							"||                                                      ||\n"
			    			"||  ( 1). Modificar cantidad de jugadores               ||\n"
			    			"||  ( 2). Modificar juego del arcade                    ||\n"
							"||  ( 3). Guardar / Salir                               ||\n"
							"||                                                      ||\n"
			    			"++------------------------------------------------------++\n");
					if(getIntInRange("ingrese una opcion:",3,1,3,"Opcion invalida",&opcion) !=1){
						controller_MensajeError("Error, agotado el numero de reintentos");
						finalizar =1;
					}
					switch(opcion){
					case 1://Modificar cant de jugadores
						controller_MensajeExitoso("MODIFICAR CANTIDAD DE JUGADORES");
						if(getIntInRange("Ingrese cantidad de jugadores (1-4):",3,1,4,"Opcion invalida,",&auxCantJugadores) == 1){
							Arcade_setCantJugadores(buferArcade,auxCantJugadores);
						}
						else{controller_MensajeError("Error al Modificar jugadores");
						}
						break;
					case 2://Modificar juego
						controller_MensajeExitoso("MODIFICAR JUEGO");
						controller_ListGames(pListGames);

						if(getIntInRange("Ingrese id del juego que desea cargar:",3,1,2,"Opcion invalida,",&auxIdJuego) ==1){
							Arcade_setIdJuego(buferArcade,auxIdJuego);
						}
						else{controller_MensajeError("Error al Modificar dirección");
						}
						break;
					case 3://salir
						if(PedirVerificacion("Desea guardar los cambios?","Opcion invalida")==1){
							if(Arcade_remplazar(auxArcade,buferArcade)==1){
								finalizar =1;
								rtn = 1;
							}
						}
						break;
					}
				}while(finalizar!=1);
			}
			else{controller_MensajeError("El ID seleccionado no valido");
			}
		}
	}
	return rtn;
}

int controller_removeArcade(LinkedList* pListArcade,LinkedList* pListSalones,LinkedList* pListGames){
	int rtn = -1;
	int auxId;
	int maxIdS;
	Arcade* auxArcade;
	if(pListArcade != NULL && pListSalones != NULL && pListGames != NULL){
		controller_ListArcades(pListArcade,pListSalones,pListGames);
		maxIdS = Arcade_GetLastId();
		if(getIntInRange("Ingrese el Id del pasajero que desea eliminar",3,1,maxIdS,"Opcion invalida,",&auxId) == 1){
			auxArcade = Arcade_findArcadeById(pListArcade,auxId);
			if(auxArcade != NULL && PedirVerificacion("Seguro desea eliminar este arcade?","Opcion invalida")==1){
				if(ll_remove(pListArcade,ll_indexOf(pListArcade,auxArcade))==0){
					free(auxArcade);
					auxArcade = NULL;
					rtn = 1;
				}
			}
		}
	}
    return rtn;
}

int controller_removeArcadeByIdSalon(LinkedList* pListArcade,int idSalon){
	int rtn = -1;
	int i;
	Arcade* auxArcade;
	if(pListArcade != NULL && idSalon >= 0){
		for (i = 0; i < ll_len(pListArcade); ++i) {
			auxArcade = ll_get(pListArcade,i);
			if(auxArcade->idSalon == idSalon){
				if(ll_remove(pListArcade,ll_indexOf(pListArcade,auxArcade))==0){
					free(auxArcade);
					auxArcade = NULL;
					rtn = 1;
				}
			}
		}
	}
    return rtn;
}

int controller_saveArcadeAsBinary(char* path , LinkedList* pArrayListArcade){
	int rtn = -1;
	FILE* file;
	Arcade* auxArcade;
	int len;
	int i;
	if(path != NULL && pArrayListArcade != NULL){
		len = ll_len(pArrayListArcade);
		if(len > 0){
			file = fopen(path,"wb");
			if(file!=NULL){
				for(i=0;i<len;i++){
					auxArcade = ll_get(pArrayListArcade,i);
					if(auxArcade != NULL){
						fwrite(auxArcade,sizeof(Arcade),1,file);
					}
				}
				fclose(file);
				if(i == len){
					rtn = 1;
				}
			}
		}
		else{
			rtn = 0;
		}
	}
	return rtn;
}

int controller_saveArcadeAsText(char* path,LinkedList* pArrayListArcade){
	int rtn = -1;
	FILE* pfile;
	Arcade* auxArcade;
	int len = -1;
	int i;
	if(path != NULL && pArrayListArcade != NULL){
		len = ll_len(pArrayListArcade);
		if(len > 0){
			pfile = fopen(path,"w");
			if(pfile!=NULL){
				for(i=0;i<len;i++){
					auxArcade=(Arcade*)ll_get(pArrayListArcade,i);
					fprintf(pfile,"%d,%s,%d,%d,%d,%d,%d\n",
							auxArcade->id,
							auxArcade->nacionalidad,
							auxArcade->tipoSonido,
							auxArcade->cantJugadores,
							auxArcade->cantFichas,
							auxArcade->idJuego,
							auxArcade->idSalon);
				}
				fclose(pfile);
				if(i == len){
					rtn = 1;
				}
			}
		}
		else{rtn = 0;
		}
	}
	return rtn;
}

/////////////////JUEGO/////////////////

int controller_loadGameFromText(char* path , LinkedList* pListGames){
	int rtn = -1;
	FILE* pFile;
	if(pListGames != NULL && path != NULL){
		pFile = fopen(path,"r");
		if(pFile != NULL && parser_GameFromText(pFile ,pListGames) == 1){
			rtn = 1;
		}
		fclose(pFile);
	}
	return rtn;
}

int controller_loadGameFromBinary(char* path , LinkedList* pListGames){
	int rtn = -1;
	FILE* pFile;
	if(pListGames != NULL && path != NULL){
		pFile = fopen(path,"rb");
		if(pFile != NULL){
			parser_GameFromBinary(pFile ,pListGames);
			fclose(pFile);
			rtn = 1;
		}
	}
	return rtn;
}

int controller_addGame(LinkedList* pListGames){
	int rtn;
		char auxName[MAX_CHARS];
		char auxEmpresa[MAX_CHARS];
		int auxTipo;
		Game* auxGame;
		if(pListGames != NULL){
			if(GetAddresWithRetrys("Ingrese Nombre del juego:",3,"Nombre invalido,",auxName,MAX_CHARS) == 1 &&
			   GetAddresWithRetrys("Ingrese Empresa:",3,"empresa invalida,",auxEmpresa,MAX_CHARS) == 1 &&
			   getIntInRange("Ingrese Tipo:\n\t 1- Plataforma \n\t 2- Laberinto \n\t 3- Aventura \n\t 0- Otros",3,0,3,"Opcion invalida,",&auxTipo) == 1){
				auxGame = Game_newParametros(auxName,auxEmpresa,auxTipo);
				if(auxGame != NULL){
					ll_add(pListGames,auxGame);
					rtn =1;
					printf( "+----------+------------------------------+------------------------------+------------------------------+\n"
							"| Id       | Nombre del juego             | Empresa                      | Genero                       |\n"
							"+----------+------------------------------+------------------------------+------------------------------+\n");
					Game_showGame(auxGame);
					printf( "+----------+------------------------------+------------------------------+------------------------------+\n");
				}
				else{rtn =-3;//error al juego new parametros
				}
			}
			else{rtn =-2;//error al cargar de datos pedidos
			}
		}
		else{rtn =-1;//error NULL
		}
	return rtn;
}

int controller_countGames(LinkedList* pListGames){
	int contador = -1;
	Game* auxPassenger;
	if(pListGames != NULL){
		contador = 0;
		for(int i = 0;i<ll_len(pListGames);i++){
			auxPassenger = ll_get(pListGames,i);
			if(auxPassenger != NULL){
				contador++;
			}
		}
	}
	return contador;
}

int controller_ListGames(LinkedList* pListGames){
	int contador = -1;
	int i;
	Game* auxGame;
	if(pListGames != NULL){
		contador = 0;
		printf( "+----------+------------------------------+------------------------------+------------------------------+\n"
				"| Id       | Nombre del juego             | Empresa                      | Tipo de juego                |\n"
				"+----------+------------------------------+------------------------------+------------------------------+\n");
		for(i = 0;i<ll_len(pListGames);i++){
			auxGame = ll_get(pListGames,i);
			if(auxGame != NULL){
				Game_showGame(auxGame);
				contador++;
			}
		}
		printf( "+----------+------------------------------+------------------------------+------------------------------+\n");
	}
	return contador;
}

int controller_saveGameAsBinary(char* path , LinkedList* pArrayListGame){
	int rtn = -1;
	FILE* file;
	Game* auxGame;
	int len;
	int i;
	if(path != NULL && pArrayListGame != NULL){
		len = ll_len(pArrayListGame);
		if(len > 0){
			file = fopen(path,"wb");
			if(file!=NULL){
				for(i=0;i<len;i++){
					auxGame = ll_get(pArrayListGame,i);
					if(auxGame != NULL){
						fwrite(auxGame,sizeof(Game),1,file);
					}
				}
				fclose(file);
				if(i == len){
					rtn = 1;
				}
			}
		}
		else{
			rtn = 0;
		}
	}
	return rtn;
}

int controller_saveGameAsText(char* path,LinkedList* pArrayListGame){
	int rtn = -1;
	FILE* pfile;
	Game* auxGame;
	int len = -1;
	int i;
	if(path != NULL && pArrayListGame != NULL){
		len = ll_len(pArrayListGame);
		if(len > 0){
			pfile = fopen(path,"w");
			if(pfile!=NULL){
				for(i=0;i<len;i++){
					auxGame=(Game*)ll_get(pArrayListGame,i);
					fprintf(pfile,"%d,%s,%s,%d\n",auxGame->id,auxGame->nombre,auxGame->empresa,auxGame->genero);
				}
				fclose(pfile);
				if(i == len){
					rtn = 1;
				}
			}
		}
		else{rtn = 0;
		}
	}
	return rtn;
}
/////////////////INFORMES/////////////////
void controler_MenuInformes(LinkedList* listaArcades,LinkedList* listaSalones,LinkedList* listaJuegos){
	int option = -1;
	int salir = 0;
	do{
		puts(	"++-^-++-^-^-^-++-^-^-^-++-^----^-++-^-^-^-++-^-^-^-++-^-++\n"
				"||<o>||>-<o>-<||>-<o>-<||  MENU  ||>-<o>-<||>-<o>-<||<o>||\n"
				"++---++-------++-------++--------++-------++-------++---++\n"
				"||                                                      ||\n"
				"||  ( 1). Listar salones con mas de 4 arcades           ||\n"
				"||  ( 2). Listar arcades para mas de 2 jugadores        ||\n"
				"||  ( 3). Listar salon                                  ||\n"
				"||  ( 4). Listar salon completo                         ||\n"
				"||  ( 5). Listar arcades de un salon                    ||\n"
				"||  ( 6). Listar salon con mas arcades                  ||\n"
				"||  ( 7). Listar aracdes sonido mono y genero plataforma||\n"
				"||  ( 0). Salir                                         ||\n"
				"||                                                      ||\n"
				"++------------------------------------------------------++\n");
		if(getIntInRange("Ingrese una opcion:",3,0,10,"Opcion invalida",&option) !=1){
			controller_MensajeError("Error!, agotado numero de reintentos");
			option =0;
		}
		switch(option){
		case 1:///Listar salones con mas de 4 arcades
			controller_MensajeCabecera("Salones con mas de 4 arcades");
			controller_ListarSalonesConMasDeCuatroArcades(listaArcades,listaSalones);
			break;
		case 2:///Listar arcades para mas de 2 jugadores
			controller_MensajeCabecera("Arcades para dos jugadores o mas");
			controller_ListarArcadesParaMasDeDosJugadores(listaSalones,listaArcades,listaJuegos);
			break;
		case 3:///Listar salon
			controller_MensajeCabecera("Mostrar salon");
			controller_ListarUnSalonDeterminado(listaSalones);
			break;
		case 4:///Listar salon completo
			controller_MensajeCabecera("Salones completos ");
			controller_ListarSalonesCompletos(listaArcades,listaSalones,listaJuegos);
			break;
		case 5:///Listar arcades de un salon
			controller_MensajeCabecera("Arcades del salon determinado ");
			controller_ListarArcadesDeUnSalonDeterminado(listaSalones,listaArcades,listaJuegos);
			break;
		case 6:///Listar salon con mas arcades
			controller_MensajeCabecera("Salon con mas arcades ");
			controller_ListarSalonConMasArcades(listaSalones,listaArcades,listaJuegos);
			break;
		case 7:///Listar aracdes sonido mono y genero plataforma
			controller_MensajeCabecera("Arcades sonido mono y juego plataforma");
			controller_ArcadesMonoPlataformaPorNombre(listaArcades,listaJuegos);
			break;
		case 0:///salir
			salir = 1;
			break;
		}
	}while(salir != 1);
}

int controller_ListarSalonesConMasDeCuatroArcades(LinkedList* listaArcades,LinkedList* listaSalones){
	int rtn =-1;
	int i;
	int j;
	int contador;
	Salon* auxSalon;
	Arcade* auxArcade;
	if(listaSalones != NULL && listaArcades != NULL){
		printf( "+----------+------------------------------+------------------------------+------------------------------+\n"
				"| Id       | Nombre del salon             | Dirección                    | Tipo de salon                |\n"
				"+----------+------------------------------+------------------------------+------------------------------+\n");
		for (i = 0; i < ll_len(listaSalones);++i){
			auxSalon = ll_get(listaSalones,i);
			contador = 0;
			for (j = 0; j < ll_len(listaArcades);++j){
				auxArcade = ll_get(listaArcades,j);
				if(auxSalon->id==auxArcade->idSalon){
					contador++;
				}
			}
			if(contador>=4){
				Salon_showSalon(auxSalon);
				rtn = 1;
			}
		}
		if(rtn==-1){
			rtn = 0;
			printf( "| NO SE ENCONTRARON SALONES CON MAS DE CUATRO ARCADES                                                   |\n");
		}
		printf( 	"+----------+------------------------------+------------------------------+------------------------------+\n");
	}
	return rtn;
}

int controller_ListarArcadesParaMasDeDosJugadores(LinkedList* listaSalones,LinkedList* listaArcades,LinkedList* listaJuegos){
	int rtn =-1;
	int i;
	Arcade* auxArcade;
	Salon* auxSalon;
	Game* auxJuego;
	char auxTipoSonido[MAX_CHARS];
	char auxGeneroJuego[MAX_CHARS];
	if(listaArcades != NULL && listaSalones != NULL && listaJuegos != NULL){
		printf( "+------+---------------------+-----------+-----------+-----------+---------------------+---------------------+---------------------+\n"
				"| Id   | Nacionalidad        | Sonido    | Jugadores | Fichas    |  Juego              |  Genero             | Salon               |\n"
				"+------+---------------------+-----------+-----------+-----------+---------------------+---------------------+---------------------+\n");
		for(i = 0;i<ll_len(listaArcades);i++){
			auxArcade = ll_get(listaArcades,i);
			if(auxArcade != NULL && auxArcade->cantJugadores>=2){
				auxJuego = Game_findGamebyId(listaJuegos,auxArcade->idJuego);
				auxSalon = Salon_findSalonById(listaSalones,auxArcade->idSalon);
				switch (auxArcade->tipoSonido){
				case 1:
					strcpy(auxTipoSonido,"mono");
					break;
				case 2:
					strcpy(auxTipoSonido,"estéreo");
					break;
				}
				switch (auxJuego->genero) {
				case OTRO:
					strncpy(auxGeneroJuego,"Otro",MAX_CHARS);
					break;
				case PLATAFORMA:
					strncpy(auxGeneroJuego,"Plataforma",MAX_CHARS);
					break;
				case LABERINTO:
					strncpy(auxGeneroJuego,"Laberinto",MAX_CHARS);
					break;
				case AVENTURA:
					strncpy(auxGeneroJuego,"Aventura",MAX_CHARS);
					break;
				}
				printf( "| %-5d| %-20s| %-10s| %-10d| %-10d| %-20s| %-20s| %-20s|\n",
						auxArcade->id,
						auxArcade->nacionalidad,
						auxTipoSonido,
						auxArcade->cantJugadores,
						auxArcade->cantFichas,
						auxJuego->nombre,
						auxGeneroJuego,
						auxSalon->nombre);
				rtn=1;
			}
		}
		if(rtn == -1){
			rtn=0;
			printf( "| NO SE ENCONTRARON ARCADES PARA DOS JUGADORES O MAS                                                                               |\n");
		}
		printf( 	"+------+---------------------+-----------+-----------+-----------+---------------------+---------------------+---------------------+\n");
	}
	return rtn;
}

int controller_ListarUnSalonDeterminado(LinkedList* listaSalones){
	int rtn =-1;
	int auxMaxIdSalon;
	int auxIdSalon;
	Salon* auxSalon;
	if(listaSalones != NULL){
		controller_ListSalones(listaSalones);
		auxMaxIdSalon = Salon_findMaxId(listaSalones);
		if(getIntInRange("Ingrese id del salon para mostrar sus arcades:",3,1,auxMaxIdSalon,"Opcion invalida,",&auxIdSalon)==1){
			auxSalon = Salon_findSalonById(listaSalones,auxIdSalon);
			printf( "+----------+------------------------------+------------------------------+------------------------------+\n"
					"| Id       | Nombre del salon             | dirección                    | Tipo de salon                |\n"
					"+----------+------------------------------+------------------------------+------------------------------+\n");
			Salon_showSalon(auxSalon);
			printf(	"+------+---------------------+-----------+-----------+-----------+--------------------------------------+\n");
			rtn =1;
		}
	}
	return rtn;
}

int controller_ListarSalonesCompletos(LinkedList* listaArcades,LinkedList* listaSalones,LinkedList* listaJuegos){
	int rtn =-1;
	int i;
	int j;
	int contadorPlataforma;
	int contadorLaberinto;
	int contadorAventura;
	Salon* auxSalon;
	Arcade* auxArcade;
	Game* auxJuego;
	if(listaSalones != NULL && listaArcades != NULL && listaJuegos != NULL){
		printf( "+----------+------------------------------+------------------------------+------------------------------+\n"
				"| Id       | Nombre del salon             | Dirección                    | Tipo de salon                |\n"
				"+----------+------------------------------+------------------------------+------------------------------+\n");
		for (i = 0; i < ll_len(listaSalones);++i){
			auxSalon = ll_get(listaSalones,i);
			contadorPlataforma =0;
			contadorLaberinto =0;
			contadorAventura =0;
			for (j = 0; j < ll_len(listaArcades);++j){
				auxArcade = ll_get(listaArcades,j);
				if(auxSalon->id==auxArcade->idSalon){
					auxJuego = Game_findGamebyId(listaJuegos,auxArcade->idJuego);
					switch (auxJuego->genero) {
					case PLATAFORMA:
						contadorPlataforma++;
						break;
					case LABERINTO:
						contadorLaberinto++;
						break;
					case AVENTURA:
						contadorAventura++;
						break;
					}
				}
			}
			if(contadorPlataforma>=4 && contadorLaberinto>=3 && contadorAventura>=5){
			Salon_showSalon(auxSalon);
			rtn = 1;
			}
		}
		if(rtn==-1){
			rtn =0;
			printf( "| NO SE ENCONTRARON SALONES COMPLETOS                                                                   |\n");
		}
		printf(	 	"+----------+------------------------------+------------------------------+------------------------------+\n");
	}
	return rtn;
}

int controller_ListarArcadesDeUnSalonDeterminado(LinkedList* listaSalones,LinkedList* listaArcades,LinkedList* listaJuegos){
	int rtn =-1;
	int i;
	int auxMaxIdSalon;
	int auxIdSalon;
	Arcade* auxArcade;
	Salon* auxSalon;
	Game* auxJuego;
	char auxTipoSonido[MAX_CHARS];
	if(listaArcades != NULL && listaSalones != NULL && listaJuegos != NULL){
		controller_ListSalones(listaSalones);
		auxMaxIdSalon = Salon_findMaxId(listaSalones);
		if(getIntInRange("Ingrese id del salon para mostrar sus arcades:",3,1,auxMaxIdSalon,"Opcion invalida,",&auxIdSalon)==1){
			auxSalon = Salon_findSalonById(listaSalones,auxIdSalon);
			printf( "+----------+------------------------------+------------------------------+------------------------------+\n"
					"| Id       | Nombre del salon             | dirección                    | Tipo de salon                |\n"
					"+----------+------------------------------+------------------------------+------------------------------+\n");
			Salon_showSalon(auxSalon);
			printf( "+------+---+-----------------+-----------++----------+-----------+-------+------------------------------+\n"
					"| Id   | Nacionalidad        | Sonido    | Jugadores | Fichas    | Juego                                |\n"
					"+------+---------------------+-----------+-----------+-----------+--------------------------------------+\n");
			for(i = 0;i<ll_len(listaArcades);i++){
				auxArcade = ll_get(listaArcades,i);
				if(auxArcade != NULL && auxArcade->idSalon==auxSalon->id){
					auxJuego = Game_findGamebyId(listaJuegos,auxArcade->idJuego);
					switch (auxArcade->tipoSonido){
					case 1:
						strcpy(auxTipoSonido,"mono");
						break;
					case 2:
						strcpy(auxTipoSonido,"estéreo");
						break;
					}
					printf( "| %-5d| %-20s| %-10s| %-10d| %-10d| %-37s|\n",
							auxArcade->id,
							auxArcade->nacionalidad,
							auxTipoSonido,
							auxArcade->cantJugadores,
							auxArcade->cantFichas,
							auxJuego->nombre);
					rtn=1;
				}
			}
			if(rtn == -1){
				rtn=0;
				printf( "| NO SE ENCONTRARON ARCADES PARA ESTE SALON                                                             |\n");
			}
			printf( 	"+------+---------------------+-----------+-----------+-----------+--------------------------------------+\n");
		}
	}
	return rtn;
}

int controller_ListarSalonConMasArcades(LinkedList* listaSalones,LinkedList* listaArcades,LinkedList* listaJuegos){
	int rtn =-1;
	int i;
	int j;
	int contador;
	int maxArcades =0;
	Arcade* auxArcade;
	Salon* auxSalon;
	Salon* auxSalonMasArcades;
	Game* auxJuego;
	char auxTipoSonido[MAX_CHARS];
	if(listaArcades != NULL && listaSalones != NULL && listaJuegos != NULL){
		for(i=0;i<ll_len(listaSalones);i++){
			contador=0;
			auxSalon = ll_get(listaSalones,i);
			for(j = 0;j<ll_len(listaArcades);j++){
				auxArcade = ll_get(listaArcades,j);
				if(auxArcade != NULL && auxArcade->idSalon==auxSalon->id){
				contador++;
				}
			}
			if(contador > maxArcades){
				maxArcades = contador;
				auxSalonMasArcades = auxSalon;
			}
		}
		printf( "+----------+------------------------------+------------------------------+------------------------------+\n"
				"| Id       | Nombre del salon             | dirección                    | Tipo de salon                |\n"
				"+----------+------------------------------+------------------------------+------------------------------+\n");
		Salon_showSalon(auxSalonMasArcades);
		printf( "+------+---+-----------------+-----------++----------+-----------+-------+------------------------------+\n"
				"| Id   | Nacionalidad        | Sonido    | Jugadores | Fichas    | Juego                                |\n"
				"+------+---------------------+-----------+-----------+-----------+--------------------------------------+\n");
		for(i = 0;i<ll_len(listaArcades);i++){
			auxArcade = ll_get(listaArcades,i);
			if(auxArcade != NULL && auxArcade->idSalon==auxSalonMasArcades->id){
				auxJuego = Game_findGamebyId(listaJuegos,auxArcade->idJuego);
				switch (auxArcade->tipoSonido){
				case 1:
					strcpy(auxTipoSonido,"mono");
					break;
				case 2:
					strcpy(auxTipoSonido,"estéreo");
					break;
				}
				printf( "| %-5d| %-20s| %-10s| %-10d| %-10d| %-37s|\n",
						auxArcade->id,
						auxArcade->nacionalidad,
						auxTipoSonido,
						auxArcade->cantJugadores,
						auxArcade->cantFichas,
						auxJuego->nombre);
				rtn=1;
			}
		}
		if(rtn == -1){
			rtn=0;
			printf( "| NO SE ENCONTRARON ARCADES PARA ESTE SALON                                                             |\n");
		}
		printf( 	"+------+---------------------+-----------+-----------+-----------+--------------------------------------+\n");
	}
	return rtn;
}

int controller_ArcadesMonoPlataformaPorNombre(LinkedList* listaArcades,LinkedList* listaJuegos){
	int rtn = -1;
	int i;
	int j;
	Game* auxGame;
	Arcade* auxArcade;
	char auxTipoSonido[MAX_CHARS];
	char auxGeneroJuego[MAX_CHARS];
	if(listaArcades != NULL && listaJuegos != NULL){
		ll_sort(listaJuegos,Game_sortByName, 1);
		printf( "+------+---------------------+-----------+-----------+-----------+---------------------+---------------------+\n"
				"| Id   | Nacionalidad        | Sonido    | Jugadores | Fichas    |  Juego              |  Genero             |\n"
				"+------+---------------------+-----------+-----------+-----------+---------------------+---------------------+\n");
		for (i=0;i<ll_len(listaJuegos);i++){
			auxGame = ll_get(listaJuegos,i);
			if(PLATAFORMA==auxGame->genero){
				for (j=0;j<ll_len(listaArcades);j++){
					auxArcade = ll_get(listaArcades,j);
					if(auxArcade->tipoSonido==MONO && auxArcade->idJuego==auxGame->id){
						switch (auxArcade->tipoSonido){
						case 1:
							strcpy(auxTipoSonido,"mono");
							break;
						case 2:
							strcpy(auxTipoSonido,"estéreo");
							break;
						}
						switch (auxGame->genero) {
						case OTRO:
							strncpy(auxGeneroJuego,"Otro",MAX_CHARS);
							break;
						case PLATAFORMA:
							strncpy(auxGeneroJuego,"Plataforma",MAX_CHARS);
							break;
						case LABERINTO:
							strncpy(auxGeneroJuego,"Laberinto",MAX_CHARS);
							break;
						case AVENTURA:
							strncpy(auxGeneroJuego,"Aventura",MAX_CHARS);
							break;
						}
						printf( "| %-5d| %-20s| %-10s| %-10d| %-10d| %-20s| %-20s|\n",
								auxArcade->id,
								auxArcade->nacionalidad,
								auxTipoSonido,
								auxArcade->cantJugadores,
								auxArcade->cantFichas,
								auxGame->nombre,
								auxGeneroJuego);
						rtn=1;
					}
				}
			}
		}
		if(rtn == -1){
			rtn=0;
			printf( "| NO SE ENCONTRARON ARCADES PARA DOS JUGADORES O MAS                                                         |\n");
		}
		printf( 	"+------+---------------------+-----------+-----------+-----------+---------------------+---------------------+\n");
	}
	return rtn;
}

/////////////////CARGA DE DATOS/////////////////

void controller_cargaDeDatosInicial(int tipoDeCarga,LinkedList* listaSalones,LinkedList* listaArcades,LinkedList* listaJuegos){
	if(listaSalones != NULL && listaArcades != NULL && listaJuegos != NULL){
		switch(tipoDeCarga){
		case DATOS_BINARIO:
			controller_loadSalonFromBinary("Salones.bin",listaSalones);
			controller_loadArcadeFromBinary("Arcades.bin",listaArcades);
			controller_loadGameFromBinary("Games.bin",listaJuegos);
			break;
		case DATOS_TEXTO:
			controller_loadSalonFromText("Salones.csv",listaSalones);
			controller_loadGameFromText("Games.csv",listaJuegos);
			controller_loadArcadeFromText("Arcades.csv",listaArcades);
			break;
		}
		Salon_lastId(listaSalones);
		Arcade_lastId(listaArcades);
		Game_lastId(listaJuegos);
	}
}

/////////////////MARCOS DE MENSAJES/////////////////

void controller_MensajeCabecera(char mensaje[]){
	int espace = (48 - strlen(mensaje))/2;
	int i;
	printf(	"+-^-+-^--^--^--^--^--^--^--^--^--^--^--^--^--^--^--^-+-^-+\n"
			"|<o>|");
	for (i = 0; i < espace; ++i) {
		printf(" ");
	}
	printf("%s",mensaje);
	for (i = 0; i < espace; ++i) {
		printf(" ");
	}
	printf(														 "|<o>|\n"
			"+---+------------------------------------------------+---+\n");
}

void controller_MensajeExitoso(char mensaje[]){
	int espace = (48 - strlen(mensaje))/2;
	int i;
	printf(	"+---+------------------------------------------------+---+\n"
			"|<o>|");
	for	(i = 0; i < espace; ++i) {
		printf(" ");
	}
	printf("%s",mensaje);
	for (i = 0; i < espace; ++i) {
		printf(" ");
	}
	printf(														 "|<o>|\n"
			"+---+------------------------------------------------+---+\n");
}

void controller_MensajeError(char mensaje[]){
	int espace = (48 - strlen(mensaje))/2;
	int i;
	printf(	"+---+------------------------------------------------+---+\n"
			"|<x>|");
	for	(i = 0; i < espace; ++i) {
		printf(" ");
	}
	printf("%s",mensaje);
	for (i = 0; i < espace; ++i) {
		printf(" ");
	}
	printf(														 "|<x>|\n"
			"+---+------------------------------------------------+---+\n");
}

