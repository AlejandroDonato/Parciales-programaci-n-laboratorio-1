#include "validacion.h"


int EsNumeroFlotante(char arrayPosiblesNumeros[]){
	int retorno = 1;
	int i = 0;
	int flagDecimal = 0;

	if(arrayPosiblesNumeros != NULL){
		if(arrayPosiblesNumeros[0]=='-'){
			i = 1;//si el primer lugar es un menos salteamos a la siguiente posicion para verificar los numeros
		}
		if(arrayPosiblesNumeros[i] == '.' || arrayPosiblesNumeros[i] == ','){
			retorno = -1;
		}
		while(!(arrayPosiblesNumeros[i] == '\0' || retorno == -1)){
			if((arrayPosiblesNumeros[i] == '.' || arrayPosiblesNumeros[i] == ',') && flagDecimal == 0){
				arrayPosiblesNumeros[i] = '.';//para que siempre sea un punto aunque ingresen una coma
				flagDecimal = 1; // solo se permite que tenga una coma/punto en un numero decimal
			}
			else if(arrayPosiblesNumeros[i] < '0' || arrayPosiblesNumeros[i] > '9'){
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

int EsNumeroEntero(char arrayPosiblesNumeros[]){
	int retorno = 1;
	int i = 0;

	if(arrayPosiblesNumeros != NULL){
		if(arrayPosiblesNumeros[0]=='-'){
			i = 1;//si el primer lugar es un menos salteamos a la siguiente posicion para verificar los numeros
		}
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

int EsChar(char arrayPosiblesLetras[]){
	int retorno = 1;
	int i = 0;

	if(arrayPosiblesLetras != NULL){

		while(arrayPosiblesLetras[i] != '\0'){
			if(!((arrayPosiblesLetras[i]>=65 && arrayPosiblesLetras[i]<=90)||(arrayPosiblesLetras[i]>=97 && arrayPosiblesLetras[i]<=122))){
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

int EsCharAndInt(char arrayPosiblesLetras[]){
	int retorno = 1;
	int i = 0;

	if(arrayPosiblesLetras != NULL){

		while(arrayPosiblesLetras[i] != '\0'){
			if(!((arrayPosiblesLetras[i]>=65 && arrayPosiblesLetras[i]<=90)||
				(arrayPosiblesLetras[i]>=97 && arrayPosiblesLetras[i]<=122)||
				(arrayPosiblesLetras[i] >='0' && arrayPosiblesLetras[i] <='9'))){
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

int EsAlfanumerica(char arrayPosiblesLetras[]){
	int retorno = -1;
	int i;
	int flagLetra;
	int flagNumero;

	if(arrayPosiblesLetras != NULL){
		i = 0;
		flagLetra =0;
		flagNumero =0;

		while(arrayPosiblesLetras[i] != '\0'){
			if(!((arrayPosiblesLetras[i]>=65 && arrayPosiblesLetras[i]<=90)||
				 (arrayPosiblesLetras[i]>=97 && arrayPosiblesLetras[i]<=122)||
				 (arrayPosiblesLetras[i]>='0'&& arrayPosiblesLetras[i]<='9'))){
					break;
			}
			if(((arrayPosiblesLetras[i]>=65 && arrayPosiblesLetras[i]<=90)||
			   (arrayPosiblesLetras[i]>=97 && arrayPosiblesLetras[i]<=122)) && flagLetra == 0 ){
				flagLetra =1;
			}
			if((arrayPosiblesLetras[i] >='0' && arrayPosiblesLetras[i] <='9') && flagNumero == 0){
				flagNumero =1;
			}
			i++;
		}
		if(flagLetra == 1 && flagNumero == 1){
			retorno = 1;
		}
	}
	return retorno;
}

int EsEmail(char arrayPosiblesLetras[]){
	int retorno;
	int i;
	int flagArroba;
	int flagPunto;

	if(arrayPosiblesLetras != NULL){
		i = 0;
		flagArroba =0;
		flagPunto =0;
		retorno = 0;
		if((arrayPosiblesLetras[i]>=65 && arrayPosiblesLetras[i]<=90)||
		   (arrayPosiblesLetras[i]>=97 && arrayPosiblesLetras[i]<=122)||
		   (arrayPosiblesLetras[i]>='0'&& arrayPosiblesLetras[i]<='9')){
			i = 1;
		}
		else{
			retorno = -1;
		}
		while(arrayPosiblesLetras[i] != '\0' && i > 0){
			if(flagArroba ==0 && arrayPosiblesLetras[i]=='@'){
				flagArroba =1;
			}
			else if(flagPunto ==0 && arrayPosiblesLetras[i]=='.'  && arrayPosiblesLetras[i-1]!='@'){
				flagPunto =1;
			}
			else if(!((arrayPosiblesLetras[i]>=65 && arrayPosiblesLetras[i]<=90)||
					  (arrayPosiblesLetras[i]>=97 && arrayPosiblesLetras[i]<=122)||
					  (arrayPosiblesLetras[i]>='0'&& arrayPosiblesLetras[i]<='9'))){
						retorno = -1;
						break;
			}
			i++;
		}
		if(flagArroba == 1 && flagPunto == 1){
			retorno = 1;
		}
	}
	return retorno;
}
