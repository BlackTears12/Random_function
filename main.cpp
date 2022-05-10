#include "Random.hpp"

double avg_eq(unsigned int length,int randrange)
{
	Random r1;
	Random r2;
	long long unsigned int sum = 0;
	for(unsigned int j=0;j<length;j++)
	{
		unsigned int i = 1;
		int random1 = r1.next(randrange);
		int random2 = r2.next(randrange);
		while((random1=r1.next(randrange)) != (random2=r2.next(randrange)))
		{
			//std::cout << random1 << " : " << random2 << std::endl;
			++i;
		}
		//std::cout << random1 << " : " << random2 << std::endl;
		//std::cout << "Same random number after " << i << " tries";
		sum+=i;
	}
	return ((double)sum/length);
}
int main()
{
	/*std::cout << "Average equal randoms after " << avg_eq(10000,10) << " tries for 1 digit numbers" << std::endl;
	std::cout << "Average equal randoms after " << avg_eq(10000,100) << " tries for 2 digit numbers" << std::endl;
	std::cout << "Average equal randoms after " << avg_eq(10000,1000) << " tries for 3 digit numbers" << std::endl;
	std::cout << "Average equal randoms after " << avg_eq(10000,10000) << " tries for 4 digit numbers" << std::endl;
	std::cout << "Average equal randoms after " << avg_eq(10000,100000) << " tries for 5 digit numbers" << std::endl;
	std::cout << "Average equal randoms after " << avg_eq(10000,1000000) << " tries for 6 digit numbers" << std::endl;
	std::cout << "Average equal randoms after " << avg_eq(10000,10000000) << " tries for 7 digit numbers" << std::endl;
	std::cout << "Average equal randoms after " << avg_eq(10000,100000000) << " tries for 8 digit numbers" << std::endl;*/
	
	//Feleződik az egyenlő randomok találásának ideje
	//	lim	   1/  *  10^n			n-ed számjegyű számok esetén az aprox egyenlő random találásának ideje
	// n->inf  2^n
	
	Random r;
	std::cout << r.next();
	return 0;
}
