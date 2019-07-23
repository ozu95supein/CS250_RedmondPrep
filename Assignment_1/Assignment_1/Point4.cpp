/*!*************************************************************
* \file Point4.cpp
* \par cs250
* \author Oscar Sanchez Bayton Griffith
* \date  1/23/2019
* \brief Function implementation of the Point4 class
***************************************************************/
#include "Point4.h"
#include <cmath>
#include "MathUtilities.h"

/*!************************************************************
\brief
Default constructor, sets x,y,z to zero and w to the defined 
value

\param 

\return

**************************************************************/
Point4::Point4(void)
{
	v[0] = 0.0f;
	v[1] = 0.0f;
	v[2] = 0.0f;
	v[3] = 1.0f;
}
// 
/*!************************************************************
\brief
Copy constructor, copies every component from the other Point4

\param

\return

**************************************************************/
Point4::Point4(const Point4& rhs)
{
	v[0] = rhs.v[0];
	v[1] = rhs.v[1];
	v[2] = rhs.v[2];
	v[3] = rhs.v[3];
}
// 
/*!************************************************************
\brief
Non-Default constructor, self-explanatory
value

\param

\return

**************************************************************/
Point4::Point4(f32 xx, f32 yy, f32 zz, f32 ww)
{
	v[0] = xx;
	v[1] = yy;
	v[2] = zz;
	v[3] = ww;
}

// 
/*!************************************************************
\brief
Assignment operator, copies every component from the other
Point4

\param const Point4& rhs

\return Point4&

**************************************************************/
Point4& Point4::operator=(const Point4& rhs)
{
	v[0] = rhs.v[0];
	v[1] = rhs.v[1];
	v[2] = rhs.v[2];
	v[3] = rhs.v[3];
	return *(this);
}
// 
/*!************************************************************
\brief
Unary negation operator, negates every component and returns a copy

\param

\return Point4

**************************************************************/
Point4 Point4::operator-(void) const
{
	Point4 newP = *(this);
	newP.v[0] = -newP.v[0];
	newP.v[1] = -newP.v[1];
	newP.v[2] = -newP.v[2];
	newP.v[3] = -newP.v[3];
	return newP;
}
// 
/*!************************************************************
\brief
Binary subtraction operator, Subtract two Point4s and you get
a Vector4

\param const Point4& rhs

\return Vector4

**************************************************************/
Vector4 Point4::operator-(const Point4& rhs) const
{
	Vector4 p;
	p.v[0] = this->v[0] - rhs.v[0];
	p.v[1] = this->v[1] - rhs.v[1];
	p.v[2] = this->v[2] - rhs.v[2];
	p.v[3] = this->v[3] - rhs.v[3];
	return p;
}
// 
/*!************************************************************
\brief
Basic vector math operations with points, you can add a Vector4 
to a Point4, or subtract a Vector4 from a Point4

\param const Vector4& rhs

\return Point4

**************************************************************/
Point4 Point4::operator+ (const Vector4& rhs) const
{
	Point4 result;
	result.v[0] = this->v[0] + rhs.v[0];
	result.v[1] = this->v[1] + rhs.v[1];
	result.v[2] = this->v[2] + rhs.v[2];
	result.v[3] = this->v[3] + rhs.v[3];
	return result;
}
/*!************************************************************
\brief
Basic vector math operations with points, you can add a Vector4
to a Point4, or subtract a Vector4 from a Point4

\param const Vector4& rhs

\return Point4

**************************************************************/
Point4 Point4::operator- (const Vector4& rhs) const
{
	Point4 result;
	result.v[0] = this->v[0] - rhs.v[0];
	result.v[1] = this->v[1] - rhs.v[1];
	result.v[2] = this->v[2] - rhs.v[2];
	result.v[3] = this->v[3] - rhs.v[3];
	return result;
}
// 
/*!************************************************************
\brief
Same as previous two operators, just modifies the original 
instead of returning a copy

\param const Vector4& rhs

\return Point4&

**************************************************************/
Point4& Point4::operator+=(const Vector4& rhs)
{
	this->v[0] = this->v[0] + rhs.v[0];
	this->v[1] = this->v[1] + rhs.v[1];
	this->v[2] = this->v[2] + rhs.v[2];
	this->v[3] = this->v[3] + rhs.v[3];
	return *(this);
}
/*!************************************************************
\brief
Same as previous two operators, just modifies the original
instead of returning a copy

\param const Vector4& rhs

\return Point4&

**************************************************************/
Point4& Point4::operator-=(const Vector4& rhs)
{
	this->v[0] = this->v[0] - rhs.v[0];
	this->v[1] = this->v[1] - rhs.v[1];
	this->v[2] = this->v[2] - rhs.v[2];
	this->v[3] = this->v[3] - rhs.v[3];
	return *(this);
}

/*!************************************************************
\brief
Comparison operators which should use an epsilon defined in
MathUtilities.h to see if the value is within a certain range
in which case we say they are equivalent.

\param const Point4& rhs

\return bool

**************************************************************/
bool Point4::operator==(const Point4& rhs) const
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
Comparison operators which should use an epsilon defined in
MathUtilities.h to see if the value is within a certain range
in which case we say they are equivalent.

\param const Point4& rhs

\return bool

**************************************************************/
bool Point4::operator!=(const Point4& rhs) const
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
/*!************************************************************
\brief
Sets x,y,z to zeroes, w to defined value

\param

\return

**************************************************************/
void Point4::Zero(void)
{
	this->v[0] = 0.0f;
	this->v[1] = 0.0f;
	this->v[2] = 0.0f;
	this->v[3] = 1.0f;
}