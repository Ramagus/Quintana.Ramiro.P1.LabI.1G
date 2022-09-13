#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Destino.h"


int eDestino_hardcodear(eDestino array[], int len, int* id)
{
	int retorno = -1;
	int i;
	int cant;

	eDestino auxArray[] =
	{
		{0, "Calafate", 22250},
		{0, "Bariloche", 103000},
		{0, "Iguazu", 84400},
		{0, "Mendoza", 95600}
	};

	if(array != NULL && len > 0 && id != NULL)
	{
		cant = sizeof(auxArray) / sizeof(eDestino);

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

int eDestino_encontrarPorId(eDestino array[], int len, int id, int* indice)
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

int eDestino_elegirCriterioOrdenamiento(int* criterio)
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
        printf("C. Precio\n");

        if(!utn_getCaracter(&opcion, "\nElija una opcion: ", "Error. Ingrese un solo caracter dentro del rango: ", 'A', 'C', 2))
        {
            switch(opcion)
            {
                case 'A':

                    *criterio = ID_DEST;

                    break;

                case 'B':

                    *criterio = DESC_DEST;

                    break;

                case 'C':

                    *criterio = PRECIO_DEST;

                    break;
            }

            retorno = 0;
        }
    }

    return retorno;
}

int eDestino_elegirSentidoOrdenamiento(int* order)
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

					*order = UP_DEST;

					break;

				case 'B':

					*order = DOWN_DEST;

					break;
			}

			retorno = 0;
		}
    }

    return retorno;
}

int eDestino_compararInt(int a, int b)
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

int eDestino_compararFloat(float a, float b)
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

int eDestino_compararChar(char a, char b)
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

int eDestino_compararString(char* a, char* b, int length)
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

int eDestino_swap(eDestino* a, eDestino* b)
{
	int retorno = -1;
	eDestino temp;

	if(a != NULL && b != NULL)
	{
		temp = *a;
		*a = *b;
		*b = temp;

		retorno = 0;
	}

	return retorno;
}

int eDestino_compararCriterio(eDestino* a, eDestino* b, int criterio)
{
	int retorno = -3;

	if(a != NULL && b != NULL && criterio >= 0)
	{
		switch(criterio)
		{
			case ID_DEST:

				retorno = eDestino_compararInt(a->id, b->id);

				break;

			case DESC_DEST:

				retorno = eDestino_compararString(a->descripcion, b->descripcion, DESC_LEN_DEST);

				break;

			case PRECIO_DEST:

				retorno = eDestino_compararFloat(a->precio, b->precio);

				break;
		}
	}

	return retorno;
}

int eDestino_ordenar(eDestino array[], int len, int criterio1, int criterio2, int order)
{
	int retorno = -1;
	int i;
	int auxLen;
	int auxCmp;
	int flagSwap;

	if(array != NULL && len > 0 && criterio1 >= 0 && criterio2 >= 0 &&
	   criterio1 != criterio2 && (order == UP_DEST || order == DOWN_DEST))
	{
		auxLen = len;

		do
		{
			flagSwap = FALSE_DEST;

			for(i = 0; i < auxLen - 1; i++)
			{
				auxCmp = eDestino_compararCriterio(&array[i], &array[i + 1], criterio1);

				if(auxCmp + !auxCmp * eDestino_compararCriterio(&array[i], &array[i + 1], criterio2) == order - !order &&
				   !eDestino_swap(&array[i], &array[i + 1]))
				{
					flagSwap = TRUE_DEST;
				}
			}

			auxLen--;

		} while(flagSwap);

		retorno = 0;
	}

	return retorno;
}

int eDestino_mostrarUnDestino(eDestino* unDestino)
{
	int retorno = -1;

	if(unDestino != NULL)
	{
		printf("|%-10d|%-20s|%-9.2f|\n", unDestino->id, unDestino->descripcion, unDestino->precio);

		retorno = 0;
	}

	return retorno;
}

int eDestino_mostrarLista(eDestino array[], int len)
{
	int retorno = -1;
	int i;

	if(array != NULL && len > 0)
	{
		printf("\n");
		system("pause");
		system("cls");

		printf("\tLISTA DE DESTINOS\n\n");
		printf("*----------*--------------------*---------*\n");
		printf("|%-10s|%-20s|%-9s|\n", "ID", "DESCRIPCION", "PRECIO");
		printf("*----------*--------------------*---------*\n");

		for(i = 0; i < len; i++)
		{
			if(eDestino_mostrarUnDestino(&array[i]))
			{
				break;
			}
		}

		printf("*----------*--------------------*---------*\n");

		if(i == len)
		{
			retorno = 0;
		}
	}

	return retorno;
}
