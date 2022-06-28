#include <stdio.h>
#include <stdlib.h>

#include "Arcade.h"
#include "LinkedList.h"
#include "Controller.h"

#define ACENDENTE 1
#define DECENDENTE 0

int main(void){
	setbuf(stdout,NULL);
	LinkedList* listaSalones = ll_newLinkedList();
	LinkedList* listaArcades = ll_newLinkedList();
	LinkedList* listaJuegos = ll_newLinkedList();
	int option = -1;
	int flagGuardar = 0;
    int salir = 0;
    int tipoDeCarga = 1; /// 0 para carga binaria y 1 para carga de texto

    controller_cargaDeDatosInicial(tipoDeCarga,listaSalones,listaArcades,listaJuegos);

    do{
    	puts(	"++-^-++-^-^-^-++-^-^-^-++-^----^-++-^-^-^-++-^-^-^-++-^-++\n"
				"||<o>||>-<o>-<||>-<o>-<||  MENU  ||>-<o>-<||>-<o>-<||<o>||\n"
				"++---++-------++-------++--------++-------++-------++---++\n"
				"||                                                      ||\n"
    			"||  ----| SALONES |----                                 ||\n"
    			"||  ( 1). Alta de salón                                 ||\n"
    			"||  ( 2). Eliminar Salón                                ||\n"
    			"||  ( 3). Listar Salones                                ||\n"
    			"||                                                      ||\n"
    			"||  ----| ARCADE |----                                  ||\n"
    			"||  ( 4). Incorporar arcade                             ||\n"
    			"||  ( 5). Modificar arcade                              ||\n"
    			"||  ( 6). Eliminar arcade                               ||\n"
    			"||  ( 7). Imprimir arcade                               ||\n"
    			"||                                                      ||\n"
    			"||  ----| Juego |----                                   ||\n"
    			"||  ( 8). Agregar juego                                 ||\n"
    			"||  ( 9). Imprimir juego                                ||\n"
    			"||                                                      ||\n"
    			"||  ----| Informes |----                                ||\n"
    			"||  (10). Menu de informes                              ||\n"
    			"||                                                      ||\n"
    			"||  ----| Filtrar |----                                 ||\n"
    			"||  (11). Filtrar salon por tipo                        ||\n"
    			"||  (12). Filtrar juegos por tipo de plataforma         ||\n"
    			"||                                                      ||\n"
    			"||  ( 0). Salir                                         ||\n"
    			"||                                                      ||\n"
    			"++------------------------------------------------------++\n");
    		if(getIntInRange("Ingrese una opcion:",3,0,12,"Opcion invalida",&option) !=1){
    			controller_MensajeError("Error!, agotado numero de reintentos");
    			option =0;
    		}
        switch(option)
        {
        /////////////////SALON/////////////////
            case 1:///Alta de salón
            	controller_MensajeCabecera("ALTA DE SALÓN ");
            	if(controller_addSalon(listaSalones) ==1){
            		controller_MensajeExitoso("Alta exitosa");
            		flagGuardar = 1;
            	}
            	else{controller_MensajeError("Error, No se pudo dar de alta ");
            	}
            	break;
            case 2:///Eliminar Salón
            	if(controller_countSalones(listaSalones)>0){
            		controller_MensajeCabecera("ELIMINAR SALON");
            		if(controller_removeSalon(listaSalones, listaArcades) ==1){
            			controller_MensajeExitoso("Exito al eliminar el salon");
            			flagGuardar = 1;
            		}
            		else{controller_MensajeError("Error, no se pudo eliminar el salon ");
            		}
            	}
            	else{controller_MensajeError("No hay salones para mostrar ");
            	}
            	break;
            case 3:///Listar Salones
            	if(controller_countSalones(listaSalones)>0){
            		controller_MensajeCabecera("LISTA DE SALONES");
            		controller_ListSalones(listaSalones);
            	}
            	else{controller_MensajeError("No hay salones para mostrar ");
            	}
            	break;
            /////////////////ARCADE/////////////////
            case 4:///Incorporar arcade
            	if(controller_countSalones(listaSalones)<=0){
            		controller_MensajeError("Error, no hay salones activos ");
            	}
            	else if(controller_countGames(listaJuegos)>0){
            		controller_MensajeCabecera("INCORPORAR ARCADE ");
            		if(controller_addArcade(listaArcades,listaSalones,listaJuegos) ==1){
            			controller_MensajeExitoso("Arcade cargdo con exito ");
            			flagGuardar = 1;
            		}
            		else{controller_MensajeError("Error, no se pudo cargar el arcade");
            		}
            	}
            	else{controller_MensajeError("Error, hay juegos para cargar ");
            	}
            	break;
            case 5:///Modificar arcade
            	if(controller_countArcades(listaArcades)>0){
            		controller_MensajeCabecera("MODIFICAR ARCADE");
            		if(controller_editArcade(listaArcades,listaSalones,listaJuegos) ==1){
            			controller_MensajeExitoso("Modificacion exitosa");
            			flagGuardar = 1;
            		}
            		else{controller_MensajeError("Error, no se pudo modificar ");
            		}
            	}
            	else{controller_MensajeError("Error, no hay arcades cargados");
            	}
            	break;
            case 6:///Eliminar arcade
            	if(controller_countArcades(listaArcades)>0){
            		controller_MensajeCabecera("ELIMINAR ARCADE");
            		if(controller_removeArcade(listaArcades,listaSalones,listaJuegos) ==1){
            			controller_MensajeExitoso("Arcade eliminado con exito");
            			flagGuardar = 1;
            		}
            		else{controller_MensajeError("Error, no se pudo eliminar");
            		}
            	}
            	else{controller_MensajeError("Error, no hay arcades cargados");
            	}
            	break;
            case 7:///Imprimir arcade
            	if(controller_countArcades(listaArcades)>0){
            		controller_MensajeCabecera("LISTA DE ARCADES");
            		if(controller_ListArcades(listaArcades,listaSalones,listaJuegos)>=0){
            		}
            		else{controller_MensajeError("Error, no se pudo mostrar los arcades ");
            		}
            	}
            	else{controller_MensajeError("Error, no hay arcades cargados");
            	}
            	break;
            /////////////////JUEGO/////////////////
            case 8:///Agregar juego
            	controller_MensajeCabecera("AGREGAR JUEGO");
            	if(controller_addGame(listaJuegos)==1){
            		controller_MensajeExitoso("Juego agregado con exito");
            		flagGuardar=1;
            	}
            	else{controller_MensajeError("Error, No se agrego el juego");
            	}
            	break;
            case 9:///Imprimir juego
            	if(controller_countGames(listaJuegos)>0){
            		controller_MensajeCabecera("IMPRIMIR JUEGOS ");
            		controller_ListGames(listaJuegos);
            	}
            	else{controller_MensajeError("Error, No existen juegos cargados");
            	}
            	break;
            /////////////////INFORMES/////////////////
            case 10:///Menu de informes
            	if(controller_countArcades(listaArcades)>0){
            		controller_MensajeCabecera("MENU DE INFORMES");
            		controler_MenuInformes(listaArcades,listaSalones,listaJuegos);
            	}
            	else{controller_MensajeError("Error, no hay arcades cargados");
            	}
            	break;
            /////////////////FILTRAR/////////////////
            case 11:///Filtrar salon
            	if(controller_countSalones(listaSalones)>0){
            		controller_MensajeCabecera("Filtrar por tipo de salon ");
            		controler_FiltrarPorSalon(listaSalones);
            	}
            	else{controller_MensajeError("No hay salones para mostrar ");
            	}
            	break;
            case 12:///Filtrar juegos
            	if(controller_countGames(listaSalones)>0){
            		controller_MensajeCabecera("Filtrar por tipo de Plataforma");
            		controler_FiltrarPorGeneroDeJuego(listaJuegos);
            	}
            	else{controller_MensajeError("No hay Juegos para mostrar");
            	}
            	break;
            /////////////////SALIR/////////////////
            case 0:///Guardar y salir
            	if(flagGuardar==1){
            		if(controller_saveSalonAsBinary("Salones.bin",listaSalones)==1 &&
            		   controller_saveArcadeAsBinary("Arcades.bin",listaArcades)==1 &&
		               controller_saveGameAsBinary("Games.bin",listaJuegos)==1){
            			controller_MensajeExitoso("Binario guardado con exito");
            			salir = 1;
            		}
            		else{controller_MensajeError("Error al guardar como binario ");
            		}
            		if(controller_saveSalonAsText("Salones.csv",listaSalones)==1 &&
            		   controller_saveArcadeAsText("Arcades.csv",listaArcades)==1 &&
                       controller_saveGameAsText("Games.csv",listaJuegos)==1){
            			controller_MensajeExitoso("Texto guardado con exito");
            			salir = 1;
            		}
            		else{controller_MensajeError("Error al guardar como texto ");
            		}
            	}
            	else{salir = 1;
            	}
            	break;
        }
    }while(salir != 1);
    controller_MensajeCabecera("FIN DEL PROGRAMA");
    return 0;
}

//agregar un filtro a la linkedlist
