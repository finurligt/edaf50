#include "prime.h"
#include <iostream>
#include <string>


int main() {
	//test
	Prime smallboye(15);
	if (smallboye.getResult().compare("CCPPCPCPCCCPCPC")==0) {
		std::cout << "Success!" << std::endl;
	} else {
		std::cout << "Failure! Result: " << smallboye.getResult() << std::endl;
	}


	//too lazy to make new main method so here we go again
	std::vector<int> primes;
	
	Prime mediumboye(200);
	std::cout << "[";
	for (int i : mediumboye.getPrimes()) {
		std::cout << i <<", ";
	}
	std::cout << "]" << std::endl;

	Prime bigboye(100000);
	int last = bigboye.getResult().rfind('P');
	std::cout << last;
}