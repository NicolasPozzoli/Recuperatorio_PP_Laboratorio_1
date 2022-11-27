/*
 ============================================================================
 Name        : Parcial.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Input.h"
#include "eEquipo.h"
#include "eFigurita.h"
#include "eAlbum.h"
#include "eSponsor.h"
#include "Figurita_Equipo_Sponsor.h"

#define TAM 55
#define MAX_TAM_EQUIPOS 55
#define MAX_TAM_SPONSOR 10

int main(void) {
	setbuf(stdout,NULL);
	int opcAdmin;
	int flagAlta=0;
	int flagAbrioSobre=0;
	int opc;
	int opcInformes=0;
	int gastoHastaCompletarAlbum=0;
	int gastoSobres;
	int figuritasPegadas;
	int cantidadSobres;


	eFigurita arrayFiguritas[TAM];
	eEquipo equipo[MAX_TAM_EQUIPOS];
	eAlbum album;
	int arrayRepetidas[TAM];
	int arrayPegadas[TAM];

	eSponsor arraySponsor[MAX_TAM_SPONSOR];         //NUEVO

	eAlbum_Inicializar(album, TAM);
	eFigurita_Inicializar(arrayFiguritas, TAM);
	eEquipo_Inicializar(equipo, MAX_TAM_EQUIPOS);
	inicializarArray(arrayRepetidas, TAM);
	inicializarArray(arrayPegadas, TAM);
	eSponsor_Inicializar(arraySponsor, MAX_TAM_SPONSOR);

//	hardCodeFiguritas(arrayFiguritas, TAM,11, &pNextId);

	do {
		if (utn_getNumero("\n1. Perfil de Administrador\n"
						"\n2 .Perfil de comprador.\n"
						"\n3 .Informes.\n"
						"\n0. SALIR\n"
						"Elija opcion: ", "Error. Opcion no valida", 0, 3, 9000000, &opc)
						== 0) {
			switch(opc)
			{
			case 1:
				if (utn_getNumero("\nPerfil de Administrador\n"
						"\n1.ALTA FIGURITA\n"
						"\n2.MODIFICAR FIGURITA\n"
						"\n3.LISTAR FIGURITA\n"
						"\n0. SALIR\n"
						"Elija opcion: ", "Error. Opcion no valida", 0, 3, 9000000, &opcAdmin)
						== 0) {

					switch (opcAdmin) {
					case 1:
						if (eFigurita_Alta_Equipo_Sponsor(arrayFiguritas, TAM, equipo, MAX_TAM_EQUIPOS,arraySponsor, MAX_TAM_SPONSOR) == 1) {

							puts("DADO DE ALTA CORRECTAMENTE.");
							flagAlta=1;


						} else {
							puts("DADO DE ALTA INCORRECTAMENTE.");
						}
						break;
					case 2:
						if(flagAlta==1 && Modificar_Figuritas_Equipo(arrayFiguritas, TAM, equipo, MAX_TAM_EQUIPOS,arraySponsor, MAX_TAM_SPONSOR))
						{

							puts("MODIFICADO CORRECTAMENTE.");

						} else {
							puts("MODIFICADO INCORRECTAMENTE.");
						}
						break;
					case 3:
						if(flagAlta==1 && eEquipo_SortFigurita(equipo, MAX_TAM_EQUIPOS, -1, arrayFiguritas, TAM)==1
								&& Mostrar_Figuritas_Equipos(arrayFiguritas, TAM, equipo, MAX_TAM_EQUIPOS)==1)
						{
							puts("Mostrados Correctamente.");
							Mostrar_Figuritas_Equipos_Sponsor(arrayFiguritas, TAM, equipo, MAX_TAM_EQUIPOS, arraySponsor, MAX_TAM_SPONSOR);
						}else
						{
							puts("Error al mostrar.");
						}
						break;
					case 0:
						break;

					}

				}

				break;
			case 2:
				if (utn_getNumero("\nPerfil de Coleccionista\n"
						"\n1. Comprar un paquete de figuritas\n"
						"\n2. Intercambiar figuritas\n"
						"\n0. SALIR\n"
						"Elija opcion: ", "Error. Opcion no valida", 0, 2, 9000000, &opcAdmin)
						== 0) {

					switch (opcAdmin) {
					case 1:
						if(flagAlta==1)
						{
							cargarFiguritasEnAlbum(arrayFiguritas, TAM, equipo, MAX_TAM_EQUIPOS, album, 1,arrayRepetidas,TAM,&gastoSobres,&gastoHastaCompletarAlbum,&figuritasPegadas,&cantidadSobres,arrayPegadas,TAM);
							flagAbrioSobre=1;
						}else
						{
							puts("No hay figuritas creadas");
						}
						break;
					case 2:
						if(flagAlta==1)
						{
							intercambiarFiguritas(arrayFiguritas, TAM, equipo, MAX_TAM_EQUIPOS, arrayRepetidas, TAM);
						}else
						{
							puts("No hay figuritas creadas");
						}
						break;
					case 0:
						break;
					}

				}
				break;
			case 3:
				if (flagAbrioSobre==1 &&
						utn_getNumero("\nINFORMES\n"
										"\n1. Listar figuritas pegadas\n"
										"\n2. Listar figuritas repetidas\n"
										"\n3. Listar figuritas doradas\n"
										"\n4. Sobres comprados para completar el album\n"
										"\n5. Dinero gastado\n"
										"\n6. Dinero gastado para completar el album\n"
										"\n7. Listar por equipo  \n"
										"\n8. Listar por sponsor (Nuevo)  \n"
										"\n0. SALIR\n"
										"Elija opcion: ", "Error. Opcion no valida", 0, 8, 9000000, &opcInformes)
										== 0)
				{
					switch(opcInformes)
					{
					case 1:
						if(mostrarPegadas(arrayFiguritas, TAM, equipo, MAX_TAM_EQUIPOS, album, TAM,arrayPegadas, TAM))
						{

						}else
						{
							puts("No hay figuritas pegadas.");
						}
						break;
					case 2:
						if(mostrarRepetidas(arrayFiguritas, TAM, equipo, MAX_TAM_EQUIPOS, arrayRepetidas, TAM))
						{

						}else
						{
							puts("No hay figuritas repetidas.");
						}
						break;
					case 3:
						if(listarDoradas(arrayFiguritas, TAM, equipo, MAX_TAM_EQUIPOS, album, TAM))
						{

						}else
						{
							puts("No hay figuritas doradas.");
						}
						break;
					case 4:
						if(figuritasPegadas==54)
						{
							printf("\nLos sobres comprados para completar el album son: %d\n",cantidadSobres+1);
						}else
						{
							puts("Aun no se completo el album");
						}
						break;
					case 5:
						printf("\nEl dinero gastado en sobres es: $%d\n",gastoSobres);
						break;
					case 6:
						if(figuritasPegadas==55)
						{
							printf("\nEl dinero gastado en sobres para completar el album fue de: $%d\n",gastoHastaCompletarAlbum+170);
						}else
						{
							puts("Aun no se completo el album");
						}
						break;
					case 7:
						if(listarPorEquipo(arrayFiguritas, TAM, equipo, MAX_TAM_EQUIPOS, album, TAM))
						{

						}else
						{
							puts("NO hay nada para mostrar");
						}
						break;
					case 8:
						listarPorSponsor(arrayFiguritas, TAM, equipo, MAX_TAM_EQUIPOS, album, TAM, arraySponsor, MAX_TAM_SPONSOR);
						break;
					case 0:
						break;
					}
				}
				break;
			case 0:
				break;
			}
		}
	} while (opc != 0);

	return 0;
}
