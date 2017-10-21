/*
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


/*
* @file sumador-restador.c
* @author Mauricio Araujo
* @date 20 Oct 2017
* @brief simulador de un ALU de 32 bits
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
* @brief operacion AND de 32 bits
* @param primera cadena de 32 bits
* @param segunda cadena de 32 bits
* @return una cadena de 32 bits con el resultado de la operacion
*/
char* obten_AND(char *opA, char *opB)
{	
	char* resultado = (char*)malloc(32*sizeof(char));
	int i;
	for(i = 0; i < strlen(opA); i++)
	{
		if(opA[i] == '1' && opB[i] == '1')
		{
			resultado[i] = '1';
		} else
		{
			resultado[i] = '0';
		}
	}
	return resultado;
}

/*
* @brief operacion OR de 32 bits
* @param primera cadena de 32 bits
* @param segunda cadena de 32 bits
* @return una cadena de 32 bits con el resultado de la operacion
*/
char* obten_OR(char *opA, char *opB)
{	
	char* resultado = (char*)malloc(32*sizeof(char));
	int i;
	for(i = 0; i < strlen(opA); i++)
	{
		if(opA[i] == '0' && opB[i] == '0')
		{
			resultado[i] = '0';
		} else
		{
			resultado[i] = '1';
		}
	}
	return resultado;
}

/*
* @brief operacion suma de 32 bits
* @param primera cadena de 32 bits
* @param segunda cadena de 32 bits
* @return una cadena de 32 bits con el resultado de la operacion
*/
char* obten_Adicion(char *opA, char *opB)
{
	char* resultado = (char*)malloc(32*sizeof(char));
	int i;
	int acarreo = 0;
	for (i = 32; i >= 0; i--)
	{	
		if(acarreo == 0){
			if(opA[i] == '0' && opB[i] == '0')
			{
				resultado[i] = '0';
			} else if(opA[i] == '1' && opB[i] == '0')
			{
				resultado[i] = '1';
			} else if(opA[i] == '0' && opB[i] == '1')
			{
				resultado[i] = '1';
			} else if(opA[i] == '1' && opB[i] == '1')
			{
				resultado[i] = '0';
				acarreo = 1;
			}
		} else {
			if(opA[i] == '0' && opB[i] == '0')
			{
				resultado[i] = '1';
			} else if(opA[i] == '1' && opB[i] == '0')
			{
				resultado[i] = '1';
			} else if(opA[i] == '0' && opB[i] == '1')
			{
				resultado[i] = '1';
			} else if(opA[i] == '1' && opB[i] == '1')
			{
				resultado[i] = '1';
				acarreo = 0;
			}
		}
	}
	return resultado;
}

/*
* @brief operacion resta de 32 bits
* @param primera cadena de 32 bits
* @param segunda cadena de 32 bits
* @return una cadena de 32 bits con el resultado de la operacion
*/
char* obten_Sustraccion(char *opA, char *opB)
{
	char* resultado = (char*)malloc(32*sizeof(char));
	int acarreo = 0;
	int i;
	for (i = 32; i >= 0; i--)
	{
		if(acarreo == 0)
		{
			if(opA[i] == '0' && opB[i] == '0')
			{
				resultado[i] = '0';
			} else if(opA[i] == '1' && opB[i] == '0')
			{
				resultado[i] = '1';
			} else if(opA[i] == '1' && opB[i] == '1')
			{
				resultado[i] = '0';
			} else if(opA[i] == '0' && opB[i] == '1')
			{
				resultado[i] = '1';
				acarreo = '1';
			}
		} else 
		{
			if(opA[i] == '0' && opB[i] == '0')
			{
				resultado[i] = '1';
			} else if(opA[i] == '1' && opB[i] == '0')
			{
				resultado[i] = '0';
				acarreo = 0;
			} else if(opA[i] == '1' && opB[i] == '1')
			{
				resultado[i] = '1';
			} else if(opA[i] == '0' && opB[i] == '1')
			{
				resultado[i] = '0';
				acarreo = '0';
			}
		}
	}
}

/*
* @brief operacion igualdad de 32 bits
* @param primera cadena de 32 bits
* @param segunda cadena de 32 bits
* @return una cadena de 32 bits con el resultado de la operacion
*/
char* obten_Igualdad(char *opA, char *opB)
{
	int igual = 1;
	int i;
	for(i = 0; i < 32; i++)
	{
		if(opA[i] != opB[i])
		{
			igual = 0;
			break;
		}
	}	
	if(igual == 0)
		return "00000000000000000000000000000000";
	else
		return "00000000000000000000000000000001";
}

/*
* @brief operacion menor que de 32 bits
* @param primera cadena de 32 bits
* @param segunda cadena de 32 bits
* @return una cadena de 32 bits con el resultado de la operacion
*/
char* obten_Menorque(char *opA, char *opB)
{
	int menor = 1;
	int i;
	for(i = 0; i < 32; i++)
	{
		if(opA[i] > opB[i])
		{
			menor = 0;
			break;
		}
	}
	if(menor == 0)
		return "00000000000000000000000000000000";
	else
		return "00000000000000000000000000000001";
}

/*
* @brief funcion para seleccionar y ejecutar la operacion requerida
* @param una cadena con la opcion de la operacion
* @param primera cadena de 32 bits
* @param segunda cadena de 32 bits
* @return una cadena de 32 bits con el resultado de la operacion
*/
char* ejecuta_opcion(char *opcion, char *opA, char *opB)
{
	if(strcmp(opcion,"000") == 0)
	{
		printf("%s\n", obten_AND(opA, opB));
	} else if(strcmp(opcion, "001") == 0)
	{
		printf("%s\n", obten_OR(opA, opB));
	} else if(strcmp(opcion, "010") == 0)
	{
		printf("%s\n", obten_Adicion(opA, opB));
	} else if(strcmp(opcion, "011") == 0)
	{
		printf("%s\n", obten_Sustraccion(opA, opB));
	} else if(strcmp(opcion, "100") == 0)
	{
		printf("%s\n", obten_Igualdad(opA, opB));
	} else if(strcmp(opcion, "101") == 0)
	{
		printf("%s\n", obten_Menorque(opA, opB));
	}
}

/*
* @brief funcion principal 
* Funcion principal que simula una ALU de 32 bits
*/
int main(int argc, char const *argv[])
{	
	char numero1[32];
	char numero2[32];
	char opcion[3];

	strcpy(opcion, argv[1]);
	strcpy(numero1, argv[2]);
	strcpy(numero2, argv[3]);

	ejecuta_opcion(opcion, numero1, numero2);

	return 0;
}

