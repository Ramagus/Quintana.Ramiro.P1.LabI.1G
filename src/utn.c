#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"

#define MAX_LEN 100


/**
 * \brief Limpia el buffer de entrada est�ndar (stdin)
 *
 * \param void
 *
 * \return void
 *
 */
static void clearStdin(void);


/** \brief Lee de stdin una cadena hasta que encuentra un '\n' o hasta que haya copiado
 *         un m�ximo de "longitud - 1" caracteres
 *
 * \param pResultado char* Puntero al espacio de memoria donde se copiar� la cadena obtenida
 * \param longitud int Define el tama�o de cadena
 *
 * \return int Retorna 0 (EXITO) si se obtiene una cadena y -1 (ERROR) si no
 *
 */
static int getString(char* cadena, int longitud);


/** \brief Verifica si la cadena ingresada es num�rica
 *
 * \param cadena char* Cadena de caracteres a ser analizada
 * \param limite int Cantidad m�xima de caracteres
 *
 * \return int Retorna 1 (VERDADERO) si la cadena es num�rica, 0 (FALSO) si no lo es y -1 en caso de error
 *
 */
static int esNumerica(char* cadena, int limite);


/** \brief Obtiene un n�mero entero
 *
 * \param pResultado int* Puntero al espacio de memoria donde se dejar� el resultado de la funci�n
 *
 * \return int Retorna 0 (EXITO) si se obtiene un n�mero entero y -1 (ERROR) si no
 *
 */
static int getInt(int* pResultado);


/** \brief Verifica si la cadena ingresada es flotante
 *
 * \param cadena char* Cadena de caracteres a ser analizada
 * \param limite int Cantidad m�xima de caracteres
 *
 * \return int Retorna 1 (VERDADERO) si la cadena es flotante, 0 (FALSO) si no lo es y -1 en caso de error
 *
 */
static int esFlotante(char* cadena, int limite);


/** \brief Obtiene un n�mero flotante
 *
 * \param pResultado float* Puntero al espacio de memoria donde se dejar� el resultado de la funci�n
 *
 * \return int Retorna 0 (EXITO) si se obtiene un n�mero flotante y -1 (ERROR) si no
 *
 */
static int getFloat(float* pResultado);


/** \brief Verifica si la cadena ingresada es alfab�tica
 *
 * \param cadena char* Cadena de caracteres a ser analizada
 * \param limite int Cantidad m�xima de caracteres
 *
 * \return int Retorna 1 (VERDADERO) si la cadena es alfab�tica, 0 (FALSO) si no lo es y -1 en caso de error
 *
 */
static int esAlfabetica(char* cadena, int limite);


/** \brief Obtiene una cadena alfab�tica
 *
 * \param pResultado char* Puntero al espacio de memoria donde se dejar� el resultado de la funci�n
 *
 * \return int Retorna 0 (EXITO) si se obtiene una cadena alfab�tica y -1 (ERROR) si no
 *
 */
static int getStringAlfabetico(char* pResultado);


/** \brief Obtiene una cadena num�rica
 *
 * \param pResultado char* Puntero al espacio de memoria donde se dejar� el resultado de la funci�n
 *
 * \return int Retorna 0 (EXITO) si se obtiene una cadena num�rica y -1 (ERROR) si no
 *
 */
static int getStringNumerico(char* pResultado);


/** \brief Obtiene una cadena num�rica flotante
 *
 * \param pResultado char* Puntero al espacio de memoria donde se dejar� el resultado de la funci�n
 *
 * \return int Retorna 0 (EXITO) si se obtiene una cadena num�rica flotante y -1 (ERROR) si no
 *
 */
static int getStringFlotante(char* pResultado);


/** \brief Verifica si la cadena ingresada es alfanum�rica
 *
 * \param cadena char* Cadena de caracteres a ser analizada
 * \param limite int Cantidad m�xima de caracteres
 *
 * \return int Retorna 1 (VERDADERO) si la cadena es alfanum�rica, 0 (FALSO) si no lo es y -1 en caso de error
 *
 */
static int esAlfaNumerica(char* cadena, int limite);


