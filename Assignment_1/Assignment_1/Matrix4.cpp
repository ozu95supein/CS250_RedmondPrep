/*!*************************************************************
* \file Matrix4.cpp
* \par cs250
* \author Oscar Sanchez Bayton Griffith
* \date  1/23/2019
* \brief Function implementation of the Matrix4 class
***************************************************************/
#include "Matrix4.h"
#include <cmath>
#include "MathUtilities.h"
// Default constructor should initialize to zeroes
/*!************************************************************
\brief
Default constructor, sets x,y,z to zero and w to the defined
value

\param

\return

**************************************************************/
Matrix4::Matrix4(void)
{
	for (int i = 0; i < 16; i++)
	{
		v[i] = 0.0f;
	}
}

// 
/*!************************************************************
\brief
Copy constructor, copies every entry from the other matrix.

\param

\return

**************************************************************/
Matrix4::Matrix4(const Matrix4& rhs)
{
	for (int i = 0; i < 16; i++)
	{
		v[i] = rhs.v[i];
	}
}

/*!************************************************************
\brief
Non-Default constructor, self-explanatory
value

\param

\return

**************************************************************/
Matrix4::Matrix4(f32 mm00, f32 mm01, f32 mm02, f32 mm03,
	f32 mm10, f32 mm11, f32 mm12, f32 mm13,
	f32 mm20, f32 mm21, f32 mm22, f32 mm23,
	f32 mm30, f32 mm31, f32 mm32, f32 mm33)
{
	v[0] = mm00;
	v[1] = mm01;
	v[2] = mm02;
	v[3] = mm03;
	v[4] = mm10;
	v[5] = mm11;
	v[6] = mm12;
	v[7] = mm13;
	v[8] = mm20;
	v[9] = mm21;
	v[10] = mm22;
	v[11] = mm23;
	v[12] = mm30;
	v[13] = mm31;
	v[14] = mm32;
	v[15] = mm33;
}

/*!************************************************************
\brief
Assignment operator, copies every component from the other
Matrix4

\param const Matrix4& rhs

\return Matrix4&

**************************************************************/
Matrix4& Matrix4::operator=(const Matrix4& rhs)
{
	for (int i = 0; i < 16; i++)
	{
		this->v[i] = rhs.v[i];
	}
	return *(this);
}

// Multiplying a Matrix4 with a Vector4 or a Point4
/*!************************************************************
\brief
Default constructor, sets x,y,z to zero and w to the defined
value

\param

\return

**************************************************************/
Vector4 Matrix4::operator*(const Vector4& rhs) const
{
	Vector4 result;
	result.v[0] = 0.0f;
	int i;
	for (i = 0; i < 4; i++)
	{
		result.v[0] += (v[i] * rhs.v[i]);
	}
	for (i = 0; i < 4; i++)
	{
		result.v[1] += (v[i + 4] * rhs.v[i]);
	}
	for (i = 0; i < 4; i++)
	{
		result.v[2] += (v[i + 8] * rhs.v[i]);
	}
	for (i = 0; i < 4; i++)
	{
		result.v[3] += (v[i + 12] * rhs.v[i]);
	}
	return result;
}
/*!************************************************************
\brief
Matrix times point4
value

\param const Point4& rhs

\return Point4

**************************************************************/
Point4 Matrix4::operator*(const Point4& rhs) const
{
	Point4 result(0.0f, 0.0f, 0.0f, 0.0f);
	result.v[0] = 0.0f;
	int i;
	for (i = 0; i < 4; i++)
	{
		result.v[0] += (v[i] * rhs.v[i]);
	}
	for (i = 0; i < 4; i++)
	{
		result.v[1] += (v[i + 4] * rhs.v[i]);
	}
	for (i = 0; i < 4; i++)
	{
		result.v[2] += (v[i + 8] * rhs.v[i]);
	}
	for (i = 0; i < 4; i++)
	{
		result.v[3] += (v[i + 12] * rhs.v[i]);
	}
	return result;
}

