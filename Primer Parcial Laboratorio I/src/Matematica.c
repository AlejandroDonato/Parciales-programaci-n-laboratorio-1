#include "Matematica.h"


int Multiplicacion(float numeroUno, float numeroDos, float *resultado){
	int rtn;
	float auxiliarProducto;

	if(resultado != NULL){
	auxiliarProducto = numeroUno * numeroDos;
	*resultado = auxiliarProducto;
	rtn = 1;
	}
	else {
		rtn =0;
		}
	return rtn;
}

int Divicion(float dividendo,float divisor, float* resultado){
	int flag;
	if(divisor != 0 && resultado != NULL){
	*resultado = dividendo / divisor;
	flag =1;
	}
	else {
	flag =0;
	*resultado =0;
	}
	return flag;
}

int sumar(float num1, float num2, float* resultado){
	int flag;
	if(resultado != NULL){
		*resultado = num1 + num2;
		flag =1;
	}
	else {
		flag =0;
		*resultado =0;
		}
	return flag;
}

int resta(float num1, float num2, float* resultado){
	int flag;
	if(resultado != NULL){
		*resultado = num1 - num2;
		flag =1;
	}
	else {
		flag =0;
		*resultado =0;
		}
	return flag;
}

int ReglaDeTres(float numeroA, float numeroB, float numeroC, float* resultado){
	int flag;
	if(resultado != NULL && numeroA != 0){
		*resultado = numeroC * numeroB / numeroA;
		flag =1;
	}
	else {
		flag =0;
		*resultado =0;
		}
	return flag;
}
