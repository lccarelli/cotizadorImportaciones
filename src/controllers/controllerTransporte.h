/*
 * controllerTransporte.h
 *
 *  Created on: 21 jun. 2021
 *      Author: lau
 */

#ifndef CONTROLLERS_CONTROLLERTRANSPORTE_H_
#define CONTROLLERS_CONTROLLERTRANSPORTE_H_
#include "../entidades/Transporte.h"
#define TRANSPORTE 1


int controller_modificarTransporte(Transporte* trnsprt);
int controller_listarTransporte(Transporte* trnspt);
float controller_calcularMaritimo(Transporte* trnspt, float cm3);

float controller_calcularAereoPesoVolumentrico(Transporte* trnspt, float cm3);
float controller_calcularAereoPesoReal(Transporte* trnspt, float peso);
float controller_calcularMaritimo(Transporte* trnspt, float cm3);

#endif /* CONTROLLERS_CONTROLLERTRANSPORTE_H_ */
