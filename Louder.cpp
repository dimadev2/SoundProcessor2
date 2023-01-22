#include "Louder.h"

void Louder::process(list<string> argv) {
	auto iter = argv.begin();
	Reader r((*iter).c_str());
	iter++;
	Writer w((*iter).c_str(), r.getHeader());
	iter++;
	size_t loud = std::atoi((*iter).c_str());
	iter++;
	Interval interval;
	interval.start = std::atoi((*iter).c_str());
	iter++;
	interval.end = std::atoi((*iter).c_str());

	size_t secs = 0;
	while (true) {
		secs++;
		try {
			Chunk c = r.readChunk();
			if (secs >= interval.start && secs <= interval.end) {
				for (size_t i = 0; i < c.size; i++) {
					c.chunk[i] *= loud;
				}
			}
			w.writeChunk(c);
		}
		catch (readException) {
			break;
		}
	}
}
