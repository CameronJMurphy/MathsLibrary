#pragma once
#include <iostream>
#include <math.h>
#include <vector>

class vector4
{
public:

	vector4();
	vector4(float X, float Y, float Z , float W);
	~vector4();
	vector4(const vector4& other);
	

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
	
	};

	void editVector(float X, float Y, float Z, float W);

	float magnitude();

	void normalise();

	vector4 operator+ (const vector4& other) const;//Add one vector to another

	void operator += (const vector4& other);

	vector4 operator- (const vector4& other)const;//subtract one vector from another

	float& operator[](const int x);

	const float& operator[](const int x) const;

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

	operator float*();
	operator const float*()const;

	vector4& operator=(const vector4& other);
	

};



class vector3
{
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
	void editVector(float X, float Y, float Z);

	float magnitude();

	bool normalise();

	vector3 operator+ (const vector3& other) const;//Add one vector to another
	

	vector3 operator- (const vector3& other) const;//subtract one vector from another
	

	
	vector3 cross(const vector3& other) const;//cross product

	float dot(const vector3& other) const;
	

	vector3 operator* (const float other) const;//scale
	

	friend vector3 operator*(float num, vector3 object)//scale
	{
		vector3 temp(object.x*num, object.y*num, object.z*num);
		return temp;
	}
	
	float& operator[](const int num);

	const float& operator[](const int num) const;

	operator float*();

	void print();
	
};


class vector2 // tested
{
public: 

	vector2();
	vector2(float X, float Y);
	~vector2();

	union
	{
		struct
		{
			float x;
			float y;
		};
		float data[2];
	};

	void editVector(float X, float Y);

	vector2 operator+(vector2 other);

	vector2 operator-(vector2 other);

	vector2 operator*(float num);

	friend vector2 operator*(float num, vector2& vec)
	{
		vector2 temp(vec.x*num, vec.y*num);
		return temp;
	};
	
	float magnitude();	

	bool normalise();

	void print();

	operator float*();


	float dot(vector2& other);

};




