#include "Product.h"
#include <iostream>

Product::Product()
{
	id = 0;
	isAvailable = false;
	cost = 0;
}

Product::~Product() {}

void Product::outputTheData() {
	if (isAvailable) {
		std::cout << "Name (id: " << id << ") available, price: " << cost << std::endl;
	}
	else {
		std::cout << "Name (id: " << id << ") unavailable, price: " << cost << std::endl;
	}
}

void Product::setData(int _id, bool _ava, int _cost) {
	id = _id;
	isAvailable = _ava;
	cost = _cost;
}
