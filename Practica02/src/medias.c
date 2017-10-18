/*
* Programa para calcular las media 
* aritmetica, armonica o geometrica
* de un número n de datos.
*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
/*
* Funcion auxiliar para sumar elementos
*/
float suma_deltas(float datos[], int n)
{
	float suma = 0.0;
	int i;
	for(i = 0; i < n; i++)
		suma = suma + datos[i];
	return suma;
}

/*
* Funcion auxiliar para multiplicar elementos
*/
float multiplica_deltas(float datos[], int n)
{
	float resultado = 1.0;
	int i;
	for(i = 0; i < n; i++)
		resultado = resultado * datos[i];
	return resultado;
}

/*
* Función auxiliara para validar entrada
*/
int valida_entrada(char c)
{
	if(c == 'A' || c == 'H' || c == 'G')
		return 1;
	else 
		return 0;
}

/*
* Función para calcular la media aritmetica de 
* un número n de datos.
* Recibe un arreglo con los datos a calcular y el numero n
* de datos.
* return un número de coma flotante para el resultado.
*/
float media_aritmetica(float datos[], int n)
{
	float suma = suma_deltas(datos, n);
	return ((1.0 / (float)n) * (suma));
}

/*
* Función para calcular la media armonica de 
* un número n de datos.
* Recibe un arreglo con los datos a calcular y el numero n
* de datos.
* return un número de coma flotante para el resultado.
*/
float media_armonica(float datos[], int n)
{
	float suma = suma_deltas(datos, n);
	return ((n) / (1.0 / (suma)));
}

/*
* Función para calcular la media geometrica de 
* un número n de datos.
* Recibe un arreglo con los datos a calcular y el numero n
* de datos.
* return un número de coma flotante para el resultado.
*/
float media_geometrica(float datos[], int n)
{
	float resultado = multiplica_deltas(datos, n);
	return pow(resultado, (1.0/n));
}

/*
* Funcion para imprimir arreglo
*/
void imprime(float datos[], int n)
{
	int i;
	for(i = 0; i < n; i++)
		printf("%.3f\n", datos[i]);
}

int main(int argc, char const *argv[])
{

	//Declaramos variables 
	int elementos = argc - 2; //número de elementos a calcular
	float media; //Guardamos la media requerida por el usuario
	float datos[elementos];

	//Rellenamos el nuevo arreglo solo con los numeros
	int i;
	for(i = 2; i < argc; i++)
	{
		datos[i - 2] = atof(argv[i]);
	}

	if(valida_entrada(*argv[1]) == 1){ //Validamos entrada
		//Caso Aritmetica
		if (*argv[1] == 'A')
		{
			media = media_aritmetica(datos, elementos);
			printf("Media Aritmetica %.3f\n", media);
			printf("Datos:\n");
			imprime(datos, elementos);
		}
		//Caso Armonica
		if (*argv[1] == 'H')
		{
			media = media_armonica(datos, elementos);
			printf("Media Armonica %.3f\n", media);
			printf("Datos:\n");
			imprime(datos, elementos);
		}
		//Caso Geometrica
		if (*argv[1] == 'G')
		{
			media = media_geometrica(datos, elementos);
			printf("Media Geometrica %.3f\n", media);
			printf("Datos:\n");
			imprime(datos, elementos);
		} 
	} else { //Entrada invalida
		printf("Entrada invalida!\n");
		return 1;
	}
	
	return 0;
}