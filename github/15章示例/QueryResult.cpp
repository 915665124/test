#include"QueryResult.h"

using namespace std;

string make_plural(size_t ctr, const string &word, const string &ending)
{
	return (ctr == 1) ? word : word + ending;//make_plural(wc, "word ", "s ")当输入中文本中
											 //word数大于一是在word后加s，为words为word的复数！
}

ostream &print(ostream &os, const QueryResult &qr) {
	os << qr.sought << " occurs " << qr.lines->size() << " " << make_plural(qr.lines->size(), "time", "s") << endl;
	for (auto num : *qr.lines) {
		//qr.file is the shared_ptr to vector<string>
		//qr.file->begin() is the the first line of the file
		//qr.file->begin()+num is the num line of the file
		os << "\t(line " << num + 1 << ")  " << *(qr.file->begin() + num) << endl;
	}
	return os;
}