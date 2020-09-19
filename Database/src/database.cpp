#include "database.h"

Database::Database(map<Date, Events> new_data){data = new_data;}

void Database::Add(const Date& date, const string& event){
	Event e(event, 0);
	auto it = lower_bound(begin(data[date].vector), end(data[date].vector), e);
	e.number = 1 + data[date].number;
	if(it == end(data[date].vector)) {
		data[date].vector.push_back(e);
		data[date].number++;
		return;
	}
	if (it->name != event){
		data[date].vector.insert(it, e);
		data[date].number++;
	}
}

void Database::Print(ostream& os) const {
	for(auto& [date, events] : data){
		map<int, string> d;
		for (auto& event : events.vector){
			d[event.number] = event.name;
		}
		for (auto& event : d){
			os << date << " " << event.second << endl;
		}
	}
}
/*
void Database::Print(ostream& os) const {
	for (const auto& date_events : data){
		for (const auto& event : date_events.second){
			os << date_events.first << " " << event << endl;
		}
	}
}*/

pair<Date, string> Database::Last(const Date& d) const {
	auto it = data.upper_bound(d);
	if (it == begin(data)) {throw invalid_argument("");}
	it--;
	int m = 0;
	string max_event;
	for (auto event : it->second.vector){
		m = max(event.number, m);
		if (m == event.number){max_event = event.name;}
	}
	return {it->first, max_event};
}

ostream& operator<<(ostream& os,const pair<Date, string>& p){
	os << p.first << " " << p.second;
	return os;
}
