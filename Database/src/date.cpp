#include "date.h"

Date::Date(int new_year, int new_month, int new_day){
		year = new_year;
		month = new_month;
		day = new_day;
	}

istream& operator>>(istream& input_stream, Date& date){
	try{
    string s;
    input_stream >> s;
    stringstream stream(s);
	int year, month, day;
	if (not (stream >> year)){
		throw runtime_error("Wrong date format: " + s);
	}
	if (stream.peek() != '-'){
		throw runtime_error("Wrong date format: " + s);
	}
    stream.ignore(1);
    if (not (stream >> month)){
        throw runtime_error("Wrong date format: " + s);
    	}
    if (stream.peek() != '-'){
    	throw runtime_error("Wrong date format: " + s);
    }
    stream.ignore(1);
    if (not (stream >> day)){
    	throw runtime_error("Wrong date format: " + s);
    	}
    string e = "";
    stream >> e;
    if (e != "") {
    	throw runtime_error("Wrong date format: " + s);
    }
    if (month < 1 or month > 12){
        	throw runtime_error("Month value is invalid: " + to_string(month));
        }
    if (day < 1 or day > 31){
    	throw runtime_error("Day value is invalid: " + to_string(day));
    }
    Date new_date = {year, month, day};
    date = new_date;
    return input_stream;
	} catch(exception& e){
		cerr << e.what() << endl;
		exit(1);
		return input_stream;
	}
}

ostream& operator<<(ostream& stream,const Date& date){
	stream << setfill('0') << setw(4) << date.year << "-" << setw(2);
	stream << date.month << "-" << setw(2) << date.day << setfill(' ');
	return stream;
}

bool operator<(const Date& d1, const Date& d2){
	if (d1.year < d2.year)       {return true;}
	else if (d1.year > d2.year)  {return false;}
	else if (d1.month < d2.month){return true;}
	else if (d1.month > d2.month){return false;}
	else if (d1.day < d2.day)    {return true;}
	else if (d1.day > d2.day)    {return false;}
	else {return false;}
}

bool operator>(const Date& d1, const Date& d2){return d2 < d1;}
bool operator==(const Date& d1, const Date& d2){
	return d1.day == d2.day and d1.month == d2.month and d1.year == d2.year;
}
bool operator!=(const Date& d1, const Date& d2){return !(d1 == d2);}
bool operator<=(const Date& d1, const Date& d2){return d1 < d2 or d1 == d2;}
bool operator>=(const Date& d1, const Date& d2){return d1 > d2 or d1 == d2;}

Date ParseDate(istream& input_stream){
	Date date;
	input_stream >> date;
	return date;
}
