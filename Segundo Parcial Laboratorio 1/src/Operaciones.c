#include "Operaciones.h"

int TodosLosCalculos(float precioVuelo,float descuento,float recargo,float ValorOtraMoneda,float distancia,
	  float *precioConDescuento,float *precioConRegargo,float *precioEnOtraMoneda,float *precioXDistancia){
	int rtn;
	float resultado1;
	float resultado2;
	float resultado3;
	float resultado4;

	if(Multiplicacion(precioVuelo, descuento, &resultado1) == 1 &&
	   Multiplicacion(precioVuelo, recargo, &resultado2) == 1 &&
	   ReglaDeTres(ValorOtraMoneda, 1, precioVuelo, &resultado3) == 1 &&
	   Divicion(precioVuelo,distancia, &resultado4) == 1){
		rtn = 1;

		*precioConDescuento = resultado1;
		*precioConRegargo = resultado2;
		*precioEnOtraMoneda = resultado3;
		*precioXDistancia = resultado4;
	}
	else{
		rtn = 0;
	}
	return rtn;
}
