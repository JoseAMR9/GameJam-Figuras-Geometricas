#pragma once
#include "Minimapa.h"
#include "Jugador.h"
#include "Triangulo.h"
#include "Circulo.h"
#include "Cuadrado.h"

class Juego 
{
	private:
		int tramos;
		bool juegoGanado;
		int tiempo;
		clock_t tiempoInicio;
		int tiempoRestante;
		Minimapa* minimapa;
		Jugador* jugador;
		Triangulo* triangulo;
		Circulo* circulo;
		Cuadrado* cuadrado;

	public:
		Juego()
		{
			srand(time(NULL));
			tramos = 1;
			juegoGanado = false;
			tiempo = 90;
			tiempoRestante = tiempo;
			tiempoInicio = clock();
			minimapa = new Minimapa();
			jugador = new Jugador();
			triangulo = new Triangulo();
			circulo = new Circulo();
			cuadrado = new Cuadrado();
		}
		~Juego() 
		{
			delete minimapa;
			delete jugador;
			delete triangulo;
			delete circulo;
			delete cuadrado;
		}
		void ReiniciarTriangulo()
		{
			int aleatorio = rand() % 3;
			if (aleatorio == 0) triangulo->setColorARGB(Color::Yellow.ToArgb());
			else if (aleatorio == 1) triangulo->setColorARGB(Color::Blue.ToArgb());
			else triangulo->setColorARGB(Color::Red.ToArgb());

			if (tramos == 1) {
				triangulo->setX(460);
				triangulo->setY((rand() % 213) + 30);
				triangulo->setDX((rand() % 12) + 7);
				triangulo->setDY(0);
			}
			else if (tramos == 2) {
				triangulo->setY(0);
				triangulo->setX(rand() % 270);
				triangulo->setDY((rand() % 5) + 3);
				triangulo->setDX(0);
			}
			else if (tramos == 3)
			{
				triangulo->setX(-triangulo->getAncho());
				triangulo->setY((rand() % 213) + 30);
				triangulo->setDX((rand() % 12) + 7);
				triangulo->setDY(0);
			}
		}
		void ReiniciarCirculo()
		{
			int aleatorio = rand() % 3;
			if (aleatorio == 0) circulo->setColorARGB(Color::Yellow.ToArgb());
			else if (aleatorio == 1) circulo->setColorARGB(Color::Blue.ToArgb());
			else circulo->setColorARGB(Color::Red.ToArgb());

			if (tramos == 1) {
				circulo->setX(460);
				circulo->setY((rand() % 213) + 30);
				circulo->setDX((rand() % 12) + 7);
				circulo->setDY(0);
			}
			else if (tramos == 2) {
				circulo->setY(0);
				circulo->setX(rand() % 270);
				circulo->setDY((rand() % 5) + 3);
				circulo->setDX(0);
			}
			else if (tramos == 3)
			{
				circulo->setX(-circulo->getAncho());
				circulo->setY((rand() % 213) + 30);
				circulo->setDX((rand() % 12) + 7);
				circulo->setDY(0);
			}
		}
		void ReiniciarCuadrado()
		{
			int aleatorio = rand() % 3;
			if (aleatorio == 0) cuadrado->setColorARGB(Color::Yellow.ToArgb());
			else if (aleatorio == 1) cuadrado->setColorARGB(Color::Blue.ToArgb());
			else cuadrado->setColorARGB(Color::Red.ToArgb());

			if (tramos == 1) {
				cuadrado->setX(460);
				cuadrado->setY((rand() % 213) + 30);
				cuadrado->setDX((rand() % 12) + 7);
				cuadrado->setDY(0);
			}
			else if (tramos == 2) {
				cuadrado->setX(rand() % 270);
				cuadrado->setY(0);
				cuadrado->setDX(0);
				cuadrado->setDY((rand() % 5) + 3);
			}
			else if (tramos == 3)
			{
				cuadrado->setX(-cuadrado->getAncho());
				cuadrado->setY((rand() % 213) + 30);
				cuadrado->setDX((rand() % 12) + 7);
				cuadrado->setDY(0);
			}
		}
		void ActualizarInformacion(Graphics^ g) 
		{
			g->DrawString("Tramo: " + tramos.ToString(), gcnew Font("Monocraft", 10), Brushes::Black,0,0);
			g->DrawString("Minimapa", gcnew Font("Monocraft", 10), Brushes::Black, 508,5);
			g->DrawString("Lados: " + jugador->getLados(), gcnew Font("Monocraft", 8), Brushes::Black, 505, 115);
			g->DrawString("Numeros: " + jugador->getPuntos(), gcnew Font("Monocraft", 8), Brushes::Black, 505, 130);
			g->DrawString("Sum.Ang: " + jugador->getSumAngulos(), gcnew Font("Monocraft", 8), Brushes::Black, 505, 145);
			g->DrawString("Velocidad: " + jugador->getVelocidad(), gcnew Font("Monocraft", 8), Brushes::Black, 505, 160);
		}
		void MovimientoAutomatico()
		{
			int velocidad = jugador->getVelocidad();

			switch (tramos)
			{
			case 1:
				jugador->setY(jugador->getY() + jugador->getDY());


				if (jugador->getY() <= 0)
					jugador->setDY(velocidad);
				else if (jugador->getY() + jugador->getAlto() >= 282)
					jugador->setDY(-velocidad);
				break;

			case 2: 
				jugador->setX(jugador->getX() + jugador->getDX());

				
				if (jugador->getX() <= 0)
					jugador->setDX(velocidad);
				else if (jugador->getX() + jugador->getAncho() >= 500)
					jugador->setDX(-velocidad);
				break;

			case 3:
				jugador->setY(jugador->getY() + jugador->getDY());

				if (jugador->getY() <= 0)
					jugador->setDY(velocidad);
				else if (jugador->getY() + jugador->getAlto() >= 282)
					jugador->setDY(-velocidad);
				break;
			}
		}
		void MovimientoJugador(bool accion, Keys tecla)
		{
			int velocidad = jugador->getVelocidad();

			if (accion == true) 
			{
				if (tramos == 1) 
				{
					if (tecla == Keys::Up) jugador->setDY(-velocidad);
					else if (tecla == Keys::Down) jugador->setDY(velocidad);
				}
				else if (tramos == 2) 
				{
					if (tecla == Keys::Left) jugador->setDX(-velocidad);
					else if (tecla == Keys::Right) jugador->setDX(velocidad);
				}
				else if (tramos == 3)
				{
					if (tecla == Keys::Up) jugador->setDY(-velocidad);
					else if (tecla == Keys::Down) jugador->setDY(velocidad);
				}
			}
			else 
			{
				if (tecla == Keys::Up) jugador->setDY(0);
				else if (tecla == Keys::Down) jugador->setDY(0);
				else if (tecla == Keys::Left) jugador->setDX(0);
				else if (tecla == Keys::Right) jugador->setDX(0);
			}
		}
		void Mover(Graphics^ g, int tramos) 
		{
			jugador->Mover(g, tramos);
			triangulo->Mover(g, tramos);
			circulo->Mover(g, tramos);
			cuadrado->Mover(g, tramos);

			if (tramos == 1)
			{
				if (triangulo->getX() <= 0) ReiniciarTriangulo();
				if (circulo->getX() <= 0)   ReiniciarCirculo();
				if (cuadrado->getX() <= 0)  ReiniciarCuadrado();
			}
			else if (tramos == 2)
			{
				if (triangulo->getY() >= g->VisibleClipBounds.Height) ReiniciarTriangulo();
				if (circulo->getY() >= g->VisibleClipBounds.Height)   ReiniciarCirculo();
				if (cuadrado->getY() >= g->VisibleClipBounds.Height)  ReiniciarCuadrado();
			}
			else if (tramos == 3)
			{
				if (triangulo->getX() > 460) ReiniciarTriangulo();
				if (circulo->getX() > 460)   ReiniciarCirculo();
				if (cuadrado->getX() > 460)  ReiniciarCuadrado();
			}
		}
		void Mostrar(Graphics^ g) 
		{
			ActualizarInformacion(g);
			minimapa->DibujarLinea(g);
			minimapa->DibujarRectangulo1(g);
			minimapa->DibujarRectangulo2(g);
			minimapa->DibujarRectangulo3(g);
			minimapa->MoverCirculoJugador(g, jugador->getColorARGB(), tramos);

			jugador->Dibujar(g);
			triangulo->Dibujar(g);
			circulo->Dibujar(g);
			cuadrado->Dibujar(g);

			ActualizarTiempo();
			g->DrawString("Tiempo restante: " + tiempoRestante.ToString(), gcnew Font("Monocraft", 10), Brushes::Black, 0, 20);
			if (GetTiempoRestante() == 0) 
			{
				g->DrawString("SE TE ACABO EL TIEMPO", gcnew Font("Monocraft", 14, FontStyle::Bold), Brushes::Black, 60, 150);
				g->DrawString("YOU LOST", gcnew Font("Monocraft", 14, FontStyle::Bold), Brushes::Black, 120, 190);
			}
			if (jugador->getLados() == 10)
			{
				g->DrawString("FELICIDADES LLEGASTE AL DECÁGONO", gcnew Font("Monocraft", 14, FontStyle::Bold), Brushes::Black, 60, 150);
				g->DrawString("YOU WIN", gcnew Font("Monocraft", 14, FontStyle::Bold), Brushes::Black, 120, 190);
			}
		}
		void Colisiones(Figuras* figura)
		{
			if (jugador->Area().IntersectsWith(figura->Area()))
			{
				if (jugador->getColorARGB() == figura->getColorARGB())
				{
					jugador->setPuntos(jugador->getPuntos() + figura->getPuntos());
					jugador->CambiarForma();

					if (jugador->getLados() == 5) 
					{
						tramos++;
						jugador->setX(100);
						jugador->setY(220);
						ReiniciarTriangulo();
						ReiniciarCirculo();
						ReiniciarCuadrado();
					}
					if (jugador->getLados() == 8)
					{
						tramos++;
						jugador->setX(440);
						jugador->setY(100);
						ReiniciarTriangulo();
						ReiniciarCirculo();
						ReiniciarCuadrado();
					}
					if (jugador->getLados() == 10)
					{
						juegoGanado = true;
					}
				}
				else
				{
					if (jugador->getPuntos() < figura->getPuntos()) 
					{
						jugador->setPuntos(0);
						if (jugador->getLados() > 3) jugador->setLados(jugador->getLados() - 1);
					}
					else 
					{
						jugador->setPuntos(jugador->getPuntos() - figura->getPuntos());
						if (jugador->getLados() > 3) jugador->setLados(jugador->getLados() - 1);
					}
				}
				if (tramos == 1) 
				{
					figura->setX(460); 
					figura->setY((rand() % 213) + 30); 
					figura->setDX((rand() % 12) + 7);
				}
				else if (tramos == 2) 
				{
					figura->setX(rand() % 270); 
					figura->setY(0); 
					figura->setDY((rand() % 5) + 3);
					minimapa->setXActual(655);
					minimapa->setYActual(190);
				}
				else if (tramos == 3)
				{
					figura->setX(40); 
					figura->setY((rand() % 213) + 30); 
					figura->setDX((rand() % 12) + 7);
					minimapa->setXActual(655);
					minimapa->setYActual(60);
				}
			}
		}
		void ActualizarColisiones()
		{
			Colisiones(triangulo);
			Colisiones(circulo);
			Colisiones(cuadrado);
		}
		void ActualizarTiempo() {
			tiempoRestante = tiempo - (clock() - tiempoInicio) / CLOCKS_PER_SEC;
			if (tiempoRestante < 0) tiempoRestante = 0;
		}
		int getTramos() 
		{
			return tramos;
		}
		bool getJuegoGanado()
		{
			return juegoGanado;
		}
		int GetTiempoRestante() {
			return tiempoRestante;
		}
};
