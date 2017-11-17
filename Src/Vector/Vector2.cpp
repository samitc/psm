//
// Created by amit on 18/11/2016.
//

#include "Vector2.h"
Vector dotVector2(const Vector &vec1, const Vector &vec2)
{
	Vector ret = mulVector(vec1, vec2);
	ret=addHorizontalVector(ret,ret);
	return permuteVector(ret,MAKE_PERMUTE(0,0,0,0));
}
Vector lengthSqVector2(const Vector &vec)
{
	return dotVector2(vec,vec);
}
Vector NormalizeVector2(const Vector &vec)
{
	return divVector(vec,lengthVector2(vec));
}