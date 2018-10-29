#pragma once
#include<string>
#include<iostream>
#include<fstream>
#include<vector>
#include<map>
#include<memory>
#include<set>
#include"QueryResult.h"


class TextQuery {
public:
	using line_no = std::vector<std::string>::size_type;
	TextQuery(std::ifstream &filename);
	QueryResult query(const std::string &sought) const;
private:
	std::shared_ptr<std::vector<std::string>> file;
	std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
};