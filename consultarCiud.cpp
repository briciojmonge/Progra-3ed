#include "consultarCiud.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void Mainconsultaciud(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	progra3ED::consultarCiud form;
	Application::Run(% form);
}