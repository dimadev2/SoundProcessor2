#include "Mix.h"

void Mix::process(list<string> argv) {
	auto iter = argv.begin();
	Reader r1((*iter).c_str());
	iter++;
	Reader r2((*iter).c_str());
	iter++;
	Writer w((*iter).c_str(), r1.getHeader());
	iter++;
	Interval interval;
	interval.start = std::atoi((*iter).c_str());
	iter++;
	interval.end = std::atoi((*iter).c_str());

	size_t secs = 0;
	while (true) {
		secs++;
		try {
			Chunk c1 = r1.readChunk();
			Chunk c2 = r2.readChunk();
			if (secs >= interval.start && secs <= interval.end) {
				size_t minSize = c1.size < c2.size ? c1.size : c2.size;
				for (size_t i = 0; i < minSize; i++) {
					c1.chunk[i] = (c1.chunk[i] + c2.chunk[i]) / 2;
				}
			}
			w.writeChunk(c1);
		}
		catch (readException) {
			break;
		}
	}
}
