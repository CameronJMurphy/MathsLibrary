#pragma once
#include <iostream>
#include <math.h>

class vector4
{
public:

	vector4();
	vector4(float X, float Y, float Z , float W);
	~vector4();

	

	union
	{
		struct
		{
			float x;
			float y;
			float z;
			float w;
		};
		float data[4];
		int data[4];

	};

	void editVector();

	float magnitude();

	bool normalize();

	vector4* operator+ (const vector4& other) const;//Add one vector to another

	void operator += (const vector4& other);

	vector4* operator- (const vector4& other)const;//subtract one vector from another

	void print();

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
			union
			{
				float z, w;
			};
		};
		float data[3];
	
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




