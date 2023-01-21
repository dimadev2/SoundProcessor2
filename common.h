#pragma once
#include <cstdint>
#include <vector>
#include <string>

using std::vector;
using std::string;

namespace config {
	const size_t sampleRate = 44100;
	const size_t blockAlign = 2;
}

struct Interval {
	size_t start;
	size_t end;
};

struct Chunk {
	Chunk() {
		chunk = new uint16_t[capacity];
	}
	~Chunk() {
		delete[] chunk;
	}

	static constexpr size_t capacity = config::sampleRate;
	size_t size;
	uint16_t* chunk;
};
