#ifndef PRODUCT_H
#define PRODUCT_H

class Product
{
public:
	Product();
	~Product();
	virtual void outputTheData();
	void setData(int _id, bool _ava, int _cost);
	int cost;

protected:

	int id;
	bool isAvailable;

};
#endif