/** \brief Obtiene una cadena alfanum�rica
 *
 * \param pResultado char* Puntero al espacio de memoria donde se dejar� el resultado de la funci�n
 *
 * \return int Retorna 0 (EXITO) si se obtiene una cadena alfanum�rica y -1 (ERROR) si no
 *
 */
static int getStringAlfaNumerico(char* pResultado);


/** \brief Verifica si la cadena ingresada es eMail
 *
 * \param cadena char* Cadena de caracteres a ser analizada
 * \param limite int Cantidad m�xima de caracteres
 *
 * \return int Retorna 1 (VERDADERO) si la cadena es eMail, 0 (FALSO) si no lo es y -1 en caso de error
 *
 */
static int esEmail(char* cadena, int limite);


/** \brief Obtiene una cadena eMail
 *
 * \param pResultado char* Puntero al espacio de memoria donde se dejar� el resultado de la funci�n
 *
 * \return int Retorna 0 (EXITO) si se obtiene una cadena eMail y -1 (ERROR) si no
 *
 */
static int getStringEmail(char* pResultado);


/** \brief Verifica si la cadena ingresada es DNI
 *
 * \param cadena char* Cadena de caracteres a ser analizada
 * \param limite int Cantidad m�xima de caracteres
 *
 * \return int Retorna 1 (VERDADERO) si la cadena es DNI, 0 (FALSO) si no lo es y -1 en caso de error
 *
 */
static int esDNI(char* cadena, int limite);


/** \brief Obtiene una cadena DNI
 *
 * \param pResultado char* Puntero al espacio de memoria donde se dejar� el resultado de la funci�n
 *
 * \return int Retorna 0 (EXITO) si se obtiene una cadena DNI y -1 (ERROR) si no
 *
 */
static int getStringDNI(char* pResultado);


/** \brief Verifica si la cadena ingresada es CUIT
 *
 * \param cadena char* Cadena de caracteres a ser analizada
 * \param limite int Cantidad m�xima de caracteres
 *
 * \return int Retorna 1 (VERDADERO) si la cadena es CUIT, 0 (FALSO) si no lo es y -1 en caso de error
 *
 */
static int esCUIT(char* cadena, int limite);


/** \brief Obtiene una cadena CUIT
 *
 * \param pResultado char* Puntero al espacio de memoria donde se dejar� el resultado de la funci�n
 *
 * \return int Retorna 0 (EXITO) si se obtiene una cadena CUIT y -1 (ERROR) si no
 *
 */
static int getStringCUIT(char* pResultado);


/** \brief Verifica si la cadena ingresada es tel�fono
 *
 * \param cadena char* Cadena de caracteres a ser analizada
 * \param limite int Cantidad m�xima de caracteres
 *
 * \return int Retorna 1 (VERDADERO) si la cadena es tel�fono, 0 (FALSO) si no lo es y -1 en caso de error
 *
 */
static int esTelefono(char* cadena, int limite);


/** \brief Obtiene una cadena telef�nica
 *
 * \param pResultado char* Puntero al espacio de memoria donde se dejar� el resultado de la funci�n
 *
 * \return int Retorna 0 (EXITO) si se obtiene una cadena telef�nica y -1 (ERROR) si no
 *
 */
static int getStringTelefono(char* pResultado);


/** \brief Verifica si la cadena ingresada es fecha
 *
 * \param cadena char* Cadena de caracteres a ser analizada
 * \param limite int Cantidad m�xima de caracteres
 *
 * \return int Retorna 1 (VERDADERO) si la cadena es fecha, 0 (FALSO) si no lo es y -1 en caso de error
 *
 */
static int esFecha(char* cadena, int limite);


/** \brief Obtiene una cadena de fecha
 *
 * \param pResultado char* Puntero al espacio de memoria donde se dejar� el resultado de la funci�n
 *
 * \return int Retorna 0 (EXITO) si se obtiene una cadena de fecha y -1 (ERROR) si no
 *
 */
static int getStringFecha(char* pResultado);


/** \brief Obtiene un caracter
 *
 * \param pResultado char* Puntero al espacio de memoria donde se dejar� el resultado de la funci�n
 *
 * \return int Retorna 0 (EXITO) si se obtiene un solo caracter y -1 (ERROR) si no
 *
 */
static int getChar(char* pResultado);


