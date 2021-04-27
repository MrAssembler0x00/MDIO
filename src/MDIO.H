/* Autor: Victor Salinas
 * Determina la posicion [x, y] del cursor 
 * y si das clik derecho o izquierdo.
 * 
 * ¡CUIDADO int86 es una instrucion de la aquitectura de la CPU x86
 * Su adaptacion requiere un cambio interno de las interupciones del
 * hardware afitrion!           
*/
#include <conio.h>
#include <stdio.h>
#include <graphics.h>
#include <dos.h>


union REGS in, out;	//Registros de memoria de entrada y salida



/*_____Funciones principales del mouse_____*/

// Inizializa el mouse
int startmd() {//start_md
	in.x.ax = 0;
	int86(0X33, &in, &out);
	return out.x.ax;
}


// Muestra el mouse en la pantalla
void showmd() {//show_md
	in.x.ax = 1;
	int86(0X33, &in, &out);
}

// Oculta el mouse en la pantalla
void hidemd() {//hide_md
	in.x.ax = 2;
	int86(0X33, &in, &out);
}



/*_____Extraer Poscion y que boton le a dado_____*/

// Detecta que boton click en la pantalla y que posicion esta
void getmd_all(int * click, int * x, int * y) {//getMd_all
	in.x.ax = 3;
	int86(0X33, &in, &out);
	*click = out.x.bx;
	*x = out.x.cx;
	*y = out.x.dx;
}

void getmd_pos(int * x, int * y) {//getMd_pos
	in.x.ax = 3;
	int86(0X33, &in, &out);
	*x = out.x.cx;
	*y = out.x.dx;
}

void getmd_press(int * click) {//getMd_press
	in.x.ax = 3;
	int86(0X33, &in, &out);
	*click = out.x.bx;
}

void getmd_x(int * x) {//getMd_x
	in.x.ax = 3;
	int86(0X33, &in, &out);
	*x = out.x.cx;
}

void getmd_y(int * y) {//getMd_y
	in.x.ax = 3;
	int86(0X33, &in, &out);
	*y = out.x.dx;
}




/*_____Poner Poscion y que boton le a dado_____*/

// Pone el mouse en la posicion en la que se le indique
void setmd_pos(int x, int y) {//setMd_pos
	in.x.ax = 4;
	in.x.cx = x;
	in.x.dx = y;
	int86(0X33, &in, &out);
}

// Pone la posicion X del mouse 

void setmd_x(int x) {//setMd_x
	in.x.ax = 4;
	in.x.cx = x;
	int86(0X33, &in, &out);
}

// Pone la posicion Y del mouse
void setmd_y(int y) {//setMd_y
	in.x.ax = 4;
	in.x.dx = y;
	int86(0X33, &in, &out);
}



/*_____Cuanto espacio de movimiento quieres_____*/

void delmc_x(int min, int max) {//setMd_x_del
	in.x.ax = 7;
	in.x.cx = min;
	in.x.dx = max;
	int86(0X33, &in, &out);
}

void delmc_y(int min, int max) {//setMd_y_del
	in.x.ax = 8;
	in.x.cx = min;
	in.x.dx = max;
	int86(0X33, &in, &out);
}