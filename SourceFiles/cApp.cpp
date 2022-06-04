/*cApp.cpp - This is where the implementation overall of our application is -> holding it all together. */

#include "../HeaderFiles/cApp.h"


cApp::cApp() = default;

cApp::~cApp() = default;


// The default entry point for wxWidgets "main" function. It's a macro that masks the default main cpp entry point.
wxIMPLEMENT_APP(cApp);

// Main function to show the window.
bool cApp::OnInit()
{
    m_frame1 = new cMain();
    m_frame1->Show(true);


    return true;
}