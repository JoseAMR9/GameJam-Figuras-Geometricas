#pragma once
#include "Dependencias.h"

class Figuras {

protected:
	int x, y;
	int dx, dy;
	int ancho, alto;
	int colorARGB;
	int puntos;

public:
	Figuras()
	{
		x = y = 0;
		colorARGB = Color::Gray.ToArgb();
		dx = dy = 0;
		ancho = alto = 0;
		puntos = 0;
	}
	Rectangle Area()
	{
		return Rectangle(x, y, ancho, alto);
	}
	virtual void Mover(Graphics^ g)
	{
		x += dx;
	}
	virtual void Dibujar(Graphics^ g) = 0;

	void setX(int _x)
	{
		x = _x;
	}
	void setY(int _y)
	{
		y = _y;
	}
	void setDX(int _dx)
	{
		dx = _dx;
	}
	void setDY(int _dy)
	{
		dy = _dy;
	}
	int getX()
	{
		return x;
	}
	int getY()
	{
		return y;
	}
	int getDX()
	{
		return dx;
	}
	int getDY()
	{
		return dy;
	}
	void setPuntos(int _puntos)
	{
		puntos = _puntos;
	}
	int getPuntos()
	{
		return puntos;
	}
	void setColorARGB(int _colorARGB) 
	{
		colorARGB = _colorARGB;
	}
	int getColorARGB() 
	{
		return colorARGB;
	}
	int getAncho() 
	{
		return ancho;
	}
	int getAlto()
	{
		return alto;
	}
};
