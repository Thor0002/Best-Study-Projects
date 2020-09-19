#pragma once

#include <sstream>
#include <iostream>
#include <iomanip>
using namespace std;

class Date{
 public:
	Date(){};
	Date(int new_year, int new_month, int new_day);
	int year;
	int month;
	int day;
};

istream& operator>>(istream& input_stream, Date& date);

ostream& operator<<(ostream& stream,const Date& date);

bool operator<(const Date& d1, const Date& d2);
bool operator>(const Date& d1, const Date& d2);
bool operator==(const Date& d1, const Date& d2);
bool operator!=(const Date& d1, const Date& d2);
bool operator<=(const Date& d1, const Date& d2);
bool operator>=(const Date& d1, const Date& d2);

Date ParseDate(istream& input_stream);

