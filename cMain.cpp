#include "cMain.h"

/*This macro will take the class that produces the events and the base class.
In this case, in cMain class, there is a function OnButtonClicked that takes an event argument.*/
wxBEGIN_EVENT_TABLE(cMain, wxFrame)
                EVT_BUTTON(10001, cMain::OnButtonClicked)
wxEND_EVENT_TABLE()

cMain::cMain() : wxFrame(nullptr, wxID_ANY, "My First App!", wxPoint(30,30), wxSize(800, 600))
{
    pButton = new wxButton*[nFieldWidth * nFieldHeight];
    wxGridSizer *grid = new wxGridSizer(nFieldWidth, nFieldHeight, 0, 0);

    nField = new int[nFieldWidth * nFieldHeight];

    wxFont font(24, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false);

    for (int x = 0; x < nFieldWidth; x++)
    {
        for (int y = 0; y < nFieldHeight; y++)
        {
            pButton[y * nFieldWidth + x] = new wxButton(this, 10000 + (y * nFieldWidth + x));
            grid->Add(pButton[y * nFieldWidth + x], 1, wxEXPAND | wxALL);

            pButton[y * nFieldWidth + x]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &cMain::OnButtonClicked, this);
            nField[y * nFieldWidth + x] = 0;

        }
    }

    this->SetSizer(grid);
    grid->Layout();
}

cMain::~cMain()
{
    delete[]pButton;
}

void cMain::OnButtonClicked(wxCommandEvent &event)
{
    // Get coordinate of button in field array
    int x = (event.GetId() - 10000) % nFieldWidth;
    int y = (event.GetId() - 10000) / nFieldWidth;

    if (bFirstClick)
    {
        int mines = 30;

        while (mines)
        {
            int rx = rand() % nFieldWidth;
            int ry = rand() % nFieldHeight;

            if (nField[ry * nFieldWidth + rx] == 0 && rx != x && ry != y)
            {
                nField[ry * nFieldWidth + rx] = -1;
                mines--;
            }
        }

        bFirstClick = false;
    }

    // Disable button, preventing it being pressed again
    pButton[y * nFieldWidth + x]->Enable(false);

    // Check if player hit a mine
    if (nField[y * nFieldWidth + x] == -1)
    {
        wxMessageBox("BOO00M! GAME OVER!");

        // Reset the game
        bFirstClick = true;
        for (int x = 0; x < nFieldWidth; x++)
        {
            for (int y = 0; y < nFieldHeight; y++)
            {
                nField[y * nFieldWidth + x] = 0;
                pButton[y * nFieldWidth + x]->SetLabel("");
                pButton[y * nFieldWidth + x]->Enable(true);
            }
        }
    }
    else
    {
        // Count neighbouring mines
        int mine_count = 0;
        for (int i = -1; i < 2; i++)
        {
            for (int j = -1; j < 2; j++)
            {
                if (x + i >= 0 && x + i < nFieldWidth && y + j >= 0 && y + j < nFieldHeight)
                {
                    if (nField[(y + j) * nFieldWidth + (x + i)] == -1)
                        mine_count++;
                }
            }

            // Update buttons label to show min count if > 0
            if (mine_count > 0)
            {
                pButton[y * nFieldWidth + x]->SetLabel(std::to_string(mine_count));
            }
        }

    }

    event.Skip();
}