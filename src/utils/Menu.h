#ifndef MENU_H_
#define MENU_H_


/*-------------SECCION-ARTICULO-------------*/
#define AR_LEER_ARCHIVO	1
#define AR_ALTA			2
#define AR_MODIF		3
#define AR_BAJA			4
#define AR_LISTAR		5
#define AR_GUARAR		6
/*-------------SECCION-POSICION-ARANCELARIA-------------*/
#define PO_LEER_ARCHIVO	7
#define PO_ALTA			8
#define PO_MODIF		9
#define PO_BAJA			10
#define PO_LISTAR		11
#define PO_GUARAR		12
/*-------------SECCION-TRANSPORTES-------------*/
#define TR_MODIFICAR	13
#define TR_LISTAR		14
/*-------------SECCION-INFORMES-------------*/
#define INFO_1			15
#define INFO_2			16
#define INFO_3			17
#define SALIR		0
/*-------------MENU-MODIFICAR-ARTICULO---------------*/
#define CODIGO 1
#define DESCRIPCION 2
#define PAIS_FABRICACION 3
#define MEDIDA_ALTO 4
#define MEDIDA_LARGO 5
#define MEDIDA_PROFUNDO 6
#define VALOR_FOB 7
#define POSICION_ARANCELARIA 8
/*-------------MENU-MODIFICAR-POSICION---------------*/
#define DESCRIPCION_PO 1
#define SEGURO 2
#define IMPORTACION 3
#define TASA_ESTADISTICA 4
#define LICENCIA 5
/*-------------MENU-MODIFICAR-TRANSPORTE---------------*/
#define FACTOR_CONVERSION	1
#define VALOR_CONTENEDOR 	2
#define VALOR_KILO_AEREO	3
#define VALOR_KILO_MARITIMO	4

void menu_principal(int* select);
void menu_modificarArticulo(int* select);
void menu_modificarPosicion(int* select);
void menu_modificarTransporte(int* select);
#endif /* MENU_H_ */
