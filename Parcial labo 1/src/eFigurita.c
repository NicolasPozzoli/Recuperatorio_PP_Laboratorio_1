/*
 * eFigurita.c
 *
 *  Created on: 5 oct. 2022
 *      Author: Nicolas
 */


#include "eFigurita.h"

/**
* \brief Evalua si se trata de una cadena solo de letras
* \param pBuffer Es la cadena que evaluamos
* \param limite Es el tamano maximo del string
* \return En caso de exito retorna 1, si no 0
*
*/

/// @brief Genera un id que se incrementa
///
/// @return  Retorna el id incrementado


 int eFigurita_ObtenerID(void) {
	//ID AUTOINCREMENTAL - PRIVADO / GLOBAL
	//INICIALIZADO UNA UNICA VEZ AL COMIENZO DEL PROGRAMA CON ALCANCE UNICAMENTE EN FUNCION eFigurita_ObtenerID();
	static int Gen_idIncremental = 0;
	return Gen_idIncremental++;
}


/// @brief
///
/// @param array Es el array de figuritas a incializar
/// @param TAM	Es el tamaño maximo del array
///
void eFigurita_Inicializar(eFigurita array[], int TAM) {
	int i;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//SET ESTADO DE "LIBRE"
			array[i].isEmpty = LIBRE;
		}
	}
}


/// @brief Busca en el array un index libre
///
/// @param array Es el array a recorrer
/// @param TAM  Es el tamaño maximo del array
/// @return  En caso de exito retorna el index encontrado y en caso de error -1
///
int eFigurita_ObtenerIndexLibre(eFigurita array[], int TAM) {
	int rtn = -1;
	int i;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//PREGUNTO POR EL ESTADO "LIBRE"
			if (array[i].isEmpty == LIBRE) {
				//OBTENGO EL PRIMER INDEX DEL VECTOR "LIBRE" Y SALGO
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}


/// @brief Busca en el array por id
///
/// @param array Es el array a recorrer
/// @param TAM  Es el tamaño maximo del array
///  @param ID  Es el ID a buscar
/// @return  En caso de exito retorna el index encontrado y en caso de error -1
///

int eFigurita_BuscarPorID(eFigurita array[], int TAM, int ID) {
	int rtn = -1;
	int i;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//BUSCO QUE ESTE "OCUPADO" Y QUE CONCIDA EL ID QUE ESTOY BUSCANDO
			if (array[i].idFigurita == ID && array[i].isEmpty == OCUPADO) {
				//SI ENCONTRE EL ID
				//DEVUELVO EL INDEX DE DONDE ESTA EL ID BUSCADO Y SALGO
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}

/// @brief Muestra un auxiliar de figurita
///
/// @param Gen Es el auxiliar a mostrar
///
///
///

void eFigurita_MostrarUno(eFigurita Gen) {
	//PRINTF DE UN SOLO Gen
	printf("%5d\n", Gen.idFigurita);
}

/// @brief Muestra todos los datos ocupados
///
/// @param array Es el array a recorrer
/// @param TAM  Es el tamaño maximo del array
/// @return  En caso de exito retorna 1 y en caso de error -1
///
int eFigurita_MostrarTodos(eFigurita array[], int TAM) {
	int i;
	int rtn = 0;
	int cantidad = 0;

	//CABECERA
	puts("\n\t> LISTADO Gen");
	printf("%5s\n\n", "ID"); //AGREGAR TITULOS DE COLUMNA (QUITAR DE VER QUE NO ES NECESARIO)

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//PREGUNTO POR SU ESTADO "OCUPADO"
			if (array[i].isEmpty == OCUPADO) {
				//MUESTRO UN SOLO Gen
				eFigurita_MostrarUno(array[i]);
				//CONTADOR DE Gen
				cantidad++;
			}
		}
	}

	//SI CANTIDAD == 0 - NO HUBO Gen PARA MOSTRAR (ARRAY SIN ALTAS)
	if (cantidad > 0) {
		rtn = 1;
	}

	return rtn;
}

