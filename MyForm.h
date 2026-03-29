#pragma once
#include "Juego.h"

namespace GameJam {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{

		Juego* juego;
		bool automatico = false;

	public:
		MyForm(void)
		{
			InitializeComponent();
			juego = new Juego();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
			delete juego;
		}
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	protected:
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(159, 103);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(214, 87);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Jugador";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(548, 103);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(206, 87);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Automatico";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(922, 343);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyUp);
			this->ResumeLayout(false);

		}
#pragma endregion

	Void timer1_Tick(Object^ sender, EventArgs^ e) 
	{
		Graphics^ g = this->CreateGraphics();

		BufferedGraphicsContext^ espaciobuffer = BufferedGraphicsManager::Current;
		BufferedGraphics^ buffer = espaciobuffer->Allocate(g, this->ClientRectangle);
		PintarSecciones(buffer->Graphics);

		if (automatico) {
			juego->MovimientoAutomatico();
		}

		juego->Mover(buffer->Graphics, juego->getTramos());
		juego->ActualizarColisiones();
		juego->Mostrar(buffer->Graphics);

		if (juego->getJuegoGanado() || juego->GetTiempoRestante() == 0)
		{
			timer1->Enabled = false;
		}

		buffer->Render(g);

		delete buffer;
	}
	Void MyForm_KeyDown(Object^ sender, KeyEventArgs^ e)
	{

		juego->MovimientoJugador(true, e->KeyCode);

	}
	Void MyForm_KeyUp(Object^ sender, KeyEventArgs^ e)
	{

		juego->MovimientoJugador(false, e->KeyCode);

	}
	private:
		void PintarSecciones(Graphics^ g)
		{
			if (juego->getTramos() == 1) 
			{
				SolidBrush^ brocha1 = gcnew SolidBrush(Color::SkyBlue);
				g->FillRectangle(brocha1, 0, 0, 500, 282);

				SolidBrush^ brocha2 = gcnew SolidBrush(Color::White);
				g->FillRectangle(brocha2, 500, 1, 500, 282);
			}
			else if (juego->getTramos() == 2) 
			{
				SolidBrush^ brocha1 = gcnew SolidBrush(Color::LightGreen);
				g->FillRectangle(brocha1, 0, 0, 500, 282);

				SolidBrush^ brocha2 = gcnew SolidBrush(Color::White);
				g->FillRectangle(brocha2, 500, 1, 500, 282);
			}
			else if (juego->getTramos() == 3)
			{
				SolidBrush^ brocha1 = gcnew SolidBrush(Color::PaleVioletRed);
				g->FillRectangle(brocha1, 0, 0, 500, 282);

				SolidBrush^ brocha2 = gcnew SolidBrush(Color::White);
				g->FillRectangle(brocha2, 500, 1, 500, 282);
			}
		}
	Void button1_Click(Object^ sender, EventArgs^ e) 
	{
		this->button1->Visible = false;
		this->button2->Visible = false;
		this->timer1->Enabled = true;
		this->Focus();
	}
	Void button2_Click(Object^ sender, EventArgs^ e) 
	{
		this->button2->Visible = false;
		this->button1->Visible = false; 
		this->timer1->Enabled = true;
		automatico = true;
	}
};
}
