#pragma once

#include <iostream>
#include <memory>

#include "date.h"
using namespace std;

enum class Comparison {
	Less,
	LessOrEqual,
	Greater,
	GreaterOrEqual,
	Equal,
	NotEqual
};

enum class LogicalOperation{
	Or,
	And
};

class Node{
public:
	virtual bool Evaluate(const Date& d, const string& e) const = 0;
};

class DateComparisonNode : public Node{
public:
	DateComparisonNode(const Comparison& new_cmp,const Date& new_date) : cmp(new_cmp), date(new_date){}
	bool Evaluate(const Date& d, const string& e) const override;
private:
	const Comparison cmp;
	const Date date;
};

class EventComparisonNode : public Node{
public:
	EventComparisonNode(const Comparison& new_cmp, const string& new_value) : cmp(new_cmp), event(new_value){}
	bool Evaluate(const Date& d, const string& e) const override;
private:
	const Comparison cmp;
	const string event;
};

class LogicalOperationNode : public Node{
public:
	LogicalOperationNode(LogicalOperation log_op, shared_ptr<Node> new_left,shared_ptr<Node> new_right)
    : logical_operation(log_op), left(new_left), right(new_right){}
	bool Evaluate(const Date& d, const string& e) const override;
private:
	const LogicalOperation logical_operation;
	shared_ptr<const Node> left, right;
};

class EmptyNode : public Node{
public:
	bool Evaluate(const Date& d, const string& e) const override;
};

bool callLogic(LogicalOperation log_op, bool t1, bool t2);

