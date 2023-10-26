#pragma once

namespace progra3ED {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for ventanaAdministradorh
	/// </summary>
	public ref class ventanaAdministradorh : public System::Windows::Forms::Form
	{
	public:
		ventanaAdministradorh(void)
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
		~ventanaAdministradorh()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TabControl^ tabs;
	private: System::Windows::Forms::TabPage^ Incersión;
	private: System::Windows::Forms::TabPage^ Consulta;
	private: System::Windows::Forms::TabPage^ Modificación;
	private: System::Windows::Forms::Button^ InPaisbtn;

	private: System::Windows::Forms::Button^ InMenbtn;

	private: System::Windows::Forms::Button^ InResbtn;

	private: System::Windows::Forms::Button^ InCiudbtn;
	private: System::Windows::Forms::Button^ InProdbtn;
	private: System::Windows::Forms::Button^ InClienbtn;



	protected:

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
			this->tabs = (gcnew System::Windows::Forms::TabControl());
			this->Incersión = (gcnew System::Windows::Forms::TabPage());
			this->InClienbtn = (gcnew System::Windows::Forms::Button());
			this->InProdbtn = (gcnew System::Windows::Forms::Button());
			this->InMenbtn = (gcnew System::Windows::Forms::Button());
			this->InResbtn = (gcnew System::Windows::Forms::Button());
			this->InCiudbtn = (gcnew System::Windows::Forms::Button());
			this->InPaisbtn = (gcnew System::Windows::Forms::Button());
			this->Consulta = (gcnew System::Windows::Forms::TabPage());
			this->Modificación = (gcnew System::Windows::Forms::TabPage());
			this->tabs->SuspendLayout();
			this->Incersión->SuspendLayout();
			this->SuspendLayout();
			// 
			// tabs
			// 
			this->tabs->Controls->Add(this->Incersión);
			this->tabs->Controls->Add(this->Consulta);
			this->tabs->Controls->Add(this->Modificación);
			this->tabs->Location = System::Drawing::Point(3, 0);
			this->tabs->Name = L"tabs";
			this->tabs->SelectedIndex = 0;
			this->tabs->Size = System::Drawing::Size(792, 435);
			this->tabs->TabIndex = 0;
			// 
			// Incersión
			// 
			this->Incersión->BackColor = System::Drawing::Color::Silver;
			this->Incersión->Controls->Add(this->InClienbtn);
			this->Incersión->Controls->Add(this->InProdbtn);
			this->Incersión->Controls->Add(this->InMenbtn);
			this->Incersión->Controls->Add(this->InResbtn);
			this->Incersión->Controls->Add(this->InCiudbtn);
			this->Incersión->Controls->Add(this->InPaisbtn);
			this->Incersión->Location = System::Drawing::Point(4, 22);
			this->Incersión->Name = L"Incersión";
			this->Incersión->Padding = System::Windows::Forms::Padding(3);
			this->Incersión->Size = System::Drawing::Size(784, 409);
			this->Incersión->TabIndex = 0;
			this->Incersión->Text = L"Incersión";
			this->Incersión->Click += gcnew System::EventHandler(this, &ventanaAdministradorh::tabPage1_Click);
			// 
			// InClienbtn
			// 
			this->InClienbtn->Font = (gcnew System::Drawing::Font(L"Consolas", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->InClienbtn->Location = System::Drawing::Point(198, 309);
			this->InClienbtn->Name = L"InClienbtn";
			this->InClienbtn->Size = System::Drawing::Size(365, 40);
			this->InClienbtn->TabIndex = 5;
			this->InClienbtn->Text = L"Insertar Cliente";
			this->InClienbtn->UseVisualStyleBackColor = true;
			this->InClienbtn->Click += gcnew System::EventHandler(this, &ventanaAdministradorh::InClienbtn_Click);
			// 
			// InProdbtn
			// 
			this->InProdbtn->Font = (gcnew System::Drawing::Font(L"Consolas", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->InProdbtn->Location = System::Drawing::Point(198, 252);
			this->InProdbtn->Name = L"InProdbtn";
			this->InProdbtn->Size = System::Drawing::Size(365, 40);
			this->InProdbtn->TabIndex = 4;
			this->InProdbtn->Text = L"Insertar Prod";
			this->InProdbtn->UseVisualStyleBackColor = true;
			this->InProdbtn->Click += gcnew System::EventHandler(this, &ventanaAdministradorh::InProdbtn_Click);
			// 
			// InMenbtn
			// 
			this->InMenbtn->Font = (gcnew System::Drawing::Font(L"Consolas", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->InMenbtn->Location = System::Drawing::Point(198, 196);
			this->InMenbtn->Name = L"InMenbtn";
			this->InMenbtn->Size = System::Drawing::Size(365, 40);
			this->InMenbtn->TabIndex = 3;
			this->InMenbtn->Text = L"Insertar Menu";
			this->InMenbtn->UseVisualStyleBackColor = true;
			this->InMenbtn->Click += gcnew System::EventHandler(this, &ventanaAdministradorh::InMebtn_Click);
			// 
			// InResbtn
			// 
			this->InResbtn->Font = (gcnew System::Drawing::Font(L"Consolas", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->InResbtn->Location = System::Drawing::Point(198, 139);
			this->InResbtn->Name = L"InResbtn";
			this->InResbtn->Size = System::Drawing::Size(365, 40);
			this->InResbtn->TabIndex = 2;
			this->InResbtn->Text = L"Insertar Restaurante";
			this->InResbtn->UseVisualStyleBackColor = true;
			this->InResbtn->Click += gcnew System::EventHandler(this, &ventanaAdministradorh::InResbtn_Click);
			// 
			// InCiudbtn
			// 
			this->InCiudbtn->Font = (gcnew System::Drawing::Font(L"Consolas", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->InCiudbtn->Location = System::Drawing::Point(198, 82);
			this->InCiudbtn->Name = L"InCiudbtn";
			this->InCiudbtn->Size = System::Drawing::Size(365, 42);
			this->InCiudbtn->TabIndex = 1;
			this->InCiudbtn->Text = L"Insertar Ciudad";
			this->InCiudbtn->UseVisualStyleBackColor = true;
			this->InCiudbtn->Click += gcnew System::EventHandler(this, &ventanaAdministradorh::InCiudbtn_Click);
			// 
			// InPaisbtn
			// 
			this->InPaisbtn->Font = (gcnew System::Drawing::Font(L"Consolas", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->InPaisbtn->Location = System::Drawing::Point(198, 24);
			this->InPaisbtn->Name = L"InPaisbtn";
			this->InPaisbtn->Size = System::Drawing::Size(365, 43);
			this->InPaisbtn->TabIndex = 0;
			this->InPaisbtn->Text = L"Insertar País";
			this->InPaisbtn->UseVisualStyleBackColor = true;
			this->InPaisbtn->Click += gcnew System::EventHandler(this, &ventanaAdministradorh::InPaisbtn_Click);
			// 
			// Consulta
			// 
			this->Consulta->BackColor = System::Drawing::Color::Silver;
			this->Consulta->Location = System::Drawing::Point(4, 22);
			this->Consulta->Name = L"Consulta";
			this->Consulta->Padding = System::Windows::Forms::Padding(3);
			this->Consulta->Size = System::Drawing::Size(784, 409);
			this->Consulta->TabIndex = 1;
			this->Consulta->Text = L"Consulta";
			this->Consulta->Click += gcnew System::EventHandler(this, &ventanaAdministradorh::tabPage2_Click);
			// 
			// Modificación
			// 
			this->Modificación->BackColor = System::Drawing::Color::Silver;
			this->Modificación->Location = System::Drawing::Point(4, 22);
			this->Modificación->Name = L"Modificación";
			this->Modificación->Size = System::Drawing::Size(784, 409);
			this->Modificación->TabIndex = 2;
			this->Modificación->Text = L"Modificación";
			// 
			// ventanaAdministradorh
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::DarkGray;
			this->ClientSize = System::Drawing::Size(796, 435);
			this->Controls->Add(this->tabs);
			this->Name = L"ventanaAdministradorh";
			this->Text = L"ventanaAdministradorh";
			this->Load += gcnew System::EventHandler(this, &ventanaAdministradorh::ventanaAdministradorh_Load);
			this->tabs->ResumeLayout(false);
			this->Incersión->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void ventanaAdministradorh_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void tabPage1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void tabPage2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void InPaisbtn_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void InCiudbtn_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void InResbtn_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void InMebtn_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void InProdbtn_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void InClienbtn_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
