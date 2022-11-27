/*
 * Figurita_Equipo.c
 *
 *  Created on: 5 oct. 1622
 *      Author: Nicolas
 */
#include "eFigurita.h"
#include "eEquipo.h"
#include "Input.h"
#include "eAlbum.h"
#include "eSponsor.h"

/// @brief  Da de alta una figurita y un equipo
///
/// @param array  Es el array de figuritas a dar de alta
/// @param TAM Es el tamaño maximo del array de figuritas
/// @param arrayEquipo  Es el array de equipo a dar de alta
/// @param TAMequipo	Es el tamaño maximo del array de equipo
/// @return  Retorna 1 en caso de exito y -1 en caso de error

int eFigurita_Alta_Equipo_Sponsor(eFigurita array[], int TAM,eEquipo arrayEquipo[], int TAMequipo,eSponsor arraySponsor[], int TAMsponsor) {
	int rtn = 0;
	eFigurita auxFigurita;
	eEquipo auxEquipo;
	eSponsor auxSponsor;

	//BUSCO ESPACIO EN ARRAY
	int indexFigurita = eFigurita_ObtenerIndexLibre(array, TAM);
	int indexEquipo = eEquipo_ObtenerIndexLibre(arrayEquipo, TAMequipo);
	int indexSponsor = eSponsor_ObtenerIndexLibre(arraySponsor, TAMsponsor);

	//SI INDEX == -1 ARRAY LLENO
	//SI INDEX != -1 TENGO EN INDEX POSICION DE ARRAY LIBRE
	if (indexFigurita != -1
			&& indexEquipo != -1
			&& indexSponsor != -1) {
		//PIDO DATOS - CARGO Gen AUXILIAR


		auxFigurita = eFigurita_CargarDatos();

		auxFigurita.idFigurita = eFigurita_ObtenerID();

		auxFigurita.isEmpty = OCUPADO;

		array[indexFigurita] = auxFigurita;

			auxEquipo = eEquipo_CargarDatos();
			//SETEO ID UNICO - VARIABLE ESTATICA AUTOINCREMENTAL

			auxEquipo.idEquipo = eEquipo_ObtenerID();


			auxFigurita.idEquipo=auxEquipo.idEquipo;
			//CAMBIO SU ESTADO A "OCUPADO"


			auxEquipo.isEmpty = OCUPADO;

			arrayEquipo[indexEquipo] = auxEquipo;


			auxSponsor = eSponsor_CargarDatos();

			auxSponsor.idSponsor = eSponsor_ObtenerID();

			auxSponsor.isEmpty = OCUPADO;

			auxFigurita.idSponsor=auxSponsor.idSponsor;

			arraySponsor[indexSponsor] = auxSponsor;

		//SETEO EL ARRAY CON AUXILIAR EN INDEX LIBRE OBTENIDO PREVIAMENTE



		//RETORNO 1 PARA SABER QUE FUE DADO DE ALTA SATISFACTORIAMENTE
		rtn = 1;
	}


	return rtn;
}

