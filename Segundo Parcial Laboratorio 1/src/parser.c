#include "parser.h"


/////////////////SALON/////////////////

int parser_SalonFromText(FILE* pFile ,LinkedList* pArrayListSalon){
	int rtn = -1;
	char auxId[MAX_CHARS];
	char auxNombre[MAX_CHARS];
	char auxDireccion[MAX_CHARS];
	char auxTipo[MAX_CHARS];
	int cant;
	Salon* auxSalon;
	if(pFile != NULL && pArrayListSalon != NULL){
		while(!feof(pFile)){
			cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",auxId,auxNombre,auxDireccion,auxTipo);
			auxSalon = Salon_newParametrosTxt(auxNombre,auxDireccion,auxTipo,auxId);
				ll_add(pArrayListSalon,auxSalon);
			if(cant < 4){
				if(feof(pFile)){
					break;
				}
				else{
					rtn = 0;
					break;
				}
			}
		}
		rtn = 1;
	}
    return rtn;
}

int parser_SalonFromBinary(FILE* pFile, LinkedList* pArrayListSalon){
	int rtn = -1;
	int cant;
	Salon* auxSalon;
	if(pFile != NULL && pArrayListSalon != NULL){
		while(!feof(pFile)){
			auxSalon = Salon_new();
			cant = fread(auxSalon,sizeof(Salon),1,pFile);
			if(auxSalon != NULL){
				if(Salon_isValid(auxSalon)==1){
					ll_add(pArrayListSalon,auxSalon);
				}
			}
			if(cant < 1){
				if(feof(pFile)){
					break;
				}
				else{
					rtn = 0;
					break;
				}
			}
		}
		rtn = 1;
	}
	return rtn;
}

/////////////////ARCADE/////////////////

int parser_ArcadeFromText(FILE* pFile ,LinkedList* pArrayListArcade){
	int rtn = -1;
	char auxId[MAX_CHARS];
	char auxNacionalidad[MAX_CHARS];
	char auxTipoSonido[MAX_CHARS];
	char auxCantJugadores[MAX_CHARS];
	char auxCantFichas[MAX_CHARS];
	char auxIdJuego[MAX_CHARS];
	char auxIdSalon[MAX_CHARS];
	int cant;
	Arcade* auxArcade;
	if(pFile != NULL && pArrayListArcade != NULL){
		while(!feof(pFile)){
			cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",auxId,auxNacionalidad,auxTipoSonido,auxCantJugadores,auxCantFichas,auxIdJuego,auxIdSalon);
			auxArcade = Arcade_newParametrosTxt(auxId,auxNacionalidad,auxTipoSonido,auxCantJugadores,auxCantFichas,auxIdJuego,auxIdSalon);
				ll_add(pArrayListArcade,auxArcade);
			if(cant < 7){
				if(feof(pFile)){
					break;
				}
				else{
					rtn = 0;
					break;
				}
			}
		}
		rtn = 1;
	}
    return rtn;
}

int parser_ArcadeFromBinary(FILE* pFile, LinkedList* pArrayListArcade){
	int rtn = -1;
	int cant;
	Arcade* auxArcade;
	if(pFile != NULL && pArrayListArcade != NULL){
		while(!feof(pFile)){
			auxArcade = Arcade_new();
			cant = fread(auxArcade,sizeof(Arcade),1,pFile);
			if(auxArcade != NULL){
				if(Arcade_isValid(auxArcade)==1){
					ll_add(pArrayListArcade,auxArcade);
				}
			}
			if(cant < 1){
				if(feof(pFile)){
					break;
				}
				else{
					rtn = 0;
					break;
				}
			}
		}
		rtn = 1;
	}
	return rtn;
}

/////////////////JUEGO//////////////////

int parser_GameFromText(FILE* pFile ,LinkedList* pArrayListGame){
	int rtn = -1;
	char auxId[MAX_CHARS];
	char auxNombre[MAX_CHARS];
	char auxEmpresa[MAX_CHARS];
	char auxGenero[MAX_CHARS];
	int cant;
	Game* auxJuego;
	if(pFile != NULL && pArrayListGame != NULL){
		while(!feof(pFile)){
			cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",auxId,auxNombre,auxEmpresa,auxGenero);
			auxJuego = Game_newParametrosTxt(auxNombre,auxEmpresa,auxGenero,auxId);
				ll_add(pArrayListGame,auxJuego);
			if(cant < 4){
				if(feof(pFile)){
					break;
				}
				else{
					rtn = 0;
					break;
				}
			}
		}
		rtn = 1;
	}
    return rtn;
}

int parser_GameFromBinary(FILE* pFile , LinkedList* pArrayListGame){
	int rtn = -1;
	int cant;
	Game* auxJuego;
	if(pFile != NULL && pArrayListGame != NULL){
		while(!feof(pFile)){
			auxJuego = Game_new();
			cant = fread(auxJuego,sizeof(Game),1,pFile);
			if(auxJuego != NULL){
				if(Game_isValid(auxJuego)==1){
					ll_add(pArrayListGame,auxJuego);
				}
			}
			if(cant < 1){
				if(feof(pFile)){
					break;
				}
				else{
					rtn = 0;
					break;
				}
			}
		}
		rtn = 1;
	}
	return rtn;
}

