//
// Created by amit on 18/11/2016.
//

#include "Vector3.h"

Vector dotVector3(const Vector &vec1,const Vector &vec2)
{
	Vector temp = mulVector(vec1, vec2);
	Vector ret=addHorizontalVector(temp,temp);
	ret=addVector(ret,permuteVector(temp,MAKE_PERMUTE(2,2,2,2)));
	return permuteVector(ret,MAKE_PERMUTE(0,0,0,0));
}
Vector lengthSqVector3(const Vector &vec)
{
	return dotVector3(vec,vec);
}
Vector NormalizeVector3(const Vector &vec)
{
	return divVector(vec,lengthVector3(vec));
}