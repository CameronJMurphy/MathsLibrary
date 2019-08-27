#include "Matrix.h"


/////////////Matrix3////////////////////
Matrix3::Matrix3()
{
	vector3 X, Y, Z;//they will be 0,0,0
	Matrix3(X,Y,Z);
}
Matrix3::Matrix3(float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3)
{
	data[0][0] = x1;
	data[1][0] = y1;
	data[2][0] = z1;
	data[0][1] = x2;
	data[1][1] = y2;
	data[2][1] = z2;
	data[0][2] = x3;
	data[1][2] = y3;
	data[2][2] = z3;
	
}

Matrix3::Matrix3(vector3 X, vector3 Y, vector3 Z) : xAxis(X), yAxis(Y), zAxis(Z)
{

}
Matrix3::~Matrix3()
{

}

const Matrix3 Matrix3::identity = Matrix3(1.0f,0.0f,0.0f,
										   0.0f,1.0f,0.0f,
										   0.0f,0.0f,1.0f);

vector3 Matrix3::operator* (const vector3& vec) const
{
	vector3 result;
	for (int row = 0; row < 3; ++row) {
		result[row] = data[0][row] * vec[0] +
					  data[1][row] * vec[1] +
					  data[2][row] * vec[2];
	}
	return result;

}
Matrix3 Matrix3::operator* (const Matrix3& other) const
{
	Matrix3 result;
	for (int row = 0; row < 3; ++row) {
		for (int col = 0; col < 3; ++col) {
			result.data[col][row] = data[0][row] * other.data[col][0] +
									data[1][row] * other.data[col][1] +
									data[2][row] * other.data[col][2];
		}
	}
	return result;

}



Matrix3 Matrix3::transposed() const {
	Matrix3 result;
	// flip row and column
	for (int row = 0; row < 3; ++row)
		for (int col = 0; col < 3; ++col)
			result.data[row][col] = data[col][row];
	return result;
}


vector3& Matrix3::operator[] (int index)
{
	return axis[index];
}

const vector3& Matrix3::operator[] (int index) const
{
	return axis[index];
}

Matrix3::operator float*()
{
	return &xAxis.x;
}

void Matrix3::setRotateX(float radians)
{
	// leave X axis and elements unchanged
	xAxis = { 1, 0, 0 };
	yAxis = { 0, cosf(radians), sinf(radians) };
	zAxis = { 0, -sinf(radians), cosf(radians) };

}
void Matrix3::rotateX(float radians) 
{
	Matrix3 temp;
	temp.setRotateX(radians);
	*this = *this * temp;
}


void Matrix3::setRotateY(float radians)
{
	xAxis = { cosf(radians), 0, -sinf(radians) };
	yAxis = { 0, 1, 0};
	zAxis = { sinf(radians), 0, cosf(radians) };
}
void Matrix3::rotateY(float radians) {
	Matrix3 temp;
	temp.setRotateY(radians);
	*this = *this * temp;
}

void Matrix3::setRotateZ(float radians)
{
	xAxis = { cosf(radians), sinf(radians), 0 };
	yAxis = { -sinf(radians), cosf(radians), 0 };
	zAxis = { 0, 0 , 1 };
}
void Matrix3::rotateZ(float radians) {
	Matrix3 temp;
	temp.setRotateZ(radians);
	*this = *this * temp;
}

void Matrix3::setScaled(float x, float y, float z) {
	// set scale of each axis
	xAxis = { x, 0, 0 };
	yAxis = { 0, y, 0 };
	zAxis = { 0, 0, z };
}

void Matrix3::setScaled(const vector3& vec) {
	// set scale of each axis
	xAxis = { vec.x, 0, 0 };
	yAxis = { 0, vec.y, 0 };
	zAxis = { 0, 0, vec.z };
}

void Matrix3::scale(float x, float y, float z) {
	Matrix3 temp;
	temp.setScaled(x, y, z);
	*this = *this * temp;
}

void Matrix3::scale(const vector3& vec) {
	Matrix3 temp;
	temp.setScaled(vec.x, vec.y, vec.z);
	*this = *this * temp;
	
}

void Matrix3::setEuler(float pitch, float yaw, float roll) {
	Matrix3 x, y, z;
	x.setRotateX(pitch);
	y.setRotateY(yaw);
	z.setRotateZ(roll);
	// combine rotations in a specific order
	*this = z * y * x;
}


///////////Matrix4/////////////

const Matrix4 identity = Matrix4(1.0f, 0.0f, 0.0f, 0.0f,
								 0.0f, 1.f, 0.0f, 0.0f,
								 0.0f, 0.0f, 1.f, 0.0f,
								 0.0f, 0.0f, 0.0f, 1.f);

