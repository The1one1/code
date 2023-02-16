#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	set<int> s;

	s.insert(1);
	s.insert(2);
	s.insert(3);
	s.insert(4);
	s.insert(5);
	s.insert(6);

	auto x = s.lower_bound(3);
	cout << *x << endl;
}