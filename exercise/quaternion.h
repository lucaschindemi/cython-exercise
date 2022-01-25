#ifndef __QUATERNION__
#define __QUATERNION__


struct Quaternion;

// Dot product
float kmQuaternionDot(const Quaternion* q1, const Quaternion* q2);

// Length 
float kmQuaternionLengthSq(const Quaternion* q);
float kmQuaternionLength(const Quaternion* q);


struct Quaternion {
  Quaternion(float _w, float _x, float _y, float _z):
  w(_w), x(_x), y(_y), z(_z)
  {};

  // Dot product
  float dot(const Quaternion* q);

  // Length
  float length();

  float w,x,y,z;
};



#endif
