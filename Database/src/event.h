#pragma once

#include <iostream>
#include <vector>
using namespace std;

class Event{
public:
	Event(){};
	Event(const string& new_event, const int& new_n){
		name = new_event;
		number = new_n;
	}
	string name;
	int number;
};

bool operator<(const Event& e1, const Event& e2);

bool operator==(const Event& e1, const Event& e2);

class Events{
public:
	vector<Event> vector;
	int number = 0;
};
