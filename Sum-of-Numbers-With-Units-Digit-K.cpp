class Solution {
public:
    int minimumNumbers(int num, int k) {
       int last_digit = num % 10;
       int ans = 1;
        while((k*ans)%10 != last_digit)
           ans++;
           if(ans == 10)
               return -1;
        
        return ans;
    }
};