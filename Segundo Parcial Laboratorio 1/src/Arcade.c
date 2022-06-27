#include "Arcade.h"


static int IsValidId(char* arrayPosiblesNumeros);
static int IsValidNacionalidad(char* posiblesLetras);
static int IsValidTipoSonido(char* arrayPosiblesNumeros);
static int IsValidCantJugadores(char* arrayPosiblesNumeros);
static int IsValidCantFichas(char* arrayPosiblesNumeros);
static int IsValidIdJuego(char* arrayPosiblesNumeros);
static int IsValidIdSalon(char* arrayPosiblesNumeros);

Arcade* Arcade_new(){
	return (Arcade*)malloc(sizeof(Arcade));
}

Arcade* Arcade_newParametrosTxt(char* idStr,char* nacionalidadStr,char* tipoSonidoStr,char* cantJugadoresStr,char* cantFichasStr,char* idJuegoStr,char* idSalonStr){
	Arcade* auxArcadeP = NULL;
	auxArcadeP = Arcade_new();
	if(auxArcadeP != NULL && idStr != NULL && nacionalidadStr != NULL && tipoSonidoStr != NULL &&
	   cantJugadoresStr != NULL && cantFichasStr != NULL && idSalonStr != NULL && idJuegoStr != NULL){
		if( Arcade_setIdTxt(auxArcadeP,idStr) ==1 &&
			Arcade_setNacionalidad(auxArcadeP,nacionalidadStr) ==1 &&
			Arcade_setTipoSonidoTxt(auxArcadeP,tipoSonidoStr) ==1 &&
			Arcade_setCantJugadoresTxt(auxArcadeP,cantJugadoresStr) ==1 &&
			Arcade_setCantFichasTxt(auxArcadeP,cantFichasStr) ==1 &&
			Arcade_setIdSalonTxt(auxArcadeP,idSalonStr) ==1 &&
			Arcade_setIdJuegoTxt(auxArcadeP,idJuegoStr) ==1){
		}
		else{
			free(auxArcadeP);
			auxArcadeP = NULL;
		}
	}
	else{
		free(auxArcadeP);
		auxArcadeP = NULL;
	}
	return auxArcadeP;
}

Arcade* Arcade_newParametros(char* nacionalidad,int tipoSonido,int cantJugadores,int cantFichas,int idJuego,int idSalon){
	Arcade* auxArcadeP = NULL;
	auxArcadeP = Arcade_new();
	if(auxArcadeP != NULL && nacionalidad != NULL && tipoSonido >0 &&
	   cantJugadores >0 && cantFichas >0 && idSalon >=0 && idJuego >=0){
		if( Arcade_setNacionalidad(auxArcadeP,nacionalidad) ==1 &&
			Arcade_setTipoSonido(auxArcadeP,tipoSonido) ==1 &&
			Arcade_setCantJugadores(auxArcadeP,cantJugadores) ==1 &&
			Arcade_setCantFichas(auxArcadeP,cantFichas) ==1 &&
			Arcade_setIdSalon(auxArcadeP,idSalon) ==1 &&
			Arcade_setIdJuego(auxArcadeP,idJuego) ==1){
			Arcade_setId(auxArcadeP,Arcade_GenerarId());
		}
		else{
			free(auxArcadeP);
			auxArcadeP = NULL;
		}
	}
	else{
		free(auxArcadeP);
		auxArcadeP = NULL;
	}
	return auxArcadeP;
}

int Arcade_setIdTxt(Arcade* this,char* id){
	int rtn=-1;
	if(this != NULL && id != NULL){
		if(IsValidId(id)==1){
			rtn =1;
			this->id = atoi(id);
		}
	}
	return rtn;
}
int Arcade_getIdTxt(Arcade* this,char* id){
	int rtn=-1;
	if(this != NULL && id != NULL){
		rtn =1;
		sprintf(id,"%d",this->id);
	}
	return rtn;
}
int Arcade_setId(Arcade* this,int id){
	int rtn=-1;
	if(this != NULL && id >= 0){
		rtn =1;
		this->id = id;
	}
	return rtn;
}
int Arcade_getId(Arcade* this,int* id){
	int rtn=-1;
	if(this != NULL && id >= 0){
		rtn =1;
		*id = this->id;
	}
	return rtn;
}

