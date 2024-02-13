from setuptools import setup, Extension
import numpy as np
# External C files
source_c = ['src/ODE.c','src/ExplicitEuler.c','src/VanDerPol.c']

# Define the extension module
extension_module = Extension('ODE',
                             sources=source_c,
                             include_dirs=['include',np.get_include()],
                             library_dirs=['lib'])

setup(
    name='ODE',
    version='1.0',
    description='Your package description',
    ext_modules=[extension_module],
    script_args=['build'],
    options={'build': {'build_lib': 'lib', 'build_temp': 'bin'}}
)