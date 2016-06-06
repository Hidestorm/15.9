#include "Query.h"
#include "WordQuery.h"
#include "BinaryQuery.h"

Query & Query::operator=(const Query &)
{
	// TODO: 在此处插入 return 语句
}
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
std::ostream&
operator<<(std::ostream &os, const Query &q)
{
	return q.display(os);
}