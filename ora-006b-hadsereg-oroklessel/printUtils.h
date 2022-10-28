#pragma once
#include <iostream>

void printIndents(int indent) {
	for (int ind = 0; ind < indent; ind++) {
		std::cout << "\t";
	}
}