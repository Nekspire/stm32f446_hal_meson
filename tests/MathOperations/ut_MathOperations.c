#include "unity_fixture.h"
#include "sum.h"

TEST_GROUP(MathOperations);

TEST_SETUP(MathOperations)
{

}

TEST_TEAR_DOWN(MathOperations)
{

}

TEST(MathOperations, Sum)
{
    TEST_ASSERT_EQUAL_INT(4, MathOperations_sum(2, 2));
}