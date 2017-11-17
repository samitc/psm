//
// Created by amit on 16/11/2016.
//
#include "General.h"
#include "Vector.h"
#define eqVector(v, x,y,z,w)\
{\
    float vx,vy,vz,vw;\
    storeVector(v,vx,vy,vz,vw);\
    ASSERT_EQ((float)(x),vx);\
    ASSERT_EQ((float)(y),vy);\
    ASSERT_EQ((float)(z),vz);\
    ASSERT_EQ((float)(w),vw);\
}
#define neVector(v, x,y,z,w)\
{\
    float vx,vy,vz,vw;\
    storeVector(v,vx,vy,vz,vw);\
    ASSERT_NEAR((float)(x),vx,0.00001);\
    ASSERT_NEAR((float)(y),vy,0.00001);\
    ASSERT_NEAR((float)(z),vz,0.00001);\
    ASSERT_NEAR((float)(w),vw,0.00001);\
}
TEST(VectorGeneralTests, zeroVector)
{
    Vector v = loadZeroVector();
    float x,y,z,w;
    storeVector(v,x,y,z,w);
    ASSERT_EQ(0,x);
    ASSERT_EQ(0,y);
    ASSERT_EQ(0,z);
    ASSERT_EQ(0,w);
}
TEST(VectorGeneralTests, loadVector)
{
    Vector v = loadVector(5,2,3,4);
    float vals[4];
    storeVector(v,vals);
    ASSERT_EQ(5,vals[0]);
    ASSERT_EQ(2,vals[1]);
    ASSERT_EQ(3,vals[2]);
    ASSERT_EQ(4,vals[3]);
}
TEST(VectorGeneralTests, loadOneVal)
{
    Vector v = loadValZeroVector(8);
    Vector4Data vals = storeVector(v);
    ASSERT_EQ(8,vals.x);
    ASSERT_EQ(0,vals.y);
    ASSERT_EQ(0,vals.z);
    ASSERT_EQ(0,vals.w);
}
TEST(VectorGeneralTests, loadAllVals)
{
    Vector v =loadAllValsVector(13);
    eqVector(v,13,13,13,13);
}
TEST(VectorGeneralTests, addVector)
{
    Vector v1=loadVector(4,5,6,7);
    Vector v2=loadVector(7,6,5,4);
    Vector v3=addVector(v1,v2);
    Vector v4=addVector(v2,v1);
    eqVector(v3,11,11,11,11);
    eqVector(v4,11,11,11,11);
}
TEST(VectorGeneralTests, addFTest)
{
    Vector v1=loadVector(4,5,6,7);
    Vector v2=loadVector(7,6,5,4);
    Vector v3=addFVector(v1,v2);
    Vector v4=addFVector(v2,v1);
    eqVector(v3,11,5,6,7);
    eqVector(v4,11,6,5,4);
}
TEST(VectorGeneralTests, subTest)
{
    Vector v1=loadVector(3,6,3,7);
    Vector v2=loadVector(1,3,2,4);
    Vector v3=subVector(v1,v2);
    Vector v4=subVector(v2,v1);
    eqVector(v3,2,3,1,3);
    eqVector(v4,-2,-3,-1,-3);
}
/*TEST(VectorGeneralTests, horizontalAddTest)
{
    Vector v1=loadVector(5,6,2,4);
    Vector v2=loadVector(7,8,5,3);
    Vector v3=addHorizontalVector(v1,v2);
    Vector v4=addHorizontalVector(v2,v1);
    eqVector(v3,11,15,6,8);
    eqVector(v4,15,11,8,6);
}
TEST(VectorGeneralTests, addSubTest)
{
    Vector v1=loadVector(6,3,1,1);
    Vector v2=loadVector(8,5,75,3);
    Vector v3=addSubVector(v1,v2);
    Vector v4=addSubVector(v2,v1);
    eqVector(v3,14,-2,76,-2);
    eqVector(v4,14,2,76,2);
}*/
TEST(VectorGeneralTests, mulTest)
{
    Vector v1=loadVector(4,6,3,2);
    Vector v2=loadVector(5,3,2,1);
    Vector v3=mulVector(v1,v2);
    Vector v4=mulVector(v2,v1);
    eqVector(v3,20,18,6,2);
    eqVector(v4,20,18,6,2);
}
TEST(VectorGeneralTests, divTest)
{
    Vector v1=loadVector(10,6,7,11);
    Vector v2=loadVector(4,3,4,6);
    Vector v3=divVector(v1,v2);
    Vector v4=divVector(v2,v1);
    eqVector(v3,2.5,2,7/4.0,11/6.0);
    eqVector(v4,4.0/10,0.5,4.0/7,6.0/11);
}
TEST(VectorGeneralTests, sqrtTest)
{
    Vector v1=loadVector(9,16,25,36);
    Vector v3=sqrtVector(v1);
    eqVector(v3,3,4,5,6);
}
TEST(VectorGeneralTests, lerpTest)
{
    Vector v1=loadVector(1,2,3,4);
    Vector v2=loadVector(10,20,30,40);
    Vector v3=lerpVector(v1,v2,loadVector(0,0.25,0.75,1));
    Vector v4=lerpVector(v1,v2,loadVector(0.2,0.4,0.6,0.8));
    Vector v5=lerpVector(v1,v2,loadVector(0.9,0.8,0.2,0.1));
    Vector v6=lerpVector(v1,v2,loadVector(0.5,0.5,0.5,0.5));
    Vector v7=lerpVector(v2,v1,loadVector(0,0.25,0.75,1));
    Vector v8=lerpVector(v2,v1,loadVector(0.2,0.4,0.6,0.8));
    Vector v9=lerpVector(v2,v1,loadVector(0.9,0.8,0.2,0.1));
    Vector v10=lerpVector(v2,v1,loadVector(0.5,0.5,0.5,0.5));
    Vector v11=lerpVector(v1,v2,loadVector(0,0,0,0));
    Vector v12=lerpVector(v1,v2,loadVector(1,1,1,1));
    Vector v13=lerpVector(v2,v1,loadVector(0,0,0,0));
    Vector v14=lerpVector(v2,v1,loadVector(1,1,1,1));
    eqVector(v3,1,6.5,23.25,40);
    neVector(v4,2.8,9.2,19.2,32.8);
    neVector(v5,9.1,16.4,8.4,7.6);
    eqVector(v6,5.5,11,16.5,22);
    eqVector(v7,10,15.5,9.75,4);
    neVector(v8,8.2,12.8,13.8,11.2);
    neVector(v9,1.9,5.6,24.6,36.4);
    eqVector(v10,5.5,11,16.5,22);
    eqVector(v11,1,2,3,4);
    eqVector(v12,10,20,30,40);
    eqVector(v13,10,20,30,40);
    eqVector(v14,1,2,3,4);
}
