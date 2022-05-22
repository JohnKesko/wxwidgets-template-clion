#include "cApp.h"

// Entry point for wxWidgets "main" function
wxIMPLEMENT_APP(cApp);

cApp::cApp()
{

}


cApp::~cApp()
{

}

// Main function to show the window
bool cApp::OnInit()
{
    m_frame1 = new cMain();
    m_frame1->Show();

    return true;
}