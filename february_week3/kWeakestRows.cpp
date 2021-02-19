#include<vector>
#include <utility>  // pair
#include <algorithm>    // sort

using namespace std;

class Solution {
public:
    int numSoldiers(vector<int> a){
        int low = 0, high = a.size()-1;
        while(low <= high){
            int mid = low + (high-low) / 2;
            if (a[mid]==0){
                high -= 1;
            }
            else{
                low += 1;
            }
        }
        return low;
    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        std::vector<pair<int, int>> num_soldiers;
        for (int i=0; i < mat.size(); i++){
            int soldiers = 0;
            num_soldiers.push_back(make_pair(numSoldiers(mat[i]), i));
        }
        sort(num_soldiers.begin(), num_soldiers.end(), comp());
        vector<int> result;
        
        for (int i=0; i < k; i++)
            result.push_back(num_soldiers[i].second);
        return result;
        
    }
    
    struct comp {
        bool operator()(pair<int, int> a, pair<int, int>b) {
            if(a.first > b.first) return false;
            else if(a.first == b.first) return a.second<b.second;
            return true;
        }
    };
};