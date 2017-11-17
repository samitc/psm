//
// Created by amit on 18/11/2016.
//

#ifndef PSM_VECTOR4_H
#define PSM_VECTOR4_H
#include "Vector.h"

Vector dotVector4(const Vector &vec1, const Vector &vec2);
Vector lengthSqVector4(const Vector &vec);
Vector lengthVector4(const Vector &vec);
Vector NormalizeVector4(const Vector &vec);
#include "Vector4.cpp"
#endif //PSM_VECTOR4_H
