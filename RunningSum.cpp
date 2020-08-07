class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        if ((int)nums.size() ==1)
            return nums;
        
        for(size_t i = 1; i < nums.size(); i++){
            nums[i] += nums[i-1];
        }
        return nums;
    }
};