int Arcade_setNacionalidad(Arcade* this,char* nacionalidad){
	int rtn=-1;
	if(this != NULL && nacionalidad != NULL){
		if(IsValidNacionalidad(nacionalidad)==1){
			rtn =1;
			strncpy(this->nacionalidad,nacionalidad,MAX_CHARS);
		}
	}
	return rtn;
}
int Arcade_getNacionalidad(Arcade* this,char* nacionalidad){
	int rtn=-1;
	if(this != NULL && nacionalidad != NULL){
		rtn =1;
		strncpy(nacionalidad,this->nacionalidad,MAX_CHARS);
	}
	return rtn;
}

int Arcade_setTipoSonidoTxt(Arcade* this,char* tipoSonido){
	int rtn=-1;
	if(this != NULL && tipoSonido != NULL){
		if(IsValidTipoSonido(tipoSonido)==1){
			rtn =1;
			this->tipoSonido = atoi(tipoSonido);
		}
	}
	return rtn;
}
int Arcade_getTipoSonidoTxt(Arcade* this,char* tipoSonido){
	int rtn=-1;
	if(this != NULL && tipoSonido != NULL){
		rtn =1;
		sprintf(tipoSonido,"%d",this->tipoSonido);
	}
	return rtn;
}
int Arcade_setTipoSonido(Arcade* this,int tipoSonido){
	int rtn=-1;
	if(this != NULL && tipoSonido >= 0){
		rtn =1;
		this->tipoSonido = tipoSonido;
	}
	return rtn;
}
int Arcade_getTipoSonido(Arcade* this,int* tipoSonido){
	int rtn=-1;
	if(this != NULL && tipoSonido >= 0){
		rtn =1;
		*tipoSonido = this->tipoSonido;
	}
	return rtn;
}

int Arcade_setCantJugadoresTxt(Arcade* this,char* cantJugadores){
	int rtn=-1;
	if(this != NULL && cantJugadores != NULL){
		if(IsValidCantJugadores(cantJugadores)==1){
			rtn =1;
			this->cantJugadores = atoi(cantJugadores);
		}
	}
	return rtn;
}
int Arcade_getCantJugadoresTxt(Arcade* this,char* cantJugadores){
	int rtn=-1;
	if(this != NULL && cantJugadores != NULL){
		rtn =1;
		sprintf(cantJugadores,"%d",this->cantJugadores);
	}
	return rtn;
}
int Arcade_setCantJugadores(Arcade* this,int cantJugadores){
	int rtn=-1;
	if(this != NULL && cantJugadores >= 0){
		rtn =1;
		this->cantJugadores = cantJugadores;
	}
	return rtn;
}
int Arcade_getCantJugadores(Arcade* this,int* cantJugadores){
	int rtn=-1;
	if(this != NULL && cantJugadores >= 0){
		rtn =1;
		*cantJugadores = this->cantJugadores;
	}
	return rtn;
}

int Arcade_setCantFichasTxt(Arcade* this,char* cantFichas){
	int rtn=-1;
	if(this != NULL && cantFichas != NULL){
		if(IsValidCantFichas(cantFichas)==1){
			rtn =1;
			this->cantFichas = atoi(cantFichas);
		}
	}
	return rtn;
}
int Arcade_getCantFichasTxt(Arcade* this,char* cantFichas){
	int rtn=-1;
	if(this != NULL && cantFichas != NULL){
		rtn =1;
		sprintf(cantFichas,"%d",this->cantFichas);
	}
	return rtn;
}
int Arcade_setCantFichas(Arcade* this,int cantFichas){
	int rtn=-1;
	if(this != NULL && cantFichas >= 0){
		rtn =1;
		this->cantFichas = cantFichas;
	}
	return rtn;
}
int Arcade_getCantFichas(Arcade* this,int* cantFichas){
	int rtn=-1;
	if(this != NULL && cantFichas >= 0){
		rtn =1;
		*cantFichas = this->cantFichas;
	}
	return rtn;
}

