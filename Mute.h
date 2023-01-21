#pragma once
#include "BaseConverter.h"

class Mute : public BaseConverter {
public:
	virtual void process(list<string> argv);
};

