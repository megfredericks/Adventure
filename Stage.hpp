/*
 * Stage.hpp
 *
 *  Created on: Feb 15, 2016
 *      Author: megfredericks
 */

#ifndef STAGE_HPP_
#define STAGE_HPP_

#include <string>
#include <fstream>
#include <iostream>
#include <vector>

#include "Player.hpp"
#include "Item.hpp"

class Stage {
public:
	Stage(std::string name);
	void setExit(std::string nextStageToMove, int command);
	void explain();
	void update(std::string command, std::string& currentStage, Player player);
	std::string getName();
	std::string getDescription();
	void setDescription(std::string newDescription);
	void setName(std::string newName);
	void addItem(Item item);
	std::vector<Item> items;
	bool isEnd();
	void makeEnding();
private:
	struct nextStage {
		std::string stageToMove;
		int key; // the number the user enters to get to this room
	};
	std::string name;
	std::string description;
	nextStage options[2];
	bool ending;
};

#endif /* STAGE_HPP_ */
