from distutils.core import setup, Extension
from Cython.Build import cythonize

ext = Extension("quaternion",
                sources=["quaternion.pyx", "quaternionOperations.cpp"],
                language="c++")

setup(name="quaternion",
      ext_modules=cythonize(ext))
