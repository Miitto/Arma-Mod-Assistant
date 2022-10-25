#include "cSettings.h"

wxString cSettings::currentConfigFile = "";
cSettings* cSettings::mainSettings = nullptr;
BaseOptions* cSettings::settings = nullptr;

cSettings::cSettings(std::string path, std::string prefix, std::string name, std::string author, std::string addons, std::string modPath, std::string type)
{
	mainSettings = this;
	if (settings) delete settings;
	settings = new BaseOptions();
	settings->prefix = prefix;
	settings->name = name;
	settings->author = author;
	settings->addons = addons;
	settings->path = modPath;
	settings->type = type;
	cSettings::setConfigFile(path);
	cGuiControl::setUpGui();
	cGuiControl::fillFolderTree();
}

cSettings::cSettings(std::wstring path, std::wstring prefix, std::wstring name, std::wstring author, std::wstring addons, std::wstring modPath, std::wstring type)
{
	mainSettings = this;
	if (settings) delete settings;
	settings = new BaseOptions();
	settings->prefix = prefix;
	settings->name = name;
	settings->author = author;
	settings->addons = addons;
	settings->path = modPath;
	settings->type = type;
	cSettings::setConfigFile(path);
	cGuiControl::setUpGui();
	cGuiControl::fillFolderTree();
}

cSettings::~cSettings()
{
	if (settings) delete settings;
}

cSettings* cSettings::getSettings() {
	return mainSettings;
}

bool cSettings::setConfigFile(wxString path) 
{
	if (!path) {
		return false;
	}
	currentConfigFile = path;
	return true;
}
bool cSettings::setConfigFile(std::string path) 
{
	if (path.empty()) {
		return false;
	}
	currentConfigFile = path;
	return true;
}
bool cSettings::setConfigFile(const char* path) 
{
	if (!path) {
		return false;
	}
	currentConfigFile = path;
	return true;
}

wxString cSettings::getConfigFile()
{
	return currentConfigFile;
}
