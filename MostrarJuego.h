#pragma once
#include "Juego.h"
#include "time.h"

namespace Galaga {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MostrarJuego
	/// </summary>
	public ref class MostrarJuego : public System::Windows::Forms::Form
	{
	public:
		MostrarJuego(void)
		{
			hora_inicial_disparo_grande = time(NULL);
			hora_inicial_creación_asteroide = time(NULL);
			hora_inicial_eliminación_asteroide = time(NULL);
			hora_inicial_movimiento_enemigos = time(NULL);
			rd = gcnew Random();
			objJuego = new Juego<void>();
			iniciar_juego = false;
			recibir_x = recibir_y = recibir_nivel = recibir_vidas = recibir_puntaje = 0;
			enviar_x = enviar_y = enviar_nivel = enviar_vidas = enviar_puntaje = 0;
			CERRADO = true;
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MostrarJuego()
		{
			if (components)
			{
				delete objJuego;
				delete components;
			}
		}
	private: System::ComponentModel::IContainer^  components;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>

		time_t hora_inicial_disparo_grande;
		time_t hora_inicial_creación_asteroide;
		time_t hora_inicial_eliminación_asteroide;
		time_t hora_inicial_movimiento_enemigos;
		Juego<void>* objJuego;
		Dirección teclapulsada;
		Random^ rd;
		bool nueva_bala;
		bool iniciar_juego;
		int puntaje_mostrar;
		int recibir_x, recibir_y, recibir_nivel, recibir_vidas, recibir_puntaje;
		int enviar_x, enviar_y, enviar_nivel, enviar_vidas, enviar_puntaje;
		bool CERRADO;

	private: System::Windows::Forms::Timer^  timer1;



#pragma region Windows Form Designer generated code
			 /// <summary>
			 /// Required method for Designer support - do not modify
			 /// the contents of this method with the code editor.
			 /// </summary>
			 void InitializeComponent(void)
			 {
				 this->components = (gcnew System::ComponentModel::Container());
				 this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
				 this->SuspendLayout();
				 // 
				 // timer1
				 // 
				 this->timer1->Enabled = true;
				 this->timer1->Interval = 10;
				 this->timer1->Tick += gcnew System::EventHandler(this, &MostrarJuego::timer1_Tick);
				 // 
				 // MostrarJuego
				 // 
				 this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				 this->ClientSize = System::Drawing::Size(1084, 961);
				 this->MaximumSize = System::Drawing::Size(1100, 1000);
				 this->MinimumSize = System::Drawing::Size(1100, 1000);
				 this->Name = L"MostrarJuego";
				 this->Text = L"MostrarJuego";
				 this->Load += gcnew System::EventHandler(this, &MostrarJuego::MostrarJuego_Load);
				 this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MostrarJuego::MostrarJuego_KeyDown);
				 this->ResumeLayout(false);

			 }
#pragma endregion
	public: int GetPuntajeMostrar() { return puntaje_mostrar; }
	public: int EnviarX() { return enviar_x; }
	public: int EnviarY() { return enviar_y; }
	public: int EnviarNivel() { return enviar_nivel; }
	public: int EnviarVidas() { return enviar_vidas; }
	public: int EnviarPuntaje() { return enviar_puntaje; }
	public: bool GetCERRADO() { return CERRADO; }
	public: void RecibirDatosPartida(int x, int y, int nivel, int vidas, int puntaje)
	{
		recibir_x = x;
		recibir_y = y;
		recibir_nivel = nivel;
		recibir_vidas = vidas;
		recibir_puntaje = puntaje;
	}
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e)
	{
		Graphics^ g = this->CreateGraphics();
		BufferedGraphicsContext^ espacio_buffer = BufferedGraphicsManager::Current;
		BufferedGraphics^ buffer = espacio_buffer->Allocate(g, this->ClientRectangle);
		buffer->Graphics->Clear(Color::White);
		Bitmap^ bit = gcnew Bitmap(gcnew String("Background.jpeg"));
		System::Drawing::Rectangle porción = System::Drawing::Rectangle(0, 0, bit->Width, bit->Height);
		System::Drawing::Rectangle zoom = System::Drawing::Rectangle(0, 0, g->VisibleClipBounds.Width, g->VisibleClipBounds.Height);
		//**********************************************************************
		buffer->Graphics->DrawImage(bit, zoom, porción, GraphicsUnit::Pixel); //FONDO
		if (iniciar_juego) //AL INICIAR EL JUEGO
		{
			if (recibir_x == 0 && recibir_y == 0 && recibir_nivel == 0)
			{
				objJuego->AñadirEnemigos(buffer->Graphics);
				objJuego->CrearTanqueJugador(buffer->Graphics);
				objJuego->AgregarVidasIniciales(buffer->Graphics, 10);
			}
			else
			{
				objJuego->SetNivel(recibir_nivel);
				objJuego->AñadirEnemigos(buffer->Graphics);
				objJuego->CrearTanqueJugador(buffer->Graphics);
				objJuego->AgregarVidasIniciales(buffer->Graphics, recibir_vidas);
				objJuego->GetJugador()->SetX(recibir_x);
				objJuego->GetJugador()->SetY(recibir_y);
				objJuego->SetPuntaje(recibir_puntaje);
				objJuego->SetVidas(recibir_vidas);
			}
		}
		if (CERRADO)
		{
			enviar_x = objJuego->GetJugador()->GetX();
			enviar_y = objJuego->GetJugador()->GetY();
			enviar_nivel = objJuego->GetNivel();
			enviar_vidas = objJuego->GetJugador()->GetVida();
			enviar_puntaje = objJuego->GetPuntaje();
		}
		time_t hora_disparo_grande = time(NULL);
		time_t hora_creación_asteroide = time(NULL);
		time_t hora_eliminación_asteroide = time(NULL);
		time_t hora_mover_enemigos = time(NULL);
		if(difftime(hora_mover_enemigos, hora_inicial_movimiento_enemigos) > 1) //MOVER ENEMIGOS
		{
			objJuego->MoverEnemigosJ(buffer->Graphics);
			hora_inicial_movimiento_enemigos = time(NULL);
		}
		if (difftime(hora_disparo_grande, hora_inicial_disparo_grande) > 2)
		{
			objJuego->DispararEnemigos();
			hora_inicial_disparo_grande = time(NULL);
		}
		if (difftime(hora_creación_asteroide, hora_inicial_creación_asteroide) > 2)
		{
			objJuego->AgregarAsteroide(buffer->Graphics);
			hora_inicial_creación_asteroide = time(NULL);
		}
		if (difftime(hora_eliminación_asteroide, hora_inicial_eliminación_asteroide) > 4)
		{
			objJuego->EliminarAsteroide(buffer->Graphics);
			hora_inicial_eliminación_asteroide = time(NULL);
		}
		objJuego->CambioNivel(buffer->Graphics);
		objJuego->MoverTodos(buffer->Graphics, teclapulsada);
		if ((objJuego->GetNivel() == 6 || objJuego->GetVidaJugador() <= 0) && timer1->Enabled)
		{
			timer1->Enabled = false;
			puntaje_mostrar = objJuego->GetPuntaje();
			MessageBox::Show("GANASTE! :) " + "  Tu puntaje fue de " + objJuego->GetPuntaje().ToString() + " puntos");
			CERRADO = false;
			this->Close();
		}
		this->Text = "Nivel: " + objJuego->GetNivel() + " | " + "Puntuación: " + objJuego->GetPuntaje(); //Mostrar Datos Ventana

		//**********************************************************************
		buffer->Render(g);
		nueva_bala = false;
		iniciar_juego = false;
		delete buffer;
		delete espacio_buffer;
		delete g;
		delete bit;
	}
	private: System::Void MostrarJuego_Load(System::Object^  sender, System::EventArgs^  e) {
		timer1->Enabled = true;
		iniciar_juego = true;
	}
	private: System::Void MostrarJuego_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		if (e->KeyCode == Keys::Left) { teclapulsada = izquierda; }
		if (e->KeyCode == Keys::Up) { teclapulsada = arriba; }
		if (e->KeyCode == Keys::Right) { teclapulsada = derecha; }
		if (e->KeyCode == Keys::Down) { teclapulsada = abajo; }
		if (e->KeyCode == Keys::C) { objJuego->DispararJugador(); teclapulsada = ninguno; }
		if (e->KeyCode == Keys::Space)
		{
			if (timer1->Enabled)
			{
				timer1->Enabled = false;
			}
			else
			{
				timer1->Enabled = true;
			}
		}
		objJuego->SetDX_DY(teclapulsada);
	}
	};
}