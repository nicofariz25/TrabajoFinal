#include <iostream>
#include <conio2.h>
#include <ctime>
using namespace std;

class Enemigo
{
protected:
	int dx;
	int dy;
	int velocidad;
	clock_t paso;
	clock_t tempo;
public:
	Enemigo();
	Enemigo(int dx, int dy);
	virtual void dibujar();
	virtual void borrar();
	virtual void movimiento();
	virtual void movimientoDerecha();
	int getDX();
	void setDY();
};
Enemigo::Enemigo()
{
	
}
Enemigo::Enemigo(int dx, int dy)
{
	this->dx=dx;
	this->dy = dy;
	velocidad = 2;
	paso = CLOCKS_PER_SEC * velocidad;
	tempo = clock();
}
void Enemigo::dibujar()
{
	gotoxy(dx,dy);
	cout<<"A";
}
void Enemigo::borrar()
{
	gotoxy(dx,dy);
	cout<<" ";
}

void Enemigo::movimiento()
{
	
}
void Enemigo::movimientoDerecha()
{
	
}
int Enemigo::getDX()
{
	return dx;
}

void Enemigo::setDY()
{
	
	dy+=1;
	dx+=1;
}

class Enemigo1 : public Enemigo
{
private:
	
public:
	Enemigo1(int dx, int dy);
	Enemigo1();
	void dibujar() override;
	void borrar() override;
	void movimiento() override;
	void movimientoDerecha()override;
};
Enemigo1::Enemigo1(int dx, int dy) : Enemigo(dx,dy)
{
	
}
Enemigo1::Enemigo1():Enemigo(0,0){}
void Enemigo1::borrar()
{
	gotoxy(dx,dy);
	cout<<" ";
}
void Enemigo1::dibujar()
{
	borrar	();
	gotoxy(dx,dy);
	cout<<"H";
}
void Enemigo1::movimiento()
{
	if(paso+tempo<clock())
	{
		borrar();
		dx+=2;
		tempo = clock();
	}
}
void Enemigo1::movimientoDerecha()
{
	if(paso+tempo<clock())
	{
		borrar();
		dx-=2;
		tempo = clock();
	}
	
}

class Enemigo2 : public Enemigo
{
private:
public:
	Enemigo2(int dx,int dy);
	Enemigo2();
	void dibujar()override;
	void borrar() override;
	void movimiento() override;
	void movimientoDerecha() override;
};
Enemigo2 ::Enemigo2(int dx, int dy): Enemigo(dx,dy){}
Enemigo2::Enemigo2():Enemigo(0,0){}
void Enemigo2::borrar()
{
	gotoxy(dx,dy);
	cout<<" ";
}
void Enemigo2::movimiento()
{
	if(tempo+paso<clock())
	{
		borrar();
		dx+=2;
		tempo = clock();
	}
}
void Enemigo2::dibujar()
{
	gotoxy(dx,dy);
	cout<<"M";
}
void Enemigo2::movimientoDerecha()
{
	if(paso+tempo<clock())
	{
		borrar();
		dx-=2;
		tempo = clock();
	}
	
}
class Enemigo3 : public Enemigo
{
private:
public:
	Enemigo3(int dx, int dy);
	Enemigo3();
	void dibujar()override;
	void borrar() override;
	void movimiento() override;
	void movimientoDerecha() override;
};
Enemigo3 ::Enemigo3(int dx, int dy): Enemigo(dx,dy){}
Enemigo3::Enemigo3():Enemigo(0,0){}
void Enemigo3::borrar()
{
	gotoxy(dx,dy);
	cout<<" ";
}
void Enemigo3::movimiento()
{
	if(tempo+paso<clock())
	{
		borrar();
		dx+=2;
		tempo = clock();
	}
}
void Enemigo3::dibujar()
{
	
	gotoxy(dx,dy);
	cout<<"T";
}
void Enemigo3::movimientoDerecha()
{
	if(paso+tempo<clock())
	{
		borrar();
		dx-=2;
		tempo = clock();
	}
	
}

