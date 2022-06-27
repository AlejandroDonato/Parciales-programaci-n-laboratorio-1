#include "Juego.h"

static int IsValidId(char* arrayPosiblesNumeros);
static int IsValidNombre(char* posibleNombre);
static int IsValidEmpresa(char* posibleEmpresa);
static int IsValidGenero(char* arrayPosiblesNumeros);

Game* Game_new(){
	return (Game*)malloc(sizeof(Game));
}

Game* Game_newParametros(char* nombre, char* empresa, int genero){
	Game* auxGameP = NULL;
	auxGameP = Game_new();
	if(auxGameP != NULL && nombre != NULL && empresa != NULL && genero >= 0){
		if( Game_setNombre(auxGameP, nombre) ==1 &&
			Game_setEmpresa(auxGameP, empresa) == 1 &&
			Game_setGenero(auxGameP, genero) == 1){
			auxGameP->id = Game_GenerarId();
			if(auxGameP->id < 0){
				free(auxGameP);
				auxGameP = NULL;
			}
		}
		else{
			free(auxGameP);
			auxGameP = NULL;
		}
	}
	else{
		free(auxGameP);
		auxGameP = NULL;
	}
	return auxGameP;
}

Game* Game_newParametrosTxt(char* nombre, char* empresa,char* genero,char* id){
	Game* auxGameP = NULL;
	auxGameP = Game_new();
	if(auxGameP != NULL && nombre != NULL && empresa != NULL && genero !=NULL && id !=NULL){
		if( Game_setNombre(auxGameP, nombre) ==1 &&
			Game_setEmpresa(auxGameP, empresa) == 1 &&
			Game_setGeneroTxt(auxGameP, genero) == 1 &&
			Game_setIdTxt(auxGameP, id) == 1){
		}
		else{
			free(auxGameP);
			auxGameP = NULL;
		}
	}
	else{
		free(auxGameP);
		auxGameP = NULL;
	}
	return auxGameP;
}

int Game_setIdTxt(Game* this,char* id){
	int rtn=-1;
	if(this != NULL && id != NULL){
		if(IsValidId(id)==1){
			rtn =1;
			this->id = atoi(id);
		}
	}
	return rtn;
}
int Game_getIdTxt(Game* this,char* id){
	int rtn=-1;
	if(this != NULL && id != NULL){
		rtn =1;
		sprintf(id,"%d",this->id);
	}
	return rtn;
}
int Game_setId(Game* this,int id){
	int rtn=-1;
	if(this != NULL && id >= 0){
		rtn =1;
		this->id = id;
	}
	return rtn;
}
int Game_getId(Game* this,int* id){
	int rtn=-1;
	if(this != NULL && id >= 0){
		rtn =1;
		*id = this->id;
	}
	return rtn;
}

int Game_setNombre(Game* this,char* nombre){
	int rtn=-1;
	if(this != NULL && nombre != NULL){
		if(IsValidNombre(nombre)==1){
			rtn =1;
			strncpy(this->nombre,nombre,MAX_CHARS);
		}
	}
	return rtn;
}
int Game_getNombre(Game* this,char* nombre){
	int rtn=-1;
	if(this != NULL && nombre != NULL){
		rtn =1;
		strncpy(nombre,this->nombre,MAX_CHARS);
	}
	return rtn;
}

int Game_setEmpresa(Game* this,char* empresa){
	int rtn=-1;
	if(this != NULL && empresa != NULL){
		if(IsValidEmpresa(empresa)==1){
			rtn =1;
			strncpy(this->empresa,empresa,MAX_CHARS);
		}
	}
	return rtn;
}
int Game_getEmpresa(Game* this,char* empresa){
	int rtn=-1;
	if(this != NULL && empresa != NULL){
		rtn =1;
		strncpy(empresa,this->empresa,MAX_CHARS);
	}
	return rtn;
}

