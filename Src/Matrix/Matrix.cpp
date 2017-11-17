//
// Created by amit on 18/11/2016.
//

#include "Matrix.h"

const Vector MI0 = loadVector(1, 0, 0, 0);
const Vector MI1 = loadVector(0, 1, 0, 0);
const Vector MI2 = loadVector(0, 0, 1, 0);
const Vector MI3 = loadVector(0, 0, 0, 1);
Matrix loadIdentityMatrix()
{
	return setMatrix(MI0, MI1, MI2, MI3);
}
Matrix setMatrix(const Vector &r0, const Vector &r1, const Vector &r2, const Vector &r3)
{
	Matrix ret;
	ret.v[0] = r0;
	ret.v[1] = r1;
	ret.v[2] = r2;
	ret.v[3] = r3;
	return ret;
}
Matrix transposeMatrix(const Matrix &matrix)
{
	Matrix ret;
	Vector t1 = shuffleVector(ret.v[0], ret.v[1], MAKE_SHUFFLE(1, 0, 1, 0));
	Vector t2 = shuffleVector(ret.v[2], ret.v[3], MAKE_SHUFFLE(1, 0, 1, 0));
	Vector t3 = shuffleVector(ret.v[0], ret.v[1], MAKE_SHUFFLE(3, 2, 3, 2));
	Vector t4 = shuffleVector(ret.v[2], ret.v[3], MAKE_SHUFFLE(3, 2, 3, 2));
	ret.v[0] = shuffleVector(t1, t2, MAKE_SHUFFLE(2, 0, 2, 0));
	ret.v[1] = shuffleVector(t1, t2, MAKE_SHUFFLE(3, 1, 3, 1));
	ret.v[2] = shuffleVector(t3, t4, MAKE_SHUFFLE(2, 0, 2, 0));
	ret.v[3] = shuffleVector(t3, t4, MAKE_SHUFFLE(3, 1, 3, 1));
	return ret;
}
Matrix translationMatrix(const Vector &translation)
{
	return setMatrix(MI0,MI1,MI2,translation);
}