static void clearStdin(void)
{
	scanf("%*[\n]");
}

int utn_formatearCadena(char* cadena, int limite)
{
    int retorno = -1;
    int i;

    if(cadena != NULL && limite > 0)
    {
        strlwr(cadena);

        for(i = 0; i < limite && cadena[i] != '\0'; i++)
        {
            if(i == 0 || isspace(cadena[i - 1]))
            {
                cadena[i] = toupper(cadena[i]);
            }
        }

        retorno = 0;
    }

    return retorno;
}

static int getString(char* cadena, int longitud)
{
    int retorno = -1;
    char bufferString[MAX_LEN];
    int len;

    if(cadena != NULL && longitud > 0)
    {
        clearStdin();

        if(fgets(bufferString, MAX_LEN, stdin) != NULL)
        {
            len = strnlen(bufferString, MAX_LEN);

            if(len < longitud)
            {
                if(bufferString[len - 1] == '\n')
                {
                    bufferString[len - 1] = '\0';
                }

                strncpy(cadena, bufferString, longitud);
                retorno = 0;
            }
        }
    }

    return retorno;
}

static int esNumerica(char* cadena, int limite)
{
    int retorno = -1;
    int i;

    if(cadena != NULL && limite > 0)
    {
        retorno = 1;

        for(i = 0; i < limite && cadena[i] != '\0'; i++)
        {
            if(!isdigit(cadena[i]))
            {
                if((i == 0) && (cadena[i] == '-' || cadena[i] == '+'))
                {
                    continue;
                }

                retorno = 0;
                break;
            }
        }
    }

    return retorno;
}

static int getInt(int* pResultado)
{
    int retorno = -1;
    char bufferString[MAX_LEN];

    if(pResultado != NULL && !getString(bufferString, MAX_LEN) && esNumerica(bufferString, MAX_LEN) == 1)
    {
        *pResultado = atoi(bufferString);
        retorno = 0;
    }

    return retorno;
}

int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
    int retorno = -1;
    int bufferInt;
    int flagError = 0;

    if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
    {
        do
        {
            if(flagError == 0)
            {
                printf("%s", mensaje);

                flagError = 1;
            }

            else
            {
                printf("%s", mensajeError);
            }

            if((!getInt(&bufferInt)) && (bufferInt >= minimo && bufferInt <= maximo))
            {
                *pResultado = bufferInt;
                retorno = 0;
                break;
            }

            reintentos--;

        } while(reintentos >= 0);
    }

    return retorno;
}

static int esFlotante(char* cadena, int limite)
{
    int retorno = -1;
    int i;
    int tienePunto = 0;

    if(cadena != NULL && limite > 0)
    {
        retorno = 1;

        for(i = 0; i < limite && cadena[i] != '\0'; i++)
        {
            if(!isdigit(cadena[i]))
            {
                if((i == 0) && (cadena[i] == '-' || cadena[i] == '+'))
                {
                    continue;
                }

                if(cadena[i] == '.' && tienePunto == 0)
                {
                    tienePunto = 1;
                    continue;
                }

                retorno = 0;
                break;
            }
        }
    }

    return retorno;
}

static int getFloat(float* pResultado)
{
    int retorno = -1;
    char bufferString[MAX_LEN];

    if(pResultado != NULL && !getString(bufferString, MAX_LEN) && esFlotante(bufferString, MAX_LEN) == 1)
    {
        *pResultado = atof(bufferString);
        retorno = 0;
    }

    return retorno;
}

int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos)
{
    int retorno = -1;
    float bufferFloat;
    int flagError = 0;

    if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
    {
        do
        {
            if(flagError == 0)
            {
                printf("%s", mensaje);

                flagError = 1;
            }

            else
            {
                printf("%s", mensajeError);
            }

            if((!getFloat(&bufferFloat)) && (bufferFloat >= minimo && bufferFloat <= maximo))
            {
                *pResultado = bufferFloat;
                retorno = 0;
                break;
            }

            reintentos--;

        } while(reintentos >= 0);
    }

    return retorno;
}

