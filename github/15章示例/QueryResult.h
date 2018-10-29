#pragma once
#include<iostream>
#include<string>
#include<memory>
#include<set>
#include<vector>


class QueryResult {
	friend std::ostream& print(std::ostream&, const QueryResult&);
public:
	using line_no = std::vector<std::string>::size_type;
	using iter = std::set<line_no>::iterator;
	QueryResult(std::string s, std::shared_ptr<std::set<line_no>> p,
		std::shared_ptr<std::vector<std::string>> f)
		:sought(s), lines(p), file(f) {}
	
	iter begin() const {
		return lines->begin();
	}
	iter last() const {		//return the position of the last element
		return --end();
	}
	iter end() const {
		return (lines->end());
	}
	std::shared_ptr<std::vector<std::string>> get_file() const {
		return file;
	}
private:
	std::string sought;
	std::shared_ptr<std::set<line_no>> lines;
	std::shared_ptr<std::vector<std::string>> file;
};
std::ostream& print(std::ostream&, const QueryResult&);