class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if((nums[j]>=0 && nums[i] > INT_MAX-nums[j]) || (nums[j] < 0 && nums[i] < INT_MIN-nums[j])) continue;
                for(int k=j+1, l=n-1; k<n && l>k;){
                    int ij = nums[i]+nums[j];
                    if(nums[k]>=0 && ij > INT_MAX-nums[k]) break; 
                    if(nums[k] < 0 && ij < INT_MIN-nums[k]){
                        k++;
                        continue;
                    }
                    ij += nums[k];
                    if(nums[l]>=0 && ij > INT_MAX-nums[l]){
                        l--;
                        continue;
                    }
                    if(nums[l] < 0 && ij < INT_MIN-nums[l]) break;
                    ij += nums[l];
                    if(ij == target){
                        ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                        while(k<n-1 && nums[k] == nums[k+1]) k++;
                        while(l>k && nums[l] == nums[l-1]) l--;
                        k++, l--;
                    }
                    else if(ij > target) l--;
                    else k++;
                }
                while(j<n-1 && nums[j] == nums[j+1]) j++;
            }
            while(i<n-1 && nums[i] == nums[i+1]) i++;
        }
        return ans;
    }
};