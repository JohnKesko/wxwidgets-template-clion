#pragma once
#include "wx/wx.h"

class cMain : public wxFrame
{
public:
    cMain();
    ~cMain();

public:
    int nFieldWidth = 10;
    int nFieldHeight = 10;

    wxButton **pButton;

    int *nField = nullptr;
    bool bFirstClick = true;

    void OnButtonClicked(wxCommandEvent &event);

    wxDECLARE_EVENT_TABLE();
};