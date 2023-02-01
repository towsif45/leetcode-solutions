class Solution {
public:
    int longestSubstring(string s, int k) {
        bool check[26] = {0};
        int distinct = 0, ans = 0;

        for(int i=0; i<s.size(); i++){
            if(!check[s[i]-'a']) distinct++, check[s[i]-'a'] = 1;
        }

        for(int curr_distinct = 1; curr_distinct <= distinct; curr_distinct++){
            int windowCount[26] = {0};
            int left = 0, right = 0, window_distinct = 0, window_k = 0;
            while(right < s.size()){
                if(window_distinct <= curr_distinct){
                    int indx = s[right]-'a';
                    if(windowCount[indx] == 0) window_distinct++;
                    windowCount[indx]++;
                    if(windowCount[indx] == k) window_k++;
                    right++;
                }
                else{
                    int indx = s[left]-'a';
                    if(windowCount[indx] == k) window_k--;
                    windowCount[indx]--;
                    if(windowCount[indx] == 0) window_distinct--;
                    left++;
                }

                if(window_k == curr_distinct && window_distinct == curr_distinct){
                    ans = max(ans, right-left);
                }
            }
        }
        return ans;
    }
};