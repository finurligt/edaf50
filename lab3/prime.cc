#include "prime.h"
#include <iostream>
#include <vector>


Prime::Prime(int size) {
	primes = std::string(size, 'P');
	primes.replace(0, 1, "C");
	primes.replace(1, 1, "C");
	int i = 2;
	while (i < primes.size() / 2) {
		int i2(i*2);
		while (i2 < primes.size()) {
			primes.replace(i2, 1, "C");
			i2 += i;
		}
		i++;
	}
}

std::string Prime::getResult() {
	return primes;
}

std::vector<int> Prime::getPrimes() {
	std::vector<int> resultVect;
	int i(0);
	while (i < primes.size()) {
		if (primes.at(i)=='P') {
			resultVect.push_back(i);
		}
		i++;
	}
	return resultVect;
}