#include "node.h"

template <class T>
bool MakeComparison(const Comparison& cmp, const T& l, const T& r);

bool DateComparisonNode::Evaluate(const Date& d, const string& e) const {return MakeComparison(cmp, d, date);}

bool EventComparisonNode::Evaluate(const Date& d, const string& e) const {return MakeComparison(cmp, e, event);}

bool LogicalOperationNode::Evaluate(const Date& d, const string& e) const {
	bool t1 = left->Evaluate(d, e);
	bool t2 = right->Evaluate(d, e);
	return callLogic(logical_operation, t1, t2);
}

bool EmptyNode::Evaluate(const Date& d, const string& e) const {return true;}

template <class T>
bool MakeComparison(const Comparison& cmp, const T& l, const T& r){
	if (cmp == Comparison::Equal) {return l == r;}
	if (cmp == Comparison::Greater) {return l > r;}
	if (cmp == Comparison::GreaterOrEqual) {return l >= r;}
	if (cmp == Comparison::Less) {return l < r;}
	if (cmp == Comparison::LessOrEqual) {return l <= r;}
	if (cmp == Comparison::NotEqual) {return l != r;}
	return false;
}

bool callLogic(LogicalOperation log_op, bool t1, bool t2){
	if (log_op == LogicalOperation::And) {return t1 and t2;}
	if (log_op == LogicalOperation::Or) {return t1 or t2;}
	return false;
}
