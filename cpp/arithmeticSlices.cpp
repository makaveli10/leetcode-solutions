#include<vector>
#include <string>

using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if (A.size() < 3)
            return 0;
        int result=0;
        int count=2, diff = A[1] - A[0];
        for (int i=2; i < A.size(); i++){
            // increment count no of items in current slice
            // with equeal difference between them
            if (A[i]-A[i-1] == diff){
                count += 1;
            }
            else{
                // add all possible slices to the result
                for(int j=count; j>=3; j--){
                    result += (count - j + 1);
                }
                
                // update diff and count
                diff = A[i] - A[i-1];
                count = 2;
            }
        }
        // update result if diff not changed at the end
        if (count != 0){
            for(int j=count; j>=3; j--){
                result += (count - j + 1);
            }
        }
        return result;
    }
};