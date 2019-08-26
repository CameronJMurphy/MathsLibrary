#include "Matrix.h"


/////////////Matrix3////////////////////
Matrix3::Matrix3()
{
	vector3 X, Y, Z;//they will be 0,0,0
	Matrix3(X,Y,Z);
}
Matrix3::Matrix3(vector3 X, vector3 Y, vector3 Z) : xAxis(X), yAxis(Y), zAxis(Z)
{

}
Matrix3::~Matrix3()
{

}

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
Matrix3 Matrix3::operator* (const Matrix3* other) const
{
	Matrix3 result;
	for (int row = 0; row < 3; ++row) {
		for (int col = 0; col < 3; ++col) {
			result.data[col][row] = data[0][row] * other->data[col][0] +
									data[1][row] * other->data[col][1] +
									data[2][row] * other->data[col][2];
		}
	}
	return result;
}

Matrix3 Matrix3::operator* (Matrix3* other)
{
	Matrix3 result;
	for (int row = 0; row < 3; ++row) {
		for (int col = 0; col < 3; ++col) {
			result.data[col][row] = data[0][row] * other->data[col][0] +
				data[1][row] * other->data[col][1] +
				data[2][row] * other->data[col][2];
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
}void Matrix3::setScaled(const vector3& vec) {
	// set scale of each axis
	xAxis = { vec.x, 0, 0 };
	yAxis = { 0, vec.y, 0 };
	zAxis = { 0, 0, vec.z };
}void Matrix3::scale(float x, float y, float z) {
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