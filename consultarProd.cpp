#include "consultarProd.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void Mainconsultaprod(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	progra3ED::consultarProd form;
	Application::Run(% form);
}