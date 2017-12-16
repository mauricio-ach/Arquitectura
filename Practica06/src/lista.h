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
* @file lista.h
* @author Mauricio Araujo
* @date 2 Nov 2017
* @brief Contiene las funciones principales de una lista
*/

/**
* @brief estructura nodo
* Implementacion de una estructura tipo nodo
*/
typedef struct nodolista
{
    char *elemento;
    struct nodolista *siguiente;
} *nodo;

/**
* @brief estructura lista
* Implementacion de una estructura tipo lista utilizando nodos
*/
typedef struct li
{
    nodo inicio;
    nodo fin;
    int tamano;
} *lista;

/**
* @brief crea una lista
* @return una lista con memoria reservada.
*/
lista inicializa(void);

/**
* @brief agrega un elemento al inicio de la lista
* @param el elemento a añadir
* @param la lista en donde sera agregado
*/
void agrega_inicio(char *elemento, lista l);

/**
* @brief agrega un elemento al final de la lista
* @param el elemento a añadir
* @param la lista en donde sera agregado
*/
void agrega_fin(char *elemento, lista l);

/**
* @brief elimina un elemento al inicio de la lista
* @param la lista en donde sera eliminado
* @return el elemento que fue eliminado
*/
char* elimina_inicio(lista l);


/**
 * @brief crea un nodo con el elemento indicado
 * @param el elemento del nodo
 * @return el nodo creado
 */
nodo crea_nodo(char *elemento);