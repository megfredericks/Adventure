/*
 * Item.cpp
 *
 *  Created on: Mar 8, 2016
 *      Author: megfredericks
 */

#include <vector>
#include "Item.hpp"

Item::Item(std::string name) {
	// TODO Auto-generated constructor stub
	this->name = name;
}

std::string Item::getName() {
	return this->name;
}


