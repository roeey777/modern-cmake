#include <CppUTest/TestHarness.h>
#include <CppUTest/CommandLineTestRunner.h>


#include <fact/fact.hpp>

TEST_GROUP(FactTests)
{
  void setup()
  {
    MemoryLeakWarningPlugin::turnOffNewDeleteOverloads();
  }

  void teardown()
  {
    /*
     * for CppUTest version 3.8 or lower one should use:
     *   MemoryLeakWarningPlugin::turnOnNewDeleteOverloads();
     * and from CppUTest version 4.0 onwards one should use the following
     * instead:
     */
    MemoryLeakWarningPlugin::turnOnDefaultNotThreadSafeNewDeleteOverloads();
  }
};

TEST(FactTests, FactorialCorrectness)
{
  CHECK_EQUAL(factorial(0), 1);
  CHECK_EQUAL(factorial(1), 1);
  CHECK_EQUAL(factorial(2), 2);
  CHECK_EQUAL(factorial(3), 6);
  CHECK_EQUAL(factorial(10), 3628800);
}

int main(int argc, char** argv)
{
    return CommandLineTestRunner::RunAllTests(argc, argv);
}
