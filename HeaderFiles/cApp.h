/*cApp.h - This is the container if you will for holding the application together all together.*/

#pragma once
#include "wx/wx.h"
#include "cMain.h"


class cApp : public wxApp
{
public:
    //Default constructor
    cApp();

    //Destructor
    ~cApp() override;


// Function declaration
public:
    bool OnInit() override;

private:
    cMain* m_frame1 = nullptr;

};