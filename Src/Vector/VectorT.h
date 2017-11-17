//
// Created by amit on 18/11/2016.
//

#ifndef PSM_VECTORT_H
#define PSM_VECTORT_H
#if defined(SSE_INSTRUCTION_USING)
	#include <immintrin.h>
#endif
struct Vector4Data
{
	union
	{
		float vector4DF32[4];
		unsigned int vector4DU32[4];
		struct
		{
			float x;
			float y;
			float z;
			float w;
		};
	};
};
#if defined(SSE_INSTRUCTION_USING)
typedef __m128 Vector;
#else
typedef Vector4Data Vector;
#endif
#define MAKE_PERMUTE(c0,c1,c2,c3) (((c3) << 6) | ((c2) << 4) | \
                                     ((c1) << 2) | ((c0)))
#define MAKE_SHUFFLE(c0,c1,c2,c3) MAKE_PERMUTE(c0,c1,c2,c3)
void storeVector(const Vector &vec, float &x, float &y, float &z, float &w);
void storeVector(const Vector &vec, float *data);
Vector4Data storeVector(const Vector &vec);
Vector loadZeroVector();
Vector loadValZeroVector(float x);
Vector loadAllValsVector(float val);
Vector loadVector(float x, float y, float z, float w);
Vector loadVectorAlign(const float *data);
Vector loadVectorUnAlign(const float *data);
Vector addVector(const Vector &vec1, const Vector &vec2);
/*
 * add only first value in the vector.
 */
Vector addFVector(const Vector &vec1,const Vector &vec2);
Vector subVector(const Vector &vec1, const Vector &vec2);
/*
r[0]=a[0]+a[1];
r[1]=b[0]+b[1];
r[2]=a[2]+a[3];
r[3]=b[2]+b[3];
 */
Vector addHorizontalVector(const Vector &vec1, const Vector &vec2);// sse3
/*
every element in even index are subtracted and every element in odd index are added.
*/
Vector addSubVector(const Vector &vec1, const Vector &vec2);//sse3
Vector mulVector(const Vector &vec1, const Vector &vec2);
Vector divVector(const Vector &vec1, const Vector &vec2);
Vector sqrtVector(const Vector &vec);
#if defined(SSE_INSTRUCTION_USING)
	#include "VectorSse.cpp"

#else
#endif
#define permuteVector(vec,control) _mm_permute_ps((vec), (control));
#define shuffleVector(vec1, vec2, control) _mm_shuffle_ps(vec1, vec2, control);
#endif //PSM_VECTOR_H
