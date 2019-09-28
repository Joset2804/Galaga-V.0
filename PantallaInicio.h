#pragma once
#include "MostrarJuego.h"
#include "Instrucciones.h"
#include "Ranking.h"
#include "ClaseRanking.h"
#include "CargarPartida.h"
#include "Puntaje.h"

namespace Galaga {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for PantallaInicio
	/// </summary>
	public ref class PantallaInicio : public System::Windows::Forms::Form
	{
	public:
		PantallaInicio(void)
		{
			objClaseRanking = new ClaseRanking();
			objCargarPartida = new CargarPartida();
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~PantallaInicio()
		{

			if (components)
			{
				delete objClaseRanking;
				delete objCargarPartida;
			}
		}
	private: System::Windows::Forms::TextBox^  textBox1;
	protected:
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button1;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		String^ lista_puntajes;
		String^ lista_jugadores;
		ClaseRanking* objClaseRanking;
		CargarPartida* objCargarPartida;
		int x, y, nivel, vidas, puntaje;

	private: System::Windows::Forms::Button^  button4;
			 System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
			 /// <summary>
			 /// Required method for Designer support - do not modify
			 /// the contents of this method with the code editor.
			 /// </summary>
			 void InitializeComponent(void)
			 {
				 System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(PantallaInicio::typeid));
				 this->textBox1 = (gcnew System::Windows::Forms::TextBox());
				 this->label1 = (gcnew System::Windows::Forms::Label());
				 this->button3 = (gcnew System::Windows::Forms::Button());
				 this->button2 = (gcnew System::Windows::Forms::Button());
				 this->button1 = (gcnew System::Windows::Forms::Button());
				 this->button4 = (gcnew System::Windows::Forms::Button());
				 this->SuspendLayout();
				 // 
				 // textBox1
				 // 
				 this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->textBox1->Location = System::Drawing::Point(218, 291);
				 this->textBox1->MaxLength = 10;
				 this->textBox1->Name = L"textBox1";
				 this->textBox1->Size = System::Drawing::Size(114, 22);
				 this->textBox1->TabIndex = 14;
				 // 
				 // label1
				 // 
				 this->label1->AutoSize = true;
				 this->label1->BackColor = System::Drawing::SystemColors::Control;
				 this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->label1->Location = System::Drawing::Point(135, 295);
				 this->label1->Name = L"label1";
				 this->label1->Size = System::Drawing::Size(77, 18);
				 this->label1->TabIndex = 13;
				 this->label1->Text = L"Usuario: ";
				 // 
				 // button3
				 // 
				 this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->button3->Location = System::Drawing::Point(268, 355);
				 this->button3->Name = L"button3";
				 this->button3->Size = System::Drawing::Size(167, 30);
				 this->button3->TabIndex = 12;
				 this->button3->Text = L"Puntajes Anteriores";
				 this->button3->UseVisualStyleBackColor = true;
				 this->button3->Click += gcnew System::EventHandler(this, &PantallaInicio::button3_Click);
				 // 
				 // button2
				 // 
				 this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->button2->Location = System::Drawing::Point(514, 355);
				 this->button2->Name = L"button2";
				 this->button2->Size = System::Drawing::Size(120, 30);
				 this->button2->TabIndex = 11;
				 this->button2->Text = L"Instrucciones";
				 this->button2->UseVisualStyleBackColor = true;
				 this->button2->Click += gcnew System::EventHandler(this, &PantallaInicio::button2_Click);
				 // 
				 // button1
				 // 
				 this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->button1->Location = System::Drawing::Point(387, 267);
				 this->button1->Name = L"button1";
				 this->button1->Size = System::Drawing::Size(167, 74);
				 this->button1->TabIndex = 10;
				 this->button1->Text = L"Jugar";
				 this->button1->UseVisualStyleBackColor = true;
				 this->button1->Click += gcnew System::EventHandler(this, &PantallaInicio::button1_Click);
				 // 
				 // button4
				 // 
				 this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->button4->Location = System::Drawing::Point(55, 355);
				 this->button4->Name = L"button4";
				 this->button4->Size = System::Drawing::Size(128, 30);
				 this->button4->TabIndex = 17;
				 this->button4->Text = L"Cargar Partida";
				 this->button4->UseVisualStyleBackColor = true;
				 this->button4->Click += gcnew System::EventHandler(this, &PantallaInicio::button4_Click);
				 // 
				 // PantallaInicio
				 // 
				 this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				 this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
				 this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
				 this->ClientSize = System::Drawing::Size(693, 397);
				 this->Controls->Add(this->button4);
				 this->Controls->Add(this->textBox1);
				 this->Controls->Add(this->label1);
				 this->Controls->Add(this->button3);
				 this->Controls->Add(this->button2);
				 this->Controls->Add(this->button1);
				 this->MaximumSize = System::Drawing::Size(709, 436);
				 this->MinimumSize = System::Drawing::Size(709, 436);
				 this->Name = L"PantallaInicio";
				 this->Text = L"PantallaInicio";
				 this->Load += gcnew System::EventHandler(this, &PantallaInicio::PantallaInicio_Load);
				 this->ResumeLayout(false);
				 this->PerformLayout();

			 }
#pragma endregion
	private: System::Void PantallaInicio_Load(System::Object^  sender, System::EventArgs^  e) {
	}
			 void MarshalString(String ^ s, std::string& os) //Pasar String^ a std::string 
			 {
				 using namespace Runtime::InteropServices;
				 const char* chars = (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
				 os = chars;
				 Marshal::FreeHGlobal(IntPtr((void*)chars));
			 }
			 
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) { //INICIO NORMAL
		if (textBox1->Text->Length > 0)
		{
			MostrarJuego^ objMostrarJuego = gcnew MostrarJuego();
			objMostrarJuego->ShowDialog();
			if (!objMostrarJuego->GetCERRADO())
			{
				std::string aux;
				MarshalString(textBox1->Text, aux);
				objClaseRanking->EscribirJugador(aux);
				objClaseRanking->EscribirPuntaje(objMostrarJuego->GetPuntajeMostrar());
			}
			else //Si fue cerrado
			{
				std::string aux;
				MarshalString(textBox1->Text, aux);
				x = objMostrarJuego->EnviarX();
				y = objMostrarJuego->EnviarY();
				nivel = objMostrarJuego->EnviarNivel();
				vidas = objMostrarJuego->EnviarVidas();
				puntaje = objMostrarJuego->EnviarPuntaje();
				objCargarPartida->EscribirDatosPartida(x, y, nivel, vidas, puntaje, aux);
				MessageBox::Show("Su partida ha sido guardada.");
			}
			delete objMostrarJuego;
		}
		else
		{
			MessageBox::Show("Por favor, ingrese su nombre de usuario.");
		}
	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) { //INSTRUCCIONES
		Instrucciones^ objInstrucciones = gcnew Instrucciones();
		objInstrucciones->ShowDialog();
		delete objInstrucciones;
	}
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) { //RANKING
		Ranking^ objRanking = gcnew Ranking();
		objClaseRanking->LeerPuntajes();
		objClaseRanking->LeerJugadores();
		std::string aux_puntajes = objClaseRanking->GetInformaciónPuntaje(); //Copia la información recopilada en un auxiliar
		std::string aux_jugadores = objClaseRanking->GetInformaciónJugadores(); //Copia la información recopilada en un auxiliar

		lista_puntajes = gcnew String(aux_puntajes.c_str()); //Inicializa lista_puntajes y le da como parámetro el aux que tiene el dato de puntajes
		lista_jugadores = gcnew String(aux_jugadores.c_str()); //Inicializa lista_jugadores y le da como parámetro el aux que tiene el dato de nombres

		objRanking->RecibirNombresYPuntajes(lista_jugadores, lista_puntajes); //Envía la información (string) al formulario Ranking para que, finalmente, los muestre
		objRanking->ShowDialog();
		delete objRanking;
	}
	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) { //CARGAR PARTIDA
		MostrarJuego^ objMostrarJuego = gcnew MostrarJuego();
		std::string nombre;
		objCargarPartida->LeerDatosPartida();
		x = objCargarPartida->GetX();
		y = objCargarPartida->GetY();
		nivel = objCargarPartida->GetNivel();
		vidas = objCargarPartida->GetVidas();
		puntaje = objCargarPartida->GetPuntaje();
		nombre = objCargarPartida->GetNombre();
		objMostrarJuego->RecibirDatosPartida(x, y, nivel, vidas, puntaje);
		objMostrarJuego->ShowDialog();
		//ESTO ESTÁ BIEN
		if (!objMostrarJuego->GetCERRADO()) //true: el juego fue cerrado | false: el juego fue terminado
		{
			objClaseRanking->EscribirJugador(nombre);
			objClaseRanking->EscribirPuntaje(objMostrarJuego->GetPuntajeMostrar());
		}
		else //Si fue cerrado
		{
			x = objMostrarJuego->EnviarX();
			y = objMostrarJuego->EnviarY();
			nivel = objMostrarJuego->EnviarNivel();
			vidas = objMostrarJuego->EnviarVidas();
			puntaje = objMostrarJuego->EnviarPuntaje();
			objCargarPartida->EscribirDatosPartida(x, y, nivel, vidas, puntaje, nombre);
			MessageBox::Show("Su partida ha sido guardada.");
		}
		delete objMostrarJuego;
	}
};
}