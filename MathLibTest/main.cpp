#include <vector.h>
#include <iostream>

int main()
{

	vector3 a;
	vector3 b;
	float c;

	a.editVector();
	c = a[2];
	std::cout << c;
	//a.print();
	return 0;
}