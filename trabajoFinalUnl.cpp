#include <iostream>
#include <conio2.h>
using namespace std;

class Nave
{
private: 
	int dx;
	int dy;
public:
	Nave();
	void dibujar();
	void borrar();
	void moverIzquierda();
	void moverDerecha();
	
};
Nave::Nave()
{
   dx = 20;
   dy = 20;
}
void Nave::dibujar()
{
   gotoxy(dx,dy);
   cout<<"A";
}
void Nave::borrar()
{
	gotoxy(dx,dy);
	cout<<" ";
}
void Nave::moverIzquierda()
{
	if(dx>=3)
	{
		dx -= 1;
	}
	
}
void Nave::moverDerecha()
{
	if(dx<=73)
	{
		dx +=1;
	}
}
class Juego
{
private:
	Nave nave1;
	int bordeX;
	int bordeX2;
	int bordeY;
	int bordeY2;
public:
	Juego();
	void leerTeclasYdibujar();
	void dibujarBordes();
	void gameLoop();
};

Juego::Juego()
{
	bordeX = 1;
	bordeX2 = 1;
	bordeY = 1;
	bordeY2 = 1;
}
void Juego::leerTeclasYdibujar()
{
    if(kbhit())
	{
		nave1.borrar();
		char tecla = getch();
		switch(tecla)
		{
		case 'a':
			nave1.moverIzquierda();
			break;
		case 'd':
			nave1.moverDerecha();
			break;
		}
		nave1.dibujar();
	}	
}
void Juego::dibujarBordes()
{
	if(bordeX<75)
	{
		gotoxy(bordeX,1);
		cout<<".";
		bordeX++;
	}
	
	if(bordeX2<75)
	{
		gotoxy(bordeX2,30);
		cout<<".";
		bordeX2++;
	}
	if(bordeY<30)
	{
		gotoxy(1,bordeY);
		cout<<".";
		bordeY++;
	}
	if(bordeY2<30)
	{
		gotoxy(75,bordeY2);
		cout<<".";
		bordeY2++;
	}
}
void Juego::gameLoop()
{
	leerTeclasYdibujar();
	dibujarBordes();
	
}
int main(int argc, char *argv[]) {
	Juego juego1;
	
	while(true){
	juego1.gameLoop();
	}
	return 0;
}

