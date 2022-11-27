/*
 * Figurita_Equipo.h
 *
 *  Created on: 5 oct. 2022
 *      Author: Nicolas
 */

#ifndef FIGURITA_EQUIPO_SPONSOR_H_
#define FIGURITA_EQUIPO_SPONSOR_H_

int eFigurita_Alta_Equipo_Sponsor(eFigurita array[], int TAM,eEquipo arrayEquipo[], int TAMequipo,eSponsor arraySponsor[], int TAMsponsor);
int Mostrar_Figuritas_Equipos(eFigurita array[], int TAM,eEquipo arrayEquipo[], int TAMequipo);

int Mostrar_Figuritas_Equipos_Sponsor(eFigurita array[], int TAM,eEquipo arrayEquipo[], int TAMequipo,eSponsor arraySponsor[], int TAMsponsor);
void calcularGastoDeSobres(int* pGastoSobres);
int Modificar_Figuritas_Equipo(eFigurita array[], int TAM,eEquipo arrayEquipo[], int TAMequipo,eSponsor arraySponsor[], int TAMsponsor);
int cargarFiguritasEnAlbum(eFigurita array[], int TAM,eEquipo arrayEquipo[], int TAMequipo,eAlbum album,
		int cantidadFiguritas,int figuritasRepetidas[],int TAMrepetidas,int *gastoSobres,int* pGastosHastaCompletarAlbum,int *pFiguritasPegadas,int *pCantidadSobres,int arrayFiguritasPegadas[],int TAMpegadas);
int intercambiarFiguritas(eFigurita array[],int TAM,eEquipo arrayEquipo[], int TAMequipo,int arrayRepetidas[],int TAMrepetidas);
int mostrarRepetidas(eFigurita array[], int TAM,eEquipo arrayEquipo[], int TAMequipo,int arrayFiguritasRepetidas[],int TAMrepetidas);
int mostrarPegadas(eFigurita array[], int TAM,eEquipo arrayEquipo[], int TAMequipo,eAlbum album,int TAMalbum,int arrayPegadas[],int TAMpegadas);
int hardCodeFiguritas(eFigurita arrayFigurita[], int len,int cantidad, int *pNextId);
int mostrarRepetidasConID(eFigurita array[], int TAM,eEquipo arrayEquipo[], int TAMequipo,int arrayFiguritasRepetidas[],int TAMrepetidas);
int eEquipo_BuscarPorDescripcion(eEquipo array[], int TAM, char descripcion[],int TAMdescripcion);
int listarPorEquipo(eFigurita array[], int TAM,eEquipo arrayEquipo[], int TAMequipo,eAlbum album,int TAMalbum);
int listarDoradas(eFigurita array[], int TAM,eEquipo arrayEquipo[], int TAMequipo,eAlbum album,int TAMalbum);
int contarFiguritasPegadas(int arrayPegadas[],int TAM);
int eEquipo_SortFigurita(eEquipo array[], int TAM, int criterio,eFigurita arrayFigurita[], int TAMfigurita);
int listarPorSponsor(eFigurita array[], int TAM,eEquipo arrayEquipo[], int TAMequipo,eAlbum album,int TAMalbum,eSponsor arraySponsor[],int TAMsponsor);
#endif /* FIGURITA_EQUIPO_SPONSOR_H_ */
