class Solution {
public:
    int myAtoi(string s) {
        string s_new;
        int wh = 0, sign = 1;
        while(s[wh] == ' ') wh++;
        if(s[wh] == '-') sign = -1, wh++;
        else if(s[wh] == '+') wh++;
        
        for(int i=wh; s[i] >= '0' && s[i] <= '9'; i++){
            s_new += s[i];
        }
        int z=0;
        while(s_new[z] == '0') z++;
        if(s_new.size()-z > 10){
            if(sign==1) return INT_MAX;
            else return INT_MIN;
        }
        // cout << "s_new "<< s_new << endl;
        long long int ans = 0;
        for(long long int i=1, j=s_new.size()-1; i <= 1e11 && j>=z; i*=10, j--){
            // cout << i << " " << j << endl;
            ans += (s_new[j]-'0')*i;
        }
        ans*=sign;
        if(ans > INT_MAX) return INT_MAX;
        if(ans < INT_MIN) return INT_MIN;
        return (int) ans;
    }
};