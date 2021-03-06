#include "Configuration.h"
#include <filesystem>
#include <fstream>
#include <json/json.h>

namespace NickvisionSpotlight::Models
{
	Configuration::Configuration() : m_configDir(std::string(getenv("appdata")) + "\\Nickvision\\NickvisionSpotlight\\"), m_preferLightTheme(false)
	{
		if (!std::filesystem::exists(m_configDir))
		{
			std::filesystem::create_directories(m_configDir);
		}
		std::ifstream configFile(m_configDir + "config.json");
		if (configFile.is_open())
		{
			Json::Value json;
			try
			{
				configFile >> json;
				SetPreferLightTheme(json.get("PreferLightTheme", false).asBool());
			}
			catch (...) {}
		}
	}

	bool Configuration::PreferLightTheme() const
	{
		return m_preferLightTheme;
	}

	void Configuration::SetPreferLightTheme(bool preferLightTheme)
	{
		m_preferLightTheme = preferLightTheme;
	}

	void Configuration::Save() const
	{
		if (!std::filesystem::exists(m_configDir))
		{
			std::filesystem::create_directories(m_configDir);
		}
		std::ofstream configFile(m_configDir + "config.json");
		if (configFile.is_open())
		{
			Json::Value json;
			json["PreferLightTheme"] = PreferLightTheme();
			configFile << json;
		}
	}
}