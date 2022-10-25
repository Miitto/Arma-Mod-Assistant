#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <wx/string.h>
#include "cSettings.h"

class cCommon
{
public:
	cCommon();
	~cCommon();

	int dirExists(const char* const path);
};

