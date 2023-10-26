#pragma once

namespace progra3ED {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class VentanaPrincipal : public System::Windows::Forms::Form
	{
	public:
		VentanaPrincipal(void)
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
		~VentanaPrincipal()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Panel^ panel1;

	private: System::Windows::Forms::Label^ label3;

	private: System::Windows::Forms::CheckBox^ checkBox2;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::CheckBox^ checkBox1;
	private: System::Windows::Forms::Button^ button1;




	protected:

	protected:


















	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Consolas", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(12, 24);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(161, 37);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Registro";
			this->label1->Click += gcnew System::EventHandler(this, &VentanaPrincipal::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Black;
			this->label2->Location = System::Drawing::Point(6, 106);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(0, 13);
			this->label2->TabIndex = 1;
			this->label2->Click += gcnew System::EventHandler(this, &VentanaPrincipal::label2_Click);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::Silver;
			this->panel1->Controls->Add(this->textBox1);
			this->panel1->Controls->Add(this->label4);
			this->panel1->Controls->Add(this->checkBox2);
			this->panel1->Controls->Add(this->checkBox1);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Location = System::Drawing::Point(19, 92);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(621, 160);
			this->panel1->TabIndex = 2;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &VentanaPrincipal::panel1_Paint);
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::Color::White;
			this->textBox1->Location = System::Drawing::Point(373, 65);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(215, 20);
			this->textBox1->TabIndex = 4;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &VentanaPrincipal::textBox1_TextChanged);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Consolas", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(374, 32);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(214, 24);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Digite su código:";
			this->label4->Click += gcnew System::EventHandler(this, &VentanaPrincipal::label4_Click_1);
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->BackColor = System::Drawing::Color::Transparent;
			this->checkBox2->Font = (gcnew System::Drawing::Font(L"Consolas", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->checkBox2->Location = System::Drawing::Point(18, 107);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(99, 26);
			this->checkBox2->TabIndex = 2;
			this->checkBox2->Text = L"Cliente";
			this->checkBox2->UseVisualStyleBackColor = false;
			this->checkBox2->CheckedChanged += gcnew System::EventHandler(this, &VentanaPrincipal::checkBox2_CheckedChanged);
			// 
			// checkBox1
			// 
			this->checkBox1->Font = (gcnew System::Drawing::Font(L"Consolas", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->checkBox1->Location = System::Drawing::Point(18, 61);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(174, 24);
			this->checkBox1->TabIndex = 5;
			this->checkBox1->Text = L"Administrador";
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &VentanaPrincipal::checkBox1_CheckedChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Consolas", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(14, 11);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(214, 24);
			this->label3->TabIndex = 0;
			this->label3->Text = L"Tipo de Usuario: ";
			this->label3->Click += gcnew System::EventHandler(this, &VentanaPrincipal::label3_Click);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::MediumSpringGreen;
			this->button1->Font = (gcnew System::Drawing::Font(L"Consolas", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(516, 290);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(124, 48);
			this->button1->TabIndex = 3;
			this->button1->Text = L"Siguiente";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &VentanaPrincipal::button1_Click);
			// 
			// VentanaPrincipal
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::DarkGray;
			this->ClientSize = System::Drawing::Size(655, 350);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Name = L"VentanaPrincipal";
			this->Text = L"Progra 3 Estructuras de Datos";
			this->Load += gcnew System::EventHandler(this, &VentanaPrincipal::VentanaPrincipal_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void VentanaPrincipal_Load(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label4_Click_1(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void checkBox1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void checkBox2_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}