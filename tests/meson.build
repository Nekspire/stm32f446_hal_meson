project(
    'STM32H753ZIT6_BLINKING_LED_UT',
    ['c', 'cpp'],
    version: '1.0',
    meson_version: '>=0.60.0',
)

sp_unity = subproject('Unity')

sp_unity_dep = sp_unity.get_variable('unity_dep')

test_inc = include_directories(
    'D:\\programming\\vscode\\embedded\\stm32h753zit6_blinking_led\\app\\source\\MathOperations',
)

test_src = files(
    'test_group_runner.c',

    'MathOperations\\ut_MathOperations.c',

    'D:\\programming\\vscode\\embedded\\stm32h753zit6_blinking_led\\app\\source\\MathOperations\\sum.c',
)

# create .exe file
# unit tests
test = executable(
    meson.project_name(),
    sources: test_src,
    include_directories: test_inc,
    dependencies: sp_unity_dep,
    native: true
)

test(
    meson.project_name(),
    test,
    args: ['-v']
)