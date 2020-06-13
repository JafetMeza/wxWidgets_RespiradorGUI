#include "App.h"
#include "id.h"
#include "MainWindow.h"
IMPLEMENT_APP(App);

App::App()
{

}

bool App::OnInit()
{
	if (!wxApp::OnInit())
		return false;

	MainWindow* main = new MainWindow(nullptr, window::id::MAINWINDOW, _("Sciodesk"), wxPoint(-1, -1), wxSize(1100, 500));

	main->Show();
	return true;
}

App::~App()
{}