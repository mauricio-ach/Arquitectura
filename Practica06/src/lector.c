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
* @file lector.c
* @author Mauricio Araujo
* @date 2 Nov 2017
* @brief Programa que lee un archivo y lo escribe en otro usando listas
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lista.h"

int main(int argc, char const *argv[])
{
	FILE *archivo_entrada;
	FILE *archivo_salida;
	lista lista_palabras = inicializa();
	char *palabra = (char*)malloc(sizeof(char));
	/*Procedemos a abrir archivo*/
	archivo_entrada = fopen("doc/entrada.txt", "r");

	if(!archivo_entrada)
	{
		printf("Error al abrir archivo ! \n");
		exit(1);
	}

	/*Procesamos palabras a lista*/
	fscanf(archivo_entrada,"%s", &palabra);
	if(*palabra == EOF)
	{
		printf("Nada por leer !\n");
		exit(0);
	} else {
		agrega_inicio(palabra, lista_palabras);
		while(!feof(archivo_entrada))
		{
		fscanf(archivo_entrada, "%s", &palabra);
		agrega_fin(palabra, lista_palabras);
		}
	}

	/*Cerramos archivo*/
	fclose(archivo_entrada);

	/*Procedemos a escribir archivo*/
	archivo_salida = fopen("doc/salida.txt", "w");

	if(!archivo_salida)
	{
		printf("Error al crear archivo !\n");
		exit(1);
	}
	
	/*Procesamos palabras a texto*/
	while(lista_palabras -> tamano != 0)
	{
		palabra = elimina_inicio(lista_palabras);
		fputs(palabra, archivo_salida);
	}

	/*Procedemos a cerrar archivo*/
	fclose(archivo_salida);

	return 0;
}