#pragma once
#include "Query_base.h"

class Query {
	// these operators need access to the Query_base* constructor
	friend Query operator~(const Query &);
	friend Query operator|(const Query&, const Query&);
	friend Query operator&(const Query&, const Query&);
//	friend ostream &operator << (ostream&, Query&);
public:
	Query(const std::string&); // builds a new WordQuery
							   // copy control to manage pointers and use counting
	Query(const Query &c) : q(c.q), use(c.use) { ++*use; }
	~Query() { decr_use(); }
//	Query& operator=(const Query&);
	// interface functions: will call corresponding Query_base	operations
	std::set<TextQuery::line_no>
		eval(const TextQuery &t) const { return q->eval(t); }
	std::ostream &display(std::ostream &os) const
	{
		return q->display(os);
	}
private:
	Query(Query_base *query) : q(query),
		use(new std::size_t(1)) { }
	Query_base *q;
	std::size_t *use;
	void decr_use()	{
		if (--*use == 0) { 
			delete q;
			delete use;
		}
	}
};
inline ostream & operator<<(ostream &os, const Query &q) {
	return q.display(os);
}

