#include <vector.h>
#include <Bits.h>
#include <iostream>

int main()
{
	char bit = '1';
	char bitfield{ 110 };
	
	//1101110

	char set = checkBit(bitfield, bit);

	std::cout << (int)set;
	return 0;
}