class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> result(candies.size());
        int max_candies = *max_element (candies.begin(), candies.end());
        
        for (size_t i = 0; i< candies.size(); i++){
            if (candies[i] + extraCandies >= max_candies)
                result[i] = true;
        }
        return result;
    }
};
