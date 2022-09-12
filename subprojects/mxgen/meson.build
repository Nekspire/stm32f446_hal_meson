project(
    'mxgen',
    ['c', 'cpp'],
    version: '1.0',
    meson_version: '>=0.60.0',
)

# global variables for sources and includes
src = files(
    'Core/Src/system_stm32f4xx.c',
    'Core/Src/gpio.c',
    'Core/Src/main.c',
    'Core/Src/stm32f4xx_hal_msp.c',
    'Core/Src/stm32f4xx_it.c',
    'Core/Src/syscalls.c',
    'Core/Src/sysmem.c',
    'Core/Startup/startup_stm32f446retx.s',
    'Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_cortex.c',
    'Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma_ex.c',
    'Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma.c',
    'Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_exti.c',
    'Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ex.c',
    'Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash.c',
    'Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_gpio.c',
    'Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr_ex.c',
    'Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr.c',
    'Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc_ex.c',
    'Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc.c',
    'Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim_ex.c',
    'Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim.c',
    'Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal.c',
)

inc = include_directories(
    'Core/Inc',
    'Drivers/CMSIS/Device/ST/STM32F4xx/Include',
    'Drivers/CMSIS/Include',
    'Drivers/STM32F4xx_HAL_Driver/Inc',
    'Drivers/STM32F4xx_HAL_Driver/Inc/Legacy',
)

c_args = []
c_link_args = []
c_link_args +=  '-Wl,-T,@0@/@1@'.format(meson.current_source_dir(), 'STM32F446RETX_FLASH.ld')

# create dependency for subproject STM32CubeMX
mxgen_dep = declare_dependency(
    sources: src,
    include_directories: inc,
    compile_args: c_args,
    link_args: c_link_args,
)