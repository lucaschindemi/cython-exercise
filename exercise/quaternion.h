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

  float dot(const Quaternion* q){
    return kmQuaternionDot(this, q);
  }

  float length(){
    return kmQuaternionLength(this);
  }

  float w,x,y,z;
};


// Returns the dot product of the 2 quaternions
float kmQuaternionDot(const Quaternion* q1, const Quaternion* q2) {
  // A dot B = B dot A = AtBt + AxBx + AyBy + AzBz

  return (q1->w * q2->w +
      q1->x * q2->x +
      q1->y * q2->y +
      q1->z * q2->z);
}

// Returns the length of the quaternion squared (prevents a sqrt)
float kmQuaternionLengthSq(const Quaternion* q)
{
  return q->x * q->x + q->y * q->y +
            q->z * q->z + q->w * q->w;
}

// Returns the length of the quaternion
float kmQuaternionLength(const Quaternion* q)
{
  return sqrtf(kmQuaternionLengthSq(q));
}




#endif
