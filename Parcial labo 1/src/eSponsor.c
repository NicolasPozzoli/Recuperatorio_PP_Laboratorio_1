#include "eSponsor.h"

int eSponsor_ObtenerID(void) {
	//ID AUTOINCREMENTAL - PRIVADO / GLOBAL
	//INICIALIZADO UNA UNICA VEZ AL COMIENZO DEL PROGRAMA CON ALCANCE UNICAMENTE EN FUNCION eSponsor_ObtenerID();
	static int Sponsor_idIncremental = 0;
	return Sponsor_idIncremental++;
}

void eSponsor_Inicializar(eSponsor array[], int TAM) {
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



int eSponsor_ObtenerIndexLibre(eSponsor array[], int TAM) {
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

int eSponsor_BuscarPorID(eSponsor array[], int TAM, int ID) {
	int rtn = -1;
	int i;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//BUSCO QUE ESTE "OCUPADO" Y QUE CONCIDA EL ID QUE ESTOY BUSCANDO
			if (array[i].idSponsor == ID && array[i].isEmpty == OCUPADO) {
				//SI ENCONTRE EL ID
				//DEVUELVO EL INDEX DE DONDE ESTA EL ID BUSCADO Y SALGO
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}

void eSponsor_MostrarUno(eSponsor Sponsor) {
	//PRINTF DE UN SOLO Sponsor
	printf("%5d\n", Sponsor.idSponsor);
}

int eSponsor_MostrarTodos(eSponsor array[], int TAM) {
	int i;
	int rtn = 0;
	int cantidad = 0;

	//CABECERA
	puts("\n\t> LISTADO Sponsor");
	printf("%5s\n\n", "ID"); //AGREGAR TITULOS DE COLUMNA (QUITAR DE VER QUE NO ES NECESARIO)

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//PREGUNTO POR SU ESTADO "OCUPADO"
			if (array[i].isEmpty == OCUPADO) {
				//MUESTRO UN SOLO Sponsor
				eSponsor_MostrarUno(array[i]);
				//CONTADOR DE Sponsor
				cantidad++;
			}
		}
	}

	//SI CANTIDAD == 0 - NO HUBO Sponsor PARA MOSTRAR (ARRAY SIN ALTAS)
	if (cantidad > 0) {
		rtn = 1;
	}

	return rtn;
}

int eSponsor_MostrarDadosDeBaja(eSponsor array[], int TAM) {
	int i;
	int rtn = 0;
	int cantidad = 0;

	//CABECERA
	puts("\t> Sponsor\n");
	printf("%5s\n\n", "ID"); //AGREGAR TITULOS DE COLUMNA (QUITAR DE VER QUE NO ES NECESARIO)

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//PREGUNTO POR SU ESTADO "BAJA"
			if (array[i].isEmpty == BAJA) {
				//MUESTRO UN SOLO Sponsor
				eSponsor_MostrarUno(array[i]);
				//CONTADOR DE Sponsor
				cantidad++;
			}
		}
	}

	//SI CANTIDAD == 0 - NO HUBO Sponsor PARA MOSTRAR (ARRAY SIN BAJAS)
	if (cantidad > 0) {
		rtn = 1;
	}

	return rtn;
}

eSponsor eSponsor_CargarDatos(void) {
	eSponsor auxiliar;
	int opcion;
	float precio;


		if(elegirSponsor(auxiliar.descripcion)==0 &&
			utn_getFloat("Ingrese el precio que quiere cobrar por el sponsor: ", "Error.", 0, 1000000, 9000000, &precio)==0)
		{
				auxiliar.precio=precio;
		}
	return auxiliar;
}

