/*
 * PosicionArancelaria.c
 *
 *  Created on: 19 jun. 2021
 *      Author: lau
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../entidades/PosicionArancelaria.h"
#include "../collections/LinkedList.h"
#include "../utils/Menu.h"
#include "../utils/utn.h"

PosicionArancelaria* posicion_nuevo(void){
	return (PosicionArancelaria*)malloc(sizeof(PosicionArancelaria));
}

PosicionArancelaria* posicion_nuevoConParametros(
										int id,
										char* descripcion,
										float seguro,
										float importacion,
										float tasaEstadistica,
										int licencia)
{
	PosicionArancelaria* aux = posicion_nuevo();
	if( aux != NULL){
		if (
				posicion_setId(aux, id) < 0 ||
				posicion_setDescripcion(aux, descripcion) < 0 ||
				posicion_setSeguro(aux, seguro) < 0 ||
				posicion_setImportacion(aux, importacion) < 0 ||
				posicion_setTasaEstadistica(aux, tasaEstadistica) < 0 ||
				posicion_setLicencia(aux, licencia) < 0

		){
			if( posicion_borrar(aux) == OK )
			aux = NULL;
		}
	}
	return aux;
}

int posicion_borrar(PosicionArancelaria* this){
	int retorno = ERROR;
	if(this != NULL){
		free(this);
		retorno = OK;
	}
	return retorno;
}

int posicion_requestDescripcion(char* descripcion){
	int retorno = ERROR;
	if (!utn_getString("\nDESCRIPCION?: ", "\nERROR-> DESCRIPCION", descripcion, DESCRIPCION_LEN, 3))
		retorno = OK;
	return retorno;
}

int posicion_requestSeguro(float* seguro){
	int retorno = ERROR;
	if (!utn_getFloat("\n% SEGURO:", "\nERROR-> SEGURO", seguro, 3)){
		retorno = OK;
	}
	return retorno;
}

int posicion_requestImportacion(float* importacion){
	int retorno = ERROR;
	if (!utn_getFloat("\n% IMPORTACION:", "\nERROR-> IMPORTACION", importacion, 3)){
		retorno = OK;
	}
	return retorno;
}

int posicion_requestTasaEstadistica(float* tasaEstadistica){
	int retorno = ERROR;
	if (!utn_getFloat("\n% TASA ESTADISTICA:", "\nERROR-> TASA ESTADISTICA", tasaEstadistica, 3)){
		retorno = OK;
	}
	return retorno;
}

int posicion_requestLicencia(int* licencia){
	int retorno = ERROR;
	if (!utn_getInt("\n% Licencia Automatica (1) - Licencia No-Automatica(0)", "\nERROR-> Licencia", licencia, 3)){
		retorno = OK;
	}
	return retorno;
}

int posicion_setId(PosicionArancelaria* this, int id){
	int retorno = ERROR;
	if(this !=NULL){
		this->id = id;
		retorno = OK;
	}
	return retorno;
}

int posicion_setDescripcion(PosicionArancelaria* this, char* descripcion){
	int retorno = ERROR;
	if(this!= NULL && descripcion!=NULL){
		strcpy(this->descripcion, descripcion);
		retorno = OK;
	}
	return retorno;
}

int posicion_setSeguro(PosicionArancelaria* this, float seguro){
	int retorno = ERROR;

	if(this != NULL && seguro > 0){
		this->seguro = seguro;
		retorno = OK;
	}
	return retorno;
}

int posicion_setImportacion(PosicionArancelaria* this, float importacion){
	int retorno = ERROR;
	if(this != NULL && importacion > 0){
		this->importacion = importacion;
		retorno = OK;
	}
	return retorno;
}

int posicion_setTasaEstadistica(PosicionArancelaria* this, float tasaEstadistica){
	int retorno = ERROR;
	if(this != NULL){
		this->tasaEstadistica = tasaEstadistica;
		retorno = OK;
	}
	return retorno;
}

int posicion_setLicencia(PosicionArancelaria* this, int licencia){
	int retorno = ERROR;
	if(this !=NULL){
		this->licencia = licencia;
		retorno = OK;
	}
	return retorno;
}

int posicion_getId(PosicionArancelaria* this, int* flag){
	*flag = ERROR;
	int aux;
	if (this != NULL && flag !=NULL){
		aux = this->id;
		*flag = OK;
	}
	return aux;
}

char* posicion_getDescripcion(PosicionArancelaria* this, int* flag){
	*flag = ERROR;
	char* aux;
	if (this != NULL && flag !=NULL){
		aux = this->descripcion;
		*flag = OK;
	}
	return aux;
}

float posicion_getSeguro(PosicionArancelaria* this, int* flag){
	*flag = ERROR;
	float aux;
	if (this != NULL && flag !=NULL){
		aux = this->seguro;
		*flag = OK;
	}
	return aux;
}

float posicion_getImportacion(PosicionArancelaria* this, int* flag){
	*flag = ERROR;
	float aux;
	if (this != NULL && flag !=NULL){
		aux = this->importacion;
		*flag = OK;
	}
	return aux;
}

float posicion_getTasaEstadistica(PosicionArancelaria* this, int* flag){
	*flag = ERROR;
	float aux;
	if (this != NULL && flag !=NULL){
		aux = this->tasaEstadistica;
		*flag = OK;
	}
	return aux;
}

int posicion_getLicencia(PosicionArancelaria* this, int* flag){
	*flag = ERROR;
	int aux;
	if (this != NULL && flag !=NULL){
		aux = this->licencia;
		*flag = OK;
	}
	return aux;
}


static int contador=0; // NO ES LOCAL DE LA FUNCION

void posicion_setearValorInicialDeId(int id){
	contador = id;
}

int posicion_generarId(void){
	contador++;
	return contador;
}






