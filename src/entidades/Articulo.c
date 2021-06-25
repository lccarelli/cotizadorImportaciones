/*
 * Articulo.c
 *
 *  Created on: 16 jun. 2021
 *      Author: lau
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../entidades/Articulo.h"
#include "../utils/utn.h"
#include "../collections/LinkedList.h"
#include "../utils/Menu.h"

Articulo* articulo_nuevo(void){
	return (Articulo*)malloc(sizeof(Articulo));
}

Articulo* articulo_nuevoConParametros(
										int id,
										char* codigo,
										char* descripcion,
										char* paisFabricacion,
										float alto,
										float largo,
										float profundidad,
										float peso,
										float valorFOB,
										char* nomenclatura,
										int idPosicionA

 ){
	Articulo* aux = articulo_nuevo();
	if( aux != NULL){
		if (
				articulo_setId(aux, id) < 0 ||
				articulo_setCodigo(aux, codigo) < 0 ||
				articulo_setDescripcion(aux, descripcion) < 0 ||
				articulo_setPaisFabricacion(aux, paisFabricacion) < 0 ||
				articulo_setMedidasAlto(aux, alto) < 0 ||
				articulo_setMedidasLargo(aux, largo) < 0 ||
				articulo_setMedidasProfundidad(aux, profundidad) < 0 ||
				articulo_setPeso(aux, peso) < 0 ||
				articulo_setValorFOB(aux, valorFOB) < 0 ||
				articulo_setNomenclatura(aux, nomenclatura) < 0 ||
				articulo_setPosicionArancelaria(aux, idPosicionA) < 0

		){
			printf("\n hubo un error en nuevo parametro");
			articulo_borrar(aux);
			aux = NULL;
		}
	}
	return aux;
}

int articulo_borrar(Articulo* this){
	int retorno = ERROR;
	if(this != NULL){
		free(this);
		retorno = OK;
	}
	return retorno;
}

int articulo_requestCodigo(char* codigo){
	int retorno = ERROR;
	if (!utn_getString("\nCODIGO?: ", "\nERROR-> CODIGO", codigo, TEXTO_LEN, 3))
		retorno = OK;
	return retorno;
}
int articulo_requestNomenclatura(char* nomenclatura){
	int retorno = ERROR;
	if (!utn_getString("\nNOMENCLATURA?: ", "\nERROR-> NOMENCLATURA", nomenclatura, TEXTO_LEN, 3))
		retorno = OK;
	return retorno;
}

int articulo_requestDescripcion(char* descripcion){
	int retorno = ERROR;
	if (!utn_getString("\nDESCRIPCION?: ", "\nERROR-> DESCRIPCION", descripcion, TEXTO_LEN, 3))
		retorno = OK;
	return retorno;
}

int articulo_requestPaisFabricacion(char* paisFabricacion){
	int retorno = ERROR;
	if (!utn_getString("\nPAIS_FABRICACION?: ", "\nERROR-> PAIS_FABRICACION", paisFabricacion, TEXTO_LEN, 3))
		retorno = OK;
	return retorno;
}

int articulo_requestMedidasAlto(float* alto){
	int retorno = ERROR;
	if (!utn_getFloat("\nMEDIDA->ALTO?:", "\nERROR-> MEDIDA.ALTO", alto, 3)){
		retorno = OK;
	}
	return retorno;
}

int articulo_requestMedidasLargo(float* largo){
	int retorno = ERROR;
	if (!utn_getFloat("\nMEDIDA->LARGO?:", "\nERROR-> MEDIDA.LARGO", largo, 3)){
		retorno = OK;
	}
	return retorno;
}

int articulo_requestMedidasProfundidad(float* profundidad){
	int retorno = ERROR;
	if (!utn_getFloat("\nMEDIDA->PROFUNDIDAD?:", "\nERROR-> MEDIDA.PROFUNDIDAD", profundidad, 3)){
		retorno = OK;
	}
	return retorno;
}

int articulo_requestPeso(float* peso){
	int retorno = ERROR;
	if (!utn_getFloat("\nPESO?:", "\nERROR-> PESO", peso, 3)){
		retorno = OK;
	}
	return retorno;
}

int articulo_requestValorFOB(float* valorFOB){
	int retorno = ERROR;
	if (!utn_getFloat("\nVALOR FOB?:", "\nERROR-> VALOR FOB", valorFOB, 3)){
		retorno = OK;
	}
	return retorno;
}

int articulo_requestPosicionArancelaria(int* idPosicion){
	int retorno = ERROR;
	if (!utn_getInt("\nPOSICION_ARANCELARIA?:", "\nERROR-> POSICION_ARANCELARIA", idPosicion, 3)){
		retorno = OK;
	}
	return retorno;
}

int articulo_setId(Articulo* this, int id){
	int retorno = ERROR;
	if(this !=NULL && id>=0){
		this->id = id;
		retorno = OK;
	}
	return retorno;
}

int articulo_setCodigo(Articulo* this, char* codigo){
	int retorno = ERROR;
	if(this != NULL && codigo !=NULL && utn_isAlphanumeric(codigo)){
		strcpy(this->codigo, codigo);
		retorno = OK;
	}
	return retorno;
}

int articulo_setNomenclatura(Articulo* this, char* nomenclatura){
	int retorno = ERROR;
	if(this != NULL && nomenclatura !=NULL){
		strcpy(this->nomenclatura, nomenclatura);
		retorno = OK;
	}
	return retorno;
}


int articulo_setDescripcion(Articulo* this, char* descripcion){
	int retorno = ERROR;
	if(this != NULL && descripcion !=NULL){
		strcpy(this->descripcion, descripcion);
		retorno = OK;
	}
	return retorno;
}

int articulo_setPaisFabricacion(Articulo* this, char* paisFabricacion){
	int retorno = ERROR;
	if(this != NULL && paisFabricacion !=NULL && utn_isAlphabetic(paisFabricacion)){
		strcpy(this->paisFabricacion, paisFabricacion);
		retorno = OK;
	}
	return retorno;
}

int articulo_setMedidasAlto(Articulo* this, float alto){
	int retorno = ERROR;
	if(this != NULL && alto > 0){
		this->medidas.alto = alto;
		retorno = OK;
	}
	return retorno;
}

int articulo_setMedidasLargo(Articulo* this, float largo){
	int retorno = ERROR;
	if(this != NULL && largo > 0){
		this->medidas.largo = largo;
		retorno = OK;
	}
	return retorno;
}

int articulo_setMedidasProfundidad(Articulo* this, float profundidad){
	int retorno = ERROR;
	if(this != NULL && profundidad > 0){
		this->medidas.profundidad = profundidad;
		retorno = OK;
	}
	return retorno;
}

int articulo_setPeso(Articulo* this, float peso){
	int retorno = ERROR;
	if(this != NULL && peso > 0){
		this->peso = peso;
		retorno = OK;
	}
	return retorno;
}

int articulo_setValorFOB(Articulo* this, float valorFOB){
	int retorno = ERROR;
	if(this != NULL && valorFOB  > 0){
		this->valorFOB = valorFOB;
		retorno = OK;
	}
	return retorno;
}

int articulo_setPosicionArancelaria(Articulo* this, int idPosicion){
	int retorno = ERROR;
	if(this !=NULL && idPosicion > 0){
		this->PosicionArancelaria = idPosicion;
		retorno = OK;
	}
	return retorno;
}

int articulo_setCM3(Articulo* this, float cm3){
	int retorno = ERROR;
	if(this != NULL && cm3 > 0){
		this->medidas.cm3 = cm3;
		retorno = OK;
	}
	return retorno;
}

int articulo_setCostoMaritimo(Articulo* this, float costoMaritimo){
	int retorno = ERROR;
	if(this != NULL && costoMaritimo > 0){
		this->costoMaritimo = costoMaritimo;
		retorno = OK;
	}
	return retorno;
}


int articulo_setCostoAereo(Articulo* this, float costoAereo){
	int retorno = ERROR;
	if(this != NULL && costoAereo > 0){
		this->costoAereo = costoAereo;
		retorno = OK;
	}
	return retorno;
}



int isPosicionArancelaria(int* id){
	return 1;
}

int articulo_getId(Articulo* this, int* flag){
	*flag = ERROR;
	int aux;
	if (this != NULL && flag !=NULL){
		aux = this->id;
		*flag = OK;
	}
	return aux;
}

char* articulo_getCodigo(Articulo* this, int* flag){
	*flag = ERROR;
	char* aux;
	if (this != NULL && flag !=NULL){
		aux = this->codigo;
		*flag = OK;
	}
	return aux;
}

char* articulo_getNomenclatura(Articulo* this, int* flag){
	*flag = ERROR;
	char* aux;
	if (this != NULL && flag !=NULL){
		aux = this->nomenclatura;
		*flag = OK;
	}
	return aux;
}
char* articulo_getDescripcion(Articulo* this, int* flag){
	*flag = ERROR;
	char* aux;
	if (this != NULL && flag !=NULL){
		aux = this->descripcion;
		*flag = OK;
	}
	return aux;
}

char* articulo_getPaisFabricacion(Articulo* this, int* flag){
	*flag = ERROR;
	char* aux;
	if (this != NULL && flag !=NULL){
		aux = this->paisFabricacion;
		*flag = OK;
	}
	return aux;
}

float articulo_getMedidaAlto(Articulo* this, int* flag){
	*flag = ERROR;
	float aux;
	if (this != NULL && flag !=NULL){
		aux = this->medidas.alto;
		*flag = OK;
	}
	return aux;
}

float articulo_getMedidaLargo(Articulo* this, int* flag){
	*flag = ERROR;
	float aux;
	if (this != NULL && flag !=NULL){
		aux = this->medidas.largo;
		*flag = OK;
	}
	return aux;
}

float articulo_getMedidaProfundidad(Articulo* this, int* flag){
	*flag = ERROR;
	float aux;
	if (this != NULL && flag !=NULL){
		aux = this->medidas.profundidad;
		*flag = OK;
	}
	return aux;
}

float articulo_getPeso(Articulo* this, int* flag){
	*flag = ERROR;
	float aux;
	if (this != NULL && flag !=NULL){
		aux = this->peso;
		*flag = OK;
	}
	return aux;
}

float articulo_getValorFOB(Articulo* this, int* flag){
	*flag = ERROR;
	float aux;
	if (this != NULL && flag !=NULL){
		aux = this->valorFOB;
		*flag = OK;
	}
	return aux;
}

int articulo_getPosicionArancelaria(Articulo* this, int* flag){
	*flag = ERROR;
	int aux;
	if (this != NULL && flag !=NULL){
		aux = this->PosicionArancelaria;
		*flag = OK;
	}
	return aux;
}

float articulo_getCM3(Articulo* this, int* flag){
	*flag = ERROR;
	float aux;
	if (this != NULL && flag !=NULL){
		aux = this->medidas.cm3;
		*flag = OK;
	}
	return aux;
}

float articulo_getCostoMaritimo(Articulo* this, int* flag){
	*flag = ERROR;
	float aux;
	if (this != NULL && flag !=NULL){
		aux = this->costoMaritimo;
		*flag = OK;
	}
	return aux;
}


float articulo_getCostoAereo(Articulo* this, int* flag){
	*flag = ERROR;
	float aux;
	if (this != NULL && flag !=NULL){
		aux = this->costoAereo;
		*flag = OK;
	}
	return aux;
}

static int contador=0; // NO ES LOCAL DE LA FUNCION

void articulo_setearValorInicialDeId(int id)
{
	contador = id;
}

int articulo_generarId(void){

	contador++;
	return contador;

}


