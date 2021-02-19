#include<vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int area=0, maxA = 0;
        int i=0, j=(height.size()) - 1;
        while(i < j){
            area = std::min(height[i], height[j]) * (j - i);
            if (area > maxA)
                maxA = area;
            if (height[i] > height[j])
                j--;
            else
                i++;
        }
        return maxA;
    }
};