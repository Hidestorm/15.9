#include "Query.h"
#include "WordQuery.h"
#include "BinaryQuery.h"

Query::Query(const string &s) : q(new WordQuery(s)), use(new size_t(1)) {}


inline Query operator&(const Query &lhs, const Query &rhs)
{
	return new AndQuery(lhs, rhs);
}
inline Query operator|(const Query &lhs, const Query &rhs)
{
	return new OrQuery(lhs, rhs);
}
inline Query operator~(const Query &oper)
{
	return new NotQuery(oper);
}
