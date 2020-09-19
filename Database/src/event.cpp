#include "event.h"

bool operator<(const Event& e1, const Event& e2){
	return e1.name < e2.name;
};

bool operator==(const Event& e1, const Event& e2){
	return e1.name == e2.name;
};
