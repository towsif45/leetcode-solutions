class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int sz = s.size(), res = 0;
        map<char, int> mp;
        
        for(int i=0; i<sz; i++) mp[s[i]] = -1;
        
        for(int i=0,j=0; j<sz; j++){
            if(mp[s[j]] != -1){
                i = max(mp[s[j]]+1, i);
            }
            res = max(res, j-i+1);
            mp[s[j]] = j;
        }
        
        return res;
    }
};