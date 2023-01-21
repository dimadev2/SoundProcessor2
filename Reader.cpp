#include "Reader.h"

Reader::Reader(const char* filename) {
	fopen_s(&file, filename, "r");
	fread(fileHeader, 1, 44, file);
}

Reader::~Reader() {
	fclose(file);
}

Chunk Reader::readChunk() {
	Chunk ch;

	size_t len = fread(ch.chunk, config::blockAlign, Chunk::capacity, file);
	if (len == 0) {
		throw readException("End of file");
	}
	else {
		ch.size = len;
		return ch;
	}
}
