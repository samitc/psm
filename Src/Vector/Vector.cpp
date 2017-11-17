//
// Created by amit on 18/11/2016.
//

#include "Vector.h"

Vector lerpVector(const Vector &vec1, const Vector &vec2, const Vector &t)
{
	Vector s = subVector(vec2, vec1);
	return addVector(vec1, mulVector(t, s));
}
