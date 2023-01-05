class Solution {
public:
    string add(string num1, string num2){
        int carry = 0, i=num1.size()-1, j=num2.size()-1;
        string ans = "";
        for(; i>=0 || j>=0; i--, j--){
            int sum = carry;
            if(i>=0) sum += num1[i]-'0';
            if(j>=0) sum += num2[j]-'0';
            char dig = (sum%10)+'0';
            ans = dig+ans;
            carry = sum/10;
        }
        if(carry) {
            char c = carry+'0'; 
            ans = c+ans;
        }
        return ans;
    }
    string multiply(string num1, string num2) {
        string ans = "";
        for(int i=num2.size()-1; i>=0; i--){
            int carry = 0;
            string tmp = "";
            for(int j=num1.size()-1; j>=0; j--){
                int mul = (num2[i]-'0')*(num1[j]-'0')+carry;
                char dig = (mul%10)+'0';
                tmp = dig+tmp;
                carry = mul/10;
            }
            if(carry) {
                char c = carry + '0';
                tmp = c + tmp;
            }
            ans = add(ans, tmp);
            num1 += "0";
        }
        while(ans.size() > 1 && ans[0] == '0') ans.erase(0, 1);
        return ans;
    }
};