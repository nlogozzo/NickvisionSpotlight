#pragma once

#include <wx/wx.h>
#include <wx/infobar.h>

namespace NickvisionSpotlight::Controls
{
	class InfoBar : public wxInfoBar
	{
	public:
		InfoBar(wxWindow* parent, long id);
		void SetIsLightTheme(bool isLightTheme);
		void ShowMessage(const wxString& message, int icon = wxICON_INFORMATION);

	private:
		bool m_isLightTheme;
	};
}

