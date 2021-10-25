#include<iostream>
#include<iomanip>
#include<vector>
using namespace std;


void answer(int n) {
	int j;
	bool x=false;
	for(j=2; j<n; j++) {
		if(n%j==0) {
			cout<<"*"<<j;
			x=true;
			answer(n/j);
			break;
		}
	}
	if(x==false)
		cout<<"*"<<n;
}
int main() {
	int n=1,i;
	bool x=false;
	cin>>n;
	for(i=2; i<n; i++)
		if(n%i==0) {
			cout<<n<<"="<<i;
			x=true;
			answer(n/i);
			break;
		}
	if(x==false)
		cout<<"no answer";
	return 0;
}