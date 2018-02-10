/*
 * Player.hpp
 *
 *  Created on: Mar 7, 2016
 *      Author: megfredericks
 */

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include <string>
#include <vector>
#include "Item.hpp"

class Player {
public:
	Player(std::string name);
	bool addItem(Item newItem);
	std::vector<Item> inventory;
private:
	std::string name;
};

#endif /* PLAYER_HPP_ */
