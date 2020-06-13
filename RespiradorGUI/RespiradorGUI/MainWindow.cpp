#include "MainWindow.h"
#include "id.h"
#include <wx/artprov.h>

// event tables and other macros for wxWidgets
wxBEGIN_EVENT_TABLE(MainWindow, wxFrame)
EVT_MENU(window::id::MENU_QUIT, MainWindow::OnQuit)
EVT_MENU(window::id::MENU_ABOUT, MainWindow::OnAbout)
EVT_BUTTON(window::id::START_BUTTON, MainWindow::OnStartClicked)
EVT_BUTTON(window::id::STOP_BUTTON, MainWindow::OnStopClicked)
wxEND_EVENT_TABLE()

MainWindow::MainWindow(wxWindow* parent,
	wxWindowID id,
	const wxString& title,
	const wxPoint& pos,
	const wxSize& size,
	long style,
	const wxString& name):wxFrame(parent, id, title, pos, size, style, name)
{
	//set the frame icon
    SetIcon(wxICON(sample));

	// create a menu bar
	#pragma region M E N U
	wxMenu* fileMenu = new wxMenu;

	// the "About" item should be in the help menu
	wxMenu* helpMenu = new wxMenu;
	helpMenu->Append(window::id::MENU_ABOUT, "&About\tF1", "Show about dialog");

	wxMenuItem* quitItem = new wxMenuItem(fileMenu, window::id::MENU_QUIT);
	quitItem->SetBitmap(wxArtProvider::GetBitmap("wxART_QUIT"));
	fileMenu->Append(quitItem);
	//fileMenu->Append(window::id::MENU_QUIT, "E&xit\tAlt-X", "Quit this program");

	// now append the freshly created menu to the menu bar...
	wxMenuBar* menuBar = new wxMenuBar();
	menuBar->Append(fileMenu, "&File");
	menuBar->Append(helpMenu, "&Help");

	// ... and attach this menu bar to the frame
	SetMenuBar(menuBar);
	#pragma endregion

	//Status Bar
	CreateStatusBar(2);
	SetStatusText("Bienvenidos a la App del Respirador!");
	
	//Create main app GUI
	#pragma region B O D Y
	wxFont font(28, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false);
	wxFont fonty(22, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false);
	SetBackgroundColour("white");
	SetMinSize(wxSize(1100, 500));
	SetMaxSize(wxSize(1200, 600));
	CenterOnScreen();

	wxSizerFlags szrflags(0);
	szrflags.Border(wxALL, 5);

	wxSizerFlags szrf(0);
	szrf.Border(wxALL, 15);

	wxBoxSizer* szrMain = new wxBoxSizer(wxVERTICAL);

	#pragma region T O P      P A R T 
	wxBoxSizer* szrButtons = new wxBoxSizer(wxHORIZONTAL);
	wxBitmap bmp1 = wxArtProvider::GetBitmap("wxART_GO_FORWARD");
	wxBitmap bmp2 = wxArtProvider::GetBitmap("wxART_ERROR");
	start = new wxBitmapButton(this, window::id::START_BUTTON, bmp1, wxDefaultPosition, wxSize(60, 40));
	start->SetBackgroundColour(wxColour("black"));
	stop = new wxBitmapButton(this, window::id::STOP_BUTTON, bmp2, wxDefaultPosition, wxSize(40, 40));

	wxFlexGridSizer* grid = new wxFlexGridSizer(4, 1, 1);

	#pragma region C O L U M N A     1
	wxBoxSizer* szrPosition = new wxBoxSizer(wxVERTICAL);
	wxFlexGridSizer* grid1 = new wxFlexGridSizer(2, 1, 1);
	wxStaticText* posicion1 = new wxStaticText(this, -1, "Position 1");
	wxTextCtrl* ptxt1 = new wxTextCtrl(this, -1, "");
	wxStaticText* posicion2 = new wxStaticText(this, -1, "Position 2");
	wxTextCtrl* ptxt2 = new wxTextCtrl(this, -1, "");
	grid1->Add(posicion1, szrflags);
	grid1->Add(ptxt1, szrflags);
	grid1->Add(posicion2, szrflags);
	grid1->Add(ptxt2, szrflags);
	szrPosition->Add(grid1);
	#pragma endregion

	#pragma region C O L U M N A     2
	wxBoxSizer* szrVelocity = new wxBoxSizer(wxVERTICAL);
	wxFlexGridSizer* grid2 = new wxFlexGridSizer(2, 1, 1);
	wxStaticText* velocity1 = new wxStaticText(this, -1, "Velocidad 1");
	wxTextCtrl* vtxt1 = new wxTextCtrl(this, -1, "");
	wxStaticText* velocity2 = new wxStaticText(this, -1, "Velocidad 2");
	wxTextCtrl* vtxt2 = new wxTextCtrl(this, -1, "");
	grid2->Add(velocity1, szrflags);
	grid2->Add(vtxt1, szrflags);
	grid2->Add(velocity2, szrflags);
	grid2->Add(vtxt2, szrflags);
	szrVelocity->Add(grid2);
	#pragma endregion

	#pragma region C O L U M N A     3
	wxBoxSizer* szrpauses = new wxBoxSizer(wxVERTICAL);
	wxFlexGridSizer* grid3 = new wxFlexGridSizer(2, 1, 1);
	wxStaticText* pause1 = new wxStaticText(this, -1, "Pausa Inspiratoria");
	wxTextCtrl* pausetxt1 = new wxTextCtrl(this, -1, "");
	wxStaticText* pause2 = new wxStaticText(this, -1, "Pausa Espiratoria");
	wxTextCtrl* pausetxt2 = new wxTextCtrl(this, -1, "");
	grid3->Add(pause1, szrflags);
	grid3->Add(pausetxt1, szrflags);
	grid3->Add(pause2, szrflags);
	grid3->Add(pausetxt2, szrflags);
	szrpauses->Add(grid3);
	#pragma endregion

	#pragma region C O L U M N A     4
	wxBoxSizer* szrbreath = new wxBoxSizer(wxVERTICAL);
	wxFlexGridSizer* grid4 = new wxFlexGridSizer(2, 1, 1);
	wxStaticText* breath = new wxStaticText(this, -1, "Respiracion por minuto");
	wxTextCtrl* btxt1 = new wxTextCtrl(this, -1, "");
	grid4->Add(breath, szrflags);
	grid4->Add(btxt1, szrflags);
	szrbreath->Add(grid4);
	#pragma endregion

	grid->Add(grid1);
	grid->Add(grid2);
	grid->Add(grid3);
	grid->Add(grid4, 0, wxALIGN_CENTER_VERTICAL, 0);

	szrButtons->Add(start, szrflags);
	szrButtons->Add(stop, szrflags);
	szrButtons->Add(grid);
	#pragma endregion

	#pragma region T I T L E
	wxStaticText* Title = new wxStaticText(this, -1, "RESPIRADOR AUTOMATICO");
	Title->SetFont(font);

	wxStaticText* blank = new wxStaticText(this, -1, "         ");
	blank->SetFont(font);
	#pragma endregion

	#pragma region B O T T O M     P A R T
	wxFlexGridSizer* szr = new wxFlexGridSizer(2, 1, 1);
	wxStaticText* field1text = new wxStaticText(this, -1, "RESPIRACION POR MINUTO");
	field1text->SetFont(fonty);
	field1text->SetForegroundColour("gray");
	wxTextCtrl* field1ctrl = new wxTextCtrl(this, -1, "", wxPoint(-1, -1), wxSize(550, -1));
	field1ctrl->SetFont(fonty);
	wxStaticText* field2text = new wxStaticText(this, -1, "FLUJO");
	field2text->SetFont(fonty);
	field2text->SetForegroundColour("gray");
	wxTextCtrl* field2ctrl = new wxTextCtrl(this, -1, "", wxPoint(-1, -1), wxSize(550, -1));
	field2ctrl->SetFont(fonty);
	wxStaticText* field3text = new wxStaticText(this, -1, "PRESION");
	field3text->SetFont(fonty);
	field3text->SetForegroundColour("gray");
	wxTextCtrl* field3ctrl = new wxTextCtrl(this, -1, "", wxPoint(-1, -1), wxSize(550, -1));
	field3ctrl->SetFont(fonty);

	szr->Add(field1text, szrf);
	szr->Add(field1ctrl, szrf);
	szr->Add(field2text, szrf);
	szr->Add(field2ctrl, szrf);
	szr->Add(field3text, szrf);
	szr->Add(field3ctrl, szrf);
	#pragma endregion

	szrMain->Add(szrButtons, 0, wxALIGN_LEFT, 0);
	szrMain->Add(Title, 0, wxALIGN_CENTER, 0);
	szrMain->Add(blank);
	szrMain->Add(szr, 0, wxALIGN_RIGHT, 0);

	SetSizer(szrMain);
#pragma endregion
}

MainWindow::~MainWindow()
{}

void MainWindow::OnQuit(wxCommandEvent& event)
{
    // true is to force the frame to close
    Close(true);
}

void MainWindow::OnAbout(wxCommandEvent& event)
{
    wxMessageBox(wxString::Format
    (
        "Version 2.0.0!\n"
        "\n"
        "Interfaz realizada por Sciodesk\n"
    ),
        "About Respirador App",
        wxOK | wxICON_INFORMATION,
        this);
}

void MainWindow::OnStartClicked(wxCommandEvent &event)
{
	SetStatusText("Respirador Encendido");
}

void MainWindow::OnStopClicked(wxCommandEvent &event)
{
	SetStatusText("Respirador Apagado");
}


