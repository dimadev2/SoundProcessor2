#include "ConverterManager.h"

ConverterManager::ConverterManager() {
	converters["mute"] = new Mute();
	converters["mix"] = new Mix();
	converters["loud"] = new Louder();
}

ConverterManager::~ConverterManager() {
	delete converters["mute"];
	delete converters["mix"];
	delete converters["louder"];
}

void ConverterManager::execute(const char* command) {
	istringstream istream(command);

	string converterType;
	istream >> converterType;

	string tmp;
	list<string> argv;
	while (istream >> tmp) {
		argv.push_back(tmp);
	}

	try {
		converters.at(converterType)->process(argv);
	}
	catch (std::exception) {
		return;
	}
}
