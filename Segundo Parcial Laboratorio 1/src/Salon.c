#include "Salon.h"

static int IsValidId(char* arrayPosiblesNumeros);
static int IsValidNombre(char* posibleNombre);
static int IsValidDireccion(char* posibleDireccion);
static int IsValidTipo(char* arrayPosiblesNumeros);

Salon* Salon_new(){
	return (Salon*)malloc(sizeof(Salon));
}

Salon* Salon_newParametros(char* nombre, char* direccion, int tipo){
	Salon* auxSalonP = NULL;
	auxSalonP = Salon_new();
	if(auxSalonP != NULL && nombre != NULL && direccion != NULL && tipo > 0){
		if( Salon_setNombre(auxSalonP, nombre) ==1 &&
			Salon_setDireccion(auxSalonP, direccion) == 1 &&
			Salon_setTipo(auxSalonP, tipo) == 1){
			auxSalonP->id = Salon_GenerarId();
			if(auxSalonP->id < 0){
				free(auxSalonP);
				auxSalonP = NULL;
			}
		}
		else{
			free(auxSalonP);
			auxSalonP = NULL;
		}
	}
	else{
		free(auxSalonP);
		auxSalonP = NULL;
	}
	return auxSalonP;
}

Salon* Salon_newParametrosTxt(char* nombre, char* direccion,char* tipo,char* id){
	Salon* auxSalonP = NULL;
	auxSalonP = Salon_new();
	if(auxSalonP != NULL && nombre != NULL && direccion != NULL && tipo !=NULL && id !=NULL){
		if( Salon_setNombre(auxSalonP, nombre) ==1 &&
			Salon_setDireccion(auxSalonP, direccion) == 1 &&
			Salon_setTipoTxt(auxSalonP, tipo) == 1 &&
			Salon_setIdTxt(auxSalonP, id) == 1){
		}
		else{
			free(auxSalonP);
			auxSalonP = NULL;
		}
	}
	else{
		free(auxSalonP);
		auxSalonP = NULL;
	}
	return auxSalonP;
}

int Salon_setIdTxt(Salon* this,char* id){
	int rtn=-1;
	if(this != NULL && id != NULL){
		if(IsValidId(id)==1){
			rtn =1;
			this->id = atoi(id);
		}
	}
	return rtn;
}
int Salon_getIdTxt(Salon* this,char* id){
	int rtn=-1;
	if(this != NULL && id != NULL){
		rtn =1;
		sprintf(id,"%d",this->id);
	}
	return rtn;
}
int Salon_setId(Salon* this,int id){
	int rtn=-1;
	if(this != NULL && id >= 0){
		rtn =1;
		this->id = id;
	}
	return rtn;
}
int Salon_getId(Salon* this,int* id){
	int rtn=-1;
	if(this != NULL && id >= 0){
		rtn =1;
		*id = this->id;
	}
	return rtn;
}

int Salon_setNombre(Salon* this,char* nombre){
	int rtn=-1;
	if(this != NULL && nombre != NULL){
		if(IsValidNombre(nombre)==1){
			rtn =1;
			strncpy(this->nombre,nombre,MAX_CHARS);
		}
	}
	return rtn;
}
int Salon_getNombre(Salon* this,char* nombre){
	int rtn=-1;
	if(this != NULL && nombre != NULL){
		rtn =1;
		strncpy(nombre,this->nombre,MAX_CHARS);
	}
	return rtn;
}

int Salon_setDireccion(Salon* this,char* direccion){
	int rtn=-1;
	if(this != NULL && direccion != NULL){
		if(IsValidDireccion(direccion)==1){
			rtn =1;
			strncpy(this->direccion,direccion,MAX_CHARS);
		}
	}
	return rtn;
}
int Salon_getDireccion(Salon* this,char* direccion){
	int rtn=-1;
	if(this != NULL && direccion != NULL){
		rtn =1;
		strncpy(direccion,this->direccion,MAX_CHARS);
	}
	return rtn;
}

