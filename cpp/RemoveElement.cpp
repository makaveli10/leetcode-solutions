class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.size()==0)
            return nums.size();
        
        int i = 0;
        int j = 0;
        for(; j < nums.size(); j++){
            if(nums[j] != val){
                nums[i++] = nums[j];
            }
        }
        return i;
    }
};
