# incluye < iostream >
# incluir < windows.h >
# incluye < conio.h >
# incluye < stdlib.h >
# incluye < time.h >

usando el  espacio de nombres  std ;

# definir  ARRIBA  72
# definir  IZQUIERDA  75
# definir  ABAJO  80
# definir  DERECHA  77
# definir  ESC  27

int Puntos;
int cuerpo [ 200 ] [ 2 ];
int n = 1 ;
int tam = 3 ;
int x = 10 , y = 12 ;
int dir = 3 ;
int xc = 30 , yc = 20 ;
int xxc = 40 , yyc = 18 ;
int d;
int dif;
doble tiempo;

void  inicializarArreglo ()
{
	para ( int i = 0 ; i < 200 ; i ++) {
		// inicializa los valores de cuerpo
		cuerpo [i] [ 0 ] = 0 ;
		cuerpo [i] [ 1 ] = 0 ;
	}
}

vacío  dificultad ()
{
	cout << " Serpiente \ n elija una dificultad para alterar la velocidad \ n 1: facil \ n 2: media " << endl;
	cin >> d;
	cambiar (d) {
		caso  1 :
			dif = 80 ;
			romper ;
		caso  2 :
		    dif = 60 ;
			romper ;	
	}
	sistema ( " cls " );
}

void  gotoxySnake ( int x, int y)
{
	HANDLE hCon;
	hCon = GetStdHandle (STD_OUTPUT_HANDLE);
	
	COORD dwPos;
	dwPos. X = x;
	dwPos. Y = y;
	
	SetConsoleCursorPosition (hCon, dwPos);
}

 pintar vacío ()
{
	para ( int i = 2 ; i < 78 ; i ++) {
		gotoxySnake (i, 3 ); cout << ( char ) 205 ;
		gotoxySnake (i, 23 ); cout << ( char ) 205 ;	
	}
	para ( int i = 4 ; i < 23 ; i ++) {
		gotoxySnake ( 2 , i); cout << ( char ) 186 ;
		gotoxySnake ( 77 , i); cout << ( char ) 186 ;
	}
	gotoxySnake ( 2 , 3 ); cout << ( char ) 201 ;
	gotoxySnake ( 2 , 23 ); cout << ( char ) 200 ;
	gotoxySnake ( 77 , 3 ); cout << ( char ) 187 ;
	gotoxySnake ( 77 , 23 ); cout << ( char ) 188 ;
	
}

void  dibujarcuerpo ()
{
	para ( int i = 1 ; i <tam; i ++) {
		gotoxySnake (cuerpo [i] [ 0 ], cuerpo [i] [ 1 ]); cout << " O " ;
	}
}

vacío  guardarposicion ()
{
	cuerpo [n] [ 0 ] = x;
	cuerpo [n] [ 1 ] = y;
	n ++;
	si (n == tam) {n = 1 ;}
	dibujarcuerpo ();
}


 borrarcuerpo vacío ()
{
		gotoxySnake (cuerpo [n] [ 0 ], cuerpo [n] [ 1 ]); cout << "  " ;
		guardarposicion ();
	}

void  Teclear ( char y tecla)
{
	si ( kbhit ()) {
		tecla = getch ();
		cambiar (tecla) {
			caso ARRIBA:
			si (dir! = 2 ) {dir = 1 ;}
			romper ;
			caso ABAJO:
			si (dir! = 1 ) {dir = 2 ;}
			romper ;
			caso IZQUIERDA:
			si (dir! = 3 ) {dir = 4 ;}
			romper ;
			caso DERECHA:
			si (dir! = 4 ) {dir = 3 ;}
			romper ;	
		}
	}

}

 comida vacía ()
{
	si (x == xc && y == yc) {
		srand (( unsigned ) tiempo ( NULL ));
		xc = ( rand ()% 73 ) + 4 ;
		srand (( unsigned ) tiempo ( NULL ));
		yc = ( rand ()% 19 ) + 4 ;
		tam ++;
		gotoxySnake (xc, yc); cout << ( carácter ) 4 ;
		Puntos ++;
		gotoxySnake ( 50 , 2 ); cout << Puntos;
	}
	
}

bool  gameover ()
{
	if (y == 3 || y == 23 || x == 2 || x == 77 ) { devolver  falso ; }
	para ( int j = tam- 1 ; j> 0 ; j -) {
		if (cuerpo [j] [ 0 ] == x && cuerpo [j] [ 1 ] == y) { return  false ; }
	}
	devuelve  verdadero ;
}

 puntosx vacío ()
{
	tiempo = tiempo + 0.05 ;
	int tiempo2 = tiempo;
	gotoxySnake ( 35 , 2 ); cout << tiempo;
	si (x == xxc && y == yyc) {
		srand (( unsigned ) tiempo ( NULL ));
		xxc = ( rand ()% 73 ) + 4 ;
		srand (( unsigned ) tiempo ( NULL ));
		yyc = ( rand ()% 19 ) + 4 ;
		Puntos = Puntos + 5 ;
        gotoxySnake ( 50 , 2 ); cout << Puntos;
	}
	si (tiempo2% 10 == 0 ) {
	    gotoxySnake (xxc, yyc); cout << ( char ) 6 ;	
	} else  if (tiempo2% 15 == 0 ) {
		gotoxySnake (xxc, yyc); cout << "  " ;
		srand (( unsigned ) tiempo ( NULL ));
		xxc = ( rand ()% 73 ) + 4 ;
		srand (( unsigned ) tiempo ( NULL ));
		yyc = ( rand ()% 19 ) + 4 ;
	}
} 

 proceso vacío ( char & tecla, int & puntos)
{ 
	Puntos = puntos;
	borrarcuerpo ();
	comida ();
	puntosx ();
	Teclear (tecla);
	Teclear (tecla);
	si (dir == 1 ) {y--;}
	si (dir == 2 ) {y ++;}
	si (dir == 3 ) {x ++;}
	si (dir == 4 ) {x--;}
	Sueño (dif);
}


int  serpiente ()
{
	sistema ( " cls " );
	char tecla;
	int puntos = 0 ;
	int xPos = 30 , yPos = 20 ;
	
	inicializarArreglo ();
	dificultad ();	
	gotoxySnake ( 50 , 2 );
	cout << puntos;
	pintar ();
	gotoxySnake (xPos, yPos);
        cout << ( carácter ) 4 ;	
	
	while (tecla! = 27 && gameover ()) {
	    proceso (tecla, puntos);
	}
	
	if (! gameover ()) {
		MessageBox ( NULL , " Has perdido " , " Perdedor " , MB_OK);
		sistema ( " cls " );
	}
	
	sistema ( " pausa> NULO " );
	return  0 ;
}