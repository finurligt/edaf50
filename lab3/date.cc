#include <ctime>  // time and localtime
#include "date.h"
#include <ostream>
#include <string>
#include <iostream>

int Date::daysPerMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

Date::Date() {
	time_t timer = time(0); // time in seconds since 1970-01-01
	tm* locTime = localtime(&timer); // broken-down time
	year = 1900 + locTime->tm_year;
	month = 1 + locTime->tm_mon;
	day = locTime->tm_mday;
}

Date::Date(int y, int m, int d) { 
	year = y; 
	month = m;
	day = d;    ///////might change later tbh
}

int Date::getYear() const {
	return year;
}

int Date::getMonth() const {
	return month;
}

int Date::getDay() const {
	return day;
}

void Date::next() {
	day++;
	if (day > daysPerMonth[month - 1]) {
		day = 1;
		month++;
	}
	if (month > 12) {
		month = 1;
		year++;
	}
}


std::ostream& operator<<(std::ostream& ostream, Date& date) {
	std::string year = std::to_string(date.getYear());
	std::string month = std::to_string(date.getMonth());
	std::string day = std::to_string(date.getDay());
	ostream << std::string(4 - year.size(), '0').append(year) 
		<< "-" << std::string(2 - month.size(), '0').append(month) 
		<< "-" << std::string(2 - day.size(), '0').append(day);
	return ostream;
}

std::istream& operator>>(std::istream& istream, Date& date) {
	std::string line;
	std::getline(istream, line);
	int first = line.find("-");
	int second = line.find("-",first+1);

	std::string ystring = line.substr(0, first);
	std::string mstring = line.substr(first+1, second);
	std::string dstring = line.substr(second+1, second + 3);

	if (dstring.size() > 2) {
		std::cout << "fail d length'" << dstring << "'" << std::endl;
		istream.setstate(std::ios_base::failbit);
	}

	int y;
	int m;
	int d;

	try {
		y = std::stoi(ystring);
		m = std::stoi(mstring);
		d = std::stoi(dstring);
	} catch (std::invalid_argument const &e) {
		std::cout << "fail";
		istream.setstate(std::ios_base::failbit);
	}

	if (y < 10000 && m <= 12 && d<=date.daysPerMonth[m-1]) {
		date.year = y;
		date.month = m;
		date.day = d;
	} else {
		std::cout << "fail";
		istream.setstate(std::ios_base::failbit);
	}

	//std::cout << y << "-" << m << "-" << d << std::endl;
	return istream;
}

//is.setstate(ios_base::failbit)

/*
int main() {
	Date dt(2019, 9, 21);
	std::cout << dt;
	std::cin >> dt;
}
*/

