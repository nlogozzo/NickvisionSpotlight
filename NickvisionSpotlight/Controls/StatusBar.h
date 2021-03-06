#pragma once

#include <wx/wx.h>

namespace NickvisionSpotlight::Controls
{
	class StatusBar : public wxStatusBar
	{
	public:
		StatusBar(wxWindow* parent, long id);
		void SetIsLightTheme(bool isLightTheme);
		wxString GetMessage() const;
		void SetMessage(const wxString& message);

	private:
		wxStaticText* m_lblMessage;
	};
}

