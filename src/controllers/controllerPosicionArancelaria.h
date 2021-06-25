/*
 *  Created on: 19 jun. 2021
 *      Author: lau
 */

#ifndef CONTROLLERS_CONTROLLERPOSICIONARANCELARIA_H_
#define CONTROLLERS_CONTROLLERPOSICIONARANCELARIA_H_
#include "../entidades/PosicionArancelaria.h"
#include "../entidades/Transporte.h"
#include "../collections/Dictionary.h"

/*------------------------------ABM-------------------------------------*/
int controller_posicionAlta(Dictionary* posicionArancelaria, int* idMaxPA);
int controller_borrarPosicion(Dictionary* posicionArancelaria);
int controller_modificarPosicion(Dictionary* posicionArancelaria);

/*------------------------------IMPRIMIR-------------------------------------*/
int controller_listarPosicion(PosicionArancelaria* pPA);
int controller_listarPosiciones(Dictionary* posicionArancelaria);

/*------------------------------ARCHIVOS-------------------------------------*/
int controller_leerDeArchivoPosicion(char* archivo, Dictionary* posicionArancelaria, int* idMaxPA);
int controller_guardarEnArchivoPosicion(char* archivo, Dictionary* posicionArancelaria);

PosicionArancelaria* devolver_posicionArancelaria(Dictionary* this, char* idCadena);
float calcularSeguro(float seguro,float valorFOB);
float calcularBaseImponible(float valorFOB, float dato, Transporte* trnspt, PosicionArancelaria* pPA, float(*funcionTransporte)(Transporte*,float));
float calcularImpuesto(float baseImponible, float impuesto);
float costoTotal(PosicionArancelaria* pPA, float baseImponible, float (*funcionImpuesto)(float,float));
#endif /* CONTROLLERS_CONTROLLERPOSICIONARANCELARIA_H_ */
