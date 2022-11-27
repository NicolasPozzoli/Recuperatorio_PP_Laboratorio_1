#ifndef eEquipo_H_
#define eEquipo_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Input.h"

#define MAX_CHARS_CADENAS 30
#define LIBRE 0
#define OCUPADO 1
#define BAJA -1

//*** eEquipo
typedef struct {
	int idEquipo;
	char descripcion[50];  //NOMBRE
	char directorTecnico[50];
	int isEmpty;
} eEquipo;
//***

/** INICIO CABECERAS DE FUNCION*/
void eEquipo_Inicializar(eEquipo array[], int TAM);
int eEquipo_ObtenerIndexLibre(eEquipo array[], int TAM);
int eEquipo_BuscarPorID(eEquipo array[], int TAM, int ID);
void eEquipo_MostrarUno(eEquipo equipo);
int eEquipo_MostrarTodos(eEquipo array[], int TAM);
int eEquipo_MostrarDadosDeBaja(eEquipo array[], int TAM);
int eEquipo_ObtenerID(void);

/** SORT */
//CRITERIO -> -1 = MENOR A MAYOR
//CRITERIO ->  1 = MAYOR A MENOR
int eEquipo_Sort(eEquipo array[], int TAM, int criterio);

//ABM
eEquipo eEquipo_CargarDatos(void);
eEquipo eEquipo_ModificarUno(eEquipo equipo);
int eEquipo_Alta(eEquipo array[], int TAM);
int eEquipo_Baja(eEquipo array[], int TAM);
int eEquipo_Modificacion(eEquipo array[], int TAM);
/** FIN CABECERAS DE FUNCION*/
#endif
