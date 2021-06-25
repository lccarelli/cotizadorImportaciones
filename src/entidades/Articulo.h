/*
 * Articulo.h
 *
 *  Created on: 16 jun. 2021
 *      Author: lau
 */

#ifndef ARTICULO_H_
#define ARTICULO_H_
#define TEXTO_LEN 71
#define ERROR -1
#define OK 0

typedef struct{
	float alto;
	float largo;
	float profundidad;
	float cm3;
}Medida;

typedef struct{
	int id;
	char codigo[TEXTO_LEN];
	char descripcion[TEXTO_LEN];
	char paisFabricacion[TEXTO_LEN];
	Medida medidas;
	float peso;
	float valorFOB;
	char nomenclatura[TEXTO_LEN];
	int PosicionArancelaria;
	float costoMaritimo;
	float costoAereo;
}Articulo;

/*---------------------------------------------------*/
/*CONSTRUCTORES*/
Articulo* articulo_nuevo(void);
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
										int idPosicion);

/*---------------------------------------------------*/
/*DESTRUCTORES*/
int articulo_borrar(Articulo* this);

/*---------------------------------------------------*/
/*REQUEST DATA*/
int articulo_requestCodigo(char* codigo);
int articulo_requestDescripcion(char* descripcion);
int articulo_requestNomenclatura(char* nomenclatura);
int articulo_requestPaisFabricacion(char* paisFabricacion);
int articulo_requestMedidasAlto(float* alto);
int articulo_requestMedidasLargo(float* largo);
int articulo_requestMedidasProfundidad(float* profundidad);
int articulo_requestPeso(float* peso);
int articulo_requestValorFOB(float* valorFOB);
int articulo_requestPosicionArancelaria(int* idPosicion);

/*---------------------------------------------------*/
/*SETTERS*/
int articulo_setId(Articulo* this, int id);
int articulo_setCodigo(Articulo* this, char* codigo);
int articulo_setDescripcion(Articulo* this, char* descripcion);
int articulo_setNomenclatura(Articulo* this, char* nomenclatura);
int articulo_setPaisFabricacion(Articulo* this, char* paisFabricacion);
int articulo_setMedidasAlto(Articulo* this, float alto);
int articulo_setMedidasLargo(Articulo* this, float largo);
int articulo_setMedidasProfundidad(Articulo* this, float profundidad);
int articulo_setPeso(Articulo* this, float peso);
int articulo_setValorFOB(Articulo* this, float valorFOB);
int articulo_setPosicionArancelaria(Articulo* this, int idPosicion);
int articulo_setCM3(Articulo* this, float cm3);
int articulo_setCostoMaritimo(Articulo* this, float costoMaritimo);
int articulo_setCostoAereo(Articulo* this, float costoAereo);

/*---------------------------------------------------*/
/*GETTERS*/
int articulo_getId(Articulo* this, int* flag);
char* articulo_getCodigo(Articulo* this, int* flag);
char* articulo_getDescripcion(Articulo* this, int* flag);
char* articulo_getPaisFabricacion(Articulo* this, int* flag);
char* articulo_getNomenclatura(Articulo* this, int* flag);
float articulo_getMedidaAlto(Articulo* this, int* flag);
float articulo_getMedidaLargo(Articulo* this, int* flag);
float articulo_getMedidaProfundidad(Articulo* this, int* flag);
float articulo_getPeso(Articulo* this, int* flag);
float articulo_getValorFOB(Articulo* this, int* flag);
int articulo_getPosicionArancelaria(Articulo* this, int* flag);
float articulo_getCM3(Articulo* this, int* flag);
float articulo_getCostoMaritimo(Articulo* this, int* flag);
float articulo_getCostoAereo(Articulo* this, int* flag);
/*---------------------------------------------------*/
/*SETEO ID*/
void articulo_setearValorInicialDeId(int id);
int articulo_generarId(void);


#endif /* ARTICULO_H_ */
