/*
 * Input.c
 *
 *  Created on: 5 abr. 2022
 *      Author: nicop
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Input.h"
#include "eFigurita.h"

int utn_getNumero(char mensaje[], char mensajeError[], int minimo, int maximo,
		int reintentos, int *pNumeroIngresado) {
	int retorno = -1;
	int auxiliarFloat;

	if (mensaje != NULL && minimo < maximo && mensajeError != NULL
			&& pNumeroIngresado != NULL && reintentos > 0) {

		do {
			printf("%s", mensaje);
			if (getInt(&auxiliarFloat) == 0 && auxiliarFloat >= minimo
					&& auxiliarFloat <= maximo) {
				*pNumeroIngresado = auxiliarFloat;
				retorno = 0;
				break;
			} else {
				printf("%s", mensajeError);
				reintentos--;

			}
		} while (reintentos > 0);
	}
	return retorno;
}

int utn_getFloat(char mensaje[], char mensajeError[], int minimo, int maximo,
		int reintentos, float *pNumeroIngresado) {
	int retorno = -1;
	float auxiliarFloat;

	if (mensaje != NULL && minimo < maximo && mensajeError != NULL
			&& pNumeroIngresado != NULL && reintentos > 0) {

		do {
			printf("%s", mensaje);
			if (getFloat(&auxiliarFloat) == 0 && auxiliarFloat >= minimo
					&& auxiliarFloat <= maximo) {
				*pNumeroIngresado = auxiliarFloat;
				retorno = 0;
				break;
			} else {
				printf("%s", mensajeError);
				reintentos--;

			}
		} while (reintentos > 0);
	}
	return retorno;
}

int getInt(int *pNumeroTomado) {
	int retorno = -1;
	char numeroAuxiliar[10];

	if (pNumeroTomado != NULL) {
		if (getString(numeroAuxiliar, sizeof(numeroAuxiliar)) == 0
				&& esInt(numeroAuxiliar, sizeof(numeroAuxiliar)) == 1) {
			*pNumeroTomado = atoi(numeroAuxiliar);
			retorno = 0;
		}
	}
	return retorno;
}

int getFloat(float *pNumeroTomado) {
	int retorno = -1;
	char numeroAuxiliar[10];

	if (pNumeroTomado != NULL) {
		if (getString(numeroAuxiliar, sizeof(numeroAuxiliar)) == 0
				&& esFloat(numeroAuxiliar, sizeof(numeroAuxiliar)) == 0) {
			*pNumeroTomado = atof(numeroAuxiliar);
			retorno = 0;
		}
	}
	return retorno;
}

int esNumerica(char arrayPosiblesNumeros[]) {
	int retorno = 0;
	int i;

	if (arrayPosiblesNumeros != NULL) {
		i = 0;

		while (arrayPosiblesNumeros[i] != '\0') {
			if (arrayPosiblesNumeros[i] < '0'
					|| arrayPosiblesNumeros[i] > '9') {
				retorno = -1;
				break;
			}
			i++;
		}
	} else {
		retorno = -1;
	}
	return retorno;
}


int esInt(char *string, int limite) {
	int retorno;
	int i = 0;
	//printf("el array tiene datos\n");
	for (i = 0; i < limite && string[i] != '\0'; i++) {
		if (i == 0 && (string[i] == '-' || string[i] == '+')) {
			continue;
		}
		if (string[i] < '0' || string[i] > '9') {
			//printf("El string tenia algo que no era n°.\n");
			retorno = 0;
			break;
		} else {
			//printf("El string tenia algo que no era n°.\n");
			retorno = 1;
		}
	}
	return retorno;
}

/*int esFloat(char* string, int limite)
 {
 int retorno;
 int i = 0;
 int flagPunto=0;
 //printf("el array tiene datos\n");
 for(i=0; i<limite && string[i] !='\0'; i++)
 {
 if(i == 0 && (string[i] == '-' || string[i] == '+'))
 {
 continue;
 }
 if(string[i] < '0' || string[i] > '9')      // modificar
 {
 //printf("El string tenia algo que no era n°.\n");
 retorno = 0;
 break;
 }
 else
 {
 //printf("El string tenia algo que no era n°.\n");
 retorno = 1;
 }
 if(string[i]=='.')
 {
 if(flagPunto==1)
 {
 retorno=-1;
 }
 else
 {
 flagPunto=1;
 }
 }
 }
 return retorno;
 }

 */

