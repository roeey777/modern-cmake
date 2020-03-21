#include <fact/fact.hpp>
#include <spdlog/spdlog.h>

unsigned int factorial(unsigned int x)
{
	spdlog::info("factorial({})", x);
	return x <= 1 ? 1 : x * factorial(x-1);
}
