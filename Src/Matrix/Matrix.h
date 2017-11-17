//
// Created by amit on 18/11/2016.
//

#ifndef PSM_MATRIX_H
#define PSM_MATRIX_H
#include "../Vector/Vector.h"

struct Matrix
{
	static constexpr int MATRIX_SIZE = 4;
	Vector v[4];
};
Matrix loadIdentityMatrix();
Matrix setMatrix(const Vector &r0,const Vector &r1,const Vector &r2,const Vector &r3);
Matrix transposeMatrix(const Matrix &matrix);
Vector determinantMatrix(const Matrix &matrix);
Matrix invertMatrix(const Matrix &matrix);
Matrix translationMatrix(const Vector &translation);
Matrix rotationXMatrix(const Vector &vec);
Matrix rotationYMatrix(const Vector &vec);
Matrix rotationZMatrix(const Vector &vec);
Matrix rotationMatrix(const Vector &vec);
#include "Matrix.cpp"

#endif //PSM_MATRIX_H