// Basic Matrix arithmetic operations
/*!************************************************************
\brief
Adds two matrices, does not self assign

\param const Matrix4& rhs

\return Matrix4

**************************************************************/
Matrix4 Matrix4::operator+(const Matrix4& rhs) const
{
	Matrix4 result;
	for (int i = 0; i < 16; i++)
	{
		result.v[i] = this->v[i] + rhs.v[i];
	}
	return result;
}
/*!************************************************************
\brief
subtract matrices

\param const Matrix4& rhs

\return Matrix4

**************************************************************/
Matrix4 Matrix4::operator-(const Matrix4& rhs) const
{
	Matrix4 result;
	for (int i = 0; i < 16; i++)
	{
		result.v[i] = this->v[i] - rhs.v[i];
	}
	return result;
}
/*!************************************************************
\brief
Matrix multiplication

\param const Matrix4& rhs

\return Matrix4

**************************************************************/
Matrix4 Matrix4::operator*(const Matrix4& rhs) const
{
	Matrix4 result;
	result.v[0] = result.v[1] = result.v[2] = result.v[3] = result.v[4] = result.v[5] = result.v[6] = result.v[7] = result.v[8] = result.v[8] = result.v[10] = result.v[11] = result.v[12] = result.v[13] = result.v[14] = result.v[15] = 0.0f;

	result.v[0] = (this->v[0] * rhs.v[0]) + (this->v[1] * rhs.v[4]) + (this->v[2] * rhs.v[8]) + (this->v[3] * rhs.v[12]);
	result.v[1] = (this->v[0] * rhs.v[1]) + (this->v[1] * rhs.v[5]) + (this->v[2] * rhs.v[9]) + (this->v[3] * rhs.v[13]);
	result.v[2] = (this->v[0] * rhs.v[2]) + (this->v[1] * rhs.v[6]) + (this->v[2] * rhs.v[10]) + (this->v[3] * rhs.v[14]);
	result.v[3] = (this->v[0] * rhs.v[3]) + (this->v[1] * rhs.v[7]) + (this->v[2] * rhs.v[11]) + (this->v[3] * rhs.v[15]);

	result.v[4] = (this->v[4] * rhs.v[0]) + (this->v[5] * rhs.v[4]) + (this->v[6] * rhs.v[8]) + (this->v[7] * rhs.v[12]);
	result.v[5] = (this->v[4] * rhs.v[1]) + (this->v[5] * rhs.v[5]) + (this->v[6] * rhs.v[9]) + (this->v[7] * rhs.v[13]);
	result.v[6] = (this->v[4] * rhs.v[2]) + (this->v[5] * rhs.v[6]) + (this->v[6] * rhs.v[10]) + (this->v[7] * rhs.v[14]);
	result.v[7] = (this->v[4] * rhs.v[3]) + (this->v[5] * rhs.v[7]) + (this->v[6] * rhs.v[11]) + (this->v[7] * rhs.v[15]);

	result.v[8] = (this->v[8] * rhs.v[0]) + (this->v[9] * rhs.v[4]) + (this->v[10] * rhs.v[8]) + (this->v[11] * rhs.v[12]);
	result.v[9] = (this->v[8] * rhs.v[1]) + (this->v[9] * rhs.v[5]) + (this->v[10] * rhs.v[9]) + (this->v[11] * rhs.v[13]);
	result.v[10] = (this->v[8] * rhs.v[2]) + (this->v[9] * rhs.v[6]) + (this->v[10] * rhs.v[10]) + (this->v[11] * rhs.v[14]);
	result.v[11] = (this->v[8] * rhs.v[3]) + (this->v[9] * rhs.v[7]) + (this->v[10] * rhs.v[11]) + (this->v[11] * rhs.v[15]);

	result.v[12] = (this->v[12] * rhs.v[0]) + (this->v[13] * rhs.v[4]) + (this->v[14] * rhs.v[8]) + (this->v[15] * rhs.v[12]);
	result.v[13] = (this->v[12] * rhs.v[1]) + (this->v[13] * rhs.v[5]) + (this->v[14] * rhs.v[9]) + (this->v[15] * rhs.v[13]);
	result.v[14] = (this->v[12] * rhs.v[2]) + (this->v[13] * rhs.v[6]) + (this->v[14] * rhs.v[10]) + (this->v[15] * rhs.v[14]);
	result.v[15] = (this->v[12] * rhs.v[3]) + (this->v[13] * rhs.v[7]) + (this->v[14] * rhs.v[11]) + (this->v[15] * rhs.v[15]);

	return result;
}

