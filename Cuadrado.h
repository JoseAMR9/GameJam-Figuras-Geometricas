#pragma once
#include "Figuras.h"

class Cuadrado : public Figuras
{
public:
	Cuadrado()
	{
		int aleatorio = rand() % 3;
		if (aleatorio == 0) colorARGB = Color::Yellow.ToArgb();
		else if (aleatorio == 1) colorARGB = Color::Blue.ToArgb();
		else colorARGB = Color::Red.ToArgb();

		x = 460;
		y = (rand() % 213) + 30;
		dx = (rand() % 12) + 7;
		ancho = alto = 40;
		puntos = (rand() % 5) + 1;
	}
	void Mover(Graphics^ g, int tramos)
	{
		switch (tramos)
		{
		case 1:
			if (x + dx > 0 && x + ancho + dx < g->VisibleClipBounds.Width) x -= dx;
			break;

		case 2:
			if (y + dy + alto < g->VisibleClipBounds.Height) y += dy;
			else {
				y = 0;
				x = rand() % (480 - ancho);
			}
			break;
		case 3:
			x += dx;
			if (x > 500)
			{
				x = -ancho;
				y = rand() % (int)(g->VisibleClipBounds.Height - alto);
			}
			break;
		}
	}
	void Dibujar(Graphics^ g) override
	{
		Pen^ lapiz = gcnew Pen(Color::Black);
		SolidBrush^ brocha = gcnew SolidBrush(Color::FromArgb(colorARGB));
		g->FillRectangle(brocha, x, y, ancho, alto);
		g->DrawRectangle(lapiz, Area());
		if (colorARGB == Color::Blue.ToArgb())
		{
			g->DrawString(getPuntos().ToString(), gcnew Font("Arial", 8), Brushes::White, getX() + 15, getY() + 15);
		}
		else
		{
			g->DrawString(getPuntos().ToString(), gcnew Font("Arial", 8), Brushes::Black, getX() + 15, getY() + 15);
		}
	}
};
