#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    // Runtime: 0 ms
    // Memory Usage: 6.7 MB
    // recursive
//     vector<string> smappings = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}, ans;
    
//     vector<string> letterCombinations(string digits) {
//         if (digits.empty()) return {};
        
//         combine(digits, 0, "");
//         return ans;
        
//     }
    
//     void combine(string& digits, int i, string comb) {
//         if (i==digits.size())
//         {
//             ans.push_back(comb);
//             return;
//         }
        
//         for(auto& newChar: smappings[digits[i]-'2']) {
//             combine(digits, i+1, comb+newChar);
//         }
//     }

    // Runtime: 0 ms
    // Memory Usage: 6.5 MB
    // iterative
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        
        vector<string> smappings = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}, ans{""};
        
        for(auto& digit: digits)
        {
            vector<string> comb;
            for(auto& cComb: ans)
            {
                for (auto& newChar: smappings[digit - '2'])
                {
                    string newComb = cComb + newChar; 
                    comb.push_back(newComb);
                }
            }
            ans = move(comb);

        }

        return ans;
    }
};