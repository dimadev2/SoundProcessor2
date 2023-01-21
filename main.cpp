#include <iostream>
#include <string>
#include "ConverterManager.h"

using std::cin;
using std::cout;

void printHelp();

int main() {
	ConverterManager manager = ConverterManager();
	char command[64];
	while (true) {
		cout << "~#: ";
		cin.getline(command, 64);
		if (strcmp(command, "-h") == 0) {
			printHelp();
		}
		else if (strcmp(command, "-q") == 0) {
			break;
		}
		else {
			manager.execute(command);
		}
	}
}

void printHelp() {
	cout << "WAV converter\n";
	cout << "Commands:\n";
	cout << "\tmute input output start end\n";
	cout << "\tmix input1 input2 output start end\n";
	cout << "\tloud input output additionalLoud start end\n";
}