int Arcade_setIdSalonTxt(Arcade* this,char* idSalon){
	int rtn=-1;
	if(this != NULL && idSalon != NULL){
		if(IsValidIdSalon(idSalon)==1){
			rtn =1;
			this->idSalon = atoi(idSalon);
		}
	}
	return rtn;
}
int Arcade_getIdSalonTxt(Arcade* this,char* idSalon){
	int rtn=-1;
	if(this != NULL && idSalon != NULL){
		rtn =1;
		sprintf(idSalon,"%d",this->idSalon);
	}
	return rtn;
}
int Arcade_setIdSalon(Arcade* this,int idSalon){
	int rtn=-1;
	if(this != NULL && idSalon >= 0){
		rtn =1;
		this->idSalon = idSalon;
	}
	return rtn;
}
int Arcade_getIdSalon(Arcade* this,int* idSalon){
	int rtn=-1;
	if(this != NULL && idSalon >= 0){
		rtn =1;
		*idSalon = this->idSalon;
	}
	return rtn;
}

int Arcade_setIdJuegoTxt(Arcade* this,char* idJuego){
	int rtn=-1;
	if(this != NULL && idJuego != NULL){
		if(IsValidIdJuego(idJuego)==1){
			rtn =1;
			this->idJuego = atoi(idJuego);
		}
	}
	return rtn;
}
int Arcade_getIdJuegoTxt(Arcade* this,char* idJuego){
	int rtn=-1;
	if(this != NULL && idJuego != NULL){
		rtn =1;
		sprintf(idJuego,"%d",this->idJuego);
	}
	return rtn;
}
int Arcade_setIdJuego(Arcade* this,int idJuego){
	int rtn=-1;
	if(this != NULL && idJuego >= 0){
		rtn =1;
		this->idJuego = idJuego;
	}
	return rtn;
}
int Arcade_getIdJuego(Arcade* this,int* idJuego){
	int rtn=-1;
	if(this != NULL && idJuego >= 0){
		rtn =1;
		*idJuego = this->idJuego;
	}
	return rtn;
}

