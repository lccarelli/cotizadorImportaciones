/*
 * controllerTransporte.c
 *
 *  Created on: 21 jun. 2021
 *      Author: lau
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../entidades/Transporte.h"
#include "../utils/Menu.h"

int controller_modificarTransporte(Transporte* trnsprt){
	int select;
	int retorno = ERROR;
	float factorConversion;
	float valorContenedor;
	float valorKiloAereo;
	float valorKiloMaritimo;

	if(trnsprt!=NULL){
		do{
			menu_modificarTransporte(&select);
			switch(select){

			case FACTOR_CONVERSION:
				if (
						transporte_requestFactorConversion(&factorConversion) == OK &&
						transporte_setFactorConversion(trnsprt, factorConversion) == OK
					){
						printf("\nModificacion exitosa.");
						retorno = OK;
					 }
				break;

			case VALOR_CONTENEDOR:
				if (
						transporte_requestValorContenedor(&valorContenedor) == OK &&
						transporte_setValorContenedor(trnsprt, valorContenedor) == OK
				){
						printf("\nModificacion exitosa");
						retorno = OK;
					}
				break;

			case VALOR_KILO_AEREO:
				if (
						transporte_requestValorKiloAereo(&valorKiloAereo) == OK &&
						transporte_setValorKiloAereo(trnsprt, valorKiloAereo) == OK
				){
						printf("\nModificacion exitosa");
						retorno = OK;
					}
				break;

			case VALOR_KILO_MARITIMO:
				if (
						transporte_requestValorKiloMaritimo(&valorKiloMaritimo) == OK &&
						transporte_setValorKiloMaritimo(trnsprt, valorKiloMaritimo) == OK
				){
						printf("\nModificacion exitosa");
						retorno = OK;
					}
				break;
			}
			retorno = OK;

		}while(!(select==SALIR));
	}
	return retorno;
}

int controller_listarTransporte(Transporte* trnspt){
	int flag = ERROR;
	if(trnspt!=NULL){
		printf("\n ID - FACTOR_CONVERSION - VALOR_CONTENEDOR - VALOR_KILO_AEREO - VALOR_KILO_MARITIMO");
		printf("\n %d ->\t%.2f -\t%.2f -\t%.2f -\t%.2f",
				transporte_getId(trnspt, &flag),
				transporte_getFactorConversion(trnspt, &flag),
				transporte_getValorContenedor(trnspt, &flag),
				transporte_getValorKiloAereo(trnspt, &flag),
				transporte_getValorKiloMaritimo(trnspt, &flag));
	}
	return flag;
}

float controller_calcularAereoPesoVolumentrico(Transporte* trnspt, float cm3){
	return (float)(((cm3)/trnspt->factorConversion)*trnspt->valorKiloAereo);
}

float controller_calcularAereoPesoReal(Transporte* trnspt, float peso){
	return (float)(peso*trnspt->valorKiloAereo);
}

float controller_calcularMaritimo(Transporte* trnspt, float cm3){
	return (float)((cm3/PASO_A_METRO_3)*(trnspt->valorContenedor/CONTENEDOR));
}



