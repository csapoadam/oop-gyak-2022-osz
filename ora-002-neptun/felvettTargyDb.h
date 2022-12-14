#pragma once

#include <map>
#include <vector>
#include <string>

#include "targyDb.h"
#include "hallgatoDb.h"

namespace Neptun {
	class FelvettTargyDb {
		const TargyDb& targyakDb;
		const HallgatoDb& hallgatokDb;

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
		FelvettTargyDb(TargyDb&, HallgatoDb&);
		void add(const std::string& neptunkod, const std::string& kurzuskod);
		void printTargyakByHallgato(const std::string& neptunkod) const;
		void printHallgatokByTargy(const std::string& targykod) const;
		// Ez pedig majd hozzaadja a kreditszamot a hallgatohoz,
		// es torli a felvett targyak db-jebol
		void completeTargy(const std::string& neptunkod, const std::string& targykod);
	};
}