int utn_getCadena(char* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
    int retorno = -1;
    char bufferString[MAX_LEN];
    int flagError = 0;
    int len;

    if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
    {
        do
        {
            if(flagError == 0)
            {
                printf("%s", mensaje);

                flagError = 1;
            }

            else
            {
                printf("%s", mensajeError);
            }

            if(!getString(bufferString, MAX_LEN))
            {
                len = strlen(bufferString);

                if(len >= minimo && len <= maximo)
                {
                    strncpy(pResultado, bufferString, maximo);
                    retorno = 0;
                    break;
                }
            }

            reintentos--;

        } while(reintentos >= 0);
    }

    return retorno;
}

static int esAlfabetica(char* cadena, int limite)
{
    int retorno = -1;
    int i;

    if(cadena != NULL && limite > 0)
    {
        retorno = 1;

        for(i = 0; i < limite && cadena[i] != '\0'; i++)
        {
            if(!isalpha(cadena[i]) && !isspace(cadena[i]))
            {
                retorno = 0;
                break;
            }
        }
    }

    return retorno;
}

static int getStringAlfabetico(char* pResultado)
{
    int retorno = -1;
    char bufferString[MAX_LEN];

    if(pResultado != NULL && !getString(bufferString, MAX_LEN) && esAlfabetica(bufferString, MAX_LEN) == 1)
    {
        strncpy(pResultado, bufferString, MAX_LEN);
        retorno = 0;
    }

    return retorno;
}

int utn_getAlfabetico(char* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
    int retorno = -1;
    char bufferString[MAX_LEN];
    int flagError = 0;
    int len;

    if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
    {
        do
        {
            if(flagError == 0)
            {
                printf("%s", mensaje);

                flagError = 1;
            }

            else
            {
                printf("%s", mensajeError);
            }

            if(!getStringAlfabetico(bufferString))
            {
                len = strlen(bufferString);

                if(len >= minimo && len <= maximo)
                {
                    strncpy(pResultado, bufferString, maximo);
                    retorno = 0;
                    break;
                }
            }

            reintentos--;

        } while(reintentos >= 0);
    }

    return retorno;
}

static int getStringNumerico(char* pResultado)
{
    int retorno = -1;
    char bufferString[MAX_LEN];

    if(pResultado != NULL && !getString(bufferString, MAX_LEN) && esNumerica(bufferString, MAX_LEN) == 1)
    {
        strncpy(pResultado, bufferString, MAX_LEN);
        retorno = 0;
    }

    return retorno;
}

int utn_getStringNumerico(char* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
    int retorno = -1;
    char bufferString[MAX_LEN];
    int flagError = 0;
    int len;

    if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
    {
        do
        {
            if(flagError == 0)
            {
                printf("%s", mensaje);

                flagError = 1;
            }

            else
            {
                printf("%s", mensajeError);
            }

            if(!getStringNumerico(bufferString))
            {
                len = strlen(bufferString);

                if(len >= minimo && len <= maximo)
                {
                    strncpy(pResultado, bufferString, maximo);
                    retorno = 0;
                    break;
                }
            }

            reintentos--;

        } while(reintentos >= 0);
    }

    return retorno;
}

static int getStringFlotante(char* pResultado)
{
    int retorno = -1;
    char bufferString[MAX_LEN];

    if(pResultado != NULL && !getString(bufferString, MAX_LEN) && esFlotante(bufferString, MAX_LEN) == 1)
    {
        strncpy(pResultado, bufferString, MAX_LEN);
        retorno = 0;
    }

    return retorno;
}

int utn_getStringFlotante(char* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
    int retorno = -1;
    char bufferString[MAX_LEN];
    int flagError = 0;
    int len;

    if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
    {
        do
        {
            if(flagError == 0)
            {
                printf("%s", mensaje);

                flagError = 1;
            }

            else
            {
                printf("%s", mensajeError);
            }

            if(!getStringFlotante(bufferString))
            {
                len = strlen(bufferString);

                if(len >= minimo && len <= maximo)
                {
                    strncpy(pResultado, bufferString, maximo);
                    retorno = 0;
                    break;
                }
            }

            reintentos--;

        } while(reintentos >= 0);
    }

    return retorno;
}

