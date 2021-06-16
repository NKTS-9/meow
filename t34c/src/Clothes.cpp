#include "Clothes.h"

#include <iostream>
Clothes::Clothes()
{
	size = 0;
}

Clothes::~Clothes()
{
}

void Clothes::outputTheData() {
	if (isAvailable) {
		std::cout << "Clothes (id: " << id << ") available, price: " << cost << std::endl;
	}
	else {
		std::cout << "Clothes (id: " << id << ") unavailable, price: " << cost << std::endl;
	}
}

void Clothes::setCount(int val) {
	size = val;
}
