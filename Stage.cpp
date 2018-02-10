/*
 * Stage.cpp
 *
 *  Created on: Feb 15, 2016
 *      Author: megfredericks
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include "Stage.hpp"
#include "Player.hpp"
#include "Item.hpp"

Stage::Stage(std::string name) {
	// TODO Auto-generated constructor stub
	setName(name);
	this->ending = false;
}

void Stage::setName(std::string newName) {
	this->name = newName;
}

void Stage::setDescription(std::string newDescription) {
	this->description = newDescription;
}

std::string Stage::getName() {
	return this->name;
}

std::string Stage::getDescription() {
	return this->description;
}

void Stage::explain() {
	printf("%s", this->description.c_str());
}

void Stage::setExit(std::string nextStageToMove, int command) {
	nextStage stageInfo;
	stageInfo.stageToMove = nextStageToMove;
	stageInfo.key = command;
	this->options[command - 1] = stageInfo;
}

void Stage::update(std::string command, std::string& currentStage, Player player) {
	int choice;
	std::stringstream stream;
	stream.str(command);
	stream >> choice;
	currentStage = options[choice - 1].stageToMove;
}

void Stage::addItem(Item item) {
	this->items.push_back(item);
}

bool Stage::isEnd() {
	return this->ending;
}

void Stage::makeEnding() {
	this->ending = true;
}


