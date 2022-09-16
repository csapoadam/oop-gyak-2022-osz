#pragma once

#include <map>
#include <vector>
#include <string>

namespace Neptun {
	class FelvettTargyDb {
		std::map<
			std::string, std::vector<std::string>
		> hallgatokToKurzusok;
		std::map<
			std::string, std::vector<std::string>
		> kurzusokToHallgatok;
	public:
		void add(std::string neptunkod, std::string kurzuskod);
		void printTargyakByHallgato(std::string neptunkod);
	};
}