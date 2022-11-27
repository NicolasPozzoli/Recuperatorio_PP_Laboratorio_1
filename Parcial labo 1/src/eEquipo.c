/*
 * eEquipo.c
 *
 *  Created on: 5 oct. 2022
 *      Author: Nicolas
 */

#include "eEquipo.h"


int elegirEquipo(char *equipoIngresado) {
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




int eEquipo_ObtenerID(void) {
	//ID AUTOINCREMENTAL - PRIVADO / GLOBAL
	//INICIALIZADO UNA UNICA VEZ AL COMIENZO DEL PROGRAMA CON ALCANCE UNICAMENTE EN FUNCION eEquipo_ObtenerID();
	static int Gen_idIncremental = 0;
	return Gen_idIncremental++;
}

void eEquipo_Inicializar(eEquipo array[], int TAM) {
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

int eEquipo_ObtenerIndexLibre(eEquipo array[], int TAM) {
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

int eEquipo_BuscarPorID(eEquipo array[], int TAM, int ID) {
	int rtn = -1;
	int i;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//BUSCO QUE ESTE "OCUPADO" Y QUE CONCIDA EL ID QUE ESTOY BUSCANDO
			if (array[i].idEquipo == ID && array[i].isEmpty == OCUPADO) {
				//SI ENCONTRE EL ID
				//DEVUELVO EL INDEX DE DONDE ESTA EL ID BUSCADO Y SALGO
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}

void eEquipo_MostrarUno(eEquipo Figurita) {
	//PRINTF DE UN SOLO Gen
	printf("%5d\n", Figurita.idEquipo);
}

int eEquipo_MostrarTodos(eEquipo array[], int TAM) {
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
				eEquipo_MostrarUno(array[i]);
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

int eEquipo_MostrarDadosDeBaja(eEquipo array[], int TAM) {
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
				eEquipo_MostrarUno(array[i]);
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

eEquipo eEquipo_CargarDatos(void) {
	eEquipo auxiliar;
	/** CARGAR DATOS NECESARIOS PARA EL ALTA*/
	/** IMPORTANTE - NO CARGAR ID NI ESTADO - SE HACE EN EL ALTA */
	if(elegirEquipo(auxiliar.descripcion)==0
			&& utn_getNombre(auxiliar.directorTecnico, MAX_CHARS_CADENAS, "Ingrese Director Tecnico: ", "Error.", 9000000)==0)
	{
		puts("Datos cargados correctamente");
	}
	return auxiliar;
}

eEquipo eEquipo_ModificarUno(eEquipo equipo) {
	eEquipo auxiliar = equipo;
	int opc;

	if(utn_getNumero("\nMODIFICAR FIGURITA DATOS EQUIPO\n\n"
				     "1.Descripcion(nombre)\n"
				     "2.DT\n"
				     "\nElija opcion: \n", "Error.", 1, 2, 9000000, &opc)==0)
	{
		switch(opc)
		{
		case 1:
			if(elegirEquipo(auxiliar.descripcion)==0)
			{
				puts("Modificado Correctamente.");
			}else
			{
				puts("Modificado Incorrectamente.");
			}
			break;
		case 2:
			if(utn_getString("Ingrese Director Tecnico: ", "Error.\n", 9000000, MAX_CHARS_CADENAS, auxiliar.directorTecnico)==0)
			{
				puts("Modificado Correctamente.");
			}else
			{
				puts("Modificado Incorrectamente.");
			}
			break;
		}

	}
	return auxiliar;
}

int eEquipo_Alta(eEquipo array[], int TAM) {
	int rtn = 0;
	eEquipo auxGen;

	//BUSCO ESPACIO EN ARRAY
	int index = eEquipo_ObtenerIndexLibre(array, TAM);

	//SI INDEX == -1 ARRAY LLENO
	//SI INDEX != -1 TENGO EN INDEX POSICION DE ARRAY LIBRE
	if (index != -1) {
		//PIDO DATOS - CARGO Gen AUXILIAR
		auxGen = eEquipo_CargarDatos();
		//SETEO ID UNICO - VARIABLE ESTATICA AUTOINCREMENTAL
		auxGen.idEquipo = eEquipo_ObtenerID();
		//CAMBIO SU ESTADO A "OCUPADO"
		auxGen.isEmpty = OCUPADO;
		//SETEO EL ARRAY CON AUXILIAR EN INDEX LIBRE OBTENIDO PREVIAMENTE
		array[index] = auxGen;

		//RETORNO 1 PARA SABER QUE FUE DADO DE ALTA SATISFACTORIAMENTE
		rtn = 1;
	}

	return rtn;
}

int eEquipo_Baja(eEquipo array[], int TAM) {
	int rtn = 0;
	int idGen;
	int index;
	int flag = 0;

	//LISTO TODOS LOS Gen
	if (eEquipo_MostrarTodos(array, TAM)) {
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
		while (eEquipo_BuscarPorID(array, TAM, idGen) == -1) {
			puts("NO EXISTE ID.");

			/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
			printf("INGRESE ID A DAR DE BAJA: ");
			scanf("%d", &idGen);
		}

		//OBTENGO INDEX DEL ARRAY DE Gen A DAR DE BAJA
		index = eEquipo_BuscarPorID(array, TAM, idGen);

		/**PREGUNTAR SI DESEA CONTINUAR*/
		//BAJA ACEPTADA - CAMBIO ESTADO A "BAJA"
		array[index].isEmpty = BAJA;

		//RETORNO 1 SI SE DIO DE BAJA CORRECTAMENTE
		rtn = 1;
	}

	return rtn;
}

int eEquipo_Modificacion(eEquipo array[], int TAM) {
	int rtn = 0;
	int idGen;
	int index;
	int flag = 0;
	eEquipo auxiliar;

	//LISTO TODOS LOS Gen
	if (eEquipo_MostrarTodos(array, TAM)) {
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
		while (eEquipo_BuscarPorID(array, TAM, idGen) == -1) {
			puts("NO EXISTE ID.");

			/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
			printf("INGRESE ID A DAR DE BAJA: ");
			scanf("%d", &idGen);
		}

		//OBTENGO INDEX DEL ARRAY DE Gen A MODIFICAR
		index = eEquipo_BuscarPorID(array, TAM, idGen);

		//LLAMO A FUNCION QUE MODIFICA Gen
		auxiliar = eEquipo_ModificarUno(array[index]);

		/**PREGUNTAR SI DESEA CONTINUAR*/
		//MODIFICACION ACEPTADA
		array[index] = auxiliar;

		//RETORNO 1 SI SE MODIFICO CORRECTAMENTE
		rtn = 1;
	}

	return rtn;
}

int eEquipo_Sort(eEquipo array[], int TAM, int criterio) {
	int rtn = 0;
	int i;
	int j;
	eEquipo aux;

	/** EJEMPLO DE SORT CON ID DE Gen
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
						if (array[i].idEquipo > array[j].idEquipo) {
							//INTERCAMBIO POSICIONES EN ARRAY
							aux = array[i];
							array[i] = array[j];
							array[j] = aux;
						}
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
						if (array[i].idEquipo < array[j].idEquipo) {
							//INTERCAMBIO POSICIONES EN ARRAY
							aux = array[i];
							array[i] = array[j];
							array[j] = aux;
						}
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



