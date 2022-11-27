#ifndef eFigurita_H_
#define eFigurita_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Input.h"

#define MAX_CHARS_CADENAS 30
#define LIBRE 0
#define OCUPADO 1
#define BAJA -1


typedef struct {
	int dia;
	int mes;
	int anio;
} eFecha;

//*** eFigurita
typedef struct {
	int idFigurita; // PK
	char nombreJugador[MAX_CHARS_CADENAS];
	char posicion[MAX_CHARS_CADENAS];
	int idEquipo;
	int idSponsor;    //NUEVOO
	float altura;
	float peso;
	int anioIngreso;
	eFecha fechaNacimiento[MAX_CHARS_CADENAS];
	int isEmpty;
} eFigurita;


//***

/** INICIO CABECERAS DE FUNCION*/
void eFigurita_Inicializar(eFigurita array[], int TAM);
int eFigurita_ObtenerIndexLibre(eFigurita array[], int TAM);
int eFigurita_BuscarPorID(eFigurita array[], int TAM, int ID);
void eFigurita_MostrarUno(eFigurita Figurita);
int eFigurita_MostrarTodos(eFigurita array[], int TAM);
int eFigurita_MostrarDadosDeBaja(eFigurita array[], int TAM);
int eFigurita_ObtenerID(void);
int isValidFecha(int dia, int mes, int anio);

/** SORT */
//CRITERIO -> -1 = MENOR A MAYOR
//CRITERIO ->  1 = MAYOR A MENOR
int eFigurita_Sort(eFigurita array[], int TAM, int criterio);

//ABM
eFigurita eFigurita_CargarDatos(void);
eFigurita eFigurita_ModificarUno(eFigurita Figurita);
int eFigurita_Alta(eFigurita array[], int TAM);
int eFigurita_Baja(eFigurita array[], int TAM);
int eFigurita_Modificacion(eFigurita array[], int TAM);
int getFecha(eFecha *pFecha, int limite, char *mensaje,char *mensajeError, int reintentos);
/** FIN CABECERAS DE FUNCION*/
#endif
