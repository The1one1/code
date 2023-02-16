class Solution {
public:
    vector<string> morseCode = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    int uniqueMorseRepresentations(vector<string>& words) {\
        map<string, int> m;
        for(auto &it: words)
        {
            string str = "";
            for(auto &it1: it)
            {
                str += morseCode[it1 - 'a'];
            }
            map[str]++;
        }
        return m.size();
    }
};