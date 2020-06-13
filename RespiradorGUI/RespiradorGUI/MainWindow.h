#pragma once
#include "wx/wxprec.h"
#include <wx/activityindicator.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
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
	wxBitmapButton*start = nullptr;
	wxBitmapButton* stop = nullptr;
	wxActivityIndicator* activity = nullptr;

	void OnQuit(wxCommandEvent& event);
	void OnAbout(wxCommandEvent& event);
	void OnStartClicked(wxCommandEvent& event);
	void OnStopClicked(wxCommandEvent& event);

	wxDECLARE_EVENT_TABLE();
};