static int IsValidId(char* arrayPosiblesNumeros){
	int retorno = 1;
	int i = 0;
	if(arrayPosiblesNumeros != NULL){
		while(arrayPosiblesNumeros[i] != '\0'){
			if(arrayPosiblesNumeros[i] < '0' || arrayPosiblesNumeros[i] > '9'){
				retorno = -1;
				break;
			}
			i++;
		}
	}
	else{
		retorno = -1;
	}
	return retorno;
}
static int IsValidNacionalidad(char* posiblesLetras){
	int retorno = 1;
	int i = 0;
	if(posiblesLetras != NULL){
		while(posiblesLetras[i] != '\0'){
			if(!((posiblesLetras[i]>=65 && posiblesLetras[i]<=90)||(posiblesLetras[i]>=97 && posiblesLetras[i]<=122)||posiblesLetras[i]==' ')){
				retorno = -1;
				break;
			}
			i++;
		}
	}
	else{
		retorno = -1;
	}
	return retorno;
}
static int IsValidTipoSonido(char* arrayPosiblesNumeros){
	int retorno = 1;
	int i = 0;
	if(arrayPosiblesNumeros != NULL){
		while(arrayPosiblesNumeros[i] != '\0'){
			if(arrayPosiblesNumeros[i] < '0' || arrayPosiblesNumeros[i] > '9'){
				retorno = -1;
				break;
			}
			i++;
		}
	}
	else{
		retorno = -1;
	}
	return retorno;
}
static int IsValidCantJugadores(char* arrayPosiblesNumeros){
	int retorno = 1;
	int i = 0;
	if(arrayPosiblesNumeros != NULL){
		while(arrayPosiblesNumeros[i] != '\0'){
			if(arrayPosiblesNumeros[i] < '0' || arrayPosiblesNumeros[i] > '9'){
				retorno = -1;
				break;
			}
			i++;
		}
	}
	else{
		retorno = -1;
	}
	return retorno;
}
static int IsValidCantFichas(char* arrayPosiblesNumeros){
	int retorno = 1;
	int i = 0;
	if(arrayPosiblesNumeros != NULL){
		while(arrayPosiblesNumeros[i] != '\0'){
			if(arrayPosiblesNumeros[i] < '0' || arrayPosiblesNumeros[i] > '9'){
				retorno = -1;
				break;
			}
			i++;
		}
	}
	else{
		retorno = -1;
	}
	return retorno;
}
static int IsValidIdJuego(char* arrayPosiblesNumeros){
	int retorno = 1;
	int i = 0;
	if(arrayPosiblesNumeros != NULL){
		while(arrayPosiblesNumeros[i] != '\0'){
			if(arrayPosiblesNumeros[i] < '0' || arrayPosiblesNumeros[i] > '9'){
				retorno = -1;
				break;
			}
			i++;
		}
	}
	else{
		retorno = -1;
	}
	return retorno;
}
static int IsValidIdSalon(char* arrayPosiblesNumeros){
	int retorno = 1;
	int i = 0;
	if(arrayPosiblesNumeros != NULL){
		while(arrayPosiblesNumeros[i] != '\0'){
			if(arrayPosiblesNumeros[i] < '0' || arrayPosiblesNumeros[i] > '9'){
				retorno = -1;
				break;
			}
			i++;
		}
	}
	else{
		retorno = -1;
	}
	return retorno;
}

void Arcade_showArcade(Arcade* arcade,char* nombreJuego,char* nombreSalon){
	char auxTipoSonido[MAX_CHARS];

	switch (arcade->tipoSonido){
		case 1:
			strcpy(auxTipoSonido,"mono");
			break;
		case 2:
			strcpy(auxTipoSonido,"estéreo");
			break;
		}
	printf( "| %-5d| %-20s| %-10s| %-10d| %-10d| %-20s| %-20s|\n",
			arcade->id,
			arcade->nacionalidad,
			auxTipoSonido,
			arcade->cantJugadores,
			arcade->cantFichas,
			nombreJuego,
			nombreSalon);

}

Arcade* Arcade_findArcadeById(LinkedList* this,int id){
	Arcade* rtn = NULL;
	int i;
	Arcade* auxArcade;
	if(this != NULL && id >= 0){
		for(i = 0;i < ll_len(this); i++){
			auxArcade = ll_get(this, i);
			if(auxArcade != NULL && auxArcade->id == id){
				rtn = auxArcade;
				break;
			}
		}
	}
	return rtn;
}
/*
int Arcade_lastId(char* path){
	int maxId = -1;
	char auxId[MAX_CHARS];
	FILE* pFileID;
	pFileID = fopen("lastIDArcade","r");
	if(pFileID != NULL){
		fscanf(pFileID,"%[^\n]\n",auxId);
		if(atoi(auxId) > maxId){
			maxId = atoi(auxId);
		}
		fclose(pFileID);
	}
	else{
		pFileID = fopen("lastIDArcade","w");
		maxId = 0;
		fprintf(pFileID, "%d\n",maxId);
		fclose(pFileID);
	}
	return maxId;
}*/
int Arcade_lastId(LinkedList* listaArcades){
	int maxId;
	char auxId[MAX_CHARS];
	FILE* pFileID;
	maxId = Arcade_findMaxId(listaArcades);
	pFileID = fopen("lastIDArcade.csv","r");
	if(pFileID != NULL){
		fscanf(pFileID,"%[^\n]\n",auxId);
		fclose(pFileID);
		if(atoi(auxId) > maxId){
			maxId = atoi(auxId);
			pFileID = fopen("lastIDArcade.csv","w");
			fprintf(pFileID, "%d\n",maxId);
			fclose(pFileID);
		}
	}
	else{
		pFileID = fopen("lastIDArcade.csv","w");
		if(maxId >= 0){
			fprintf(pFileID, "%d\n",maxId);
			fclose(pFileID);
		}
		else{
			fprintf(pFileID, "%d\n",0);
			fclose(pFileID);
		}
	}
	return maxId;
}

