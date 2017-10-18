#include <stdio.h>
#include <string.h>

char resultado[33];

char *obten_AND(char *opA, char *opB)
{
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
	resultado[32] = '\0';
	return resultado;
}


char *obten_OR(char *opA, char *opB)
{
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
	resultado[33] = '\0';
	return resultado;

}
/*
char** obten_Adicion(char** opA, char** opB);

char** obten_Sustraccion(char** opA, char** opB);

char** obten_Igualdad(char** opA, char** opB);

char** obten_Menorque(char** opA, char** opB);
*/

int main(int argc, char const *argv[])
{	

	return 0;
}

