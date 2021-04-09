class Solution {
public: 
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), cmp);
        vector<int> sol_dp(envelopes.size());
        int res = 0;
        for(int i=0; i< envelopes.size(); i++)
        {
            for(int j=0; j<i; j++)
            {
                if(envelopes[j][0] < envelopes[i][0] && envelopes[j][1] < envelopes[i][1])
                {
                    sol_dp[i] = max(sol_dp[i], sol_dp[j] + 1);
                    res = max(res, sol_dp[i]);
                }
            }           
        }
        return res + 1;
    }
    
private:
    // Comparator function to sort pairs
    // according to second value
    static bool cmp(vector<int>& a, vector<int>& b)
    {
        return a[0]==b[0] ? b[1] > a[1] : b[0] > a[0];
    }
};