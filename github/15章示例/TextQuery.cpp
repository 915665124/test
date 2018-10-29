#include "TextQuery.h"
#include<sstream>

using namespace std;


TextQuery::TextQuery(ifstream &is) :file(new vector<string>) {
	string text;
	while (getline(is, text)) {
		file->push_back(text);		//(*file).push_back(text);
		int n = file->size() - 1;	//the code "-1" correspond to the variable num in the Class QueryResult
									//this "-1" will influence the derived class
		istringstream line(text);
		string word;
		while (line >> word) {
			auto &lines = wm[word];		//using the auto key word with smart pointer
			if (!lines) {
				lines.reset(new set<line_no>);		//
			}
			lines->insert(n);			//insert the line_no into the set of the map, a word get its line_no(s)
		}
	}
}
QueryResult TextQuery::query(const string& sought) const {
	static shared_ptr<set<line_no>> nodata(new set<line_no>);
	auto loc = wm.find(sought);
	if (loc == wm.end())
		return QueryResult(sought, nodata, file);
	else
		return QueryResult(sought, loc->second, file);
}