#pragma once

namespace progra3ED {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for consultaMen
	/// </summary>
	public ref class consultaMen : public System::Windows::Forms::Form
	{
	public:
		consultaMen(void)
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
		~consultaMen()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textBox3;
	protected:
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Label^ label5;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(19, 253);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(403, 20);
			this->textBox3->TabIndex = 21;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Consolas", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(15, 217);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(350, 22);
			this->label4->TabIndex = 20;
			this->label4->Text = L"Ingrese el c�digo del Restaurante:";
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::MediumSpringGreen;
			this->button1->Font = (gcnew System::Drawing::Font(L"Consolas", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(526, 307);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(130, 59);
			this->button1->TabIndex = 19;
			this->button1->Text = L"Buscar";
			this->button1->UseVisualStyleBackColor = false;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(16, 172);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(403, 20);
			this->textBox2->TabIndex = 18;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(16, 97);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(403, 20);
			this->textBox1->TabIndex = 17;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Consolas", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(12, 136);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(320, 22);
			this->label3->TabIndex = 16;
			this->label3->Text = L"Ingrese el c�digo de la ciudad:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Consolas", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(15, 52);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(280, 22);
			this->label2->TabIndex = 15;
			this->label2->Text = L"Ingrese el c�digo del pa�s:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Consolas", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(242, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(180, 22);
			this->label1->TabIndex = 14;
			this->label1->Text = L"Consulta de Men�s";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(19, 330);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(403, 20);
			this->textBox4->TabIndex = 23;
			this->textBox4->TextChanged += gcnew System::EventHandler(this, &consultaMen::textBox4_TextChanged);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Consolas", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(15, 294);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(280, 22);
			this->label5->TabIndex = 22;
			this->label5->Text = L"Ingrese el c�digo del Men�:";
			this->label5->Click += gcnew System::EventHandler(this, &consultaMen::label5_Click);
			// 
			// consultaMen
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::DarkGray;
			this->ClientSize = System::Drawing::Size(668, 385);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"consultaMen";
			this->Text = L"consultaMen";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label5_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void textBox4_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
