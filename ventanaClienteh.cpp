#include "ventanaClienteh.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void Mainvc(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	progra3ED::ventanaClienteh form;
	Application::Run(% form);
}
