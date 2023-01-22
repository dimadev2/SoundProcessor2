#pragma once
#include <exception>
#include "FileThread.h"

class readException : std::exception {
public:
	readException(const char* msg) : msg(msg) {}
	std::string show() const;
private:
	std::string msg;
};

class Reader : FileThread {
public:
	Reader(const char* filename);
	~Reader(); 
	const char* getHeader() const { return fileHeader; }

	Chunk readChunk();
private:
	char fileHeader[488];
};
