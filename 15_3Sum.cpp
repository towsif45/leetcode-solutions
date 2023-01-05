class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i=0; i<n; i++){
            for(int j=i+1, k=n-1; j<n && k>j;){
                if(nums[i] == -nums[j]-nums[k]){
                    ans.push_back({nums[i], nums[j], nums[k]});
                    while(j < n-1 && nums[j] == nums[j+1]) j++;
                    while(k > j && nums[k] == nums[k-1]) k--;
                    j++, k--;
                }
                else if(nums[i] < -nums[j]-nums[k]){
                    while(j < n-1 && nums[j] == nums[j+1]) j++;
                    j++;
                }
                else{
                    while(k > 0 && nums[k] == nums[k-1]) k--;
                    k--;
                }
            }
            while(i<n-1 && nums[i] == nums[i+1]) i++;
        }
        return ans;
    }
};