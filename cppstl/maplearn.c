/*************************************************************************
    > File Name: maplearn.c
    > Author:  zengyi
    > Mail: zengyi@ebupt.com
    > Created Time: Fri Jul  7 16:45:17 2017
 ************************************************************************/

#include<iostream>
#include<map>
#include<string>
using namespace std;
int main(){
	map<char, int> mp;
	map<char, int>::iterator iter;
	string st;
	string::iterator striter;
	cout << "map empty():" << mp.empty() <<endl;
	int a = 0;
	char ch;
	int b;
	pair<char, int> pr;
	while (a<3){
		cin >> ch >> b;
		pr.first = ch;
		pr.second = b;
		mp.insert(pr);
		a++;
	}
	for(iter = mp.begin(); iter!= mp.end(); ++iter){
		cout << iter->first <<' '<< iter->second <<endl;
	}
	cout << endl ;
	cin >> st;
	for(striter = st.begin();striter != st.end();++striter){
		mp[*striter]++;
	}
	for(iter = mp.begin(); iter!= mp.end(); ++iter){
		cout << iter->first <<' '<< iter->second <<endl;
	}
	cout << endl ;
	mp.erase('c');
	for(iter = mp.begin(); iter!= mp.end(); ++iter){
		cout << iter->first <<' '<< iter->second <<endl;
	}
	cout << endl ;


}
