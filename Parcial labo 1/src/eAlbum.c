#include "eAlbum.h"

static int eAlbum_ObtenerID(void);
static int eAlbum_ObtenerID(void) {
	//ID AUTOINCREMENTAL - PRIVADO / GLOBAL
	//INICIALIZADO UNA UNICA VEZ AL COMIENZO DEL PROGRAMA CON ALCANCE UNICAMENTE EN FUNCION eAlbum_ObtenerID();
	static int Gen_idIncremental = 0;
	return Gen_idIncremental++;
}

int eAlbum_esPegada(eAlbum album, int tam,int indice)
{
	int rtn=-1;
	if(tam>0 && indice>=0)
	{
		if(album.idFigurita[indice]>=0 && album.idFigurita[indice]<=55)
		{
			rtn=1;
		}
	}
	return rtn;
}



void eAlbum_Inicializar(eAlbum array, int TAM) {
	int i;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//SET ESTADO DE "LIBRE"
			array.isEmpty[i] = LIBRE;
		}
	}
}

int eAlbum_ObtenerIndexLibre(eAlbum array[], int TAM) {
	int rtn = -1;
	int i;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//PREGUNTO POR EL ESTADO "LIBRE"
			if (array[i].isEmpty == OCUPADO) {
				//OBTENGO EL PRIMER INDEX DEL VECTOR "LIBRE" Y SALGO
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}

int eAlbum_BuscarPorID(eAlbum array[], int TAM, int ID) {
	int rtn = -1;
	int i;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//BUSCO QUE ESTE "OCUPADO" Y QUE CONCIDA EL ID QUE ESTOY BUSCANDO
			if (array[i].idGen == ID && array[i].isEmpty == OCUPADO) {
				//SI ENCONTRE EL ID
				//DEVUELVO EL INDEX DE DONDE ESTA EL ID BUSCADO Y SALGO
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}

void eAlbum_MostrarUno(eAlbum Gen) {
	//PRINTF DE UN SOLO Gen
	printf("%5d\n", Gen.idGen);
}

int eAlbum_MostrarTodos(eAlbum array[], int TAM) {
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
				eAlbum_MostrarUno(array[i]);
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

int eAlbum_MostrarDadosDeBAJA(eAlbum array[], int TAM) {
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
				eAlbum_MostrarUno(array[i]);
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

eAlbum eAlbum_CargarDatos(void) {
	eAlbum auxiliar;
	/** CARGAR DATOS NECESARIOS PARA EL ALTA*/
	/** IMPORTANTE - NO CARGAR ID NI ESTADO - SE HACE EN EL ALTA */
	return auxiliar;
}

eAlbum eAlbum_ModificarUno(eAlbum Gen) {
	eAlbum auxiliar = Gen;
	/** MODIFICAR DATOS NECESARIOS PARA EL "MODIFICAR" */
	/** IMPORTANTE - MODIFICAR EL AUXILIAR QUE ES LA COPIA DEL ORIGINAL */
	return auxiliar;
}

int eAlbum_Alta(eAlbum array[], int TAM) {
	int rtn = 0;
	eAlbum auxGen;

	//BUSCO ESPACIO EN ARRAY
	int index = eAlbum_ObtenerIndexLibre(array, TAM);

	//SI INDEX == -1 ARRAY LLENO
	//SI INDEX != -1 TENGO EN INDEX POSICION DE ARRAY LIBRE
	if (index != -1) {
		//PIDO DATOS - CARGO Gen AUXILIAR
		auxGen = eAlbum_CargarDatos();
		//SETEO ID UNICO - VARIABLE ESTATICA AUTOINCREMENTAL
		auxGen.idGen = eAlbum_ObtenerID();
		//CAMBIO SU ESTADO A "OCUPADO"
	//	auxGen.isEmpty = OCUPADO;
		//SETEO EL ARRAY CON AUXILIAR EN INDEX LIBRE OBTENIDO PREVIAMENTE
		array[index] = auxGen;

		//RETORNO 1 PARA SABER QUE FUE DADO DE ALTA SATISFACTORIAMENTE
		rtn = 1;
	}

	return rtn;
}

int eAlbum_BAJA(eAlbum array[], int TAM) {
	int rtn = 0;
	int idGen;
	int index;
	int flag = 0;

	//LISTO TODOS LOS Gen
	if (eAlbum_MostrarTodos(array, TAM)) {
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
		while (eAlbum_BuscarPorID(array, TAM, idGen) == -1) {
			puts("NO EXISTE ID.");

			/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
			printf("INGRESE ID A DAR DE BAJA: ");
			scanf("%d", &idGen);
		}

		//OBTENGO INDEX DEL ARRAY DE Gen A DAR DE BAJA
		index = eAlbum_BuscarPorID(array, TAM, idGen);

		/**PREGUNTAR SI DESEA CONTINUAR*/
		//BAJA ACEPTADA - CAMBIO ESTADO A "BAJA"
	//	array.isEmpty[index] = BAJA;

		//RETORNO 1 SI SE DIO DE BAJA CORRECTAMENTE
		rtn = 1;
	}

	return rtn;
}

int eAlbum_Modificacion(eAlbum array[], int TAM) {
	int rtn = 0;
	int idGen;
	int index;
	int flag = 0;
	eAlbum auxiliar;

	//LISTO TODOS LOS Gen
	if (eAlbum_MostrarTodos(array, TAM)) {
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
		while (eAlbum_BuscarPorID(array, TAM, idGen) == -1) {
			puts("NO EXISTE ID.");

			/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
			printf("INGRESE ID A DAR DE BAJA: ");
			scanf("%d", &idGen);
		}

		//OBTENGO INDEX DEL ARRAY DE Gen A MODIFICAR
		index = eAlbum_BuscarPorID(array, TAM, idGen);

		//LLAMO A FUNCION QUE MODIFICA Gen
		auxiliar = eAlbum_ModificarUno(array[index]);

		/**PREGUNTAR SI DESEA CONTINUAR*/
		//MODIFICACION ACEPTADA
		array[index] = auxiliar;

		//RETORNO 1 SI SE MODIFICO CORRECTAMENTE
		rtn = 1;
	}

	return rtn;
}

int eAlbum_Sort(eAlbum array[], int TAM, int criterio) {
	int rtn = 0;
	int i;
	int j;
	eAlbum aux;

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
						if (array[i].idGen > array[j].idGen) {
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
						if (array[i].idGen < array[j].idGen) {
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
