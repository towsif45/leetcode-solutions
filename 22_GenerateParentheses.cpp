class Solution {
public:
    vector<string> ans;
    stack<char> st;
    int nn;
    void solve(int i, string s){
        //cout << s << endl;
        if(i == 2*nn){
            if(st.empty()) ans.emplace_back(s);
            return;
        }

        st.push('(');
        solve(i+1, s+"(");
        st.pop();
        if(!st.empty()) {
            st.pop();
            solve(i+1, s+")");
            st.push('(');
        }
        return;
    }

    vector<string> generateParenthesis(int n) {
        nn = n;
        solve(0, "");
        return ans;
    }
};