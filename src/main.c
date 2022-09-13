#include <stdio.h>
#include <stdlib.h>
#include "Nexo.h"
#include "utn.h"

#define EMPRESA_MAX 4
#define TIPO_MAX 4
#define MICRO_MAX 10
#define CHOFER_MAX 4
#define DEST_MAX 4
#define VIAJE_MAX 10

int main(void)
{
	setbuf(stdout, NULL);

	eEmpresa arrayEmpresas[EMPRESA_MAX];
	eTipo arrayTipos[TIPO_MAX];
	eMicro arrayMicros[MICRO_MAX];
	eChofer arrayChoferes[CHOFER_MAX];
	eDestino arrayDestinos[DEST_MAX];
	eViaje arrayViajes[VIAJE_MAX];

	int opcion;
	int flagExit = 0;

	int auxOrder;

	int idEmpresa = 1000;
	int idTipo = 5000;
	int idMicro = 1;
	int idChofer = 1;
	int idDest = 20000;
	int idViaje = 1;

	if(!eMicro_inicializar(arrayMicros, MICRO_MAX) && !eViaje_inicializar(arrayViajes, VIAJE_MAX))
	{
		eEmpresa_hardcodear(arrayEmpresas, EMPRESA_MAX, &idEmpresa);
		eTipo_hardcodear(arrayTipos, TIPO_MAX, &idTipo);
		eMicro_hardcodear(arrayMicros, MICRO_MAX, &idMicro);
		eChofer_hardcodear(arrayChoferes, CHOFER_MAX, &idChofer);
		eDestino_hardcodear(arrayDestinos, DEST_MAX, &idDest);
		eViaje_hardcodear(arrayViajes, VIAJE_MAX, &idViaje);

		do
		{
			if(!mostrarMenuPrincipal(&opcion))
			{
				switch(opcion)
				{

					case 1:

						if(ABM_eMicro(arrayMicros, MICRO_MAX, arrayChoferes, CHOFER_MAX, arrayEmpresas, EMPRESA_MAX, arrayTipos, TIPO_MAX, &idMicro))
						{
							printf("\nNo se pudo mostrar el menu de ABM Micros\n");
						}

						break;

					case 2:

						if(!eMicro_arrayIsEmpty(arrayMicros, MICRO_MAX))
						{
							if(!eMicro_elegirSentidoOrdenamiento(&auxOrder) &&
							   !eMicro_ordenar(arrayMicros, MICRO_MAX, EMPRESA_MICRO, CAPACIDAD_MICRO, auxOrder) &&
							   !eMicro_mostrarLista(arrayMicros, MICRO_MAX, arrayChoferes, CHOFER_MAX, arrayEmpresas, EMPRESA_MAX, arrayTipos, TIPO_MAX))
							{
								printf("\nLista de Micros mostrada correctamente\n");
							}

							else
							{
								printf("\nNo se pudo mostrar la lista de Micros\n");
							}
						}

						else
						{
							printf("\nNo hay Micros para mostrar\n");
						}

						break;

					case 3:

						if(!eEmpresa_mostrarLista(arrayEmpresas, EMPRESA_MAX))
						{
							printf("\nLista de Empresas mostrada correctamente\n");
						}

						else
						{
							printf("\nNo se pudo mostrar la lista de Empresas\n");
						}

						break;

					case 4:

						if(!eTipo_mostrarLista(arrayTipos, TIPO_MAX))
						{
							printf("\nLista de Tipos mostrada correctamente\n");
						}

						else
						{
							printf("\nNo se pudo mostrar la lista de Tipos\n");
						}

						break;

					case 5:

						if(!eDestino_mostrarLista(arrayDestinos, DEST_MAX))
						{
							printf("\nLista de Destinos mostrada correctamente\n");
						}

						else
						{
							printf("\nNo se pudo mostrar la lista de Destinos\n");
						}

						break;

					case 6:

						if(ABM_eViaje(arrayViajes, VIAJE_MAX, arrayMicros, MICRO_MAX, arrayChoferes, CHOFER_MAX, arrayEmpresas, EMPRESA_MAX, arrayTipos, TIPO_MAX, arrayDestinos, DEST_MAX, &idViaje))
						{
							printf("\nNo se pudo mostrar el menu de ABM Viajes\n");
						}

						break;

					case 7:

						if(!eViaje_arrayIsEmpty(arrayViajes, VIAJE_MAX))
						{
							if(!eViaje_mostrarLista(arrayViajes, VIAJE_MAX, arrayMicros, MICRO_MAX, arrayEmpresas, EMPRESA_MAX, arrayTipos, TIPO_MAX, arrayDestinos, DEST_MAX))
							{
								printf("\nLista de Viajes mostrada correctamente\n");
							}

							else
							{
								printf("\nNo se pudo mostrar la lista de Viajes\n");
							}
						}

						else
						{
							printf("\nNo hay Viajes para mostrar\n");
						}

						break;

					case 8:

						if(realizarInformes(arrayViajes, VIAJE_MAX, arrayMicros, MICRO_MAX, arrayChoferes, CHOFER_MAX, arrayEmpresas, EMPRESA_MAX, arrayTipos, TIPO_MAX, arrayDestinos, DEST_MAX))
						{
							printf("\nNo se pudo mostrar el menu de Informes\n");
						}

						break;

					case 9:

						if(utn_respuestaEsAfirmativa("\nEsta seguro que desea salir del menu? (S/N): ", "Error. Solo S o N: ") == 1)
						{
							printf("\nUsted ha salido del menu\n");

							flagExit = 1;
						}

						break;
				}
			}

			printf("\n");
			system("pause");
			system("cls");

		} while(opcion != 9 || !flagExit);
	}

	else
	{
		printf("Error en la inicializacion\n");
	}

	return EXIT_SUCCESS;
}
