#include "quaternion.h"
#include <math.h>

// ----- Structure methods -----
// Dot product between quaternions
float Quaternion::dot(const Quaternion* q){
    return kmQuaternionDot(this, q);
}

// Length of quaternion
float Quaternion::length(){
    return kmQuaternionLength(this);
}

// -----

// Returns the dot product of the 2 quaternions
float kmQuaternionDot(const Quaternion* q1, const Quaternion* q2) {
  // A dot B = B dot A = AtBt + AxBx + AyBy + AzBz

  return (q1->w * q2->w +
      q1->x * q2->x +
      q1->y * q2->y +
      q1->z * q2->z);
}

// Returns the length of the quaternion
float kmQuaternionLength(const Quaternion* q)
{
  return sqrtf(kmQuaternionLengthSq(q));
}

// Returns the length of the quaternion squared (prevents a sqrt)
float kmQuaternionLengthSq(const Quaternion* q)
{
  return q->x * q->x + q->y * q->y +
            q->z * q->z + q->w * q->w;
}