int eFigurita_MostrarDadosDeBaja(eFigurita array[], int TAM) {
	int i;
	int rtn = 0;
	int cantidad = 0;

	//CABECERA
	puts("\t> Gen\n");
	printf("%5s\n\n", "ID"); //AGREGAR TITULOS DE COLUMNA (QUITAR DE VER QUE NO ES NECESARIO)

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//PREGUNTO POR SU ESTADO "BAJA"
			if (array[i].isEmpty == BAJA) {
				//MUESTRO UN SOLO Gen
				eFigurita_MostrarUno(array[i]);
				//CONTADOR DE Gen
				cantidad++;
			}
		}
	}

	//SI CANTIDAD == 0 - NO HUBO Gen PARA MOSTRAR (ARRAY SIN BAJAS)
	if (cantidad > 0) {
		rtn = 1;
	}

	return rtn;
}

eFigurita eFigurita_CargarDatos(void) {
	eFigurita auxiliar;
	/** CARGAR DATOS NECESARIOS PARA EL ALTA*/
	/** IMPORTANTE - NO CARGAR ID NI ESTADO - SE HACE EN EL ALTA */
	if(elegirPosicion(auxiliar.posicion)==0
			&& utn_getNombre(auxiliar.nombreJugador, MAX_CHARS_CADENAS, "Ingrese nombre de jugador: ",  "Error.", 9000000) == 0
					&& utn_getFloat("Ingrese altura: ", "Error.", 1, 2, 9000000,
							&auxiliar.altura) == 0
					&& utn_getFloat("Ingrese peso: ", "Error.", 40, 180, 9000000,
							&auxiliar.peso) == 0
					&& utn_getNumero("Ingrese anio de ingreso a la seleccion: ",
							"Error.", 1980, 2022, 9000000, &auxiliar.anioIngreso) == 0
					&& getFecha(auxiliar.fechaNacimiento, MAX_CHARS_CADENAS, "Ingrese fecha de nacimiento: ", "Error.", 9000000)== 0)
	{
		puts("DATOS CARGADO CON EXITO.");
	}else
	{
		puts("Error al cargar Datos. /n");

	}


	return auxiliar;
}

eFigurita eFigurita_ModificarUno(eFigurita Figurita) {
	eFigurita auxiliar = Figurita;
	int opcModificar;
	/** MODIFICAR DATOS NECESARIOS PARA EL "MODIFICAR" */
	/** IMPORTANTE - MODIFICAR EL AUXILIAR QUE ES LA COPIA DEL ORIGINAL */

	if(utn_getNumero("\nMODIFICAR FIGURITA DATOS JUGADOR.\n"
				     "\n1. Nombre\n"
				     "\n2. Posicion\n"
				     "\n3. Altura."
				     "\n4. Peso.\n"
				     "\n5. Anio de ingreso.\n"
				     "\n6. Nacimiento.\n"
				     "\nElija opcion a modificar: \n", "Error. Opcion no valida.", 0, 7, 9000000, &opcModificar)==0)
	{
		switch(opcModificar)
		{
		case 1:
			if(utn_getString("Ingrese nombre de jugador: ", "Error.", 9000000,
						MAX_CHARS_CADENAS, auxiliar.nombreJugador) == 0)
			{
				puts("DATOS MODIFICADOS CORRECTAMENTE.");
			}
			break;
		case 2:
			if(elegirPosicion(auxiliar.posicion) == 0)
			{
				puts("DATOS MODIFICADOS CORRECTAMENTE.");
			}
			break;
		case 3:
			if(utn_getFloat("Ingrese altura: ", "Error.", 1, 2, 9000000,
					&auxiliar.altura) == 0)
			{
				puts("DATOS MODIFICADOS CORRECTAMENTE.");
			}
			break;
		case 4:
			if(utn_getFloat("Ingrese peso: ", "Error.", 40, 180, 9000000,
					&auxiliar.peso) == 0)
			{
				puts("DATOS MODIFICADOS CORRECTAMENTE.");
			}
			break;
		case 5:
			if(utn_getNumero("Ingrese anio de ingreso a la seleccion: ",
					"Error.", 0, 1000, 9000000, &auxiliar.anioIngreso) == 0)
			{
				puts("DATOS MODIFICADOS CORRECTAMENTE.");
			}
			break;
		case 6:
			if(getFecha(auxiliar.fechaNacimiento, MAX_CHARS_CADENAS, "Ingrese fecha de nacimiento: ", "Error.", 9000000)== 0)
			{
				puts("DATOS MODIFICADOS CORRECTAMENTE.");
			}
			break;
		case 0:
			break;


		}
	}


	return auxiliar;
}

