#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void){
    LinkedList* this= NULL;
    this = (LinkedList *)malloc(sizeof(LinkedList));
    if(this != NULL){
    	this->size=0;
    	this->pFirstNode = NULL;
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this){
	int returnAux = -1;
	    if(this != NULL){
	        returnAux = this->size;
	    }
    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex){
	Node* pNode = NULL;
	    int i;
	    if(this != NULL && nodeIndex >= 0 && nodeIndex < ll_len(this)){
	        pNode = this->pFirstNode;
	        for(i = 0; i < nodeIndex; i++){
	        	pNode = pNode->pNextNode;
	        }
	    }
	    return pNode;
}
/*static Node* getNode(LinkedList* this, int nodeIndex){
	Node* pNode = NULL;
	    int i;
	    if(this != NULL && nodeIndex >= 0 && nodeIndex < ll_len(this)){
	        pNode = this->pFirstNode;
	        for(i = 0; i < ll_len(this); i++){
	        	if(nodeIndex == i){
	        		break;
	        	}
	        	else{
	        		pNode = pNode->pNextNode;
	        	}
	        }
	    }
	    return pNode;
}*/

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex){
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement){
    int rtn = -1;
    Node* pNewNode = (Node*) malloc(sizeof(Node));
    Node* pAuxNode = NULL;
    if(this != NULL && nodeIndex >= 0 && nodeIndex <= ll_len(this)+1 && pNewNode != NULL){
        pNewNode->pElement = pElement;
        pNewNode->pNextNode = NULL;
        rtn = 0;
        this->size++;
        if(nodeIndex == 0 && ll_len(this) == 0){//posicion 0 - lista vacia
            this->pFirstNode = pNewNode;
        }
        else if(nodeIndex == 0 && ll_len(this)!=0){//posicion 0 - lista cargada
        	pAuxNode = getNode(this, 0);
        	this->pFirstNode = pNewNode;
        	this->pFirstNode->pNextNode = pAuxNode;
        }
        else if(nodeIndex == ll_len(this)){// ultima posicion - lista cargada
        	pAuxNode = getNode(this, nodeIndex-1);
        	pAuxNode->pNextNode = pNewNode;
        }
        else{// posicion x - lista cargada
        	pAuxNode = getNode(this, nodeIndex-1);
        	pAuxNode->pNextNode = pNewNode;
        	pAuxNode->pNextNode->pNextNode = pAuxNode;
        }
    }
    return rtn;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement){
	int rtn = -1;
	 if(this != NULL){
	        rtn = addNode(this, ll_len(this), pElement);
	    }
	    return rtn;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index){
    void* rtn = NULL;
    Node* auxNode;
    if(this != NULL && index >= 0 && index < ll_len(this)){
    	auxNode = getNode(this, index);
    	if(auxNode->pElement != NULL){
    		rtn = auxNode->pElement;
    	}
    }
    return rtn;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement){
	int rtn = -1;
	    Node* auxNode;
	    if(this != NULL && index >= 0 && index < ll_len(this)){
	        auxNode = getNode(this, index);
	        auxNode->pElement = pElement;
	        rtn = 0;
	    }
	    return rtn;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index){
	int rtn = -1;
	Node* prevNode;
	Node* pDelNode;
	if(this != NULL && index >= 0 && index < ll_len(this) && ll_len(this) > 0){
		pDelNode = getNode(this, index);
		if(index == 0){
			this->pFirstNode = pDelNode->pNextNode;
		}
		else{
			prevNode = getNode(this, index -1);
			prevNode->pNextNode = pDelNode->pNextNode;
		}
		free(pDelNode);
		this->size--;
		rtn = 0;
	}
	return rtn;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this){
	int rtn = -1;
	int i;
	Node* pDelNode;
	Node* pAuxNode;
	if(this != NULL && ll_len(this) > 0){
		for(i = 0; i < ll_len(this); i++){
			pDelNode=getNode(this,i);
			if(pDelNode!=NULL){
				pAuxNode = pDelNode->pNextNode;
				this->size--;
				free(pDelNode);
			}
			free(pAuxNode);
		}
		this->pFirstNode = NULL;
		if(ll_len(this) == 0){
			rtn = 0;
		}
	}
	return rtn;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this){
	int rtn = -1;
	if(this != NULL){
		ll_clear(this);
		free(this);
		rtn = 0;
	}
	return rtn;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement){
	int rtn = -1;
	int i;
	Node* pAuxNode;
	if(this!=NULL){
		pAuxNode = this->pFirstNode;
		for(i = 0; i < ll_len(this); i++){
			if(pAuxNode->pElement == pElement){
				rtn = i;
				break;
			}
			pAuxNode = pAuxNode->pNextNode;
		}
	}
	return rtn;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this){
	int rtn = -1;
	if(this != NULL){
		if(ll_len(this) == 0 && this->pFirstNode == NULL){
			rtn = 1;
		}
		else if(ll_len(this) != 0 && this->pFirstNode != NULL){
			rtn = 0;
		}
	}
	return rtn;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement){
	 int rtn = -1;
	    if(this != NULL && index >= 0 && index <= ll_len(this)){
	         if(addNode(this,index,pElement) == 0){
	        	 rtn = 0;
	        }
	    }
	    return rtn;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index){
	void* rtn = NULL;
	if(this != NULL && index >= 0 && index < ll_len(this)){
		rtn = ll_get(this,index);
		ll_remove(this,index);
	}
	return rtn;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement){
	 int rtn = -1;
	 if(this != NULL){
		 if(ll_indexOf(this,pElement) >= 0){
			 rtn = 1;
		 } else {
			 rtn = 0;
		 }
	 }
	 return rtn;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2){
	int rtn = -1;
	int cont = 0;
	int i;
	Node* pAuxNode;
	if(this != NULL && this2 != NULL){
		if(ll_len(this) >= ll_len(this2)){
			for(i = 0; i <ll_len(this2); i++){
				pAuxNode = ll_get(this2,i);
				if(ll_contains(this,pAuxNode)==1){
					cont++;
				}
			}
		}
		if(cont == ll_len(this2)){
			rtn = 1;
		}
		else{
			rtn = 0;
		}
	}
	return rtn;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to){
	LinkedList* newThis = NULL;
	void* auxElement = NULL;
	int i;
	if(this != NULL && from >= 0 && from < to && to <= ll_len(this)){
		newThis = ll_newLinkedList();
		if(newThis != NULL){
			for(i = from; i < to; i++){
				auxElement = ll_get(this, i);
				ll_add(newThis,auxElement);
			}
		}
	}
	return newThis;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this){
	LinkedList* cloneArray = NULL;
	if(this != NULL ){
		cloneArray = ll_subList(this,0,ll_len(this));
	}
	return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order){
	int rtn =-1;
	int i,j;
	void* auxElement;
	void* pElementI;
	void* pElementJ;
	if (this != NULL && ll_len(this) > 1 && (order == 1 || order == 0) && pFunc != NULL){
		rtn = 0;
		for(i = 0; i < ll_len(this) - 1; i++){
			for(j = i + 1; j < ll_len(this); j++){
				pElementI = ll_get(this, i);
				pElementJ = ll_get(this, j);
				if(order == 0){//orden descendente
					if( pFunc(pElementI, pElementJ) == -1 ){
						auxElement = pElementI;
						ll_set(this, i, pElementJ);
						ll_set(this, j, auxElement);
					}
				}
				else if(order == 1){//orden ascendente
					if( pFunc(pElementI, pElementJ) == 1 ){
						auxElement = pElementI;
						ll_set(this, i, pElementJ);
						ll_set(this, j, auxElement);
					}
				}
			}
		}
	}
	return rtn;
}