int Arcade_GenerarId(void){
	FILE* pFileID;
	char maxId[MAX_CHARS];
	int newId = -1;
	pFileID = fopen("lastIDArcade.csv","r");
	if(pFileID != NULL){
		fscanf(pFileID,"%[^,]\n",maxId);
		fclose(pFileID);
		if( atoi(maxId)>=0){
			newId = atoi(maxId);
			newId++;
			pFileID = fopen("lastIDArcade.csv","w");
			fprintf(pFileID, "%d\n",newId);
			fclose(pFileID);
		}
	}
	else{
		pFileID = fopen("lastIDArcade.csv","w");
		newId = 0;
		fprintf(pFileID, "%d\n",newId);
		fclose(pFileID);
	}
	return newId;
}

int Arcade_GetLastId(void){
	FILE* pFileID;
	char maxId[MAX_CHARS];
	pFileID = fopen("lastIDArcade.csv","r");
	fscanf(pFileID,"%[^,]\n",maxId);
	fclose(pFileID);
	return atoi(maxId);
}

int Arcade_findMaxId(LinkedList* this){
	int maxID = -1;
	int i;
	Arcade* auxArcade;
	if(this != NULL){
		for(i = 0;i < ll_len(this); i++){
			auxArcade = ll_get(this,i);
			if(auxArcade->id > maxID){
				maxID = auxArcade->id;
			}
		}
	}
	return maxID;
}

int Arcade_isValid(Arcade* this){
    int rtn = -1;
    int id;
    char nacionalidad[MAX_CHARS];
    int tipoSonido;
    int cantJugadores;
    int cantFichas;
    int idSalon;
    int idJuego;

    if(this != NULL){
        Arcade_getId(this,&id);
        Arcade_getNacionalidad(this,nacionalidad);
        Arcade_getTipoSonido(this, &tipoSonido);
        Arcade_getCantJugadores(this,&cantJugadores);
        Arcade_getCantFichas(this, &cantFichas);
        Arcade_getIdJuego(this, &idJuego);
        Arcade_getIdSalon(this, &idSalon);

        if(id > 0 && nacionalidad != NULL && tipoSonido > 0 && cantJugadores > 0 && cantFichas > 0 && idJuego > 0 && idSalon > 0){
            rtn=1;
        }
    }
    return rtn;
}

int Arcade_remplazar(Arcade* this, Arcade* this2){
	int rtn = -1;
	if(this != NULL && this2 != NULL){
		this->id = this2->id;
		strncpy(this->nacionalidad,this2->nacionalidad,MAX_CHARS);
		this->tipoSonido = this2->tipoSonido;
		this->cantJugadores = this2->cantJugadores;
		this->cantFichas = this2->cantFichas;
		this->idJuego = this2->idJuego;
		this->idSalon = this2->idSalon;
		rtn =1;
	}
	return rtn;
}

int Arcade_sortById( void* this1, void* this2){
    int rtn = 0;
    Arcade* auxP1;
    Arcade* auxP2;
    if( this1 != NULL && this2 != NULL){
    	auxP1 = (Arcade*) this1;
    	auxP2 = (Arcade*) this2;
        if(auxP1->id > auxP2->id){
        	rtn = 1;
        } else if(auxP1->id < auxP2->id){
        	rtn = -1;
        } else{
        	rtn = 0;
        }
    }
    return rtn;
}