int Salon_setTipoTxt(Salon* this,char* tipo){
	int rtn=-1;
	if(this != NULL && tipo != NULL){
		if(IsValidTipo(tipo)==1){
			rtn =1;
			this->tipo = atoi(tipo);
		}
	}
	return rtn;
}
int Salon_getTipoTxt(Salon* this,char* tipo){
	int rtn=-1;
	if(this != NULL && tipo != NULL){
		rtn =1;
		sprintf(tipo,"%d",this->tipo);
	}
	return rtn;
}
int Salon_setTipo(Salon* this,int tipo){
	int rtn=-1;
	if(this != NULL && tipo >= 0){
		rtn =1;
		this->tipo = tipo;
	}
	return rtn;
}
int Salon_getTipo(Salon* this,int* tipo){
	int rtn=-1;
	if(this != NULL && tipo >= 0){
		rtn =1;
		*tipo = this->tipo;
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
			if(!((posibleNombre[i]>=65 && posibleNombre[i]<=90)||(posibleNombre[i]>=97 && posibleNombre[i]<=122)||posibleNombre[i]==' ')){
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
static int IsValidDireccion(char* posibleDireccion){
	int retorno = 1;
	int i = 0;

	if(posibleDireccion != NULL){
		while(posibleDireccion[i] != '\0'){
			if(!((posibleDireccion[i]>=65 && posibleDireccion[i]<=90)||
				 (posibleDireccion[i]>=97 && posibleDireccion[i]<=122)||
   				 (posibleDireccion[i] >='0' && posibleDireccion[i] <='9')||
				 posibleDireccion[i]==' ')){
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
static int IsValidTipo(char* arrayPosiblesNumeros){
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

void Salon_showSalon(Salon* this){
	char auxTipo[MAX_CHARS];
	switch (this->tipo) {
		case SHOPING:
			strncpy(auxTipo,"Shoping",MAX_CHARS);
			break;
		case LOCAL:
			strncpy(auxTipo,"Local",MAX_CHARS);
			break;
	}
	printf( "| %-9d| %-29s| %-29s| %-29s|\n",
			this->id,
			this->nombre,
			this->direccion,
			auxTipo);
}

int Salon_lastId(LinkedList* listaSalones){
	int maxId;
	char auxId[MAX_CHARS];
	FILE* pFileID;
	pFileID = fopen("lastIDSalon.csv","r");
	maxId = Salon_findMaxId(listaSalones);
	if(pFileID != NULL){
		fscanf(pFileID,"%[^\n]\n",auxId);
		fclose(pFileID);
		if(atoi(auxId) > maxId){
			maxId = atoi(auxId);
			pFileID = fopen("lastIDSalon.csv","w");
			fprintf(pFileID, "%d\n",maxId);
			fclose(pFileID);
		}
	}
	else{
		pFileID = fopen("lastIDSalon.csv","w");
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

int Salon_GenerarId(void){
	FILE* pFileID;
	char maxId[MAX_CHARS];
	int newId = -1;
	pFileID = fopen("lastIDSalon.csv","r");
	if(pFileID != NULL){
		fscanf(pFileID,"%[^,]\n",maxId);
		fclose(pFileID);
		if( atoi(maxId)>=0){
			newId = atoi(maxId);
			newId++;
			pFileID = fopen("lastIDSalon.csv","w");
			fprintf(pFileID, "%d\n",newId);
			fclose(pFileID);
		}
	}
	else{
		pFileID = fopen("lastIDSalon.csv","w");
		newId = 0;
		fprintf(pFileID, "%d\n",newId);
		fclose(pFileID);
	}
	return newId;
}

Salon* Salon_findSalonById(LinkedList* this, int id){
	Salon* rtn = NULL;
	int i;
	Salon* auxSalon;
	if(this != NULL && id >0){
		i = 0;
		while(i < ll_len(this)){
			auxSalon = (Salon*)ll_get(this,i);

			if(auxSalon->id == id){
				rtn = auxSalon;
				break;
			}
			i++;
		}
	}
	return rtn;
}

int Salon_findMaxId(LinkedList* this){
	int maxID = -1;
	int i;
	Salon* auxSalon;
	if(this != NULL){
		for(i = 0;i < ll_len(this); i++){
			auxSalon = ll_get(this,i);
			if(auxSalon->id > maxID){
				maxID = auxSalon->id;
			}
		}
	}
	return maxID;
}

int Salon_findMinId(LinkedList* this){
	int maxID = -1;
	int i;
	Salon* auxSalon;
	if(this != NULL){
		for(i = 0;i < ll_len(this); i++){
			auxSalon = ll_get(this,i);
			if(maxID == -1){
				maxID = auxSalon->id;
			}
			else if(auxSalon->id < maxID){
				maxID = auxSalon->id;
			}
		}
	}
	return maxID;
}

int Salon_remplazar(Salon* this, Salon* this2){
	int rtn = -1;
	if(this != NULL && this2 != NULL){
		this->id = this2->id;
		strncpy(this->nombre,this2->nombre,MAX_CHARS);
		strncpy(this->direccion,this2->direccion,MAX_CHARS);
		this->tipo = this2->tipo;
		rtn =1;
	}
	return rtn;
}

int Salon_isValid(Salon* this){
    int rtn = -1;
    int id;
    char nombre[MAX_CHARS];
    char direccion[MAX_CHARS];
    int tipo;

    if(this != NULL){
        Salon_getId(this,&id);
        Salon_getNombre(this,nombre);
        Salon_getDireccion(this,direccion);
        Salon_getTipo(this,&tipo);
        if(id > 0 && nombre != NULL && direccion != NULL && tipo > 0){
            rtn=1;
        }
    }
    return rtn;
}
