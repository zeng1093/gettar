/*************************************************************************
    > File Name: vectorlearn.cpp
    > Author:  zengyi
    > Mail: zengyi@ebupt.com
    > Created Time: Fri Jul  7 15:33:16 2017
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;
int main(){
	vector<int> ve;
	vector<int> ve1;
	int b,a = 0;
	vector<int>:: iterator iter;
	while (a < 3){
		cin >> b;
		ve.push_back(b);
		a++;
	}
	for(iter = ve.begin();iter!= ve.end();++iter){
		cout << *iter << " ";
	}
	cout << endl;
	cout << "ve empty():" << ve.empty() << endl;
	cout << "ve1 empty():" << ve1.empty() << endl;
	
	cout << "ve size():" << ve.size() << endl;
	cout << "ve1 size():" << ve1.size() << endl;

	cout << "ve front():" << ve.front() << endl;
	cout << "ve back():" << ve.back() << endl;
	
	cout << "ve[1]:" << ve[1] <<endl;

	cout << "After pop:" << endl;
	ve.pop_back();
	for(iter = ve.begin();iter!= ve.end();++iter){
		cout << *iter << ' ';
	}

	cout << endl <<"after erase" << endl;
	ve.erase( ve.begin() + 1);	
	for(iter = ve.begin();iter!= ve.end();++iter){
		cout << *iter ;
	}

	cout << endl << "after clear" << endl;
	ve.clear();
	for(iter = ve.begin();iter!= ve.end();++iter){
		cout << *iter ;
	}



//	cout << b <<endl;
//	cout << b <<endl;
	return 0;

}
