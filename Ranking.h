#pragma once
#include "string"
#include "ClaseRanking.h"
namespace Galaga {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Ranking
	/// </summary>
	public ref class Ranking : public System::Windows::Forms::Form
	{
	public:
		Ranking(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Ranking()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:
	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		String^ jugadores;
		String^ puntajes;
	private: System::Windows::Forms::Timer^  timer1;

	private: System::ComponentModel::IContainer^  components;


#pragma region Windows Form Designer generated code
			 /// <summary>
			 /// Required method for Designer support - do not modify
			 /// the contents of this method with the code editor.
			 /// </summary>
			 void InitializeComponent(void)
			 {
				 this->components = (gcnew System::ComponentModel::Container());
				 System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Ranking::typeid));
				 this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
				 this->SuspendLayout();
				 // 
				 // timer1
				 // 
				 this->timer1->Enabled = true;
				 this->timer1->Tick += gcnew System::EventHandler(this, &Ranking::timer1_Tick);
				 // 
				 // Ranking
				 // 
				 this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				 this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
				 this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
				 this->ClientSize = System::Drawing::Size(634, 376);
				 this->MaximumSize = System::Drawing::Size(650, 415);
				 this->MinimumSize = System::Drawing::Size(650, 415);
				 this->Name = L"Ranking";
				 this->Text = L"Ranking";
				 this->Load += gcnew System::EventHandler(this, &Ranking::Ranking_Load);
				 this->ResumeLayout(false);

			 }
#pragma endregion
	public: void RecibirNombresYPuntajes(String^ jugadores, String^ puntajes)
	{
		this->jugadores = jugadores;
		this->puntajes = puntajes;
	}
	private: System::Void Ranking_Load(System::Object^  sender, System::EventArgs^  e) {}
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		Graphics^ g = this->CreateGraphics();
		Bitmap^ bit = gcnew Bitmap(gcnew String("RankingStars.jpg"));
		BufferedGraphicsContext^ espacio_buffer = BufferedGraphicsManager::Current;
		BufferedGraphics^ buffer = espacio_buffer->Allocate(g, this->ClientRectangle);
		buffer->Graphics->Clear(Color::White);
		System::Drawing::Rectangle porción = System::Drawing::Rectangle(0, 0, g->VisibleClipBounds.Width, g->VisibleClipBounds.Height);
		System::Drawing::Rectangle zoom = System::Drawing::Rectangle(0, 0, g->VisibleClipBounds.Width, g->VisibleClipBounds.Height);
		buffer->Graphics->DrawImage(bit, zoom, porción, GraphicsUnit::Pixel);

		buffer->Graphics->DrawString("Puntajes Anteriores", gcnew System::Drawing::Font("Harrington", 27), gcnew System::Drawing::SolidBrush(System::Drawing::Color::Black), System::Drawing::Rectangle(200, 50, 1000, 200));
		buffer->Graphics->DrawString(jugadores, gcnew System::Drawing::Font("Arial", 20), gcnew System::Drawing::SolidBrush(System::Drawing::Color::Black), System::Drawing::Rectangle(200, 120, 200, 700));
		buffer->Graphics->DrawString(puntajes, gcnew System::Drawing::Font("Arial", 20), gcnew System::Drawing::SolidBrush(System::Drawing::Color::Black), System::Drawing::Rectangle(400, 120, 200, 700));
		//---------
		buffer->Render(g);
		delete buffer;
		delete espacio_buffer;
		delete g;
	}
	};
}
