#include "consultaMen.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void Mainconsultamen(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	progra3ED::consultaMen form;
	Application::Run(% form);
}