int esFloat(char string[], int limite) {
	int retorno = -1;
	int i = 0;
	int puntos = 0;

	if (string != NULL && limite > 0) {
		retorno = 0;
		if (string[0] == '-' || string[0] == '+') {
			i = 1;
		}
		while (string[i] != '\0') {
			if (string[i] == '.' && puntos == 0) {
				puntos++;
				i++;
				continue;
			}
			if (string[i] < '0' || string[i] > '9') {
				retorno = -2;
				break;
			}
			i++;
		}
	}
	return retorno;
}

/*
 int myGets(char cadena[], int size)
 {
 int retorno = -1;
 cadena[strlen(cadena)-1]='\0';
 if(cadena != NULL && size > 0 && fgets(cadena, size, stdin) == cadena)
 {
 retorno = 0;
 }
 return retorno;
 }
 */
//-----------------------------------------------GET STRING------------------------------------------------------------
int getString(char *string, int longitud) {
	int retorno = -1;
	//aprender memoria dinamica
	char bufferString[4096];

	if (string != NULL && longitud > 0) {
		fflush(stdin);

		if (fgets(bufferString, sizeof(bufferString), stdin) != NULL) {
			//si aca hay un salto de linea ponele un \0
			if (bufferString[strnlen(bufferString, sizeof(bufferString)) - 1]
					== '\n') {
				bufferString[strnlen(bufferString, sizeof(bufferString)) - 1] =
						'\0';
			}
			if (bufferString[0] == '\0') {
				return -1;
			}

			//si la longitud de la cadena a revisar es <= a la longitud deseada copiamos
			//el contenido
			if (strnlen(bufferString, sizeof(bufferString)) <= longitud) {
				strncpy(string, bufferString, longitud);
				retorno = 0;
			}
		}
	}
	return retorno;
}

static int getNombre(char *pResultado, int longitud) {
	int retorno = -1;
	char buffer[4096];

	if (pResultado != NULL) {
		if (getString(buffer, sizeof(buffer)) == 0
				&& esNombre(buffer, sizeof(buffer))
				&& strnlen(buffer, sizeof(buffer)) < longitud) {
			strncpy(pResultado, buffer, longitud);
			retorno = 0;
		}
	}
	return retorno;
}

