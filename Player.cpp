/*
 * Player.cpp
 *
 *  Created on: Mar 7, 2016
 *      Author: megfredericks
 */

#include "Player.hpp"
#include "Item.hpp"
#include <string>
#include <vector>

Player::Player(std::string name) {
	// TODO Auto-generated constructor stub
	this->name = name;
}

bool Player::addItem(Item item) {
	this->inventory.push_back(item);
	if (this->inventory.size() == 3) {
		return true;
	}
	return false;
}



