class Solution {
public:
    string longestPalindrome(string s) {
    	int n = s.length();
    	int l = 0, r = 0;
        for(int i=0; i<n; i++){
        	int len = max(expand(s, i, i), expand(s, i, i+1));
        	if(r-l+1 < len){
        		l = i - (len-1)/2;
        		r = i + len/2;
        	}
        }
        return s.substr(l, r-l+1);
    }

    int expand(string s, int left, int right){
    	while(left >= 0 && right < s.length() && s[left] == s[right]){
    		left--;
    		right++;
    	}
    	return right - left - 1;
    }
};