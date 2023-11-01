#include "VentanaPrincipal.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int Main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	progra3ED::VentanaPrincipal mainForm;
	Application::Run(% mainForm);
	return 0;

}
