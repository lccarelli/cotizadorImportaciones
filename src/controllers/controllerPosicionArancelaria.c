/*
 * controllerArticulo.c
 *
 *  Created on: 19 jun. 2021
 *      Author: lau
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "controllerPosicionArancelaria.h"
#include "../entidades/PosicionArancelaria.h"
#include "../collections/LinkedList.h"
#include "../utils/utn.h"
#include "../utils/Menu.h"

static int controller_buscarUltimoId(int id, int* idMaxA, int indice);

int controller_posicionAlta(Dictionary* posicionArancelaria, int* idMaxPA){

	int retorno = ERROR;
	char descripcion[DESCRIPCION_LEN];
	float seguro, importacion, tasaEstadistica;
	int licencia;
	char idChar[11];
	int id;

	PosicionArancelaria* pPA = NULL;

	if(posicionArancelaria != NULL){
		if(
				posicion_requestDescripcion(descripcion) == OK &&
				posicion_requestSeguro(&seguro) == OK &&
				posicion_requestImportacion(&importacion) == OK &&
				posicion_requestTasaEstadistica(&tasaEstadistica) == OK &&
				posicion_requestLicencia(&licencia) == OK

		){
			posicion_setearValorInicialDeId(*idMaxPA);
			id = posicion_generarId();
			snprintf(idChar, sizeof(idChar), "%d", id);
			if(dict_insert(posicionArancelaria,idChar, pPA) == OK){
				*idMaxPA = id;
				retorno = OK;
			}
		} else {
			posicion_borrar(pPA);
		}
	}
	return retorno;
}

int controller_listarPosiciones(Dictionary* posicionArancelaria){
	int retorno = ERROR;
	PosicionArancelaria* pPA;
	LinkedList* list;

	if(posicionArancelaria!=NULL){
		list = dict_getValues(posicionArancelaria);
		printf("\nID,NCM,SEGURO,DERECHO,TASA,TIPO_LICENCIA");
		for(int i=0; i<ll_len(list);i++){
			pPA=ll_get(list, i);
			if(controller_listarPosicion(pPA) == OK){
				retorno = OK;
			}
		}
	}
	return retorno;
}

int controller_listarPosicion(PosicionArancelaria* pPA){
	int flag = ERROR;
	if(pPA!=NULL){
		printf("\n%d -> %s -%f - %f - %f - %d",
				posicion_getId(pPA, &flag),
				posicion_getDescripcion(pPA, &flag),
				posicion_getSeguro(pPA, &flag),
				posicion_getImportacion(pPA, &flag),
				posicion_getTasaEstadistica(pPA, &flag),
				posicion_getLicencia(pPA, &flag));
	}
	return flag;
}

int controller_borrarPosicion(Dictionary* posicionArancelaria){
	char idCadena[32];
	int retorno = OK;
	PosicionArancelaria* pPA;

	if(utn_getStringWithOnlyNumbers(
			"\nIngrese ID a borrar->",
			"ERROR",
			idCadena,
			sizeof(idCadena), 3) == OK

	){
		pPA = dict_get(posicionArancelaria, idCadena);
		controller_listarPosicion(pPA);
		posicion_borrar(pPA) == OK ? dict_remove(posicionArancelaria, idCadena): (retorno = ERROR);

	}
	return retorno;
}

int controller_modificarPosicion(Dictionary* posicionArancelaria){
	char idCadena[32], descripcion[DESCRIPCION_PO];
	float seguro, importacion, tasaEstadistica;
	int licencia, select;
	int retorno = OK;
	PosicionArancelaria* pPA;

	if(utn_getStringWithOnlyNumbers(
			"\nIngrese ID a modificar->",
			"ERROR",
			idCadena,
			sizeof(idCadena), 3) == OK

	){
		pPA = dict_get(posicionArancelaria, idCadena);
		controller_listarPosicion(pPA);

		if(pPA!=NULL){
			do{
				menu_modificarPosicion(&select);
				switch(select){

				case DESCRIPCION_PO:
					if (
							posicion_requestDescripcion(descripcion) == OK &&
							posicion_setDescripcion(pPA, descripcion) == OK
						){
							printf("\nModificacion exitosa.");
							retorno = OK;
						 }
					break;

				case SEGURO:
					if (
							posicion_requestSeguro(&seguro) == OK &&
							posicion_setSeguro(pPA, seguro) == OK
					){
							printf("\nModificacion exitosa");
							retorno = OK;
						}
					break;

				case IMPORTACION:
					if (
							posicion_requestImportacion(&importacion) == OK &&
							posicion_setImportacion(pPA, importacion) == OK
					){
							printf("\nModificacion exitosa");
							retorno = OK;
						}
					break;

				case TASA_ESTADISTICA:
					if (
							posicion_requestTasaEstadistica(&tasaEstadistica) == OK &&
							posicion_setTasaEstadistica(pPA, tasaEstadistica) == OK
					){
							printf("\nModificacion exitosa");
							retorno = OK;
						}
					break;

				case LICENCIA:
					if (
							posicion_requestLicencia(&licencia) == OK &&
							posicion_setLicencia(pPA, licencia) == OK
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

int controller_leerDeArchivoPosicion(char* archivo, Dictionary* posicionArancelaria, int* idMaxPA){
	FILE* pFile;
	char id[101];
	char descripcion[101];
	char seguro[101];
	char importacion[101];
	char tasaEstadistica[101];
	char licencia[101];
	int idA;
	int idMax;
	PosicionArancelaria* pPA;
	int indice=0;
	int retorno = ERROR;


	pFile = fopen(archivo,"r");
	if(pFile!=NULL){
		indice=0;
		do{
			if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,descripcion,seguro,importacion,tasaEstadistica,licencia) == 6){
				printf("%s %s %s %s %s %s\n",id,descripcion,seguro,importacion,tasaEstadistica,licencia);
				if(utn_isNumeric(id)){
					idA = atoi(id);
					pPA = posicion_nuevoConParametros(
							idA,
							descripcion,
							atof(seguro),
							atof(importacion),
							atof(tasaEstadistica),
							atoi(licencia));
					dict_insert(posicionArancelaria, id, pPA);
					idMax = controller_buscarUltimoId(idA, idMaxPA, indice);
					retorno = OK;
				}
				indice++;
			}
		}
		while(feof(pFile)==0 && indice<100);
		fclose(pFile);
		*idMaxPA = idMax;
	}
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

int controller_guardarEnArchivoPosicion(char* archivo, Dictionary* posicionArancelaria){
	int retorno = ERROR;
	int flag;

	FILE* pFile;
	PosicionArancelaria* pPA;
	LinkedList* list;

	pFile = fopen(archivo, "w");
	if(pFile!=NULL){
		list = dict_getValues(posicionArancelaria);
		fprintf(pFile, "ID, SEGURO, IMPORTACION, TASA_ESTADISTICA, LICENCIA\n");
		for(int i=0; i<ll_len(list); i++){
			pPA = ll_get(list,i);
			fprintf(
					pFile,
					"%d, %s, %.2f, %.2f, %.2f, %d\n",
					posicion_getId(pPA, &flag),
					posicion_getDescripcion(pPA, &flag),
					posicion_getSeguro(pPA, &flag),
					posicion_getImportacion(pPA, &flag),
					posicion_getTasaEstadistica(pPA, &flag),
					posicion_getLicencia(pPA, &flag));

			!flag ? (retorno = OK) : posicion_borrar(pPA);
		}
		fclose(pFile);
	}
	return retorno;
}


float calcularSeguro(float seguro,float valorFOB){
	return (float)(valorFOB*(seguro/100));
}

float calcularBaseImponible(float valorFOB, float dato, Transporte* trnspt, PosicionArancelaria* pPA, float(*funcionTransporte)(Transporte*,float)){

	return 	(float)(valorFOB +
			calcularSeguro(pPA->seguro,valorFOB) +
			funcionTransporte(trnspt,dato));
}

PosicionArancelaria* devolver_posicionArancelaria(Dictionary* this, char* idCadena){
	PosicionArancelaria* pPA;
	return pPA = dict_get(this, idCadena);
}

float calcularImpuesto(float baseImponible, float impuesto){

	return (float)baseImponible*(impuesto/100);
}

float costoTotal(PosicionArancelaria* pPA, float baseImponible, float(*funcionImpuesto)(float,float)){

	return 	(float)(baseImponible +
			funcionImpuesto(pPA->importacion, baseImponible) +
			funcionImpuesto(pPA->tasaEstadistica, baseImponible));
}


