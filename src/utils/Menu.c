#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "Menu.h"
#include "../utils/utn.h"


void menu_principal(int* select){

	printf("\nMENU PRINCIPAL:"
			"\n\t****SECCION ARTICULO****"
			"\n\t1).CARGAR ARCHIVO"
			"\n\t2).ALTA"
			"\n\t3).MODIFICAR"
			"\n\t4).BORRAR"
			"\n\t5).LISTAR"
			"\n\t6).GUARDAR ARCHIVO\n"
			"\n\t****SECCION POSICION ARANCELARIA****"
			"\n\t7).CARGAR ARCHIVO"
			"\n\t8).ALTA"
			"\n\t9).MODIFICAR"
			"\n\t10).BORRAR"
			"\n\t11).LISTAR"
			"\n\t12).GUARDAR ARCHIVO\n"
			"\n\t****SECCION TRANSPORTE****"
			"\n\t13).MODIFICAR"
			"\n\t14).LISTAR\n"
			"\n\t****SECCION INFORMES****"
			"\n\t15).FILTRO-> MARITIMO > 5"
			"\n\t16).ORDENAR-> x COSTO_MARITIMO"
			"\n\t17).LISTA CON COSTO"
			"\n\n\t0).salir\n");
	utn_getInt("\nIngrese su seleccion -> ", "\nERROR", select, 3);
}

void menu_modificarArticulo(int* select){

	printf("\nMenu para modificar Articulo:"
			"\n\t1). CODIGO"
			"\n\t2). DESCRIPCION"
			"\n\t3). PAIS_FABRICACION"
			"\n\t4). MEDIDAS_ ALTO"
			"\n\t5). MEDIDAS_ LARGO"
			"\n\t6). MEDIDAS_ PROFUNDIDAD"
			"\n\t7). VALOR_FOB"
			"\n\t8). ID_POSICION"
			"\n\t0). salir\n");
	utn_getInt("\nIngrese su seleccion -> ", "\nERROR", select, 3);
}

void menu_modificarPosicion(int* select){

	printf("\nMenu para modificar Posicion:"
			"\n\t1). DESCRIPCION"
			"\n\t2). SEGURO"
			"\n\t3). IMPORTACION"
			"\n\t4). TASA_ESTADISTICA"
			"\n\t5). LICENCIA (AUTOMATICA-> 1 || NO-AUTOMATICA-> 0"
			"\n\t0). salir\n");
	utn_getInt("\nIngrese su seleccion -> ", "\nERROR", select, 3);
}

void menu_modificarTransporte(int* select){

	printf("\nMenu para modificar Posicion:"
			"\n\t1). FACTOR_CONVERSION"
			"\n\t2). VALOR_CONTENEDOR"
			"\n\t3). VALOR_KILO_AEREO"
			"\n\t4). VALOR_KILO_MARITIMO"
			"\n\t0). salir\n");
	utn_getInt("\nIngrese su seleccion -> ", "\nERROR", select, 3);
}