int eFigurita_Alta(eFigurita array[], int TAM) {
	int rtn = 0;
	eFigurita auxGen;

	//BUSCO ESPACIO EN ARRAY
	int index = eFigurita_ObtenerIndexLibre(array, TAM);

	//SI INDEX == -1 ARRAY LLENO
	//SI INDEX != -1 TENGO EN INDEX POSICION DE ARRAY LIBRE
	if (index != -1) {
		//PIDO DATOS - CARGO Gen AUXILIAR
		auxGen = eFigurita_CargarDatos();
		//SETEO ID UNICO - VARIABLE ESTATICA AUTOINCREMENTAL
		auxGen.idFigurita = eFigurita_ObtenerID();
		//CAMBIO SU ESTADO A "OCUPADO"
		auxGen.isEmpty = OCUPADO;
		//SETEO EL ARRAY CON AUXILIAR EN INDEX LIBRE OBTENIDO PREVIAMENTE
		array[index] = auxGen;

		//RETORNO 1 PARA SABER QUE FUE DADO DE ALTA SATISFACTORIAMENTE
		rtn = 1;
	}

	return rtn;
}

int eFigurita_Baja(eFigurita array[], int TAM) {
	int rtn = 0;
	int idGen;
	int index;
	int flag = 0;

	//LISTO TODOS LOS Gen
	if (eFigurita_MostrarTodos(array, TAM)) {
		//BANDERA EN 1 SI HAY Gen DADOS DE ALTA PARA LISTAR
		flag = 1;
	}

	//SI HAY Gen PARA DAR DE BAJA
	if (flag) {
		//PIDO ID A DAR DE BAJA
		/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
		printf("INGRESE ID A DAR DE BAJA: ");
		scanf("%d", &idGen);

		//BUSCO INDEX POR ID EN ARRAY
		while (eFigurita_BuscarPorID(array, TAM, idGen) == -1) {
			puts("NO EXISTE ID.");

			/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
			printf("INGRESE ID A DAR DE BAJA: ");
			scanf("%d", &idGen);
		}

		//OBTENGO INDEX DEL ARRAY DE Gen A DAR DE BAJA
		index = eFigurita_BuscarPorID(array, TAM, idGen);

		/**PREGUNTAR SI DESEA CONTINUAR*/
		//BAJA ACEPTADA - CAMBIO ESTADO A "BAJA"
		array[index].isEmpty = BAJA;

		//RETORNO 1 SI SE DIO DE BAJA CORRECTAMENTE
		rtn = 1;
	}

	return rtn;
}

int eFigurita_Modificacion(eFigurita array[], int TAM) {
	int rtn = 0;
	int idGen;
	int index;
	int flag = 0;
	eFigurita auxiliar;

	//LISTO TODOS LOS Gen
	if (eFigurita_MostrarTodos(array, TAM)) {
		//BANDERA EN 1 SI HAY Gen DADOS DE ALTA PARA LISTAR
		flag = 1;
	}

	//SI HAY Gen PARA MODIFICAR
	if (flag) {
		//PIDO ID A MODIFICAR
		/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
		printf("INGRESE ID A DAR DE BAJA: ");
		scanf("%d", &idGen);

		//BUSCO INDEX POR ID EN ARRAY
		while (eFigurita_BuscarPorID(array, TAM, idGen) == -1) {
			puts("NO EXISTE ID.");

			/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
			printf("INGRESE ID A DAR DE BAJA: ");
			scanf("%d", &idGen);
		}

		//OBTENGO INDEX DEL ARRAY DE Gen A MODIFICAR
		index = eFigurita_BuscarPorID(array, TAM, idGen);

		//LLAMO A FUNCION QUE MODIFICA Gen
		auxiliar = eFigurita_ModificarUno(array[index]);

		/**PREGUNTAR SI DESEA CONTINUAR*/
		//MODIFICACION ACEPTADA
		array[index] = auxiliar;

		//RETORNO 1 SI SE MODIFICO CORRECTAMENTE
		rtn = 1;
	}

	return rtn;
}