/*!************************************************************
\brief
Similar to the three above except they modify the original


\param const Matrix4& rhs

\return Matrix4&

**************************************************************/
Matrix4& Matrix4::operator+=(const Matrix4& rhs)
{
	for (int i = 0; i < 16; i++)
	{
		this->v[i] = this->v[i] + rhs.v[i];
	}
	return *(this);
}
/*!************************************************************
\brief
subtract and self assign

\param const Matrix4& rhs

\return Matrix4&

**************************************************************/
Matrix4& Matrix4::operator-=(const Matrix4& rhs)
{
	for (int i = 0; i < 16; i++)
	{
		this->v[i] = this->v[i] - rhs.v[i];
	}
	return *(this);
}
/*!************************************************************
\brief
matrix multiplication and no self assignment

\param const Matrix4& rhs

\return Matrix4&

**************************************************************/
Matrix4& Matrix4::operator*=(const Matrix4& rhs)
{
	//note, I took part of this code off the internet because I was trying and it didn't work
	Matrix4 A = *(this);
	Matrix4 B = rhs;
	Matrix4 C;
	for (int j = 0; j < 4; j++)
	{
		for (int i = 0; i < 4; i++)
		{
			C.v[i + j * 4] = A.v[j * 4] * B.v[i] + A.v[j * 4 + 1] * B.v[i + 4] + A.v[j * 4 + 2] * B.v[i + 8] + A.v[j * 4 + 3] * B.v[i + 12];
		}
	}
	*(this) = C;
	return C;
}

//
/*!************************************************************
\brief
Scale/Divide the entire matrix by a float

\param const f32 rhs

\return Matrix4

**************************************************************/
Matrix4 Matrix4::operator*(const f32 rhs) const
{
	Matrix4 result;
	for (int i = 0; i < 16; i++)
	{
		result.v[i] = v[i] * rhs;
	}
	return result;
}
/*!************************************************************
\brief
Scale/Divide the entire matrix by a float

\param const f32 rhs

\return Matrix4

**************************************************************/
Matrix4 Matrix4::operator/(const f32 rhs) const
{
	Matrix4 result;
	for (int i = 0; i < 16; i++)
	{
		result.v[i] = v[i] / rhs;
	}
	return result;
}
/*!************************************************************
\brief
matrix multiplication and self assignment

\param const Matrix4& rhs

\return Matrix4&

**************************************************************/
Matrix4& Matrix4::operator*=(const f32 rhs)
{
	this->v[0] = this->v[0] * rhs;
	this->v[1] = this->v[1] * rhs;
	this->v[2] = this->v[2] * rhs;
	this->v[3] = this->v[3] * rhs;
	this->v[4] = this->v[4] * rhs;
	this->v[5] = this->v[5] * rhs;
	this->v[6] = this->v[6] * rhs;
	this->v[7] = this->v[7] * rhs;
	this->v[8] = this->v[8] * rhs;
	this->v[9] = this->v[9] * rhs;
	this->v[10] = this->v[10] * rhs;
	this->v[11] = this->v[11] * rhs;
	this->v[12] = this->v[12] * rhs;
	this->v[13] = this->v[13] * rhs;
	this->v[14] = this->v[14] * rhs;
	this->v[15] = this->v[15] * rhs;

	return *(this);
}
/*!************************************************************
\brief
Division and self assign

\param const f32 rhs

\return Matrix4&

**************************************************************/
Matrix4& Matrix4::operator/=(const f32 rhs)
{
	this->v[0] = this->v[0] / rhs;
	this->v[1] = this->v[1] / rhs;
	this->v[2] = this->v[2] / rhs;
	this->v[3] = this->v[3] / rhs;
	this->v[4] = this->v[4] / rhs;
	this->v[5] = this->v[5] / rhs;
	this->v[6] = this->v[6] / rhs;
	this->v[7] = this->v[7] / rhs;
	this->v[8] = this->v[8] / rhs;
	this->v[9] = this->v[9] / rhs;
	this->v[10] = this->v[10] / rhs;
	this->v[11] = this->v[11] / rhs;
	this->v[12] = this->v[12] / rhs;
	this->v[13] = this->v[13] / rhs;
	this->v[14] = this->v[14] / rhs;
	this->v[15] = this->v[15] / rhs;

	return *(this);
}

