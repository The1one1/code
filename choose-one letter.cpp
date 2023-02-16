#include<bits/stdc++.h>
using namespace std;

vector<string> missingWords(string s, string t) {
    vector<string> ans;
    int i = 0, j = 0;
    while(i < s.size() && j < t.size()) {
        if(s[i] == t[j]) {
            i++;
            j++;
        }
        else {
            string temp = "";
            while(i < s.size() && s[i] != ' ') {
                temp += s[i];
                i++;
            }
            ans.push_back(temp);
            i++;
        }
    }
    while(i < s.size()) {
        string temp = "";
        while(i < s.size() && s[i] != ' ') {
            temp += s[i];
            i++;
        }
        ans.push_back(temp);
        i++;
    }
    return ans;
}

int main() {
    string s, t;
    cin >> s >> t;
    vector<string> ans = missingWords(s, t);
    cout <<"Hellow";
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
}
