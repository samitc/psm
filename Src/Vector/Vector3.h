//
// Created by amit on 18/11/2016.
//

#ifndef PSM_VECTOR3_H
#define PSM_VECTOR3_H
#include "Vector.h"

Vector dotVector3(const Vector &vec1, const Vector &vec2);
Vector lengthSqVector3(const Vector &vec);
Vector lengthVector3(const Vector &vec);
Vector NormalizeVector3(const Vector &vec);
#include "Vector3.cpp"
#endif //PSM_VECTOR3_H
