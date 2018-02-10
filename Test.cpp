/*
 * Main.cpp
 *
 *  Created on: Feb 16, 2016
 *      Author: megfredericks
 */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

int main() {
	// Printing description of Stage
	std::string description;
	std::ifstream infile;
	infile.open("beginning.txt");
	while(!infile.eof() && (description.front() != '$')) {
		getline(infile, description);
		if (description.front() == '$') {
			break;
		}
		std::cout << description << std::endl;
	}
	// Printing out player options
	std::cout << std::endl;
	std::cout << "(1) " << description.substr(1) << std::endl;
	for (int i = 0; i < 2; i++) {
		getline(infile, description);
		std::cout << "(" << i + 2 << ") " << description << std::endl;
	}
	infile.close();

	// Getting user choice
	int input;
	std::cout << "What will you do? ";
	std::cin >> input;

	if (input == 1) {
		// West case (set of footprints)
		int input2;
		std::ifstream infile2;
		while(!infile2.eof() && (description.front() != '$')) {
			getline(infile2, description);
			if (description.front() == '$') {
				break;
			}
			std::cout << description << std::endl;
		}
	} else if (input == 2) {
		int input3;
	} else if (input == 3) {
		int input4;
	} else if (input == 4) {
		int input5;
	} else {
		// incorrect input
	}
}

