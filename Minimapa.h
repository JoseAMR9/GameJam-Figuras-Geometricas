#pragma once
#include "Dependencias.h"

class Minimapa 
{
	private:
		int x1, y1;
		int x2, y2;
		int rondas;

		double xActual, yActual;
		double xDestino, yDestino;
		double velocidad = 1;

	public:
		Minimapa()
		{
			x1 = x2 = 500;
			y1 = 1;
			y2 = 282;
			rondas = 1;

			xActual = 525;
			yActual = 240;
			xDestino = 655;
			yDestino = 220;
		}
		Rectangle Area()
		{
			return Rectangle(x1, y1, x2 - x1, y2 - y1);
		}
		void DibujarLinea(Graphics^ g)
		{
			Pen^ lapiz = gcnew Pen(Color::Black, 2);
			g->DrawLine(lapiz, x1, y1, x2, y2);
		}
		void DibujarRectangulo1(Graphics^ g) 
		{
			Pen^ lapiz = gcnew Pen(Color::Black);
			// Rectángulo redondeado
			int rx = 520, ry = 220, ancho = 150, alto = 40, radio = 10;
			SolidBrush^ brocha = gcnew SolidBrush(Color::SkyBlue); // solo contorno

			System::Drawing::Drawing2D::GraphicsPath^ path = gcnew System::Drawing::Drawing2D::GraphicsPath();
			path->AddArc(rx, ry, radio, radio, 180, 90); // esquina superior izquierda
			path->AddArc(rx + ancho - radio, ry, radio, radio, 270, 90); // esquina superior derecha
			path->AddArc(rx + ancho - radio, ry + alto - radio, radio, radio, 0, 90); // esquina inferior derecha
			path->AddArc(rx, ry + alto - radio, radio, radio, 90, 90); // esquina inferior izquierda
			path->CloseFigure();

			g->FillPath(brocha, path);
			g->DrawPath(lapiz, path);
			g->DrawString("T1", gcnew Font("Monocraft", 7), Brushes::Black, 526, 225);
		}
		void DibujarRectangulo2(Graphics^ g) 
		{
			Pen^ lapiz = gcnew Pen(Color::Black);
			int rx = 635;        // posición X
			int ry = 90;        // posición Y más arriba
			int ancho = 40;      // ahora más estrecho
			int alto = 120;      // más alto que ancho para vertical
			int radio = 10;      // radio de esquinas

			SolidBrush^ brocha = gcnew SolidBrush(Color::Transparent);

			System::Drawing::Drawing2D::GraphicsPath^ path = gcnew System::Drawing::Drawing2D::GraphicsPath();
			path->AddArc(rx, ry, radio, radio, 180, 90);
			path->AddArc(rx + ancho - radio, ry, radio, radio, 270, 90);
			path->AddArc(rx + ancho - radio, ry + alto - radio, radio, radio, 0, 90);
			path->AddArc(rx, ry + alto - radio, radio, radio, 90, 90);
			path->CloseFigure();

			g->FillPath(brocha, path);
			g->DrawPath(lapiz, path);
			g->DrawString("T2", gcnew Font("Monocraft", 7), Brushes::Black, rx + 5, ry + 5);
		}
		void DibujarRectangulo3(Graphics^ g) 
		{
			Pen^ lapiz = gcnew Pen(Color::Black);
			// Rectángulo redondeado
			int rx = 520, ry = 35, ancho = 150, alto = 40, radio = 10;
			SolidBrush^ brocha = gcnew SolidBrush(Color::Transparent); // solo contorno

			System::Drawing::Drawing2D::GraphicsPath^ path = gcnew System::Drawing::Drawing2D::GraphicsPath();
			path->AddArc(rx, ry, radio, radio, 180, 90); // esquina superior izquierda
			path->AddArc(rx + ancho - radio, ry, radio, radio, 270, 90); // esquina superior derecha
			path->AddArc(rx + ancho - radio, ry + alto - radio, radio, radio, 0, 90); // esquina inferior derecha
			path->AddArc(rx, ry + alto - radio, radio, radio, 90, 90); // esquina inferior izquierda
			path->CloseFigure();

			g->FillPath(brocha, path);
			g->DrawPath(lapiz, path);
			g->DrawString("T3", gcnew Font("Monocraft", 7), Brushes::Black, 526, 39);
		}
		void DibujarCirculoJugador(Graphics^ g, int jugadorColorg)
		{
			int tam = 10;
			Pen^ lapiz = gcnew Pen(Color::Black);
			SolidBrush^ brocha = gcnew SolidBrush(Color::FromArgb(jugadorColorg));
			g->FillEllipse(brocha, xActual, yActual, tam, tam);
			g->DrawEllipse(lapiz, xActual, yActual, tam, tam);
			
		}
		void MoverCirculoJugador(Graphics^ g, int jugadorColorg, int tramoActual) 
		{
			switch (tramoActual)
			{
			case 1:
				xDestino = 655;
				yDestino = 240;
				break;

			case 2:
				xDestino = 655;
				yDestino = 100;
				break;

			case 3:
				xDestino = 520;
				yDestino = 40;
				break;
			}
			if (xActual < xDestino) xActual += velocidad;
			else if (xActual > xDestino) xActual -= velocidad;

			if (tramoActual == 2)
			{
				if (yActual < yDestino) yActual += velocidad;
				else if (yActual > yDestino) yActual -= velocidad;
			}

			DibujarCirculoJugador(g, jugadorColorg);
		}
		void setXActual(int _xActual) 
		{
			xActual = _xActual;
		}
		void setYActual(int _yActual)
		{
			yActual = _yActual;
		}
};
