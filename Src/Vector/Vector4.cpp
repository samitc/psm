//
// Created by amit on 18/11/2016.
//

#include "Vector4.h"

Vector dotVector4(const Vector &vec1, const Vector &vec2)
{
	Vector ret = mulVector(vec1, vec2);
	ret=addHorizontalVector(ret,ret);
	permuteVector(ret,MAKE_PERMUTE(0,2,0,2));
	return addHorizontalVector(ret,ret);
}
Vector lengthSqVector4(const Vector &vec)
{
	return dotVector4(vec,vec);
}
Vector lengthVector4(const Vector &vec)
{
	return sqrtVector(lengthSqVector4(vec));
}
Vector NormalizeVector4(const Vector &vec)
{
	return divVector(vec,lengthVector4(vec));
}