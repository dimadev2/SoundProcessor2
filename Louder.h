#pragma once
#include "BaseConverter.h"

class Louder : public BaseConverter {
public:
	virtual void process(list<string> argv);
};
