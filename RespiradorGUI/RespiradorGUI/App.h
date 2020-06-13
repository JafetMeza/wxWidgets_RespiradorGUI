#pragma once
#include "wx/wxprec.h"
#include <wx/activityindicator.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif // !WX_PRECOMP

class App : public wxApp
{
public: 
	App();
	bool OnInit();
	~App();
};

DECLARE_APP(App);

