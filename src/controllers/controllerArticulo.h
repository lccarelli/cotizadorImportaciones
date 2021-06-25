/*
 * cotrollerArticulo.h
 *
 *  Created on: 19 jun. 2021
 *      Author: lau
 */

#ifndef CONTROLLERS_CONTROLLERARTICULO_H_
#define CONTROLLERS_CONTROLLERARTICULO_H_
#include "../entidades/Articulo.h"
#include "../entidades/Transporte.h"
#include "../collections/Dictionary.h"
#include "../entidades/PosicionArancelaria.h"

/*------------------------------ABM-------------------------------------*/
int controller_articuloAlta(Dictionary* articulos, int* idMax, Transporte* trnspt, Dictionary* pscn);
int controller_borrarArticulo(Dictionary* articulos);
int controller_modificarArticulo(Dictionary* articulos);

/*------------------------------IMPRIMIR-------------------------------------*/
int controller_listarArticulo(Articulo* pA);
int controller_listarArticulos(Dictionary* articulos);

/*------------------------------ARCHIVOS-------------------------------------*/
int controller_leerDeArchivo(char* archivo, Dictionary* articulos, int* idMaxA, Transporte* trnspt, Dictionary* pscn);
int controller_guardarEnArchivo(char* archivo, Dictionary* articulos);

/*------------------------------Calculos-------------------------------------*/
float controller_calcularCM3Articulo(float alto, float largo, float profundidad);
void controller_calcularTransporte(Transporte*trnspt, Articulo* pA, PosicionArancelaria* pPA);
int controller_ordenarPorCostoMaritimo(Dictionary* articulos);
int sortCostoMaritimo(LinkedList* list);
int imprimirCostos(LinkedList* list);
#endif /* CONTROLLERS_CONTROLLERARTICULO_H_ */
