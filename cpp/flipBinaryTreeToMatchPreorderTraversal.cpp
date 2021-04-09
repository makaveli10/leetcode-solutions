class Solution {
public:
    vector<int> result;
    int i = 0;
    
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) { 
        if (matchVoyage(root, voyage))
            return result;
        else
            return vector<int>{-1};
    }
    
    bool matchVoyage(TreeNode* root, vector<int>& v)
    {
        if(!root) return true;
        if(root -> val != v[i++]) return false;
        if(root -> left && root -> left -> val != v[i])
        {
            result.push_back(root -> val);
            
            return matchVoyage(root -> right, v) && matchVoyage(root -> left, v);
        }
        
        return matchVoyage(root -> left, v) && matchVoyage(root -> right, v);
    }
};