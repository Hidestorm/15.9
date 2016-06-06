#pragma once
#include "Query.h"
class WordQuery : public Query_base {
	friend class Query; // Query uses the WordQuery constructor
	WordQuery(const std::string &s) : query_word(s) { }
	// concrete class: WordQuery defines all inherited pure virtual	functions
	std::set<line_no> eval(const TextQuery &t) const
	{
		return t.run_query(query_word);
	}
	std::ostream& display(std::ostream &os) const
	{
		return os << query_word;
	}
	std::string query_word; // word for which to search
};

class NotQuery : public Query_base {
	friend Query operator~(const Query &);
	NotQuery(Query q) : query(q) { }
	// concrete class: NotQuery defines all inherited pure virtual	functions
	std::set<line_no> eval(const TextQuery&) const;
	std::ostream& display(std::ostream &os) const
	{
		return os << "~(" << query << ")";
	}
	const Query query;
};