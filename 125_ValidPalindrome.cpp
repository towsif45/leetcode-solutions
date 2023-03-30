class Solution {
public:
    bool check(char c){
        return (tolower(c) < 'a' || tolower(c) > 'z') && (c < '0' || c > '9');
    }
    bool isPalindrome(string s) {
        for(int i = 0, j = s.size()-1; i <= j; i++, j--){
            
            while(i < s.size() && check(s[i])) i++;
            while(j > 0 && check(s[j])) j--;
            // cout << i << " " << j << endl;
            // cout << (char)tolower(s[i]) << " " << (char)tolower(s[j]) << endl;
            if(!check(s[i]) && !check(s[j]) && tolower(s[i]) != tolower(s[j])) return false;
        }
        return true;
    }
};