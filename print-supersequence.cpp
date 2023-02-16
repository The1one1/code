    void lcs(string &str1, string &str2, vector<vector<int>> &dp)
    {
        for(int i = 1; i <= str1.size(); i++){
            for(int j = 1; j <= str2.size(); j++){
                if(str1[i-1] == str2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
    }

    string superSeq(string str1, string str2, vector<vector<int> > &dp) {

        string s;
        int i = str1.size(), j = str2.size();
        while(i > 0 and j > 0){
            if(dp[i][j-1] == dp[i-1][j]){
                if(dp[i][j] > dp[i][j-1]){
                    s.push_back(str2[j-1]);
                    i--, j--;
                }
                else{
                    s.push_back(str1[i-1]);
                    i--;
                }
            }
            else{
                if(dp[i][j-1] > dp[i-1][j]){
                    s.push_back(str2[j-1]);
                    j--;
                }
                else{
                    s.push_back(str1[i-1]);
                    i--;
                }
            }
        }
        while(i > 0){
            s.push_back(str1[i-1]);
            i--;
        }

        while(j > 0){
            s.push_back(str2[j-1]);
            j--;
        }
        // string str = s.reverse();
        string str;
        for(int i = s.size()-1; i >= 0; i--){
            str.push_back(s[i]);
        }
        return str;
    }
    
    string shortestSupersequence(string str1, string str2) {
        vector<vector<int>> dp(str1.size() + 1, vector<int>(str2.size() + 1, 0));
        lcs(str1, str2, dp);
        return superSeq(str1, str2, dp);
    }
