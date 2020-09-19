#pragma once

#include "date.h"
#include <map>
#include <vector>
#include <algorithm>
#include "event.h"


class Database{
 public:
	Database(){}
	//Database(map<Date, vector<string>> new_data);
	//map<Date, vector<string>> data;
	Database(map<Date, Events> new_data);
    map<Date, Events> data;

void Add(const Date& date, const string& event);

template <class Func> int RemoveIf(Func f);

template <class Func> vector<pair<Date, string>> FindIf(Func f) const;

void Print(ostream& os) const;

pair<Date, string> Last(const Date& d) const;
};

template <class Func>
int Database::RemoveIf(Func f){
	int k = 0;
	vector<Date> dates;
	for(auto& [date, events] : data){
		const Date d = date;
		auto it = remove_if(begin(events.vector), end(events.vector), [f, d](const Event e){return f(d, e.name);});
		k += end(events.vector) - it;
		events.vector.erase(it, end(events.vector));
		if(events.vector.size() == 0){dates.push_back(date);}
	}
	for(const Date& date :dates){
		data.erase(date);
	}
	return k;
}

template <class Func>
vector<pair<Date, string>> Database::FindIf(Func f) const {
	vector<pair<Date, string>> finded_events;
	for(auto& [date, events] : data){
		map<int, string> d;
		for (auto& event : events.vector){
			if(f(date, event.name)){d[event.number] = event.name;}
		}
		for (auto& event : d){
			finded_events.push_back({date, event.second});
		}
	}
	return finded_events;
}

ostream& operator<<(ostream& os,const pair<Date, string>& p);