static int esAlfaNumerica(char* cadena, int limite)
{
    int retorno = -1;
    int i;

    if(cadena != NULL && limite > 0)
    {
        retorno = 1;

        for(i = 0; i < limite && cadena[i] != '\0'; i++)
        {
            if(!isalnum(cadena[i]) && !isspace(cadena[i]))
            {
                retorno = 0;
                break;
            }
        }
    }

    return retorno;
}

static int getStringAlfaNumerico(char* pResultado)
{
    int retorno = -1;
    char bufferString[MAX_LEN];

    if(pResultado != NULL && !getString(bufferString, MAX_LEN) && esAlfaNumerica(bufferString, MAX_LEN) == 1)
    {
        strncpy(pResultado, bufferString, MAX_LEN);
        retorno = 0;
    }

    return retorno;
}

int utn_getAlfaNumerico(char* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
    int retorno = -1;
    char bufferString[MAX_LEN];
    int flagError = 0;
    int len;

    if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
    {
        do
        {
            if(flagError == 0)
            {
                printf("%s", mensaje);

                flagError = 1;
            }

            else
            {
                printf("%s", mensajeError);
            }

            if(!getStringAlfaNumerico(bufferString))
            {
                len = strlen(bufferString);

                if(len >= minimo && len <= maximo)
                {
                    strncpy(pResultado, bufferString, maximo);
                    retorno = 0;
                    break;
                }
            }

            reintentos--;

        } while(reintentos >= 0);
    }

    return retorno;
}

static int esEmail(char* cadena, int limite)
{
    int retorno = -1;
    int i;
    int tieneArroba = 0;

    if(cadena != NULL && limite > 0)
    {
        retorno = 1;

        for(i = 0; i < limite && cadena[i] != '\0'; i++)
        {
            if(!isalpha(cadena[i]) && !isdigit(cadena[i]) && cadena[i] != '-' && cadena[i] != '_' && cadena[i] != '~' && cadena[i] != '.')
            {
                if(i > 2 && cadena[i] == '@' && tieneArroba == 0)
                {
                    tieneArroba = 1;
                    continue;
                }

                retorno = 0;
                break;
            }
        }
    }

    return retorno;
}

static int getStringEmail(char* pResultado)
{
    int retorno = -1;
    char bufferString[MAX_LEN];

    if(pResultado != NULL && !getString(bufferString, MAX_LEN) && esEmail(bufferString, MAX_LEN) == 1)
    {
        strncpy(pResultado, bufferString, MAX_LEN);
        retorno = 0;
    }

    return retorno;
}

int utn_getEmail(char* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
    int retorno = -1;
    char bufferString[MAX_LEN];
    int flagError = 0;
    int len;

    if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
    {
        do
        {
            if(flagError == 0)
            {
                printf("%s", mensaje);

                flagError = 1;
            }

            else
            {
                printf("%s", mensajeError);
            }

            if(!getStringEmail(bufferString))
            {
                len = strlen(bufferString);

                if(len >= minimo && len <= maximo)
                {
                    strncpy(pResultado, bufferString, maximo);
                    retorno = 0;
                    break;
                }
            }

            reintentos--;

        } while(reintentos >= 0);
    }

    return retorno;
}

static int esDNI(char* cadena, int limite)
{
    int retorno = -1;
    int i;
    int tienePuntos = 0;

    if(cadena != NULL && limite > 0)
    {
        retorno = 1;

        for(i = 0; i < limite && cadena[i] != '\0'; i++)
        {
            if(!isdigit(cadena[i]))
            {
                if((cadena[i] == '.' && tienePuntos != 2) && ((i == 1 || i == 2) || (i == 5 || i == 6)))
                {
                    tienePuntos++;
                    continue;
                }

                retorno = 0;
                break;
            }
        }

        if(tienePuntos < 2)
        {
            retorno = 0;
        }
    }

    return retorno;
}

static int getStringDNI(char* pResultado)
{
    int retorno = -1;
    char bufferString[MAX_LEN];

    if(pResultado != NULL && !getString(bufferString, MAX_LEN) && esDNI(bufferString, MAX_LEN) == 1)
    {
        strncpy(pResultado, bufferString, MAX_LEN);
        retorno = 0;
    }

    return retorno;
}

