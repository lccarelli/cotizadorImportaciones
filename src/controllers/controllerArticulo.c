/*
 * controllerArticulo.c
 *
 *  Created on: 19 jun. 2021
 *      Author: lau
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../controllers/controllerTransporte.h"
#include "../controllers/controllerPosicionArancelaria.h"
#include "../entidades/Transporte.h"
#include "../entidades/PosicionArancelaria.h"
#include "../entidades/Articulo.h"
#include "../collections/LinkedList.h"
#include "controllerArticulo.h"
#include "../utils/utn.h"
#include "../utils/Menu.h"

static int controller_buscarUltimoId(int id, int* idMaxA, int indice);
static int compararCostoMayorMaritimo(void* this1, void* this2);

int controller_articuloAlta(Dictionary* articulos, int* idMax, Transporte* trnspt, Dictionary* pscn){

	int retorno = ERROR;
	char codigo[TEXTO_LEN], descripcion[TEXTO_LEN], paisFabricacion[TEXTO_LEN], nomenclatura[TEXTO_LEN];
	float alto, largo, profundidad, peso, valorFOB;
	int posicionArancelaria;
	char idChar[11], idPAChar[11];
	int id, flag;

	Articulo* pA = NULL;
	PosicionArancelaria* pPA = NULL;

	if(articulos != NULL){

		if(articulo_requestPosicionArancelaria(&posicionArancelaria) == OK){
			snprintf(idPAChar, sizeof(idPAChar), "%d", posicionArancelaria);
			pPA = devolver_posicionArancelaria(pscn, idPAChar);

			if(pPA!=NULL){

				if(
					articulo_requestCodigo(codigo) == OK &&
					articulo_requestDescripcion(descripcion) == OK &&
					articulo_requestPaisFabricacion(paisFabricacion) == OK &&
					articulo_requestMedidasAlto(&alto) == OK &&
					articulo_requestMedidasLargo(&largo) == OK &&
					articulo_requestMedidasProfundidad(&profundidad) == OK &&
					articulo_requestPeso(&peso) == OK &&
					articulo_requestValorFOB(&valorFOB) == OK &&
					articulo_requestNomenclatura(nomenclatura) == OK
				){
					articulo_setearValorInicialDeId(*idMax);
					id = articulo_generarId();
					pA = articulo_nuevoConParametros(
														id,
														codigo,
														descripcion,
														paisFabricacion,
														alto,
														largo,
														profundidad,
														peso,
														valorFOB,
														nomenclatura,
														posicionArancelaria
													);
					articulo_setCM3(pA,controller_calcularCM3Articulo(alto, largo, profundidad));
					snprintf(idChar, sizeof(idChar), "%d", id);
					controller_calcularTransporte(trnspt, pA, pPA);
					if(dict_insert(articulos,idChar, pA) == OK){
						*idMax = id;

						printf("\nLos costos de importacion son -> ");
						printf("\nValorFOB - COSTO_MARITIMO - COSTO_AEREO");
						printf("\n\t%.2f\t-\t%.2f\t-\t%.2f",
								articulo_getValorFOB(pA, &flag),
								articulo_getCostoMaritimo(pA, &flag),
								articulo_getCostoAereo(pA, &flag));
						retorno = OK;
					}
				} else articulo_borrar(pA);
			} else printf("\n CARGAR POSICION ARANCELARIA");
		}
	}
	return retorno;
}


int controller_listarArticulos(Dictionary* articulos){
	int retorno = ERROR;
	Articulo* pA = NULL;
	LinkedList* list = NULL;

	if(articulos!=NULL){
		list = dict_getValues(articulos);
		printf("\nID  CODIGO\tITEM\t\t\tORIGEN\tFOB\tKG\tALTO\tANCHO\tPROFUNDO\tNCM\t\tCOSTO_MARIT\tCOSTO_AEREO");
		for(int i=0; i<ll_len(list);i++){
			pA=ll_get(list, i);
			if(controller_listarArticulo(pA) == OK){
				retorno = OK;
			}
		}
	} else {
		articulo_borrar(pA);
		ll_deleteLinkedList(list);
	}
	return retorno;
}

int controller_listarArticulo(Articulo* pA){
	int flag = ERROR;
	if(pA!=NULL){
		printf("\n%d -> %s\t%s\t%s\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t\t%s\t%.2f\t\t%.2f",
				articulo_getId(pA, &flag),
				articulo_getCodigo(pA, &flag),
				articulo_getDescripcion(pA, &flag),
				articulo_getPaisFabricacion(pA, &flag),
				articulo_getValorFOB(pA, &flag),
				articulo_getPeso(pA, &flag),
				articulo_getMedidaAlto(pA, &flag),
				articulo_getMedidaLargo(pA, &flag),
				articulo_getMedidaProfundidad(pA, &flag),
				articulo_getNomenclatura(pA, &flag),
				articulo_getCostoMaritimo(pA, &flag),
				articulo_getCostoAereo(pA, &flag));
	}
	return flag;
}

int controller_borrarArticulo(Dictionary* articulos){
	char idCadena[32];
	int retorno = OK;
	Articulo* pA;

	if(utn_getStringWithOnlyNumbers(
			"\nIngrese ID a borrar->",
			"ERROR",
			idCadena,
			sizeof(idCadena), 3) == OK

	){
		pA = dict_get(articulos, idCadena);
		controller_listarArticulo(pA);
		articulo_borrar(pA) == OK ? dict_remove(articulos, idCadena): (retorno = ERROR);

	}
	return retorno;
}

int controller_modificarArticulo(Dictionary* articulos){
	char idCadena[32], codigo[101], descripcion[101], paisFabricacion[101];
	float alto, largo, profundidad, valorFOB;
	int select, idPosicion;
	int retorno = OK;
	Articulo* pA;

	if(utn_getStringWithOnlyNumbers(
			"\nIngrese ID a modificar->",
			"ERROR",
			idCadena,
			sizeof(idCadena), 3) == OK

	){
		pA = dict_get(articulos, idCadena);
		controller_listarArticulo(pA);

		if(pA!=NULL){
			do{
				menu_modificarArticulo(&select);
				switch(select){

				case CODIGO:
					if (
							articulo_requestCodigo(codigo) == OK &&
							articulo_setCodigo(pA, codigo) == OK
						){
							printf("\nModificacion exitosa.");
							retorno = OK;
						 }
					break;

				case DESCRIPCION:
					if (
							articulo_requestDescripcion(descripcion) == OK &&
							articulo_setDescripcion(pA, descripcion) == OK
					){
							printf("\nModificacion exitosa");
							retorno = OK;
						}
					break;

				case PAIS_FABRICACION:
					if (
							articulo_requestPaisFabricacion(paisFabricacion) == OK &&
							articulo_setPaisFabricacion(pA, paisFabricacion) == OK
					){
							printf("\nModificacion exitosa");
							retorno = OK;
						}
					break;

				case MEDIDA_ALTO:
					if (
							articulo_requestMedidasAlto(&alto) == OK &&
							articulo_setMedidasAlto(pA, alto) == OK
					){
							printf("\nModificacion exitosa");
							retorno = OK;
						}
					break;

				case MEDIDA_LARGO:
					if (
							articulo_requestMedidasLargo(&largo) == OK &&
							articulo_setMedidasLargo(pA, largo) == OK
					){
							printf("\nModificacion exitosa");
							retorno = OK;
						}
					break;

				case MEDIDA_PROFUNDO:
					if (
							articulo_requestMedidasProfundidad(&profundidad) == OK &&
							articulo_setMedidasProfundidad(pA, profundidad) == OK
					){
							printf("\nModificacion exitosa");
							retorno = OK;
						}
					break;

				case VALOR_FOB:
					if (
							articulo_requestValorFOB(&valorFOB) == OK &&
							articulo_setValorFOB(pA, valorFOB) == OK
					){
							printf("\nModificacion exitosa");
							retorno = OK;
						}
					break;

				case POSICION_ARANCELARIA:
					if (
							articulo_requestPosicionArancelaria(&idPosicion) == OK &&
							articulo_setPosicionArancelaria(pA, idPosicion) == OK
					){
							printf("\nModificacion exitosa");
							retorno = OK;
						}
					break;
				}
				retorno = OK;

			}while(!(select==SALIR));
		}

	}
	return retorno;
}

/*--------------------------------ARCHIVOS-------------------------------------*/
/*--------------------------------ARCHIVOS-------------------------------------*/
/*--------------------------------ARCHIVOS-------------------------------------*/
/*--------------------------------ARCHIVOS-------------------------------------*/

