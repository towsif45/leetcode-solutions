class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int sz = heights.size();
        int left[sz+1], right[sz+1];
        stack<int> s;
        int ans = INT_MIN;
        for(int i=0; i<heights.size(); i++){
            while(!s.empty() && heights[s.top()] >= heights[i]) s.pop();
            if(!s.empty()) left[i] = s.top()+1;
            else left[i] = 0;
            s.push(i);
        }
        s = stack<int>();
        for(int i=heights.size()-1; i>= 0; i--){
            while(!s.empty() && heights[s.top()] >= heights[i]) s.pop();
            if(!s.empty()) right[i] = s.top()-1;
            else right[i] = heights.size()-1;
            s.push(i);
        }
        
        for(int i=0; i<heights.size(); i++){
            // cout << left[i] << " " << right[i] << endl;
            int area = (right[i]-left[i]+1)*heights[i];
            ans = max(ans, area);
        }
        return ans;
    }
};