int utn_getDNI(char* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
    int retorno = -1;
    char bufferString[MAX_LEN];
    int flagError = 0;
    int len;

    if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
    {
        do
        {
            if(flagError == 0)
            {
                printf("%s", mensaje);

                flagError = 1;
            }

            else
            {
                printf("%s", mensajeError);
            }

            if(!getStringDNI(bufferString))
            {
                len = strlen(bufferString);

                if(len >= minimo && len <= maximo)
                {
                    strncpy(pResultado, bufferString, maximo);
                    retorno = 0;
                    break;
                }
            }

            reintentos--;

        } while(reintentos >= 0);
    }

    return retorno;
}

static int esCUIT(char* cadena, int limite)
{
    int retorno = -1;
    int i;
    int tieneGuiones = 0;

    if(cadena != NULL && limite > 0)
    {
        retorno = 1;

        for(i = 0; i < limite && cadena[i] != '\0'; i++)
        {
            if(!isdigit(cadena[i]))
            {
                if((cadena[i] == '-' && tieneGuiones != 2) && ((i == 2) || (i == 10 || i == 11)))
                {
                    tieneGuiones++;
                    continue;
                }

                retorno = 0;
                break;
            }
        }

        if(tieneGuiones < 2)
        {
            retorno = 0;
        }
    }

    return retorno;
}

static int getStringCUIT(char* pResultado)
{
    int retorno = -1;
    char bufferString[MAX_LEN];

    if(pResultado != NULL && !getString(bufferString, MAX_LEN) && esCUIT(bufferString, MAX_LEN) == 1)
    {
        strncpy(pResultado, bufferString, MAX_LEN);
        retorno = 0;
    }

    return retorno;
}

int utn_getCUIT(char* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
    int retorno = -1;
    char bufferString[MAX_LEN];
    int flagError = 0;
    int len;

    if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
    {
        do
        {
            if(flagError == 0)
            {
                printf("%s", mensaje);

                flagError = 1;
            }

            else
            {
                printf("%s", mensajeError);
            }

            if(!getStringCUIT(bufferString))
            {
                len = strlen(bufferString);

                if(len >= minimo && len <= maximo)
                {
                    strncpy(pResultado, bufferString, maximo);
                    retorno = 0;
                    break;
                }
            }

            reintentos--;

        } while(reintentos >= 0);
    }

    return retorno;
}

static int esTelefono(char* cadena, int limite)
{
    int retorno = -1;
    int i;
    int tieneGuiones = 0;

    if(cadena != NULL && limite > 0)
    {
        retorno = 1;

        for(i = 0; i < limite && cadena[i] != '\0'; i++)
        {
            if(!isdigit(cadena[i]) && !isspace(cadena[i]))
            {
                if((cadena[i] == '-' && tieneGuiones != 2) && i > 1)
                {
                    tieneGuiones++;
                    continue;
                }

                if(i == 0 && cadena[i] == '+')
                {
                    continue;
                }

                retorno = 0;
                break;
            }
        }

        if(tieneGuiones < 1)
        {
            retorno = 0;
        }
    }

    return retorno;
}

static int getStringTelefono(char* pResultado)
{
    int retorno = -1;
    char bufferString[MAX_LEN];

    if(pResultado != NULL && !getString(bufferString, MAX_LEN) && esTelefono(bufferString, MAX_LEN) == 1)
    {
        strncpy(pResultado, bufferString, MAX_LEN);
        retorno = 0;
    }

    return retorno;
}

int utn_getTelefono(char* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
    int retorno = -1;
    char bufferString[MAX_LEN];
    int flagError = 0;
    int len;

    if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
    {
        do
        {
            if(flagError == 0)
            {
                printf("%s", mensaje);

                flagError = 1;
            }

            else
            {
                printf("%s", mensajeError);
            }

            if(!getStringTelefono(bufferString))
            {
                len = strlen(bufferString);

                if(len >= minimo && len <= maximo)
                {
                    strncpy(pResultado, bufferString, maximo);
                    retorno = 0;
                    break;
                }
            }

            reintentos--;

        } while(reintentos >= 0);
    }

    return retorno;
}

