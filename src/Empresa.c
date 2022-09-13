#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Empresa.h"


int eEmpresa_hardcodear(eEmpresa array[], int len, int* id)
{
	int retorno = -1;
	int i;
	int cant;

	eEmpresa auxArray[] =
	{
		{0, "Plusmar"},
		{0, "Flecha Bus"},
		{0, "Tas"},
		{0, "El Rapido"}
	};

	if(array != NULL && len > 0 && id != NULL)
	{
		cant = sizeof(auxArray) / sizeof(eEmpresa);

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

int eEmpresa_encontrarPorId(eEmpresa array[], int len, int id, int* indice)
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

int eEmpresa_elegirCriterioOrdenamiento(int* criterio)
{
    int retorno = -1;
	char opcion;

    if(criterio != NULL)
    {
        printf("\n");
        system("pause");
        system("cls");

        printf("\tCRITERIO DE ORDENAMIENTO\n\n");
        printf("A. ID\n");
        printf("B. Descripcion\n");

        if(!utn_getCaracter(&opcion, "\nElija una opcion: ", "Error. Ingrese un solo caracter dentro del rango: ", 'A', 'B', 2))
        {
            switch(opcion)
            {
                case 'A':

                    *criterio = ID_EMPRESA;

                    break;

                case 'B':

                    *criterio = DESC_EMPRESA;

                    break;
            }

            retorno = 0;
        }
    }

    return retorno;
}

int eEmpresa_elegirSentidoOrdenamiento(int* order)
{
    int retorno = -1;
    char option;

    if(order != NULL)
    {
		printf("\n");
		system("pause");
		system("cls");

		printf("\tSENTIDO DE ORDENAMIENTO\n\n");
		printf("A. Orden Ascendente\n");
		printf("B. Orden Descendente\n");

		if(!utn_getCaracter(&option, "\nElija una opcion: ", "Error. Ingrese un solo caracter dentro del rango: ", 'A', 'B', 2))
		{
			switch(option)
			{
				case 'A':

					*order = UP_EMPRESA;

					break;

				case 'B':

					*order = DOWN_EMPRESA;

					break;
			}

			retorno = 0;
		}
    }

    return retorno;
}

int eEmpresa_compararInt(int a, int b)
{
	int retorno = -2;

	if(a > 0 && b > 0)
	{
		if(a < b)
		{
			retorno = -1;
		}

		else if(a == b)
		{
			retorno = 0;
		}

		else
		{
			retorno = 1;
		}
	}

	return retorno;
}

int eEmpresa_compararFloat(float a, float b)
{
	int retorno = -2;

	if(a > 0 && b > 0)
	{
		if(a < b)
		{
			retorno = -1;
		}

		else if(a == b)
		{
			retorno = 0;
		}

		else
		{
			retorno = 1;
		}
	}

	return retorno;
}

int eEmpresa_compararChar(char a, char b)
{
	int retorno = -2;

	if(a != '\0' && b != '\0')
	{
		if(a < b)
		{
			retorno = -1;
		}

		else if(a == b)
		{
			retorno = 0;
		}

		else
		{
			retorno = 1;
		}
	}

	return retorno;
}

int eEmpresa_compararString(char* a, char* b, int length)
{
	int retorno = -2;
	int auxCmp;

	if(a != NULL && b != NULL && length > 0)
	{
		auxCmp = strncmp(a, b, length);

		if(auxCmp < 0)
		{
			retorno = -1;
		}

		else if(auxCmp == 0)
		{
			retorno = 0;
		}

		else
		{
			retorno = 1;
		}
	}

	return retorno;
}

int eEmpresa_swap(eEmpresa* a, eEmpresa* b)
{
	int retorno = -1;
	eEmpresa temp;

	if(a != NULL && b != NULL)
	{
		temp = *a;
		*a = *b;
		*b = temp;

		retorno = 0;
	}

	return retorno;
}

int eEmpresa_compararCriterio(eEmpresa* a, eEmpresa* b, int criterio)
{
	int retorno = -3;

	if(a != NULL && b != NULL && criterio >= 0)
	{
		switch(criterio)
		{
			case ID_EMPRESA:

				retorno = eEmpresa_compararInt(a->id, b->id);

				break;

			case DESC_EMPRESA:

				retorno = eEmpresa_compararString(a->descripcion, b->descripcion, DESC_LEN_EMPRESA);

				break;
		}
	}

	return retorno;
}

int eEmpresa_ordenar(eEmpresa array[], int len, int criterio1, int criterio2, int order)
{
	int retorno = -1;
	int i;
	int auxLen;
	int auxCmp;
	int flagSwap;

	if(array != NULL && len > 0 && criterio1 >= 0 && criterio2 >= 0 &&
	   criterio1 != criterio2 && (order == UP_EMPRESA || order == DOWN_EMPRESA))
	{
		auxLen = len;

		do
		{
			flagSwap = FALSE_EMPRESA;

			for(i = 0; i < auxLen - 1; i++)
			{
				auxCmp = eEmpresa_compararCriterio(&array[i], &array[i + 1], criterio1);

				if(auxCmp + !auxCmp * eEmpresa_compararCriterio(&array[i], &array[i + 1], criterio2) == order - !order &&
				   !eEmpresa_swap(&array[i], &array[i + 1]))
				{
					flagSwap = TRUE_EMPRESA;
				}
			}

			auxLen--;

		} while(flagSwap);

		retorno = 0;
	}

	return retorno;
}

int eEmpresa_mostrarUnaEmpresa(eEmpresa* unaEmpresa)
{
	int retorno = -1;

	if(unaEmpresa != NULL)
	{
		printf("|%-10d|%-20s|\n", unaEmpresa->id, unaEmpresa->descripcion);

		retorno = 0;
	}

	return retorno;
}

int eEmpresa_mostrarLista(eEmpresa array[], int len)
{
	int retorno = -1;
	int i;

	if(array != NULL && len > 0)
	{
		printf("\n");
		system("pause");
		system("cls");

		printf("\tLISTA DE EMPRESAS\n\n");
		printf("*----------*--------------------*\n");
		printf("|%-10s|%-20s|\n", "ID", "DESCRIPCION");
		printf("*----------*--------------------*\n");

		for(i = 0; i < len; i++)
		{
			if(eEmpresa_mostrarUnaEmpresa(&array[i]))
			{
				break;
			}
		}

		printf("*----------*--------------------*\n");

		if(i == len)
		{
			retorno = 0;
		}
	}

	return retorno;
}
