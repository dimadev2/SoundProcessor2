#pragma once
#include <map>
#include <sstream>
#include "ConverterInclude.h"

using std::string;
using std::map;
using std::istringstream;

class ConverterManager {
public:
	ConverterManager();
	~ConverterManager();

	void execute(const char* command);
private:
	map<string, BaseConverter*> converters;
};

