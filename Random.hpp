#include <iostream>
#include <time.h>
#include <math.h>
#include <string.h>

#define SEED seed[0]
#define VALUE seed[1]
#define MOD seed[2]
#define MUL seed[3]
#define INC seed[4]

class Random
{	//Linear congruential generator
public:
    Random()
    {
        time_t t;
        time(&t);
		seed = (long long unsigned int*)malloc(sizeof(long long unsigned int)*5);
		VALUE *= SEED*t;
		MOD = pow(2,31);
		MUL = 1103515245;
		INC = 12345;
    }
    ~Random()
	{
		free(seed);
	}

	int next()
	{
		VALUE = (MUL*VALUE+INC) % MOD;
		return VALUE;
	}
	int next(int min,int max)
    {
		if(min<0 || max-min<1) throw IllegalArgumentExeption();
		return min+(next()%(max-min));
    }
	int next(int max)
	{
		return next(0,max);
	}
	void printData()
	{
		std::cout << "value: " << VALUE << std::endl;
		std::cout << "modulus: " << MOD << std::endl;
		std::cout << "multiplier: " << MUL << std::endl;
		std::cout << "increment: " << INC << std::endl;
	}
	int current()
	{
		return VALUE;
	}

private:
class IllegalArgumentExeption : std::exception{};
	long long unsigned int* seed;
};
#undef SEED
#undef VALUE
#undef MOD
#undef MUL
#undef INC