int Game_setGeneroTxt(Game* this,char* genero){
	int rtn=-1;
	if(this != NULL && genero != NULL){
		if(IsValidGenero(genero)==1){
			rtn =1;
			this->genero = atoi(genero);
		}
	}
	return rtn;
}
int Game_getGeneroTxt(Game* this,char* genero){
	int rtn=-1;
	if(this != NULL && genero != NULL){
		rtn =1;
		sprintf(genero,"%d",this->genero);
	}
	return rtn;
}
int Game_setGenero(Game* this,int genero){
	int rtn=-1;
	if(this != NULL && genero >= 0){
		rtn =1;
		this->genero = genero;
	}
	return rtn;
}
int Game_getGenero(Game* this,int* genero){
	int rtn=-1;
	if(this != NULL && genero >= 0){
		rtn =1;
		*genero = this->genero;
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
static int IsValidNombre(char* posibleNombre){
	int retorno = 1;
	int i = 0;

	if(posibleNombre != NULL){
		while(posibleNombre[i] != '\0'){
			if(!((posibleNombre[i]>=65 && posibleNombre[i]<=90)||
				 (posibleNombre[i]>=97 && posibleNombre[i]<=122)||
				  posibleNombre[i]==' '||
				 (posibleNombre[i]>='0' || posibleNombre[i]<='9'))){
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
static int IsValidEmpresa(char* posibleEmpresa){
	int retorno = 1;
	int i = 0;

	if(posibleEmpresa != NULL){
		while(posibleEmpresa[i] != '\0'){
			if(!((posibleEmpresa[i]>=65 && posibleEmpresa[i]<=90)||
				 (posibleEmpresa[i]>=97 && posibleEmpresa[i]<=122)||
				  posibleEmpresa[i]==' '||
				 (posibleEmpresa[i]>='0' || posibleEmpresa[i]<='9'))){
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
static int IsValidGenero(char* arrayPosiblesNumeros){
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


void Game_showGame(Game* this){
	char auxGenero[MAX_CHARS];
	switch (this->genero) {
		case OTRO:
			strncpy(auxGenero,"Otro",MAX_CHARS);
			break;
		case PLATAFORMA:
			strncpy(auxGenero,"Plataforma",MAX_CHARS);
			break;
		case LABERINTO:
			strncpy(auxGenero,"Laberinto",MAX_CHARS);
			break;
		case AVENTURA:
			strncpy(auxGenero,"Aventura",MAX_CHARS);
			break;
	}
	printf( "| %-9d| %-29s| %-29s| %-29s|\n",
			this->id,
			this->nombre,
			this->empresa,
			auxGenero);
}

int Game_lastId(LinkedList* listaJuegos){
	int maxId;
	char auxId[MAX_CHARS];
	FILE* pFileID;
	maxId = Game_findMaxId(listaJuegos);
	pFileID = fopen("lastIDGame.csv","r");
	if(pFileID != NULL){
		fscanf(pFileID,"%[^\n]\n",auxId);
		fclose(pFileID);
		if(atoi(auxId) > maxId){
			maxId = atoi(auxId);
			pFileID = fopen("lastIDGame.csv","w");
			fprintf(pFileID, "%d\n",maxId);
			fclose(pFileID);
		}
	}
	else{
		pFileID = fopen("lastIDGame.csv","w");
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

int Game_GenerarId(void){
	FILE* pFileID;
	char maxId[MAX_CHARS];
	int newId = -1;
	pFileID = fopen("lastIDGame.csv","r");
	if(pFileID != NULL){
		fscanf(pFileID,"%[^,]\n",maxId);
		fclose(pFileID);
		if( atoi(maxId)>=0){
			newId = atoi(maxId);
			newId++;
			pFileID = fopen("lastIDGame.csv","w");
			fprintf(pFileID, "%d\n",newId);
			fclose(pFileID);
		}
	}
	else{
		pFileID = fopen("lastIDGame.csv","w");
		newId = 0;
		fprintf(pFileID, "%d\n",newId);
		fclose(pFileID);
	}
	return newId;}


Game* Game_findGamebyId(LinkedList* this, int id){
	Game* rtn = NULL;
	int i;
	Game* auxGame;
	if(this != NULL && id >0){
		i = 0;
		while(i < ll_len(this)){
			auxGame = ll_get(this,i);
			if(auxGame->id == id){
				rtn = auxGame;
				break;
			}
			i++;
		}
	}
	return rtn;
}

int Game_findMaxId(LinkedList* this){
	int maxID = -1;
	int i;
	Game* auxGame;
	if(this != NULL){
		for(i = 0;i < ll_len(this); i++){
			auxGame = ll_get(this,i);
			if(auxGame->id > maxID){
				maxID = auxGame->id;
			}
		}
	}
	return maxID;
}

int Game_findMinId(LinkedList* this){
	int maxID = -1;
	int i;
	Game* auxGame;
	if(this != NULL){
		for(i = 0;i < ll_len(this); i++){
			auxGame = ll_get(this,i);
			if(maxID == -1){
				maxID = auxGame->id;
			}
			else if(auxGame->id < maxID){
				maxID = auxGame->id;
			}
		}
	}
	return maxID;
}

int Game_isValid(Game* this){
    int rtn = -1;
    int id;
    char nombre[MAX_CHARS];
    char empresa[MAX_CHARS];
    int genero;

    if(this != NULL){
        Game_getId(this,&id);
        Game_getNombre(this,nombre);
        Game_getEmpresa(this,empresa);
        Game_getGenero(this,&genero);
        if(id > 0 && nombre != NULL && empresa != NULL && genero >= 0){
            rtn=1;
        }
    }
    return rtn;
}

int Game_sortByName( void* this1, void* this2){
    int rtn = 0;
    Game* auxP1;
    Game* auxP2;
    if( this1 != NULL && this2 != NULL){
    	auxP1 = (Game*) this1;
    	auxP2 = (Game*) this2;
        if( strcmp(auxP1->nombre, auxP2->nombre) > 0){
        	rtn = 1;
        } else if( strcmp(auxP1->nombre, auxP2->nombre) < 0){
        	rtn = -1;
        } else{
        	rtn = 0;
        }
    }
    return rtn;
}
