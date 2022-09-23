#pragma once

#include <map>
#include <vector>
#include <string>

#include "targyDb.h"

namespace Neptun {
	class FelvettTargyDb {
		std::map<
			std::string, std::vector<std::string>
		> hallgatokToKurzusok;
		std::map<
			std::string, std::vector<std::string>
		> kurzusokToHallgatok;

		// const-nak kell lenniuk, mert printTargyakByHallgato() is const
		// es meghivja (ugyanugy ahogy printHallgatokByTargy is)
		bool doesTargyExist(const std::string&) const;
		bool doesHallgatoExist(const std::string&) const;
		void ensureTargyExists(const std::string&);
		void ensureHallgatoExists(const std::string&);

	public:
		void add(const std::string& neptunkod, const std::string& kurzuskod);
		void printTargyakByHallgato(
			const std::string& neptunkod,
			TargyDb& targyakDb
		) const;
		void printHallgatokByTargy(const std::string& targykod) const;
	};
}