int controller_leerDeArchivo(char* archivo, Dictionary* articulos, int* idMaxA, Transporte* trnspt, Dictionary* pscn){
	FILE* pFile;
	char id[101];
	char codigo[101];
	char descripcion[101];
	char paisFabricacion[101];
	char alto[101];
	char largo[101];
	char profundidad[101];
	char peso[101];
	char valorFOB[101];
	char nomenclatura[101];
	char idPosicion[101];
	int idA;
	int idMax;
	Articulo* pA = NULL;
	int indice=-1;
	int retorno = ERROR;
	PosicionArancelaria* pPA = NULL;

	pFile = fopen(archivo,"r");
	if(pFile!=NULL){
		indice=0;
		do{
			if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",
						id,
						codigo,
						descripcion,
						paisFabricacion,
						valorFOB,
						peso,
						alto,
						largo,
						profundidad,
						nomenclatura,
						idPosicion) == 11
				){
				printf("%s %s %s %s %s %s %s %s %s %s %s\n",id,codigo,descripcion,paisFabricacion,alto,largo,profundidad,peso,valorFOB,nomenclatura,idPosicion);
				pPA = devolver_posicionArancelaria(pscn, idPosicion);
				if(utn_isNumeric(id)){
					idA = atoi(id);
					pA = articulo_nuevoConParametros(
							atoi(id),
							codigo,
							descripcion,
							paisFabricacion,
							atof(alto),
							atof(largo),
							atof(profundidad),
							atof(peso),
							atof(valorFOB),
							nomenclatura,
							atoi(idPosicion));
					articulo_setCM3(pA,controller_calcularCM3Articulo(atof(alto), atof(largo), atof(profundidad)));
					controller_calcularTransporte(trnspt, pA, pPA);
					dict_insert(articulos, id, pA);
					idMax = controller_buscarUltimoId(idA, idMaxA, indice);
					retorno = OK;
				}	indice++;
			}
		}
		while(feof(pFile)==0 && indice<20);
		fclose(pFile);
		*idMaxA = idMax;
	} else	articulo_borrar(pA);
	return retorno;
}


