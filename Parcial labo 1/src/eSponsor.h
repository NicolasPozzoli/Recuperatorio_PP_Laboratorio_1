#ifndef eSponsor_H_
#define eSponsor_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Input.h"

#define MAX_CHARS_CADENAS 30
#define LIBRE 0
#define OCUPADO 1
#define BAJA -1

//*** eSponsor
typedef struct {
	int idSponsor;
	char descripcion[50];  //NOMBRE  ALFA NUMERICA
	float precio;
	int isEmpty;
} eSponsor;
//***

/** INICIO CABECERAS DE FUNCION*/
void eSponsor_Inicializar(eSponsor array[], int TAM);
int eSponsor_ObtenerIndexLibre(eSponsor array[], int TAM);
int eSponsor_BuscarPorID(eSponsor array[], int TAM, int ID);
void eSponsor_MostrarUno(eSponsor equipo);
int eSponsor_MostrarTodos(eSponsor array[], int TAM);
int eSponsor_MostrarDadosDeBaja(eSponsor array[], int TAM);
int eSponsor_ObtenerID(void);

/** SORT */
//CRITERIO -> -1 = MENOR A MAYOR
//CRITERIO ->  1 = MAYOR A MENOR
int eSponsor_Sort(eSponsor array[], int TAM, int criterio);

//ABM
eSponsor eSponsor_CargarDatos(void);
eSponsor eSponsor_ModificarUno(eSponsor equipo);
int eSponsor_Alta(eSponsor array[], int TAM);
int eSponsor_Baja(eSponsor array[], int TAM);
int eSponsor_Modificacion(eSponsor array[], int TAM);
/** FIN CABECERAS DE FUNCION*/
int elegirSponsor(char* pSponsorIngresado);

#endif
