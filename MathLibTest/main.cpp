#include <vector.h>
#include <Bits.h>
#include <Matrix.h>

#include <iostream>

int main()
{
	//vector2//

	/*vector2 a(2,3);
	vector2 b(4, 5);
	vector2 c = 5 * a;
	vector2 d(3, 4);
	a.print();
	b.print();
	c.print();
	d.normalized();
	float length = d.magnitude();
	float dotProduct = a.dot(b);
	std::cout << dotProduct;*/
	
	//vector3//

	/*vector3 a(2, 3, 4);
	vector3 b(5, 6, 7);
	vector3 c = a.cross(b);
	vector3 d = 2 * a;
	float dotProduct = a.dot(b);

	a.print();
	b.print();
	c.print();
	d.print();

	float* e = a;
	std::cout << *e;

	std::cout << dotProduct;
	a.normalize();
	float length = a.magnitude();

	std::cout << length;*/

	
	//vector4//

	vector4 a(1, 2, 3, 4);
	vector4 b(5, 6, 7, 8);
	vector4 c = a - b;

	a += b;

	c.normalise();
	std::cout << c.magnitude() << std::endl;;
	a.print();
	b.print();
	c.print();

	

	return 0;
}