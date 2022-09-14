//23/08/17
#include <stdlib.h>
#include <iostream>
using namespace std;
const int FIL = 3;
const int COL = 3;

/**
a) Dada una matriz de entero debe contar la cantidad de posiciones vacias, es decir aquellas 
que tengan almacenado el valor 0 y retornar dicho valor.
**/

int contarPosVacias(int tablero[FIL][COL])
{
	int cont=0;
	for(int i=0;i<FIL;i++)
	{
		for(int j=0;i<COL;i++)
		{
			if(tablero[i][j]==0)
			{
				cont++;
			}
		}
	}
	return cont;
}

/**
b)Dada una matriz de caracteres esta función debe imprimirla por pantalla con forma de matriz y dejando dos espacios
entre valores de una misma fila. El ejemplo de ejecución muestra el resultado esperado.
**/

void mostrarTablero(char mascara[FIL][COL])
{
	cout<<endl;
 	for(int i=0;i<FIL;i++)
 	{
 		for(int j=0;j<COL;j++)
 		{
 			cout<<mascara[i][j]<<"  ";
		}
		cout<<endl;
	}
}

/**
c)Dada una matriz de enteros y un numero entero n, el objetivo de esta función es colorar n bombas en el tablero en celdas elegidas de
manera pseudo-aleatoria. Una bomba en la fila i columna j del tablero, se simboliza almacenando el valor 1 en la posición [i,j]. Para
obtener una fila y columna al azar debe valerse de la función rand() implementada en la librería stdlib. Para ello, considere que la
expresión rand() % 10 resultará en un entero pseudo-aleatorio perteneciente al intervalo [0,10). Para elegir un número de fila(resp.
columna) de manera pseudo-aleatoria usted debería utilizar rand() % FIL (resp. COL).
No se requiere validar que la posición a minar no haya sido minada previamente. Es decir el tablero puede quedar minado con menos
de n bombas.
**/

void minarTablero(int tablero[FIL][COL] , int bombas)
{
	for(int i=0;i<bombas;i++)
	{
		tablero[rand()%FIL][rand()%COL]=1;
	}
}

/**
d)Dada dos matrices y dos enteros simbolizando una posición de fila y columna esta función debe descubrir la posición i,j de la matriz.
Para ello debe evaluar el valor de la matriz tablero y asignar el valor correspondiente como se indica a continuación:
Si tablero en i,j contiene 1 (esta minado) debe almacenar '*' en la matriz mascara.
Si tablero en i,j contiene 0 (no esta minado) debe almacenar '_' en la matriz mascara.
**/

void realizarJugada(int tablero[FIL][COL], char mascara[FIL][COL], int i, int j)
{

			if(tablero[i][j]==1)
			{
				mascara[i][j]='*';
			}
			else if(tablero[i][j]==0)
			{
				mascara[i][j]='_';
			}
		
}

/**
e)Dada una matriz de caracteres, debe determinar si el jugador ha perdido la partida. Esto sucede cuándo existe una posición con el valor
'*', que simboliza que una posición minada ha sido descubierta. Por tanto este método debe retornar true si efectivamente existe una
posición con dicho valor o false en caso contrario.
**/

bool jugadorPerdio(char mascara[FIL][COL])
{
	for(int i=0;i<FIL;i++)
	{
		for(int j=0;j<COL;j++)
		{
			if(mascara[i][j]=='*')
			{
				return true;
			}
		}
	}
}

/**
f)Dada una matriz de caracteres y un entero que indica la cantidad de posiciones que se deben descubrir para que el jugador gane la
partida, este método debe determinar si el jugador ganó. El jugador gana la partida cuándo el número de posiciones vacías
descubiertas(aquellas que tienen almacenado el valor '_') es igual al valor aDescubrir, por lo tanto si ese es el caso el método debe
retornar true. En caso contrario false
**/

bool jugadorGano(char mascara[FIL][COL], int aDescubrir)
{
	int descubiertas=0;
	for(int i=0;i<FIL;i++)
	{
		for(int j=0;j<COL;j++)
		{
			if(mascara[i][j]=='_')
			{
				descubiertas++;
			}
		}
	}
	
	for(int i=0;i<FIL;i++)
	{
		for(int j=0;j<COL;j++)
		{
			if(descubiertas==aDescubrir)
			return true;
		}
	}
}

int  main()
{
	/**
	a) Defina una matriz de enteros de FIL filas y COL columnas con identificador tab.
	b) Defina una matriz de caracteres de FIL filas y COL columnas con identificador masc.
	c) Inicialice todos las posiciones de tab con el valor 0 y las de masc con '#'.
	**/
	int tab[FIL][COL];
	char masc[FIL][COL];
	
	for(int i=0;i<FIL;i++)
	{
		for(int j=0;j<COL;j++)
		{
			tab[i][j]=0;
			masc[i][j]='#';
		}
	}
	
	/**
	d) Defina una variable entera con identificador nBombas, solicite al usuario que ingrese un valor y almacenelo en nBombas.

	e1) Invoque la función minarTablero con tab y nBombas.
	e2) Defina una variable de tipo entero con identificador posADescubir y asignele el valor resultante de la
	invocación a contarPosVacias con tab.
	e2) Invoque a la función mostarTablero con masc.
	e3) Implemente el ciclo del juego. Mientras el fin del juego no haya sido alcanzado(*), el programa deberá
	realizar las siguientes acciones:
	**/
	int nBombas;
	cout<<"Ingrese la cantdad de bombas: "<<endl;
	cin>>nBombas;
	if(nBombas>0 && nBombas<FIL*COL)
	{
		/**
		e1) Invoque la función minarTablero con tab y nBombas.
		e2) Defina una variable de tipo entero con identificador posADescubir y asignele el valor resultante de la invocación a contarPosVacias con tab.
		e3) Invoque a la función mostarTablero con masc.
		**/
		
		minarTablero(tab,nBombas);
		int posADescubrir= contarPosVacias(tab);
		mostrarTablero(masc);
		do
		{
			/**
			i) Solicite que se ingrese la posición a jugar, es decir solicitar al usuario dos números enteros que representarán la fila 
    		y columna a descubrir. Deberá validar que sean posiciones válidas, es decir mayores que 0 y menores que FIL (resp.COL) y 
			volver a solicitar si es incorrecta.
			**/
			int fila,columna;
			cout<<"Ingrese 2 numeros enteros que reprecenten la poscion a jugar: "<<endl;
			cin>>fila>>columna;
			
			while((fila<0||fila>=FIL) || (columna<0||columna>=COL))
			{
				cout<<"Coordenadas incorrectas, pruebe de nuevo: "<<endl;
				cin>>fila>>columna;
			}
			
			/**
			ii) invoque a la función realizarJugada con tab, masc y los valores obtenidos en el paso anterior.
			iii) invoque a la función mostarTablero con masc.
			**/
			realizarJugada(tab,masc,fila,columna);
			mostrarTablero(masc);
			
		}while(!(jugadorGano(masc,posADescubrir)) || !(jugadorPerdio(masc)));
		
		cout<<"Juego Terminado!"<<endl;
		if(jugadorGano(masc,posADescubrir))
		{
			cout<< "Usted gano la partida."<<endl;
		}
		else
		{
			cout<<"Usted ha perdido la partida."<<endl;
		}
	}
	else
	{
		cout<<"El número de bombas debe ser mayor a 0 y menor que "<<FIL*COL;
	}
	
	return 0;
}
