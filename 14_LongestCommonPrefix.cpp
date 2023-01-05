class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int sz = INT_MAX;
        for(int i=0; i<strs.size(); i++) sz = min(sz, (int) strs[i].size());
        string ans = "";

        for(int i=0; i<sz; i++){
            char c = strs[0][i];
            for(int j=1; j<strs.size(); j++){
                if(strs[j][i] != c) return ans;
            }
            ans += c;
        }
        return ans;
    }
};