Matrix4::Matrix4()
{
	for (int col = 0; col < 4; ++col)
	{
		for (int row = 0; row < 4; ++row)
		{
			data[col][row] = 0;
		}
	}
}
Matrix4::Matrix4(float x1, float y1, float z1, float w1, float x2, float y2, float z2, float w2, float x3, float y3, float z3, float w3, float x4, float y4, float z4, float w4)
{
	data[0][0] = x1;
	data[1][0] = y1;
	data[2][0] = z1;
	data[3][0] = w1;
	data[0][1] = x2;
	data[1][1] = y2;
	data[2][1] = z2;
	data[3][1] = w2;
	data[0][2] = x3;
	data[1][2] = y3;
	data[2][2] = z3;
	data[3][2] = w3;
	data[0][3] = x4;
	data[1][3] = y4;
	data[2][3] = z4;
	data[3][3] = w4;
}
Matrix4::Matrix4(vector4 X, vector4 Y, vector4 Z, vector4 W) : xAxis(X), yAxis(Y), zAxis(Z), translation(W)
{

}
Matrix4::~Matrix4()
{

}



const vector4& Matrix4::operator[] (int index) const
{
	return axis[index];
}

vector4 Matrix4::operator* (const vector4& vec) const
{
	vector4 result;
	result.data[0] = data[0][0] * vec.data[0] + data[1][0] * vec.data[1] +
		data[2][0] * vec.data[2] + data[3][0] * vec.data[3];

	result.data[1] = data[0][1] * vec.data[0] + data[1][1] * vec.data[1] +
		data[2][1] * vec.data[2] + data[3][1] * vec.data[3];

	result.data[2] = data[0][2] * vec.data[0] + data[1][2] * vec.data[1] +
		data[2][2] * vec.data[2] + data[3][2] * vec.data[3];

	result.data[3] = data[0][3] * vec.data[0] + data[1][3] * vec.data[1] +
		data[2][3] * vec.data[2] + data[3][3] * vec.data[3];
	return result;
}

Matrix4 Matrix4::operator* (const Matrix4& other) const
{
	Matrix4 result;
	for (int r = 0; r < 4; ++r) {
		for (int c = 0; c < 4; ++c) {
			result.data[c][r] = data[0][r] * other.data[c][0] +
				data[1][r] * other.data[c][1] +
				data[2][r] * other.data[c][2] +
				data[3][r] * other.data[c][3];
		}
	}
	return result;
}


Matrix4 Matrix4::transposed() const
{
	Matrix4 result;
	// flip row and column
	for (int row = 0; row < 4; ++row)
		for (int col = 0; col < 4; ++col)
			result.data[row][col] = data[col][row];
	return result;
}


Matrix4::operator float*()
{
	return &data[0][0] ;
}



void Matrix4::setRotateX(float radians)
{
	// leave X axis and elements unchanged
	xAxis = { 1, 0, 0, 0 };
	yAxis = { 0, cosf(radians), sinf(radians), 0 };
	zAxis = { 0, -sinf(radians), cosf(radians), 0 };
	translation = { 0, 0, 0, 1 };
}
void Matrix4::rotateX(float radians)
{
	Matrix4 temp;
	temp.setRotateX(radians);
	*this = *this * temp;
}

void Matrix4::setRotateY(float radians)
{
	xAxis = { cosf(radians), 0, -sinf(radians),0 };
	yAxis = { 0, 1, 0 ,0};
	zAxis = { sinf(radians), 0, cosf(radians),0 };
	translation = { 0, 0, 0, 1 };

}
void Matrix4::rotateY(float radians)
{
	Matrix4 temp;
	temp.setRotateY(radians);
	*this = *this * temp;
}

void Matrix4::setRotateZ(float radians)
{
	xAxis = { cosf(radians), sinf(radians), 0 ,0};
	yAxis = { -sinf(radians), cosf(radians), 0 ,0};
	zAxis = { 0, 0 , 1 ,0};
	translation = { 0, 0, 0, 1 };
}
void Matrix4::rotateZ(float radians)
{
	Matrix4 temp;
	temp.setRotateZ(radians);
	*this = *this * temp;
}

void Matrix4::setScaled(float x, float y, float z)
{
	// set scale of each axis
	xAxis = { x, 0, 0, 0 };
	yAxis = { 0, y, 0, 0 };
	zAxis = { 0, 0, z, 0 };
	translation = { 0, 0, 0, 1 };
}
void Matrix4::setScaled(const vector4& vec)
{
	// set scale of each axis
	xAxis = { vec.x, 0, 0, 0 };
	yAxis = { 0, vec.y, 0, 0 };
	zAxis = { 0, 0, vec.z, 0 };
	translation = { 0, 0, 0, 1 };
}

void Matrix4::scale(float x, float y, float z)
{
	Matrix4 temp;
	temp.setScaled(x, y, z);
	*this = *this * temp;

}
void Matrix4::scale(const vector4& vec)//overload to take a vector
{
	Matrix4 temp;
	temp.setScaled(vec.x, vec.y, vec.z);
	*this = *this * temp;
}

void Matrix4::setEuler(float pitch, float yaw, float roll)
{
	Matrix4 x, y, z;
	x.setRotateX(pitch);
	y.setRotateY(yaw);
	z.setRotateZ(roll);
	// combine rotations in a specific order
	*this = z * y * x;
}

void Matrix4::translate(float x, float y, float z) {
	// apply vector offset
	translation += vector4(x, y, z, 0);
}