class Disparo
{
private:	
	int x;
	int y;
	clock_t tempo;
	clock_t paso;
	int velocidad;
	
	bool activo;
public:
	Disparo();
	void incioDisparo(int dx, int dy);
	bool actualizar();
	void dibujar();
	
};
Disparo::Disparo()
{
	x = 0;
	y = 0;
	velocidad = 5;
	paso = CLOCKS_PER_SEC / velocidad;
	tempo = clock();
	
	activo = false;
	
}
void Disparo::incioDisparo(int dx, int dy)
{
	if(!activo)
	{
		x = dx;
		y = dy-1;
		activo = true;
		tempo = clock();
	}
}
bool Disparo::actualizar()
{   if(!activo)
{
	return false;
}
if(tempo + paso < clock()){
	gotoxy(x,y);
	cout<<" ";
	y--;
	gotoxy(x,y);
	cout<<"I";
	tempo = clock();
}
if(y<=2)
{
	gotoxy(x,y);
	cout<<" ";
	activo = false;
}


return activo;
}
void Disparo::dibujar()
{
	gotoxy(x,y);
	cout<<"I";
}

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
	void disparar();
	void actualizarDisparo();
	Disparo disparo;
	
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
void Nave::disparar()
{
	disparo.incioDisparo(dx,dy);
}
void Nave::actualizarDisparo()
{
	disparo.actualizar();
}
class Juego
{
private:
	Nave nave1;
	int bordeX;
	int bordeX2;
	int bordeY;
	int bordeY2;
	int dx;
	bool a;
	Enemigo1 enemigo1[5];
	Enemigo2 enemigo2[5];
	Enemigo3 enemigo3[5];
public:
	Juego();
	void leerTeclasYdibujar();
	void dibujarBordes();
	void dibujarEnemigos();
	void movimientoEnemigos();
	void gameLoop();
};

Juego::Juego()
{
	bordeX = 1;
	bordeX2 = 1;
	bordeY = 1;
	bordeY2 = 1;
	dx = 10;
	a = true;
	for(int x = 0; x<5; x++)
	{
		
		enemigo1[x]=Enemigo1{dx,5};
		enemigo2[x]=Enemigo2{dx,10};
		enemigo3[x]=Enemigo3{dx,15};
		dx +=10;
	}
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
		case 'b':
			nave1.disparar();
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
void Juego::dibujarEnemigos()
{
	
	for(int x = 0;x<5;x++)
	{
		
		enemigo1[x].dibujar();
		//enemigo1[x].movimiento();
		enemigo2[x].dibujar();
		//enemigo2[x].movimiento();
		enemigo3[x].dibujar();
		//enemigo3[x].movimiento();
	}	
}
void Juego::movimientoEnemigos()
{
	
	for(int x = 0;x<5;x++)
	{
		if(a){
		enemigo1[x].movimiento();
		enemigo2[x].movimiento();
		enemigo3[x].movimiento();
		if(enemigo1[4].getDX()>=72)
		{
			a = false;
			for(int x = 0;x<5;x++)
			{
				enemigo1[x].setDY();
				enemigo2[x].setDY();
				enemigo3[x].setDY();
			}
		}
		}
		   
		
	}
	if(a==false)
	{
		for(int x= 0;x<5;x++)
		{
			enemigo1[x].movimientoDerecha();
			enemigo2[x].movimientoDerecha();
			enemigo3[x].movimientoDerecha();
			if(enemigo1[0].getDX()<=3)
			{
				a = true;
				for(int x=0;x<5;x++)
				{
					enemigo1[x].borrar();
					enemigo1[x].setDY();
					enemigo2[x].borrar();
					enemigo2[x].setDY();
					enemigo3[x].borrar();
					enemigo3[x].setDY();
				}
			}
		}
	}
	
}
void Juego::gameLoop()
{
	leerTeclasYdibujar();
	
	nave1.actualizarDisparo();
	dibujarBordes();
	movimientoEnemigos();
	dibujarEnemigos();
	
}
int main(int argc, char *argv[]) {
	Juego juego1;
	
	while(true){
		juego1.gameLoop();
	}
	return 0;
}












