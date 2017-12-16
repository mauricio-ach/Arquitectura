/**
  Copyright (C)  2017 by Mauricio Araujo 

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


/**
* @file lista.c
* @author Mauricio Araujo
* @date 2 Nov 2017
* @brief Programa que implementa un TDA lista
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lista.h"

/**
* @brief crea una lista
* @return una lista con memoria reservada.
*/
lista inicializa(void)
{
	lista l = malloc(sizeof(lista));
	l -> inicio = NULL;
	l -> fin = NULL;
	l -> tamano = 0;
	return l;
}

/**
 * @brief crea un nodo con el elemento indicado
 * @param el elemento del nodo
 * @return el nodo creado
 */
nodo crea_nodo(char *e)
{
	nodo n = malloc(sizeof(nodo));
	n -> elemento = malloc(strlen(e) + 1);
	strcpy(n -> elemento, e);
	return n;
}

/**
* @brief agrega un elemento al inicio de la lista
* @param el elemento a añadir
* @param la lista en donde sera agregado
*/
void agrega_inicio(char *elemento, lista l)
{
	nodo n = crea_nodo(elemento);
	if(l -> tamano == 0)
	{
		l -> inicio = n;
		l -> fin = n;
	} else
	{
		n -> siguiente = l -> inicio;
		l -> inicio = n;
	}
	l -> tamano = l -> tamano + 1;
}

/**
* @brief agrega un elemento al final de la lista
* @param el elemento a añadir
* @param la lista en donde sera agregado
*/
void agrega_fin(char *elemento, lista l)
{
	nodo n = crea_nodo(elemento);
	if(l -> tamano == 0)
	{
		l -> inicio = n;
		l -> fin = n;
	} else 
	{
		n -> siguiente = NULL;
		l -> fin -> siguiente = n;
		l -> fin = n;
	}
	l -> tamano = l -> tamano + 1;
}

/**
* @brief elimina un elemento al inicio de la lista
* @param la lista en donde sera eliminado
* @return el elemento que fue eliminado
*/
char* elimina_inicio(lista l)
{
	if(l -> tamano == 0)
		return NULL;
	char *c = l -> inicio -> elemento;
	nodo n = l -> inicio;
	if(l -> tamano == 1)
	{
		l -> inicio = NULL;
		l -> fin = NULL;
		l -> tamano = 0;
	} else
	{
		l -> inicio = n -> siguiente;
		l -> tamano = l -> tamano - 1;		
	}
	free(n);
	return c;	
}