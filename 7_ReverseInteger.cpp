class Solution {
public:
    int reverse(int x) {
        if(x == 0) return 0;
        
        int tmp = x, rev = 0;
        while(tmp != 0){
            int d = tmp%10;
            if((x < 0 && rev >= (INT_MIN-d)/10) || (x > 0 && rev <= (INT_MAX-d)/10)){
                rev *= 10;
                rev += tmp%10;
                tmp /= 10;
            }
            else{
                return 0;
            }
        }
        return rev;
    }
};