#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../collections/Dictionary.h"
#include "../collections/LinkedList.h"
#include "../entidades/Articulo.h"
#include "../entidades/PosicionArancelaria.h"
#include "../entidades/Transporte.h"
#include "../controllers/controllerArticulo.h"
#include "../utils/utn.h"


static int buscarMaritimoMayor(void* articulo, float filtro);
static void transporte_imprimirArticulos(Articulo* pA);

LinkedList* ll_filtrar(LinkedList* this,float filtro, int (*funcionCriterio)(void*,float)){
	LinkedList* filtrada=NULL;
	int i;
	void* pA;
	if(this!=NULL){
		// 1) GENERO LISTA FILTRADA ( FILTRO )
		filtrada = ll_newLinkedList();
		for(i=0; i<ll_len(this); i++){
			pA = ll_get(this, i);
			if(funcionCriterio(pA,filtro)){
				ll_add(filtrada,pA);
			}
		}
	}
	return filtrada;
}

static int buscarMaritimoMayor(void* articulo, float filtro){
	int retorno = 0;
	int flag = ERROR;
	if(articulo!=NULL){
		if(articulo_getCostoMaritimo(articulo, &flag)>filtro){
			retorno = 1;
		}
	}
	return retorno;
}

void informes_listarMaritimosMayor(Dictionary* articulos){
	LinkedList* list = NULL;
	LinkedList* listaFiltrada = NULL;
	Articulo* pA = NULL;
	float filtro;

	if(articulos!=NULL){
		list = dict_getValues(articulos);
		utn_getFloat("\nIngrese: buscar Maritimos mayor a->", "\nERROR", &filtro, 3);
		listaFiltrada = ll_filtrar(list, filtro,buscarMaritimoMayor);
		printf("\n ID	NMC		COSTO_MARTITIMO");
		for(int i=0; i<ll_len(listaFiltrada); i++){
			pA = ll_get(listaFiltrada, i);
			transporte_imprimirArticulos(pA);
		}
	} else {
		articulo_borrar(pA);
		ll_deleteLinkedList(list);
		ll_deleteLinkedList(listaFiltrada);
	}
}

static void transporte_imprimirArticulos(Articulo* pA){
	int flag;

	printf("\n %d	%s	%.2f",
			articulo_getId(pA, &flag),
			articulo_getNomenclatura(pA, &flag),
			articulo_getCostoMaritimo(pA, &flag));

}

