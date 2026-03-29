#pragma once
#include "Figuras.h"

class Jugador : public Figuras 
{
	private:
		int lados;
		int velocidad;
	public:
		Jugador() 
		{
			int aleatorio = rand() % 3;
			if (aleatorio == 0) colorARGB = Color::Yellow.ToArgb();
			else if (aleatorio == 1) colorARGB = Color::Blue.ToArgb();
			else colorARGB = Color::Red.ToArgb();

			x = 0;
			y = 100;
			dx = 8;
			dy = 8;
			ancho = alto = 40;
			puntos = 0;
			lados = 3;
			velocidad = 12;
		}
		void Mover(Graphics^ g, int tramos)
		{
			if (tramos == 1) 
			{
				if (y + dy > 0 && y + alto + dy < g->VisibleClipBounds.Height) y += dy;
			}
			else if (tramos == 2) 
			{
				if (x + dx > 0 && x + ancho + dx < g->VisibleClipBounds.Width) x += dx;
			}
			else if (tramos == 3) 
			{
				if (y + dy > 0 && y + alto + dy < g->VisibleClipBounds.Height) y += dy;
			}
		}
		void Dibujar(Graphics^ g) override 
		{
			Pen^ lapiz = gcnew Pen(Color::FromArgb(colorARGB));
			SolidBrush^ brocha = gcnew SolidBrush(Color::FromArgb(colorARGB));

			if (lados == 3)
			{
				g->DrawLine(lapiz, x, y + alto, x + ancho / 2, y);
				g->DrawLine(lapiz, x + ancho / 2, y, x + ancho, y + alto);
				g->DrawLine(lapiz, x + ancho, y + alto, x, y + alto);
			}
			else if (lados == 4)
			{
				g->FillRectangle(brocha, x, y, ancho, alto);
				g->DrawRectangle(lapiz, x, y, ancho, alto);
			}
			else if (lados == 5)
			{
				int centroX = x + ancho / 2;
				int centroY = y + alto / 2;
				int r = ancho / 2;

				// Coordenadas aproximadas para un pentágono
				int px1 = centroX;
				int py1 = y;
				int px2 = x + ancho;
				int py2 = y + alto / 2.5;
				int px3 = x + ancho * 0.8;
				int py3 = y + alto;
				int px4 = x + ancho * 0.2;
				int py4 = y + alto;
				int px5 = x;
				int py5 = y + alto / 2.5;

				g->DrawLine(lapiz, px1, py1, px2, py2);
				g->DrawLine(lapiz, px2, py2, px3, py3);
				g->DrawLine(lapiz, px3, py3, px4, py4);
				g->DrawLine(lapiz, px4, py4, px5, py5);
				g->DrawLine(lapiz, px5, py5, px1, py1);
			}
			else if (lados == 6) // HEXÁGONO
			{
				int px1 = x + ancho * 0.25; int py1 = y;
				int px2 = x + ancho * 0.75; int py2 = y;
				int px3 = x + ancho;       int py3 = y + alto / 2;
				int px4 = x + ancho * 0.75; int py4 = y + alto;
				int px5 = x + ancho * 0.25; int py5 = y + alto;
				int px6 = x;                int py6 = y + alto / 2;

				g->DrawLine(lapiz, px1, py1, px2, py2);
				g->DrawLine(lapiz, px2, py2, px3, py3);
				g->DrawLine(lapiz, px3, py3, px4, py4);
				g->DrawLine(lapiz, px4, py4, px5, py5);
				g->DrawLine(lapiz, px5, py5, px6, py6);
				g->DrawLine(lapiz, px6, py6, px1, py1);
			}

			else if (lados == 7) // HEPTÁGONO
			{
				int px1 = x + ancho * 0.5; int py1 = y;
				int px2 = x + ancho * 0.85; int py2 = y + alto * 0.15;
				int px3 = x + ancho;        int py3 = y + alto * 0.45;
				int px4 = x + ancho * 0.8;  int py4 = y + alto * 0.8;
				int px5 = x + ancho * 0.4;  int py5 = y + alto;
				int px6 = x + ancho * 0.1;  int py6 = y + alto * 0.7;
				int px7 = x;                int py7 = y + alto * 0.3;

				g->DrawLine(lapiz, px1, py1, px2, py2);
				g->DrawLine(lapiz, px2, py2, px3, py3);
				g->DrawLine(lapiz, px3, py3, px4, py4);
				g->DrawLine(lapiz, px4, py4, px5, py5);
				g->DrawLine(lapiz, px5, py5, px6, py6);
				g->DrawLine(lapiz, px6, py6, px7, py7);
				g->DrawLine(lapiz, px7, py7, px1, py1);
			}

			else if (lados == 8) // OCTÁGONO
			{
				int px1 = x + ancho * 0.3; int py1 = y;
				int px2 = x + ancho * 0.7; int py2 = y;
				int px3 = x + ancho;       int py3 = y + alto * 0.3;
				int px4 = x + ancho;       int py4 = y + alto * 0.7;
				int px5 = x + ancho * 0.7; int py5 = y + alto;
				int px6 = x + ancho * 0.3; int py6 = y + alto;
				int px7 = x;               int py7 = y + alto * 0.7;
				int px8 = x;               int py8 = y + alto * 0.3;

				g->DrawLine(lapiz, px1, py1, px2, py2);
				g->DrawLine(lapiz, px2, py2, px3, py3);
				g->DrawLine(lapiz, px3, py3, px4, py4);
				g->DrawLine(lapiz, px4, py4, px5, py5);
				g->DrawLine(lapiz, px5, py5, px6, py6);
				g->DrawLine(lapiz, px6, py6, px7, py7);
				g->DrawLine(lapiz, px7, py7, px8, py8);
				g->DrawLine(lapiz, px8, py8, px1, py1);
			}

			else if (lados == 9) // ENEÁGONO
			{
				int px1 = x + ancho * 0.5; int py1 = y;
				int px2 = x + ancho * 0.8; int py2 = y + alto * 0.1;
				int px3 = x + ancho;       int py3 = y + alto * 0.35;
				int px4 = x + ancho;       int py4 = y + alto * 0.65;
				int px5 = x + ancho * 0.8; int py5 = y + alto * 0.9;
				int px6 = x + ancho * 0.5; int py6 = y + alto;
				int px7 = x + ancho * 0.2; int py7 = y + alto * 0.9;
				int px8 = x;               int py8 = y + alto * 0.65;
				int px9 = x;               int py9 = y + alto * 0.35;

				g->DrawLine(lapiz, px1, py1, px2, py2);
				g->DrawLine(lapiz, px2, py2, px3, py3);
				g->DrawLine(lapiz, px3, py3, px4, py4);
				g->DrawLine(lapiz, px4, py4, px5, py5);
				g->DrawLine(lapiz, px5, py5, px6, py6);
				g->DrawLine(lapiz, px6, py6, px7, py7);
				g->DrawLine(lapiz, px7, py7, px8, py8);
				g->DrawLine(lapiz, px8, py8, px9, py9);
				g->DrawLine(lapiz, px9, py9, px1, py1);
			}

			else if (lados == 10) // DECÁGONO
			{
				int px1 = x + ancho * 0.5; int py1 = y;
				int px2 = x + ancho * 0.85; int py2 = y + alto * 0.15;
				int px3 = x + ancho;       int py3 = y + alto * 0.35;
				int px4 = x + ancho;       int py4 = y + alto * 0.65;
				int px5 = x + ancho * 0.85; int py5 = y + alto * 0.85;
				int px6 = x + ancho * 0.5; int py6 = y + alto;
				int px7 = x + ancho * 0.15; int py7 = y + alto * 0.85;
				int px8 = x;               int py8 = y + alto * 0.65;
				int px9 = x;               int py9 = y + alto * 0.35;
				int px10 = x + ancho * 0.15; int py10 = y + alto * 0.15;

				g->DrawLine(lapiz, px1, py1, px2, py2);
				g->DrawLine(lapiz, px2, py2, px3, py3);
				g->DrawLine(lapiz, px3, py3, px4, py4);
				g->DrawLine(lapiz, px4, py4, px5, py5);
				g->DrawLine(lapiz, px5, py5, px6, py6);
				g->DrawLine(lapiz, px6, py6, px7, py7);
				g->DrawLine(lapiz, px7, py7, px8, py8);
				g->DrawLine(lapiz, px8, py8, px9, py9);
				g->DrawLine(lapiz, px9, py9, px10, py10);
				g->DrawLine(lapiz, px10, py10, px1, py1);
			}
			g->DrawString(getPuntos().ToString(), gcnew Font("Arial", 8), Brushes::Black, getX() + 15, getY() + 15);
		}
		void CambiarForma() 
		{
			if (lados < 11) lados += 1;
		}
		void setLados(int _lados) 
		{
			lados = _lados;
		}
		void setVelocidad(int _velocidad) 
		{
			velocidad = _velocidad;
		}
		int getLados() 
		{
			return lados;
		}
		int getVelocidad() 
		{
			return velocidad;
		}
		int getSumAngulos() 
		{
			return (lados - 2) * 180;
		}
};
