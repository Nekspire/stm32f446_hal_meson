#include"unity.h"
#include"unity_fixture.h"

TEST_GROUP_RUNNER(MathOperations)
{
    RUN_TEST_CASE(MathOperations, Sum)
}

void run_all_tests(void)
{
    RUN_TEST_GROUP(MathOperations);
}

int main(int argc, const char ** argv)
{
    return UnityMain(argc, argv, run_all_tests);
}