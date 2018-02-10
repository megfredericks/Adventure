/*
 * Item.hpp
 *
 *  Created on: Mar 8, 2016
 *      Author: megfredericks
 */

#ifndef ITEM_HPP_
#define ITEM_HPP_

#include <string>

class Item {
public:
	Item(std::string name);
	std::string getName();
private:
	std::string name;
};

#endif /* ITEM_HPP_ */
