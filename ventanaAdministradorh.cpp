#include "ventanaAdministradorh.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void Mainva(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	progra3ED::ventanaAdministradorh form;
	Application::Run(% form);
}