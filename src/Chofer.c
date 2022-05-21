#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Chofer.h"


int eChofer_hardcodear(eChofer array[], int len, int* id)
{
	int retorno = -1;
	int i;
	int cant;

	eChofer auxArray[] =
	{
		{0, "Julieta", 'F'},
		{0, "Ricardo", 'M'},
		{0, "Julio", 'M'},
		{0, "Tamara", 'F'}
	};

	if(array != NULL && len > 0 && id != NULL)
	{
		cant = sizeof(auxArray) / sizeof(eChofer);

		if(cant <= len)
		{
			for(i = 0; i < cant; i++)
			{
				array[i] = auxArray[i];
				array[i].id = *id;

				(*id)++;
			}

			retorno = 0;
		}
	}

	return retorno;
}

int eChofer_encontrarPorId(eChofer array[], int len, int id, int* indice)
{
	int retorno = -1;
	int i;

	if(array != NULL && len > 0 && id > 0 && indice != NULL)
	{
		for(i = 0; i < len; i++)
		{
			if(array[i].id == id)
			{
				*indice = i;
				retorno = 0;
				break;
			}
		}
	}

	return retorno;
}

int eChofer_mostrarUnChofer(eChofer* unChofer)
{
	int retorno = -1;

	if(unChofer != NULL)
	{
		printf("|%-10d|%-20s|%-4c|\n", unChofer->id, unChofer->nombre, unChofer->sexo);

		retorno = 0;
	}

	return retorno;
}

int eChofer_mostrarLista(eChofer array[], int len)
{
	int retorno = -1;
	int i;

	if(array != NULL && len > 0)
	{
		printf("\n");
		system("pause");
		system("cls");

		printf("\tLISTA DE CHOFERES\n\n");
		printf("*----------*--------------------*----*\n");
		printf("|%-10s|%-20s|%-4s|\n", "ID", "NOMBRE", "SEXO");
		printf("*----------*--------------------*----*\n");

		for(i = 0; i < len; i++)
		{
			if(eChofer_mostrarUnChofer(&array[i]))
			{
				break;
			}
		}

		printf("*----------*--------------------*----*\n");

		if(i == len)
		{
			retorno = 0;
		}
	}

	return retorno;
}
