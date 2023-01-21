#pragma once
#include "BaseConverter.h"

class Mix : public BaseConverter {
public:
	virtual void process(list<string> argv);
};
