#include "Bits.h"
#include <iostream>
#include <string>


const char* binarystring = "101";

int binToDec(const char* binaryString)
{
	int decimal = std::stoi(binaryString, nullptr, 2);
	return decimal;
}

void decToBin(char* binaryString, int len, int value)
{
	if (value != 0)
	{
		for (int i = 0; value > 0; ++i)
		{
			binaryString[i] = value % 2;
			value = value / 2;
		}
	}
}

void setBit(char& bitfield, char bit, char value)
{
	bitfield |= value << bit;
}

char checkBit(char& bitfield, char bit)
{
	return bitfield &( 1 << ((bit - '0') - 1));
}