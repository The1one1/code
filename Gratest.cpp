#include<bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    string greatestLetter(string s) 
    {
        map<char, int> lower, upper;
        for (auto c : s) 
        {
            if (islower(c)) 
                lower[c]++;
            
            else
                upper[c]++;
        }
        char max_letter = 'a';
        for (auto c : upper) 
        {
            if(lower.find(tolower(c.first)) != lower.end()) 
                max_letter = c.first;
            
        }
        return string(1, max_letter);
    }
};

int main(){
    string s = "lEeTcOdE";
    Solution obj;
    cout<<obj.greatestLetter(s)<<endl;
    return 0;
}