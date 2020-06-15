#include "MainWindow.h"
#include "id.h"

// event tables and other macros for wxWidgets
wxBEGIN_EVENT_TABLE(MainWindow, wxFrame)
EVT_MENU(window::id::MENU_QUIT, MainWindow::OnQuit)
EVT_MENU(window::id::MENU_ABOUT, MainWindow::OnAbout)
EVT_BUTTON(window::id::START_BUTTON, MainWindow::OnStartClicked)
EVT_BUTTON(window::id::STOP_BUTTON, MainWindow::OnStopClicked)
EVT_TEXT(window::id::POSITION1, MainWindow::OnTextEnterPosition1)
EVT_TEXT(window::id::POSITION2, MainWindow::OnTextEnterPosition2)
EVT_TEXT(window::id::VELOCITY1, MainWindow::OnTextEnterVelocity1)
EVT_TEXT(window::id::VELOCITY2, MainWindow::OnTextEnterVelocity2)
EVT_TEXT(window::id::PAUSE1, MainWindow::OnTextEnterPause1)
EVT_TEXT(window::id::PAUSE2, MainWindow::OnTextEnterPause2)
EVT_TEXT(window::id::BREATH, MainWindow::OnTextEnterBreath)
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
	CreateStatusBar(1);
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

	//wxPanel* panel = new wxPanel(this, -1, wxPoint(-1, -1), wxSize(), wxBORDER_RAISED);
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
	wxStaticText* ptxt1 = new wxStaticText(this, -1, "Position 1");
	position1 = new wxTextCtrl(this, window::id::POSITION1, "");
	wxStaticText* ptxt2 = new wxStaticText(this, -1, "Position 2");
	position2 = new wxTextCtrl(this, window::POSITION2, "");
	grid1->Add(ptxt1, szrflags);
	grid1->Add(position1, szrflags);
	grid1->Add(ptxt2, szrflags);
	grid1->Add(position2, szrflags);
	szrPosition->Add(grid1);
	#pragma endregion

	#pragma region C O L U M N A     2
	wxBoxSizer* szrVelocity = new wxBoxSizer(wxVERTICAL);
	wxFlexGridSizer* grid2 = new wxFlexGridSizer(2, 1, 1);
	wxStaticText* vtxt1 = new wxStaticText(this, -1, "Velocidad 1");
	velocity1 = new wxTextCtrl(this, window::id::VELOCITY1, "");
	wxStaticText* vtxt2 = new wxStaticText(this, -1, "Velocidad 2");
	velocity2 = new wxTextCtrl(this, window::id::VELOCITY2, "");
	grid2->Add(vtxt1, szrflags);
	grid2->Add(velocity1, szrflags);
	grid2->Add(vtxt2, szrflags);
	grid2->Add(velocity2, szrflags);
	szrVelocity->Add(grid2);
	#pragma endregion

	#pragma region C O L U M N A     3
	wxBoxSizer* szrpauses = new wxBoxSizer(wxVERTICAL);
	wxFlexGridSizer* grid3 = new wxFlexGridSizer(2, 1, 1);
	wxStaticText* pausetxt1 = new wxStaticText(this, -1, "Pausa Inspiratoria");
	pause1 = new wxTextCtrl(this, window::id::PAUSE1, "");
	wxStaticText* pausetxt2 = new wxStaticText(this, -1, "Pausa Espiratoria");
	pause2 = new wxTextCtrl(this, window::id::PAUSE2, "");
	grid3->Add(pausetxt1, szrflags);
	grid3->Add(pause1, szrflags);
	grid3->Add(pausetxt2, szrflags);
	grid3->Add(pause2, szrflags);
	szrpauses->Add(grid3);
	#pragma endregion

	#pragma region C O L U M N A     4
	wxBoxSizer* szrbreath = new wxBoxSizer(wxVERTICAL);
	wxFlexGridSizer* grid4 = new wxFlexGridSizer(2, 1, 1);
	wxStaticText* btxt1 = new wxStaticText(this, -1, "Respiracion por minuto");
	breath = new wxTextCtrl(this, window::id::BREATH, "");
	grid4->Add(btxt1, szrflags);
	grid4->Add(breath, szrflags);
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
	wxTextCtrl* field1ctrl = new wxTextCtrl(this, -1, "", wxPoint(-1, -1), wxSize(550, -1), wxTE_READONLY);
	field1ctrl->SetFont(fonty);
	wxStaticText* field2text = new wxStaticText(this, -1, "FLUJO");
	field2text->SetFont(fonty);
	field2text->SetForegroundColour("gray");
	wxTextCtrl* field2ctrl = new wxTextCtrl(this, -1, "", wxPoint(-1, -1), wxSize(550, -1), wxTE_READONLY);
	field2ctrl->SetFont(fonty);
	wxStaticText* field3text = new wxStaticText(this, -1, "PRESION");
	field3text->SetFont(fonty);
	field3text->SetForegroundColour("gray");
	wxTextCtrl* field3ctrl = new wxTextCtrl(this, -1, "", wxPoint(-1, -1), wxSize(550, -1), wxTE_READONLY);
	field3ctrl->SetFont(fonty);

	szr->Add(field1text, szrf);
	szr->Add(field1ctrl, szrf);
	szr->Add(field2text, szrf);
	szr->Add(field2ctrl, szrf);
	szr->Add(field3text, szrf);
	szr->Add(field3ctrl, szrf);
	#pragma endregion

	szrMain->Add(szrButtons, 0, wxALIGN_LEFT, 10);
	szrMain->Add(Title, 0, wxALIGN_CENTER, 10);
	szrMain->Add(blank);
	szrMain->Add(szr, 0, wxALIGN_RIGHT, 10);

	SetSizer(szrMain);
