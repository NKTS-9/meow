#include <iostream>
#include "Product.h"
#include "Clothes.h"
#include "Food.h"


void Calculation(Product* pr[5]) {
	int max = 0, num = 0;
	for (int i = 0; i < 5; ++i) {
		if (pr[i]->cost > max) {
			max = pr[i]->cost;
			num = i;
		}
	}
	std::cout << "The most expensive product: ";
	pr[num]->outputTheData();
	std::cout << std::endl;
}

void ChangeTheArray(Product* pr[5]) {
	std::cout << "What position should be changed? \n>";
	int p;
	std::cin >> p;
	--p;
	std::cout << "Enter ID, availability(1 or 0) and cost\n>";
	int _id, _av, _cost;
	std::cin >> _id >> _av >> _cost;
	pr[p]->setData(_id, _av, _cost);
}

void OutputTheArray(Product* pr[5]) {
	std::cout << "=====================================\n";
	for (int i = 0; i < 5; i++)
	{
		pr[i]->outputTheData();
	}
	std::cout << "=====================================\n";
}

void Menu(Product* pr[5]) {
	std::cout << "Enter:\n1.Output The Array\n2.Change The Array\n3.Parameter calculation\n4.Exit the menu\n>";
	int c;
	std::cin >> c;

	switch (c)
	{
	case 1:
		OutputTheArray(pr);
		Menu(pr);
		return;

	case 2:
		ChangeTheArray(pr);
		Menu(pr);
		return;

	case 3:
		Calculation(pr);
		Menu(pr);
		return;

	case 4:
		return;

	default:
		std::cout << "Access denied\n";
		Menu(pr);
		return;
	}
}

int main()
{
	Product myProduct;
	Food myFood1;
	Food myFood2;
	Clothes myClothes1;
	Clothes myClothes2;

	Product* pr[5];

	pr[0] = &myProduct;
	pr[1] = &myFood1;
	pr[2] = &myFood2;
	pr[3] = &myClothes1;
	pr[4] = &myClothes2;

	Menu(pr);
}
