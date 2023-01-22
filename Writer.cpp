#include "Writer.h"

Writer::Writer(const char* filename, const char* fileHeader) {
	fopen_s(&file, filename, "w");
	fwrite(fileHeader, 1, 488, file);
}

Writer::~Writer() {
	fclose(file);
}

void Writer::writeChunk(const Chunk& chunk) {
	fwrite(chunk.chunk, config::blockAlign, chunk.size, file);
}
