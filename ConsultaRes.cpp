#include "ConsultaRes.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void MainconsultaRes(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	progra3ED::ConsultaRes form;
	Application::Run(% form);