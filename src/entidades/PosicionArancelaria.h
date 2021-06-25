/*
 * PosicionArancelaria.h
 *
 *  Created on: 19 jun. 2021
 *      Author: lau
 */

#ifndef POSICIONARANCELARIA_H_
#define POSICIONARANCELARIA_H_
#define ERROR -1
#define OK 0
#define DESCRIPCION_LEN 101


typedef struct{
	int id;
	char descripcion[DESCRIPCION_LEN];
	float seguro;
	float importacion;
	float tasaEstadistica;
	int licencia;
}PosicionArancelaria;


/*---------------------------------------------------*/
/*CONSTRUCTORES*/
PosicionArancelaria* posicion_nuevo(void);
PosicionArancelaria* posicion_nuevoConParametros(
										int id,
										char* descripcion,
										float seguro,
										float importacion,
										float tasaEstadistica,
										int licencia);

/*---------------------------------------------------*/
/*DESTRUCTORES*/
int posicion_borrar(PosicionArancelaria* this);

/*--------------------------------------------------*/
/*REQUEST DATA*/
int posicion_requestDescripcion(char* descripcion);
int posicion_requestSeguro(float* seguro);
int posicion_requestImportacion(float* importacion);
int posicion_requestTasaEstadistica(float* tasaEstadistica);
int posicion_requestLicencia(int* licencia);

/*--------------------------------------------------*/
/*SETTERS*/
int posicion_setId(PosicionArancelaria* this, int id);
int posicion_setDescripcion(PosicionArancelaria* this, char* descripcion);
int posicion_setSeguro(PosicionArancelaria* this, float seguro);
int posicion_setImportacion(PosicionArancelaria* this, float importacion);
int posicion_setTasaEstadistica(PosicionArancelaria* this, float tasaEstadistica);
int posicion_setLicencia(PosicionArancelaria* this, int licencia);

/*--------------------------------------------------*/
/*GETTERS*/
int posicion_getId(PosicionArancelaria* this, int* flag);
char* posicion_getDescripcion(PosicionArancelaria* this, int* flag);
float posicion_getSeguro(PosicionArancelaria* this, int* flag);
float posicion_getImportacion(PosicionArancelaria* this, int* flag);
float posicion_getTasaEstadistica(PosicionArancelaria* this, int* flag);
int posicion_getLicencia(PosicionArancelaria* this, int* flag);


void posicion_setearValorInicialDeId(int id);
int posicion_generarId(void);

#endif /* POSICIONARANCELARIA_H_ */
