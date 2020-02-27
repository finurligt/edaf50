#ifndef PRIME_H
#define PRIME_H
#include <iostream>
#include <vector>


class Prime {
public:
	Prime(int size);
	std::string getResult();
	std::vector<int> getPrimes();


private:
	std::string primes;
};


#endif
