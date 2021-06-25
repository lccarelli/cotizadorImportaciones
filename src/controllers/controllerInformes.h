/*
 * controllers_Informes.h
 *
 *  Created on: 22 jun. 2021
 *      Author: lau
 */

#ifndef CONTROLLERS_CONTROLLERINFORMES_H_
#define CONTROLLERS_CONTROLLERINFORMES_H_

LinkedList* ll_filtrar(LinkedList* this,int (*funcionCriterio)(void*));
void informes_listarMaritimosMayor(Dictionary* articulos);
#endif /* CONTROLLERS_CONTROLLERINFORMES_H_ */
