#include"QueryResult.h"
#include"TextQuery.h"
#include"Query.h"
#include"NotQuery.h"
#include"AndQuery.h"
#include"OrQuery.h"

using namespace std;

int main() {
	//�ı���Ѱ�����д
	//ʹ��TextQuery��������ļ�������һ��QueryResult����QueryResult��������������������Ϣ

	string word1{ "nothing" }, word2{ "tell!" };
	ifstream infile;
	infile.open("dialogue.txt", ios::out);
	if (!infile) {
		cerr << "open file fail " << endl;
	}

	cout << "*****************************************************\ntest the TextQuery and QueryReslult\n";
	TextQuery file(infile);
	QueryResult result1(file.query(word1));
	print(cout, result1);
	cout << "the first test end\n*****************************************************\n\n";

	cout << "*****************************************************\ntest the interface of the Query \n";
	Query q = ~(Query(word1) & Query(word2));
	cout << q.rep() << endl;
	QueryResult result2(q.eval(file));
	print(cout, result2);
	cout << "\nthe interface test end\n*****************************************************" << endl;

	infile.close();

	return 0;
}