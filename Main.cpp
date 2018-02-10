/*
 * Main.cpp
 *
 *  Created on: Mar 5, 2016
 *      Author: megfredericks
 */

#include <vector>
#include <ctime>
#include <iostream>
#include <ctype.h>

#include "Stage.hpp"
#include "Player.hpp"
#include "Item.hpp"

std::vector<Stage> createMap() {
	int numberOfStages = 12;
	std::vector<Stage> gameMap;
	std::ifstream infile;
	infile.open("gameText.txt");
	std::string line;
	std::string description;
	std::string name;
	bool continueReading = true;
	for (int i = 0; i < numberOfStages; i++) {
		getline(infile, line);
		name = line;
		continueReading = true;
		description = "";
		line = "";
		while (continueReading) {
			getline(infile, line);
			if (line.front() == '@') {
				continueReading = false;
			} else {
				description.append(line + "\n");
			}
		}
		gameMap.push_back(Stage (name));
		gameMap.at(i).setDescription(description);
	}
	gameMap.at(0).setExit(gameMap.at(2).getName(), 1); // Beginning --> River
	gameMap.at(0).setExit(gameMap.at(1).getName(), 2); // Beginning --> Clearing
	gameMap.at(1).setExit(gameMap.at(4).getName(), 1); // Clearing --> InsideHouse
	gameMap.at(1).setExit(gameMap.at(11).getName(), 2); // Clearing --> Footsteps
	gameMap.at(2).setExit(gameMap.at(3).getName(), 2); // River --> Upstream
	gameMap.at(2).setExit(gameMap.at(9).getName(), 1); // River --> RiverDeath
	gameMap.at(3).setExit(gameMap.at(6).getName(), 1); // Upstream --> Cave
	gameMap.at(3).setExit(gameMap.at(8).getName(), 2); // Upstream --> Bridge
	gameMap.at(4).setExit(gameMap.at(5).getName(), 1); // InsideHouse --> Bedroom
	gameMap.at(4).setExit(gameMap.at(1).getName(), 2); // InsideHouse --> Clearing
	gameMap.at(5).setExit(gameMap.at(10).getName(), 1); // Bedroom --> TrapDoor
	gameMap.at(5).setExit(gameMap.at(1).getName(), 2); // Bedroom --> Clearing
	gameMap.at(6).setExit(gameMap.at(7).getName(), 1); // Cave --> InnerCave
	gameMap.at(6).setExit(gameMap.at(8).getName(), 2); // Cave --> Bridge
	gameMap.at(10).setExit(gameMap.at(0).getName(), 2); // TrapDoor --> Beginning
	gameMap.at(10).setExit(gameMap.at(11).getName(), 1); // TrapDoor --> Footsteps
	gameMap.at(9).makeEnding(); // RiverDeath = ending
	gameMap.at(7).makeEnding(); // DeepCave = ending
	gameMap.at(11).makeEnding(); // Footsteps = ending
	gameMap.at(6).addItem(Item ("shelter")); // Cave (+shelter)
	gameMap.at(8).addItem(Item ("food")); // Bridge (+food)
	gameMap.at(4).addItem(Item ("shelter")); // InsideHouse (+shelter)
	gameMap.at(2).addItem(Item ("water")); // River (+water)

	return gameMap;
}

void invalidInput() {
	srand (time(NULL));
	int randomNum = rand() % 3;
	std::string output;
	if (randomNum == 0) {
		output = "Excuse me?";
	} else if (randomNum == 1) {
		output = "Stop it.";
	} else if (randomNum == 2) {
		output = "That is not an option.";
	}
	std::cout << output << std::endl;
}

bool checkInput(std::string command) {
	if (command.compare("exit") == 0) {
		std::cout << "Ending game. Goodbye." << std::endl;
		return false;
	} else if (command.compare("1") == 0 || command.compare("2") == 0) {
		return true;
	} else {
		invalidInput();
		return true;
	}
}

int main() {
	std::vector<Stage> gameMap (createMap());
	int currentStage = 0;
	bool running = true;
	std::string input;

	// Getting player name
	std::cout << "Welcome to S u r v i v a l." << std::endl << "What is your name?" << std::endl;
	std::cout << "> ";
	std::cin >> input;
	Player player (input);
	std::cout << "Hello " << input << "." << std::endl;
	std::cout << "Beginning journey . . ." << std::endl << std::endl;

	// Get description of first room
	std::string temp;
	gameMap[currentStage].explain();
	bool end; // If the player has acquired food, shelter, and water

	while(running) {
		std::cout << "> ";
		std::cin >> input;
		running = checkInput(input);
		if (!running) {
			break;
		}
		std::cout << std::endl;
		std::string stageName = gameMap[currentStage].getName();
		gameMap[currentStage].update(input, stageName, player);
		for (int i = 0; i < gameMap.size(); i++) {
			if (gameMap.at(i).getName().compare(stageName) == 0) {
				currentStage = i;
			}
		}
		gameMap[currentStage].explain();
		if (!gameMap[currentStage].items.empty()) {
			end = player.addItem(gameMap[currentStage].items.at(0));
		}
		if (end) {
			std::cout << std::endl;
			std::cout << "C O N G R A T U L A T I O N S ! ! !" << std::endl;
			std::cout << "You've acquired food, water, and shelter! You survived . . . For now." << std::endl;
			running = false;
		} else if (gameMap[currentStage].isEnd()) {
			std::cout << std::endl;
			std::cout << "Sorry, you didn't survive. Better luck next time!" << std::endl;
			running = false;
		} else {
			std::cout << "What will you do?" << std::endl;
		}
	}
	std::cout << "Thanks for playing!" << std::endl;
}



