//
// Created by amit on 18/11/2016.
//
#include <string.h>

Vector loadZeroVector()
{
	return _mm_setzero_ps();
}
Vector addVector(const Vector &vec1, const Vector &vec2)
{
	return _mm_add_ps(vec1, vec2);
}
Vector addFVector(const Vector &vec1,const Vector &vec2)
{
	return _mm_add_ss(vec1,vec2);
}
Vector loadVector(float x, float y, float z, float w)
{
	return _mm_set_ps(w, z, y, x);
}
Vector loadVectorAlign(const float *data)
{
	return _mm_load_ps(data);
}
Vector loadVectorUnAlign(const float *data)
{
	return _mm_loadu_ps(data);
}
Vector loadValZerosVector(float x)
{
	return _mm_set_ss(x);
}
Vector loadAllValsVector(float val)
{
	return _mm_set_ps1(val);
}
void storeVector(const Vector &vec, float &x, float &y, float &z, float &w)
{
    x = vec.m128_f32[0];
    y = vec.m128_f32[1];
    z = vec.m128_f32[2];
    w = vec.m128_f32[3];
}
void storeVector(const Vector &vec, float *data)
{
	memcpy(data, &vec, sizeof(Vector));
}
Vector4Data storeVector(const Vector &vec)
{
	Vector4Data ret;
	storeVector(vec, ret.vector4DF32);
	return ret;
}
Vector subVector(const Vector &vec1, const Vector &vec2)
{
	return _mm_sub_ps(vec1, vec2);
}
// sse3 only
Vector addSubVector(const Vector &vec1, const Vector &vec2)
{
	return _mm_addsub_ps(vec1, vec2);
}
// sse3 only
Vector addHorizontalVector(const Vector &vec1, const Vector &vec2)
{
	return _mm_hadd_ps(vec1, vec2);
}
Vector mulVector(const Vector &vec1, const Vector &vec2)
{
	return _mm_mul_ps(vec1, vec2);
}
Vector divVector(const Vector &vec1, const Vector &vec2)
{
	return _mm_div_ps(vec1, vec2);
}
Vector sqrtVector(const Vector &vec)
{
	return _mm_sqrt_ps(vec);
}
