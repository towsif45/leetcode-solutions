class Solution {
public:
    string countAndSay(int n) {
        vector<string> dp;
        dp.push_back("1");

        for(int i=1; i<n; i++){
            string prev = dp[i-1], gen;
            for(int j=0; j<prev.size(); j++){
                int cnt = 1;
                while(j+1 < prev.size() && prev[j] == prev[j+1]) cnt++, j++;
                gen += '0'+cnt;
                gen += prev[j];
            }
            dp.push_back(gen);
        }
        return dp[n-1];
    }
};