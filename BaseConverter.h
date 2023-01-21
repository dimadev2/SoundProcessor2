#pragma once
#include <list>
#include <string>
#include "FileThreadInclude.h"

using std::list;
using std::string;

class BaseConverter {
public:
	virtual void process(list<string> argv) = 0;
};