static int esFecha(char* cadena, int limite)
{
    int retorno = -1;
    int i;

    if(cadena != NULL && limite > 0)
    {
        retorno = 1;

        for(i = 0; i < limite && cadena[i] != '\0'; i++)
        {
            if(!isdigit(cadena[i]))
            {
                if((cadena[i] == '/' || cadena[i] == '-') && (i == 2 || i == 5))
                {
                    continue;
                }

                retorno = 0;
                break;
            }
        }
    }

    return retorno;
}

static int getStringFecha(char* pResultado)
{
    int retorno = -1;
    char bufferString[MAX_LEN];

    if(pResultado != NULL && !getString(bufferString, MAX_LEN) && esFecha(bufferString, MAX_LEN) == 1)
    {
        strncpy(pResultado, bufferString, MAX_LEN);
        retorno = 0;
    }

    return retorno;
}

int utn_getFecha(char* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
    int retorno = -1;
    char bufferString[MAX_LEN];
    int flagError = 0;
    int len;

    if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
    {
        do
        {
            if(flagError == 0)
            {
                printf("%s", mensaje);

                flagError = 1;
            }

            else
            {
                printf("%s", mensajeError);
            }

            if(!getStringFecha(bufferString))
            {
                len = strlen(bufferString);

                if(len >= minimo && len <= maximo)
                {
                    strncpy(pResultado, bufferString, maximo);
                    retorno = 0;
                    break;
                }
            }

            reintentos--;

        } while(reintentos >= 0);
    }

    return retorno;
}

static int getChar(char* pResultado)
{
    int retorno = -1;
    char bufferChar;
    char auxString[5];
    int len;

    if(pResultado != NULL && !getString(auxString, sizeof(auxString)))
    {
        len = strnlen(auxString, sizeof(auxString));

        if(len == 1)
        {
            bufferChar = auxString[0];
            *pResultado = bufferChar;
            retorno = 0;
        }
    }

    return retorno;
}

int utn_getCaracter(char* pResultado, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos)
{
	int retorno = -1;
	char bufferChar;
	int flagError = 0;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do
		{
			if(flagError == 0)
            {
                printf("%s", mensaje);

                flagError = 1;
            }

            else
            {
                printf("%s", mensajeError);
            }

			if(!getChar(&bufferChar))
			{
				if(isalpha(minimo) && isalpha(maximo))
                {
                    if((isupper(minimo) && isupper(maximo)) && islower(bufferChar))
                    {
                        bufferChar = toupper(bufferChar);
                    }

                    else if((islower(minimo) && islower(maximo)) && isupper(bufferChar))
                    {
                        bufferChar = tolower(bufferChar);
                    }
                }

                if(bufferChar >= minimo && bufferChar <= maximo)
                {
                    *pResultado = bufferChar;
                    retorno = 0;
                    break;
                }
			}

			reintentos--;

		} while(reintentos >= 0);
	}

	return retorno;
}

int utn_getSexo(char* pResultado, char* mensaje, char* mensajeError, int reintentos)
{
	int retorno = -1;
	char bufferChar;
	int flagError = 0;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && reintentos >= 0)
	{
		do
		{
			if(flagError == 0)
            {
                printf("%s", mensaje);

                flagError = 1;
            }

            else
            {
                printf("%s", mensajeError);
            }

			if(!getChar(&bufferChar))
			{
                if(islower(bufferChar))
                {
                    bufferChar = toupper(bufferChar);
                }

                if(bufferChar == 'M' || bufferChar == 'F')
                {
                    *pResultado = bufferChar;
                    retorno = 0;
                    break;
                }
			}

			reintentos--;

		} while(reintentos >= 0);
	}

	return retorno;
}

int verificarRespuesta(char* pResp, char* mensaje, char* mensajeError)
{
    char dato;
    int retorno = -1;
    int flagError = 0;

    if(pResp != NULL && mensaje != NULL && mensajeError != NULL)
    {
        do
        {
            if(flagError == 0)
            {
                printf("%s", mensaje);

                flagError = 1;
            }

            else
            {
                printf("%s", mensajeError);
            }

            if(!getChar(&dato) && islower(dato))
			{
				dato = toupper(dato);
			}

        } while(dato != 'S' && dato != 'N');

        *pResp = dato;

        if(dato == 'S')
        {
            retorno = 1;
        }

        else
        {
            retorno = 0;
        }
    }

    return retorno;
}