int esNombre(char *cadena, int longitud) {
	int i = 0;
	int retorno = 1;

	if (cadena != NULL && longitud > 0) {
		for (i = 0; cadena[i] != '\0' && i < longitud; i++) {
			if ((cadena[i] < 'A' || cadena[i] > 'Z')
					&& (cadena[i] < 'a' || cadena[i] > 'z')) {
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

int utn_getString(char *mensaje, char *mensajeError, int reintentos,
		int longitud, char *pResultado) {
	char bufferString[4096];
	int retorno = -1;
	while (reintentos >= 0) {
		reintentos--;
		printf("%s", mensaje);
		if (getNombre(bufferString, sizeof(bufferString)) == 0
				&& strnlen(bufferString, sizeof(bufferString)) < longitud) {
			strncpy(pResultado, bufferString, longitud);
			retorno = 0;
			break;
		}
		printf("%s", mensajeError);
	}
	return retorno;
}

int esTexto(char *string, int longitud) {
	int i = 0;
	int retorno = 1;
	if (string != NULL && longitud > 0) {
		for (i = 0; string[i] != '\0' && i < longitud; i++) {
			if (string[i] < 32 || string[i] > 126) {

				retorno = 0;
				break;
			}
		}

	}
	return retorno;
}

int getTexto(char *pResultado, int longitud) {
	int retorno = -1;
	char buffer[4096];

	if (pResultado != NULL) {
		if (getString(buffer, sizeof(buffer)) == 0
				&& esTexto(buffer, sizeof(buffer))
				&& strnlen(buffer, sizeof(buffer)) < longitud)

				{
			strncpy(pResultado, buffer, longitud);
			retorno = 0;
		}
	}
	return retorno;
}

int utn_getTexto(char *mensaje, char *mensajeError, int reintentos,
		int longitud, char *pResultado) {
	char buffer[4096];
	int retorno = -1;
	while (reintentos >= 0) {
		reintentos--;
		printf("%s", mensaje);
		if (getTexto(buffer, sizeof(buffer)) == 0
				&& strnlen(buffer, sizeof(buffer)) <= longitud) {
			strncpy(pResultado, buffer, longitud);
			retorno = 0;
			break;
		}
		printf("%s", mensajeError);
	}
	return retorno;

}

int elegirPosicion(char *posicionIngresada) {
	int rtn = -1;
	char posicion[50];
	int flag = 0;

	if (utn_getString("Ingrese posicion de jugador: ", "Error.", 9000000, 50,
			posicion) == 0) {
		do {
			if (strcmp(posicion, "delantero") == 0
					|| strcmp(posicion, "mediocampista") == 0
					|| strcmp(posicion, "defensor") == 0
					|| strcmp(posicion, "arquero") == 0) {
				flag = 1;
				rtn = 0;
				strcpy(posicionIngresada, posicion);
			} else {
				utn_getString("Posicion no encontrada. Ingrese otra: ",
						"Error.", 9000000, 50, posicion);

			}
		} while (flag == 0);

	}

	return rtn;
}


int inicializarArray(int array[],int TAM)
{
	int rtn=-1;
	if(array!=NULL && TAM>0)
	{
		for(int i=0;i<TAM;i++)
		{
			array[i]=0;
		}
		rtn=1;
	}

	return rtn;
}

/*int elegirEquipo(char *equipoIngresado) {
	int rtn = -1;
	char equipo[50];
	int flag = 0;
	int contArgentina = 0;
	int contBrasil = 0;
	int contUruguay = 0;
	int contColombia = 0;
	int contEcuador = 0;

	if (utn_getString(
			"Ingrese descripcion (Nombre del equipo) (argentina, brasil, uruguay, colombia o ecuador): ",
			"Error.", 9000000, 50, equipo) == 0) {
		do {
			if (strcmp(equipo, "argentina") == 0 && contArgentina < 11) {
				flag = 1;
				rtn = 0;
				strcpy(equipoIngresado, equipo);
				contArgentina++;
			} else {
				if (strcmp(equipo, "brasil") == 0 && contBrasil < 11) {
					flag = 1;
					rtn = 0;
					strcpy(equipoIngresado, equipo);
					contBrasil++;
				} else {
					if (strcmp(equipo, "uruguay") == 0 && contUruguay < 11) {
						flag = 1;
						rtn = 0;
						strcpy(equipoIngresado, equipo);
						contUruguay++;
					} else {

						if (strcmp(equipo, "colombia") == 0
								&& contColombia < 11) {
							flag = 1;
							rtn = 0;
							strcpy(equipoIngresado, equipo);
							contColombia++;
						} else {
							if (strcmp(equipo, "ecuador") == 0
									&& contEcuador < 11) {
								flag = 1;
								rtn = 0;
								strcpy(equipoIngresado, equipo);
								contEcuador++;
							} else {
								utn_getString(
										"Equipo no encontrado o ya ingreso 11 figuritas. Ingrese otro: ",
										"Error.", 9000000, 50, equipo);
							}
						}
					}
				}
			}
		} while (flag == 0);

	}

	return rtn;
}
*/

int isValidNombre(char *pBuffer, int limite)
{
    int retorno = 0;
    int cantidadEspacios = 0;
    int i;
    if( pBuffer != NULL && limite > 0 && strlen(pBuffer) > 0 &&
        pBuffer[0]>='A' && pBuffer[0]<='Z')

    {
        retorno = 1;
        for(i=1; i < limite && pBuffer[i] != '\0'; i++)
        {
            if(pBuffer[i]==' ' && cantidadEspacios == 0)
            {
                cantidadEspacios++;
            }
            else if(!(pBuffer[i] >= 'a' && pBuffer[i] <= 'z' && pBuffer[i-1] != ' ') &&
                    !(pBuffer[i] >= 'A' && pBuffer[i] <= 'Z' && pBuffer[i-1] == ' '))
            {
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

int utn_getNombre(char *pNombre, int limite, char *mensaje,
                    char *mensajeError, int reintentos)
{
    int retorno=-1;
    char buffer[4096];
    if( pNombre != NULL && limite > 0 && mensaje != NULL &&
        mensajeError != NULL && reintentos>=0)
    {
        do
        {
            reintentos--;
            printf("\n%s", mensaje);
            if( getString(buffer, limite) == 0 &&
                isValidNombre(buffer, limite))
            {
                strncpy(pNombre, buffer, limite);
                retorno = 0;
                break;
            }
            else
            {
                printf("\n%s", mensajeError);
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}

int isValidEntero(char *pBuffer, int limite)
{
    int retorno = 0;
    int i;
    if  ((pBuffer != NULL && limite > 0 && strlen(pBuffer) > 0) &&
        (pBuffer[0] == '-' || pBuffer[0] == '+' ||
        (pBuffer[0]>='0' && pBuffer[0]<='9')))
    {
        retorno = 1;
        for(i=1; i < limite && pBuffer[i] != '\0'; i++)
        {
            if (!(pBuffer[i]>='0' && pBuffer[i]<='9'))
            {
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}


//________________________________________________FUNCIONES__DE__USO______________________________________________________________

int calcular(float gastosHospedaje, float gastosTransporte, float gastosComida,
		int contJugadores, int contAfc, int contCaf, int contConcacaf,
		int contUefa, int contConmebol, int contOfc,
		float *pGastosMantenimiento, float *pPromedioCaf, float *pPromedioAfc,
		float *pPromedioConcacaf, float *pPromedioUefa,
		float *pPromedioConmebol, float *pPromedioOfc,
		float *pCostoMantenimientoAumento, float *pAumento) {
	int rtn = -1;

	float gastosMantenimiento;
	float promedioCaf;
	float promedioAfc;
	float promedioConcacaf;
	float promedioUefa;
	float promedioConmebol;
	float promedioOfc;
	float aumento;
	float gastoMantenimientoAumento;

	if (pGastosMantenimiento != NULL && pPromedioCaf != NULL
			&& pPromedioAfc != NULL && pPromedioConcacaf != NULL
			&& pPromedioUefa != NULL && pPromedioConmebol != NULL
			&& pPromedioOfc != NULL) {

		gastosMantenimiento = gastosTransporte + gastosComida + gastosHospedaje;
		*pGastosMantenimiento = gastosMantenimiento;

		//	printf("\nContcaf: %d\n", contCaf);
		//	printf("\ncont Jugadores: %d\n", contJugadores);

		promedioCaf = (float) contCaf / contJugadores;
		promedioAfc = (float) contAfc / contJugadores;
		promedioConcacaf = (float) contConcacaf / contJugadores;
		promedioUefa = (float) contUefa / contJugadores;
		promedioConmebol = (float) contConmebol / contJugadores;
		promedioOfc = (float) contOfc / contJugadores;

		*pPromedioCaf = promedioCaf;
		*pPromedioAfc = promedioAfc;
		*pPromedioConcacaf = promedioConcacaf;
		*pPromedioUefa = promedioUefa;
		*pPromedioConmebol = promedioConmebol;
		*pPromedioOfc = promedioOfc;

		if (promedioUefa > promedioCaf && promedioUefa > promedioAfc
				&& promedioUefa > promedioConcacaf
				&& promedioUefa > promedioConmebol
				&& promedioUefa > promedioOfc) {
			aumento = gastosMantenimiento * 35 / 100;
			gastoMantenimientoAumento = gastosMantenimiento + aumento;
			*pAumento = aumento;
			*pCostoMantenimientoAumento = gastoMantenimientoAumento;
		}

		rtn = 0;

	}

	return rtn;
}

void mostrarResultados(float gastosMantenimiento, float promedioCaf,
		float promedioAfc, float promedioConcacaf, float promedioUefa,
		float promedioConmebol, float promedioOfc) {

	printf(
			"\n\n+--------------------------------------+------------------------------+\n");
	printf(
			"| Promedio de jugadores de AFC        -->                 %-7.2f     |\n",
			promedioAfc);
	printf(
			"|                                                                     |\n");
	printf(
			"| Promedio de jugadores de CAF        -->                 %-7.2f     |\n",
			promedioCaf);
	printf(
			"|                                                                     |\n");
	printf(
			"| Promedio de jugadores de Concacaf   -->                 %-7.2f     |\n",
			promedioConcacaf);
	printf(
			"|                                                                     |\n");
	printf(
			"| Promedio de jugadores de UEFA       -->                 %-7.2f     |\n",
			promedioUefa);
	printf(
			"|                                                                     |\n");
	printf(
			"| Promedio de jugadores de CONMEBOL   -->                 %-7.2f     |\n",
			promedioConmebol);
	printf(
			"|                                                                     |\n");
	printf(
			"| Promedio de jugadores de OFC        -->                 %-7.2f     |\n",
			promedioOfc);
	printf(
			"|                                                                     |\n");
	printf(
			"| Costo de mantenimiento              -->                 $%-7.2f    |\n",
			gastosMantenimiento);
	printf(
			"|                                                                     |\n");
	printf(
			"| No se aplicaron aumentos.                                           |\n");
	printf(
			"+--------------------------------------+------------------------------+\n");

}

void mostrarResultadosConAumento(float gastosMantenimiento, float promedioCaf,
		float promedioAfc, float promedioConcacaf, float promedioUefa,
		float promedioConmebol, float promedioOfc,
		float gastosMantenimientoAumentado, float aumento) {

	printf(
			"\n\n+--------------------------------------+------------------------------+\n");
	printf(
			"| Promedio de jugadores de AFC        -->                 %-7.2f     |\n",
			promedioAfc);
	printf(
			"|                                                                     |\n");
	printf(
			"| Promedio de jugadores de CAF        -->                 %-7.2f     |\n",
			promedioCaf);
	printf(
			"|                                                                     |\n");
	printf(
			"| Promedio de jugadores de Concacaf   -->                 %-7.2f     |\n",
			promedioConcacaf);
	printf(
			"|                                                                     |\n");
	printf(
			"| Promedio de jugadores de UEFA       -->                 %-7.2f     |\n",
			promedioUefa);
	printf(
			"|                                                                     |\n");
	printf(
			"| Promedio de jugadores de CONMEBOL   -->                 %-7.2f     |\n",
			promedioConmebol);
	printf(
			"|                                                                     |\n");
	printf(
			"| Promedio de jugadores de OFC        -->                 %-7.2f     |\n",
			promedioOfc);
	printf(
			"|                                                                     |\n");
	printf(
			"| Costo de mantenimiento              -->                 $%-7.2f    |\n",
			gastosMantenimiento);
	printf(
			"|                                                                     |\n");
	printf(
			"| Recibio un aumento de               -->                 $%-7.2f    |\n",
			aumento);
	printf(
			"|                                                                     |\n");
	printf(
			"| Su nuevo valor es de                -->                 $%-7.2f    |\n",
			gastosMantenimientoAumentado);
	printf(
			"+--------------------------------------+------------------------------+\n");
}

/*int isDescription(char *string, int len) {
	int i = 0;
	int ret = 0;
	if (string != NULL && strlen(string) > 0) {
		while (string[i] != '\0') {
			if ((string[i] < 'a' || string[i] > 'z') && (string[i] < 'A' || string[i] > 'Z')) {
				if(string[i] != ' ')
				{
					ret = -1;
					break;
				}

			}
			i++;
		}
	}
	return ret;
}
*/