static int controller_buscarUltimoId(int id, int* idMaxA, int indice){

	int idMax;

	if(indice == 0) idMax = id;
	else {
		if(id > *idMaxA) idMax = id;
	}
	return idMax;
}

int controller_guardarEnArchivo(char* archivo, Dictionary* articulos){
	int retorno = ERROR;
	int flag;

	FILE* pFile;
	Articulo* pA = NULL;
	LinkedList* list = NULL;

	pFile = fopen(archivo, "w");
	if(pFile!=NULL){
		list = dict_getValues(articulos);
		fprintf(pFile, "ID, CODIGO, DESCRIPCION, PAIS_FABRICACION, MEDIDA_ALTO, MEDIDA_LARGO, MEDIDA_PROFUNDIDAD, PESO, VALOR_FOB, ID_POSICION, COSTO_MARITIMO,COSTO_AEREO\n");
		for(int i=0; i<ll_len(list); i++){
			pA = ll_get(list,i);
			fprintf(
					pFile,
					"%d, %s, %s, %s, %.3f, %.3f, %.3f, %.3f, %.3f, %d,%.3f,%.3f\n",
					articulo_getId(pA, &flag),
					articulo_getCodigo(pA, &flag),
					articulo_getDescripcion(pA, &flag),
					articulo_getPaisFabricacion(pA, &flag),
					articulo_getMedidaAlto(pA, &flag),
					articulo_getMedidaLargo(pA, &flag),
					articulo_getMedidaProfundidad(pA, &flag),
					articulo_getPeso(pA, &flag),
					articulo_getValorFOB(pA, &flag),
					articulo_getPosicionArancelaria(pA, &flag),
					articulo_getCostoMaritimo(pA, &flag),
					articulo_getCostoAereo(pA, &flag));

			!flag ? (retorno = OK) : articulo_borrar(pA);
		}
		fclose(pFile);
	} else {
		articulo_borrar(pA);
		ll_deleteLinkedList(list);
	}
	return retorno;
}

