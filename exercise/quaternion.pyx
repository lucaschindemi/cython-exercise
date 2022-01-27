from libc.stdlib cimport malloc, free

cdef extern from "quaternion.h":
    cdef cppclass Quaternion:
        float w,x,y,z
        Quaternion(float, float, float, float)
        float dot(const Quaternion* q)
        float length()
        Quaternion* conjugate(Quaternion* q_conj)
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


    # We expose the str method to be able to print the quaternion
    def __str__(self):
        return ('Quaternion: (' + str(self._thisptr.w) + ', ' + str(self._thisptr.x) + ', ' + 
            str(self._thisptr.y) + ', ' + str(self._thisptr.z) + ')')


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
    cpdef conjugate(self):
        # save space for storing the conjugate
        cdef Quaternion* q_conj = <Quaternion*> malloc(sizeof(Quaternion))

        # get conjugate of instance and store it in q_conj
        self._thisptr.conjugate(q_conj)

        # parse Quaternion to PyQuaternion
        pq_conj = PyQuaternion(q_conj.w, q_conj.x, q_conj.y, q_conj.z)

        free(q_conj) # free Quaternion

        return pq_conj # return PyQuaternion conjugate

    # Display quaternion
    @property
    def display(self):
        self._thisptr.display()
