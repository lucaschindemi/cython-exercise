cdef extern from "quaternion.h":
    cdef cppclass Quaternion:
        float w,x,y,z
        Quaternion(float, float, float, float)
        float dot(const Quaternion* q)
        float length()
        Quaternion* conjugate(const Quaternion* q)
        void display()

cdef class PyQuaternion:

    cdef Quaternion *_thisptr

    def __cinit__(self, float _w, float _x, float _y, float _z):
        self._thisptr = new Quaternion(_w, _x, _y, _z)
        if self._thisptr == NULL:
            raise MemoryError()

    def __dealloc__(self):
        if self._thisptr != NULL:
            del self._thisptr


    # We expose the quaternion members
    @property
    def w(self):
        return self._thisptr.w

    @property
    def x(self):
        return self._thisptr.x

    @property
    def y(self):
        return self._thisptr.y

    @property
    def z(self):
        return self._thisptr.z

    # We declare a setter for each member in order to rewrite it
    @w.setter
    def w(self, val):
        self._thisptr.w = val

    @x.setter
    def x(self, val):
        self._thisptr.x = val

    @y.setter
    def y(self, val):
        self._thisptr.y = val

    @z.setter
    def z(self, val):
        self._thisptr.z = val

    # Dot product operation between quaternions
    def dot(self, PyQuaternion q):
        return self._thisptr.dot(q._thisptr)

    # Length of quaternion
    @property
    def length(self):
        return self._thisptr.length()

    # Conjugate of quaternion
    def conjugate(self, PyQuaternion q):
        self._thisptr = self._thisptr.conjugate(q._thisptr)

    # Display quaternion
    @property
    def display(self):
        self._thisptr.display()
