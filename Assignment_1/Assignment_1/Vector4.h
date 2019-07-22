#ifndef VECTOR4_H
#define VECTOR4_H

#include <stdio.h>              // printf
#include "Types.h"

class Vector4
{
    public:

        // It stores the coordinates
        f32 v[4];

        // Default constructor, initializes x,y,z to zeroes, w to defined value
        Vector4(void);
        // Copy constructor, copies every component from the other Vector4
        Vector4(const Vector4& rhs);
        // Non-Default constructor, self explanatory
        Vector4(f32 xx, f32 yy, f32 zz, f32 ww = 0.0f);
        // Assignment operator, does not need to handle self assignment
        Vector4& operator=(const Vector4& rhs);
        // Unary negation operator, negates all components and returns a copy
        Vector4 operator-(void) const;

        // Basic Vector math operations. Add Vector to Vector B, or Subtract Vector A from
        // Vector B, or multiply a vector with a scalar, or divide a vector by that scalar
        Vector4 operator+(const Vector4& rhs) const;
        Vector4 operator-(const Vector4& rhs) const;
        Vector4 operator*(const f32 rhs) const;
        Vector4 operator/(const f32 rhs) const;
        // Same as above, just stores the result in the original vector
        Vector4& operator+=(const Vector4& rhs);
        Vector4& operator-=(const Vector4& rhs);
        Vector4& operator*=(const f32 rhs);
        Vector4& operator/=(const f32 rhs);
        // Comparison operators which should use an epsilon defined in
        // MathUtilities.h to see if the value is within a certain range
        // in which case we say they are equivalent.
        bool operator==(const Vector4& rhs) const;
        bool operator!=(const Vector4& rhs) const;

        // Computes the dot product with the other vector. Treat it as 3D vector.
        f32 Dot(const Vector4& rhs) const;
        // Computes the cross product with the other vector. Treat it as a 3D vector.
        Vector4 Cross(const Vector4& rhs) const;
        // Computes the true length of the vector
        f32 Length(void) const;
        // Computes the squared length of the vector
        f32 LengthSq(void) const;
        // Normalizes the vector to make the final vector be of length 1. If the length is zero
        // then this function should not modify anything.
        void Normalize(void);
        // Sets x,y,z to zeroes, w to defined value
        void Zero(void);
        // Already implemented, simple print function
        void Print(void) const
        {
            printf("%5.3f, %5.3f, %5.3f, %5.3f\n", v[0], v[1], v[2], v[3]);
        }
};

#endif