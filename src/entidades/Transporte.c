/*
 * Transporte.c
 *
 *  Created on: 19 jun. 2021
 *      Author: lau
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../utils/utn.h"
#include "Transporte.h"

void transporte_init(Transporte* this){
	this[0].id = 1;
	this[0].factorConversion = 6000;
	this[0].valorContenedor = 10000;
	this[0].valorKiloAereo = 12.70;
	//this[0].valorKiloMaritimo = 153;
}


int transporte_setFactorConversion(Transporte* this, float factorConversion){
	int retorno = ERROR;
	if(this != NULL && factorConversion > 0){
		this->factorConversion = factorConversion;
		retorno = OK;
	}
	return retorno;
}

int transporte_setValorContenedor(Transporte* this, float valorContenedor){
	int retorno = ERROR;
	if(this != NULL && valorContenedor > 0){
		this->valorContenedor = valorContenedor;
		retorno = OK;
	}
	return retorno;
}

int transporte_setValorKiloAereo(Transporte* this, float valorKiloAereo){
	int retorno = ERROR;
	if(this != NULL && valorKiloAereo > 0){
		this->valorKiloAereo = valorKiloAereo;
		retorno = OK;
	}
	return retorno;
}

int transporte_setValorKiloMaritimo(Transporte* this, float valorKiloMaritimo){
	int retorno = ERROR;
	if(this != NULL && valorKiloMaritimo > 0){
		this->valorKiloMaritimo = valorKiloMaritimo;
		retorno = OK;
	}
	return retorno;
}


int transporte_getId(Transporte* this, int* flag){
	*flag = ERROR;
	int aux;
	if (this != NULL && flag !=NULL){
		aux = this->id;
		*flag = OK;
	}
	return aux;
}

float transporte_getFactorConversion(Transporte* this, int* flag){
	*flag = ERROR;
	int aux;
	if (this != NULL && flag !=NULL){
		aux = this->factorConversion;
		*flag = OK;
	}
	return aux;
}

float transporte_getValorContenedor(Transporte* this, int* flag){
	*flag = ERROR;
	int aux;
	if (this != NULL && flag !=NULL){
		aux = this->valorContenedor;
		*flag = OK;
	}
	return aux;
}

float transporte_getValorKiloAereo(Transporte* this, int* flag){
	*flag = ERROR;
	int aux;
	if (this != NULL && flag !=NULL){
		aux = this->valorKiloAereo;
		*flag = OK;
	}
	return aux;
}

float transporte_getValorKiloMaritimo(Transporte* this, int* flag){
	*flag = ERROR;
	int aux;
	if (this != NULL && flag !=NULL){
		aux = this->valorKiloMaritimo;
		*flag = OK;
	}
	return aux;
}

int transporte_requestFactorConversion(float* factorConversion){
	int retorno = ERROR;
	if (!utn_getFloat("\n% FACTOR_CONVERSION:", "\nERROR-> FACTOR_CONVERSION", factorConversion, 3)){
		retorno = OK;
	}
	return retorno;
}

int transporte_requestValorContenedor(float* valorContenedor){
	int retorno = ERROR;
	if (!utn_getFloat("\n% VALOR_CONTENEDOR:", "\nERROR-> VALOR_CONTENEDOR", valorContenedor, 3)){
		retorno = OK;
	}
	return retorno;
}

int transporte_requestValorKiloAereo(float* valorKiloAereo){
	int retorno = ERROR;
	if (!utn_getFloat("\n% VALOR_KILO_AEREO:", "\nERROR-> VALOR_KILO_AEREO", valorKiloAereo, 3)){
		retorno = OK;
	}
	return retorno;
}

int transporte_requestValorKiloMaritimo(float* valorKiloMaritimo){
	int retorno = ERROR;
	if (!utn_getFloat("\n% VALOR_KILO_MARITIMO:", "\nERROR-> VALOR_KILO_MARITIMO", valorKiloMaritimo, 3)){
		retorno = OK;
	}
	return retorno;
}