/// @brief  Lista el array con datos asignados
///
/// @param array  Es el array de figuritas a mostrar
/// @param TAM		Es el tamaño maximo del array de figuritas
/// @param arrayEquipo Es el array de equipo a mostrar
/// @param TAMequipo  Es el tamaño maximo del array de equipo
/// @return  Retorna 1 en caso de exito y -1 en caso de error
int Mostrar_Figuritas_Equipos(eFigurita array[], int TAM,eEquipo arrayEquipo[], int TAMequipo) {
	int i;
	int rtn = 0;
	int cantidad = 0;
	int indexDelEquipo;

	//CABECERA
	puts("\n\t LISTADO DE FIGURITAS");
	printf("%16s  %16s  %16s  %16s  %16s  %16s  %16s  %16s  %16s \n\n", "ID","NOMBRE","POSICION",
			"EQUIPO","ALTURA","PESO","INGRESO","NACIMIENTO", "DT"); //AGREGAR TITULOS DE COLUMNA (QUITAR DE VER QUE NO ES NECESARIO)

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//PREGUNTO POR SU ESTADO "OCUPADO"
			if (array[i].isEmpty == OCUPADO) {

				//MUESTRO UN SOLO Gen
				indexDelEquipo=eEquipo_BuscarPorID(arrayEquipo, TAMequipo,arrayEquipo[i].idEquipo);

				if(indexDelEquipo!=-1)
				{

					printf("%16d  %16s  %16s  %16s  %16.2f  %16.2f  %16d  %9d/%d/%d  %16s\n", array[i].idFigurita,array[i].nombreJugador,array[i].posicion,
							arrayEquipo[indexDelEquipo].descripcion,array[i].altura,array[i].peso,array[i].anioIngreso,array[i].fechaNacimiento->dia,
							array[i].fechaNacimiento->mes,array[i].fechaNacimiento->anio,arrayEquipo[indexDelEquipo].directorTecnico);
				}else
				{
				//	printf("%16d  %16s  %16s  %16s  %16.2f  %16.2f  %16d  %16s  %16s\n", array[i].idFigurita,array[i].nombreJugador,array[i].posicion,
					//		arrayEquipo[indexDelEquipo].descripcion,array[i].altura,array[i].peso,array[i].anioIngreso,array[i].fechaNacimiento,arrayEquipo[indexDelEquipo].directorTecnico);
	//BORRAR
				}
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


int Mostrar_Figuritas_Equipos_Sponsor(eFigurita array[], int TAM,eEquipo arrayEquipo[], int TAMequipo,eSponsor arraySponsor[], int TAMsponsor) {
	int i;
	int rtn = 0;
	int cantidad = 0;
	int indexDelEquipo;
	int indexDelSponsor;

	//CABECERA
	puts("\n\t LISTADO DE FIGURITAS");
	printf("%16s  %16s  %16s  %16s  %16s  %16s  %16s  %16s  %16s  %16s \n\n", "ID","NOMBRE","POSICION",
			"EQUIPO","ALTURA","PESO","INGRESO","NACIMIENTO", "DT","Sponsor(Nuevo)"); //AGREGAR TITULOS DE COLUMNA (QUITAR DE VER QUE NO ES NECESARIO)

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//PREGUNTO POR SU ESTADO "OCUPADO"
			if (array[i].isEmpty == OCUPADO) {

				//MUESTRO UN SOLO Gen
				indexDelEquipo=eEquipo_BuscarPorID(arrayEquipo, TAMequipo,arrayEquipo[i].idEquipo);
				indexDelSponsor=eSponsor_BuscarPorID(arraySponsor, TAMsponsor,arraySponsor[i].idSponsor);
				if(indexDelEquipo!=-1)
				{

					printf("%16d  %16s  %16s  %16s  %16.2f  %16.2f  %16d  %9d/%d/%d  %16s  %16s\n", array[i].idFigurita,array[i].nombreJugador,array[i].posicion,
							arrayEquipo[indexDelEquipo].descripcion,array[i].altura,array[i].peso,array[i].anioIngreso,array[i].fechaNacimiento->dia,
							array[i].fechaNacimiento->mes,array[i].fechaNacimiento->anio,arrayEquipo[indexDelEquipo].directorTecnico,arraySponsor[indexDelSponsor].descripcion);
				}else
				{
				//	printf("%16d  %16s  %16s  %16s  %16.2f  %16.2f  %16d  %16s  %16s\n", array[i].idFigurita,array[i].nombreJugador,array[i].posicion,
					//		arrayEquipo[indexDelEquipo].descripcion,array[i].altura,array[i].peso,array[i].anioIngreso,array[i].fechaNacimiento,arrayEquipo[indexDelEquipo].directorTecnico);
	//BORRAR
				}
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


/// @brief  Modifica los datos segun el id
///
/// @param array  Es el array de figuritas a modificar
/// @param TAM		Es el tamaño maximo del array de figuritas
/// @param arrayEquipo Es el array de equipo a modificar
/// @param TAMequipo  Es el tamaño maximo del array de equipo
/// @return  Retorna 1 en caso de exito y -1 en caso de error

int Modificar_Figuritas_Equipo(eFigurita array[], int TAM,eEquipo arrayEquipo[], int TAMequipo,eSponsor arraySponsor[], int TAMsponsor) {
	int rtn = 0;
	int idFigurita;
	int index;
	int indexEquipo;
	int indexSponsor;
	int flag = 0;
	int opc;
	eFigurita auxiliar;
	eEquipo auxiliarEquipo;
	eSponsor auxiliarSponsor;
//	int opcMod;

	//LISTO TODOS LOS Gen
	if (Mostrar_Figuritas_Equipos_Sponsor(array, TAM, arrayEquipo, TAMequipo, arraySponsor, TAMsponsor)) {
		//BANDERA EN 1 SI HAY Gen DADOS DE ALTA PARA LISTAR
		flag = 1;
	}

	//SI HAY Gen PARA MODIFICAR
	if (flag) {
		//PIDO ID A MODIFICAR
		if(utn_getNumero("INGRESE ID A MODIFICAR: ", "Error.", 0, 55, 9000000, &idFigurita)==0)
		{
			//BUSCO INDEX POR ID EN ARRAY
			while (eFigurita_BuscarPorID(array, TAM, idFigurita) == -1) {
				puts("NO EXISTE ID.");


				utn_getNumero("INGRESE ID A MODIFICAR: ", "Error.", 0, 55, 9000000, &idFigurita);
			}

			//OBTENGO INDEX DEL ARRAY DE Gen A MODIFICAR
			index = eFigurita_BuscarPorID(array, TAM, idFigurita);

			indexEquipo=eEquipo_BuscarPorID(arrayEquipo, TAMequipo, array[index].idEquipo);
			indexSponsor=eSponsor_BuscarPorID(arraySponsor, TAMsponsor, array[index].idSponsor);


			if(utn_getNumero("\nMenu de modificar\n"
					"\n1.Modificar datos de jugador.\n"
					"\n2.Modificar datos de equipo.\n"
					"\n3.Modificar datos de sponsor.\n", "", 1, 3, 9000000, &opc)==0)
			{
				switch(opc)
				{
				case 1:
					auxiliar = eFigurita_ModificarUno(array[index]);
					array[index] = auxiliar;
					break;
				case 2:
					auxiliarEquipo = eEquipo_ModificarUno(arrayEquipo[indexEquipo]);
					arrayEquipo[indexEquipo] = auxiliarEquipo;
					break;
				case 3:
					auxiliarSponsor = eSponsor_ModificarUno(arraySponsor[indexSponsor]);
					arraySponsor[indexSponsor] = auxiliarSponsor;
					break;
				}
			}
			//RETORNO 1 SI SE MODIFICO CORRECTAMENTE
			rtn = 1;
		}
		}



	return rtn;
}

int calcularGastoDeSobres(int* pGastoSobres)
{
	static int gasto=0;
	gasto=gasto+170;
	*pGastoSobres=gasto;
	return 1;
}



/// @brief  Recorre el array de figuritas y cuenta cuantas estan pegadas
///
/// @param array  Es el array de figuritas a recorrer
/// @param TAM		Es el tamaño maximo del array de id figuritas

/// @return  Retorna la cantidad de figuritas pegadas
///
int contarFiguritasPegadas(int arrayPegadas[],int TAM)
{
	int contador=0;
	int rtn=-1;

		for(int i=0;i<TAM;i++)
		{
			if(arrayPegadas[i]==1)
			{
				contador++;
				rtn=contador;
			}

		}
	return rtn;
}



///  @brief  Carga figuritas obtenidas en el album
///
/// @param array  Es el array de figuritas
/// @param TAM  Es el tamaño maximo del array de figuritas
/// @param arrayEquipo  Es el array de equipo
/// @param TAMequipo  Es el tamaño maximo del array de equipo
/// @param arrayAlbum  Es el array  de album
/// @param TAMAlbum  Es el tamaño maximo del array de album
/// @param cantidadFiguritas  Es la cantidad de figuritas
/// @param figuritasRepetidas  Es la cantidad de figuritas repetidas
/// @param TAMrepetidas  Es el tamaño maximo de figuritas repetidas
/// @param gastoSobres  Es el gasto en sobres
/// @param pGastosHastaCompletarAlbum  Es el gasto que se realizo en completar el album
/// @param pFiguritasPegadas  Cantidad de figuritas pegadas
/// @param pCantidadSobres		Cantidad de sobres abiertos
/// @return   retorna 0

int cargarFiguritasEnAlbum(eFigurita array[], int TAM,eEquipo arrayEquipo[], int TAMequipo,eAlbum album,
		int cantidadFiguritas,int figuritasRepetidas[],int TAMrepetidas,int *gastoSobres,int* pGastosHastaCompletarAlbum,int *pFiguritasPegadas,int *pCantidadSobres,int arrayFiguritasPegadas[],int TAMpegadas)
{
	int idFigu;
	int index;
	static int contadorFiguritas=0;
	static int gastoHastaCompletarAlbum=0;
	int figuritasPegadas;
	static int contadorSobres=0;

	if(array!=NULL && arrayEquipo!=NULL && TAM>0 && TAMequipo>0)
	{
		puts("Te tocaron las siguientes figuritas");
		for(int i=0;i<5;i++)
		{
			idFigu=rand()%cantidadFiguritas;
			contadorFiguritas++;
			index=eFigurita_BuscarPorID(array, TAM, idFigu);

			printf("%s\n",array[index].nombreJugador);

			if(album.idFigurita[index]!=array[index].idFigurita)
			{
				album.idFigurita[index]=array[index].idFigurita;
				album.isEmpty[index]=OCUPADO;
				arrayFiguritasPegadas[index]=1;

			}else
			{
				figuritasRepetidas[index]++;
				if(album.idFigurita[index]==array[index].idFigurita)
				{

					printf("\nLa figurita %s es repetida\n",array[index].nombreJugador);
				}
			}

		}
		if(contadorFiguritas%50==0)   //si es igual a 50 es dorada
		{
			album.esDorada[index]=DORADA;
			printf("\nTe salio en dorado: %s\n",array[index].nombreJugador);
		}

		calcularGastoDeSobres(gastoSobres);

		figuritasPegadas=contarFiguritasPegadas(arrayFiguritasPegadas, TAM);
		if(figuritasPegadas==54)
		{
			puts("Ya se completo el album");
			*pGastosHastaCompletarAlbum=gastoHastaCompletarAlbum;
			*pCantidadSobres=contadorSobres;

		}else
		{
			gastoHastaCompletarAlbum=gastoHastaCompletarAlbum+170;
			contadorSobres++;
		}

		*pFiguritasPegadas=figuritasPegadas;
	}
	return 0;
}



int mostrarRepetidasConID(eFigurita array[], int TAM,eEquipo arrayEquipo[], int TAMequipo,int arrayFiguritasRepetidas[],int TAMrepetidas)
{
	int i;
	int rtn = 0;
	int cantidad = 0;
	int indexEquipo;



		//CABECERA
		puts("\n\t> LISTADO DE FIGURITAS REPETIDAS");
		printf("%16s  %16s  %16s  %16s  \n\n","ID","NOMBRE",
				"EQUIPO","CANTIDAD"); //AGREGAR TITULOS DE COLUMNA (QUITAR DE VER QUE NO ES NECESARIO)

		//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
		if (array != NULL && TAM > 0) {
			//RECORRO TODO EL ARRAY
			for (i = 0; i < TAM; i++) {
				//PREGUNTO POR SU ESTADO "OCUPADO"
				if (array[i].isEmpty == OCUPADO) {

					indexEquipo=eEquipo_BuscarPorID(arrayEquipo, TAMequipo, arrayEquipo[i].idEquipo);
					//MUESTRO UN SOLO Figurita
				if(arrayFiguritasRepetidas[i]>0)
				{
					printf("%16d  %16s  %16s  %16d  \n\n",array[i].idFigurita,array[i].nombreJugador,
							arrayEquipo[indexEquipo].descripcion,arrayFiguritasRepetidas[i]);

				}
					//CONTADOR DE Figurita
					cantidad++;
				}
			}


		//SI CANTIDAD == 0 - NO HUBO Figurita PARA MOSTRAR (ARRAY SIN ALTAS)
		if (cantidad > 0) {
			rtn = 1;
		}


	}

	return rtn;
}

///  @brief  Intercambia figuritas
///
/// @param array  Es el array de figuritas
/// @param TAM  Es el tamaño maximo del array de figuritas
/// @param arrayEquipo  Es el array de equipo
/// @param TAMequipo  Es el tamaño maximo del array de equipo
/// @param arrayAlbum  Es el array  de album
/// @param TAMAlbum  Es el tamaño maximo del array de album
/// @param arrayRepetidas  Es el array de figuritas repetidas
/// @param TAMrepetidas  Es el tamaño maximo de figuritas repetidas

/// @return   retorna 0

int intercambiarFiguritas(eFigurita array[],int TAM,eEquipo arrayEquipo[], int TAMequipo,eAlbum album, int TAMalbum,int arrayRepetidas[],int TAMrepetidas)
{
	int id;
	int index;
	int idRepetida;
	int indexRepetida;
//	int aux;

	//eFigurita_MostrarTodos(array, TAM);

	Mostrar_Figuritas_Equipos(array, TAM, arrayEquipo, TAMequipo);

	if(utn_getNumero("\nIngrese ID de la figurita que desea adquirir: ", "Error.", 0, 54, 9000000, &id)==0)
	{

		index=eFigurita_BuscarPorID(array, TAM, id);

		if(index!=-1)
		{
			printf("\nDesea adquirir a %s:\n",array[index].nombreJugador);

			//MOSTRAR REPETIDAS
			mostrarRepetidasConID(array, TAM, arrayEquipo, TAMequipo, arrayRepetidas, TAMrepetidas);

			if(utn_getNumero("\nIngrese ID de la figurita que vas a intercambiar: ", "Error.", 0, 54, 9000000, &idRepetida)==0)
			{
				indexRepetida=eFigurita_BuscarPorID(array, TAM, idRepetida);

				if(indexRepetida!=-1)
				{
					if(arrayRepetidas[indexRepetida]>0)
					{
						arrayRepetidas[indexRepetida]=arrayRepetidas[indexRepetida]-1;
						album.idFigurita[index]=array[index].idFigurita;
					//	arrayAlbum[index].isEmpty=OCUPADO;

					}else
					{
						puts("No tenes esa figurita");
					}

				}else
				{
					puts("No existe esa figurita.");
				}

			}
		}else
		{
			puts("No existe esa figurita.");
		}




	}
	return 0;
}

/// @brief Lista las repetidas del array
///
/// @param array  Es el array de figuritas
/// @param TAM  Es el tamaño maximo del array de figuritas
/// @param arrayEquipo  Es el array de equipo
/// @param TAMequipo  Es el tamaño maximo del array de equipo
/// @param arrayFiguritasRepetidas  Es el array de figuritas repetidas
/// @param TAMrepetidas  Es el tamaño maximo del array de repetidas
/// @return  retorna 1 si mostro y -1 si no mostro

int mostrarRepetidas(eFigurita array[], int TAM,eEquipo arrayEquipo[], int TAMequipo,int arrayFiguritasRepetidas[],int TAMrepetidas)
{
	int i;
	int rtn = -1;
	int cantidad = 0;
	int indexEquipo;



		//CABECERA
		puts("\n\t> LISTADO DE FIGURITAS REPETIDAS");
		printf("%16s  %16s  %16s  \n\n","NOMBRE",
				"EQUIPO","CANTIDAD"); //AGREGAR TITULOS DE COLUMNA (QUITAR DE VER QUE NO ES NECESARIO)

		//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
		if (array != NULL && TAM > 0) {
			//RECORRO TODO EL ARRAY
			for (i = 0; i < TAM; i++) {
				//PREGUNTO POR SU ESTADO "OCUPADO"
				if (array[i].isEmpty == OCUPADO) {

					indexEquipo=eEquipo_BuscarPorID(arrayEquipo, TAMequipo, arrayEquipo[i].idEquipo);
					//MUESTRO UN SOLO Figurita
				if(arrayFiguritasRepetidas[i]>0)
				{
					printf("%16s  %16s  %16d  \n\n",array[i].nombreJugador,
							arrayEquipo[indexEquipo].descripcion,arrayFiguritasRepetidas[i]);

				}
					//CONTADOR DE Figurita
					cantidad++;
				}
			}


		//SI CANTIDAD == 0 - NO HUBO Figurita PARA MOSTRAR (ARRAY SIN ALTAS)
		if (cantidad > 0) {
			rtn = 1;
		}


	}

	return rtn;
}


/// @brief Lista las pegadas del array
///
/// @param array  Es el array de figuritas
/// @param TAM  Es el tamaño maximo del array de figuritas
/// @param arrayEquipo  Es el array de equipo
/// @param TAMequipo  Es el tamaño maximo del array de equipo
/// @param arrayAlbum Es el array de album
/// @param TAMalbum  Es el tamaño maximo del array de album
/// @return  retorna 1 si mostro y -1 si no mostro
///
int mostrarPegadas(eFigurita array[], int TAM,eEquipo arrayEquipo[], int TAMequipo,eAlbum album,int TAMalbum,int arrayPegadas[],int TAMpegadas)
{
	int i;
	int rtn = -1;
	int cantidad = 0;
	int indexEquipo;



		//CABECERA
		puts("\n\t> LISTADO DE FIGURITAS PEGADAS");
		printf("%16s  %16s  %16s  \n\n","NOMBRE",
				"EQUIPO","POSICION"); //AGREGAR TITULOS DE COLUMNA (QUITAR DE VER QUE NO ES NECESARIO)

		//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
		if (array != NULL && TAM > 0) {
			//RECORRO TODO EL ARRAY
			for (i = -1; i < TAM; i++) {
				//PREGUNTO POR SU ESTADO "OCUPADO"
				if (array[i].isEmpty == OCUPADO) {

					indexEquipo=eEquipo_BuscarPorID(arrayEquipo, TAMequipo, arrayEquipo[i].idEquipo);
					//MUESTRO UN SOLO Figurita
				if(arrayPegadas[i]>0)
				{
					printf("%16s  %16s  %16s  \n\n",array[i].nombreJugador,
							arrayEquipo[indexEquipo].descripcion,array[i].posicion);

				}
					//CONTADOR DE Figurita
					cantidad++;
				}
			}


		//SI CANTIDAD == 0 - NO HUBO Figurita PARA MOSTRAR (ARRAY SIN ALTAS)
		if (cantidad > 0) {
			rtn = 1;
		}


	}

	return rtn;
}

/// @brief  Busca en el array de figuritas segun el nombre del equipo
///
/// @param array  Es el array de figuritas
/// @param TAM  Es el tamaño maximo del array de figuritas
/// @param descripcion  Es el nombre del equipo a buscar
/// @param TAMdescripcion  Es el tamaño maximo del nombre del equipo
/// @return  Retorna el index en caso de exito y en caso de error -1

int eEquipo_BuscarPorDescripcion(eEquipo array[], int TAM, char descripcion[],int TAMdescripcion) {
	int rtn = -1;
	int i;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//BUSCO QUE ESTE "OCUPADO" Y QUE CONCIDA EL ID QUE ESTOY BUSCANDO
			if (array[i].isEmpty == OCUPADO) {

				if(strcmp(descripcion,array[i].descripcion)==0)
				{
					//SI ENCONTRE EL ID
					//DEVUELVO EL INDEX DE DONDE ESTA EL ID BUSCADO Y SALGO
					rtn = i;
					break;
				}

			}
		}
	}

	return rtn;
}

/// @brief   Lista el array de figuritas segun el equipo elegido
///
/// @param array  Es el array de figuritas
/// @param TAM  Es el tamaño maximo del array de figuritas
/// @param arrayEquipo  Es el array de equipo
/// @param TAMequipo  Es el tamaño maximo del array de equipo
/// @param arrayAlbum  Es el array de album
/// @param TAMalbum  Es el tamaño maximo del array de album
/// @return  Retorna 1 si mostro y -1 si no mostro
int listarPorEquipo(eFigurita array[], int TAM,eEquipo arrayEquipo[], int TAMequipo,eAlbum album,int TAMalbum)
{
	int i;
	int rtn = -1;
	int cantidad = 0;
	int indexEquipo;
	char equipoIngresado[MAX_CHARS_CADENAS];

	if(elegirEquipo(equipoIngresado)==0)
	{
		//CABECERA
		puts("\n\t> LISTADO DE FIGURITAS PEGADAS POR EQUIPO");
		printf("%16s  %16s  %16s  \n\n","NOMBRE",
				"EQUIPO","POSICION"); //AGREGAR TITULOS DE COLUMNA (QUITAR DE VER QUE NO ES NECESARIO)

		//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
		if (TAMalbum > 0) {

			//RECORRO TODO EL ARRAY
			for (i = 0; i < TAMalbum; i++) {

				//PREGUNTO POR SU ESTADO "OCUPADO"
				if (array[i].isEmpty==OCUPADO) {
					if(strcmp(arrayEquipo[i].descripcion,equipoIngresado)==0)
					{

						indexEquipo=eEquipo_BuscarPorID(arrayEquipo, TAMequipo, arrayEquipo[i].idEquipo);

						printf("\n%16s  %16s  %16s\n",array[i].nombreJugador,arrayEquipo[indexEquipo].descripcion,array[i].posicion);

						//MUESTRO UN SOLO Figurita
						//CONTADOR DE Figurita
						cantidad++;

					}


				}
			}


		//SI CANTIDAD == 0 - NO HUBO Figurita PARA MOSTRAR (ARRAY SIN ALTAS)
		if (cantidad > 0) {
			rtn = 1;
		}


	}else
	{
		puts("Error.");
	}

	}



	return rtn;
}


/// @brief  Lista las doradas del array de figuritas
///
/// @param array  Es el array de figuritas
/// @param TAM  Es el tamaño maximo del array de figuritas
/// @param arrayEquipo  Es el array de equipo
/// @param TAMequipo  Es el tamaño maximo del array de equipo
/// @param arrayAlbum  Es el array de album
/// @param TAMalbum  Es el tamaño maximo del array de album
/// @return Retorna 1 si mostro y -1 si no mostro
int listarDoradas(eFigurita array[], int TAM,eEquipo arrayEquipo[], int TAMequipo,eAlbum album,int TAMalbum)
{
	int i;
	int rtn = -1;
	int cantidad = 0;
	int indexEquipo;
//	char equipoIngresado[MAX_CHARS_CADENAS];

		//CABECERA
		puts("\n\t> LISTADO DE FIGURITAS DORADAS PEGADAS");
		printf("%16s  %16s  %16s  \n\n","NOMBRE",
				"EQUIPO","POSICION"); //AGREGAR TITULOS DE COLUMNA (QUITAR DE VER QUE NO ES NECESARIO)

		//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
		if (TAMalbum > 0) {

			//RECORRO TODO EL ARRAY
			for (i = 0; i < TAMalbum; i++) {

				//PREGUNTO POR SU ESTADO "OCUPADO"
				if  (array[i].isEmpty==OCUPADO
						&& album.esDorada[i]==DORADA) {


						indexEquipo=eEquipo_BuscarPorID(arrayEquipo, TAMequipo, arrayEquipo[i].idEquipo);


						printf("\n%16s  %16s  %16s\n",array[i].nombreJugador,arrayEquipo[indexEquipo].descripcion,array[i].posicion);

						//MUESTRO UN SOLO Figurita
						//CONTADOR DE Figurita
						cantidad++;




				}
			}


		//SI CANTIDAD == 0 - NO HUBO Figurita PARA MOSTRAR (ARRAY SIN ALTAS)
		if (cantidad > 0) {
			rtn = 1;
		}


	}else
	{
		puts("Error.");
	}





	return rtn;
}


/// @brief Ordena el array de figuritas segun el criterio
///
/// @param array  Es el array de equipo
/// @param TAM  Es el tamaño maximo del array de equipo
/// @param criterio  Es el criterio de busqueda. -1(menor a mayor) 1(mayor a menor).
/// @param arrayFigurita  Es el array de figurita
/// @param TAMfigurita  Es el tamaño maximo del array de figuritas
/// @return  Retorna 1 si pudo ordenar y si no -1
int eEquipo_SortFigurita(eEquipo array[], int TAM, int criterio,eFigurita arrayFigurita[], int TAMfigurita) {
	int rtn = 0;
	int i;
	int j;
//	eFigurita aux;


	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (arrayFigurita != NULL && TAMfigurita > 0) {
		switch (criterio) {
		case -1:
			for (i = 0; i < TAMfigurita - 1; i++) {
				for (j = i + 1; j < TAMfigurita; j++) {
					//PREGUNTO POR ESTADO "OCUPADO" DE AMBOS
					if (arrayFigurita[i].isEmpty == OCUPADO
							&& arrayFigurita[j].isEmpty == OCUPADO) {
						//CRITERIO DE ORDENAMIENTO
					/*	if (arrayFigurita[i].idEquipo>arrayFigurita[j].idEquipo) {
							//INTERCAMBIO POSICIONES EN ARRAY
							aux=arrayFigurita[i];
							arrayFigurita[i] = arrayFigurita[j];
							arrayFigurita[j] = aux;

						}*/

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




/*int hardCodeFiguritas(eFigurita arrayFigurita[], int len,int cantidad, int *pNextId)
{

	int rtn = -1;

	eFigurita aux[27]={{ 0, "Ronaldo Nazario", "Delantero", 1, 1.50, 70, 1990,23,1 },
			{0, "Lionel Messi", "Delantero", 2, 1.50, 70, 1990,23,1 },
	{ 0, "Neymar", "Delantero", 3, 1.50, 70, 1990,23,1 },
	{ 0, "Mbappe", "Delantero", 0, 1.50, 70, 1990,23,1 },
	{ 0, "Ronaldo Nazario", "Delantero", 0, 1.50, 70, 1990,23,1 },
	{ 0, "Lionel", "Delantero", 0, 1.50, 70, 1990,23,1 },
	{ 0, "Facundo", "Delantero", 0, 1.50, 70, 1990,23,1 },
	{ 0, "Pepe", "Delantero", 0, 1.50, 70, 1990,23,1 },
	{ 0, "Lolo", "Delantero", 0, 1.50, 70, 1990,23,1 },
	{ 0, "Ramos", "Delantero", 0, 1.50, 70, 1990,23,1 },
	{ 0, "Sirigliano", "Delantero", 0, 1.50, 70, 1990,23,1 }};
	if (arrayFigurita != NULL && pNextId != NULL && len > 0 && len <= 3000 && cantidad <= len)
	{
		for (int i = 0; i < cantidad; i++)
		{
			printf("\nnombre: %s\n",aux[i].nombreJugador);
			arrayFigurita[i] = aux[i];
			arrayFigurita[i].idFigurita = *pNextId;
			(*pNextId)++;
		}
		rtn = 1;
	}
	return rtn;

}


*/



int listarPorSponsor(eFigurita array[], int TAM,eEquipo arrayEquipo[], int TAMequipo,eAlbum album,int TAMalbum,eSponsor arraySponsor[],int TAMsponsor)
{
	int i;
	int rtn = -1;
	int cantidad = 0;
	int indexEquipo;
	int indexSponsor;
	char sponsorIngresado[MAX_CHARS_CADENAS];

	puts("Elija el sponsor que desea filtrar:");
	if(elegirSponsor(sponsorIngresado)==0)
	{
		//CABECERA
		printf("\n\t LISTADO DE FIGURITAS PEGADAS DE SPONSOR: %s\n",sponsorIngresado);
		printf("%16s  %16s  %16s  %16s  \n\n","NOMBRE",
				"EQUIPO","POSICION","SPONSOR"); //AGREGAR TITULOS DE COLUMNA (QUITAR DE VER QUE NO ES NECESARIO)

		//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
		if (TAMalbum > 0) {

			//RECORRO TODO EL ARRAY
			for (i = 0; i < TAMalbum; i++) {

				//PREGUNTO POR SU ESTADO "OCUPADO"
				if (array[i].isEmpty==OCUPADO) {
					if(strcmp(arraySponsor[i].descripcion,sponsorIngresado)==0)
					{

						indexEquipo=eEquipo_BuscarPorID(arrayEquipo, TAMequipo, arrayEquipo[i].idEquipo);
						indexSponsor=eSponsor_BuscarPorID(arraySponsor, TAMsponsor, arraySponsor[i].idSponsor);

						printf("\n%16s  %16s  %16s  %16s\n",array[i].nombreJugador,arrayEquipo[indexEquipo].descripcion,array[i].posicion,arraySponsor[indexSponsor].descripcion);

						//MUESTRO UN SOLO Figurita
						//CONTADOR DE Figurita
						cantidad++;

					}


				}
			}


		//SI CANTIDAD == 0 - NO HUBO Figurita PARA MOSTRAR (ARRAY SIN ALTAS)
		if (cantidad > 0) {
			rtn = 1;
		}


	}else
	{
		puts("Error.");
	}

	}



	return rtn;
}



