class Solution {
public:
    bool isValid(string s) {
        while(s.find("abc") != string::npos){
            s.replace(s.find("abc"), 3, "");
        }
        if(s.empty()) return 1;
        else return 0;
    }
};