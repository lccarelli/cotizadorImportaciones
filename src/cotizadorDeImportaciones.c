/*
 ============================================================================
 Name        : cotizadorDeImportaciones.c
 Author      : lau
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "collections/LinkedList.h"
#include "controllers/controllerArticulo.h"
#include "controllers/controllerInformes.h"
#include "controllers/controllerPosicionArancelaria.h"
#include "controllers/controllerTransporte.h"
#include "entidades/Transporte.h"
#include "utils/utn.h"
#include "utils/Menu.h"


int main(void){
	int opcion=0;
	Dictionary* articulos;
	Dictionary* posicionArancelaria;
	Transporte transporte[TRANSPORTE];
	int idMax=-1;
	int idMaxPA = -1;

	transporte_init(transporte);
	articulos = dict_new(0);
	posicionArancelaria = dict_new(0);


	do{
		menu_principal(&opcion);
		switch(opcion){

			case AR_LEER_ARCHIVO:{
				controller_leerDeArchivo("articulos.csv", articulos, &idMax,transporte, posicionArancelaria);
				printf("\n idMax->%d", idMax);
				break;
			}
			case AR_ALTA:{
				controller_articuloAlta(articulos, &idMax, transporte, posicionArancelaria) == OK ?
						printf("\n Operacion exitosa") :
						printf("\n Hubo un error");
				break;
			}
			case AR_MODIF:{
				controller_modificarArticulo(articulos) == OK ?
						printf("\n Operacion exitosa") :
						printf("\n Hubo un error");
				break;
			}
			case AR_BAJA:{
				controller_borrarArticulo(articulos) == OK ?
						printf("\n Operacion exitosa") :
						printf("\n Hubo un error");
				break;
			}
			case AR_LISTAR:{
				controller_listarArticulos(articulos) == OK ?
						printf("\n Operacion exitosa") :
						printf("\n Hubo un error");
				break;
			}
			case AR_GUARAR:{
				controller_guardarEnArchivo("articulos_out.csv", articulos) == OK ?
						printf("\n Operacion exitosa") :
						printf("\n Hubo un error");
				break;
			}
			case PO_LEER_ARCHIVO:{
				controller_leerDeArchivoPosicion("posicion.csv", posicionArancelaria, &idMaxPA) == OK ?
						printf("\n Operacion exitosa") :
						printf("\n Hubo un error");
				break;
			}
			case PO_ALTA:{
				controller_posicionAlta(articulos, &idMaxPA) == OK ?
						printf("\n Operacion exitosa") :
						printf("\n Hubo un error");
				break;
			}
			case PO_MODIF:{
				controller_modificarPosicion(posicionArancelaria) == OK ?
						printf("\n Operacion exitosa") :
						printf("\n Hubo un error");
				break;
			}
			case PO_BAJA:{
				controller_borrarPosicion(posicionArancelaria) == OK ?
						printf("\n Operacion exitosa") :
						printf("\n Hubo un error");
				break;
			}
			case PO_LISTAR:{
				controller_listarPosiciones(posicionArancelaria) == OK ?
						printf("\n Operacion exitosa") :
						printf("\n Hubo un error");
				break;
			}
			case PO_GUARAR:{
				controller_guardarEnArchivoPosicion("posicion_out.csv",posicionArancelaria) == OK ?
						printf("\n Operacion exitosa") :
						printf("\n Hubo un error");
				break;
			}
			case TR_MODIFICAR:{
				controller_modificarTransporte(transporte) == OK ?
						printf("\n Operacion exitosa") :
						printf("\n Hubo un error");
				break;
			}
			case TR_LISTAR:{
				controller_listarTransporte(transporte) == OK ?
						printf("\n Operacion exitosa") :
						printf("\n Hubo un error");
				break;
			}
			case INFO_1:{
				informes_listarMaritimosMayor(articulos);
				break;
			}
			case INFO_2:{
				controller_ordenarPorCostoMaritimo(articulos);
				break;
			}
			case INFO_3:{
				//imprimirCostos(articulos);
				break;
			}
		}
	}while(opcion!=SALIR);

	return EXIT_SUCCESS;
}
