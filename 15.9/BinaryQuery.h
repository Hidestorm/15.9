#pragma once
#include "WordQuery.h"
#include "Query_base.h"
class BinaryQuery : public Query_base {
protected:
	BinaryQuery(Query left, Query right, std::string op) :
		lhs(left), rhs(right), oper(op) { }
	// abstract class: BinaryQuery doesn't define eval
	std::ostream& display(std::ostream &os) const
	{
		return os << "(" << lhs << " " << oper << " "
			<< rhs << ")";
	}
	const Query lhs, rhs; // right- and left-hand operands
	const std::string oper; // name of the operator
};
class AndQuery : public BinaryQuery {
	friend Query operator&(const Query&, const Query&);
	AndQuery(Query left, Query right) :
		BinaryQuery(left, right, "&") { }
	// concrete class: And Query inherits display and defines remaining pure virtual
	std::set<line_no> eval(const TextQuery&) const;
};
class OrQuery : public BinaryQuery {
	friend Query operator|(const Query&, const Query&);
	OrQuery(Query left, Query right) :
		BinaryQuery(left, right, "|") { }
	// concrete class: OrQuery inherits display and defines	remaining pure virtual
	std::set<line_no> eval(const TextQuery&) const;
};