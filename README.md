Libreria diseñada por Victor Salinas Parra para sistemas operativo x86
PUBLIC DOMAIN


Descripción: MDIO.H utiliza la Interrupción 0x33 – 33h para controlar el driver del mouse este opera en la arquitectura x86.
Las funciones se introducen en el registro AX, parra ello debemos vincularlo con los registros de la CPU
Para escribir un datos debemos hacer un union de los registros (REGS).


unión REGS in, out;	 o	unión REGS registros;	Nos permitira tener acceso a los registros de la CPU.

in.x.ax = <code>		Lo queremos almacenar en la instrucción AX

Para lanzar la interrupción, usaremos la función de la librería dos.h int86, que se define en Turbo C como:
int int86(int numero_interrupcion, union REGS *registros_entrada, union REGS *registros_salida);


							ESQUEMA DE INSTRUCIONES 				AX


Detecta el mouse
00h				AX = 0		

Output: 	AX > 0 ‘si se ha detectado mouse’
		AX = 0 ‘no se ha detectado el mouse’


Muestra el mouse
01h				AX = 1


Ocultar el mouse
02h				AX = 2


Lee el driver del mouse
03h				AX = 3

Output:
	BX = 0 ‘no se ha pulsado ninguna tecla’
	BX = 1 ‘se ha pulsado el botón izquierdo’
	BX = 2 ‘se ha pulsado el botón derecho’
	BX = 4 ‘se ha pulsado el botón centra’
        CX = H ‘posición horizontal’
	CX = V ‘posición vertical’


Establece la posición x e y del mouse
04h				AX = 4

Input:
	DX = X ‘posición x’
	CX = Y ‘posición y’


Rango de desplazamiento de X – Horizontal
07h				 AX = 7

Input:
	DX = H ‘mínimo’ 
	CX = H ‘máximo’
	
	
Rango de desplazamiento de Y – Vertical
08h				 AX = 8

Input:
	DX = V ‘mínimo’
	CX = V ‘máximo’



FUNCIONES DE LA LIBRERÍA MDIO.H
	Funciones Principales
		startmd();
		showmd();
		hidemd();
	Obtener atributos del mouse
		getmd_all();
		getmd_pos();
		getmd_press();
		getmd_x();
		getmd_y();
	Introducir atributos del mouse
		setmd_pos();
		setmd_x();
		setmd_y();
	Otros atributos
		delmc_x();
		delmc_y();


FUNCIONES PRINCIPALES
	startmd
	Inicializa el ratón, devuelve el estado del mouse.
	SI existe el mouse devolverá un 1 si no existe devolver un 0;
	int startmd();

	showmd
	Muestra de forma gráfica o no grafica el mouse;
	void showmd();

	hidemd
	Oculta el mouse de la pantalla;
	void hidemd();


FUNCIONES DE EXTRACION DE DATOS
	getmd_all
	Devuelve el click del mouse, posición X y posición Y;
	void getmd_all(int*,int*,int*);

	getmd_pos
	Devuelve la posición X y posición Y;
	void getmd_pos(int*,int*);

	getmd_press
	Devuelve el click del mouse;
	void getmd_press(int*);

	getmd_x
	Devuelve solo la posición X;
	void getmd_x(int*);

	getmd_y
	Devuelve solo la posición X;
	void getmd_y(int*);


FUNCIONES DE INSERCION DE DATOS
•	setmd_pos
	Se introduce la nueva posición X e Y del mouse;
	void setmd_pos(int*,int*);

•	setmd_x
	Se introduce la nueva posicion X;
	void setmd_x(int*);

•	setmd_y
	Se introduce la nueva posicion Y;
	void setmd_y(int*);


FUNCIONES DE DELIMITACION DEL MOUSE
•	delmd_x
	Limita posicion X con minimo y maximo;
	void delmd_x(int*,int*);

•	delmd_y
	Limita posicion X con minimo y maximo;
	void delmd_y(int*,int*);
