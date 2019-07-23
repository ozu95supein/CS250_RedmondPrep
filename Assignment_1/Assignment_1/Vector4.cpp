/*!*************************************************************
* \file Vector4.cpp
* \par cs250
* \author Oscar Sanchez Bayton Griffith
* \date  
* \brief Function implementation of the Vector4 class
***************************************************************/
#include "Vector4.h"
#include <cmath>
#include "MathUtilities.h"

// Default constructor, initializes x,y,z to zeroes, w to defined value
/*!************************************************************
\brief
Default constructor, sets x,y,z to zero and w to the defined
value

\param

\return

**************************************************************/
Vector4::Vector4(void)
{
	for (int i = 0; i < 4; i++)
	{
		v[i] = 0.0f;
	}
}
// Copy constructor, copies every component from the other Vector4
/*!************************************************************
\brief
Copy constructor, copies every component from the other Point4

\param const Vector4& rhs

\return

**************************************************************/
Vector4::Vector4(const Vector4& rhs)
{
	for (int i = 0; i < 4; i++)
	{
		v[i] = rhs.v[i];
	}
}
// Non-Default constructor, self explanatory
/*!************************************************************
\brief
Non-Default constructor, self-explanatory
value

\param

\return

**************************************************************/
Vector4::Vector4(f32 xx, f32 yy, f32 zz, f32 ww)
{
	v[0] = xx;
	v[1] = yy;
	v[2] = zz;
	v[3] = ww;
}
/*!************************************************************
\brief
Assignment operator, copies every component from the other
Point4

\param const Vector4& rhs

\return Vector4&

**************************************************************/
Vector4& Vector4::operator=(const Vector4& rhs)
{
	for (int i = 0; i < 4; i++)
	{
		v[i] = (f32)(rhs.v[i]);
	}
	return (*this);
}
/*!************************************************************
\brief
Unary negation operator, negates every component and returns a 
copy

\param

\return Vector4

**************************************************************/
Vector4 Vector4::operator-(void) const
{
	Vector4 neg;
	neg.v[0] = (f32)(-(this->v[0]));
	neg.v[1] = (f32)(-(this->v[1]));
	neg.v[2] = (f32)(-(this->v[2]));
	neg.v[3] = (f32)(-(this->v[3]));
	return neg;
}

/*!************************************************************
\brief
Addition operator

\param const Vector4& rhs

\return Vector4

**************************************************************/
Vector4 Vector4::operator+(const Vector4& rhs) const
{
	Vector4 result;
	for (int i = 0; i < 4; i++)
	{
		result.v[i] = (f32)this->v[i] + (f32)rhs.v[i];
	}
	return result;
}
/*!************************************************************
\brief
Binary subtraction operator, Subtract two Point4s and you get
a Vector4

\param const Vector4& rhs

\return Vector4

**************************************************************/
Vector4 Vector4::operator-(const Vector4& rhs) const
{
	Vector4 result;
	for (int i = 0; i < 4; i++)
	{
		result.v[i] = (f32)this->v[i] - (f32)rhs.v[i];
	}
	return result;
}
/*!************************************************************
\brief
Default constructor, sets x,y,z to zero and w to the defined
value

\param

\return

**************************************************************/
Vector4 Vector4::operator*(const f32 rhs) const
{
	Vector4 result;
	for (int i = 0; i < 4; i++)
	{
		result.v[i] = (f32)this->v[i] * (f32)rhs;
	}
	return result;
}
/*!************************************************************
\brief
Default constructor, sets x,y,z to zero and w to the defined
value

\param

\return

**************************************************************/
Vector4 Vector4::operator/(const f32 rhs) const
{
	Vector4 result;
	for (int i = 0; i < 4; i++)
	{
		result.v[i] = (f32)this->v[i] / (f32)rhs;
	}
	return result;
}
// Same as above, just stores the result in the original vector
/*!************************************************************
\brief
Default constructor, sets x,y,z to zero and w to the defined
value

\param

\return

**************************************************************/
Vector4& Vector4::operator+=(const Vector4& rhs)
{
	v[0] += rhs.v[0];
	if (isZero(v[0]))
	{
		v[0] = 0.0f;
	}
	v[1] += rhs.v[1];
	if (isZero(v[1]))
	{
		v[1] = 0.0f;
	}
	v[2] += rhs.v[2];
	if (isZero(v[2]))
	{
		v[2] = 0.0f;
	}
	v[3] += rhs.v[3];
	if (isZero(v[3]))
	{
		v[3] = 0.0f;
	}
	return (*this);
}
/*!************************************************************
\brief
Default constructor, sets x,y,z to zero and w to the defined
value

\param

\return

**************************************************************/
Vector4& Vector4::operator-=(const Vector4& rhs)
{
	v[0] -= rhs.v[0];
	if (isZero(v[0]))
	{
		v[0] = 0.0f;
	}
	v[1] -= rhs.v[1];
	if (isZero(v[1]))
	{
		v[1] = 0.0f;
	}
	v[2] -= rhs.v[2];
	if (isZero(v[2]))
	{
		v[2] = 0.0f;
	}
	v[3] -= rhs.v[3];
	if (isZero(v[3]))
	{
		v[3] = 0.0f;
	}
	return (*this);
}
/*!************************************************************
\brief
Default constructor, sets x,y,z to zero and w to the defined
value

\param

\return

**************************************************************/
Vector4& Vector4::operator*=(const f32 rhs)
{
	v[0] *= rhs;
	if (isZero(v[0]))
	{
		v[0] = 0.0f;
	}
	v[1] *= rhs;
	if (isZero(v[1]))
	{
		v[1] = 0.0f;
	}
	v[2] *= rhs;
	if (isZero(v[2]))
	{
		v[2] = 0.0f;
	}
	v[3] *= rhs;
	if (isZero(v[3]))
	{
		v[3] = 0.0f;
	}
	return (*this);
}
/*!************************************************************
\brief
Default constructor, sets x,y,z to zero and w to the defined
value

\param

\return

**************************************************************/
Vector4& Vector4::operator/=(const f32 rhs)
{
	v[0] /= rhs;
	if (isZero(v[0]))
	{
		v[0] = 0.0f;
	}
	v[1] /= rhs;
	if (isZero(v[1]))
	{
		v[1] = 0.0f;
	}
	v[2] /= rhs;
	if (isZero(v[2]))
	{
		v[2] = 0.0f;
	}
	v[3] /= rhs;
	if (isZero(v[3]))
	{
		v[3] = 0.0f;
	}
	return (*this);
}
// Comparison operators which should use an epsilon defined in
// MathUtilities.h to see if the value is within a certain range
// in which case we say they are equivalent.
/*!************************************************************
\brief
Default constructor, sets x,y,z to zero and w to the defined
value

\param

\return

**************************************************************/
bool Vector4::operator==(const Vector4& rhs) const
{
	float temp;
	temp = v[0] - rhs.v[0];
	if (abs(temp) > EPSILON)
	{
		return false;
	}
	temp = v[1] - rhs.v[1];
	if (abs(temp) > EPSILON)
	{
		return false;
	}
	temp = v[2] - rhs.v[2];
	if (abs(temp) > EPSILON)
	{
		return false;
	}
	temp = v[2] - rhs.v[2];
	if (abs(temp) > EPSILON)
	{
		return false;
	}
	return true;
}
/*!************************************************************
\brief
Default constructor, sets x,y,z to zero and w to the defined
value

\param

\return

**************************************************************/
bool Vector4::operator!=(const Vector4& rhs) const
{
	float temp;
	temp = v[0] - rhs.v[0];
	if (abs(temp) > EPSILON)
	{
		return true;
	}
	temp = v[1] - rhs.v[1];
	if (abs(temp) > EPSILON)
	{
		return true;
	}
	temp = v[2] - rhs.v[2];
	if (abs(temp) > EPSILON)
	{
		return true;
	}
	temp = v[2] - rhs.v[2];
	if (abs(temp) > EPSILON)
	{
		return true;
	}
	return false;
}

