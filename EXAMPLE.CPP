#include <stdio.h>
#include <conio.h>
#include <mdio.h>

void main() {
	clrscr();
	int status,i,gd=DETECT,gm,  x,y,click;

	//initgraph(&gd, &gm, "T:\\TURBOC\\BGI");
	initgraph(&gd, &gm, "T:\\BGI");

	//Detecta el controlador de entrada del mouse
	if (!startmd()) printf("No se a detectado el mouse.\n");
	else {
		// Para mostrar el mouse
		showmd();
		
		// Para ocultar
		//hidemd();
		
		//Mientras no tetecte una pulsacion haz. . .
		while (!kbhit()) {

			// Obtener la posición actual del ratón
			getmd_all(&click, &x, &y);
			
			
			gotoxy(1, 1);
			printf("x = %d, Y = %d", x, y);

			// clik detecta a que le as dado click
			if (click==1) printf("\nClick Izquierdo en la posicion\t = %d, %d\t",x, y);
			if (click==2) printf("\nClick Derecho en la posicion\t = %d, %d\t",x, y);
			if (click==4) printf("\nClick Central en la posicion\t = %d, %d\t",x, y);
			delay(50);
		}
		getch();
		closegraph();
	}
	getch();
	return;
}
