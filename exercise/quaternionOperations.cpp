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
Quaternion* Quaternion::conjugate(Quaternion* q_conj){
    return kmQuaternionConjugate(q_conj, this);
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

// Returns q_conj, sets q_conj to the conjugate of q
Quaternion* kmQuaternionConjugate(Quaternion* q_conj, const Quaternion* q)
{
  q_conj->w = q->w;
  q_conj->x = -q->x;
  q_conj->y = -q->y;
  q_conj->z = -q->z; 

  return q_conj;
}

// To show the members of the quaternion
void displayQuaternion(Quaternion* q)
{

  std::cout<<"Quaternion: " << "(" << q->w << ", " << q->x << ", " << q->y << ", " << q->z << ") \n";

}