#include<vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        // create result vector
        vector<string> result;
        
        // insert starting string
        result.push_back(S);
            
        // logic would be to insert and then change the current character
        // to create new string and push back to the vector
        for (int i=0; i < S.length(); i++){
            if (S[i] < 65)
                continue;
            if (S[i] >= 65 && S[i] <= 90){
                vector<string> temp = result;
                for (auto rs : temp){
                    rs[i] += 32;
                    result.push_back(rs);
                }
                temp.clear();
            }
            if (S[i] >= 97 && S[i] <= 122){
                vector<string> temp = result;
                for (auto rs : temp){
                    rs[i] -= 32;
                    result.push_back(rs);
                }
                temp.clear();
            }
        }
        return result;
    }
};