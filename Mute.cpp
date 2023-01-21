#include "Mute.h"

void Mute::process(list<string> argv) {
	auto iter = argv.begin();
	Reader r((*iter).c_str());
	iter++;
	Writer w((*iter).c_str(), r.getHeader());
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
				memset(c.chunk, 0, c.size * config::blockAlign);
			}
			w.writeChunk(c);
		}
		catch (readException) {
			break;
		}
	}
}
