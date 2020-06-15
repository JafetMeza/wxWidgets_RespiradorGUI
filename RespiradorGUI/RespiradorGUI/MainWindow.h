#pragma once
#include "wx/wxprec.h"
#include <wx/activityindicator.h>
#include <wx/artprov.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#include <wx/activityindicator.h>
#include <wx/artprov.h>
#endif // !WX_PRECOMP

class MainWindow : public wxFrame
{
public:
	MainWindow(wxWindow *parent, 
		wxWindowID id, 
		const wxString& title, 
		const wxPoint& pos = wxDefaultPosition, 
		const wxSize& size = wxDefaultSize, 
		long style = wxDEFAULT_FRAME_STYLE,
		const wxString& name = wxFrameNameStr);
	~MainWindow();

public:
	bool pos1 = false;
	bool pos2 = false;
	bool vel1 = false;
	bool vel2 = false;
	bool pau1 = false;
	bool pau2 = false;
	bool brth = false;

	wxBitmapButton*start = nullptr;
	wxBitmapButton* stop = nullptr;
	wxTextCtrl* position1 = nullptr;
	wxTextCtrl* position2 = nullptr;
	wxTextCtrl* velocity1 = nullptr;
	wxTextCtrl* velocity2 = nullptr;
	wxTextCtrl* pause1 = nullptr;
	wxTextCtrl* pause2 = nullptr;
	wxTextCtrl* breath = nullptr;
	wxActivityIndicator* activity = nullptr;

	void OnQuit(wxCommandEvent& event);
	void OnAbout(wxCommandEvent& event);
	void OnStartClicked(wxCommandEvent& event);
	void OnStopClicked(wxCommandEvent& event);
	void OnTextEnterPosition1(wxCommandEvent& event);
	void OnTextEnterPosition2(wxCommandEvent& event);
	void OnTextEnterVelocity1(wxCommandEvent& event);
	void OnTextEnterVelocity2(wxCommandEvent& event);
	void OnTextEnterPause1(wxCommandEvent& event);
	void OnTextEnterPause2(wxCommandEvent& event);
	void OnTextEnterBreath(wxCommandEvent& event);
	wxDECLARE_EVENT_TABLE();
};