// Computes the dot product with the other vector. Treat it as 3D vector.
/*!************************************************************
\brief
Default constructor, sets x,y,z to zero and w to the defined
value

\param

\return

**************************************************************/
f32 Vector4::Dot(const Vector4& rhs) const
{
	f32 result;
	result = (v[0] * rhs.v[0]) + (v[1] * rhs.v[1]) + (v[2] * rhs.v[2]);
	return result;
}
// Computes the cross product with the other vector. Treat it as a 3D vector.
/*!************************************************************
\brief
Default constructor, sets x,y,z to zero and w to the defined
value

\param

\return

**************************************************************/
Vector4 Vector4::Cross(const Vector4& rhs) const
{
	f32 a, b, c;
	a = b = c = 0.0;
	//i
	a = (this->v[1] * rhs.v[2]) - (this->v[2] * rhs.v[1]);
	b = -((this->v[0] * rhs.v[2]) - (this->v[2] * rhs.v[0]));
	c = (this->v[0] * rhs.v[1]) - (this->v[1] * rhs.v[0]);
	//IS w value 0, 1, or something else?
	return Vector4(a, b, c, 0);
}
// Computes the true length of the vector
/*!************************************************************
\brief
Default constructor, sets x,y,z to zero and w to the defined
value

\param

\return

**************************************************************/
f32 Vector4::Length(void) const
{
	f32 result = this->LengthSq();
	result = sqrt(result);
	return result;
}
// Computes the squared length of the vector
/*!************************************************************
\brief
Default constructor, sets x,y,z to zero and w to the defined
value

\param

\return

**************************************************************/
f32 Vector4::LengthSq(void) const
{
	f32 result = (v[0] * v[0]) + (v[1] * v[1]) + (v[2] * v[2]) + (v[3] * v[3]);
	return result;
}
// Normalizes the vector to make the final vector be of length 1. If the length is zero
// then this function should not modify anything.
/*!************************************************************
\brief
Default constructor, sets x,y,z to zero and w to the defined
value

\param

\return

**************************************************************/
void Vector4::Normalize(void)
{
	f32 l = this->Length();
	if (l)
	{
		v[0] = v[0] / l;
		v[1] = v[1] / l;
		v[2] = v[2] / l;
		v[3] = v[3] / l;
	}
}
// Sets x,y,z to zeroes, w to defined value
/*!************************************************************
\brief
Default constructor, sets x,y,z to zero and w to the defined
value

\param

\return

**************************************************************/
void Vector4::Zero(void)
{
	v[0] = 0.0f;
	v[1] = 0.0f;
	v[2] = 0.0f;
	v[3] = 0.0f;
}