#pragma once

namespace progra3ED {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for ventanaClienteh
	/// </summary>
	public ref class ventanaClienteh : public System::Windows::Forms::Form
	{
	public:
		ventanaClienteh(void)
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
		~ventanaClienteh()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TabPage^ Consulta;
	protected:
	private: System::Windows::Forms::Button^ ConProductoBTN;
	private: System::Windows::Forms::Button^ ConMenuBTN;
	private: System::Windows::Forms::Button^ ConRestBTN;
	private: System::Windows::Forms::Button^ ConCiudadBTN;
	private: System::Windows::Forms::Button^ ConPaisBTN;
	private: System::Windows::Forms::TabControl^ tabs;

	protected:









	protected:
















	protected:












































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
			this->Consulta = (gcnew System::Windows::Forms::TabPage());
			this->ConProductoBTN = (gcnew System::Windows::Forms::Button());
			this->ConMenuBTN = (gcnew System::Windows::Forms::Button());
			this->ConRestBTN = (gcnew System::Windows::Forms::Button());
			this->ConCiudadBTN = (gcnew System::Windows::Forms::Button());
			this->ConPaisBTN = (gcnew System::Windows::Forms::Button());
			this->tabs = (gcnew System::Windows::Forms::TabControl());
			this->Consulta->SuspendLayout();
			this->tabs->SuspendLayout();
			this->SuspendLayout();
			// 
			// Consulta
			// 
			this->Consulta->BackColor = System::Drawing::Color::Silver;
			this->Consulta->Controls->Add(this->ConProductoBTN);
			this->Consulta->Controls->Add(this->ConMenuBTN);
			this->Consulta->Controls->Add(this->ConRestBTN);
			this->Consulta->Controls->Add(this->ConCiudadBTN);
			this->Consulta->Controls->Add(this->ConPaisBTN);
			this->Consulta->Location = System::Drawing::Point(4, 22);
			this->Consulta->Name = L"Consulta";
			this->Consulta->Padding = System::Windows::Forms::Padding(3);
			this->Consulta->Size = System::Drawing::Size(784, 409);
			this->Consulta->TabIndex = 1;
			this->Consulta->Text = L"Consulta";
			// 
			// ConProductoBTN
			// 
			this->ConProductoBTN->Font = (gcnew System::Drawing::Font(L"Consolas", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ConProductoBTN->Location = System::Drawing::Point(200, 265);
			this->ConProductoBTN->Name = L"ConProductoBTN";
			this->ConProductoBTN->Size = System::Drawing::Size(365, 43);
			this->ConProductoBTN->TabIndex = 5;
			this->ConProductoBTN->Text = L"Consultar Producto";
			this->ConProductoBTN->UseVisualStyleBackColor = true;
			this->ConProductoBTN->Click += gcnew System::EventHandler(this, &ventanaClienteh::ConProductoBTN_Click);
			// 
			// ConMenuBTN
			// 
			this->ConMenuBTN->Font = (gcnew System::Drawing::Font(L"Consolas", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ConMenuBTN->Location = System::Drawing::Point(200, 216);
			this->ConMenuBTN->Name = L"ConMenuBTN";
			this->ConMenuBTN->Size = System::Drawing::Size(365, 43);
			this->ConMenuBTN->TabIndex = 4;
			this->ConMenuBTN->Text = L"Consultar Menu";
			this->ConMenuBTN->UseVisualStyleBackColor = true;
			this->ConMenuBTN->Click += gcnew System::EventHandler(this, &ventanaClienteh::ConMenuBTN_Click);
			// 
			// ConRestBTN
			// 
			this->ConRestBTN->Font = (gcnew System::Drawing::Font(L"Consolas", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ConRestBTN->Location = System::Drawing::Point(200, 167);
			this->ConRestBTN->Name = L"ConRestBTN";
			this->ConRestBTN->Size = System::Drawing::Size(365, 43);
			this->ConRestBTN->TabIndex = 3;
			this->ConRestBTN->Text = L"Consultar Restaurante";
			this->ConRestBTN->UseVisualStyleBackColor = true;
			this->ConRestBTN->Click += gcnew System::EventHandler(this, &ventanaClienteh::ConRestBTN_Click);
			// 
			// ConCiudadBTN
			// 
			this->ConCiudadBTN->Font = (gcnew System::Drawing::Font(L"Consolas", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ConCiudadBTN->Location = System::Drawing::Point(200, 118);
			this->ConCiudadBTN->Name = L"ConCiudadBTN";
			this->ConCiudadBTN->Size = System::Drawing::Size(365, 43);
			this->ConCiudadBTN->TabIndex = 2;
			this->ConCiudadBTN->Text = L"Consultar Ciudad";
			this->ConCiudadBTN->UseVisualStyleBackColor = true;
			this->ConCiudadBTN->Click += gcnew System::EventHandler(this, &ventanaClienteh::ConCiudadBTN_Click);
			// 
			// ConPaisBTN
			// 
			this->ConPaisBTN->Font = (gcnew System::Drawing::Font(L"Consolas", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ConPaisBTN->Location = System::Drawing::Point(200, 69);
			this->ConPaisBTN->Name = L"ConPaisBTN";
			this->ConPaisBTN->Size = System::Drawing::Size(365, 43);
			this->ConPaisBTN->TabIndex = 1;
			this->ConPaisBTN->Text = L"Consultar País";
			this->ConPaisBTN->UseVisualStyleBackColor = true;
			this->ConPaisBTN->Click += gcnew System::EventHandler(this, &ventanaClienteh::ConPaisBTN_Click);
			// 
			// tabs
			// 
			this->tabs->Controls->Add(this->Consulta);
			this->tabs->Location = System::Drawing::Point(-2, -2);
			this->tabs->Name = L"tabs";
			this->tabs->SelectedIndex = 0;
			this->tabs->Size = System::Drawing::Size(792, 435);
			this->tabs->TabIndex = 1;
			// 
			// ventanaClienteh
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(802, 445);
			this->Controls->Add(this->tabs);
			this->Name = L"ventanaClienteh";
			this->Text = L"ventanaClienteh";
			this->Consulta->ResumeLayout(false);
			this->tabs->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Incersión_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void Consulta_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void ConPaisBTN_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void ConCiudadBTN_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void ConRestBTN_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void ConMenuBTN_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void ConProductoBTN_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
