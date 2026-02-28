#include <iostream>
#include <conio2.h>
#include <ctime>
#include <cstdlib>
using namespace std;

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
	bool actualizarDisparoNave();
	int getX();
	int getY();
	void desactivo();
	
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
bool Disparo::actualizarDisparoNave()
{   if(!activo)
{
	return false;
}
if(tempo + paso < clock()){
	gotoxy(x,y);
	cout<<" ";
	y++;
	gotoxy(x,y);
	cout<<"I";
	tempo = clock();
}
if(y>=29)
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
int Disparo::getX()
{
	return x;
}
int Disparo::getY()
{
	return y;
}
void Disparo::desactivo()
{
	activo = false;
}
class Enemigo
{
protected:
	int dx;
	int dy;
	int velocidad;
	clock_t paso;
	clock_t tempo;
	int vida;

public:
	Enemigo();
	Enemigo(int dx, int dy);
	virtual void dibujar();
	virtual void borrar();
	virtual void movimiento();
	virtual void movimientoDerecha();
	int getDX();
	int getDY();
	void setDY();
	void disparar(int dx, int dy);
	void actualizarDisparo();
	void dibujarDisparos();
	Disparo disparos;
	void restandoVidas();
	bool enemigoVivo();
	
	
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
int Enemigo::getDY()
{
	return dy;
}
void Enemigo::setDY()
{
	
	dy+=1;
	dx+=1;
}

void Enemigo::disparar(int dx, int dy)
{
	disparos.incioDisparo(dx,dy);
}
void Enemigo::actualizarDisparo()
{
	disparos.actualizarDisparoNave();
}
void Enemigo::restandoVidas()
{
	if(vida > 0){
		vida--;
	}
}
bool Enemigo::enemigoVivo()
{
	return (vida > 0);
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
	vida = 5;
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
Enemigo2 ::Enemigo2(int dx, int dy): Enemigo(dx,dy)
{
	vida = 3;
}
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
Enemigo3 ::Enemigo3(int dx, int dy): Enemigo(dx,dy)
{
	vida = 2;
}
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



class Nave
{
private: 
	int dx;
	int dy;
	int vida;
	
public:
	Nave();
	void dibujar();
	void borrar();
	void moverIzquierda();
	void moverDerecha();
	void disparar();
	void actualizarDisparo();
	int getDX();
	int getDY();
	Disparo disparo;
	int getVida();
	
	void perderVidas();
	
	bool gameOver();
	
};
Nave::Nave()
{
	dx = 20;
	dy = 28;
	vida = 3;
	
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
int Nave::getDX()
{
	return dx;
}
int Nave::getDY()
{
	return dy;
}

int Nave::getVida()
{
	return vida;
}
void Nave::perderVidas()
{
vida --;	
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
	int puntosJugador;
	Enemigo1 enemigo1[5];
	Enemigo2 enemigo2[5];
	Enemigo3 enemigo3[5];
public:
	Juego();
	void leerTeclasYdibujar();
	void dibujarBordes();
	void dibujarEnemigos();
	void movimientoEnemigos();
	void disparosEnemigos();
	void dibujarInterfaces();
	void colisionEnemigos();
	void sumarPuntos();
	int getPuntosJugador();
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
	puntosJugador=0;
	for(int x = 0; x<5; x++)
	{
		
		enemigo1[x]=Enemigo1{dx,5};
		enemigo2[x]=Enemigo2{dx,10};
		enemigo3[x]=Enemigo3{dx,15};
		dx +=10;
	}
}
int Juego::getPuntosJugador()
{
	return puntosJugador;
}
void Juego::sumarPuntos()
{
	puntosJugador+=15;
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
void Juego::colisionEnemigos()
{
	for(int x = 0;x<5;x++)
	{
		if((nave1.disparo.getX()==enemigo1[x].getDX())&&(nave1.disparo.getY()==enemigo1[x].getDY())&&enemigo1[x].enemigoVivo())
		{
			enemigo1[x].restandoVidas();
			sumarPuntos();
			nave1.disparo.desactivo();
			
		}
		if((nave1.disparo.getX()==enemigo2[x].getDX())&&(nave1.disparo.getY()==enemigo2[x].getDY())&&enemigo2[x].enemigoVivo())
		{
			enemigo2[x].restandoVidas();
			sumarPuntos();
			nave1.disparo.desactivo();
		}
		if((nave1.disparo.getX()==enemigo3[x].getDX())&&(nave1.disparo.getY()==enemigo3[x].getDY())&&enemigo3[x].enemigoVivo())
		{
			enemigo3[x].restandoVidas();
              sumarPuntos();			
			nave1.disparo.desactivo();
		}
		
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
		
		if(enemigo1[x].enemigoVivo()){enemigo1[x].dibujar();}
		
	    if(enemigo2[x].enemigoVivo()){enemigo2[x].dibujar();}
		if(enemigo3[x].enemigoVivo()){enemigo3[x].dibujar();}
		
		
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
void Juego::disparosEnemigos()
{
	srand(time(NULL));
	for(int x = 0; x<5;x++)
	{
		
		if(rand() % 100 < 4)  {
			enemigo1[x].disparar(enemigo1[x].getDX(), enemigo1[x].getDY());
			
		}
		
		if(rand() % 100 < 4){
			enemigo2[x].disparar(enemigo2[x].getDX(), enemigo2[x].getDY());
			
		}
		
		if(rand() % 100 < 4){
			enemigo3[x].disparar(enemigo3[x].getDX(), enemigo3[x].getDY());
		}
		if(enemigo1[x].disparos.getX()==nave1.getDX()&&enemigo1[x].disparos.getY()==nave1.getDY())
		{
			nave1.perderVidas();
			enemigo1[x].disparos = Disparo();
			
		
		}
		if(enemigo2[x].disparos.getX()==nave1.getDX()&&enemigo2[x].disparos.getY()==nave1.getDY())
		{
			nave1.perderVidas();
			enemigo2[x].disparos = Disparo();
		}
		if(enemigo3[x].disparos.getX()==nave1.getDX()&&enemigo3[x].disparos.getY()==nave1.getDY())
		{
			nave1.perderVidas();
			enemigo3[x].disparos = Disparo();
		}
		enemigo1[x].actualizarDisparo();
		enemigo2[x].actualizarDisparo();
		enemigo3[x].actualizarDisparo();
		
	}
}
void Juego::dibujarInterfaces()
{
	gotoxy(80,4);
	cout<<"VIDA:"<<endl;
	gotoxy(97,4);
	cout<<nave1.getVida();
	gotoxy(80,2);
	cout<<"puntos jugador: ";
	gotoxy(97,2);
	cout<<getPuntosJugador();
		
}
void Juego::gameLoop()
{
	leerTeclasYdibujar();
	colisionEnemigos();
	nave1.actualizarDisparo();
	dibujarBordes();
	disparosEnemigos();
	movimientoEnemigos();
	dibujarEnemigos();
	dibujarInterfaces();
	
	
}
int main(int argc, char *argv[]) {
	Juego juego1;
	
	while(true){
		juego1.gameLoop();
	}
	return 0;
}
