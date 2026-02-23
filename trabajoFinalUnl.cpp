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
	if(dx>=2)
	{
		dx -= 1;
	}
	
}
void Nave::moverDerecha()
{
	if(dx<=30)
	{
		dx +=1;
	}
}
class Juego
{
private:
	Nave nave1;
public:
	Juego();
	void leerTeclasYdibujar();
	void gameLoop();
};

Juego::Juego(){}
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
void Juego::gameLoop()
{
	leerTeclasYdibujar();
	
}
int main(int argc, char *argv[]) {
	Juego juego1;
	
	while(true){
	juego1.gameLoop();
	}
	return 0;
}

