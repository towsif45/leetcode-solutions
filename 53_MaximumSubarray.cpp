class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cur = 0, mx = INT_MIN;
        for(int i=0; i<nums.size(); i++){
            cur += nums[i];
            if(cur < nums[i]) cur = nums[i];
            mx = max(cur, mx);
        }
        return mx;
    }
};