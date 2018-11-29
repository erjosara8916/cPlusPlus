#include "NewFrame.h"

//(*InternalHeaders(NewFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(NewFrame)
const long NewFrame::ID_CALENDARCTRL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(NewFrame,wxFrame)
	//(*EventTable(NewFrame)
	//*)
END_EVENT_TABLE()

NewFrame::NewFrame(wxWindow* parent,wxWindowID id)
{
	//(*Initialize(NewFrame)
	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
	CalendarCtrl1 = new wxCalendarCtrl(this, ID_CALENDARCTRL1, wxDefaultDateTime, wxPoint(120,120), wxDefaultSize, 0, _T("ID_CALENDARCTRL1"));
	//*)
}

NewFrame::~NewFrame()
{
	//(*Destroy(NewFrame)
	//*)
}