float controller_calcularCM3Articulo(float alto, float largo, float profundidad){
	return (alto*largo*profundidad);
}

void controller_calcularTransporte(Transporte*trnspt, Articulo* pA, PosicionArancelaria* pPA){

	float aereoVolumetrico, maritimo, aereoPesoReal;

	aereoPesoReal = costoTotal(	pPA,
								calcularBaseImponible(pA->valorFOB,pA->peso,trnspt,pPA,controller_calcularAereoPesoReal),
								calcularImpuesto);
	aereoVolumetrico = costoTotal(	pPA,
									calcularBaseImponible(pA->valorFOB,pA->medidas.cm3,trnspt,pPA,controller_calcularAereoPesoVolumentrico),
									calcularImpuesto);

	maritimo = costoTotal(	pPA,
				calcularBaseImponible(pA->valorFOB,pA->medidas.cm3,trnspt,pPA,controller_calcularMaritimo),
				calcularImpuesto);


	aereoPesoReal > aereoVolumetrico ?
			articulo_setCostoAereo(pA, aereoPesoReal):
			articulo_setCostoAereo(pA, aereoVolumetrico);


	articulo_setCostoMaritimo(pA,maritimo);

}

int controller_ordenarPorCostoMaritimo(Dictionary* articulos){
	int retorno = ERROR;
	LinkedList* list = NULL;

	if(articulos!=NULL){

		list = dict_getValues(articulos);
		sortCostoMaritimo(list);
		imprimirCostos(list);
		retorno = OK;
	}
	return retorno;
}

int sortCostoMaritimo(LinkedList* list){
    int result;

    if(list != NULL){
        ll_sort(list, compararCostoMayorMaritimo, 0);
        result = OK;
    } else {result = ERROR;};
    return result;
}


static int compararCostoMayorMaritimo(void* this1, void* this2){
	int flag;
    float costoA;
    float costoB;

    costoA = articulo_getCostoMaritimo((Articulo*)this1, &flag);
    costoB = articulo_getCostoMaritimo((Articulo*)this2, &flag);

    if(costoA > costoB){
    	return 1;
    };
    if(costoA < costoB){
    	return -1;
    };

    return 0;
};

int imprimirCostos(LinkedList* list){

	int flag;
	int retorno = ERROR;
	Articulo* pA = NULL;

	if(list!=NULL){
		printf("\nLos costos de importacion son -> ");
		printf("\nNMC\t\tVFOB\tCOSTO_MARITIMO\tCOSTO_AEREO");
		for(int i=0; i<ll_len(list);i++){
			pA=ll_get(list, i);
			printf("\n%s\t%.2f\t%.2f\t\t%.2f",
					articulo_getNomenclatura(pA, &flag),
					articulo_getValorFOB(pA, &flag),
					articulo_getCostoMaritimo(pA, &flag),
					articulo_getCostoAereo(pA, &flag));
				retorno = OK;
		}
	} else {
		articulo_borrar(pA);
		ll_deleteLinkedList(list);
	}
	return retorno;
}
