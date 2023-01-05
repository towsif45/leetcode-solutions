class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        
        if(target <= nums[left]) return left;
        if(target > nums[right]) return right+1;
        
        while (left <= right) {
            int mid = (left+right)/2;
            if(nums[mid] == target) return mid;
            if(nums[mid] < target && target < nums[mid+1]) return mid + 1;
            if(nums[mid] > target) right = mid-1;
            else left = mid+1;
        }
        
        return -1;
    }
};