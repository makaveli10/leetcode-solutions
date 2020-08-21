class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0 || nums.size()==1)
            return static_cast<int>(nums.size());
        
        auto it = nums.begin();
        it++;
        for(it; it != nums.end(); it++){
            if (*it == *(it-1)){
                nums.erase(it--);
            }
        }
        return static_cast<int>(nums.size());
    }
};
