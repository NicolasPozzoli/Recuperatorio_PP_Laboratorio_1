#ifndef eAlbum_H_
#define eAlbum_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARS_CADENAS 30
#define LIBRE 0
#define OCUPADO 1
#define BAJA -1


#define DORADA 3
#define NODORADA 2

//*** eAlbum
typedef struct {
	int idGen;
	int idFigurita[55];
	int esDorada[55];
	int estado;
	int isEmpty[55];
} eAlbum;
//***

/** INICIO CABECERAS DE FUNCION*/
void eAlbum_Inicializar(eAlbum array, int TAM);
int eAlbum_ObtenerIndexLibre(eAlbum array[], int TAM);
int eAlbum_BuscarPorID(eAlbum array[], int TAM, int ID);
void eAlbum_MostrarUno(eAlbum Gen);
int eAlbum_MostrarTodos(eAlbum array[], int TAM);
int eAlbum_MostrarDadosDeBaja(eAlbum array[], int TAM);

/** SORT */
//CRITERIO -> -1 = MENOR A MAYOR
//CRITERIO ->  1 = MAYOR A MENOR
int eAlbum_Sort(eAlbum array[], int TAM, int criterio);

//ABM
eAlbum eAlbum_CargarDatos(void);
eAlbum eAlbum_ModificarUno(eAlbum Gen);
int eAlbum_Alta(eAlbum array[], int TAM);
int eAlbum_Baja(eAlbum array[], int TAM);
int eAlbum_Modificacion(eAlbum array[], int TAM);
/** FIN CABECERAS DE FUNCION*/

int eAlbum_esPegada(eAlbum album, int tam,int indice);
#endif
