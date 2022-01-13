project(
    'stm32f446_hal_meson',
    ['c', 'cpp'],
    version: '0.1',
    meson_version: '>=0.60.0',
    default_options: ['c_std=c11', 'warning_level=3']
)

# include the test framework
cpputestdep = dependency('CppUTest', native : true)

# global variables tracking sources and includes
c_args = []
c_link_args = []
project_src = []
project_inc = []
test_src = []
test_inc = []
link_deps = []

# set specific compiler flags
c_args += [
    '-mcpu=cortex-m4',
    '-mthumb',
    '-mthumb-interwork',
    '-ffunction-sections',
    '-fdata-sections',
    '-fno-common',
    '-fmessage-length=0',
    '-Wall',
    '-O0'
]

# set specific linker flags
c_link_args += [
    '-mcpu=cortex-m4',
    '-mthumb',
    '-mthumb-interwork',
    '-Wl,--gc-sections',
    '-Wl,--print-memory-usage',
    '-Wl,--warn-common',
]

# set 'software' or 'hardware' floating point unit type
# default value: 'soft'
fpu = 'soft'

# check which fpu type add set compiler and linker flags 
if fpu == 'hard'
    c_args += [
        '-mfloat-abi=hard',
        '-mfpu=fpv4-sp-d16'
    ]
    c_link_args += [
        '-mfloat-abi=hard',
        '-mfpu=fpv4-sp-d16'
    ]
elif fpu == 'soft'
    c_args += [
        '-mfloat-abi=soft'
    ]
endif

# microcontroller specific settings
defines = [
    '-DSTM32F446xx',
    '-DUSE_HAL_DRIVER'
]

linker_file = files('STM32F446RETx_FLASH.ld')
startup_file = files('startup_stm32f446xx.s')

# add defines to the c_args
c_args += defines

# add the linker script to flags
c_link_args += ['-Wl,-T,@0@/@1@'.format(meson.current_source_dir(), linker_file[0])]

project_inc += include_directories(
    'Core/Inc',
    'Drivers/CMSIS/Device/ST/STM32F4xx/Include',
    'Drivers/CMSIS/Include',
    'Drivers/STM32F4xx_HAL_Driver/Inc',
    'Drivers/STM32F4xx_HAL_Driver/Inc/Legacy'
)


project_src += files(
    'Core/Src/gpio.c',
    'Core/Src/main.c',
    'Core/Src/stm32f4xx_hal_msp.c',
    'Core/Src/stm32f4xx_it.c',
    'Core/Src/system_stm32f4xx.c',
    'Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal.c',
    'Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim.c',
    'Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim_ex.c',
    'Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc.c',
    'Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc_ex.c',
    'Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr.c',
    'Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr_ex.c',
    'Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_gpio.c',
    'Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash.c',
    'Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ramfunc.c',
    'Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ex.c',
    'Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_exti.c',
    'Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma.c',
    'Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma_ex.c',
    'Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_cortex.c',
)

# create .elf executable
elf = executable(
    meson.project_name(),
    [project_src, startup_file],
    name_suffix : 'elf',
    c_args : c_args,
    link_args : c_link_args,
    dependencies : link_deps,
    include_directories : project_inc
)

# create .bin executable based on .elf
bin = custom_target(
    'bin',
    input: elf,
    output:  meson.project_name() + '.bin',
    command: [find_program('objcopy'), '-O', 'binary', '@INPUT@', '@OUTPUT@'],
    build_by_default: true,
    depends: elf
)

# create .hex executable based on .elf
hex = custom_target(
    'hex',
    input: elf,
    output:  meson.project_name() + '.hex',
    command: [find_program('objcopy'), '-O', 'binary', '@INPUT@', '@OUTPUT@'],
    build_by_default: true,
    depends: elf
)

# create executable based on cpputest dependency
testexe = executable(
    'testexe',
    ['test/testcase.cpp', 'test/testrunner.cpp'],
    link_args : ['-lpthread', '-lCppUTest', '-lCppUTestExt'],
    dependencies: cpputestdep,
    native : true
)

test('Unit tests', testexe)