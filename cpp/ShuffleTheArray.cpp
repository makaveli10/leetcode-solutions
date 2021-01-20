class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        if (n==1){
            return nums;
        }
        vector<int> result;
        for(size_t i = 0; i < n; i++){
            result.push_back(nums[i]);
            result.push_back(nums[i+n]);
        }
        return result;
    }
};