#pragma endregion
}

MainWindow::~MainWindow()
{}

#pragma region E V E N T O S
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

void MainWindow::OnStartClicked(wxCommandEvent& event)
{
	if (pos1 && pos2 && vel1 && vel2 && pau1 && pau2 && brth)
	{
		start->Disable();
		position1->Disable();
		position2->Disable();
		velocity1->Disable();
		velocity2->Disable();
		pause1->Disable();
		pause2->Disable();
		breath->Disable();

		SetStatusText("");
		wxStatusBar* sb = GetStatusBar();
		sb->SetBackgroundColour("green");
		sb->SetForegroundColour(wxColour(wxT("BLACK")));
		wxStaticText* txt = new wxStaticText(sb, wxID_ANY, wxT("Respirador Encendido"), wxPoint(10, 5), wxDefaultSize, 0);
		sb->SetStatusWidths(1, NULL);
		SetStatusBar(sb);
	}
	else
	{
		wxMessageBox(wxString::Format
		(
			"Valores Incompletos\n"
			"\n"
			"Llena todos los campos solicitados\n"
		),
			"Error",
			wxOK | wxICON_EXCLAMATION,
			this);
	}
}

void MainWindow::OnStopClicked(wxCommandEvent& event)
{
	start->Enable();
	position1->Enable();
	position2->Enable();
	velocity1->Enable();
	velocity2->Enable();
	pause1->Enable();
	pause2->Enable();
	breath->Enable();

	SetStatusText("");
	wxStatusBar* sb = GetStatusBar();
	sb->SetBackgroundColour("red");
	sb->SetForegroundColour(wxColour(wxT("WHITE")));
	wxStaticText* txt = new wxStaticText(sb, wxID_ANY, wxT("Respirador Apagado    "), wxPoint(10, 5), wxDefaultSize, 0);
	sb->SetStatusWidths(1, NULL);
	SetStatusBar(sb);

}

bool CheckEmptyText(const char* str)
{
	if (str[0] != '\0')
		return true;
	return false;
}

bool convertion(const char* str)
{
	char* p;
	long converted = strtol(str, &p, 10);
	if (*p)
	{
		return false;
	}
	else
	{
		return true;
	}
}

void MainWindow::OnTextEnterPosition1(wxCommandEvent& event)
{
	wxString str = position1->GetValue();
	bool result = convertion(str.mb_str());
	if (!result)
	{
		position1->Remove(position1->GetLastPosition() - 1, position1->GetLastPosition());
	}

	pos1 = CheckEmptyText(str.mb_str());
}

void MainWindow::OnTextEnterPosition2(wxCommandEvent& event)
{
	wxString str = position2->GetValue();
	bool result = convertion(str.mb_str());
	if (!result)
	{
		position2->Remove(position2->GetLastPosition() - 1, position2->GetLastPosition());
	}

	pos2 = CheckEmptyText(str);
}

void MainWindow::OnTextEnterVelocity1(wxCommandEvent& event)
{
	wxString str = velocity1->GetValue();
	bool result = convertion(str.mb_str());
	if (!result)
	{
		velocity1->Remove(velocity1->GetLastPosition() - 1, velocity1->GetLastPosition());
	}

	vel1 = CheckEmptyText(str);
}

void MainWindow::OnTextEnterVelocity2(wxCommandEvent& event)
{
	wxString str = velocity2->GetValue();
	bool result = convertion(str.mb_str());
	if (!result)
	{
		velocity2->Remove(velocity2->GetLastPosition() - 1, velocity2->GetLastPosition());
	}

	vel2 = CheckEmptyText(str);
}

void MainWindow::OnTextEnterPause1(wxCommandEvent& event)
{
	wxString str = pause1->GetValue();
	bool result = convertion(str.mb_str());
	if (!result)
	{
		pause1->Remove(pause1->GetLastPosition() - 1, pause1->GetLastPosition());
	}

	pau1 = CheckEmptyText(str);
}

void MainWindow::OnTextEnterPause2(wxCommandEvent& event)
{
	wxString str = pause2->GetValue();
	bool result = convertion(str.mb_str());
	if (!result)
	{
		pause2->Remove(pause2->GetLastPosition() - 1, pause2->GetLastPosition());
	}

	pau2 = CheckEmptyText(str);
}

void MainWindow::OnTextEnterBreath(wxCommandEvent& event)
{
	wxString str = breath->GetValue();
	bool result = convertion(str.mb_str());
	if (!result)
	{
		breath->Remove(breath->GetLastPosition() - 1, breath->GetLastPosition());
	}

	brth = CheckEmptyText(str);
}
#pragma endregion