// 
// 
// 
/*!************************************************************
\brief
Comparison operators which should use an epsilon defined in
MathUtilities.h to see if the value is within a certain range
in which case we say they are equivalent.

\param const Matrix4& rhs

\return bool

**************************************************************/
bool Matrix4::operator==(const Matrix4& rhs) const
{
	f32 temp;
	temp = abs(this->v[0] - rhs.v[0]);
	if (temp > EPSILON)
	{
		return false;
	}
	temp = abs(this->v[1] - rhs.v[1]);
	if (temp > EPSILON)
	{
		return false;
	}
	temp = abs(this->v[2] - rhs.v[2]);
	if (temp > EPSILON)
	{
		return false;
	}
	temp = abs(this->v[3] - rhs.v[3]);
	if (temp > EPSILON)
	{
		return false;
	}
	temp = abs(this->v[4] - rhs.v[4]);
	if (temp > EPSILON)
	{
		return false;
	}
	temp = abs(this->v[5] - rhs.v[5]);
	if (temp > EPSILON)
	{
		return false;
	}
	temp = abs(this->v[6] - rhs.v[6]);
	if (temp > EPSILON)
	{
		return false;
	}
	temp = abs(this->v[7] - rhs.v[7]);
	if (temp > EPSILON)
	{
		return false;
	}
	temp = abs(this->v[8] - rhs.v[8]);
	if (temp > EPSILON)
	{
		return false;
	}
	temp = abs(this->v[9] - rhs.v[9]);
	if (temp > EPSILON)
	{
		return false;
	}
	temp = abs(this->v[10] - rhs.v[10]);
	if (temp > EPSILON)
	{
		return false;
	}
	temp = abs(this->v[11] - rhs.v[11]);
	if (temp > EPSILON)
	{
		return false;
	}
	temp = abs(this->v[12] - rhs.v[12]);
	if (temp > EPSILON)
	{
		return false;
	}
	temp = abs(this->v[13] - rhs.v[13]);
	if (temp > EPSILON)
	{
		return false;
	}
	temp = abs(this->v[14] - rhs.v[14]);
	if (temp > EPSILON)
	{
		return false;
	}
	temp = abs(this->v[15] - rhs.v[15]);
	if (temp > EPSILON)
	{
		return false;
	}
	return true;
}
/*!************************************************************
\brief
comparison operator

\param const Matrix4& rhs

\return bool

**************************************************************/
bool Matrix4::operator!=(const Matrix4& rhs) const
{
	f32 temp;
	temp = abs(this->v[0] - rhs.v[0]);
	if (temp > EPSILON)
	{
		return true;
	}
	temp = abs(this->v[1] - rhs.v[1]);
	if (temp > EPSILON)
	{
		return true;
	}
	temp = abs(this->v[2] - rhs.v[2]);
	if (temp > EPSILON)
	{
		return true;
	}
	temp = abs(this->v[3] - rhs.v[3]);
	if (temp > EPSILON)
	{
		return true;
	}
	temp = abs(this->v[4] - rhs.v[4]);
	if (temp > EPSILON)
	{
		return true;
	}
	temp = abs(this->v[5] - rhs.v[5]);
	if (temp > EPSILON)
	{
		return true;
	}
	temp = abs(this->v[6] - rhs.v[6]);
	if (temp > EPSILON)
	{
		return true;
	}
	temp = abs(this->v[7] - rhs.v[7]);
	if (temp > EPSILON)
	{
		return true;
	}
	temp = abs(this->v[8] - rhs.v[8]);
	if (temp > EPSILON)
	{
		return true;
	}
	temp = abs(this->v[9] - rhs.v[9]);
	if (temp > EPSILON)
	{
		return true;
	}
	temp = abs(this->v[10] - rhs.v[10]);
	if (temp > EPSILON)
	{
		return true;
	}
	temp = abs(this->v[11] - rhs.v[11]);
	if (temp > EPSILON)
	{
		return true;
	}
	temp = abs(this->v[12] - rhs.v[12]);
	if (temp > EPSILON)
	{
		return true;
	}
	temp = abs(this->v[13] - rhs.v[13]);
	if (temp > EPSILON)
	{
		return true;
	}
	temp = abs(this->v[14] - rhs.v[14]);
	if (temp > EPSILON)
	{
		return true;
	}
	temp = abs(this->v[15] - rhs.v[15]);
	if (temp > EPSILON)
	{
		return true;
	}
	return false;
}

// 
/*!************************************************************
\brief
Zeroes out the entire matrix

\param

\return

**************************************************************/
void Matrix4::Zero(void)
{
	for (int i = 0; i < 16; i++)
	{
		this->v[i] = 0.0f;
	}
}

// Builds the identity matrix
/*!************************************************************
\brief
turns this matrix into the identity matrix

\param

\return

**************************************************************/
void Matrix4::Identity(void)
{
	this->Zero();
	v[0] = 1.0f;
	v[5] = 1.0f;
	v[10] = 1.0f;
	v[15] = 1.0f;
}