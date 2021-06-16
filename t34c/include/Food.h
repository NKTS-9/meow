
#include <Product.h>

class Food :
	public Product
{

public:
	Food();
	~Food();
	void outputTheData();
	void setCount(int val);

private:

	int count;

};
