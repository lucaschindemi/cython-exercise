from distutils.core import setup, Extension
from Cython.Build import cythonize

ext = Extension("quaternion",
                sources=["quaternion.pyx"],
                language="c++")

setup(name="quaternion",
      ext_modules=cythonize(ext))