int eFigurita_Sort(eFigurita array[], int TAM, int criterio) {
	int rtn = 0;
	int i;
	int j;
	//eFigurita aux;

	/** EJEMPLO DE SORT CON ID DE Figurita
	 MODIFICAR "CRITERIO DE ORDENAMIENTO" PARA OTROS CASOS DE ORDENAMIENTO
	 CASE -1 -> MENOR A MAYOR (ASCENDENTE)
	 CASE  1 -> MAYOR A MENOR (DESCENDENTE)

	 UTILIZAR strcmp(...) PARA COMPARAR CADENAS
	 */

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		switch (criterio) {
		case -1:
			for (i = 0; i < TAM - 1; i++) {
				for (j = i + 1; j < TAM; j++) {
					//PREGUNTO POR ESTADO "OCUPADO" DE AMBOS
					if (array[i].isEmpty == OCUPADO
							&& array[j].isEmpty == OCUPADO) {
						//CRITERIO DE ORDENAMIENTO
					/*	if (strcmp(array[i].equipo , array[j].equipo)==1) {
							//INTERCAMBIO POSICIONES EN ARRAY
							aux=array[i];
							array[i] = array[j];
							array[j] = aux;

						}
						*/
					}
				}
			}
			rtn = 1;
			break;
		case 1:
			for (i = 0; i < TAM - 1; i++) {
				for (j = i + 1; j < TAM; j++) {
					//PREGUNTO POR ESTADO "OCUPADO" DE AMBOS
					if (array[i].isEmpty == OCUPADO
							&& array[j].isEmpty == OCUPADO) {
						//CRITERIO DE ORDENAMIENTO
			/*			if(strcmp(array[i].equipo , array[j].equipo)==-1) {
							//INTERCAMBIO POSICIONES EN ARRAY
							aux=array[i];
							array[i] = array[j];
							array[j] = aux;
						}
						*/
					}
				}
			}
			rtn = 1;
			break;
		default:
			//CRITERIO DE ORDENAMIENTO MAL INGRESADO
			rtn = 0;
			break;
		}
	}
	return rtn;
}

int isValidFecha(int dia, int mes, int anio)
{
    int retorno = 0;
    if(dia > 0 && mes > 0 &&  anio > 0)
    {
        if(((mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12) &&
                (dia > 0 && dia <= 31)) ||
                ((mes == 4 || mes == 6 || mes == 9 || mes == 11) &&
                 (dia > 0 && dia <= 30)) ||
                ((mes == 2 && (anio % 4) == 0) &&
                 (dia > 0 && dia <= 29)) ||
                ((mes == 2 && (anio % 4) != 0) &&
                 (dia > 0 && dia <= 28)))
        {
            retorno = 1;
        }
    }
    return retorno;
}

int getFecha(eFecha *pFecha, int limite, char *mensaje,
                    char *mensajeError, int reintentos)
{
    int retorno=-1;
    int bufferDia;
    int bufferMes;
    int bufferAnio;
    eFecha auxFecha;

    if( pFecha != NULL && limite >= 11 && mensaje != NULL &&
        mensajeError != NULL && reintentos>=0)
    {
        do
        {
            reintentos--;
            printf("\n%s", mensaje);
            printf("\nIntroduzca Dia(dd): ");
            if( utn_getNumero("", "Error. Ingrese dia valido: ", 1, 30, 9000000, &bufferDia) == 0)
            {
                auxFecha.dia =bufferDia;
            }
            else
            {
                continue;
            }
            printf("\nIntroduzca Mes(mm): ");
            if( utn_getNumero("", "Error. Ingrese mes valido: ", 1, 12, 9000000, &bufferMes) == 0)
            {
            	auxFecha.mes = bufferMes;
            }
            else
            {
                continue;
            }
            printf("\nIntroduzca Anio(aaaa): ");
            if(utn_getNumero("", "Error. Ingrese anio valido: ", 1900, 2022, 9000000, &bufferAnio) == 0)
            {
            	auxFecha.anio =bufferAnio;
            }
            else
            {
                continue;
            }
            if (isValidFecha(bufferDia, bufferMes, bufferAnio))
            {
                retorno = 0;
                *pFecha=auxFecha;
                break;
            }
            else
            {
                printf("%s", mensajeError);
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}
