#include <bits/stdc++.h>
using namespace std;

bool fun1(string str, vector<string> &m)
{
    for(int i = 0; i < m.size(); i++) 
    {
        int j = 0, k = 0;
        while(j < str.size() and k < m[i].size()){
            if(m[i][k] == str[j] or m[i][k] == toupper(str[j])){
                k++, j++;
            }else k++;
        }
        if(j == str.size()) return true;
    }
    return false;
}

bool fun2(string str, vector<string> &m){
    for(int i = 0; i < m.size(); i++){
        string s;
        for(int j = 0; j < m.size(); j++){
            s.push_back(tolower(m[j][i]));
        }
        int j = 0, k = 0;
        while(j < str.size() and k < s.size()){
            if(s[k] == str[j] ){
                k++, j++;
            }else k++;
        }
        if(j == str.size()) return true;
    }
    return false;
}

int main() {
	int t; cin >> t;
	while(t--) {
	    int r, c; cin >> r >> c;
	    vector<string> m(r,"");
	    for(int i = 0; i < r; i++) {
            cin >> m[i];
	    }
	    
	    string str = "spoon";
	    if(fun1(str, m) or fun2(str, m)) {
	        cout << "There is a spoon!\n";
	    }
	    else {
	        cout <<"There is indeed no spoon!\n";
	    }
	}
}
