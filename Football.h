#pragma once
#include "DrawingField.h"
#include "Form_for_drawing.h"
#include "Fut.h"
#include "Pole.h"
#include "Mach.h"


namespace IDZ_oop {

	constexpr int _Cursor = 1;
	constexpr int _Fut = 3;
	constexpr int _Ladya = 5;
	constexpr int _Pole = 7;
	constexpr int _Mach = 8;
	constexpr int _Delete = 9;

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Football_board
	/// </summary>
	public ref class Football_board : public System::Windows::Forms::Form
	{
	public:
		Football_board(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			maxpictureBox1Height = pictureBox1->Height;
			maxpictureBox1Width = pictureBox1->Width;
			isDown = false;

			Bitmap^ bitmap = gcnew Bitmap(pictureBox1->Size.Width, pictureBox1->Size.Height);
			Graphics^ g = Graphics::FromImage(bitmap);
			g->FillRectangle(gcnew SolidBrush(Color::White), 0, 0, pictureBox1->Width, pictureBox1->Height);
			pictureBox1->Image = bitmap;

			draw();

			cursorType = _Cursor;

		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Football_board()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;

	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::Button^ button8;
	private: System::Windows::Forms::Button^ button9;
	private: System::Windows::Forms::Button^ button10;
	private: System::Windows::Forms::Button^ button11;

	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;
	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(232, 7);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(742, 847);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &Football_board::pictureBox1_Click_1);
			this->pictureBox1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Football_board::pictureBox1_MouseDown);
			this->pictureBox1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Football_board::pictureBox1_MouseMove);
			this->pictureBox1->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Football_board::pictureBox1_MouseUp);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(50, 155);
			this->button1->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(140, 77);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Курсор";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Football_board::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(1086, 508);
			this->button2->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(140, 77);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Сохранить";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Football_board::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(50, 55);
			this->button3->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(140, 77);
			this->button3->TabIndex = 3;
			this->button3->Text = L"Удалить";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Football_board::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(50, 278);
			this->button4->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(140, 77);
			this->button4->TabIndex = 4;
			this->button4->Text = L"Удалить все";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Football_board::button4_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(982, 62);
			this->button5->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(244, 63);
			this->button5->TabIndex = 5;
			this->button5->Text = L"Футбольное поле";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &Football_board::button5_Click);
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(1929, 354);
			this->button7->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(117, 68);
			this->button7->TabIndex = 7;
			this->button7->Text = L"Ладья";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &Football_board::button7_Click);
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(1050, 287);
			this->button8->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(118, 68);
			this->button8->TabIndex = 8;
			this->button8->Text = L"мяч";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &Football_board::button8_Click);
			// 
			// button9
			// 
			// 
			this->button10->Location = System::Drawing::Point(1050, 159);
			this->button10->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(118, 68);
			this->button10->TabIndex = 10;
			this->button10->Text = L"футболист";
			this->button10->UseVisualStyleBackColor = true;
			this->button10->Click += gcnew System::EventHandler(this, &Football_board::button10_Click);
			// 
			// button11
			// 
			this->textBox2->Location = System::Drawing::Point(982, 14);
			this->textBox2->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(241, 26);
			this->textBox2->TabIndex = 13;
			this->textBox2->Text = L"Что добавить на поле\?";
			this->textBox2->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(13, 7);
			this->textBox3->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(211, 26);
			this->textBox3->TabIndex = 14;
			this->textBox3->Text = L"Кнопки управления";
			this->textBox3->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// Football_board
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1370, 599);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->button11);
			this->Controls->Add(this->button10);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->pictureBox1);
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->Name = L"Football_board";
			this->Text = L"Football";
			this->Load += gcnew System::EventHandler(this, &Football_board::Football_board_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: Point DownPosition;
	private: Point CurrentPosition;
	private: Point PrevPosition;
	private: DrawingField drawingField;
	private: int maxpictureBox1Height;
	private: int maxpictureBox1Width;
	private: int cursorType;



	private: Fut^ newFut;
	private: Pole^ newPole;
	private: Mach^ newMach;

	private: Form_for_drawing^ movingForm_for_drawing;
	private: bool isDown;
	private: Form_for_drawing^ deletingForm_for_drawing;


	private: System::Void Football_board_Load(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button10_Click(System::Object^ sender, System::EventArgs^ e) {
		cursorType = _Fut;
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		cursorType = _Delete;
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		cursorType = _Cursor;
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		SaveFileDialog^ save = gcnew SaveFileDialog();
		save->Title = "Сохранить";
		save->Filter = "png files (*.png)|*.png|All files (*.*)|*.*";
		if (save->ShowDialog() == Windows::Forms::DialogResult::OK)
		{
			pictureBox1->Image->Save(save->FileName);
		}
	}
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		drawingField.clear();
		draw();
	}
	private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
		cursorType = _Pole;
	}
	private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {
		cursorType = _Ladya;
	}
	private: System::Void button8_Click(System::Object^ sender, System::EventArgs^ e) {
		cursorType = _Mach;
	}



	private: System::Void draw() {
		Graphics^ g = Graphics::FromImage(pictureBox1->Image);
		g->FillRectangle(gcnew SolidBrush(Color::White), 0, 0, pictureBox1->Width, pictureBox1->Height);
		drawingField.drawForm_for_drawing(g);
		pictureBox1->Invalidate();
	}

	private: System::Void pictureBox1_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		isDown = true;
		DownPosition = Point(e->X, e->Y);
		PrevPosition = Point(e->X, e->Y);
		draw();

		switch (cursorType)
		{
		case _Cursor:
			movingForm_for_drawing = drawingField.findForm_for_drawing(e->X, e->Y);
			if (movingForm_for_drawing != nullptr)
			{
				switch (movingForm_for_drawing->type)
				{

				case _Fut:
					movingForm_for_drawing = (Fut^)movingForm_for_drawing;
					break;
				case _Pole:
					movingForm_for_drawing = (Pole^)movingForm_for_drawing;
					break;
				case _Mach:
					movingForm_for_drawing = (Mach^)movingForm_for_drawing;
					break;
				}
			}
			break;

		case _Delete:
			deletingForm_for_drawing = drawingField.findForm_for_drawing(e->X, e->Y);
			if (deletingForm_for_drawing != nullptr)
				drawingField.deleteForm_for_drawing(deletingForm_for_drawing);
			deletingForm_for_drawing = nullptr;
			break;

		case _Fut:
			newFut = gcnew Fut(DownPosition);
			newFut->draw(Graphics::FromImage(pictureBox1->Image));
			break;
		case _Pole:
			newPole = gcnew Pole(DownPosition);
			newPole->draw(Graphics::FromImage(pictureBox1->Image));
			break;
		case _Mach:
			newMach = gcnew Mach(DownPosition);
			newMach->draw(Graphics::FromImage(pictureBox1->Image));
			break;
		}
		pictureBox1->Invalidate();
	}
	private: System::Void pictureBox1_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		if (isDown)
		{
			CurrentPosition = Point(e->X, e->Y);
			if (movingForm_for_drawing == nullptr) {
				draw();
				switch (cursorType)
				{
				case _Cursor:
					break;
				case _Fut:
					newFut = gcnew Fut(DownPosition);
					newFut->draw(Graphics::FromImage(pictureBox1->Image));
					break;
				case _Pole:
					newPole = gcnew Pole(DownPosition);
					newPole->draw(Graphics::FromImage(pictureBox1->Image));
					break;
				case _Mach:
					newMach = gcnew Mach(DownPosition);
					newMach->draw(Graphics::FromImage(pictureBox1->Image));
					break;
				}
			}
			else
			{
				changemovingForm_for_drawingPosition();
				draw();
				movingForm_for_drawing->draw(Graphics::FromImage(pictureBox1->Image));
				PrevPosition = CurrentPosition;
			}
			pictureBox1->Invalidate();
		}
	}

	private: System::Void pictureBox1_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		isDown = false;
		switch (cursorType)
		{
		case _Cursor:
			if (movingForm_for_drawing != nullptr) {
				drawingField.addForm_for_drawing(movingForm_for_drawing);
				movingForm_for_drawing = nullptr;
			}
			break;

		case _Fut:
			drawingField.addForm_for_drawing(newFut);
			break;
		case _Pole:
			drawingField.addForm_for_drawing(newPole);
			break;
		case _Mach:
			drawingField.addForm_for_drawing(newMach);
			break;
		}
		draw();
	}
	private: System::Void changemovingForm_for_drawingPosition()
	{
		Point p1;
		Point p2;
		int dX = CurrentPosition.X - PrevPosition.X;
		int dY = CurrentPosition.Y - PrevPosition.Y;
		switch (movingForm_for_drawing->type)
		{


		case _Fut:
			p1 = ((Fut^)movingForm_for_drawing)->getFut();
			if (p1.X + dX < 0 || p1.X + dX > pictureBox1->Width || p1.Y + dY < 0 || p1.Y + dY > pictureBox1->Height)
				return;
			p1.X = p1.X + dX;
			p1.Y = p1.Y + dY;
			((Fut^)movingForm_for_drawing)->setFut(p1);
			break;
		case _Pole:
			p1 = ((Pole^)movingForm_for_drawing)->getPole();
			if (p1.X + dX < 0 || p1.X + dX > pictureBox1->Width || p1.Y + dY < 0 || p1.Y + dY > pictureBox1->Height)
				return;
			p1.X = p1.X + dX;
			p1.Y = p1.Y + dY;
			((Pole^)movingForm_for_drawing)->setPole(p1);
			break;
		case _Mach:
			p1 = ((Mach^)movingForm_for_drawing)->getMach();
			if (p1.X + dX < 0 || p1.X + dX > pictureBox1->Width || p1.Y + dY < 0 || p1.Y + dY > pictureBox1->Height)
				return;
			p1.X = p1.X + dX;
			p1.Y = p1.Y + dY;
			((Mach^)movingForm_for_drawing)->setMach(p1);
			break;
			break;
		}
	}
	private: System::Void pictureBox1_Click_1(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}

