/*************************************************************************
    > File Name: stringlearn.cpp
    > Author:  zengyi
    > Mail: zengyi@ebupt.com
    > Created Time: Fri Jul  7 15:04:38 2017
 ************************************************************************/

#include<iostream>
using namespace std;
int main(){
	char *c = new char[20];
	string s1("hello");
	string s2(s1);
	string s3;
	string s4("hello world");
	string s5(5,'c');
	const string s6("hello");
	cout << s1 << endl\
		 << s2 << endl\
		 << s5 << endl;
	s1.append(s2);
	cout << s1 << endl;
	cout << "s1 empty():" << s1.empty() <<endl;
	cout << "s3 empty():" << s3.empty() <<endl;
	
	cout << "s2 size():" << s2.size() <<endl;
	cout << "s4 size():" << s4.size() <<endl;
	cout << "s2 length():" << s2.length() <<endl;
	cout << "s4 length():" << s4.length() <<endl;
	cout << s4.find("hello", 3) << endl; 
	cout << s4.find("world", 4) << endl; 
	cout << s4.find(s6) << endl; 
	cout << s4.find(s1) << endl; //find Ö»²éÕÒconst 
	s5 = s5 + s1;
	cout << s5 << endl;
	cout << s5[4] <<endl;
	//*c = s1.c_str();
	cout << c << endl;
	return 0;
}