eSponsor eSponsor_ModificarUno(eSponsor Sponsor) {
	eSponsor auxiliar = Sponsor;
	int opc;

	if(utn_getNumero("\nMODIFICAR FIGURITA DATOS SPONSOR\n\n"
				     "1.Descripcion(nombre)\n"
				     "2.Precio\n"
				     "\nElija opcion: \n", "Error.", 1, 2, 9000000, &opc)==0)
	{
		switch(opc)
		{
		case 1:
			if(elegirSponsor(auxiliar.descripcion)==0)
			{
				puts("Modificado Correctamente.");
			}else
			{
				puts("Modificado Incorrectamente.");
			}
			break;
		case 2:
			if(utn_getFloat("Ingrese el precio que quiere cobrar por el sponsor: ", "Error.", 0, 1000000, 9000000, &auxiliar.precio)==0)
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

int eSponsor_Alta(eSponsor array[], int TAM) {
	int rtn = 0;
	eSponsor auxSponsor;

	//BUSCO ESPACIO EN ARRAY
	int index = eSponsor_ObtenerIndexLibre(array, TAM);

	//SI INDEX == -1 ARRAY LLENO
	//SI INDEX != -1 TENGO EN INDEX POSICION DE ARRAY LIBRE
	if (index != -1) {
		//PIDO DATOS - CARGO Sponsor AUXILIAR
		auxSponsor = eSponsor_CargarDatos();
		//SETEO ID UNICO - VARIABLE ESTATICA AUTOINCREMENTAL
		auxSponsor.idSponsor = eSponsor_ObtenerID();
		//CAMBIO SU ESTADO A "OCUPADO"
		auxSponsor.isEmpty = OCUPADO;
		//SETEO EL ARRAY CON AUXILIAR EN INDEX LIBRE OBTENIDO PREVIAMENTE
		array[index] = auxSponsor;

		//RETORNO 1 PARA SABER QUE FUE DADO DE ALTA SATISFACTORIAMENTE
		rtn = 1;
	}

	return rtn;
}

int eSponsor_Baja(eSponsor array[], int TAM) {
	int rtn = 0;
	int idSponsor;
	int index;
	int flag = 0;

	//LISTO TODOS LOS Sponsor
	if (eSponsor_MostrarTodos(array, TAM)) {
		//BANDERA EN 1 SI HAY Sponsor DADOS DE ALTA PARA LISTAR
		flag = 1;
	}

	//SI HAY Sponsor PARA DAR DE BAJA
	if (flag) {
		//PIDO ID A DAR DE BAJA
		/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
		printf("INGRESE ID A DAR DE BAJA: ");
		scanf("%d", &idSponsor);

		//BUSCO INDEX POR ID EN ARRAY
		while (eSponsor_BuscarPorID(array, TAM, idSponsor) == -1) {
			puts("NO EXISTE ID.");

			/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
			printf("INGRESE ID A DAR DE BAJA: ");
			scanf("%d", &idSponsor);
		}

		//OBTENGO INDEX DEL ARRAY DE Sponsor A DAR DE BAJA
		index = eSponsor_BuscarPorID(array, TAM, idSponsor);

		/**PREGUNTAR SI DESEA CONTINUAR*/
		//BAJA ACEPTADA - CAMBIO ESTADO A "BAJA"
		array[index].isEmpty = BAJA;

		//RETORNO 1 SI SE DIO DE BAJA CORRECTAMENTE
		rtn = 1;
	}

	return rtn;
}

int eSponsor_Modificacion(eSponsor array[], int TAM) {
	int rtn = 0;
	int idSponsor;
	int index;
	int flag = 0;
	eSponsor auxiliar;

	//LISTO TODOS LOS Sponsor
	if (eSponsor_MostrarTodos(array, TAM)) {
		//BANDERA EN 1 SI HAY Sponsor DADOS DE ALTA PARA LISTAR
		flag = 1;
	}

	//SI HAY Sponsor PARA MODIFICAR
	if (flag) {
		//PIDO ID A MODIFICAR
		/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
		printf("INGRESE ID A DAR DE BAJA: ");
		scanf("%d", &idSponsor);

		//BUSCO INDEX POR ID EN ARRAY
		while (eSponsor_BuscarPorID(array, TAM, idSponsor) == -1) {
			puts("NO EXISTE ID.");

			/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
			printf("INGRESE ID A DAR DE BAJA: ");
			scanf("%d", &idSponsor);
		}

		//OBTENGO INDEX DEL ARRAY DE Sponsor A MODIFICAR
		index = eSponsor_BuscarPorID(array, TAM, idSponsor);

		//LLAMO A FUNCION QUE MODIFICA Sponsor
		auxiliar = eSponsor_ModificarUno(array[index]);

		/**PREGUNTAR SI DESEA CONTINUAR*/
		//MODIFICACION ACEPTADA
		array[index] = auxiliar;

		//RETORNO 1 SI SE MODIFICO CORRECTAMENTE
		rtn = 1;
	}

	return rtn;
}

int eSponsor_Sort(eSponsor array[], int TAM, int criterio) {
	int rtn = 0;
	int i;
	int j;
	eSponsor aux;

	/** EJEMPLO DE SORT CON ID DE Sponsor
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
						if (array[i].idSponsor > array[j].idSponsor) {
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
						if (array[i].idSponsor < array[j].idSponsor) {
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

int elegirSponsor(char* pSponsorIngresado)
{
	int rtn=-1;
	int opcion;
	char sponsor[10][40]={" ","Nike","Adidas","New balance","Puma","Kappa","Umbro","Castore","Etihad",
					"Chevrolet"};

		if(utn_getNumero("\n Sponsors.\n\n"
						 "1. Nike.\n"
						 "2. Adidas.\n"
						 "3. New balance.\n"
						 "4. Puma.\n"
						 "5. Kappa.\n"
						 "6. Umbro.\n"
						 "7. Castore.\n"
						 "8. Etihad.\n"
						 "9. Chevrolet.\n"
						 "Elija sponsor: ", "Error. ", 1, 9,9000000, &opcion)==0)
		{
			for (int i = 0; i < 15; i++) {

				if(i==opcion)
				{
					strcpy(pSponsorIngresado,sponsor[i]);
				}
			}
			rtn=0;
		}

	return rtn;
}
