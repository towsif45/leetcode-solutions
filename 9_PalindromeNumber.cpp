class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        if(x == 0) return true;
        int tmp = x;
        int dig = (int) floor(log10(x));
        long long int rev = 0;
        //cout << tmp << endl;
        for(int i=dig; tmp > 0 ;i--){
            rev += (tmp%10)*binpow(10, i);
            tmp /= 10;
            //cout << tmp << endl;
        }
        return x == rev;
    }
    
    long long int binpow(int base, int power){
        if(power == 0) return 1;
        long long int ans = 1;
        if(power & 1) ans *= base;
        ans *= binpow(base, power/2)*binpow(base, power/2);
        
        return ans;
    }
    
};