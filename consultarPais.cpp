#include "consultarPais.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void Mainconsultapais(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	progra3ED::consultarPais form;
	Application::Run(% form);
}
