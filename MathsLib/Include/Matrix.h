#pragma once
#include <vector.h>
#include <iostream>

static const float pi = 3.1415926;

class Matrix3
{
public:

	Matrix3();
	Matrix3(float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3);
	Matrix3(vector3 X, vector3 Y, vector3 Z);
	~Matrix3();

	union {
		struct {
			vector3 xAxis;
			vector3 yAxis;
			union
			{
				vector3 zAxis, translation;
			};
			
		};
		vector3 axis[3];
		float data[3][3];
	};

	

	static const Matrix3 identity;

	const vector3& operator[] (int index) const;

	vector3 operator* (const vector3& vec);

	Matrix3 operator* (const Matrix3& other) const;
	

	Matrix3 transposed() const;

	vector3& operator[] (int index);

	operator float*();

	void print();
	
	void setRotateX(float rotation);
	void rotateX(float radians);

	void setRotateY(float rotation);
	void rotateY(float radians);

	void setRotateZ(float rotation);
	void rotateZ(float radians);

	void setScaled(float x, float y, float z);
	void setScaled(const vector3& vec);

	void scale(float x, float y, float z);//takes three floats
	void scale(const vector3& vec); //overload to take a vector

	void setEuler(float pitch, float yaw, float roll);
};

class Matrix4
{
public:

	union
	{
		struct
		{
			vector4 xAxis, 
					yAxis, 
					zAxis,
					translation;
		};
		vector4 axis[4];
		float data[4][4];
		float dataSingle[16];
	};

	static const Matrix4 identity;
	
	Matrix4();
	Matrix4(float x1, float y1, float z1,float w1, float x2, float y2, float z2, float w2, float x3, float y3, float z3, float w3, float x4, float y4, float z4, float w4);
	Matrix4(vector4 X, vector4 Y, vector4 Z, vector4 W);
	~Matrix4();
	Matrix4(const Matrix4& other);



	const vector4& operator[] (int index) const;
	vector4& operator[] (int index);

	vector4 operator* (const vector4& vec);

	Matrix4 operator* (const Matrix4& other);
	
	


	Matrix4 transposed() const;


	operator float*();
	operator const float*()const;

	void print();

	void setRotateX(float rotation);
	void rotateX(float radians);

	void setRotateY(float rotation);
	void rotateY(float radians);

	void setRotateZ(float rotation);
	void rotateZ(float radians);

	void setScaled(float x, float y, float z);
	void setScaled(const vector4& vec);

	void scale(float x, float y, float z);//takes three floats
	void scale(const vector4& vec); //overload to take a vector

	void setEuler(float pitch, float yaw, float roll);

	void translate(float x, float y, float z);

	Matrix4 operator = (const Matrix4& other);

};
