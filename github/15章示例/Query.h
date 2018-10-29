#pragma once

#include"TextQuery.h"
#include"QueryResult.h"
#include"Query_base.h"
#include"WordQuery.h"

class Query {
	friend Query operator~(const Query&);
	friend Query operator|(const Query&, const Query&);
	friend Query operator&(const Query&, const Query&);
public:
	Query(const std::string &str);
	QueryResult eval(const TextQuery& t) const {
		return q->eval(t);
	}
	std::string rep() const {
		return q->rep();
	}
private:
	Query(std::shared_ptr<Query_base> query) :q(query) {}
	std::shared_ptr<Query_base> q;
};
Query operator~(const Query&);
Query operator|(const Query&, const Query&);
Query operator&(const Query&, const Query&);
inline Query::Query(const std::string &str) :q(new WordQuery(str)) { }