cdef extern from "quaternion.h":
    cdef cppclass Quaternion:
        float w,x,y,z
        Quaternion(float, float, float, float)
        float dot(const Quaternion* q)


cdef class PyQuaternion:

    cdef Quaternion *_thisptr

    def __cinit__(self, float _w, float _x, float _y, float _z):
        self._thisptr = new Quaternion(_w, _x, _y, _z)
        if self._thisptr == NULL:
            raise MemoryError()

    def __dealloc__(self):
        if self._thisptr != NULL:
            del self._thisptr

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