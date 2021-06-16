
#include <Product.h>

class Clothes :
	public Product
{
public:
	Clothes();
	~Clothes();
	void outputTheData();
	void setCount(int val);

private:

	int size;

};
