project(
   'STM32F446_HAL_MESON',
   ['c', 'cpp'],
   version: '1.0',
   meson_version: '>=0.60.0',
)

# declare subprojects
sp_mxgen = subproject('mxgen')

sp_mxgen_dep = sp_mxgen.get_variable('mxgen_dep')

# global variables for sources and includes
src = files(
   'app/app.c'
)

inc = include_directories(

)

# create .elf file
# source code
elf = executable(
   meson.project_name(),
   sources: src,
   include_directories: inc,
   dependencies: sp_mxgen_dep,
   name_suffix : 'elf',
   native: false
)