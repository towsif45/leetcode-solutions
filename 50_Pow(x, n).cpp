class Solution {
public:
    double myPow(double x, int n) {
        if(n < 0) return 1.0/binpow(x, n);
        else return binpow(x, n);
    }
    double binpow(double x, int n){
        if(n == 0) return 1;
        
        double ans = binpow(x, n/2);
        if(n&1) ans *= ans*x;
        else ans *= ans;
        return ans;
    }
};