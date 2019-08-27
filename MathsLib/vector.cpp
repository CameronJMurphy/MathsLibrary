#include "vector.h"

///////vector4/////////
vector4::vector4()
{
	x = 0;
	y = 0;
	z = 0;
	w = 0;
}

vector4::vector4(float X, float Y, float Z, float W) : x(X), y(Y), z(Z), w(W)
{

}

vector4::~vector4()
{

}

void vector4::editVector()
{
	std::cout << "Enter an x value, then a y value, then a z value & finally a w value" << std::endl;
	std::cin >> x >> y >> z >> w;

}


float vector4::magnitude()
{
	return sqrt(x * x + y * y + z * z + w * w);
}

bool vector4::normalize()
{

	float L = magnitude();
	if (L != 0)
	{
		x = x / L;
		y = y / L;
		z = z / L;
		w = w / L;
		return true;

	}
	else
		return false;
}

vector4* vector4::operator+ (const vector4& other) const//Add one vector to another
{
	vector4* temp;
	temp->x = x + other.x;
	temp->y = y + other.y;
	temp->z = z + other.z;
	temp->w = w + other.w;

	return temp;
}

vector4* vector4::operator- (const vector4& other) const //subtract one vector from another
{
	vector4* temp;
	temp->x = x - other.x;
	temp->y = y - other.y;
	temp->z = z - other.z;
	temp->w = w - other.w;

	return temp;
}

vector4 vector4::cross(vector4 other)
{
	// the result is a Vector, so W is 0
	return { y * other.z - z * other.y,
	z * other.x - x * other.z,
	x * other.y - y * other.x,
	0 };
}

float vector4::dot(vector4 other)
{
	return x * other.x + y * other.y + z * other.z + w * other.w;
}

vector4 vector4::operator* (float other)//scale
{
	vector4 temp;
	temp.x = x * other;
	temp.y = y * other;
	temp.z = z * other;
	temp.w = w * other;

	return temp;
}

void vector4::operator += (const vector4& other) 
{
	x += other.x;
	y += other.y;
	z += other.z;
	w += other.w;
}


///////////vector3/////////////

vector3::vector3()
{
	vector3(0, 0, 0);
}

vector3::vector3(float X, float Y, float Z) : x(X), y(Y), z(Z)
{

}

vector3::~vector3()
{

}

void vector3::editVector()
{
	std::cout << "Enter an x value, then a y value, and finally a z value" << std::endl;
	std::cin >> x >> y >> z;

}


float vector3::magnitude()
{
	return sqrt(x*x + y*y + z*z);

}

bool vector3::normalize()
{

	float L = magnitude();
	if (L != 0)
	{
		x = x / L;
		y = y / L;
		z = z / L;
		return true;

	}
	else
		return false;
}

vector3 vector3::operator+ (const vector3& other) const //Add one vector to another
{
	vector3 temp = *this;
	temp.x += other.x;
	temp.y += other.y;
	temp.z += other.z;

	return temp;
}

vector3 vector3::operator- (const vector3& other) const//subtract one vector from another
{
	vector3 temp = *this;
	temp.x -= other.x;
	temp.y -= other.y;
	temp.z -= other.z;

	return temp;
}

vector3 vector3::cross(const vector3& other) const
{
	vector3 temp;
	temp.x = (y * other.z) - (z * other.y);
	temp.y = (z * other.x) - (x + other.z);
	temp.z = (x * other.y) - (y * other.x);
	return temp;
}

float vector3::dot(const vector3& other) const
{
	return x * other.x + y * other.y + z * other.z;
}

vector3 vector3::operator* (const float other) const//scale
{
	vector3 temp = *this;
	temp.x *= other;
	temp.y *= other;
	temp.z *= other;

	return temp;
}

float& vector3::operator[](const int num)
{
	switch (num)
	{
	case(0):
		return x;
		break;
	case(1):
		return y;
		break;
	case(2):
		return z;
		break;
	}
}
const float& vector3::operator[](const int num) const
{
	switch (num)
	{
	case(0):
		return x;
		break;
	case(1):
		return y;
		break;
	case(2):
		return z;
		break;
	}
}

vector3::operator float*()
{
	return &x;
}

void vector3::print()
{
	std::cout << x << " " << y << " " << z << std::endl;
}
////////vector2///////////

vector2::vector2()
{
	x = 0;
	y = 0;
}

vector2::~vector2()
{

}

void vector2::editVector()
{
	std::cout << "Enter an x value, then a y value" << std::endl;
	std::cin >> x >> y;
}

vector2 vector2::operator+(vector2 other)
{
	vector2 temp = *this;
	temp.x += other.x;
	temp.y += other.y;

	return temp;
};

vector2 vector2::operator-(vector2 other)
{
	vector2 temp = *this;
	temp.x -= other.x;
	temp.y -= other.y;

	return temp;
};

vector2 vector2::operator*(float num)
{
	vector2 temp = *this;
	temp.x *= num;
	temp.y *= num;

	return temp;
};



float vector2::magnitude()
{
	return sqrt(x*x + y*y);
}

bool vector2::normalized()
{
	float L = magnitude();
	if (L != 0)
	{
		x = x / L;
		y = y / L;
		return true;

	}
	else
		return false;
};

void vector2::print()
{
	std::cout << x << " " << y << std::endl;
}

float vector2::dot(vector2& other)
{
	return x * other.x + y * other.y;

}