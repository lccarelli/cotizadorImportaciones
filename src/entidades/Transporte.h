/*
 * Transporte.h
 *
 *  Created on: 19 jun. 2021
 *      Author: lau
 */

#ifndef TRANSPORTE_H_
#define TRANSPORTE_H_
#define TRANSPORTE 1
#define ERROR -1
#define OK 0
#define CONTENEDOR 65
#define PASO_A_METRO_3 1000000

typedef struct{
	int id;
	float factorConversion;
	float valorContenedor;
	float valorKiloAereo;
	float valorKiloMaritimo;
}Transporte;


void transporte_init(Transporte* this);
int transporte_setFactorConversion(Transporte* this, float factorConversion);
int transporte_setValorContenedor(Transporte* this, float valorContenedor);
int transporte_setValorKiloAereo(Transporte* this, float valorKiloAereo);
int transporte_setValorKiloMaritimo(Transporte* this, float valorKiloMaritimo);

int transporte_getId(Transporte* this, int* flag);
float transporte_getFactorConversion(Transporte* this, int* flag);
float transporte_getValorContenedor(Transporte* this, int* flag);
float transporte_getValorKiloAereo(Transporte* this, int* flag);
float transporte_getValorKiloMaritimo(Transporte* this, int* flag);
int transporte_requestFactorConversion(float* factorConversion);
int transporte_requestValorContenedor(float* valorContenedor);
int transporte_requestValorKiloAereo(float* valorKiloAereo);
int transporte_requestValorKiloMaritimo(float* valorKiloMaritimo);




#endif /* TRANSPORTE_H_ */
