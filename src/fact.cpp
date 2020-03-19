# include <fact/fact.hpp>
#include <spdlog/spdlog.h>

unsigned int factorial(unsigned int x)
{
	spdlog::info("factorial({})", x);
	return x <= 1 ? x : x * factorial(x-1);
}
