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
    MemoryLeakWarningPlugin::turnOnNewDeleteOverloads();
  }
};

TEST(FactTests, FactorialCorrectness)
{
  CHECK_EQUAL(factorial(1), 1);
  CHECK_EQUAL(factorial(2), 2);
  CHECK_EQUAL(factorial(3), 6);
  CHECK_EQUAL(factorial(10), 3628800);
}

int main(int argc, char** argv)
{
    return CommandLineTestRunner::RunAllTests(argc, argv);
}