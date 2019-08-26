#pragma once
#include <vector.h>

class Matrix3
{
private:
	//vector3 xAxis, yAxis, zAxis;

public:

	Matrix3();
	Matrix3(vector3 X, vector3 Y, vector3 Z);
	~Matrix3();

	union {
		struct {
			vector3 xAxis;
			vector3 yAxis;
			vector3 zAxis;
		};
		vector3 axis[3];
		float data[3][3];
	};

	static const Matrix3 identity;

	const vector3& operator[] (int index) const;

	vector3 operator* (const vector3& vec) const;

	Matrix3 operator* (const Matrix3* other) const;
	Matrix3 operator* (Matrix3* other);

	Matrix3 transposed() const;

	vector3& operator[] (int index);

	operator float*();


	
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
private:
	vector4 x, y, z, w;

public:

};
