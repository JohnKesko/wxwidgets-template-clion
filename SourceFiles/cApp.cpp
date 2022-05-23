/*cApp.cpp - This is where the implementation overall of our application holding it all together. */

#include "../HeaderFiles/cApp.h"

// The default entry point for wxWidgets "main" function. It's a macro that masks the default main cpp entry point.
wxIMPLEMENT_APP(cApp);

cApp::cApp()
{

}

cApp::~cApp()
{

}

// Main function to show the window.
bool cApp::OnInit()
{
    m_frame1 = new cMain();
    m_frame1->Show();

    return true;
}