#include "Food.h"
#include <iostream>

Food::Food()
{
	count = 0;
}

Food::~Food()
{
}

void Food::outputTheData() {
	if (isAvailable) {
		std::cout << "Food (id: " << id << ") available, price: " << cost << std::endl;
	}
	else {
		std::cout << "Food (id: " << id << ") unavailable, price: " << cost << std::endl;
	}
}

void Food::setCount(int val) {
	count = val;
}
