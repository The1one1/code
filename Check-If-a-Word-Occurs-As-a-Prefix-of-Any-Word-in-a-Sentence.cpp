#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        sentence.push_back(' ');
        int l = 0, Wcnt = 0, pos = 0;
        
        for(int i = 0; i < sentence.size(); i++)
        {
            if(sentence[i] == ' ')
            {
                pos++;
                if(searchWord == sentence.substr(l, Wcnt))
                    return pos;
                
                l = i+1;
                Wcnt = 0;
            }
            else Wcnt++;
        }
        return -1;
    }
};

int main(){
    string sentence = "i love you";
    string searchWord = "love";
    Solution obj;
    cout << obj.isPrefixOfWord(sentence, searchWord) << endl;
}