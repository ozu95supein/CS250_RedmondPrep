#include "MathUtilities.h"
#include "Matrix4.h"

// Default constructor should initialize to zeroes
Matrix4::Matrix4(void)
{
	for (int i = 0; i < 16; i++)
	{
		v[i] = 0.0f;
	}
}
// Copy constructor, copies every entry from the other matrix.
Matrix4::Matrix4(const Matrix4& rhs)
{
	for (int i = 0; i < 16; i++)
	{
		v[i] = rhs.v[i];
	}
}
// Non-default constructor, self-explanatory
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
