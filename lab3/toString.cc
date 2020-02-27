
#include <iostream>

#include <sstream>

#include "date.h"

#include <ostream>
#include <string>

template <typename T>
std::string toString(T something) {
	std::ostringstream ostre;
	std::ostringstream& ostr = ostre;
	ostr << something;
	std::string temp;
	return ostr.str();
}

template <typename T>
T string_cast(std::string str) {
	std::istringstream istream(str);
	T t;
	istream >> t;
	if (istream.fail()) {
		throw std::invalid_argument("Error");
	}
	return t;
}

int main() {


	//Test double
	std::string str1 = toString(double{ 11.1 });
	if (str1.compare("11.1") == 0) {
		std::cout << "success! toString double" << std::endl;
	} else {
		std::cout << "fail!" << std::endl;
	}

	//Test int
	std::string str2 = toString(int{ 1337 });
	if (str2.compare("1337") == 0) {
		std::cout << "success! toString int" << std::endl;
	} else {
		std::cout << "fail!" << std::endl;
	}

	//Test string
	std::string str3 = toString(std::string{ "wut" });
	if (str3.compare("wut") == 0) {
		std::cout << "success! toString string" << std::endl;
	} else {
		std::cout << "fail!" << std::endl;
	}

	//Test Date
	Date asd(2011, 11, 11);
	std::string str4 = toString(asd);
	if (str4.compare("2011-11-11") == 0) {
		std::cout << "success! toString Date" << std::endl;
	} else {
		std::cout << "fail!" << str4 << std::endl;
		std::cout << "expected:" << "2011-11-11" << "a" << std::endl;
		std::cout << "got:     " << str4 << "a" << std::endl;
	}

	double a = string_cast<double>("20.01");
	if (a==20.01) {
		std::cout << "success! ";
	}
	else {
		std::cout << "fail!";
	}
	std::cout << "string_cast double" << std::endl;
	
	int b = string_cast<int>("1337");
	if (b==1337) {
		std::cout << "success! ";
	}
	else {
		std::cout << "fail!";
	}
	std::cout << "string_cast int" << std::endl;

	std::string c = string_cast<std::string>("hallu");
	if (c.compare("hallu")==0) {
		std::cout << "success! ";
	} else {
		std::cout << "fail!" << std::endl;
		std::cout << "expected: hallu" << std::endl;
		std::cout << "got:      " << c << std::endl;
	}
	std::cout << "string_cast string" << std::endl;

	Date d = string_cast<Date>("2019-02-02");
	if (d.getYear() == 2019, d.getMonth() == 2, d.getDay() == 2) {
		std::cout << "success! ";
	} else {
		std::cout << "fail!";
	}
	std::cout << "string_cast Date" << std::endl;
}