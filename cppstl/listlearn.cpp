/*************************************************************************
    > File Name: listlearn.cpp
    > Author:  zengyi
    > Mail: zengyi@ebupt.com
    > Created Time: Fri Jul  7 16:13:23 2017
 ************************************************************************/

#include<iostream>
#include<list>
#include<string>
using namespace std;
int main(){
	list<string> ls;
	string s1,s2;
	int a = 0;
	s1 = "hello world";
	list<string>:: iterator iter;

	ls.push_back(s1);
	cout << ls.size() <<endl;
	while (a<3){
		cin >> s2;
		ls.push_back(s2);
		a++;
	}
	cout << "list front():" << ls.front() << endl;
	cout << "list back():" << ls.back() << endl;
	cout << "list size():" << ls.size() << endl;
	cout << "list empty():" << ls.empty() << endl;

	for(iter = ls.begin();iter!= ls.end();++iter){
		cout << *iter << ' ';
	}
	cout << endl ;
	s1 = "front ";
	ls.push_front(s1);
	for(iter = ls.begin();iter!= ls.end();++iter){
		cout << *iter << ' ';
	}
	cout << endl ;

	ls.pop_front();
	for(iter = ls.begin();iter!= ls.end();++iter){
		cout << *iter << ' ';
	}
	cout << endl ;

	ls.erase(ls.begin());  //Ã»ÓÐÖØÔØ²Ù×Ý·û+,-
	for(iter = ls.begin();iter!= ls.end();++iter){
		cout << *iter << ' ';
	}
	cout << endl ;

	ls.clear();
	for(iter = ls.begin();iter!= ls.end();++iter){
		cout << *iter << ' ';
	}
	cout << endl ;

	//cout <<&*iter <<endl;
}
