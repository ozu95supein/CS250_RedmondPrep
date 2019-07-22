#ifndef MATHUTILITIES_H
#define MATHUTILITIES_H

#include "stdlib.h"     // rand
#include "Types.h"      // f32

// Do not change
static const f32 EPSILON = 0.0001f;

// Macro definitions
#define isZero(x) ((x < EPSILON) && (x > -EPSILON))
#define isEqual(x,y) (((x >= y) ? (x-y) : (y-x)) < EPSILON)

#endif