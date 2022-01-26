#include "quaternion.h"
#include <math.h>
#include <iostream>

// ----- Structure methods -----
// Dot product between quaternions
float Quaternion::dot(const Quaternion* q){
    return kmQuaternionDot(this, q);
}

// Length of quaternion
float Quaternion::length(){
    return kmQuaternionLength(this);
}

// Conjugate of quaternion
Quaternion* Quaternion::conjugate(const Quaternion* q){
    return kmQuaternionConjugate(this, q);
}

// Display quaternion
void Quaternion::display(){
    displayQuaternion(this);
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

// Returns pOut, sets pOut to the conjugate of pIn
Quaternion* kmQuaternionConjugate(Quaternion* pOut, const Quaternion* pIn)
{
  pOut->w = pIn->w;
  pOut->x = -pIn->x;
  pOut->y = -pIn->y;
  pOut->z = -pIn->z; 

  return pOut;
}

// To show the members of the quaternion
void displayQuaternion(Quaternion* q)
{

  std::cout<<"Quaternion: " << "(" << q->w << ", " << q->x << ", " << q->y << ", " << q->z << ") \n";

}