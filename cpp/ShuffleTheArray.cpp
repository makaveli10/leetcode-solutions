#include <vector>

class Solution {
public:
    std::vector<int> shuffle(std::vector<int>& nums, int n) {
        if (n==1){
            return nums;
        }
        
        std::vector<int> result;
        for(size_t i = 0; i < n; i++){
            result.push_back(nums[i]);
            result.push_back(nums[i+n]);
        }
        return result;
    }
};
