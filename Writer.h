#pragma once
#include "FileThread.h"

class Writer : FileThread {
public:
	Writer(const char* filename, const char* fileHeader);
	~Writer();

	void writeChunk(const Chunk& chunk);
};