#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string discountPrices(string sentence, int discount) {
        string s;
        for(int i = 0; i < sentence.size(); i++)
        {
            if(sentence[i] == '$')
            {
                int j = i + 1;
                float sum = 0, count = 0;
                bool flag = true;
                string h;
                while(j < sentence.size() && isdigit((sentence[j]))){
                    cout << sentence[j] << endl;
                    h.push_back(sentence[j]);
                    if(flag)
                        sum = sum * 10 + (sentence[j] - '0');

                    if(!flag){
                        count = count * 10 + (sentence[j]- '0');
                    }
                    j++;
                    if(sentence[j] == '.'){
                        flag = false;
                    }
                }
                cout << "count = :" << sum << endl;
                if(j == sentence.size() or sentence[j] == ' '){
                    int x = 0;
                    if(count != 0)
                        x  = log10(count) + 1;
                    
                    float y = (float)sum + ((float)count)/pow(10, x);
                    float sum = (y * (float)discount) / 100;
                    //upto to decimal place
                    sum = sum*100;
                    sum = ceil(sum)/100;
                    cout <<"sum="<<sum<<endl;
                    s.push_back('$');
                    string temp = to_string(sum), kk;
                    bool g = false;
                    int cnt = 0;
                    for(int i = 0; i < temp.size(); i++){
                        if(g){
                            cnt++;
                            if(cnt == 3){
                                break;
                            }
                        }
                        s.push_back(temp[i]);
                        if(temp[i] == '.'){
                            g = true;
                        }
                    }
                    s.append(kk);
                    cout <<"temp="<<temp<<endl;
                    if(j != sentence.size())
                        s.push_back(' ');
                    goto last;
                }
                s.append(h);
                last:;
                i = j+1;
            }
            if(i >= sentence.size())
                break;
            s.push_back(sentence[i]);
        }
        return s;
    }
};


int main(){

    string s = "there are $1 $2 and 5$ candies in the shop";
    Solution sol;
    cout << sol.discountPrices(s, 50) << endl;
}

