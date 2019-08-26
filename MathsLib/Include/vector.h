#pragma once
#include <iostream>
#include <math.h>

class vector4
{
private:
	float x, y, z, w;
public:

	vector4();
	~vector4();

	void editVector();

	float magnitude();

	bool normalize();

	vector4 operator+ (vector4 other);//Add one vector to another


	vector4 operator- (vector4 other);//subtract one vector from another


	vector4 cross(vector4 other);//cross product

	float dot(vector4 other);


	vector4 operator* (float other);//scale


	friend vector4 operator*(float num, vector4 object)//scale
	{

		object.x *= num;
		object.y *= num;
		object.z *= num;

		return object;
	}

};



class vector3
{
private:
	//float x, y, z;
public:

	vector3();
	vector3(float X, float Y, float Z);
	~vector3();
	
	union {
		struct {
			float x;
			float y;
			float z;
		};
		float axis[3];
		float data[3][3];
		
	
	};
	void editVector();

	float magnitude();

	bool normalize();

	vector3 operator+ (const vector3& other) const;//Add one vector to another
	

	vector3 operator- (const vector3& other) const;//subtract one vector from another
	

	
	vector3 cross(const vector3& other) const;//cross product

	float dot(const vector3& other) const;
	

	vector3 operator* (const float other) const;//scale
	

	friend vector3 operator*(float num, vector3 object)//scale
	{

		object.x *= num;
		object.y *= num;
		object.z *= num;

		return object;
	}
	
	float& operator[](const int num);

	const float& operator[](const int num) const;

	operator float*();

	void print();
	
};


class vector2
{
private:
	float x, y;
public: 

	vector2();
	~vector2();

	void editVector();

	vector2 operator+(vector2 other);

	vector2 operator-(vector2 other);

	vector2 operator*(float num);

	friend void operator*(float num, vector2& vec)
	{

		vec.x *= num;
		vec.y *= num;
	};
	
	float magnitude();	

	bool normalized();

	void print();

	float dot(vector2& other);

};




