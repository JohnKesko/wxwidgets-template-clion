
#include <wx/wxprec.h>

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif


class MyApplication : public wxApp
{
public:
    virtual bool OnInit();
};

class MyApplicationFrame : public wxFrame
{
public:
    MyApplicationFrame(const wxString &title, const wxPoint &position, const wxSize &size);

private:
    void OnHello(wxCommandEvent &event);
    void OnExit(wxCommandEvent &event);
    void OnAbout(wxCommandEvent &event);

wxDECLARE_EVENT_TABLE();
};

enum
{
    ID_Hello = 1,
    ID_Hello2 = 2
};

wxBEGIN_EVENT_TABLE(MyApplicationFrame, wxFrame)
                EVT_MENU(ID_Hello,   MyApplicationFrame::OnHello)
                EVT_MENU(wxID_EXIT,  MyApplicationFrame::OnExit)
                EVT_MENU(wxID_ABOUT, MyApplicationFrame::OnAbout)
wxEND_EVENT_TABLE()

// The main function that starts an instance of MyApplication class
wxIMPLEMENT_APP(MyApplication);

bool MyApplication::OnInit()
{
    MyApplicationFrame *theNewFrame = new MyApplicationFrame( "The Title Of My App", wxPoint(50, 50), wxSize(640, 480) );
    theNewFrame->Show(true);
    return true;
}

// The default constructor
MyApplicationFrame::MyApplicationFrame(const wxString &title, const wxPoint &position, const wxSize &size) : wxFrame(NULL, wxID_ANY, title, position, size)
{
    wxMenu *menuFile = new wxMenu;
    menuFile->Append(ID_Hello, "&Hello...\tCtrl-H", "..string shown in the status bar in bottom left corner");
    menuFile->Append(ID_Hello2, "&Hello2...\tCtrl-H", "..second string shown in the status bar in bottom left corner");

    menuFile->AppendSeparator();

    menuFile->Append(wxID_EXIT);

    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);

    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append( menuFile, "&File" );
    menuBar->Append( menuHelp, "&Help" );

    SetMenuBar( menuBar );

    CreateStatusBar();
    SetStatusText( "StatusBarText" );
}

// Menu Functions
void MyApplicationFrame::OnExit(wxCommandEvent &event)
{
    Close( true );
}

void MyApplicationFrame::OnAbout(wxCommandEvent &event)
{
    wxMessageBox("The OnAbout function!", ".. with second string parameter", wxOK | wxICON_INFORMATION );
}

void MyApplicationFrame::OnHello(wxCommandEvent &event)
{
    wxLogMessage("The OnHello function!");
}