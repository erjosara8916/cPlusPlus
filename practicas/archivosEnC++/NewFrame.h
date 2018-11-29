#ifndef NEWFRAME_H
#define NEWFRAME_H

//(*Headers(NewFrame)
#include <wx/calctrl.h>
#include <wx/frame.h>
//*)

class NewFrame: public wxFrame
{
	public:

		NewFrame(wxWindow* parent,wxWindowID id=wxID_ANY);
		virtual ~NewFrame();

		//(*Declarations(NewFrame)
		wxCalendarCtrl* CalendarCtrl1;
		//*)

	protected:

		//(*Identifiers(NewFrame)
		static const long ID_CALENDARCTRL1;
		//*)

	private:

		//(*Handlers(NewFrame)
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
